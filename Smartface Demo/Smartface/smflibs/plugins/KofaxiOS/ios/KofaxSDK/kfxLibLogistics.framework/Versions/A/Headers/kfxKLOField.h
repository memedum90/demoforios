//
//  KMC SDK API Reference file
//  kfxKLOField.h
//  KMCCaptureData
//
//  Created by David Duffy on 10/08/13.
//  Copyright (c) 2012 - 2014 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>
#import "kfxKLOFieldType.h"

//! Field object describes a Field object.
/**
 The Field object is instantiated using a particular FieldType object and contains a value conforming to that Field type.
 \n\n
**Serialization**
\n\n

This class adopts the NSCoding protocol so that this object may be archived and unarchived using the iOS standard [NSKeyedArchiver archiveRootObject:<object> toFile: archiveFileName]; approach.  Using keyed archive files, you can save this object for later use.  The library supports backward compatibility, such that as a new version of an app that uses the API in this SDK, includes a newer versions of the SDK libraries that have data model changes, the older archive can still be read by the newer version.  However, it is not a design goal to archive and dearchive with forward compatibility, such as decoding an archive on a newer version of the class, using an older library.\n\n
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
@interface kfxKLOField : NSObject<NSCoding>

//! Field Type object reference
/**
 This readonly member variable contains the Field Type for this Field object.
 */
@property (retain, readonly) kfxKLOFieldType *fieldType;

//! Field Value
/**
 This NSString variable contains the value for this Field object. It can be entered by the user or extracted from an image.
 */
@property (retain) NSString *value;

//! Field Valid
/**
 This boolean variable reflects whether the field-level validation or field-level scripting failed. If field-level scripting or field-level validation is not supported or performed, this field can be filled in by the application.
 */
@property (assign, atomic) bool valid;

//! Field Error Description
/**
 This NSString variable is populated when the field validation rule fails for field-level scripting. The validation server generates this errorDescription string when the field is marked invalid.
 */
@property (retain) NSString *errorDescription;

//! Tag
/**
 This NSString variable is provided for application use.
 */
@property (retain) NSString *tag;

//! initWithFieldTypeObject
/**
 This method is provided to instantiate this object with the provided Field Type object. An example follows:
 @code
 kfxKLOFieldType *theFieldType = nil;
 kfxKLOField *theField = nil;
 theFieldType = [[kfxKLOFieldType alloc] init];
 theField = [[kfxKLOField alloc] initWithFieldTypeObject: theFieldType];
 @endcode
 */
- (id) initWithFieldTypeObject: (kfxKLOFieldType *)fieldType;

/* General purpose init - should not be used */
- (id) init;

@end
