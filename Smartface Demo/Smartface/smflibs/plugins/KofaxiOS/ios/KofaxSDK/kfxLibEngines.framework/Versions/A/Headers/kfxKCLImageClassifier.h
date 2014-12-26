//  Kofax Mobile Capture API Reference File
//  kfxKCLImageClassifier.h
//  Included within kfxLibEngines
//
//  Copyright (c) 2012 - 2014 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>

#import "kfxKEDImage.h"

@class kfxKCLImageClassifier;

/// Image Classification Protocol
/**
 The kfxKCLDelegate defines the protocol for all the delegates the Image Classification Engine
 during processing.  Only a single delegate is defined, which signals the completion of
 asynchronous classification operations.
 */
@protocol kfxKCLDelegate <NSObject>

@optional

/// Classification Complete Delegate
/**
 The engine calls this delegate when a classification operation is complete.  The image parameter
 is the same image that was passed into the corresponding classifyImage call.  The classification
 results are available through the image's classificationResults property.
 
 @param imageClassifier The imageClassifier instance that invoked the delegate.
 @param status          The status of the completed classification.
 @param statusMsg       A message corresponding to the given status.
 @param image           The image classification was performed on, with results set internally.
 */
- (void) imageClassifier: (kfxKCLImageClassifier *) imageClassifier
    status: (int) status
    statusMsg: (NSString *) statusMsg
    image: (kfxKEDImage *) image;

@end

/// The Image Classifier Singleton Object
/**
 Framework: libKfxEngines\n
 Import suggestion: #import <kfxLibEngines/kfxEngines.h>\n
 Relevant Header File: kfxKCLImageClassifier.h\n
 
 An instance of this class contains methods to classify images based on a given configuration and
 model.  An example of classification would be taking captured images of drivers licenses and
 classifying them by the issuing state.\n
 The configuration files for use with this API are contained in the SDK in the "Configuration Files" folder of the SDK deliverable.  Use the Configuration file (driverslicense_config.xml) with the loadConfigurationFile method to setup the classifier to classify United States drivers licenses.\n
 Use the model file (driverslicense_model.xml) with the loadModel method to setup the model for the classifier.  Once these files are loaded, you can use the classifyImage method to determine what type of drivers license is contained in the kfxKEDImage object.\n\n
 **Licensing**
 \n\n
 This is a license protected class. Certain methods in this object are protected by a license mechanism. If you attempt to use these methods without setting the license, then you will receive the KMC_IP_LICENSE_INVALID error code. Refer to the method descriptions to determine what methods are license protected. In order to set your license, you need to use the setMobileSDKLicense method on the kfxKUTLicensing object. Example code is provided to show you how to set your license, which can be found in the kfxKUTLicensing class of the kfxUtilities framework.\n\n
 
 */
@interface kfxKCLImageClassifier : NSObject

