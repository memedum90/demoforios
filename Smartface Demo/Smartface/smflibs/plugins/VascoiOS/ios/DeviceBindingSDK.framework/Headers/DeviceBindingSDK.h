/* Copyright(c) 2013 VASCO Data Security, Inc, VASCO Data Security        */
/* International GmbH. All rights reserved. VASCO(R), VACMAN(R),          */
/* IDENTIKEY(R), aXsGUARD(TM), DIGIPASS(R), and "VASCO 'V' logo"(R) are   */
/* registered or unregistered trademarks of VASCO Data Security, Inc.     */
/* and/or VASCO Data Security International GmbH. in the U.S. and other   */
/* countries. 
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define DeviceBindingSDK_VERSION  @"4.2.0"

/**
 * This class provides a method to generate a device fingerprint
 */
@interface DeviceBindingSDK : NSObject

/**
 * Gets a device fingerprint
 * @param salt Optional salt which can be added to the device fingerprint computation process.
 * @return 64 hexadecimal characters uniquely identifying the iOS device.
 * @throws DeviceBindingSDKException If a problem occurs while generating the device fingerprint.<br/>
 * The exception can contain one of the following error codes: 
 * <ul>
 *  <li>DeviceBindingSDKErrorCodes_INTERNAL_ERROR if an internal error occurs (see DeviceBindingSDKErrorCodes.h).</li>
 * </ul>
 */
+(NSString * ) getDeviceFingerPrintWithSalt:(NSString *) salt ;

/*!
 * \mainpage DeviceBinding SDK API - Programmer documentation
 * \brief Provides the entry points of the DeviceBinding SDK framework API:
 * <ul>
 *  <li>Calling the method [DeviceBindingSDK getDeviceFingerPrint] generates and stores a unique device fingerprint </li>
 *  <li>DeviceBindingSDKException is thrown if an internal error occured.</li>
 * </ul>
 * Copyright 1999 - 2013. VASCO DATA SECURITY. All Rights Reserved.
 * @version 4.2.0
 */


@end
