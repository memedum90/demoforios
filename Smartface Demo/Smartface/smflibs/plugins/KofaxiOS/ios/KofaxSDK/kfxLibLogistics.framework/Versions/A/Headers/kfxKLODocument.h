//
//  KMC SDK API Reference file
//  kfxKLODocument.h
//  KMCCaptureData
//
//  Created by David Duffy on 10/11/13.
//  Copyright (c) 2012 - 2014 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>
#import "kfxKLODocumentType.h"
#import "kfxKLOPage.h"

//! Document object is instantiated as a specific DocumentType.
/**
 The Document object contains pages and document related data that constitute the Document.  The object contains zero or more Field objects that contain the document data, and one or more Page objects that contain images.
 \n\n
  **Initialization**
 \n\n
 
 The Document object is the top level class of the logistics data hierarchy. It brings together the DocumentType, FieldType, Field, and Page objects and provides a vehicle for submitting case information and images to a server. An application desiring to use the SDK to submit data to a server must instantiate and populate a Document object. The Document object is instantiated with a DocumentType object, using the initWithDocumentTypeObject method. The DocumentType object contains an array of FieldType objects which are used to instantiate Field objects. These Field objects populate an array within the Document object.
 \n\n
 **Life Cycle**
 \n\n
 
 After instantiation, one or more Page objects can be added to an array maintained in the Document object. Each page object contains an array of one or more images. A method is also provided to remove pages from the Document object. Once a Document object is created with at least one page, and at least one image is included in that page, the document is ready to be sent to a server using kfxKLOFrontOfficeServer or kfxKLOTotalAgilityServer. Once the document has been successfully submitted to the server, it would normally be deleted by setting it to nil. However, this should not be done until any underlying image files are deleted from the documents folder. After the object is deleted, its memory allocations are freed.\n\n
 If the document is to be kept, it could be serialized to a file, from which it can be restored if the document is to be resent to the server. It is always a good idea to conserve memory and remove sensitive customer data.
 \n\n
**Serialization**
\n\n
 
This class adopts the NSCoding protocol so that this object may be archived and unarchived using the iOS standard [NSKeyedArchiver archiveRootObject:<object> toFile: archiveFileName]; approach.  Using keyed archive files, you can save this object for later use.  The library supports backward compatibility, such that as a new version of an app that uses the API in this SDK, includes a newer versions of the SDK libraries that have data model changes, the older archive can still be read by the newer version.  However, it is not a design goal to archive and dearchive with forward compatibility, such as decoding an archive on a newer version of the class, using an older library.\n\n
 Refer to the kfxKEDImage class description, by expanding the class description, that describes how to archive and unarchive objects in this framework that adopt the NSCoding protocol.\n\n
 You can create keyed archives using NSKeyedArchiver objects and decoded by NSKeyedUnarchiver objects. The framework design uses keyed archives, which differ from sequential archives, in that every value encoded in a keyed archive is given a Kofax unique key name. When you decode an archive, the underlying implementation can use values by name, allowing the unarchive delegate to request values in any order or not at all.\n
 
 Please refer to the Apple documentation for more information: https://developer.apple.com/library/ios/documentation/cocoa/reference/foundation/Classes/NSCoder_Class/Reference/NSCoder.html
 \n\n
 **Keyed Archiving**
 https://developer.apple.com/library/mac/documentation/Cocoa/Reference/Foundation/Classes/NSKeyedArchiver_Class/Reference/Reference.html#//apple_ref/occ/cl/NSKeyedArchiver
 \n\n
 **Keyed Unarchiving**
 https://developer.apple.com/library/mac/documentation/Cocoa/Reference/Foundation/Classes/NSKeyedUnarchiver_Class/Reference/Reference.html#//apple_ref/occ/instm/NSKeyedUnarchiver


 */
@interface kfxKLODocument : NSObject <NSCoding>

//! DocumentType object.
/**
 The DocumentType object is used to instantiate the Document object, and describes the type of document.
 */
@property (retain, readonly) kfxKLODocumentType *documentType;

//! Fields array.
/**
 This array of Field objects is created during Document object initialization from the FieldType objects in the provided DocumentType object. This array is created during object initialilization and can't be modified afterwards.
 */
@property (retain, readonly) NSArray *fields;

//! Pages Array.
/**
 Each page object in this array contains one or more images. Objects may be added to this array or removed from this array using the addPage and removePage methods.
 */
@property (retain, readonly) NSMutableArray *pages;

//! addPage Method.
/**
 This method adds Page objects to the pages array.
 */
- (void) addPage: (kfxKLOPage *)objectPage;

//! removePage Method.
/**
 This method removes a page from the 'pages' array property. The image to be removed is determined by matching the supplied pageID string to the contents of the pages in the array.
 @returns KMC_SUCCESS, for success\n
 KMC_LO_PAGE_NOT_FOUND, when an image matching the supplied imageID could not be found.\n
 */
- (int) removePage: (NSString *)pageID;

//! initWithDocumentTypeObject method.
/**
 This method is used to initialize the Document object. The provided documentType object is required to perform the initialization. This method uses the FieldType information contained in the DocumentType object to populate a Field array the Document object. An example follows:
 @code
 kfxKLODocument *theDocument = [[kfxKLODocument alloc] initWithDocumentTypeObject: theDocumentType];
 @endcode
 */
- (id) initWithDocumentTypeObject: (kfxKLODocumentType *)documentTypeObject;

@end
