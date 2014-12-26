//  Kofax Mobile Capture API Reference File
//
//  kfxKEDImage.h
//  KMCEngineData Objects
//
//  Created by Mark Day on 7/23/13.
//  Copyright (c) 2012 - 2014 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <UIKit/UIKit.h>

#ifndef KFXKEDIMAGE
#define KFXKEDIMAGE 1

#import "kfxKEDImagePerfectionProfile.h"
#import "kfxKEDBasicSettingsProfile.h"
#import "kfxKEDQuickAnalysisFeedback.h"
#import "kfxKUTErrorInfo.h"


//! Image Representation enumeration
/**
 This enumeration indicates how the Image object is represented. The Image object may contain a bitmap image, or be represented by an image in a file, or both. You end up with the representation set to both when you write the image to a file by name, or you read the image into the bitmap from a file name. The library manages this representation for you based on operations you perform on the Image object.
 */
typedef enum kedImageRep {
    IMAGE_REP_NONE = 0,
	IMAGE_REP_BITMAP,
    IMAGE_REP_FILE,
    IMAGE_REP_BOTH,
    IMAGE_REP_LAST
} KEDImageRepresentation;

//! Image Mimetype enumeration
/**
 This enumeration indicates what type of image is represented in the object. The library supports these three format types.
 */
typedef enum kedImageMimetype{
	MIMETYPE_UNKNOWN = 0,
    MIMETYPE_JPG,
    MIMETYPE_PNG,
    MIMETYPE_TIF,
    MIMETYPE_LAST
} KEDImageMimeType;

//! File storage method
/**
 This enumeration indicates how the file representation is actually stored, in a file or in a buffer that represents the file contents. 
 */
typedef enum kedFileImageRep {
    FILE_REP_UNKNOWN,
    FILE_STORED,
    FILE_BUFFERED,
    FILE_REP_LAST
} KEDFileRepresentation;

#define KMC_MIN_DPI   25
#define DEFAULT_ORIENTATION 0 // Right

#define TESTING 1

//! An Image object contains an image and associated data.
/**
 Framework: libKfxEngines\n
 Import suggestion: #import <kfxLibEngines/kfxEngines.h>\n\n
  An instance of this class represents either an input Image object or an output Image object. An input Image object is normally created by the Image Capture control. The library initializes the input Image object with the attitude delta from the desired orientation, and the GPS data representing the location of the camera when the image was acquired. The input Image object can then be supplied to the image processor to perfect the image using image perfection controls.\n
 The image processor generates an output Image object and it sets other appropriate properties to indicate the results of the image processing. These include the image metadata, the native UIImage Bitmap, the imageRepresentation, imageSourceID, profile used, imageGPSLat, and imageGPSLon, and the image height and width of the newly processed image.\n
 An instance of this class contains an image representation stored in memory, in a file or both. The class includes everything related to this image, including captured image data, classification results, and metadata associated with an image after it has been processed. It includes reference information for using an Image object with image processing or image capture completes.\n\n

  The input Image object is also updated appropriately when you call imageReadFromFile. The input Image object is also modified by the doQuickAnalysis operation in the image processor. Quick analysis informs you of conditions such as a blurry, over saturated or undersaturated image. Quick analysis also provides information and a reference image for the boundary of the document in the original picture. The Quick analysis results can then be used for a subsequent image processing operation to crop and deskew the document found in the image, reducing the size of the image and compensating for and removing distortions caused by the camera angle.\n
 The Image object includes classification results. If you want to classify the type of image you want to process, you can use the Engines Classifier API to classify an image. The results are stored in an array, where the classifier model informs you the name for the  type of document. Once you have a name of the type of image, you can process the image appropriately and direct your business flow.\n
 The Image object also includes bar code data found in an image as a result of using the barcode capture control. The output image may include one or more barcode results, and one barcode object indicates the type of barcode found, the data from the barcode, and the direction in which it was found.\n
 
  If both an ImagePerfectionProfile and a BasicSettingsProfile are set in the Image Processor object, the ImagePerfectionProfile takes precedence, while ignoring the basic settings. Therefore, only one of the profiles used properties will be set after an image is processed.\n
 
  You can set a file path or a bitmap image directly, using unique methods that return error codes for exceptions. The write and read image methods also return errors. Be sure to test all return error codes to be aware of invalid sequences or invalid settings for this object. You can also convert the bitmap to a buffered file, which is normally significantly smaller than the raw bitmap. Once the buffer is created, you can delete the bitmap, and the image representation would be a FILE image representation, and stored as a FILE_STORED file representation. An image can be either stored as a buffered image or written to a file, but not both. If the image representation is specified as FILE or BOTH, then the file representation will be either FILE_STORED or FILE_BUFFERED.\n\n
 **Licensing**
 \n\n
 This is a license protected class. Certain methods in this object are protected by a license mechanism. If you attempt to use these methods without setting the license, then you will receive the KMC_IP_LICENSE_INVALID error code. Refer to the method descriptions to determine what methods are license protected. In order to set your license, you need to use the setMobileSDKLicense method on the kfxKUTLicensing object. Example code is provided to show you how to set your license, which can be found in the kfxKUTLicensing class of the kfxUtilities framework.\n\n
 **Serialization**
 \n\n
 This class adopts the NSCoding protocol so that this object may be archived and unarchived using the iOS standard [NSKeyedArchiver archiveRootObject:<object> toFile: archiveFileName]; approach. Using keyed archive files, you can save this object for later use. The framework supports backward compatibility, such that as a new version of an app that uses the API in this SDK, includes a newer versions of the SDK libraries that have data model changes, the older archive can still be read by the newer version. However, it is not a design goal to archive and dearchive with forward compatibility, such as decoding an archive on a newer version of the class, using an older library. Archival of this object includes the version of the parent library that is associated with the class. Each archive includes the name of the class as well so that unarchiving can detect errors with improper use, while maintaining backward compatibility.\n\n
 You can create keyed archives using NSKeyedArchiver objects and decoded by NSKeyedUnarchiver objects. The framework design uses keyed archives, which differ from sequential archives, in that every value encoded in a keyed archive is given a Kofax unique key name. When you decode an archive, the underlying implementation can use values by name, allowing the unarchive delegate to request values in any order or not at all.\n\n
 Please refer to the Developers Guide using the link in the welcome page under the appropriate development environment (iOS or Android), under the "Docs" folder.  Use the Welcome.htm file and the Developers guide link to display the guide, and search for the Serialization and Deserialization topic.\n\n
 Please refer to the Apple documentation for more information: https://developer.apple.com/library/ios/documentation/cocoa/reference/foundation/Classes/NSCoder_Class/Reference/NSCoder.html
 \n\n
 **Keyed Archiving**
 https://developer.apple.com/library/mac/documentation/Cocoa/Reference/Foundation/Classes/NSKeyedArchiver_Class/Reference/Reference.html#//apple_ref/occ/cl/NSKeyedArchiver
 \n\n
 *Archiving an object*
 \n\n
 The keyed archiver process in iOS (NSKeyedArchiver) uses the encodeWithCoder delegate method to save this object as a keyed archive for later use. The app developer may use the companion NSKeyedUnarchiver method to restore the object of this type.
 @code
 // Example of serialization for only this pre-initialized object we will use as the root object.
 kfxKEDImage * myImage = [[kfxKEDImage alloc] init];
 // modify and use the object.
 // Prepared to archive...
 // Create an archive file name for the archive
 NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
 NSString* documentsDirectory = [paths objectAtIndex:0];
 NSString * archiveFileName = [documentsDirectory stringByAppendingPathComponent:@"SerialKEDImage.ar"];
 // Archive the kfxKEDImage object
 [NSKeyedArchiver archiveRootObject:myImage toFile:archiveFileName];
 @endcode

 \n\n
  **Keyed Unarchiving**
 https://developer.apple.com/library/mac/documentation/Cocoa/Reference/Foundation/Classes/NSKeyedUnarchiver_Class/Reference/Reference.html#//apple_ref/occ/instm/NSKeyedUnarchiver
\n\n
 *Unarchiving an object*
 \n\n
 The keyed unarchiver process in iOS (NSKeyedUnarchiver) uses the initWithCoder delegate method to instantiate the class from a previously saved context created by the NSKeyedArchiver method.
 The unarchive process can return four exceptions. See below for example unarchive sequence. Therefore, you need to wrap your unarchiver code with a try catch block to handle these conditions:\n
 - An UnarchiveSuperInitNil unexpected exception is returned when the super init for this class returned nil. In this case the object is not restored.\n
 - An UnarchiveIllegalClassNameAssociation exception is returned when the archive file used to decode this portion refers to an unexpected class. This occurs when you attempt to unarchive this class from the wrong archive file. The library returns a new object.\n
 - An UnarchiveIllegalClassVersion exception is returned if the version that encoded the archive cannot be unarchived with this version of the library due to an unexpected version. The library returns a new object.\n\n
 The unarchive process may throw one of these exceptions:\n\n
 @throw UnarchiveSuperInitNil                   Thrown when the super init for this class returned nil. The state of the object is unknown.
 @throw UnarchiveInsufficientMemory             Thrown when the buffered file image cannot be restored into a buffer because of insufficient memory.
 @throw UnarchiveIllegalClassNameAssociation    Thrown when the archive file used for decoding refers to an unexpected class.
 @throw UnarchiveIllegalClassVersion            Thrown if the version that encoded the archive cannot be unarchived with this version of the library.
\n\n

 @code
 // Example of deserialization for only this object as the root object.
 kfxKEDImage * myImageRestored;
 
 NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
 NSString* documentsDirectory = [paths objectAtIndex:0];
 NSString * archiveFileName = [documentsDirectory stringByAppendingPathComponent:@"SerialKEDImage.ar"];
 @try{
     myImageRestored = [NSKeyedUnarchiver unarchiveObjectWithFile:archiveFileName];
 }@catch (NSException *anException)
 {
     NSString * strException = [NSString stringWithFormat:@"Unarchive Exception: %@",anException.name];
     UIAlertView* alert = [[UIAlertView alloc] initWithTitle:strException message: anException.reason delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
     [alert show];
 }
 @endcode

*/
@interface kfxKEDImage : NSObject <NSCoding>


