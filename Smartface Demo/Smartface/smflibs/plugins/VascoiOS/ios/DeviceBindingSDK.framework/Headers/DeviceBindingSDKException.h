/* Copyright(c) 2013 VASCO Data Security, Inc, VASCO Data Security        */
/* International GmbH. All rights reserved. VASCO(R), VACMAN(R),          */
/* IDENTIKEY(R), aXsGUARD(TM), DIGIPASS(R), and "VASCO 'V' logo"(R) are   */
/* registered or unregistered trademarks of VASCO Data Security, Inc.     */
/* and/or VASCO Data Security International GmbH. in the U.S. and other   */
/* countries. 
 */

#import <Foundation/Foundation.h>

/**
 * This exception is thrown when a problem occurs while generating the device fingerprint.
 */
@interface DeviceBindingSDKException : NSException {
    
    int errorCode ;

    NSException * exception ;
    
}

/** Indicates the causes of the error */
@property int errorCode ;

/** The cause of the error as a NSException */
@property (nonatomic , strong) NSException * exception ;

/**
 * Instanciate and initialize a DeviceBindingSDKException
 */
-(id) initWithCause:(NSException *) cause ;

@end

