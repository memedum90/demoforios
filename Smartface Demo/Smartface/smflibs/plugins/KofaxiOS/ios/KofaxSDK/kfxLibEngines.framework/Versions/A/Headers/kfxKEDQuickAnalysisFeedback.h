//  API Reference
//
//  kfxKEDQuickAnalysisFeedback.h
//  KMCEngineData Objects
//
//  Created by Mark Day on 7/24/13.
//  Copyright (c) 2012 - 2014 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreGraphics/CoreGraphics.h>
#ifndef KEDQUICKANALYSISFEEDBACK
#define KEDQUICKANALYSISFEEDBACK 1
#import "kfxKEDBoundingTetragon.h"


@class kfxKEDImage;     // Forward declaration

//! Quick Analysis Results Feedback Class
/**
 Framework: libKfxEngines\n
 Import suggestion: #import <kfxLibEngines/kfxEngines.h>\n
 An instance of this class contains the result of an image quick analysis so that you can confirm if the app user took a good picture. If the image is blurry, over or under saturated, you should prompt your app user to retake the image of the target sheet.  If it is not blurry and does not have any saturation issues, then the tetragon corners indicate the sheet boundary found in the input image.\n\n
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
@interface kfxKEDQuickAnalysisFeedback : NSObject <NSCoding>

// ==========================================================
//! Quick review image
/**
 The image processor generates this native image object if the quick analysis completed without error.  This image includes a green border surrounding what the libary thinks constitutes the boundary of the target sheet of interest in the larger image.\n  Your app could obtain this image, and display it for review in order to confirm that the image is correct for further use.
 Default: nil
 */
@property (retain) UIImage* quickReviewUIImage;

// ==========================================================
//! Image blurry indicator
/**
 The image processor sets this to true if the input image is blurry.
 Default: false;
 */
@property bool isBlurry;


// ==========================================================
//! Over-saturated image indicator
/**
 The image processor sets this to true if it detects that the input image is over saturated.
 Default: false;
 */
@property bool isOverSaturated;


// ==========================================================
//! Under-saturated image indicator
/**
 The image processor sets this to true if it detects that the input image is undersaturated.
 Default: false;
 */
@property bool isUnderSaturated;


// ==========================================================
//! Tetragon corner data for the sheet edges found automatically.
/**
 The image processor indicates the corners of the sheet found in the input image, if a valid sheet was detected. You can then edit and crop the same image with these coordinates using a basic settings profile initialized with these same coordinates.
 Default: an initialized object.
*/
@property (retain) kfxKEDBoundingTetragon* tetragonCorners;


// ==========================================================
//! Initialize the class instance
/**
 Use this method in your typical [[class alloc] init]; code lines to initialize an instance of this class with the standard defaults.
 */
- (id) init;

// ==========================================================
//! Parse image metadata, create, and instantiate Quick Analysis Feedback Object.
/**
 Given an NSString containing the Quick Analysis metadata, this class method parses the data. It then creates the Quick Analysis Feeback object and initializes the object properties with the parsed image information from the metadata.
 @code
 kfxKEDQuickAnalysisFeedback* quickAnalysisResult = [kfxKEDQuickAnalysisFeedback createQuickFromMetadata: metaData];
@endcode
 */
+(kfxKEDQuickAnalysisFeedback *) createQuickFromMetadata: (NSString *) metadata;

@end

#endif