// ==========================================================
//        R E A D _ O N L Y      P R O P E R T I E S
// ==========================================================

// ==========================================================
//! Uniquely identifies this image using a unique ID.
/**
 If this object is for an output image that is a processed version of the original input image, then the library copies this imageID to the imageSourceID so that you can associate the original image with the processed image. This ID is generated by the library when the object is created, and remains true for the life of that object.\n
 \n
 Default: A unique UUID string
 */
@property (readonly,atomic) NSString *imageID; //archived

#ifdef USE_MANAGER
// ==========================================================
//! Internal use only friend ID
/**
 The library internal layers uses this ID for internal operations.\n
 \n
 Default: A unique GUID string
 */
@property (readonly,atomic) NSString *friendID;
#endif


// ==========================================================
//! Identifies the source image used to generate this image.
/**
 The image processing engine sets this value after image processing using an input Image object. The IP engine sets the imageSourceID to the imageID of the input Image object, so that you can associate the original image with the processed image.\n
 \n
 Default: nil
 */
@property (readonly,atomic) NSString *imageSourceID; // archived


// ==========================================================
//! Image metadata created by the image processing process.
/**
 This metadata is formatted so that it can be both readable, and formatted for JSON parsing if needed. The image processing process generates this string while the image is being processed. It includes tetragon corner data, bar code data. It also indicates if the image is blurry, over or under-saturated, and includes other information about the results of the operations specified. It is output by the image processing engine after an image is processed.
 This is a readonly property. Use the following code snippet example to read the metadata.
 @code
 kfxKEDImage * myOwnImage = [[kfxKEDImage alloc] init];
 <Setup the image object with an image>
 <Perform some image processing operation>
 NSString * myMetaData = [myOutputImage getImageMetaData]];
 @endcode
 \n
 Default: nil
 */
@property (atomic, readonly) NSString *imageMetaData; // archived


