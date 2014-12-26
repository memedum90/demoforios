//  API Reference
//
//  kfxKEDBasicSettingsProfile.h
//  KMCEngineData Objects
//
//  Created by Mark Day on 7/23/13.
//  Copyright (c) 2012 - 2014 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>
#ifndef KEDBASICSETTNGSPROFILE
#define KEDBASICSETTNGSPROFILE

#import "kfxKEDBoundingTetragon.h"


typedef enum {
	KED_ROTATE_NONE,
	KED_ROTATE_90,
    KED_ROTATE_180,
    KED_ROTATE_270,
    KED_AUTOMATIC
} KEDRotationOptions;

typedef enum {
	KED_BITDEPTH_BITONAL = 1,
	KED_BITDEPTH_GRAYSCALE = 8,
    KED_BITDEPTH_COLOR = 24
} KEDOutputColor;

typedef enum {
    KED_CROP_NONE,
    KED_CROP_AUTO,
    KED_CROP_TETRAGON,
    KED_CROP_WITH_QUICK_ANALYSIS_RESULTS,
    KED_CROP_LAST
} KEDCroppingOptions;

//! Basic Settings Profile Specifies Image Processing options
/**
 Framework: libKfxEngines\n
 Import suggestion: #import <kfxLibEngines/kfxEngines.h>\n
 An instance of this class contains the simple image processing options that you want to perform on an image. These define the standard crop, deskew and rotation options. You can also use this object to specify the output image DPI and the desired color. You specify the output color by setting outputBitDepth to 1 for bitonal images, 8 for grayscale, or 24 for color. The image processor outputs a new image with the bitmap in one of these colors. The cropping Tetragon defines bounding corner points of an area of an image that you want to crop, and override automatic page detection.\n

 If the outputDPI is >= 300 DPI, and the outputBitDepth is 1, then the image processing includes enhanced binarization, otherwise it uses standard binarization.\n\n
**Serialization**
\n\n
 This class adopts the NSCoding protocol so that this object may be archived and unarchived using the iOS standard [NSKeyedArchiver archiveRootObject:<object> toFile: archiveFileName]; approach.  Using keyed archive files, you can save this object for later use.  The library supports backward compatibility, such that as a new version of an app that uses the API in this SDK, includes a newer versions of the SDK libraries that have data model changes, the older archive can still be read by the newer version.  However, it is not a design goal to archive and dearchive with forward compatibility, such as decoding an archive on a newer version of the class, using an older library.\n\n
 Refer to the kfxKEDImage class description, by expanding the class description, that describes how to archive and unarchive objects in this framework that adopt the NSCoding protocol.\n
 You can create keyed archives using NSKeyedArchiver objects and decoded by NSKeyedUnarchiver objects. The framework design uses keyed archives, which differ from sequential archives, in that every value encoded in a keyed archive is given a Kofax unique key name. When you decode an archive, the underlying implementation can use values by name, allowing the unarchive delegate to request values in any order or not at all.\n
 
 Please refer to the Apple documentation for more information: https://developer.apple.com/library/ios/documentation/cocoa/reference/foundation/Classes/NSCoder_Class/Reference/NSCoder.html
 \n\n
 *Keyed Archiving*
 https://developer.apple.com/library/mac/documentation/Cocoa/Reference/Foundation/Classes/NSKeyedArchiver_Class/Reference/Reference.html#//apple_ref/occ/cl/NSKeyedArchiver
 \n\n
 *Keyed Unarchiving*
 https://developer.apple.com/library/mac/documentation/Cocoa/Reference/Foundation/Classes/NSKeyedUnarchiver_Class/Reference/Reference.html#//apple_ref/occ/instm/NSKeyedUnarchiver

 */
@interface kfxKEDBasicSettingsProfile : NSObject <NSCoding>

// ==========================================================
//! Rotate automatically or by 90 degree options
/**
 Provides a simple way to enable rotation using the enum options in KEDRotationOptions.
 Default: false
 */
@property KEDRotationOptions    doRotate;

