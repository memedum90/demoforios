// kfxKLOVersion.h
// Utility Objects
// Created by David Duffy on 8/8/13.
// Copyright (c) 2012 - 2014 Kofax. Use of this code is with permission pursuant to Kofax license terms.

#import <Foundation/Foundation.h>

//! This class includes a method which returns the SDK Logistics Framework version.
/**
 This class provides a means of retrieving the version string for the logistics framework of the Kofax Mobile SDK.
 */
@interface kfxKLOVersion : NSObject

//! The factory method.
/**
 This method returns a singleton object of kfxKLOVersion.
 @code
 kfxKLOVersion* kloVersion = [kfxKLOVersion kloInstance];
 @endcode
 */
+ (kfxKLOVersion*)kloInstance;

//! Logistics package version string
/** 
 This property contains the Logistics version string.
 */
@property (retain, readonly) NSString *packageVersion;

//! Retrieve the logistics framework version.
/** This method retrieves the version string for the Logistics framework
 */
- (NSString *)getPackageVersion;

@end