// ==========================================================
//! Global latitude and longitude of the location where the original photo was taken.
/**
 These float values contain the latitude and longitude defining where the photo was taken. The library initializes this global position data from the original input image taken by the device's camera. The latitude and longitude values return the global position such as these follows:\n
 Latitude: 33.670502\n
 Longitude: -117.762001\n
 For Kofax, Irvine.\n
 \n
 Default: 0.0
 @code
 kfxKEDImage * myOwnImage = [[kfxKEDImage alloc] init];
 float actualLat = [myOwnImage getImageGPSLat];
 float actualLon = [myOwnImage getImageGPSLon];
 if ([myOwnImage.isPositionValid])
 {
 // use the valid GPS data
 }
 @endcode
 */
@property (atomic, readonly) float imageGPSLat;       // latitude archived
@property (atomic, readonly) float imageGPSLon;       // longitude archived


// ==========================================================
//! Basic settings profile used for image processing
/**
 An instance of this class contains the simple image processing options that the image processor used to produce this image. It is set by the image processing engine in the output image it produces. The profile defines the standard crop, deskew, desired rotation and other options.
 \n
 Default: nil
 @see kfxKEDBasicSettingsProfile class description
 */
@property (atomic, readonly) kfxKEDBasicSettingsProfile *basicSettingsProfileUsed;


// ==========================================================
//! Image perfection profile used to specify detailed image processing options
/**
 An instance of this class contains the advanced image processing options that the image processor used to produce this image. It is set by the image processing engine in the output image it produces. These settings are a superset of what is possible with basic settings profiles.
 @code
 // Display the profiles used addresses
 NSLog(@"BasicProfileUsed    : %@",[myOwnImage getBasicSettingsProfileUsed);
 NSLog(@"ImagePrefProfileUsed: %@",[myOwnImage getImagePerfectionProfileUsed);
 NSLog(@"ImageQuickAnalysis  : %@",[myOwnImage getImageQuickAnalysisFeedback);
 @endcode
 \n\n
 Default: nil
 */
@property (atomic, readonly) kfxKEDImagePerfectionProfile *imagePerfectionProfileUsed;


// ==========================================================
//! Defines how the image is represented in this object
/**
 An image may be in memory, in a file or both. The library sets this appropriately when the object is created, and when it is saved to a file. Therefore, it indicates the ways in which the image data is represented in this object. The imageMimeType property defines the file storage type. The library takes care of setting this property based on normal sequences such as setting a file name, clearing a bitmap image, reading an image from a file and so on. When the image is read from a file, the library sets this to IMAGE_REP_BITMAP.\n\n
 This is a readonly property. Use the following approach to read the current setting.
 \n
 Default: IMAGE_REP_NONE
 @see KEDImageRepresentation enum for the possible settings.
 @code
 kfxKEDImage * myOwnImage = [[kfxKEDImage alloc] init];
 myImagePath = [myBundle pathForResource:@"image" ofType:@"jpg"]; // assumes this file is in your test project
 NSLog(@"FilePath: %@",myImagePath);
 
 int error = [myOwnImage specifyFilePath: myImagePath];
 if (error != KMC_SUCCESS)
 return (error);  // out of context
 
 int imageRep = myOwnImage.imageRepresentation;
 NSLog(@"image rep: %@",[kfxKEDImage decodeImageRep:imageRep]);
 @endcode
 */
@property (atomic, readonly) KEDImageRepresentation imageRepresentation; // archived


// ==========================================================
//! Defines how the file is represented
/**
 When the image representation is IMAGE_REP_FILE or IMAGE_REP_BOTH, this enumeration defines how the file image is stored, either as a buffered image or a stored as a file.\n\n
 This is a readonly property.
\n
Default: FILE_REP_UNKNOWN
 @see KEDFileRepresentation enum for the possible settings.
 */
@property (atomic, readonly) KEDFileRepresentation fileRepresentation; //archived


// ==========================================================
//! Defines how large the file buffer is in bytes
/**
 When the file representation is FILE_BUFFERED, then this property indicates how big the buffer is in bytes.\n
 This is a readonly property.\n
 @see getImageFileBuffer method to get a pointer to the buffer.
 \n
 Default: 0
 */
@property (atomic, readonly) int imageFileBufferSize; // archived


// ==========================================================
//! Image Quick Analysis feedback stores quick analysis results
/**
 An instance of this class contains all the data that results from a quick analysis of an image. The Image Processing (IP) Engine takes an unknown raw input image and produces metadata. The IP Engine parses the metadata, and populates this object with what it finds. The library generates a quick analysis feedback object and saves it in the input Image object to make it available for subsequent image processing. The feedback object also includes a reference UIImage that includes a superimposed green border around what the library determines to be the document edges. These edges may not be straight but curved edges attributed to the original not being flat on the surface used to take the picture. The edge curve data is stored in the image metadata.\n
 \n
 Default: nil
 */
@property (atomic, readonly) kfxKEDQuickAnalysisFeedback *imageQuickAnalysisFeedback; // archived


// ==========================================================
//! Image Height in pixels for the image bitmap
/**
 The library sets this property when an image is read from a file, or when you specify an image bitmap. \n
 When this object is output by image processing, this represents the height of the processed image.\n
 You cannot modify the height and width and expect that an imageFileWrite will change the image to these height and width values. Instead, they are provided for reference purposes only.\n
 \n
 Default: 0
 */
@property (atomic) int imageHeight; // archived


// ==========================================================
//! Image Width in pixels for the image bitmap
/**
 The library sets this property when an image is read from a file, or when you specify an image bitmap. \n
 When this object is output by image processing, this represents the width of the processed image.\n
 You cannot modify the width and expect that an imageFileWrite will change the image to these height and width values. Instead, they are provided for reference purposes only.\n
 \n
 Default: 0
 */
@property (atomic) int imageWidth; // archived


// ==========================================================
//! Image Attitude for the pitch when the image was taken
/**
 These two pitch and roll properties are used to store the attitude of the camera at the time the image was taken by the device's camera. They are only valid when the image was taken with the Custom ImageCapture UI object. Pitch is the camera pitch in degrees, and roll is the roll in degrees. The library converts to degrees from the native values. The roll and pitch values are always between 0-90 degrees positive or negative. Horizontal pitch is 0 when level, and 90 degrees when vertical. After you increase pitch beyond straight up, the pitch starts to decrease back to 0. Horizontal roll is set to 0 when level, and increases positive as you roll right, and negative as you roll left.\n
 This value is not retained after the image is written to a file, and then later read back in from a file. It is provided for reference purposes after an image was obtained from the Image Capture screen.\n
 Note: These values are the delta from the declination setting that specifies what constitutes a level surface for taking pictures.\n
 \n
 Default: 0.0
 */
