//
//  API Reference
//  kfxKUTLicensing.h
//  Framework: kfxLibUtilities
//
//  Created by Mark Day on 8/6/13.
//  Copyright (c) 2012 - 2014 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <Foundation/Foundation.h>

#define KUT_MINIMUM_LICENSE_LENGTH      20

//! License for unlocking library features
/**
 An instance of this class contains the properties and methods you must use to set the usage license.  Once you set your usage license, you can use included properties to determine the license end date.  Once you set the license, other library API methods work as designed.  The license remains valid while the app is still running.\n\n
 Classes that contain licensed methods will include a description that highlights that it is a license protected class. Certain methods in that object are protected by this license mechanism. If you attempt to use the instance methods without setting the license, then you will receive the KMC_IP_LICENSE_INVALID error code in most cases. Refer to the method descriptions within the class to determine what methods are license protected. You use the setMobileSDKLicense method on the kfxKUTLicensing object to set the license.\n\n 
 Examples of licensed classes include kfxKEDImage, kfxKENImageProcessor and kfxKCLImageClassifier.\n\n
 Note: You can only set a valid license once per session, due to resource allocations with licensing.  Therefore you may receive an error on the second attempt, but not if the previous call used an invalid license.\n
 */
@interface kfxKUTLicensing : NSObject

// ===================================================
//! Indicates the number of days before the license expires
/**
 After you set the license, this field indicates how many days are left in your license. The library initializes this value to 0.
 */
@property (readonly) int daysRemaining;

// ===================================================
//! Sets the SDK usage license
/**
 The input to this method is the VRS license string.  If the license string is valid and days remain in the license, this method returns KMC_SUCCESS and sets the daysRemaining property to the number of days remaining in the license. If the license string is valid but no days remain in the license, this method returns KMC_IP_LICENSE_EXPIRED. If the license string is not valid, this method returns KMC_IP_LICENSE_INVALID. Any failure to set the license sets the daysRemaining property to zero.\n
 The license can only be set once.\n
 @param license is the valid license string that was contained in a distributed header file that you received from Kofax.
 @return
 This method returns an error code if the license string is invalid, or KMC_SUCCESS if the license was setup correctly.  The error codes include:\n
 - KMC_IP_LICENSE_INVALID if the license string used is nil.\n
 - KMC_IP_LICENSE_ALREADY_SET if you have already set the license.\n
 - EVRS_IP_LICENSING_FAILURE if the license string is invalid for setting a license.\n
 - EVRS_IP_LICENSE_EXPIRATION_ERROR if the time limit of your license has expired.\n
 \n\n
 Example code follows showing how to set your license.

 @code
 #import <kfxLibUtilities/kfxUtilities.h>
 #import "kfxEVRS_License.h"                 // the file Kofax distributes

 NSString * myTestLicense = nil;
 myLicense = [[kfxKUTLicensing alloc] init]; // create the licensing object
 myTestLicense = [NSString stringWithFormat: @"%s",PROCESS_PAGE_SDK_LICENSE]; // get the license from the distributed license.h file
 error = [self.myLicense setMobileSDKLicense:myTestLicense];                  // set the license
 if (error != KMC_SUCCESS)
 {
    NSString *msg = [kfxError findErrMsg: error];
    NSString *desc = [kfxError findErrDesc:error];
    NSLog(@"License error: %@\n%@",msg,desc);
    NSLog(@"License INVALID");
    NSLog(@"Days remain: %d",[myLicense daysRemaining]);
 }
 else
 {
    NSLog(@"License valid");
    NSLog(@"Days remain: %d",[myLicense daysRemaining]);
 }
 @endcode
 */
- (int) setMobileSDKLicense: (NSString*) license;

@end
