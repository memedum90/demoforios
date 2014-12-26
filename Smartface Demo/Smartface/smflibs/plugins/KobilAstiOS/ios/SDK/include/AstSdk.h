#import <Foundation/Foundation.h>

#import "AstSdkTypes.h"
#import "AstUpdate.h"
#import "AstUpdateListener.h"
#import "AstChannel.h"
#import "AstSecureWebViewListener.h"


/**
 * @brief interface class of the Kobil Application Security Technology SDK
 */
@protocol AstSdk

/**
 * @brief Initialization of the AstSdk<br />
 *        This method must be invoked before any communication can take place.
 * 
 * The method is an synchronous call. After its completion, the AstSdk calls either<br />
 * {@link AstSdkListener::onActivationBegin:} - if the App was started for the first time and therefore is not activated yet or <br />
 * {@link AstSdkListener::onLoginBegin:userIdList:} - if the App is already activated and it can continue to display a login screen OR if a mIDentity device is used
 *			
 * @warning The init function calls {@link AstSdkListener::getAppConfigParameter:} during initalization. 
 *          Also onAlert may be called when an error occurs even, if init returns with an error.
 * 
 * @param[in] locale
 *            The language of the App. This will be used for messages that will be returned to the App.
 * 
 * @param[in] version
 *            version as string "<major>.<minor>.<build>" (e.g. "3.4.24353"; major and minor may each between 0 and 255, build may be between 0 and 4294967295)
 *
 * @param[in] appName
 *            To distinguish the Apps, an App must have a name.<br />
 *            Apps with different names may have the same version numbers.<br />
 *            Encoding of this string is UTF-8 and it has a maximum length of 32 bytes.
 *
 * @return status code
 *
 * @note You should call exit at the end of the session or if the App has to go into standby
 */
- (AstStatus)init:(NSString*)locale version:(NSString*)version appName:(NSString*)appName;

/**
 * @brief Puts SDK into suspend.
 * 
 * This method allows the App to put the SDK into a suspended state, where
 * it can be minimized and put into background. During suspend there is no SSMS
 * communication and calls to doXxx methods are not allowed. Calling suspend while already suspended does nothing.
 *
 * This is a synchronous call. It may be called any time the SDK is
 * initialized. It is followed with resume.
 *
 * @note Certain hardening measurements are deactivated during suspend
 * and the overall security level is reduced. Only suspend if required by
 * your use case.
 */
- (void)suspend;

/**
 * @brief Resumes the SDK from suspended state.
 *
 * This method allows the App to put the SDK into active state after it was
 * suspended. The App shall call it after it is resumed from background
 * operation and wait for its execution before using other features of the
 * SDK again.
 *
 * If the execution of suspend could not be finished before background was
 * enforced by the operating system, the App must ensure that execution of
 * suspend is finished before calling resume.
 * For the certififcate policy both the SDK will resume successful, if the virtual device
 * session can be restored even if the hardware session was closed, e.g. due to an alert.
 *
 * This is a synchronous call. It may be called after suspend.
 * The next SDK interaction is determined by the returned status.
 *
 * @return
 * - AstStatus_OK - execution successful, SDK operation is resumed a the same state where <code>suspend()</code> was called.
 * - AstStatus_NOT_SUSPENDED - SDK is not initialized
 * - AstStatus_INTERNAL_ERROR - resuming failed with an alert; as usual exit/init is necessary. See onReport for details.
 * - AstStatus_INVALID_STATE - suspend is still running, call is ignored. See onReport for details.
 */
- (AstStatus)resume;

/**
 * @brief As init with logging parameter.
 *
 * Same as init:version:appName:, but with additional log level. The logging is done via NSLog and only available in the debug-variant of the AstSdk library. Currently, only the log level Debug is used.
 *
 * @param[in] locale same as in init:version:appName:
 * @param[in] version same as in init:version:appName:
 * @param[in] appName same as in init:version:appName:
 * @param[in] logLevel log level
 */
- (AstStatus)init:(NSString*)locale version:(NSString*)version appName:(NSString*)appName logLevel:(AstLogLevel)logLevel;