@property (readonly) float attitudePitch; // archived


// ==========================================================
//! Image Attitude for the roll when the image was taken
/**
 The attitude roll property is used with pitch to indicate the attitude of the camera at the time the image was taken by the device's camera. It is only valid when the image was taken with the Custom ImageCapture UI object. Pitch is the camera pitch in degrees, and roll is the roll value in degrees. The library converts to degrees from the native value. The roll and pitch values are always between 0-90 degrees positive or negative. Horizontal pitch is 0 when level, and 90 degrees when vertical. After you increase pitch beyond straight up, the pitch starts to decrease back to 0. Horizontal roll is set to 0 when level, and increases positive as you roll right, and negative as you roll left.\n
 This value is not retained after the image is written to a file, and then later read back in from a file. It is provided for reference purposes after an image was obtained from the Image Capture screen.\n
 Note: These values are the delta from the declination setting that specifies what constitutes a level surface for taking pictures.\n
 \n
 Default: 0.0
 */
@property (readonly) float attitudeRoll; // archived


// ==========================================================
//        W R I T E - R E A D      P R O P E R T I E S
// ==========================================================


// ==========================================================
//! App defined tag name to associate with this image
/**
 Use this string to specify the current definition of this image, such as "Raw", "Processed", or "Image Ready", or whatever you want. Use it for your own management purposes.\n
 \n
 Default: nil
 */
@property (retain,atomic) NSString *imageTag; // archived


// ==========================================================
//! Image Dots per Inch
/**
 This property indicates the image resolution as determined by the image processor. It is valid only after the Image object is created by some image creation or image processing task. When the image is read from a file, the library updates this to the actual image DPI.\n
 If you initialize the object using the initWithImage or call specifyImageBitmap, the library sets the DPI to 72 by default. You can change the default DPI before writing if needed.
 \n
 Default: 0
 */
@property (assign, atomic) int imageDPI;    // archived


// ==========================================================
//! jpeg Quality setting
/**
 This property indicates the desired level of quality for writing a JPEG image using writeImageToFile, and must be set to a range between 1 to100. The higher the number the less compression is used, the higher the quality and the larger the output file size in bytes. A low setting would highly compress the output image, and some quality is sacrificed, but the file size is smaller. Valid for color output file format only, and ignored for others.\n
 \n
 Default: 90
 @see imageFileOutputColor class that defines the number of bits per pixel.
 */
@property (assign, atomic) int jpegQuality; // archived


// ==========================================================
//! Image File Output Color
/**
 This property indicates the bit depth of the image to be written to a file by the writeImageToFile. The valid settings are 1=bitonal, 8=grayscale, 24=color. The library checks for valid settings When you call the writeImageToFile method. When the image is read from a file, the library updates this with the actual color setting of the image in the file.\n
 \n
 Default: KED_BITDEPTH_COLOR
 @see KEDImageRepresentation enum
 @see KEDOutputColor enum
 */
@property (assign, atomic) KEDOutputColor imageFileOutputColor; // archived


// ==========================================================
//! Object creation date-time string.
/**
 The library generates this date and time string when the object is instantiated, not necessarily when it is written to a file or read from a file. The date format is ISO 8601. You can change it later on, if you desire. A typical example date time string is: 2013-08-12T17:07:18-0700.\n
 If you set your own date, the library validates your setting. If it is not valid, then the date string is not stored, and the old setting remains. You must then set a valid date for the object to be used with other methods. Use the method isValidDate to check to see if the date you tried to set is valid. If it is not valid, then the library generates an error for several API methods, so that the object validity is maintained. You can use the class method ISO8601DateTime to create a valid string.
 \n
 Default: today's date and time when the object is created.
 */
@property (strong,atomic) NSString *imageCreateDateTime; // archived


// ==========================================================
//! Indicates the file storage configuration
/**
 This indicates the file format of the image File Path (that you specify with the specifyFilePath method) when it contains a valid path, and the imageRepresentation indicates the File stored. The library verifies this setting when you call the write method. If the mimetype does not match the file extension, then it returns an error for a mismatch mimetype.\n
 The library sets this property for you if you use the specifyFilePath method and use a standard file extension recognized by the library. \n
 \n
 Default: MIMETYPE_UNKNOWN
 @see KEDImageMimeType
 */
@property (assign, atomic) KEDImageMimeType imageMimeType; // archived


// ==========================================================
//! Boolean to indicate if the GPS data is valid
/**
 The two latitude and longitude properties are initialized to 0, and this bool is false to indicate that the values are not valid. They become valid when the internal library sets valid values.\n
 \n
 Default: false
 */
@property bool isPositionValid; // archived


// ==========================================================
//! Array of image barcodes found by processing
/**
 The barcode UI control returns barcode information when the barcode is detected. This array is also used by the barcode engine where multiple barcodes may be found. The library adds a kfxKEDBarcodeResult object for each barcode found.\n
 \n
 Default: an empty array ready for use.
 */
@property (nonatomic, retain) NSMutableArray* imageBarCodes;            // array of BarCodeResults


// ==========================================================
//! Image classification results
/**
 This array holds one or more image classification results after this Image object is classified by the classifier library. The classification results array is ordered such that the most probable classification is the highest rank, indicating the most probable image match from the model.\n
 \n
 Default: an empty array ready for use.\n
 @see Image Classifier (kfxKCLImageClassifier).
 */
@property (nonatomic, retain) NSMutableArray* classificationResults;    // array of Classification Results

// ==========================================================
//! Boolean to indicate if the attitude is valid
/**
 These two pitch and roll properties are initialized to 0, and this bool is false to indicate that the values are not valid. They become valid when the internal library sets valid values.\n
 \n
 Default: false
 */
@property bool isAttitudeValid; // archived



// ==========================================================
//                       M E T H O D S
// ==========================================================

