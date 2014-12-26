//
//  API Reference 
//  kfxKLOTotalAgilityServer.h
//  Framework: kfxLibLogistics
//
//  Created by David Duffy on 10/19/13.
//  Copyright (c) 2012 - 2014 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//

#import <UIKit/UIKit.h>
#import "kfxKLOUserProfile.h"
#import "kfxKLODelegate.h"
#import "kfxKLODocumentType.h"
#import "kfxKLODocument.h"

//! The Total Agility Server Class
/**
 Framework: libKfxLogistics\n
 Import suggestion: #import <kfxLibLogistics/kfxLogistics.h>\n
 Relevant Header File: kfxKLOTotalAgilityServer.h\n
 An instance of this class contains methods to interface with the Total Agility server.
 */
@interface kfxKLOTotalAgilityServer : NSObject

//! The Server URL
/**
 Set this property to the URL for the server that you want to use with the login method.
 */
@property NSString* serverURL;


//! The Session status
/**
 This is a readonly status of the current session represented by this object.
 */
@property (readonly,atomic) KFS_SessionStatus sessionStatus;


/**
 This method returns a singleton object of kfxKLOTotalAgilityServer
 @code
 kfxKLOTotalAgilityServer* myServer = [kfxKLOTotalAgilityServer instance];
 @endcode
 */
+ (kfxKLOTotalAgilityServer*) instance;

//! Register your mobile device
/**
 Use the register method to check to see if this device has access to a valid server license.
@return
KMC_IP_LICENSE_INVALID, if you have not set the license through the Utilities library.\n
KMC_LO_REGISTERING, if the library is already in the process of registering.\n
KMC_LO_SESSION_STATE_BUSY, if you are overlapping a server operation with a previously started operation, usually caused by not waiting for the status changed event before proceeding.\n
 */
-(int) registerDevice;


//! Log into the Total Agility server
/**
 Use the login method to log into the server specified by the serverURL property.  This method uses the user profile that contains the username and password in order to log into the server.  You must create or mananage a user profile object and supply it with this method.\n
@return
KMC_IP_LICENSE_INVALID, if you have not set the license through the Utilities library.
KMC_LO_NOT_REGISTERED, if you have not registered your device yet.\n
KMC_LO_REGISTERING, if the library is in the process of registering your device.\n
KMC_LO_USER_ALREADY_LOGGED_IN, if you are already logged in.  Log out and log in again if necessary.\n
KMC_LO_LOGIN_NOT_ALLOWED, if you are in an invalid state to login, such as during submission or after a document has been created.\n
KMC_LO_USER_LOGGING_IN_ON_LOGIN, if you are already logging in from a previous method call.\n 
KMC_LO_SESSION_STATE_BUSY, if you are attempting to change current state while the library is already in the process of doing another operation, such as a login while the library is already logging in.\n
KMC_LO_SERVER_URL_NOT_SET, if the server URL is invalid.\n
KMC_LO_USERNAME_NOT_SET, if the user name or password is invalid.\n
KMC_LO_DOMAIN, if the domain string in nil.\n
KMC_LO_EMAIL, if the email is invalid when the server type indicates that it is required.\n
 */
-(int) login: (kfxKLOUserProfile*) profile;


//! Logout from the Total Agility server.
/**
Use the logout method to log out of the server currently used for the current session.
@return
KMC_IP_LICENSE_INVALID if no license set.\n
KMC_LO_NOT_REGISTERED, if you have not registered your device yet.\n
KMC_LO_REGISTERING, if the library is in the process of registering your device.\n
KMC_LO_USER_ALREADY_LOGGED_OUT, if you have already logged out.\n 
KMC_LO_SESSION_STATE_BUSY, if you are attempting to change current state while the library is already in the process of doing another operation, such as a login while the library is already logging in.\n
KMC_LO_USER_NOT_LOGGED_IN_ON_LOGOUT, if you have not logged in yet.\n
 */
-(int) logout;

//! Cancel current operation.
/**
 Attempts to cancel a method already started.  May or may not be cancellable.
 @return
 Enum TBD.\n
 */

-(int) cancel;

//! Returns a list of available DocumentType names.
/**
 Use the getDocumentTypeList method to return an array of NSStrings containing DocumentType names that this server supports.
 @return
 An NSArray of NSStrings.
 */

-(NSArray *) getDocumentTypeList;


//! Get a DocumentType Object
/**
 Use the getDocumentType method to send off a request to get a kfxKLODocumentType object, matching the given DocumentType name.
 Note that this is an asynchronous operation; You must implement the documentTypeReady of the kfxKLODelegate protocol in order to
 receive the kfxKLODocumentType object.
 @return
 Enum TBD.\n
 */

-(int) getDocumentType: (NSString *) documentTypeName;


//! Submit a Document
/**
 Submits a kfxKLODocument object to the Total Agility server.
 @return
 Enum TBD.\n
 */

-(int) submitDocument: (kfxKLODocument *) theDoc;


//! kfxKLODelegate notifies you about changes in your session state
/**
 You must set this delegate to self in order for your app to receive the session changed and other delegate calls.
 */
@property (atomic, assign) id<kfxKLODelegate>      delegate;

-(void) setDelegate:(id<kfxKLODelegate>)delegate;

-(id<kfxKLODelegate>) delegate;

@end