/**
 * @brief Enable the Update feature of the AstSdk.
 *
 * This function registers a callback listener and returns an update object. If this function was not called, no
 * listener callbacks concerning the update will be invoked by the AstSdk.
 *
 * This function should be called after init and before any other usage (i.e., activation or login) of the AstSdk,
 * otherwise the behavior is undefined.
 *
 * @note You must not release the returned AstSdk interface.
 *
 * @param[in] listener
 *            implements the update relevant AstSdk callbacks.
 *
 * @return the AstSdk interface to control updates
 */
- (id<AstUpdate>)registerUpdate:(id<AstUpdateListener>)listener;

/**
 * @brief App Activation<br />
 *        This method is invoked by the App to start the activation process of the App.
 *
 * It is the response method of onActivationBegin.
 * 
 * The method is an asynchronous call. The return method is onActivationEnd.
 * 
 * @param[in] deviceType
 *            The AstDeviceType for this request.
 * @param[in] pin
 *            The new PIN entered by the user
 * @param[in] userId
 *            The user ID entered by the user
 * @param[in] activationCode
 *            The activation code entered by the user
 */
- (void)doActivation:(AstDeviceType)deviceType pin:(NSString*)pin userId:(NSString*)userId activationCode:(NSString*)activationCode;

/**
 * @brief App Login<br />
 *        This method must be invoked by the App to start the session. 
 *
 * It is the response method of onLoginBegin.
 * 
 * The method is an asynchronous call. The return method for this is onLoginEnd.
 * 
 * @param[in] deviceType
 *            The AstDeviceType for this request
 * @param[in] pin
 *            The PIN entered by user
 * @param[in] userId
 *            The userId that should be used for login (must be one of the available userIds returned by onLoginBegin)
 */
- (void)doLogin:(AstDeviceType)deviceType pin:(NSString*)pin userId:(NSString*)userId;

/**
 * @brief App Reactivation<br />
 *        This method must be invoked by the App to start the re-activation process. Applies only for virtua device.
 *
 * It must be used, if the user e.g. has forgotten his password and therefore now has to reactivate the App.
 * 
 * The method is an asynchronous call. The return method is onReActivationEnd.
 * 
 * @note The parameter userId is currently ignored. The implementation 
 *       will be available in upcoming SDKs.
 *
 * @param[in] pin
 *            The new PIN entered by the user
 * @param[in] userId
 *            The userId that should be used for reactivation
 * @param[in] activationCode
 *            The activation code, entered by the user
 */
- (void)doReactivation:(NSString*)pin userId:(NSString*)userId activationCode:(NSString*)activationCode;

 /**
 * @brief App PIN required<br />
 *        This method must be invoked by the App to start the PIN verification for a transaction.
 *
 * It is the response method of onPinRequiredBegin.
 * 
 * The method is an asynchronous call. The return method is onPinRequiredEnd.
 * 
 * @param[in] deviceType
 *            The AstDeviceType for this request.
 * @param[in] confirm
 *            The confirmation of the transaction<br />
 *            - OK: The transaction was confirmed positively
 *            - CANCEL: The transaction was cancelled, by pressing a "Cancel" button in a confirmation dialog
 * @param[in] pin
 *            The new PIN entered by the user
 */
- (void)doPinRequired:(AstDeviceType)deviceType confirm:(AstConfirmation)confirm pin:(NSString*)pin;

/**
 * @brief App PIN change request<br />
 *        This method must be invoked to start the process of changing the PIN of the App or a mIDentity device.<br />
 *        When this method is called the AST will request (the SSMS server) to change the PIN.
 *
 * The method is an asynchronous call. The return method is onPinChangeBegin.
 *
 * @pre The PIN can only be changed, if the App is logged in, see doLogin.
 * 
 * @param[in] deviceType
 *            The AstDeviceType of which the PIN should be changed. To change the PIN of the App, the device type AstDeviceType_VIRTUAL_DEVICE must be used.
 */
- (void)doPinChangeRequest:(AstDeviceType)deviceType;

