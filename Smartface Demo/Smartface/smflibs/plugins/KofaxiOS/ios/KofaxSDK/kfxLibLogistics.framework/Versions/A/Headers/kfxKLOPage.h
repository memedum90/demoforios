//
//  KMC SDK API Reference file
//  kfxKLOPage.h
//  KMCCaptureData
//
//  Created by David Duffy on 10/11/13.
//  Copyright (c) 2012 - 2014 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>
#import "kfxKEDImage.h"

typedef NS_ENUM(NSUInteger, KLOSides) {
    KLO_FRONT_SIDE,
    KLO_BACK_SIDE
};

//! Page object contains an array of one or more Image Objects.
/**
 The Page object contains an array of one more image objects. A page is flagged as the front side or back side of an original document. Each page may contain multiple images, with only one being marked as the current image to represent that page.
 \n\n
**Serialization**
\n\n

This class adopts the NSCoding protocol so that this object may be archived and unarchived using the iOS standard [NSKeyedArchiver archiveRootObject:<object> toFile: archiveFileName]; approach. Using keyed archive files, you can save this object for later use. The library supports backward compatibility, such that as a new version of an app that uses the API in this SDK, includes a newer versions of the SDK libraries that have data model changes, the older archive can still be read by the newer version. However, it is not a design goal to archive and dearchive with forward compatibility, such as decoding an archive on a newer version of the class, using an older library.\n\n
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
@interface kfxKLOPage : NSObject <NSCoding>

//! Image Objects.
/**
 This member array contains an array of image objects associated with the Page. This array provides only readonly access and cannot be modified directly. However, images can be added and removed from this array through the addImage and removeImage methods described below.
 */
@property (retain, readonly) NSArray *images;

//! Side
/**
 This boolean data item indicates whether this page is the front or back of the sheet.
 */
@property (assign, atomic) KLOSides side;

//! Page ID
/**
 This readonly NSString member contains a unique GUID identifying the page. This value is generated during object initialization.
 */
@property (retain, readonly) NSString *pageID;

//! Sheet ID
/**
 This integer value is a unique id identifying the sheet. It allows two pages that are part of a sheet to be identified.
 */
@property (assign, atomic) NSInteger sheetID;

//! Current Image Index
/**
 This integer value indicates which of several images associated with a page is the current image. It indicates the image index of the page from which the extraction is associated. It is especially useful for a multipage document. When an image is added using the 'addImage' method, this variable is automatically set to the index of the added image.
 */
@property (assign, atomic) NSInteger currentImageIndex;

//! addImage Method
/**
 This method adds an image object to the 'images' array property. After the image is added, the currentImageIndex is updated to indicate that the most recent image is current.
 */
- (void) addImage: (kfxKEDImage *)newImage;

//! removeImage Method
/**
 This method removes an image from the 'images' array property. The image to be removed is determined by matching the supplied imageID string to the contents of the images in the array. If the current image is removed, the currentImageIndex is set to 0. Otherwise, the currentImageIndex refers to the same image.
 @returns KMC_SUCCESS, for success\n
 KMC_LO_IMAGE_NOT_FOUND, when an image matching the supplied imageID could not be found.\n
 */
- (int) removeImage: (NSString *)imageID;

/* Initialization method */
- (id) init;

@end