// ==========================================================
//! Write the image contained in the UIImage to the file path specified in the object
/**
    Use this method to write the image contained in the UIImage object to the file path specified in the object, in the storage format specified in the mimetype. This method writes the bitmap in the imageBitmap of the object to a file using the specified mimetype to store the image as a TIFF, JPG or PNG file. The file path extension should match the mimetype. The method returns errors for invalid sequences, mismatched mime types, missing file path, etc.\n\n
 The following properties should be set before calling the write method:\n\n
  - The imageFileOutputColor, to specify the output color mode for bitonal, grayscale or color.\n
  - Use specifyFilePath, to set the fully qualified path, file name and file extension to which you want to write the image.\n
  - The imageMimeType, which should be linked to the file type extension. This is set for you by the specifyFilePath method.\n
  - The imageDPI, to specify the output image DPI if it has not already been set by a specifyImageBitmap or imageReadFromFile method calls.\n
  - The jpegQuality, to specify the compression that you want to use, if you want to use a differnt setting than the default.\n
  - The imageBitmap, to set the image you want to write to the file.\n
  - The following kfxKEDImage object properties are set after this method completes without error:\n
  - The imageRepresentation to indicate the object is represented by both the file name and the bitmap image.\n\n
 License Required: this is a licensed method.  You cannot use this method until you have set a valid SDK license. In order to set your license, you need to use the setMobileSDKLicense method on the kfxKUTLicensing object.  You must obtain a valid license from Kofax in order to use licensed methods. An example of setting your license can be found in the licensing class.\n
 
 @return KMC_SUCCESS if the image was written successfully, or other error:\n
  - KMC_ED_FILEPATH for missing file path\n
  - KMC_IP_LICENSE_INVALID if the license has not been set.
  - KMC_ED_NOIMAGE, when no image specified for writing\n
  - KMC_ED_FILEEXISTS, when attempting to write to a file that already exists, or if the file path was previously set to a non-existent file, and then later was created.\n
  - KMC_ED_JPEG_BITDEPTH, when the jpeg write is attempted with a pixel depth of 1 bit.\n
  - KMC_ED_MIMETYPE, when the mimetype setting is illegal.\n
  - KMC_ED_MIMETYPE_MISMATCH, when the mimetype setting does not match the file name extension\n
  - KMC_ED_INVALID_DPI, when the DPI setting is less than the minimum allowed.\n
  - KMC_ED_INVALID_JPEG_QUALITY_VALUE, when the jpeg quality value is invalid.\n
  - KMC_ED_INVALID_BITDEPTH, if you try to write a bitonal file in a format other than TIF or PNG, or if you attempt to write with an unknown format.
  - KMC_ED_IMAGE_WRITTEN_IS_NOT_GRAY, when the file that is written is found to be in color, which indicates that the imageFileOutputColor property was set incorrectly.\n
  - KMC_ED_IMAGE_WRITTEN_IS_NOT_BITONAL, when you set imageFileOutputColor to bitonal, but while bit packing the image it was found to not be true binary.\n
  - KMC_ED_INVALID_ISO_DATE_TIME_FORMAT, if you previously set an invalid date time string. 
  - Also, other image processing detected errors for file write.
 
 @see specifyFilePath to indicate what file name to use, and the path where to store the file.
 @see imageMimeType to specify the output image mimetype, which should match the image file extension.
 @see imageFileOutputColor for specifying the output color mode.
 @see jpegQuality to specify the compression ratio and associated file size control.
 @see specifyImageBitmap to specify the image to write, if you do not read the image in from a file.
 @see specifyImageDateAndTime to change the date associated with the image as needed.
 */
- (int) imageWriteToFile;


// =========================================================================
//! Write the UIImage object in this kfxKEDImage object to file buffer
/**
 Use this method to write the image contained in the UIImage object to a buffer included in this object. The buffer resembles the content of an image file, and the buffer is written in the storage format specified by the mimetype property. This method writes the bitmap in the imageBitmap of the object to the buffer using the specified mimetype to store the image as a TIFF, JPG or PNG file buffer representation.\n\n
 The method returns errors for invalid sequences, illegal mime types, invalid DPI, etc.\n\n
 The following properties should be set before calling the imageWriteToFileBuffer method:\n
  - The imageFileOutputColor, to specify the output color mode for bitonal, grayscale or color.\n
  - The imageMimeType, which controls how the buffer is formatted.\n
  - The imageDPI, to specify the output image DPI if it has not already been set by a specifyImageBitmap or imageReadFromFile method calls.\n
  - The jpegQuality, to specify the compression that you want to use, if you want to use a differnt setting than the default.\n
  - The imageBitmap, to set the image you want to write to the buffer.\n

 @return KMC_SUCCESS if the image was written to the file buffer successfully, or error:\n
  - KMC_IP_LICENSE_INVALID if the license has not been set.
  - KMC_ED_INVALID_DPI, when the DPI setting is less than the minimum allowed.\n
  - KMC_ED_INVALID_JPEG_QUALITY_VALUE, when the jpeg quality value is invalid.\n
  - KMC_ED_JPEG_BITDEPTH, when the jpeg write to buffer is attempted with a pixel depth of 1 bit.\n
  - KMC_ED_INVALID_ISO_DATE_TIME_FORMAT if you previously set an invalid date time string.\n
  - KMC_ED_OBJECT_REP_NOBITMAP, when the Image object does not contain an image.\n
  - KMC_ED_MIMETYPE, when the mimetype setting is illegal.\n
  - KMC_ED_INVALID_BITDEPTH, if you try to write a bitonal buffer in a format other than TIF or PNG, or if you attempt to write with an unknown format.
  - KMC_ED_IMAGE_WRITTEN_IS_NOT_GRAY, when the buffered file image written is found to be color, which indicates that the imageFileOutputColor property was set incorrectly.\n
  - KMC_ED_IMAGE_WRITTEN_IS_NOT_BITONAL, when you set imageFileOutputColor to bitonal, but while bit packing the image it was found to not be true binary.\n
  - KMC_ED_OBJECT_REP_MISMATCH, when the object is already represented by a file.\n
  - Also, other image processing detected errors for file write.\n\n
 License Required: this is a licensed method.  You cannot use this method until you have set a valid SDK license. In order to set your license, you need to use the setMobileSDKLicense method on the kfxKUTLicensing object.  You must obtain a valid license from Kofax in order to use licensed methods. An example of setting your license can be found in the licensing class.\n

 */
- (int) imageWriteToFileBuffer;


