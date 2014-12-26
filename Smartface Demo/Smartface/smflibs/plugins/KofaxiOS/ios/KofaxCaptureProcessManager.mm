//
// Copyright (c) 2012-2014 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import "KofaxCaptureProcessManager.h"
#import "KofaxConstant.h"
#import "KofaxClass.h"

#if defined (__APPLE__) && defined(SMARTFACE_PRODUCTION)
#import <iOSPlayer/inc/ESpratIOSPlayer.h>
#import <iOSPlayer/inc/ESpratNavigationController.h>
#else
#include "ESpratIOSPlayer.h"
#include "ESpratNavigationController.h"
#endif

#ifdef KOFAX_ENABLED

#import <CoreMotion/CoreMotion.h>
#define RAD2DEG(n) ((n) * 180 / M_PI)
#define DEG2RAD(n) ((n) * M_PI / 180)

#define kStoppedImageViewTag 1111
#define activityIndicatorTag 2222
#define _segmentedControlTag 3333



@interface KofaxCaptureProcessManager ()<kfxKUIBarCodeCaptureControlDelegate, kfxKIPDelegate, kfxKUIImageCaptureControlDelegate> {
    bool captured;
}

// To remove the Image capture  screen
@property (nonatomic, strong) UIButton * cancelCam;
@property (nonatomic, strong) UIButton * capBtn;
// To change the flass settings of the Image Capture screen
@property (nonatomic, strong) UISegmentedControl * segmentedControl;
@property (nonatomic, strong) UIImageView *backgroundImageView;

// To remember the flash mode chosen by the user
@property (nonatomic) kfxKUIFlashSetting flash;

@property (assign) BOOL isIphone5;

@end


kfxKUIImageCaptureControl   * kImageCaptureCtrl;
kfxKENImageProcessor        * captureImageProcessor;
KofaxCaptureProcessManager  * CaptureProcessInstance = nil;
UIViewController *cameraViewController;

CMMotionManager *kofax_motionManager;
NSTimeInterval kofax_lastTime;
double kofax_currentPitch;
double kofax_currentRoll;

@implementation KofaxCaptureProcessManager

//Method which detects Device's pitch & Roll
-(void)detectDevicePitchAndRoll {
    [kofax_motionManager startDeviceMotionUpdatesToQueue:[NSOperationQueue mainQueue] withHandler:^(CMDeviceMotion *devMotion, NSError *error){
        NSTimeInterval now = [NSDate timeIntervalSinceReferenceDate];
        NSTimeInterval timeSinceLast = now - kofax_lastTime;
        
        if(timeSinceLast > 0.1){
            UIInterfaceOrientation devOrientation = [[UIApplication sharedApplication] statusBarOrientation];
            
            switch (devOrientation) {
                case UIInterfaceOrientationPortrait:
                    kofax_currentPitch = devMotion.attitude.pitch;
                    kofax_currentRoll = devMotion.attitude.roll;
                    break;
                case UIInterfaceOrientationPortraitUpsideDown:
                    kofax_currentPitch = -devMotion.attitude.pitch;
                    kofax_currentRoll = -devMotion.attitude.roll;
                    break;
                case UIInterfaceOrientationLandscapeLeft:
                    kofax_currentPitch = devMotion.attitude.roll;
                    kofax_currentRoll = -devMotion.attitude.pitch;
                    break;
                case UIInterfaceOrientationLandscapeRight:
                    kofax_currentPitch = -devMotion.attitude.roll;
                    kofax_currentRoll = devMotion.attitude.pitch;
                    break;
            }
            
            kofax_currentPitch = RAD2DEG(kofax_currentPitch);
            kofax_currentRoll = RAD2DEG(kofax_currentRoll);
            
            kofax_lastTime = now;
        }
    }];
}

