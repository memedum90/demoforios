//
//  KMC SDK API Reference file
//  kfxKLOFieldType.h
//  KMCCaptureData
//
//  Created by David Duffy on 10/07/13.
//  Copyright (c) 2012 - 2014 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, KLOdataTypes) {
    KLO_TYPE_STRING,
    KLO_TYPE_INT,
    KLO_TYPE_FLOAT,
    KLO_TYPE_BOOL,
    KLO_TYPE_DATE,
    KLO_TYPE_EMAIL,
    KLO_TYPE_URL
};

//! FieldType object describes the attributes of a Field object.
/**
 The data contained in an instance of this object describes the attributes of a given Field object. The FieldType object is used as input to instantiation of the Field object.
 \n\n
**Serialization**
\n\n

This class adopts the NSCoding protocol so that this object may be archived and unarchived using the iOS standard [NSKeyedArchiver archiveRootObject:<object> toFile: archiveFileName]; approach. Using keyed archive files, you can save this object for later use. The library supports backward compatibility, such that as a new version of an app that uses the API in this SDK, includes a newer versions of the SDK libraries that have data model changes, the older archive can still be read by the newer version. However, it is not a design goal to archive and dearchive with forward compatibility, such as decoding an archive on a newer version of the class, using an older library.\n\n
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
@interface kfxKLOFieldType : NSObject<NSCoding>

//! Field Type Name
/**
 This string member variable contains a name for this Field Type. The default name value is nil.
 */
@property (retain) NSString *name;

//! Field Type Display Name
/**
 This string member variable contains a human-readable Field Type name suitable for display in User Interface controls. The default value is nil.
 */
@property (retain) NSString *displayName;

//! Field Type Label
/**
 This string member variable contains a displayable label for this field type. The default label value is nil.
 */
@property (retain) NSString *label;

//! Field object Value Required
/**
 This boolean variable indicates whether a value must be entered for the associated Field object. The default value is false.
 */
@property (assign, atomic) bool required;

//! Field Data Type
/**
 This variable identifies the type of data to be contained in the created Field object. By default, the default value is set to STRING. The value must be one of the values identified in the KLOdataTypes enum.
 */
@property (assign, atomic) KLOdataTypes dataType;

//! Field Hidden
/**
 This boolean variable defines whether the field should be visible to the user. The default value of this variable is false (not hidden).
 */
@property (assign, atomic) bool hidden;

//! ReadOnly
/**
 This boolean variable defines whether the field should be udatable by the user. The default value of this variable is false.
 */
@property (assign, atomic) bool readOnly;

//! Options Array
/**
 This array of strings contains the values associated with a choice list for this field. This array is implemented as a NSMutableArray. Thus, its contents can't be manipulated using standard getter and setter functions. For example, to add a NSString object to the array, the method might be: \n
 @code
 [theFieldType.options addObject: @"This is a string."];
 @endcode
 */
@property (retain) NSMutableArray *options;

//! Field must match options list choices.
/**
 This boolean variable determines if the user is limited to the choices in the options array, or if other values are valid. The default of this variable is true (limited to the choice in the options array).
 */
@property (assign, atomic) bool forceMatch;

//! Minimum index field value
/**
 This string value indicates the minimum value for the index field. For strings, this specifies the minimum length. For integer and float values, this specifies the minimum allowed value. This value can be negative. For dates, this specifies the oldest allowed date. The default value of this variable is nil.
 */
@property (retain) NSString *min;

//! Maximum index field value
/**
 This string value indicates the maximum value for the index field. For strings, this specifies the minimum length. For integer and float values, this specifies the maximum allowed value. The value can be negative. For dates, this specifies the newest allowed date. The default value of this variable is nil.
 */
@property (retain) NSString *max;

//! Default field value
/**
 This string value indicates the default value for the index field.
 */
@property (retain) NSString *defaultValue;

//! Application field
/**
 This string value is provided for an application-specific field. Initially, this field value is nil.
 */
@property (retain) NSString *customTag;

- (id) init;

@end