// ==========================================================
//! Initialize the imageBitmap property with the image contained in a file
/**
 Use this method to read an image contained in a file into the imageBitmap property. Be sure to release a previously used UIImage to prevent a memory leak, using the clearImageBitmap method. The file path specified in the object specifies where to get the image. The library sets the imageMimetype, based on the type of image read. The library ignores the file extension to determine the type of image read. It sets the bit depth of the image read into this Image object. The library sets the mimetype based on what is found in the image. However, the file path extension should match the actual image mimetype. This method returns errors for invalid sequences, missing file path, actual file missing in the file system, a bitmap already loaded, etc.\n
 This method sets the following kfxKEDImage properties if the image was read from the file without error:\n
    - imageBitmap, with the actual image read from the file.
    - imageHeight and imageWidth for the image read from the file\n
    - imageMetadata set to nil, because the metadata only applies to a processed image.\n
    - imageFileOutputColor, to the color depth of the image in the imageBitmap.\n
    - imageDPI, as detected by the image read from the file.\n
    - imageRepresentation, to indicate if the object is represented by both the file name and the imageBitmap.\n
    - imageMimetype, respective to the image file path set.\n
    - imageGPSLatitude and imageGPSLongitude if this data is available from the file.\n\n
 License Required: this is a licensed method.  You cannot use this method until you have set a valid SDK license. In order to set your license, you need to use the setMobileSDKLicense method on the kfxKUTLicensing object.  You must obtain a valid license from Kofax in order to use licensed methods. An example of setting your license can be found in the licensing class.\n

 @return KMC_SUCCESS if the image was read successfully, or the following errors:\n
 - KMC_ED_FILEPATH, for missing file path for the image to read\n
 - KMC_IP_LICENSE_INVALID, if you have not set your SDK license yet.\n
 - KMC_ED_BITMAP_READ_FROM_FILE_FAILED, when the actual system read from file failed, for some file types.\n
 - KMC_ED_NONEXISTENT_FILE, when the file name indicates a non-existent file\n
 - KMC_ED_IMAGELEAK, when reading from a file when the Image object already has a bitmap included, to prevent overwriting the image.\n
 - KMC_ED_NO_MEMORY_FOR_METADATA, if memory space for holding image attributes is too small or no memory available for storage.\n
 - KMC_ED_INVALID_ISO_DATE_TIME_FORMAT, if the date and time string last set was invalid.\n
 - Also, other errors detected by the other libraries.
 */
- (int) imageReadFromFile;


// ==========================================================================
//! Read an image from the file buffer into the UIImage imageBitmap property
/**
 Use this method to add a UIImage object to this kfxKEDImage from a previously set buffered file image.\n
 This method is only valid when the Image object is represented by an image representation of IMAGE_REP_FILE and the file representation of FILE_BUFFERED. After the image read completes without error, the library changes the image representation to IMAGE_REP_BOTH, and the file representation stays as FILE_BUFFERED. The image now has both the UIImage bitmap and the buffer that contains the bytes of data that would represent what would be written to a file of that mimetype.\n\n
 License Required: this is a licensed method.  You cannot use this method until you have set a valid SDK license. In order to set your license, you need to use the setMobileSDKLicense method on the kfxKUTLicensing object.  You must obtain a valid license from Kofax in order to use licensed methods. An example of setting your license can be found in the licensing class.\n\n
 @return KMC_SUCCESS if the image buffer was loaded correctly, or the following errors:\n
 - KMC_ED_INVALID_FOR_OBJECT_REP, if the object is already represented as both a bitmap and a buffered file.\n
 - KMC_ED_NO_BUFFERED_IMAGE, if there is no buffered image to read from.\n
 - KMC_ED_INVALID_ISO_DATE_TIME_FORMAT if you previously set an invalid date time string.\n
 - KMC_IP_LICENSE_INVALID, if you have not set your SDK license yet.\n
 */
- (int) imageReadFromFileBuffer;


// ==========================================================
//! Delete the file specified in the file path contained in this object
/**
 Use this method to manage files associated with Image objects. This method deletes the file associated with the Image object by using the file path contained in this object.
 It sets the imageRepresentation depending on the imageBitmap property. It returns errors for invalid sequences and missing file path, or non-existent file. It also clears the file path specified in the image after deleting the file.\n
 The deleteFile method sets the following kfxKEDImage object properties after successful completion:\n
 - The image File Path is set to nil, which is returned by the method getFilePath.\n
 - The imageRepresentation property, to indicate the object is no longer represented by a file name. It may change to bitmap or unknown, depending on presence of a bitmap in the object.\n
 
 @return KMC_SUCCESS, if the file was deleted successfully.\n
 - KMC_ED_FILEPATH, for a missing file path\n
 - KMC_ED_NONEXISTENT_FILE, when the operating system indicates that this file does not exist using the path specified.\n
 - KMC_ED_FILE_STILL_REMAINS, when the operating system indicates that after attempting to remove the file at the path, that the file was not deleted and still remains.\n
 - KMC_ED_FILE_NOT_DELETABLE, when the operating system indicates that this is a protected file that cannot be deleted.\n
 */
- (int) deleteFile;


// ==========================================================
//! Specify a bitmap image for this object
/**
 Use this method to specify the image you want this object to represent. Because the image bitmap is not accessible via standard set or get methods, use this method so that the library can return errors for invalid sequences. If you have already specified an image, then the memory is deallocated, and the library sets the new image for later use.\n
 Note on image orientation:  When you specify a bitmap, the libraries need to use kfxKEDImage objects throughout the system with iOS image orientation 0, so that all images are rendered the same as the bitmap representation. Therefore, this method will rotate the image as needed to set the image orientation to 0, whereby you can render the new image in the kfxKEDImage object and it will look the same as the original, when rendered on a Mac or on an iOS device. However, the new image stored in the kfxKEDImage object is different than the original. Therefore, you should use the method getImageBitmap to obtain the new UIImage. This provision guarantees that auto-orientation and image rotation will always be rendered correctly by a UIView controller.\n
 When this method completes successfully, the method changes the following properties:
 - imageRepresentation, to indicate the object is now represented by a bitmap.\n
 - imageWidth, to the new image width.\n
 - imageHeight, to the new image height.\n
 
 @return KMC_SUCCESS if the bitmap was set successfully, or error:\n
 - KMC_ED_OBJECT_REP_FILE_MISMATCH, when you try to set a bitmap for the object when a file already represents the object.\n
 - KMC_ED_INVALID_ISO_DATE_TIME_FORMAT, if you previously set an invalid date and time string.\n
 - KMC_ED_IMAGE_INVALID, if the image given to the method is nil.\n
 - KMC_ED_OBJECT_REP_FILE_MISMATCH, when the object is already represented by a file, and setting a bitmap would make it inconsistent.\n

 \n
 Default: nil
 */
