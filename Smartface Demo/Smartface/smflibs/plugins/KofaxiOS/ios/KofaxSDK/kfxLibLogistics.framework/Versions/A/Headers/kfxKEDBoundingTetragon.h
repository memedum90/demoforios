//  API Reference
//
//  kfxKEDBoundingTetragon.h
//  KMCEngineData Objects
//
//  Created by Mark Day on 7/23/13.
//  Copyright (c) 2012 - 2014 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

#ifndef KEDBOUNDINGTETRAGON
#define KEDBOUNDINGTETRAGON 1

//! Bounding Tetragon class holds four point data.
/**
 Framework: libKfxEngines\n
 Import suggestion: #import <kfxLibEngines/kfxEngines.h>\n
 
 An instance of this class contains the bounding tetragon corners of an area of an image that specify how to crop an image. It may represent a rectangle, in which case the image will not be stretched to make it into a rectangle. If the corners represent a tetragon, the cropped image will be stretched to adjust the image of a document that was skewed in three orientations. If the bounding tetragon coordinates are all 0, then no manual cropping is performed by the image processing engine.\n
 The library uses this tetragon class in the kfxKEDBasicSettingsProfile, in the kfxKEDQuickAnalysisFeedback and kfxKEDBarcodeResult classes.\n\n
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
@interface kfxKEDBoundingTetragon : NSObject <NSCoding>

// ===================================================
//! Represents the coordinates of the top left corner
/**
 This CGPoint structure holds the the top left X and Y coordinates of the tetragon point in pixels. The X coordinate may be less than or greater than the bottomRight the X coordinate.\n
 Avoid fractions.  The library converts to whole integers in use.
 Default: 0,0
 */
@property (assign, atomic) CGPoint topLeft;


// ===================================================
//! Represents the coordinates of the top right corner
/**
 This CGPoint structure holds the top right X and Y coordinates of the tetragon, and the X value must always be greater than top left X.\n
   Avoid fractions.  The library converts to whole integers in use.
Default: 0,0
*/
@property (assign, atomic) CGPoint topRight;


// ===================================================
//! Represents the coordinates of the bottom left corner
/**
 This CGPoint structure holds the bottom left X and Y coordinates of the tetragon, and the X value must always be less than the bottom right X.\n
 Avoid fractions.  The library converts to whole integers in use.
Default: 0,0
 */
@property (assign, atomic) CGPoint bottomLeft;

// ===================================================
//! Represents the coordinates of the bottom right corner
/**
 This CGPoint structure holds the bottom right X and Y coordinates of the tetragon, and the X value must always be greater than the bottom left X.\n
 Avoid fractions.  The library converts to whole integers in use.
Default: 0,0
 */
@property (assign, atomic) CGPoint bottomRight;

@end
#endif

