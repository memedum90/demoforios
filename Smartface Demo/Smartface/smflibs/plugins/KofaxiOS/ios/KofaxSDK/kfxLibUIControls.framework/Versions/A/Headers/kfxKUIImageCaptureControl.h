//
//  API Reference
//  kfxKUIImageCaptureControl.h
//  Framework: kfxLibUIControls
//
//  Copyright (c) 2012 - 2014 Kofax. Use of this code is with permission pursuant to Kofax license terms.


#import <UIKit/UIKit.h>
#import <CoreMotion/CoreMotion.h>

#import "kfxKUICommon.h"
#import "kfxKUIFrame.h"

@class kfxKEDImage;
@class kfxKUIImageCaptureControl;

//! This protocol must be implemented by classes whose objects are used as kfxKUIImageCaptureControl delegates
/**
 This defines protocol messages that will be sent to kfxKUIImageCaptureControl delegate
 objects.
 */
@protocol kfxKUIImageCaptureControlDelegate <NSObject>

@optional
//! A message that indicates the current stability of the device.
/** A message that indicates the current stability, which is a number from
 0-100, where 100 means that the device is completely stable and 0 is the
 maximum instability.
 */
-(void)imageCaptureControl:(kfxKUIImageCaptureControl*)imageCaptureControl
            stabilityDelay:(int) stabilityDelay;

//! A message that indicates that an image was captured.
/** A message that indicates that an image was captured. This will only be sent
 after the control receives a takePicture message. The control will wait until the desired
 stability, levelness, and camera adjustments are met and then capture an image and send
 it with this message.
 */
-(void)imageCaptureControl:(kfxKUIImageCaptureControl *)imageCaptureControl
             imageCaptured:(kfxKEDImage*)image;

//! A message that indicates the current pitch and roll.
/** A message that indicates the current angles of pitch and roll of the device.
 Both pitch and roll are angles in degrees.
 */
-(void)imageCaptureControl:(kfxKUIImageCaptureControl *)imageCaptureControl
            pitchChangedTo:(int)pitch rollChangedTo:(int)roll;

//! A message that indicates the camera has begun or finished focusing.
/** A message that indicates the camera has begun or finished focusing, where the boolean value NO indicates the camera is focusing, or YES, that focusing is complete
 */
-(void)imageCaptureControl:(kfxKUIImageCaptureControl *)imageCaptureControl
         focusStateChanged:(BOOL)isFocused;

@end


//! This class renders the camera preview to the screen and returns an image.
/**
 This class is responsible for rendering the camera preview and provides visual level and stability feedback to
 guide the user to take a clear, legible photo of a document.
 */
@interface kfxKUIImageCaptureControl : UIView

//! This message initializes the control and must be sent to the class before it is used.
/**
This message initializes the control for use and must be sent to the class before it is used.
 It is ok to send the message more than once. A common way to do this is in your UIViewController
 subclasses initialize or init methods.
 */
+(void) initializeControl;

/// The current stability delay.
/** A property to get or set the current stability delay. If not set, it defaults to 75.
 
 It is a number from 0 to 100, where 100 indicates that the device must be near perfectly still
 to take a picture and 0 indicates that stability checking is turned off.
 */
@property (nonatomic) int stabilityDelay;

/// The current camera flash mode.
/**
 A property to get or set the flash mode, with three values: kfxKUIFlashOn, kfxKUIFlashOff, and kfxKUIFlashAuto.
 */
@property (nonatomic) kfxKUIFlashSetting flash;

/// The kfxKUIFrame object
/**
 A property to get or set the kfxKUIFrame object that puts a visual frame around the image
 */
@property (nonatomic, strong) kfxKUIFrame* imageFrame;

/// Whether the level indicator is enabled.
/**
 A boolean that indicates whether the level indicator is enabled.
 */
@property (nonatomic) BOOL levelIndicator;

/// Whether page detection is enabled.
/**
 A boolean that indicates whether page detection is enabled or not.  Page detection adds an aditional
 constraint to image capture such that an image will not be captured until a document is detected
 within the viewfinder.
 */
@property (nonatomic) BOOL pageDetect;

//! The threshold to use determine if the device is level enough
/** An angle in degrees that is used when comparing the actual pitch of the device
 to the deviceDeclinationPitch. If the difference is less than the threshold, the device
 is considered level with respect to pitch. The default value is 7.
 
 Valid values are in the range [0, 45].  Values outside this range will be interpreted as 0 or 45.  A value
 of 45 disables level checking for pitch.
 */
@property (nonatomic) int levelThresholdPitch;