/**
 * @brief App PIN change<br />
 *        This method must be invoked to change the PIN of the App or a mIDentity device.
 *
 * The method is an asynchronous call. The return method is onPinChangeEnd.
 *
 * @pre Before you can invoke this method the doPinChangeRequest must return with onPinChangeBegin and the status OK.
 *
 * @param[in] deviceType
 *            The AstDeviceType for this request
 * @param[in] confirm
 *            The confirmation type
 * @param[in] currentPin
 *            The current PIN of the device
 * @param[in] newPin
 *            The new PIN that should be set in the device
 */
- (void)doPinChange:(AstDeviceType)deviceType confirm:(AstConfirmation)confirm currentPin:(NSString*)currentPin newPin:(NSString*)newPin;

/**
 * @brief Transport PIN handling<br />
 *        This method must be invoked to initialize a smart card which is in transport-pin-state. Applies only for mIDentity devices.
 *
 * The method is an asynchronous call. The return method is onTransportPinEnd.
 *
 * @pre Before you can invoke this method onTransportPinBegin must have been called.
 *
 * @param[in] newPuk
 *            The new PUK that should be set (can be empty)
 * @param[in] newPin
 *            The new PIN that should be set
 */
- (void)doTransportPin:(NSString*)newPuk newPin:(NSString*)newPin;

/**
 * @brief Unblock PIN<br />
 *        App sets new PIN using the PUK. Applies only for mIDentity devices.
 *
 * The method is an asynchronous call. The return method is onPinUnblockEnd.
 *
 * @pre Before you can invoke this method onPinUnblockBegin must have been called.
 *
 * @param[in] puk
 *            The PUK that should be used to unblock the pin
 * @param[in] newPin
 *            The new PIN that should be set
 */
- (void)doPinUnblock:(NSString*)puk newPin:(NSString*)newPin;

/**
 * @brief App Transaction<br />
 *        This method must be invoked to confirm the transaction which was sent by the SSMS server.
 *
 * It is the response method of onTransactionBegin.
 *
 * The method is an asynchronous call. The return method is onTransactionEnd.
 *
 * @param[in] deviceType
 *            The AstDeviceType for this request
 * @param[in] confirm
 *            The AstConfirmation of the transaction<br />
 *            - OK: The transaction was confirmed positively.
 *            - CANCEL: The transaction was cancelled, by pressing a "Cancel" button in a confirmation dialog.
 *            - TIMEOUT:The transaction was cancelled because the timeout has elapsed.
 * @param[in] displayData
 *            The text that was shown in the Display Data dialog
 */
- (void)doTransaction:(AstDeviceType)deviceType confirm:(AstConfirmation)confirm displayData:(NSString*)displayData;

/**
 * @brief App set Property request<br />
 *        This method must be invoked to start the process of setting a Property.<br />
 *        When this method is called the AST will request (the SSMS server) to set a Property.
 *
 * The method is an asynchronous call. The return method is onSetPropertyBegin.
 *
 * @pre Setting a Property can only be requested, if the App is logged in, see doLogin.
 *
 * @param[in] deviceType
 *            The AstDeviceType for this request
 */
- (void)doSetPropertyRequest:(AstDeviceType)deviceType;

/**
 * @brief App set Property<br />
 *        This method must be invoked to set a Property.
 *
 * The method is an asynchronous call. The return method is onSetPropertyEnd. A property can be deleted on the SSMS by setting the property with empty data.
 *
 * @note Currently, if onSetPropertyEnd reports an error, this method must be called again, if this error did not come from the SSMS, but was generated by the AstSdk locally (i.e., length check for parameter).
 *
 * @pre Before you can invoke this method the doSetPropertyRequest must return with onSetPropertyBegin and the status OK.
 *
 * @param[in] deviceType
 *            AstDeviceType for this request
 * @param[in] propertyKey
 *            key/name of the property to be set
 * @param[in] propertyData
 *            data of the property to be set
 * @param[in] propertyType
 *            The Type of the Property.<br />
 *            Possible AstPropertyType values are:
 *            - PropertyType_OCTET_STRING
 *            - PropertyType_INTEGER
 *            - PropertyType_BOOLEAN
 *            - PropertyType_UTF8STRING
 *            - PropertyType_DATE
 * @param[in] propertyOwner
 *            The Owner of the Property.<br />
 *            Possible AstPropertyOwner values are:
 *            - AstPropertyOwner_DEVICE
 *            - AstPropertyOwner_USER
 *            - AstPropertyOwner_GROUP
 * @param[in] propertyTTL
 *            The time-to-live of the Property in seconds
 * @param[in] propertyFlags
 *            Property Flags.<br />
 *            Possible AstPropertyFlags values are:
 *            - AstPropertyFlags_NON_PERSISTANCE
 *            - AstPropertyFlags_VALUE_ENCRYPTED
 *            - AstPropertyFlags_CONFIDENTIAL
 *            - AstPropertyFlags_UNIQUE_TO_USER
 *            - AstPropertyFlags_IMMEDIATE
 */
