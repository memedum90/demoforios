//
// API Reference
// kfxKUTSdkVersion.h
// Utility Objects
// Created by David Duffy on 8/8/13.
// Copyright (c) 2012 - 2014 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <Foundation/Foundation.h>

//! This class includes methods to determine the versions of several portions of the SDK, and the top level SDK Product version.
/**
 This class provides a means of retrieving the version strings for components of the Kofax Mobile SDK. This includes the SDK product, Image Perfection software, Classifier and Utilities frameworks.
 */
@interface kfxKUTSdkVersion : NSObject

//! The factory method for getting a common instantiation.
/**
 Use this method to get a singleton object of kfxKUTSdkVersion.  Once you have an instance of this class, you can retrieve the version strings.
 @code
 kfxKUTSdkVersion* sdkVersion = [kfxKUTSdkVersion sdkInstance];
 @endcode
 */
+ (kfxKUTSdkVersion*)sdkInstance;

//! SDK Version string
/** This property contains the version string for the Kofax Mobile SDK.
 */
@property (retain, readonly) NSString *sdkVersion;

//! Image Perfection software version string
/**
 This property contains the version string for image perfection software.
 */
@property (retain, readonly) NSString *ipVersion;

//! Utililities Framework version string
/**
 This property contains the Kofax Mobile SDK Utilities Framework version string.
 */
@property (retain, readonly) NSString *PackageVersion;

//! Classifier version string
/**
 This property contains the Kofax Image Classifier version string.
 */
@property (retain, readonly) NSString *ClassifierVersion;

//! Retrieve the Kofax Mobile SDK version.
/** Use this method to retrieve the version string for the Kofax Mobile SDK.
*/
- (NSString *)getSdkVersion;

//! Retrieve the Image Perfection software version.
/** This method retrieves the version string for the image perfection software.
 */
- (NSString *)getIpVersion;

//! Retrieve the Utilities framework version.
/** Use this method to retrieve the KMC SDK Utilities framework version string.
 */
- (NSString *)getPackageVersion;

//! Retrieve the Classifier version.
/** Use this method to retrieve the version string for the Classifier.
 */
- (NSString *)getClassifierVersion;

@end