// ==========================================================
//! Crop image to a user specified option
/**
 Provides a simple way to crop an image. Choose from three options specified in the KEDCroppingOptions enum.\n
 KED_CROP_NONE: Set this option to perform no image cropping.\n
 KED_CROP_AUTO: The library automatically finds the bounding tetragon around the document of interest, and crops to this boundary. Automatic cropping entails finding page boundaries, stretching the image into a rectangle if necessary, and cropping the image to the found sheet boundaries. This means that, in order to crop, the input image should have some sheet borders.\n
 KED_CROP_TETRAGON: Use this option when you want to supply the tetragon around the page edges. This boundary is defined externally by the Review and Edit UI control, or automatically by image processing.\n
 Default: KED_CROP_NONE
 */
@property KEDCroppingOptions    doCrop;

// ==========================================================
//! Deskew an output image
/**
 Provides a simple way to deskew an image when set to true. The image processor deskews the image after it is properly cropped to sheet boundaries.
 Default: false
 */
@property bool                  doDeskew;

// ==========================================================
//! Length of the shortest edge of the original
/**
 Use this property to set the length of the shortest edge of the original document in inches. The library uses this parameter to correctly estimate the output image DPI and also helps algorithms better estimate document corners, especially when one is outside the boundary of the image. You need not set both short and long edges, the algorithm uses one if it is present. If you set it to 0.0, then the library will not use this parameter.
 Default: 0.0
 */
@property float                  inputDocShortEdge;

// ==========================================================
//! Length of the longest edge of the original
/**
 Use this property to set the length of the longest edge of the original document in inches. The library uses this parameter to correctly estimate the output image DPI and also helps algorithms better estimate document corners, especially when one is outside the boundary of the image. You need not set both short and long edges, the algorithm uses one if it is present. If you set it to 0.0, then the library will not use this parameter.
 Default: 0.0
 */
@property float                 inputDocLongEdge;

// ==========================================================
//! Tetragon corner points defining the image cropping limits.
/**
 Use this object to specify the corner points of a tetragon (or rectangle) for cropping an image. If this object contains any point coordinates that are non-zero, the image processing (IP) engine will not perform automatic page detection, but will use these coordinate points instead. It may represent a rectangle, in which case the image will not be stretched to make it into a rectangle. If the corners represent a tetragon, the cropped image will be cropped to these coordinages and stretched to adjust an image of a document that was skewed in three orientations.  If the bounding rectangle coordinates are all 0, then no manual cropping is performed by the image processing engine. Instead the image processor will perform normal page detection using internal algorithms to find page edges, crop (if enabled) and stretch using these page edges.
 
 */
@property kfxKEDBoundingTetragon *croppingTetragon;


// ==========================================================
//! Desired Output image DPI
/**
 Use this property to set the desired output image DPI (Dots Per Inch). If you set it to 0, then the library will automatically detect the output image DPI and indicate it in the output object.
 Default: 0
 */
@property (nonatomic) int outputDPI;


// ==========================================================
//! Desired Output image color
/**
 Use this method to set the desired output image color enum setting. This should be set to one of the available values in the KEDOutputColor enum.\n
 @return KMC_ED_INVALID_COLOR if the outputBitDepth is invalid, and not one of the enum values.
 */
@property (nonatomic) KEDOutputColor outputBitDepth;

-(int) specifyOutputBitDepth:(KEDOutputColor)outputBitDepth;

// ==========================================================
//! Desired Output DPI
/**
 Use this method to set the desired output image DPI setting. The valid range is from 0-5000 DPI.\n
 @return KMC_ED_INVALID_DPI when the DPI is invalid.
 */
- (int) specifyOutputDPI: (int) dpi;


// ==========================================================
//! Init defaults for a basic settings profile
/**
 Use this method to create a basic settings profile object for use in your app.\n
 The method sets up the object with the defaults. You may modify them of course after you get your object reference.\n
 doRotate = KED_ROTATE_NONE;\n
 doCrop = KED_CROP_NONE;\n
 doDeskew = false;\n
 outputDPI = 0;\n
 outputBitDepth = KED_BITDEPTH_COLOR;\n
 inputDocShortEdge = 0.0;\n
 inputDocLongEdge = 0.0;\n
 croppingTetragon = [[kfxKEDBoundingTetragon alloc] init];\n
 @code
 kfxKEDBasicSettingsProfile * myBasic;
 myBasic = [[kfxKEDBasicSettingsProfile alloc] init];
 @endcode
 @return A kfxKEDBasicSettingsProfile object
 */