- (void)doSetProperty:(AstDeviceType)deviceType propertyKey:(NSString*)propertyKey propertyData:(NSData*)propertyData propertyType:(AstPropertyType)propertyType propertyOwner:(AstPropertyOwner)propertyOwner propertyTTL:(uint32_t)propertyTTL propertyFlags:(uint32_t)propertyFlags;

/**
 * @brief App get Property request<br />
 *        This method must be invoked to start the process of getting a Property.<br />
 *        When this method is called the AST will request (the SSMS server) to get a Property.
 *
 * The method is an asynchronous call. The return method is onGetPropertyBegin.
 *
 * @pre Getting a Property can only be requested, if the App is logged in, see doLogin.
 *
 * @param[in] deviceType
 *            The AstDeviceType for this request.
 */
- (void)doGetPropertyRequest:(AstDeviceType)deviceType;

/**
 * @brief App get Property<br />
 *        This method must be invoked to get a Property.
 *
 * The method is an asynchronous call. The return method is onGetPropertyEnd.
 *
 * @note Currently, if onSetPropertyEnd reports an error, this method must be called again, if this error did not come from the SSMS, but was generated by the AstSdk locally (i.e., length check for parameter).
 *
 * @pre Before you can invoke this method the doGetPropertyRequest must return with onGetPropertyBegin and the status OK.
 *
 * @param[in] deviceType
 *            The AstDeviceType for this request.
 * @param[in] propertyName
 *            The name of the requested Property 
 * @param[in] propertyOwner
 *            The Owner of the Property.<br />
 *            Possible AstPropertyOwner values are:
 *            - AstPropertyOwner_DEVICE
 *            - AstPropertyOwner_USER
 *            - AstPropertyOwner_GROUP
 */
- (void)doGetProperty:(AstDeviceType)deviceType propertyName:(NSString*)propertyName propertyOwner:(AstPropertyOwner)propertyOwner;

/**
 * @brief Delete user credentials for the corresponding userId.
 *
 * Can be called upon onLoginBegin or upon onDeactivateEnd. If parameter userId is a valid userId, the corresponding
 * credentials will be deleted. If parameter userId is nil all user credentials will be deleted.
 *
 * The AstSdk responds with onDeactiveEnd.
 *
 * @note The user credentials won't be recoverable.
 *
 * @param[in] userId userId to be deleted or nil
 */
- (void)doDeactivate:(NSString*)userId;

/**
 * @brief Hardens the UIWebView object.
 *
 * @note After hardening a webView, its delegate property may not be changed, not even to nil before releasing it (the AstSdk ensures
 * that this does not result in memory access problems).
 *
 * @warning Using UIWebView without the harden call will result in unsafe WebView.
 *
 * @param[in] webView
 *		      UIWebView object to be hardened
 */
- (void)hardenWebView:(id)webView;

/**
 * @brief sets listener object for a hardened webView
 *
 * @note The method does not check, whether the provided webview is hardened.
 *
 * @bug The detect which webview is concerned is not implemented yet, thus, the first set listener is used every time.
 *
 * @param[in] webView
 *		      hardened UIWebView object for which the listener shall be set
 * @param[in] listener
 *		      listener object to be set
 * @return pointer to listener object previous stored for this webview or nil
 */