/// The Classifier factory method
/**
 This method returns a singleton object of kfxKCLImageClassifier.  If an instance does not
 already exist, it will be created and initialized at the time of the call.
 
 @return An instance of the classifier engine.
 \n\n
 Example of how to get an object to work with the classifier, initializing the classifier and classifying an image.
 @code
    int errorCount = 0;  // use an error count just for testing purposes in this code snippet
    // Create an image object to hold the image to be classified 
    kfxKEDImage * myOwnImage = [[kfxKEDImage alloc] init];
    
	// Access the model and configuration files included in the application's bundle.
    NSBundle* myBundle = [NSBundle mainBundle];
    NSString * procImage = [myBundle pathForResource:@"imageToClassify" ofType:@"jpg"];  // a picture of a US Driver's license.
    NSString* cfgFileName = [myBundle pathForResource:@"driverslicense_config" ofType:@"xml"];
    NSString *modelFileName = [myBundle pathForResource:@"driverslicense_model" ofType:@"xml"];
	
	// Get the instance of the image classifier.    
    kfxKCLImageClassifier * imageClassifier = [kfxKCLImageClassifier instance];
    
	// Show the default number of results
    int count = imageClassifier.maxNumberOfResults;
    NSLog(@"Default Max Number of results: %d",count);
    
	// Setup that we want a maximum of three classification result possibilities
	imageClassifier.maxNumberOfResults = 3;
    
	// Test loading an invalid configuration file
    int error = [imageClassifier loadConfigurationFile: @"bogus.txt"];
    
    if (error != KMC_GN_FILE_NOT_FOUND)
        errorCount++;
    
    error = [imageClassifier loadModel:@"bogus.txt"];
    if (error != KMC_GN_FILE_NOT_FOUND)
        errorCount++;
    
	// Initialize the classifier
    [imageClassifier loadConfigurationFile:cfgFileName];
    [imageClassifier loadModel:modelFileName];

	// Setup the delegate to this view controller, so the classifier can notify me when the classification is completed.
    imageClassifier.delegate = self;
    self.classifydone = false;
    
	// Get the image to classify from the file path created above.
    UIImage *img = [UIImage imageWithContentsOfFile:procImage];

	// Set the image into the kfxKEDImage object
    error = [myOwnImage specifyImageBitmap:img];
    if (error != KMC_SUCCESS)
        errorCount++;

    // Now classify the image using the asynchronous operation    
    error = [imageClassifier classifyImage:myOwnImage];
    if (error != KMC_SUCCESS)
	{
	   errorCount++;
	   // handle the error condition directly here, because the classification did not start.
	}

	// Continue on with your application after the classification delegate is called.

 @endcode
 */
+ (kfxKCLImageClassifier *) instance;

/// A delegate to receive messages from the engine.
/**
 You must set this delegate to the reference of an object that will process messages at the end of
 classification.  This is usually "self" of the object using the classifier.
 */
@property (atomic, strong) id<kfxKCLDelegate> delegate;

/// The maximum number of results to return from a classify operation.
/**
 Acceptable values are in the range [1, 64].  The default value is 1.
 */
@property (atomic, assign) int maxNumberOfResults;

/// Loads a file that contains the configuration values for the classifier.
/**
 Both a configuration and model must be loaded before starting a classify operation.
 
 @param     configFileName  Full path to the configuration file.
 
 @retval    KMC_SUCCESS             The configuration loaded without error.
 @retval    KMC_EV_LICENSING        A valid license has not yet been set.
 @retval    KMC_CL_CONFIG_NULL      The configFileName parameter was null or empty.
 @retval    KMC_GN_FILE_NOT_FOUND   The configuration file could not be found.
 */
- (int) loadConfigurationFile: (NSString *) configFileName;

/// Loads a model file that contains the knowledge source for classification.
/**
 Both a configuration and model must be loaded before starting a classify operation.
 
 @param     modelFileName  Full path to the model file.
 
 @retval    KMC_SUCCESS             The model loaded without error.
 @retval    KMC_EV_LICENSING        A valid license has not yet been set.
 @retval    KMC_CL_MODEL_NULL       The modelFileName parameter was null or empty.
 @retval    KMC_GN_FILE_NOT_FOUND   The model file could not be found.
 */
- (int) loadModel: (NSString *) modelFileName;

/// Starts the image classification process.
/**
 A configuration and model must be loaded before calling classifyImage.  Classification will
 be performed asynchronously.  Once classification is complete, the delegate will receive a
 imageClassifier:status:statusMsg:image: message.
 
 After classification, an array of classification results will be saved in the input image.
 
 @param     imageToClassify A kfxKEDImage object containing the image that needs classification.
 
 @retval    KMC_SUCCESS                     Classification started without error.
 @retval    KMC_EV_LICENSING                A valid license has not yet been set.
 @retval    KMC_CL_CONFIG_NOT_LOADED        A configuration has not been loaded.
 @retval    KMC_CL_MODEL_NOT_LOADED         A model has not been loaded.
 @retval    KMC_CL_CLASSIFIER_BUSY          A classification is already in progress.
 @retval    KMC_CL_NO_IMAGE_SUPPLIED        A null images was passed in.
 @retval    KMC_CL_INVALID_IMAGE_SUPPLIED   The input image had no valid bitmap or file.
 \n\n
 @see kfxKEDClassificationResult for information regarding one element of the array of possible classification results.
 */
- (int) classifyImage: (kfxKEDImage *) imageToClassify;

@end