- (id)init;

// ==========================================================
//! Init defaults for a bitonal image
/**
 Use this method to create a basic settings profile object for use in your app.\n
 The method sets the following parameters automatically for you. You may modify them of course after you get your object reference...
 doRotate = KED_AUTOMATIC;\n
 doCrop = KED_CROP_AUTO;\n
 doDeskew = true; \n
 outputDPI = <the dpi you specified>;\n
 outputBitDepth = KED_BITDEPTH_BITONAL; \n
 inputDocShortEdge = 0.0; \n
 inputDocLongEdge = 0.0; \n
 croppingTetragon = [[kfxKEDBoundingTetragon alloc] init]; // Ready for adding\n
 @code
 kfxKEDBasicSettingsProfile * myBasic;
 myBasic = [[kfxKEDBasicSettingsProfile alloc] initForStandardBitonalWithDPI:300];
 @endcode
 @return A kfxKEDBasicSettingsProfile object
 */
- (id)initForStandardBitonalWithDPI: (int) dpi;

// ==========================================================
//! Init defaults for a grayscale image
/**
 Use this method to create a basic settings profile object for use in your app.\n
 The method sets the following parameters automatically for you.  You may modify them of course after you get your object reference...
 doRotate = KED_AUTOMATIC;\n
 doCrop = KED_CROP_AUTO;\n
 doDeskew = true; \n
 outputDPI = <the dpi you specified>;\n
 outputBitDepth = KED_BITDEPTH_GRAYSCALE; \n
 inputDocShortEdge = 0.0; \n
 inputDocLongEdge = 0.0; \n
 croppingTetragon = [[kfxKEDBoundingTetragon alloc] init]; // Ready for adding\n
 @code
 kfxKEDBasicSettingsProfile * myBasic;
 myBasic = [[kfxKEDBasicSettingsProfile alloc] initForStandardGrayscaleWithDPI:200];
 @endcode
 @return A kfxKEDBasicSettingsProfile object
 */
- (id)initForStandardGrayscaleWithDPI: (int) dpi;

// ==========================================================
//! Init defaults for a color image
/**
 Use this method to create a basic settings profile object for use in your app.\n
 The method sets the following parameters automatically for you.  You may modify them of course after you get your object reference...
 doRotate = KED_AUTOMATIC;\n
 doCrop = KED_CROP_AUTO;\n
 doDeskew = true; \n
 outputDPI = <the dpi you specified>;\n
 outputBitDepth = KED_BITDEPTH_COLOR; \n
 inputDocShortEdge = 0.0; \n
 inputDocLongEdge = 0.0; \n
 croppingTetragon = [[kfxKEDBoundingTetragon alloc] init]; // Ready for adding\n
 @code
 kfxKEDBasicSettingsProfile * myBasic;
 myBasic = [[kfxKEDBasicSettingsProfile alloc] initForStandardColorWithDPI:240];
 @endcode
 @return A kfxKEDBasicSettingsProfile object
 */
- (id)initForStandardColorWithDPI: (int) dpi;


// ==========================================================
//! Generate a string from cropping option given
/**
 Use this method to generate a string that represents the meaning of the cropping option given to this class method.  This is useful for debugging when you want to display the contents of the basic settings profile object.
 @see KEDCroppingOptions
 @return NSString* defining the current definition of the option.
*/
+(NSString *) decodeCroppingOption: (KEDCroppingOptions) option;


// ==========================================================
//! Generate a string from the bitDepth option given
/**
 Use this method to generate a string that represents the meaning of the outputcolor option given to this class method.  This is useful for debugging when you want to display the contents of the basic settings profile object.
 @see KEDOutputColor
 @return NSString* defining the current definition of the option.
 */
+(NSString *) decodeBitDepth:       (KEDOutputColor) option;


// ==========================================================
//! Generate a string from rotations option given
/**
 Use this method to generate a string that represents the meaning of the rotation option given to this class method.  This is useful for debugging when you want to display the contents of the basic settings profile object.
 @see KEDRotationOptions
 @return NSString* defining the current definition of the option.
 */
+(NSString *) decodeRotateOpt:      (KEDRotationOptions) option;

@end
#endif