- (id<AstSecureWebViewListener>)secureWebViewAddListener:(id)webView listener:(id<AstSecureWebViewListener>)listener;

/**
 * @brief En-/disables cookie sharing between the different AstChannel instances and the WebView client.
 * 
 * If false, all instances use their own set of cookies. Does not affect the cookies of currently
 * running transfers.
 *
 * Each call will clear the current cookie store. By default, cookie sharing is enabled.
 *
 * @param enable true to enable cookie sharing
 */
- (void)enableCookieSharing:(BOOL)enable;

/**
 * @brief Ends AstSDK
 *
 * The session will be automatically logged off and any connection to the SSMS server will be disconnected. AstSDK cleans its internal data.
 * 
 * @param[in] errorCode
 *            An optional error code of the App can be given, which might be written to AST (or SSMS) log files - if possible.
 *
 * @return Error Code: 0x00, if successful - any other value is an error.
 *
 * @note To restart a session, begin with init.
 */
- (int)exit:(int)errorCode;

/**
 * @brief Get application config data from AstSDK
 *
 * Returns the application config parameter data, which is stored and secured by the AstSDK.
 *
 * @return application config data
 */
- (NSString*)getAppConfigParameterData;

/**
 * @brief AstChannel instance for current thread
 *
 * Returns a valid AstChannel instance. May be called at any time between init and exit, will
 * return nil otherwise. See AstChannel for details. Each AstChannel must only be
 * created and used from the same thread throughout its lifetime.
 *
 * @return the AstChannel instance valid for the calling thread
 */
- (id<AstChannel>)getAstChannel;

/**
 * @brief Searches for mIDentity devices connected to the system.
 *
 * This method searches for mIDentity devices connected to the system. It is an asychronous call, as the result is returned
 * in onDetectHardwareDevicesEnd. It may not be used if the certificatePolicy is "software".
 * 
 * The call starts a one time search for devices, i.e., only devices currently connected to the system via
 * Bluetooth are returned. Use of multiple devices is supported, i.e. all found devices are reported in onDetectHardwareDevicesEnd.
 * When this method may be called is dependent on the certificatePolicy. For "hardware", it may be called any time the method
 * may called any time after init and for "both" it may called after the virtual device is logged in.
 */
- (void)doDetectHardwareDevices;

/**
 * @brief Connects a mIDentity device to the App
 *
 * The method connects a mIDentity device connected to the system (see onDetectHardwareDevicesEnd) with the App. This starts the
 * activation or login path for the selected device. The name of the device provided as parameter must be one of the strings
 * returned by onDetectHardwareDevicesEnd (e.g. if onDetectHardwareDevicesEnd returned ["mIDentity NW12345678901", "mIDentity NW98765432109"],
 * doConnectHardwareDevice("mIDentity NW98765432109") will establish connection with "mIDentity NW98765432109"). The call is
 * asynchronous, i.e. its result is returned in onConnectHardwareDeviceEnd.
 *
 * May be called after onDetectHardwareDevicesEnd returned with a list of connected devices.
 *
 * @param[in] device
 *            name of the mIDentity device to be connected to the App
 */
- (void)doConnectHardwareDevice:(NSString*)device;

/**
 * @brief Diconnects a mIDentity device to the App
 *
 * The method disconnects the currently connected mIDentity device from the App (i.e., it stays connected to the system. The call is asynchronous, i.e.
 * its result is returned in onDisconnectHardwareDeviceEnd. The method may be called at any time after a successful connection to the App. Any still running
 * processes in the AstSdk (transaction, displayMessage) are silently cancelled, i.e. it is not reported to SSMS and no onXxx-methods for these still
 * running processes are called. The only reponse is onDisconncetHardwareDeviceEnd (and later onDeviceConnection).
 *
 * After the successful disconnection (i.e. onDisconnectHardwareDeviceEnd) was called, the AstSdk is in the following state:
 * - certificate policy "hardware" 
 *   same state as after call to init and before call to doDetectHardwareDevices
 * - certificate policy "both" 
 *   same as with certififcate policy "hardware", but virtualDevice is still logged in
 */
- (void)doDisconnectHardwareDevice;

@end
