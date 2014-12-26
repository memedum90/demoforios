// kfxKEDVersion.h
// Utility Objects
// Created by David Duffy on 8/8/13.
// Copyright (c) 2012 - 2014 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <Foundation/Foundation.h>

#ifndef KFX_KED_VERSION_INCLUDED
#define KFX_KED_VERSION_INCLUDED

//! This class includes a method which returns the SDK Engines package version.
/**
 This class provides a means to retrieve the version string for the Engines
 framework of the Kofax Mobile SDK.
 */
@interface kfxKENVersion : NSObject

//! The factory method.
/**
 This method returns a singleton object of kfxKENVersion.
 @code
 kfxKENVersion* kenVersion = [kfxKENVersion kenInstance];
 self.labelEnginesVersion.text = [kenVersion getPackageVersion];
 @endcode
 */
+ (kfxKENVersion*)kenInstance;

//! Engines package version string
/**
 This property is the version string for the Engines Framework.
 */
@property (retain, readonly) NSString *packageVersion;

//! Retrieve the Engines package version.
/** Use this method to retrieve the version string for the Engines Framework.
 @code
 kfxKENVersion* kenVersion = [kfxKENVersion kenInstance];
 self.labelEnginesVersion.text = [kenVersion getPackageVersion];
 @endcode
 */
- (NSString *)getPackageVersion;

@end
#endif