- (int) specifyImageBitmap: (UIImage*) image;


// ==========================================================
//! Get the current bitmap image
/**
 Use this method to get the UIImage object currently associated with this object.\n
 @return A native UIImage object from the kfxKEDImage object.
 */
- (UIImage*) getImageBitmap;


// ==========================================================
//! Clear the bitmap image
/**
  Rather than set the bitmap image to nil, you should use this method so that the library can detect errors and to set the image representation value upon normal completion so that it is correct after the image is cleared. The memory associated with the bitmap in this object is deallocated for you.\n
 This method changes the following properties upon successful completion:
 - imageRepresentation, to indicate the object is not represented by a bitmap.\n
 @return KMC_SUCCESS if the bitmap image was removed from the object and deallocated.
 */
- (int) clearImageBitmap;


// ==========================================================
//! Clear the buffered file image
/**
 Use this method to clear the buffered file image created by the imageWriteToFileBuffer method. If the current state of the image representation is IMAGE_REP_FILE, then the state changes to unknown (INIT) state. If the image representation is BOTH, then the state changes to IMAGE_REP_BITMAP. This command is only valid in the IMAGE_REP_FILE or IMAGE_REP_BOTH, if the file representation is FILE_BUFFERED.\n
 @return KMC_SUCCESS if the file buffer was cleared successfully or:\n
 - KMC_ED_BUFFER_ALREADY_CLEARED, if in the unknown state (INIT).\n
 - KMC_ED_INVALID_FOR_OBJECT_REP, if the operation is invalid for the state of the object, such as unknown or bitmap state, or if in the FILE representation, but there is no buffered image.\n
 @see imageWriteToFileBuffer, containing a description of this method to set the file buffer.
*/
 - (int) clearFileBuffer;


// ==========================================================
//! Get a reference to the image file buffer.
/**
 Use this method to get a pointer to the image file buffer created by the imageWriteToFileBuffer method. Until the buffer is created, this pointer is null. You can access this data in order to inspect the file buffer contents, base64 encode it for submitting to some web service or other read process. As a readonly property, you cannot modify the image.\n
 \n
 Default: 0
 @see imageWriteToFileBuffer for details for creating a buffered file representation.
 @see property fileRepresentation for a description of the settings to indicate if the buffer is valid.
 @see property imageFileBufferSize
 \n\n
 Example Code follows for an image first setup for image in bitmap representation in an object called myOwnImage.
 @code
 int errorCount = 0;
 int error = KMC_SUCCESS;
 
 error = [myOwnImage imageWriteToFileBuffer];
 if (error != KMC_SUCCESS)
 {
    errorCount++;
    return (errorCount);
 }

 NSInteger buffSize = myOwnImage.imageFileBufferSize;
 const char * ptData = [myOwnImage getImageFileBuffer];
 NSLog(@"APP: Buffer Addr: 0x%X Size: %d ",(unsigned int)ptData,buffSize);
 
 // After you are done using the file buffer...
 
 error = [myOwnImage clearFileBuffer];
 if (error != KMC_SUCCESS)
 {
     errorCount++;
     return (errorCount);
 }
 
 ptData = [myOwnImage getImageFileBuffer];
 buffSize = myOwnImage.imageFileBufferSize;
 NSLog(@"APP: Buffer Addr after clear: 0x%X Size: %d ",(unsigned int)ptData,buffSize);
 
 if (ptData != 0)
 {
     errorCount++;
 }
 
 if (buffSize != 0)
 {
     errorCount++;
 }
 return (errorCount);
 
 @endcode
 
 */
- (const char *) getImageFileBuffer;


// ==========================================================
//! Check date time string validity
/**
  Use the isValidDate method after you set the date string to ensure that it is valid. Once it is marked as invalid then the Image object cannot be used with other methods.
@return true if the current date and time string is valid, or false if you set an invalid date string.
 */
- (bool) isValidDateTime;


// ==========================================================
//! Specify an image create date and time string
/**
 Use this method to set an ISO 8601 compliant date time string property and return an error code if the string is invalid. The library verifies that it complies with the standard, and then sets the string property only if it is valid, and returns an error code if not valid. You can use a class method to generate one based on the current date and time.\n
 Note that the standard setting for this property also verifies that it is correct, and does not set the value if it is invalid. Therefore you can use the isValidDateTime afterwards to determine if the string is valid.
 @return KMC_SUCCESS if the dateString is valid and set, or:\n
 - KMC_ED_INVALID_ISO_DATE_TIME_FORMAT if the string is invalid, in which case the string is not set.
 */
- (int) specifyImageCreateDateAndtime: (NSString*) dateString;


// ==========================================================
//! Specify a file path for use with the object
/**
 Use this method to associate the Image object with a file in the file system, assuming the file exists. If the previous representation was unknown, and the file path points to an existing file by name, then the Image object is represented by this file name, and the image representation is set to File. If the file does not exist, then you may follow this, for example, with a set bitmap, and then imageWriteToFile, in order to write it to a file. This specifyFilePath method returns errors when the call violates the contract of this object with your application. For instance, if the image representation already indicates IMAGE_REP_BOTH, then you cannot set a new file path to a non-existent file. In some cases, the file name will not be set if the specifyFilePath method returns an error.\n
 Valid file path extensions are: jpg, jpeg, tif, tiff, png and upper-case equivalents.\n
 If the file name extension is valid, then the library sets up the imageMimetype setting for you.\n
 @return KMC_SUCCESS if the file path was set correctly, or errors:\n
 - KMC_ED_OBJECT_REP_BITMAP_MISMATCH, when you try to set a file name for an existing file, when there is already a bitmap set for the object.\n
 - KMC_ED_FILE_EXTENSION, when you try to set a file name with an illegal file extension.
 */
