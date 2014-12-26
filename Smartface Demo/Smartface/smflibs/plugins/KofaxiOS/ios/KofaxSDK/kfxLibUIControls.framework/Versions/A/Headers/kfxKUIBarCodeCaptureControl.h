//
//  KMC SDK API Reference file
//  kfxKUIBarCodeCaptureControl.h
//  Framework: kfxLibUIControls
//
//  Copyright (c) 2012 - 2014 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <UIKit/UIKit.h>
#import <CoreMotion/CoreMotion.h>

#import "kfxKUICommon.h"

@class kfxKEDBarcodeResult;
@class kfxKEDImage;
@class kfxKUIBarCodeCaptureControl;

//! This protocol must be implemented by classes whose objects are used as kfxKUIBarCodeCaptureControl delegates
/**
 This defines protocol messages that will be sent to kfxKUIBarCodeCaptureControl delegate
 objects.
 */
@protocol kfxKUIBarCodeCaptureControlDelegate <NSObject>

@optional

//! A message that indicates that a barcode was found.
/** A message that indicates that a barcode was found. This will only be sent
 after the control receives a readBarcode message. The control will wait until the desired
 stability, levelness, and camera adjustments are met and then feed preview images to the
 barcoding engine. Once the barcoding engine detects a barcode according to the current
 symbology and direction settings, the decoded message and image will be sent with this message.  */
-(void)barcodeCaptureControl:(kfxKUIBarCodeCaptureControl *)barcodeCaptureControl
             barcodeFound:(kfxKEDBarcodeResult *)result image:(kfxKEDImage*)image;

@end

//! This class renders the camera preview to the screen and searches for barcodes.
/**
 This view provides visual guidance to the end-user to maximize the changes of correctly decoding
 a barcode.  Once the view has been asked to read a barcode, it will search continuously until
 one is found.
 */
@interface kfxKUIBarCodeCaptureControl : UIView

//! This message initializes the control and must be sent to the class before it is used.
/**
 This message initializes the control for use and must be sent to the class before it is used.
 It is ok to send the message more than once. A common way to do this is in your UIViewController
 subclasses initialize or init methods.
 */
+(void) initializeControl;

/// The current guiding line setting.
/**
 The guiding line is a visual aid for aligning barcodes within the preview.
 A guiding line is rendered as a straight line splitting the preview into
 two equal parts.  The intention is for the line to cross through all the
 bars of a barcode, like the laser of a linear scanner.  The guiding line
 is turned off by default.
 
 Acceptable values are: kfxKUIGuidingLineOff, kfxKUIGuidingLineLandscape, 
 and kfxKUIGuidingLinePortrait.
 */
@property (nonatomic) kfxKUIGuidingLine guidingLine;

/// The set of symbologies currently being searched for.
/**
 Searching for multiple symbologies slows down the speed of barcode recognition.
 You should only specify the symbologies that you are interested in reading.  The
 set of selected symbologies is empty by default.
 
 @see kfxKUISymbology for all supported values.
 @code
 barcodeControl.symbologies = @[@(kfxKUISymbologyCode39), @(kfxKUISymbologyPDF417)];
 @endcode
 */
@property (nonatomic, strong) NSArray * symbologies;

/// The set of directions currently being seached for barcodes.
/**
 Searching multiple directions slows down the speed of barcode recognition.  If you
 expect barcodes to only be oriented in certain directions, you should specify only
 those directions.  By default, all directions will be searched, represented by
 the array [kfxKUIDirectionHorizontal, kfxKUIDirectionVertical].
 
 @see kfxKUISearchDirection for all supported values.
 @code
 barcodeControl.searchDirection = @[@(kfxKUIDirectionHorizontal)];
 @endcode
 */
@property (nonatomic, strong) NSArray * searchDirection;

/// Gets the camera preview resolution.
/**
 A read-only property to get the resolution of the camera preview.  This value will vary depending
 on the target device and its camera capabilities.
 */
@property (readonly, nonatomic) CGSize imagePreviewSize;

/// A delegate to receive messages from the control
/** 
 A property to get or set the delegate that will be notified of stability, levelness and 
 found barcodes.
 */
@property (nonatomic, strong) IBOutlet id<kfxKUIBarCodeCaptureControlDelegate> delegate;

/// Reads a single barcode from the camera preview.
/**
 This call returns immediately and starts asynchronously searching for
 a barcode with the current camera and barcode parameters.  The search
 will continue indefinitely until a barcode is found, allowing time for
 the device to further stabilize and focus if necessary.
 
 Once a barcode is positively read, the delegate will receive a
 barcodeCaptureControl:barcodeFound:image message.
 
 @retval    KMC_SUCCESS      The bar code was successfully read.
            KMC_EV_LICENSING The bar code was not set successfully read, and returned the licensing error code.
 */
-(int)readBarcode;

@end
