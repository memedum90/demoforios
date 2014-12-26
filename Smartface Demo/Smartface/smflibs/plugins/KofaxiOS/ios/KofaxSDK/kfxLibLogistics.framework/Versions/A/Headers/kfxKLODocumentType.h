//
//  KMC SDK API Reference file
//  kfxKLODocumentType.h
//  KMCCaptureData
//
//  Created by David Duffy on 10/11/13.
//  Copyright (c) 2012 - 2014 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>
#import "kfxKLOFieldType.h"
#import "kfxKEDImagePerfectionProfile.h"
#import "kfxKEDBasicSettingsProfile.h"

typedef NS_ENUM(NSUInteger, KLOdocOrientation) {
    KLO_ALIGNLONG,
    KLO_ALIGNSHORT
};

typedef NS_ENUM(NSUInteger, KLOsourceServer) {
    KLO_SERVER_NONE,
    KLO_SERVER_KFS,
    KLO_SERVER_KTA
    
};

//! DocumentType object describes the attributes of a document.
/**
 The data contained in an instance of this object describes the attributes of a given Document object. It is initialized with an array of FieldType objects. A DocumentType object must be provided when initializing a Document object. It can be defined at design time or obtained at run time from a server such as KFS or TotalAgility.
\n\n
**Serialization**
\n\n

This class adopts the NSCoding protocol so that this object may be archived and unarchived using the iOS standard [NSKeyedArchiver archiveRootObject:<object> toFile: archiveFileName]; approach.  Using keyed archive files, you can save this object for later use.  The library supports backward compatibility, such that as a new version of an app that uses the API in this SDK, includes a newer versions of the SDK libraries that have data model changes, the older archive can still be read by the newer version. However, it is not a design goal to archive and dearchive with forward compatibility, such as decoding an archive on a newer version of the class, using an older library.\n\n
 Refer to the kfxKEDImage class description, by expanding the class description, that describes how to archive and unarchive objects in this framework that adopt the NSCoding protocol.\n
 You can create keyed archives using NSKeyedArchiver objects and decoded by NSKeyedUnarchiver objects. The framework design uses keyed archives, which differ from sequential archives, in that every value encoded in a keyed archive is given a Kofax unique key name. When you decode an archive, the underlying implementation can use values by name, allowing the unarchive delegate to request values in any order or not at all.\n
 
 Please refer to the Apple documentation for more information: https://developer.apple.com/library/ios/documentation/cocoa/reference/foundation/Classes/NSCoder_Class/Reference/NSCoder.html
 \n\n
 **Keyed Archiving**
 https://developer.apple.com/library/mac/documentation/Cocoa/Reference/Foundation/Classes/NSKeyedArchiver_Class/Reference/Reference.html#//apple_ref/occ/cl/NSKeyedArchiver
 \n\n
 **Keyed Unarchiving**
 https://developer.apple.com/library/mac/documentation/Cocoa/Reference/Foundation/Classes/NSKeyedUnarchiver_Class/Reference/Reference.html#//apple_ref/occ/instm/NSKeyedUnarchiver


 */
@interface kfxKLODocumentType : NSObject <NSCoding>

//! Document Type Name
/**
 This string member variable names the type of document. The default value is nil.
 */
@property (retain) NSString *typeName;

//! Document Type Display Name
/**
 This string member variable contains a human-readable Document type name suitable for display in User Interface controls. The default value is nil.
 */
@property (retain) NSString *displayName;

//! Document Type Version
/**
 This string member variable identifies the version of the document type. The default value is nil.
 */
@property (retain) NSString *version;

//! Field type array
/**
 This read-only array contains the field types contained in the document. The contents of this array are used to build an array of Fields when instantiating a Document object.
 */
@property (retain, readonly) NSArray *fieldTypes;

//! Document Orientation
/**
 This enum variable sets a preferred document orientation to be used when taking a picture. It indicates whether the long or short edge of the document is aligned with the long edge of the viewer. The default value indicates that the long edge is aligned with the long edge of the viewer.
 */
@property (assign, atomic) KLOdocOrientation docOrientation;

//! Document Width
/**
 This member variable specifies the document width in inches. The default value is 0.
 */
@property (assign, atomic) float docWidth;

//! Document Height
/**
 This member variable specifies the document height in inches. The default value is 0.
 */
@property (assign, atomic) float docHeight;

//! Image Perfection Profile
/**
 This is a reference to the image perfection profile to be used with this document type.
 */
@property (retain) kfxKEDImagePerfectionProfile *imagePerfectionProfile;

//! Basic Settings Profile
/**
 This is a reference to the basic settings profile containing the basic image processing settings (e.g. bit depth, DPI, etc.)
 */
@property (retain) kfxKEDBasicSettingsProfile *basicSettingsProfile;

//! Source Server
/**
 This enum contains the source server that was the source of the document.
 */
@property (assign, atomic) KLOsourceServer sourceServer;

//! initWithFieldTypeArray
/**
 This method is provided to instantiate this object with an array of field type objects. An example follows:
 @code
 NSArray *fieldTypeArray = nil;
 kfxKLOField *theDocumentType = nil;
 fieldTypeArray = [[NSArray alloc] initWithObjects:theFieldType1, theFieldType2, theFieldType3, nil];
 theDocumentType = [[kfxKLODocumentType alloc] initWithFieldTypeArray: fieldTypeArray];
 @endcode
 */
- (id) initWithFieldTypeArray: (NSArray *)fieldTypeArray;

@end
