// kfxKUIVersion.h
// Utility Objects
// Created by David Duffy on 8/8/13.
// Copyright (c) 2012 - 2014 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <Foundation/Foundation.h>

//! This class includes a method which returns the SDK UIControls Framework version.
/**
 This class provides a means of retrieving the UI Controls framework version string of the Kofax Mobile SDK.
 */
@interface kfxKUIVersion : NSObject

//! The factory method.
/**
 This method returns a singleton object of kfxKUIVersion.
 @code
 kfxKUIVersion* kuiVersion = [kfxKUIVersion kuiInstance];
 @endcode
 */
+ (kfxKUIVersion*)kuiInstance;

//! UI Controls framework version string
/**
 This is the version string for the UI Controls framework.
 */
@property (retain, readonly) NSString *packageVersion;

//! Retrieve the UI Controls framework version.
/** This method retrieves the version string for the UI Controls framework.
 */
- (NSString *)getPackageVersion;

@end