+(id) sharedClassInstance
{
    @synchronized (self)
    {
        if (CaptureProcessInstance == nil) {
            // Create the singleton instance once, if it is nil. This should be created only once and will be available\n
            // through the app is running\n
            
            CaptureProcessInstance = [[KofaxCaptureProcessManager alloc]init];
            [CaptureProcessInstance setFlash: kfxKUIFlashAuto];
            
            CaptureProcessInstance.isIphone5 = NO;
            if(UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
            {
                CGSize result = [[UIScreen mainScreen] bounds].size;
                if(result.height == 568)
                    CaptureProcessInstance.isIphone5 = YES;
            }
            
            //MotionManager is responsible for reporting the device's pitch & roll
            kofax_motionManager = [[CMMotionManager alloc] init];
            kofax_lastTime = 0;
            
            [CaptureProcessInstance detectDevicePitchAndRoll];
            
            captureImageProcessor = [kfxKENImageProcessor instance];
            captureImageProcessor.delegate = self;
        } else {
            // Capture & Process instance is already available
        }
    }
    return CaptureProcessInstance;
}

#pragma mark - Capture methods

-(void) presentCaptureScreenKImgWithOptions:(OptionParameter *)params {
    captured = false;
    CGFloat statusBarHeight = [[UIApplication sharedApplication] statusBarFrame].size.height;
    int majorVersion = [[[UIDevice currentDevice] systemVersion] intValue];
    if(!cameraViewController){
        cameraViewController = [[UIViewController alloc] init];
        [cameraViewController.view setBackgroundColor:[UIColor blackColor]];
        
        // Create the Image capture control object
        [kfxKUIImageCaptureControl initializeControl];
        kImageCaptureCtrl = [[kfxKUIImageCaptureControl alloc] initWithFrame:CGRectMake(5, 5 + (majorVersion<7?0:statusBarHeight), 310, 516)];
        
        // Add cancel button
        _cancelCam = [UIButton buttonWithType:UIButtonTypeRoundedRect];
        [_cancelCam addTarget:self action:@selector(cancelCaptureScreen:) forControlEvents:UIControlEventTouchDown];
        [_cancelCam setTitle:@"Cancel" forState:UIControlStateNormal];
        _cancelCam.titleLabel.font = [UIFont systemFontOfSize:12.0];
        [_cancelCam setTintColor:[UIColor whiteColor]];
        if(majorVersion >= 7){
            [_cancelCam.layer setBorderWidth:1.0];
            [_cancelCam.layer setBorderColor: [[UIColor whiteColor] CGColor]];
            [_cancelCam.layer setCornerRadius:5.0];
        }
        
        int screenW = [[UIScreen mainScreen] bounds].size.width;
        _cancelCam.frame = CGRectMake(screenW-75 , 15.0f + (majorVersion<7?0:statusBarHeight), 70, 30.0);
        [cameraViewController.view addSubview:_cancelCam];
        
        _capBtn = [[UIButton buttonWithType:UIButtonTypeCustom] retain];
        [_capBtn addTarget:self action:@selector(forceCaptureImage) forControlEvents:UIControlEventTouchUpInside];
        [_capBtn setClipsToBounds:YES];
        [cameraViewController.view addSubview:_capBtn];
        
        UIImage *bgImg = nil;
        bgImg = [UIImage imageNamed:@"icon_capture.png"];
        UIImage *bgPressImg = nil;
        bgPressImg = [UIImage imageNamed:@"icon_capture_press.png"];
        if(bgImg){
            [_capBtn setImage:bgImg forState:UIControlStateNormal];
        }
        if(bgPressImg){
            [_capBtn setImage:bgPressImg forState:UIControlStateHighlighted];
        }
        
        int yPointOfCap = self.isIphone5?502:402 - (majorVersion>=7?0:statusBarHeight);
        [_capBtn setFrame:CGRectMake(screenW/2-33, yPointOfCap, 66, 66)];
    }
    
    
    if(!_segmentedControl){
        if (params->showFlashControl) {
            // Create segment control for flash switch
            NSArray *itemArray = [NSArray arrayWithObjects: @"Auto", @"On", @"Off", nil];
            _segmentedControl = [[UISegmentedControl alloc] initWithItems:itemArray];
            _segmentedControl.frame = CGRectMake(5.0,15.0 + (majorVersion<7?0:statusBarHeight), 165.0, 30.0);
            _segmentedControl.segmentedControlStyle = UISegmentedControlStylePlain;
            _segmentedControl.tintColor = [UIColor whiteColor];
            [self setFlash: (kfxKUIFlashSetting)params->flash];
            [kImageCaptureCtrl setFlash:(kfxKUIFlashSetting)params->flash];
            [self updateFlashControl: _segmentedControl];
            [_segmentedControl setTag:_segmentedControlTag];
            [_segmentedControl addTarget:self action:@selector(flashControl:) forControlEvents: UIControlEventValueChanged];
            [cameraViewController.view addSubview:_segmentedControl];
            
        }
    } else{
        if(!params->showFlashControl){
           [_segmentedControl removeFromSuperview];
            _segmentedControl = nil;
        }
        else{
            [kImageCaptureCtrl setFlash:(kfxKUIFlashSetting)params->flash];
            [self setFlash: (kfxKUIFlashSetting)params->flash];
            [self updateFlashControl: _segmentedControl];
        }
    }
    
    // Add overlay image
    if (params->overlayImg) {
        UIImage * overlayImage = nil;
        NSString *fileName = [NSString stringWithUTF8String:params->overlayImg];
        NSArray *arr = [fileName componentsSeparatedByString:@"."];
        if ([arr count] == 2) {
            NSString *filePath = [[NSBundle mainBundle] pathForResource:[arr objectAtIndex:0] ofType:[arr objectAtIndex:1]];
            overlayImage = [UIImage imageWithContentsOfFile:filePath];
        }
        
        if (overlayImage) {
            if (!_backgroundImageView) {
                _backgroundImageView = [[UIImageView alloc] initWithFrame:CGRectMake(5, 55 + (majorVersion<7?0:statusBarHeight), 310, 415)];
                [_backgroundImageView setBackgroundColor:[UIColor clearColor]];
                [_backgroundImageView setContentMode:UIViewContentModeScaleToFill];
                [cameraViewController.view addSubview:_backgroundImageView];
            }
            [_backgroundImageView setImage:overlayImage];
        }
        else
            _backgroundImageView.image = nil;
    }
    else {
        if (_backgroundImageView && [_backgroundImageView superview]) {
            [_backgroundImageView removeFromSuperview];
        }
    }
    
    kImageCaptureCtrl.delegate = self;
    kImageCaptureCtrl.stabilityDelay = params->stabilityDelay;
    
    kImageCaptureCtrl.levelIndicator = params->levelIndicator;
    
    [kImageCaptureCtrl doContinuousMode:params->doContinues];
    [kImageCaptureCtrl setPageDetect:params->setPageDetect];
    
    kImageCaptureCtrl.levelThresholdPitch = params->levelThresholdPitch;
    kImageCaptureCtrl.levelThresholdRoll = params->levelTresholdRoll;
    
    kImageCaptureCtrl.deviceDeclinationPitch = params->deviceDeclinationPitch;
    kImageCaptureCtrl.deviceDeclinationRoll = params->deviceDeclinationRoll;
    
    kfxKUIFrame * kFrame = [[kfxKUIFrame alloc] init];
    kFrame.borderWidth = 3.0;
    kFrame.borderColor = [UIColor grayColor];
    kImageCaptureCtrl.imageFrame = kFrame;
    
    [cameraViewController.view addSubview:kImageCaptureCtrl];
    
    [_cancelCam setEnabled:YES];
    [_capBtn setEnabled:YES];
    // Bring controls to front
    [_backgroundImageView.superview bringSubviewToFront:_backgroundImageView];
    [_cancelCam.superview bringSubviewToFront:_cancelCam];
    [_segmentedControl.superview bringSubviewToFront:_segmentedControl];
    [_capBtn.superview bringSubviewToFront:_capBtn];
    [cameraViewController.view addSubview:_capBtn];

    // we are fixing kofax bug here [ugur]
    if (params->doContinues) {
        [kImageCaptureCtrl doContinuousMode:YES];
        [kImageCaptureCtrl takePicture];
    } else {
        [kImageCaptureCtrl doContinuousMode:NO];
    }

    // This is connected with Sprat project, as a plugin we need to cut here first
    UINavigationController *vc = (UINavigationController *)[ESpratNavigationController SMFGetNavigationController];
    [vc.topViewController presentViewController:cameraViewController animated:YES completion:^(){}];
    [[ESpratNavigationController SMFGetNavigationController] setStatusBarNotified:YES];
}

// Instance method to change the flash settings of the Image capture screen as per user choice
/**
 This method changes the Flash properties of the kfxKUIImageCaptureControl object as per user selection on the screen \n
 */

- (void)flashControl:(UISegmentedControl *)segment
{
    
    if(segment.selectedSegmentIndex==0){
        kImageCaptureCtrl.flash=kfxKUIFlashAuto;
    }
    else if (segment.selectedSegmentIndex==1){
        kImageCaptureCtrl.flash=kfxKUIFlashOn;
    }
    else{
        kImageCaptureCtrl.flash=kfxKUIFlashOff;
    }
    
    [self setFlash: kImageCaptureCtrl.flash];
}

- (void) updateFlashControl:(UISegmentedControl *)segment
{
    if ([self flash] == kfxKUIFlashAuto)
    {
        segment.selectedSegmentIndex = 0;
    }
    else if ([self flash] == kfxKUIFlashOn)
    {
        segment.selectedSegmentIndex = 1;
    }
    else
    {
        segment.selectedSegmentIndex = 2;
    }
    return;
}

// Instance method to remove the capture (Image/Barcode)
/**
 This method is to remove the capture screen (either the image capture control object or the barcode capture control object)\n
 This method removes the capture screen from the top of the application's view. \n
 This methos is not same as the delagate method "hideCaptureScreenKImg", as the delagate method is called after this \n
 method id completed. This method itself removes the capture screens from the application.\n
 
 */
-(IBAction)cancelCaptureScreen:(id)sender
{
    [kImageCaptureCtrl doContinuousMode:NO];
    /*if (kImageCaptureCtrl) {
     [kImageCaptureCtrl release];
     kImageCaptureCtrl = nil;
     }*/
    
    [self.delegate hideCaptureScreenKImg];
}


/**
 User pressed take picture button
 */
-(IBAction)forceCaptureImage {
    if (!captured) {
        captured = true;
        [_cancelCam setEnabled:NO];
        [_capBtn setEnabled:NO];
        
        [kImageCaptureCtrl doContinuousMode:NO];
        [kImageCaptureCtrl setPageDetect:NO];
        [kImageCaptureCtrl setLevelIndicator:NO];
        kImageCaptureCtrl.levelThresholdPitch = kImageCaptureCtrl.levelThresholdRoll = 46;
        
        kImageCaptureCtrl.stabilityDelay = 0;
        
        [kImageCaptureCtrl takePicture];
    }
}

#pragma mark - Capture delegate methods

//! A message that indicates that an image was captured.
/** A message that indicates that an image was captured. This will only be sent
 after the control receives a takePicture message. The control will wait until the desired
 stability, levelness, and camera adjustments are met and then capture an image and send
 it with this message.
 
 Once the Image is captured, remove(hide) the Image capture screen, and call the delegate method "capturedKImage" \n
 for any further processing with the capture kfxKEDImage 'image'
 
 */

-(void)imageCaptureControl:(kfxKUIImageCaptureControl *)imageCaptureControl imageCaptured:(kfxKEDImage*)image {
    UIView *superView = imageCaptureControl.superview;
    
    captured = true; // we should detect auto capture, before coming here...
    [_cancelCam setEnabled:NO];
    
    [kImageCaptureCtrl doContinuousMode:NO];
    
    // Show waiting screen
    CGFloat statusBarHeight = [[UIApplication sharedApplication] statusBarFrame].size.height;
    int majorVersion = [[[UIDevice currentDevice] systemVersion] intValue];
    
    UIImageView *imageView = (UIImageView*)[superView viewWithTag:kStoppedImageViewTag];
    
    if(!imageView){
        imageView = [[UIImageView alloc] initWithImage:[image getImageBitmap]];
        [imageView setTag:kStoppedImageViewTag];
        CGRect frame = CGRectMake(5, 55 + (majorVersion<7?0:statusBarHeight), 310, 415);
        //CGRectMake(5, 56 + statusBarHeight, 310, (_isIphone5 ? 470 + statusBarHeight : (410 + statusBarHeight + 56)) - (statusBarHeight + 56));
        [imageView setFrame:frame];
        [imageView setContentMode:UIViewContentModeScaleToFill];
        [superView addSubview:imageView];
        if (!_isIphone5) {
            for (UIView *v in superView.subviews) {
                if (v != imageView && v != kImageCaptureCtrl)
                    [superView bringSubviewToFront:v];
            }
        }
    }
    else{
        [imageView setImage:[image getImageBitmap]];
        [imageView.superview bringSubviewToFront:imageView];
    }
    
    UIActivityIndicatorView *activity = (UIActivityIndicatorView*)[superView viewWithTag:activityIndicatorTag];
    
    if (!activity) {
        activity = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhiteLarge];
        [activity setTag:activityIndicatorTag];
        [activity startAnimating];
        [activity setCenter:[imageView center]];
        [activity setHidesWhenStopped:YES];
        [superView addSubview:activity];
        
    } else {
        [activity startAnimating];
        [activity.superview bringSubviewToFront:activity];
    }
    
    
    dispatch_async( dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        @autoreleasepool {
            UIImage *img = [UIImage imageWithCGImage:[image getImageBitmap].CGImage];
            [self.delegate capturedKImage:&img];

            dispatch_async(dispatch_get_main_queue(), ^{
                imageView.image = nil;
                [activity stopAnimating];
            });
        }
    });
}

