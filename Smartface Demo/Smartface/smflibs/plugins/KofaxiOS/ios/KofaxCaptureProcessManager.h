//
// Copyright (c) 2012-2014 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>
#import "KofaxConstant.h"

#ifdef KOFAX_ENABLED

#import "kfxLibUtilities/kfxUtilities.h"
#import "kfxLibLogistics/kfxLogistics.h"
#import "kfxLibUIControls/kfxUIControls.h"
#import "kfxLibEngines/kfxEngines.h"

class OptionParameter;

#pragma mark - KofaxCaptureProcessDelegate

@protocol KofaxCaptureProcessDelegate <NSObject>

@optional


///  Capture Image Delegate
/**
 This Singleton  calls this method after an image is captured by the  kfxKUIImageCaptureControl.\n
 This is an optional delegate. The output image contains the captured image if no error was detected.\n
 @param  imageDataPtr : The captured image reference when an image is captured with  kfxKUIImageCaptureControl without error.
 */

-(void) capturedKImage:(UIImage **)imageDataPtr;


///  Processed Image Delegate
/**
 This Singleton  calls this method after an image is processed by the engine  kfxKENImageProcessor.\n
 This is an optional delegate. The output image contains the processed image if no error was detected.\n
 @param  IPPKImg : an  image reference when an image is processed with  kfxKENImageProcessor without error.
 */

-(void) processedKImage:(kfxKEDImage *)IPPKImg;
-(void) processedKImage:(kfxKEDImage *)IPPKImg withError:(NSString *)error;

///  Capture Process Completed  Delegate .
/**
 This Singleton  calls this method after an image is is captured or the bar code is read.\n
 This is an optional delegate. \n
 This method is called after the capture object (either kfxKUIImageCaptureControl or kfxKUIBarCodeCaptureControl) is removed.
 */

-(void) hideCaptureScreenKImg;

@required

@end

#pragma mark - KofaxCaptureProcessManager

@interface KofaxCaptureProcessManager : NSObject<kfxKIPDelegate, kfxKUIImageCaptureControlDelegate, kfxKUIBarCodeCaptureControlDelegate> {

}


@property (assign) id <KofaxCaptureProcessDelegate>  delegate;

/// Class Method to create an instance of the Singleton class
/**
 This method returns(creates if not already created) an object for the singleton class either \n
 a kfxKUIImageCaptureControl & kfxKENImageProcessor together  or an available \n
 kfxKUIBarCodeCaptureControl object. \n
 
*/
+(id) sharedClassInstance;

/// Instance Method to present the kfxKUIImageCaptureControl, to capture an image
/**
 This method presents the kfxKUIImageCaptureControl object  on top of the current view of the application \n
 to capture an image. Once the image is captured, the capture screen is automatically removed from the screen. \n
 Also, the user can chaneg the flas settings on the presented capture screen  along with an option to cancel the screen \n
*/

-(void) presentCaptureScreenKImg;
-(void) presentCaptureScreenKImgWithOptions:(OptionParameter *)params;

// Instance method to remove the image capture screen
/**
 This method is to remove the image capture screen \n
 This method removes the capture screen from the top of the application's view. \n
 This methos is not same as the delagate method "hideCaptureScreenKImg", as the delagate method is called after this \n
 method is completed. This method itself removes the capture screen from the application.\n
 
 */
-(IBAction)cancelCaptureScreen:(id)sender;

/// Instance method to process a kfxKEDImage
/**
 This method processes a kfxKEDImage wth the engine kfxKENImageProcessor of the singleton calss\n
 The Image perfection profile with which the image to be processed is mentioned as the input parameter \n
 After the processing is completed, the singleton calls the delegate  method " processedKImage " \n
 @param kImgae : an image reference to kfxKEDImage, to be procesed \n
 @param kIPP : a reference to kfxKEDImagePerfectionProfile, with which the imput iamge to be processed by the processor engine \n
*/
-(void) processCapturedKImg: (kfxKEDImage *)kImgae WithIPP:(kfxKEDImagePerfectionProfile *)kIPP;

@end

#endif
