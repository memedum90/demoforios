//  API Reference
//
//  kfxKEDBarcodeResult.h
//
//  KMCEngineData Objects
//
//  Created by Mark Day on 7/23/13.
//  Copyright (c) 2012 - 2014 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>
#import "kfxKEDBoundingTetragon.h"

/// Barcode enum to define barcode types to find, or those found.
typedef enum barcode {
    BARCODE_UNKNOWN = 0,
    BARCODE_PDF417,
    BARCODE_CODE39,
    BARCODE_QR,
    BARCODE_DATAMATRIX,
    BARCODE_CODE128,
    BARCODE_CODE25,
    BARCODE_EAN,
    BARCODE_UPC,
    BARCODE_CODABAR,
    BARCODE_AZTEC,
    BARCODE_CODE93,
    BARCODE_END_OF_VALID_SETTINGS
} KEDBarcodeTypes;

/// Direction enum to define the search direction used to find the barcode.
typedef enum kedBarcodedirections {
    DIRECTION_UNKNOWN = 0,
    DIRECTION_LEFT_RIGHT,
    DIRECTION_TOP_DOWN,
    DIRECTION_RIGHT_LEFT,
    DIRECTION_BOTTOM_UP,
    DIRECTION_END_OF_VALID_SETTINGS
} KEDBarcodeDirections;

/// Data format enum to define the type of data encoding used for the value found.
typedef enum dataFormat {
    FORMAT_UNKNOWN = 0,
    FORMAT_ASCII,
    FORMAT_BASE_64,
    FORMAT_END_OF_VALID_SETTINGS
} KEDBarcodeDataFormats;

//! A single barcode found data item
/**
 Framework: libKfxEngines\n
 Import suggestion: #import <kfxLibEngines/kfxEngines.h>\n

 An instance of this class contains one possible bar code result from the barcode reader. The result includes the barcode type found, the direction in which the barcode search found the barcode, the location within the image where the engine found the barcode, and the actual data read from the barcode. The results are encoded as normal ASCII text or base64 encoded.  Base64 encoding is used for barcode data when the data includes non printable characters, or embedded null characters.\n\n
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
@interface kfxKEDBarcodeResult : NSObject <NSCoding>


// =======================================
//! A single barcode type found
/**
 The type of barcodefound, such as PDF417, Aztec or Code39.
 Default: BARCODE_UNKNOWN
 */
@property KEDBarcodeTypes           type;


// =======================================
//! The barcode bounding tetragon
/**
The barcode bounding tetragon area where the barcode reader found the barcode within the input image.  The library uses a tetragon instead of a simple rectangle because the barcode may be skewed in the original image.\n
The barcode engine or the UI control adds a tetragon for each bar code found.
 Default: nil
 */
@property (strong, nonatomic) kfxKEDBoundingTetragon   *boundingBox;


// =======================================
//! The barcode data format
/**
 The actual barcode reader encodes the barcode data in this specified data format.  The data will be encoded as base64 if the barcode data contained non-printable characters, or the actual ASCII data otherwise.
 */
@property (assign, nonatomic) KEDBarcodeDataFormats     dataFormat;


// =======================================
//! The barcode data
/**
 The actual barcode data that the barcode reader decoded from the found barcode.  The data will be encoded as base64 if the barcode data contained non-printable characters, or the actual ASCII data otherwise, as specified by the dataFormat property.
 */
@property (strong, nonatomic) NSString         *value; //Bar code value read


// =======================================
//! The direction for the found barcode
/**
 The barcode reader found this barcode by reading it in the specified direction.  Since barcodes can be sideways or upside down, this direction indicates the orientation of the barcode based on the original image.
 */
@property (assign, nonatomic) KEDBarcodeDirections      direction;


// ==========================================================
//! Initialize the class instance
/**
 Use this method in your typical [[class alloc] init]; code lines to initialize an instance of this class with the standard defaults.
 */
- (id)init;


// ==========================================================
//! Decode the barcode type into a string equivalent
/**
 Use this class method to convert the actual barcode type setting into a printable string equivalent.
 @param type is an enum KEDBarcodeType setting that you want to evauluate.
 @return A string representing the setting supplied.
 */
+(NSString*) decodeType: (KEDBarcodeTypes) type;


// ==========================================================
//! Decode the barcode direction into a string equivalent
/**
 Use this class method to convert the actual barcode direction setting into a printable string equivalent.
 @param type is an enum KEDBarcodeDirections setting that you want to evauluate.
 @return A string representing the setting supplied.
 */
+(NSString*) decodeDirection: (KEDBarcodeDirections) dir;


// ==========================================================
//! Decode the barcode data format into a string equivalent
/**
 Use this class method to convert the actual barcode data format setting into a printable string equivalent.
 @param type is an enum KEDBarcodeDataFormats setting that you want to evauluate.
 @return A string representing the setting supplied.
 */
+(NSString*) decodeDataFormat: (KEDBarcodeDataFormats) format;


@end
