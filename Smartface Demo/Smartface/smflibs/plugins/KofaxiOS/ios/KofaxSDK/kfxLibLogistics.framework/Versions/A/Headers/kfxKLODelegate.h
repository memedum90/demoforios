//  API Reference for Logistics Framework
//  kfxKIPDelegate.h
//  kfxLibEngines
//
//  Created by Mark Day on 10/4/13.
//  Copyright (c) 2012 - 2014 Kofax. Use of this code is with permission pursuant to Kofax license terms.
//
#import <Foundation/Foundation.h>
#import "kfxKLODocumentType.h"

typedef enum kfxSessionStatus {
    SESSION_UNREGISTERED = 0,
    SESSION_REGISTERING,        // caused by registerDevice method call
    SESSION_REGISTERED,         // caused by registerDevice completed without error, else back to logged out
    SESSION_LOGGING_IN,         // caused by the login method
    SESSION_LOGGED_IN,          // caused by the login completed without error, else back to registered. (error indicates login failed in the event)
    SESSION_GETTING_DOCUMENT_FIELDS,  // caused by the getDocumentType method
    SESSION_GETTING_IP_SETTINGS,    // Part 2 of the getDocumentType method, after Document Fields are retreived
    SESSION_PREPARING_DOCUMENT_TYPE,    // While DocumentType object is getting created an populated
    SESSION_DOCUMENT_TYPE_READY,           // when the get document fields worked ok, else back to logged in state, event indicates the errors with either getting the field types or the scan settings.
    SESSION_SUBMITTING,         // caused by submit
    SESSION_SUBMIT_COMPLETED,   // if all images submitted ok, but if error it takes you to the document ready state (so you could retry the submit)
    SESSION_LOGGING_OUT,        // caused by the logout method, takes you to the registered state, with an event error if logout failed or success if ok
    
} KFS_SessionStatus;

//!  Logistics Server Protocol
/**
 The kfxKLODelegate defines the protocol for all the delegates for the front office server operations.  The library uses these delegates during web services processing to notify you about asynchronous events.
 */
@protocol kfxKLODelegate <NSObject>
@required

//!  Session Status Changed Delegate
/**
 The library calls this method when the status of the server connection changes based on methods used.\n
 This is a required delegate.\n
 @param  status : Set to KMC_SUCCESS if no error occurred, otherwise an error code.
 @param  errorMsg : A description of the error that occurred.
 @param  state : A definition of the current state
 @param  progressPercent: progress of a submit, when the submitDocument method is called.  One percent update is for each image of a document.  If there is only one image in the document, you will get one session submitting event of 0%, then a submit complete with a progressPercent of 100%.\n
     If there are two images in the document, you will get one session submitting event with 0%, followed by another session submitting with percent of 50%, followed by a submit completed with a percent of 100%;
 */
- (void)sessionChanged:(int)status withMsg: (NSString*) errorMsg andNewState: (KFS_SessionStatus) state andProgress: (int) progressPercent;

//!  Document Type Ready Delegate
-(void) documentTypeReady: (int)status withMsg: (NSString*) errorMsg withDocumentType: (kfxKLODocumentType *) docType;

@end
