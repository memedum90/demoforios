//  API Reference
//  kfxKEDClassificationResult.h
//
//  KMCEngineData Objects
//
//  Created by Mark Day on 7/23/13.
//  Copyright (c) 2012 - 2014 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>
#import "kfxKEDImage.h"

typedef enum {
    KED_CLASSIFY_UNKNOWN = 0,
	KED_CLASSIFY_0,
	KED_CLASSIFY_90,
    KED_CLASSIFY_180,
    KED_CLASSIFY_270,
    KED_CLASSIFY_LAST
} KEDClassifierOrientation;

//! A single classification result
/**
 Framework: libKfxEngines\n
 Import suggestion: #import <kfxLibEngines/kfxEngines.h>\n
 
 An instance of this class contains one possible image classification for the image analyzed by the classier. The result includes the ID of the classification, the orientation of the original image for reference, and the confidence level for this item.\n\n
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
@interface kfxKEDClassificationResult : NSObject <NSCoding>

// ==========================================================
//! Image classification ID
/**
 This defines the ID that the classifier thinks is associated with this image.
 Default: nil
 */
@property (retain) NSString* classID;


// ==========================================================
//! Orientation of the image used with classification
/**
 This defines reference orientation of the image as detected by the image classifier, for reference purposes. Set to one of the KEDClassifierOrientation enum setting.
 Default: KED_CLASSIFY_UNKNOWN
 */
@property KEDClassifierOrientation orientation;

// ==========================================================
//! Classification confidence
/**
 This value indicates how confident the classifer is to identify the specified classID for the input image. This value can be either negative, 0 or a positive value. Higher positive values indicate higher confidence, whereas lower negative values indicate lower confidence.
 Default: -5000
 */
@property (assign, atomic) float confidence;

// ==========================================================
//! Initialize the class instance
/**
 Use this method in your typical [[class alloc] init]; code lines to initialize an instance of this class with the standard defaults.
 */
- (id)init;

+(NSString*) decodeClassifierOrientation: (KEDClassifierOrientation) orientation;
@end