//! The threshold to use determine if the device is level enough
/** An angle in degrees that is used when comparing the actual roll of the device
 to the deviceDeclinationRoll. If the difference is less than the threshold, the device
 is considered level with respect to roll. The default value is 7.
 
 Valid values are in the range [0, 45].  Values outside this range will be interpreted as 0 or 45.  A value
 of 45 disables level checking for roll.
 */
@property (nonatomic) int levelThresholdRoll;

/// The reference pitch that indicates what angle means that the device is level
/** A property to get or set an angle in degrees that will be used to determine that the device
 is level. The default value is 0, which indicates that the top and bottom of the device are in 
 the same horizontal plane. A positive value indicates that the top of the device should be higher 
 than the bottom for the device to be considered level, and a negative value means that the bottom should be higher.
 */
@property (nonatomic) int deviceDeclinationPitch;


/// The reference roll that indicates what angle means that the device is level
/** A property to get or set an angle in degrees that will be used to determine that the device
 is level. The default value is 0, which indicates that the left and right sides of the device are in
 the same horizontal plane. A positive value indicates that the left side of the device should be higher 
 than the right for the device to be considered level, and a negative value means that the right side should be higher.
 */
@property (nonatomic) int deviceDeclinationRoll;

/// The color used by the level indicator to show the device is not level.
/**
 The level indicator will be drawn with this color when the device is tilted outside
 the limits of the level thresholds for pitch and roll.  This indicator color takes
 precedence over stability and focus, if the device is either unstable or out of focus,
 in addition to being out of level.
 
 All color values are valid.  This status color defaults to red.
 */
@property (nonatomic, strong) UIColor* indicatorColorNotLevel;

/// The color used by the level indicator to show the device is not stable.
/**
 The level indicator will be drawn with this color when the device is less stable than what
 is allowed by the set stabilityDelay threshold.  This indicator color takes precedence over 
 focus if the device is also out of focus.  If the device is out of level, the level indicator 
 color takes precedence instead.
 
 All color values are valid.  This status color defaults to blue.
 */
@property (nonatomic, strong) UIColor* indicatorColorNotStable;

/// The color used by the level indicator to show the device is out of focus.
/**
 The level indicator will be drawn with this color when the device is trying to focus or unable
 to focus.  If the device is out of level or unstable in addition to being out of focus, those 
 indicator colors take precedence.
 
 All color values are valid.  This status color defaults to yellow.
 */
@property (nonatomic, strong) UIColor* indicatorColorFocusing;

/// The color used by the level indicator to show the device is level, stable, and focused.
/**
 The level indicator will be drawn with this color when the device is within acceptable thresholds
 for levelness, stability, and focus.
 
 All color values are valid.  This status color defaults to green.
 */
@property (nonatomic, strong) UIColor* indicatorColorGood;

/// Gets the camera preview resolution.
/**
 A read-only property to get the resolution of the camera preview.  This value will vary depending
 on the target device and its camera capabilities.
 */
@property (readonly, nonatomic) CGSize imagePreviewSize;

/// A delegate to receive messages from the control
/** A property to get or set the delegate that will be notified of stability, levelness and 
 captured images.
 */
@property (nonatomic, strong) IBOutlet id<kfxKUIImageCaptureControlDelegate> delegate;

/// The motion manager being used to detect the levelness of the device
/** A property to get or set the motion manager to use to detect the levelness of the device.
 If this is never set, one will be allocated which is available to use if the application wants
 to get motion events at the same time as the control.  It may also be set, but that must be done
 in the view controller's viewDidLoad or before.
 */
@property (nonatomic, strong) CMMotionManager* motionManager;

/// Begins the image capture process.
/**
 Calling this method will start the process of monitoring the various sensors to determine when
 a level, focused, and non-blurry shot of the document can be taken. The default level indicator will not be rendered
 unless the levelIndicator property is set to true. The delegate will receive a imageCaptureControl:imageCaptured: message for each captured image.
 
 @retval    KMC_SUCCESS      The picture was successfully captured.
            KMC_EV_LICENSING The picture was not successfully captured, and returns the licensing error code.
 */
-(int)takePicture;


/// Starts or stops the continuous capture of images.
/**
 Calling this method will start or stop the continuous capture of images.  Images will automatically be captured
 when levelness and stability criteria are satisfied.  Between each image capture event, the device must be tilted
 away from its set device declination.  This signals the device to capture a new image when levelness and stability 
 criteria are again satisfied.
 
 Continuous mode can only be enabled when the levelness thresholds for pitch and roll are less than 75 degrees.
 
 @param     enable          YES to start continuous mode, NO to stop it.
 
 @retval    KMC_SUCCESS      The continuous mode was set successfully.
            KMC_EV_LICENSING The continuous mode was not set successfully, and returns the licensing error code.
 */
-(int)doContinuousMode:(BOOL)enable;

@end