#pragma mark - Process methods

/// Instance method to process a kfxKEDImage
/**
 This method processes a kfxKEDImage wth the engine kfxKENImageProcessor of the singleton calss\n
 The Image perfection profile with which the image to be processed is mentioned as the input parameter \n
 After the processing is completed, the singleton calls the delegate  method " processedKImage " \n
 @param kImgae : an image reference to kfxKEDImage, to be procesed \n
 @param kIPP : a reference to kfxKEDImagePerfectionProfile, with which the imput iamge to be processed by the processor engine \n
 */

-(void) processCapturedKImg:(kfxKEDImage *)kImgae WithIPP:(kfxKEDImagePerfectionProfile *)kIPP
{
    captureImageProcessor.imagePerfectionProfile = kIPP;
    captureImageProcessor.delegate = self;
    [captureImageProcessor processImage:kImgae];
}

#pragma mark - Process delegate methods

//!  Image Out Delegate
/**
 The Engine calls this method after an image is generated by image processing.\n
 This is a required delegate. The output image contains the processed image if no error was detected.\n
 @param  status : Set to KMC_SUCCESS if no error occurred, otherwise an error code.
 @param  errorMsg : A description of the error that occurred.
 @param  kfxImage : An output image reference when image processing completed without error.
 
 After processing the input image, call the delagate method "processedKImage" for further processing.
 
 */
- (void)imageOut:(int)status withMsg: (NSString*) errorMsg andOutputImage: (kfxKEDImage*) kfxImage
{
    [self.delegate processedKImage:kfxImage withError:errorMsg];
}
- (void)processProgress: (int) status withMsg: (NSString*) errorMsg imageID: (NSString*) imageID andProgress: (int) percent
{
    
}
- (void)analysisComplete:(int)status withMsg: (NSString*) errorMsg andOutputImage: (kfxKEDImage*) kfxImage
{
    
}

- (void)analysisProgress: (int) status withMsg: (NSString*) errorMsg imageID: (NSString*) imageID andProgress: (int) percent
{
    
}


@end

#endif
