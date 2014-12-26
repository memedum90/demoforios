//  API Reference
//
//  kfxKLOUserProfile.h
//  KMCLogistics Objects
//
//  Created by Mark Day on 10/4/13.
//  Copyright (c) 2012 - 2014 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>

//! Server User Profile
/**
 Framework: libKfxLogistics\n
 Import suggestion: #import <kfxLibLogistics/kfxLogistics.h>\n
 An instance of this class contains all the user information needed to login to a server.
 */
@interface kfxKLOUserProfile : NSObject

// ==========================================================
//! Session user name
/**
 The user name formatted as needed for this server.\n
 Default: nil
 */
@property (strong) NSString* username;

// ==========================================================
//! Session password associated with the user name
/**
 The password formatted as needed for this server.\n
 Default: nil
 */
@property (strong) NSString* password;


// ==========================================================
//! Session domain
/**
 The domain name for the server to which you want to connect.\n
 Default: nil
 */
@property (strong) NSString* domain;

// ==========================================================
//! User's email address
/**
 The email address associated with the user for the server to send notifications for successful server transactions.\n
 Default: nil
 */
@property (strong) NSString* userEmailAddress;
@end