- (int) specifyFilePath: (NSString*) fullFilePath;


// ==========================================================
//! Get the current file path
/**
 Use this method to retrieve the current file path associated with this object. In some cases, the file name may not have been set if the specifyFilePath method returned an error.
 */
- (NSString *) getFilePath;


// ==========================================================
//! Get the image ID of the input source image
/**
 Use this method to retrieve the Image ID for the original image. The imageSourceID property is set by the image processor to the image ID of the input kfxKEDImage object. You can use this to help associate an output processed image with the input image given to the image processor.
 */
- (NSString*) getImageSourceID;


// ==========================================================
//! Get the image ID of the image
/**
 Use this method to retrieve the Image ID of this original image. It is created when the kfxKEDImage class is instantiated.\n
 @see property imageID
 */
- (NSString*) getImageID;
#ifdef USE_MANAGER
- (NSString*) getFriendID;
#endif


// ==========================================================
//! Get the image metadata string
/**
 Use this method to retrieve the metadata from image processing. The image metadata is set by the image processor when an output kfxKEDImage is created by image processing to associate the output image with the processing metadata. This field is also populated by doQuickAnalysis of the image processor in the input image, so that the input image holds the quick analysis results.\n
 @see property imageMetaData
 @code
 kfxKEDImage * myOwnImage1 = [[kfxKEDImage alloc] init];
 <Perform some image processing operation>
 NSString * myMetaData = [myOwnImage1 getImageMetaData]];
 @endcode
 */
- (NSString*) getImageMetaData;


// ==========================================================
//! Get the GPS latitude associated with this image
/**
 Use this method to retrieve the GPS location where the original picture was taken.\n
 This property is set by the image capture control when taking a picture.
 */
- (float)     getImageGPSLat;


// ==========================================================
//! Get the GPS longitude associated with this image
/**
 Use this method to retrieve the GPS location where the original picture was taken.\n
 This property is set by the image capture control when taking a picture.
 */
- (float)     getImageGPSLon;


// ==========================================================
//! Get the pitch attitude of the camera when the picture was taken
/**
 Use this method to retrieve the pitch of the camera offset from the desired orientation in degrees. This property is set by the image capture control when taking a picture.
 */
- (float)     getAttitudePitch;


// ==========================================================
//! Get the roll attitude of the camera when the picture was taken
/**
 Use this method to retrieve the roll of the camera offset from the desired orientation in degrees. This property is set by the image capture control when taking a picture.
 */
- (float)     getAttitudeRoll;


// ==========================================================
//! Get the quick analysis feedback object from the last quick analysis
/**
 Use this method to retrieve the quick analysis feedback object stored in the input image. The object contains the analysis results. This property is set by the image processor when the doQuickAnalysis completed without error.
 */
- (kfxKEDQuickAnalysisFeedback *)  getImageQuickAnalysisFeedback;


// ==========================================================
//! Get the basic settings profile used in the last image processing operation
/**
 Use this method to retrieve the basic settings profile used in image processing if you specified using the basic settings profile. It is set to nil, if the image processing was performed using the image perfection profile. This property is set by the image processor when the processImage method completed without error.
 */
- (kfxKEDBasicSettingsProfile *)   getBasicSettingsProfileUsed;


// ==========================================================
//! Get the image perfection profile used in the last image processing operation
/**
 Use this method to retrieve the perfection profile used in image processing if you specified using it with image processing. It is set to nil if the image processing was performed using a basic settings profile. This property is set by the image processor when the processImage method completed without error. If you specified both a basic settings profile and an image perfection profile, the latter profile is used.
 */
- (kfxKEDImagePerfectionProfile *) getImagePerfectionProfileUsed;


+(NSString*)simpleDateTimeString:(NSDate*)date;
+(NSDate*)dateFromSimpleDateString:(NSString*)s;

// ==========================================================
//! Generate a compliant date-time string for use in this object
/**
 Use this method to generate a string appropriate for setting into the imageCreateDateTime property. When the an instance of this class is created, the library initializes the imageCreateDateTime for you. If you need to change it to a different date and time, you can use this method to create a new string.
 @see imageCreateDatetime
 @return NSString * containing the current date and time when the method is called.
 */
+(NSString*) ISO8601DateTime;


// ==========================================================
//! Generate a string from the current image representation setting
/**
 Use this method to generate a string that represents the current setting in the image representation property. This is useful for debugging when you want to display the contents of the kfxKEDImage object.
 @see imageRepresentation
 @return NSString* defining the current setting of this property.
 */
+(NSString *) decodeImageRep: (KEDImageRepresentation) option;


// ==========================================================
//! Generate a string from the current image mimetype setting
/**
 Use this method to generate a string that represents the current setting in the image mimetype property. This is useful for debugging when you want to display the contents of the kfxKEDImage object.
 @see imageMimetype
 @return NSString* defining the current setting of this property.
 */

+(NSString *) decodeMimetype: (KEDImageMimeType) option;


// ==========================================================
//! Generate a string from the current output color setting
/**
 Use this method to generate a string that represents the current setting in the imageFileOutputColor property. This is useful for debugging when you want to display the contents of the kfxKEDImage object.
 @see imageFileOutputColor
 @return NSString* defining the current setting of this property.
 */
+(NSString *) decodeFileColor: (KEDOutputColor) color;


// ==========================================================
//! Initialize an object allocated for use
/**
 Use this method to initialize an allocated object. It sets all the default settings for the object and prepares it for use.
 @code
   kfxKEDImage * myOwnImage1 = [[kfxKEDImage alloc] init];
 @endcode

 @return kfxKEDImage object
 */
- (id)init;


// ==========================================================
//! Initialize an allocated object with a specific image
/**
 Use this method to initialize an allocated object with an input image. It sets all the default settings for the object and prepares it for use.\n

 @code
 UIImage * myUIImage;
 (Get this UIImage from the photoroll, an image in your bundle or an image from any source.)
 kfxKEDImage * myOwnImage1 = [[kfxKEDImage alloc] initWithImage: myUIImage];
 @endcode
 
 @return kfxKEDImage object
 */
- (id)initWithImage:(UIImage*)image;

@end
#endif

