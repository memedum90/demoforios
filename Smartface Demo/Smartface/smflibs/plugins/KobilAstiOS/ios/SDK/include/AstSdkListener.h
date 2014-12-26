#import <Foundation/Foundation.h>

#import "AstSdkTypes.h"

/**
 * @brief interface of the Kobil Application Security Technology SDK
 *
 * @note Pay attention to return as soon as possible because these methods are synchron calls from the SDK.
 */
@protocol AstSdkListener

/**
 * @brief App-Activation<br />
 *        This method will be invoked after init, if the App is not activated yet (for certificate policy "software" and "both").
 * 
 * @post The App should display a dialog where the user can enter the data of the activation process and reply with doActivation.
 * 
 * @param[in] deviceType
 *            the AstDeviceType for which the activation process will be started
 *
 * @see onActivationEnd
 */
- (void)onActivationBegin:(AstDeviceType)deviceType;

/**
 * @brief App-Activation<br />
 *        This is the response of doActivation.
 * 
 *        If UPDATE_NECESSARY or UPDATE_AVAILABLE occur and the update procedure is enabled by having called registerUpdate,
 *        a callback onUpdateInformation will occur next.
 *
 *        For OK and UPDATE_AVAILABLE the callback onLoginBegin will be automatically called next.
 *
 *        Status may also be INVALID_USER_ID (if the given userId cannot be found or cannot be loaded) or
 *        USER_ID_ALREADY_EXISTS (if the given userId has already been activated).
 *
 * @param[in] deviceType
 *            The AstDeviceType for which the activation has been finished.
 * @param[in] status
 *            The AstStatus of the activation process. If status is OK the activation was done successfully.<br />
 *            Possible AstStatus values are:
 *            - AstStatus_OK
 *            - AstStatus_WRONG_CREDENTIALS
 *            - AstStatus_ACTIVATION_CODE_EXPIRED
 *            - AstStatus_LOCKED_USER
 *            - AstStatus_APP_REGISTERED
 *            - AstStatus_UPDATE_NECESSARY
 *            - AstStatus_UPDATE_AVAILABLE
 *            - AstStatus_UNKNOWN_VERSION
 *            - AstStatus_UNKNOWN_CLIENT_TYPE
 *            - AstStatus_INVALID_ACTIVATION_CODE
 *            - AstStatus_INVALID_USER_ID
 *            - AstStatus_USER_ID_ALREADY_EXISTS
 *            - AstStatus_INTERNAL_ERROR
 *            - AstStatus_INVALID_STATE
 *            - AstStatus_INVALID_PARAMETER
 *
 * @see onActivationBegin
 * @see onLoginBegin
 */
- (void)onActivationEnd:(AstDeviceType)deviceType status:(AstStatus)status;

/**
 * @brief App-Login<br />
 *        This method will be invoked after init, if the App was once successfully activated.
 * 
 * @post The App should display a dialog where the user can enter his PIN and reply with doLogin.
 * 
 * @note For hardware devices the parameter userIdList is always empty and can be ignored.
 *
 * @param[in] deviceType
 *            The AstDeviceType for which the login process will be started.
 * @param[in] userIdList 
 *            contains the list of userIds (NSArray of NSString)
 *
 * @see onLoginEnd
 */
- (void)onLoginBegin:(AstDeviceType)deviceType userIdList:(NSArray*)userIdList;

/**
 * @brief App-Login<br />
 *        After the SSMS session has been successfully established, this method will be invoked. The App can now continue,
 *        e.g. by opening the "WebView" to the bank portal.
 * 
 * This is the response of doLogin.
 * 
 * If UPDATE_NECESSARY or UPDATE_AVAILABLE occur and the update procedure is enabled by having called registerUpdate,
 * a callback onUpdateInformation will occur next.
 *
 * Status may also be INVALID_USER_ID if the given userId cannot be found or cannot be loaded.
 *
 * @param[in] deviceType
 *            The AstDeviceType for which the login has been finished.
 * @param[in] status
 *            The AstStatus of the activation process. If status is OK the activation was done successfully and the
 *            parameters loginOtp and userId are not null.<br />
 *            Possible AstStatus values are:
 *            - AstStatus_OK
 *            - AstStatus_ACTIVATE_CERTIFICATE
 *            - AstStatus_WRONG_CREDENTIALS
 *            - AstStatus_LOCKED_USER
 *            - AstStatus_UPDATE_NECESSARY
 *            - AstStatus_UPDATE_AVAILABLE
 *            - AstStatus_UNKNOWN_VERSION
 *            - AstStatus_UNKNOWN_CLIENT_TYPE
 *            - AstStatus_UNKNOWN_CERTIFICATE
 *            - AstStatus_LOCKED_CERTTIFICATE
 *            - AstStatus_INVALID_USER_ID
 *            - AstStatus_INTERNAL_ERROR
 *            - AstStatus_INVALID_STATE
 *            - AstStatus_INVALID_PARAMETER
 *            - AstStatus_INVALID_PIN
 *            - AstStatus_TEMPORARY_LOCKED
 *
 * @param[in] loginOtp
 *            On successful login, this parameter can be used by the App to do an auto-logon to the bank's web portal.
 * @param[in] userId
 *            The user ID for which the logon process was done successfully. For support purposes, this user ID
 *            should be displayed e.g. in an "About Box".
 * @param[in] retryCounter
 *            In the case that the login failed, this parameters contains the amount of retries that a user can enter a wrong PIN.
 * @param[in] retryDelay
 *            In the case that the login failed, this parameters contains the amount of seconds that a user
 *            should wait before retrying to enter a PIN (in the meantime login tries will result into AstStatus_TEMPORARY_LOCKED).
 *
 * @see onLoginBegin
 */
- (void)onLoginEnd:(AstDeviceType)deviceType status:(AstStatus)status loginOtp:(NSString*)loginOtp userId:(NSString*)userId retryCounter:(int)retryCounter retryDelay:(int)retryDelay;

/**
 * @brief App-Reactivation
 *        This is the response of doReactivation.
 * 
 * If UPDATE_NECESSARY or UPDATE_AVAILABLE occur and the update procedure is enabled by having called registerUpdate,
 * a callback onUpdateInformation will occur next.
 *
 * Status may also be INVALID_USER_ID if the given userId cannot be found or cannot be loaded.
 *
 * @param[in] status
 *            The AstStatus of the re-activation process. If status is OK the re-activation was done successfully.<br />
 *            Possible AstStatus values are:
 *            - AstStatus_OK
 *            - AstStatus_WRONG_CREDENTIALS
 *            - AstStatus_TEMPORARY_LOCKED
 *            - AstStatus_ACTIVATION_CODE_EXPIRED
 *            - AstStatus_LOCKED_USER
 *            - AstStatus_APP_REGISTERED
 *            - AstStatus_UPDATE_NECESSARY
 *            - AstStatus_UPDATE_AVAILABLE
 *            - AstStatus_UNKNOWN_VERSION
 *            - AstStatus_UNKNOWN_CLIENT_TYPE
 *            - AstStatus_UNKNOWN_CERTIFICATE
 *            - AstStatus_LOCKED_CERTTIFICATE
 *            - AstStatus_INVALID_USER_ID
 *            - AstStatus_INTERNAL_ERROR
 *            - AstStatus_INVALID_DEVICE
 *            - AstStatus_INVALID_STATE
 *            - AstStatus_INVALID_PARAMETER
 */
- (void)onReActivationEnd:(AstStatus)status;

/**
 * @brief App-PIN Change Begin<br />
 *        This is the response of doPinChangeRequest.
 *
 * @post If the status is OK the App can continue to invoke doPinChange.
 * 
 * @param[in] deviceType
 *            The AstDeviceType for this request.
 * @param[in] status
 *            The AstStatus of the "PIN change" process.<br />
 *            Possible AstStatus values are:
 *            - AstStatus_OK
 *            - AstStatus_INVALID_STATE
 *
 * @see onPinChangeEnd
 */
- (void)onPinChangeBegin:(AstDeviceType)deviceType status:(AstStatus)status;

/**
 * @brief App-PIN Change End<br />
 *        This is the response of doPinChange.
 * 
 * @param[in] deviceType
 *            The AstDeviceType for this request.
 * @param[in] status
 *            The AstStatus of the "PIN change" process. If status is OK the PIN was changed successfully.<br />
 *            Possible AstStatus values are:
 *            - AstStatus_OK
 *            - AstStatus_USER_CANCEL
 *            - AstStatus_INVALID_PIN
 *            - AstStatus_INVALID_NEW_PIN_FORMAT
 *            - AstStatus_INTERNAL_ERROR
 *            - AstStatus_INVALID_STATE
 *            - AstStatus_INVALID_PARAMETER
 * @param[in] retryCounter
 *            The amount of retries the user has still left (if status is not OK).
 *
 * @see onPinChangeBegin
 */
- (void)onPinChangeEnd:(AstDeviceType)deviceType status:(AstStatus)status retryCounter:(int)retryCounter;

/**
 * @brief App-server connected<br />
 * The App is notified about different connection states of the SSMS server and the KOBIL Browser
 * The App can show can according message, e.g. "Connection established".<br />
 * This method can be invoked during the "App Login".
 * 
 * @param[in] deviceType
 *            The AstDeviceType for this information.
 * @param[in] connectionState server connection status:
 *			- AstConnectionState_CONNECTED:       The SSMS is now connected.
 *			- AstConnectionState_CONNECTING:      The SSMS is now in the connection process.
 *			- AstConnectionState_DISCONNECTED:    The SSMS is disconnected
 *			- AstConnectionState_DISCONNECTING:   The SSMS is in the disconnecting process.
 *			- AstConnectionState_CONNECTION_LOST: The SSMS connection was lost.
 *			- AstConnectionState_RECONNECTED:     The SSMS connection was reconnected after AstConnectionState_CONNECTION_LOST.
 *
 * @see onLoginBegin
 */
- (void)onServerConnection:(AstDeviceType)deviceType connectionState:(AstConnectionState)connectionState;

/**
 * @brief App-device connected<br />
 *        In the case that a hardware device is used, the App is notified, that the device is connected or disconnected.
 * 
 * The App can show an according notification to the user.
 * 
 * @param[in] deviceType
 *            The AstDeviceType for this information.
 * @param[in] connectionState device connection status:
 *            AstConnectionState_CONNECTED:       The device is now connected.
 *            AstConnectionState_CONNECTING:      The device is now in the connection process.
 *            AstConnectionState_CONNECTION_LOST: The device connection was lost.
 *            AstConnectionState_DISCONNECTED:    The device is disconnected
 *            AstConnectionState_DISCONNECTING:   The device is in the disconnecting process.
 *            AstConnectionState_RECONNECTED:     The device connection was reconnected after AstConnectionState_CONNECTION_LOST.
 */
- (void)onDeviceConnection:(AstDeviceType)deviceType connectionState:(AstConnectionState)connectionState;

/**
 * Start a transaction sequence.
 *
 * During a transaction the app must not call other AstSdk functionality except <code>exit</code>.
 * The actual steps of a transaction are marked by another callback.
 *
 * This is an asynchronous call. It is either followed by {@link AstSdkListener::onPinRequiredBegin:pinReason:} or by
 * {@link AstSdkListener::onTransactionBegin:displayData:confirmationType:}, depending on the chose transaction type.
 *
 * @param deviceType
 *            The AstDeviceType for which a new transaction starts.
 * @param timeout
 *            A timeout value (in seconds). After this timeout, a user dialog should
 *            automatically close and the transaction should be cancelled with
 *            {@link AstConfirmation_TIMEOUT}.
 */
-(void)onTransactionBlockBegin:(AstDeviceType)deviceType timeout:(uint32_t)timeout;

/**
 * End a transaction sequence.
 *
 * After receiving this callback the app may again call other AstSdk functions like
 * doPinChangeRequest}
 *
 * @param deviceType
 *            The AstDeviceType for which the transaction is finished.
 */
-(void)onTransactionBlockEnd:(AstDeviceType)deviceType;

/**
 * @brief App-Transaction Begin<br />
 *        The method is invoked when SSMS sends a transaction to the virtual device or to a mIDentitiy without display.
 * 
 * @post The App should open a dialog containing the display data and then reply with the confirmation by the method doTransaction.
 * 
 * @param[in] deviceType
 *            The AstDeviceType for which the activation process will be started.
 * @param[in] displayData
 *            The data that should be shown to the user.
 * @param[in] confirmationType
 *            The AstConfirmationType of the transaction
 *            - AstConfirmationType_NO_CONFIRMATION: No confirmation is required by the App. The confirmation
 *              of the transaction is done completely in the mIDentity device.
 *            - AstConfirmationType_CONFIRMATION_REQUIRED: The confirmation of the transaction must be done by
 *              the App, because either no mIDentity device is used or the device has no display.
 *            - AstConfirmationType_SPLIT_CONFIRMATION: To confirm the the transaction, the user must press
 *              the OK button in the mIDentity device, but since the device has only an OK, but no "Cancel" button,
 *              the App must show a according dialog where the user can cancel the transaction.<br />
 *              The confirmation is "split" between the hardware (positive confirm) and the App (cancel).
 *
 * @see onTransactionEnd
 */
- (void)onTransactionBegin:(AstDeviceType)deviceType displayData:(NSString*)displayData confirmationType:(AstConfirmationType)confirmationType;

/**
 * @brief App-Transaction End<br />
 *        This is the response of doTransaction.
 * 
 * @param[in] deviceType
 *            The AstDeviceType for this request.
 * @param[in] status
 *            The AstStatus of the transaction process. If status is OK the transaction was confirmed with OK and successfully 
 *            sent to the SSMS.<br />
 *            Possible AstStatus values are:
 *            - AstStatus_OK
 *            - AstStatus_USER_CANCEL
 *            - AstStatus_USER_CONFIRMATION_TIMEOUT
 *            - AstStatus_INVALID_STATE
 *            - AstStatus_INVALID_PARAMETER
 *
 * @note This does not mean, that the transaction was completed on the bank's server. The user must watch
 *       any error messages, e.g. on the App's WebView.
 *
 * @see onTransactionBegin
 */
- (void)onTransactionEnd:(AstDeviceType)deviceType status:(AstStatus)status;

/**
 * @brief App display message<br />
 *        This method is invoked if the SSMS sends a message to the App, e.g. some informational text of the server's administrator.
 *
 * There is no response to this method.
 *
 * @post The App should open a dialog and display the message.
 * 
 * @param[in] deviceType
 *            The AstDeviceType for this information
 * @param[in] displayData
 *            The data that should be displayed to the user
 * @param[in] messageType
 *            The AstMessageType of the dialog that should be shown to the user
 */
- (void)onDisplayMessage:(AstDeviceType)deviceType displayData:(NSString*)displayData messageType:(AstMessageType)messageType;

/**
 * @brief App-Hardware Transaction<br />
 *        This method is invoked, if a transaction is started with a mIDentity device with display.
 *
 * @post The App can notify the user, to confirm the transaction on with the mIDentity hardware, e.g.:
 *       "Please confirm transaction on your device".
 *
 * @see onInfoHardwareTransactionEnd
 */
- (void)onInfoHardwareTransactionBegin;

/**
 * @brief App-Hardware Transaction
 *
 * If onInfoHardwareTransactionBegin was invoked, this method will inform the App, that the transaction is finished.
 *
 * @see onInfoHardwareTransactionBegin
 */
- (void)onInfoHardwareTransactionEnd;

/**
 * @brief App-PIN required<br />
 *        This method is invoked when SSMS sends a transaction which requires the user to enter the PIN.
 *
 * @post The App should open a dialog to request the PIN of the user and send it to the AST with the method doPinRequired.
 * 
 * @param[in] deviceType
 *            The AstDeviceType for which the PIN will be requested
 * @param[in] pinReason
 *            reason why entering the PIN was requested
 *
 * @see onPinRequiredEnd
 */
- (void)onPinRequiredBegin:(AstDeviceType)deviceType pinReason:(AstPinReason)pinReason;

/**
 * @brief App-PIN required<br />
 *        This is the response of doPinRequired.
 * 
 * @param[in] deviceType
 *            The AstDeviceType for this request.
 * @param[in] status
 *            The AstStatus of "PIN required" process. If status is OK the PIN was entered successfully.<br />
 *            Possible AstStatus values are:
 *            - AstStatus_OK
 *            - AstStatus_INVALID_PIN
 *            - AstStatus_USER_CANCEL
 *            - AstStatus_USER_CONFIRMATION_TIMEOUT
 *            - AstStatus_INVALID_STATE
 *            - AstStatus_INVALID_PARAMETER
 * @param[in] retryCounter
 *            The amount of retries, the user can enter a wrong pin before the App/device will be blocked.    
 *            
 * @see onPinRequiredBegin
 */
- (void)onPinRequiredEnd:(AstDeviceType)deviceType status:(AstStatus)status retryCounter:(int)retryCounter;

/**
 * @brief Transport-PIN required<br />
 *        When using mIDentity devices the AstSdk checks the pin at startup.
 * 
 * @param[in] checkPinReason
 *            The AstPinReason why entering the Transport-PIN was requested.
 *            
 * @see onTransportPinEnd
 */
- (void)onTransportPinBegin:(AstCheckPinReason)checkPinReason;

/**
 * @brief Transport-PIN required<br />
 *        This command is called after the App calls doTransportPin.
 * 
 * @param[in] status
 *            The AstStatus of "Transport-PIN required" process. If status is OK the PIN was entered successfully.<br />
 *            Possible AstStatus values are:
 *            - AstStatus_OK
 *            - AstStatus_INVALID_STATE
 *            - AstStatus_INVALID_PARAMETER
 *            
 * @note 
 *         If an error occurs onAlert will be called.
 *
 * @see onTransportPinBegin
 */
- (void)onTransportPinEnd:(AstStatus)status;

/**
 * @brief Unblocking-PIN required<br />
 *        Set PIN using PUK. Applies only for mIDentity devices
 * 
 * @see onPinUnblockEnd
 */
- (void)onPinUnblockBegin;

/**
 * @brief Transport-PIN required<br />
 *        This command is called after the App calls doPinUnblock.
 * 
 * @param[in] status
 *            The AstStatus of "Unblock-PIN required" process. If status is OK the PIN was unblocked successfully.<br />
 *            Possible AstStatus values are:
 *            - AstStatus_OK
 *            - AstStatus_USER_CANCEL
 *            - AstStatus_INVALID_PIN
 *            - AstStatus_INVALID_NEW_PIN_FORMAT
 *            - AstStatus_INTERNAL_ERROR
 *            - AstStatus_INVALID_DEVICE
 *            - AstStatus_INVALID_STATE
 *            - AstStatus_INVALID_PARAMETER
 * @param[in] retryCounter
 *            The amount of retries the user has still left (if status is not OK).
 *            
 * @note 
 *         If an error occurs onAlert will be called.
 *
 * @see onPinUnblockBegin
 */
- (void)onPinUnblockEnd:(AstStatus)status retryCounter:(int)retryCounter;

/**
 * @brief App-Alert
 *
 * An error occurred in the AST.<br />
 * Whenever this method is invoked, the session is automatically logged out and connection to the SSMS server is disconnected.
 *
 * If the certificate policy is both and the alert was caused by the device type AstDeviceType_MIDENTITY it is sufficient
 * to just restart the hardware part by calling doDisconnectHardwareDevice followed by doDetectHardwareDevices.
 * 
 * @param[in] deviceType
 *            The AstDeviceType for this information.
 * @param[in] subSystem
 *            The "internal sub system" of the App Security Tool, that reported the error. This information is only
 *            for support purposes.
 * @param[in] errorCode
 *            An error number which is documented in the AST.
 *
 * @note To restart the session begin with init
 */
- (void)onAlert:(AstDeviceType)deviceType subSystem:(uint32_t)subSystem errorCode:(uint32_t)errorCode;

/**
 * @brief App-URL blocked
 *
 * The URL is blocked by the whitelist or the SSL whitelist.
 * 
 * @param[in] url
 *            URL that is blocked
 * @param[in] urlBlockedReason
 *            reason why the URL is blocked
 */
- (void)onUrlBlocked:(NSString*)url urlBlockedReason:(UrlBlockedReason)urlBlockedReason;

/**
 * @brief X509 Certificate
 *
 * As soon as the AstSdk has read the public certificate of the mIDentity device, this method will be invoked sending the
 * device type and the certificate as byte array.
 * 
 * @param[in] deviceType
 *            The AstDeviceType where the certificate is retrieved from
 * @param[in] certificate
 *            The public certificate bytes in X509 format
 */
- (void)onCertificateDataAvailable:(AstDeviceType)deviceType certificate:(NSData*)certificate;

/**
 * @brief Request proxy parameters
 *
 * Application has to provide proxy parameters as dictionary. Allowed keys are AstProxyParameter_HOST, AstProxyParameter_PORT,
 * AstProxyParameter_USERNAME and AstProxyParameter_PASSWORD. Return empty dictionary or nil, if no parameters are needed.
 *
 * Example: [NSDictionary dictionaryWithObjectsAndKeys: AstProxyParameter_HOST, @"my.proxy.com", AstProxyParameter_PORT, @"8080", nil]
 * 			
 * @return dictionary with proxy parameters (may be empty)
 */
- (NSDictionary*)getProxyParameter;

/**
 * @brief Request general application parameter
 *
 * Application has to provide general application parameter. The parameters have to be returned as NSArray of NSString. In most cases only
 * a single string is needed. Then the string is expected in the first array element.
 * The application has to use lower cases for the parameter values. An upper and lower case mismatch results in an onAlert call.
 *
 * Meaning of possible parameter types:
 * - AstConfigParameter_WHITELIST array of allowed URLs as regular expression (e.g. @"http://www.google.com/.*" to allow all URLs at www.google.com)
 * - AstConfigParameter_CONFIG_BUNDLE (sub) path where to find the selected config bundle (needed for multi-asset mode); return empty array if not needed
 * - AstConfigParameter_USER_CREDENTIALS_PATH path where the user credentials shall be stored (local storage of the App; e.g. content of environment variable "HOME")
 * - AstConfigParameter_CERTIFICATE_POLICY whether software-only, hardware-only oder software and hardware-modus shall be used; possible values: "software", "hardware", "both"
 * - AstConfigParameter_SERVER_BUSY_TIMEOUT if the SSMS does not respond to a request within this time, the AstSdk informs the App about it and retires to connect the SSMS.
 * - AstConfigParameter_CONNECTION_RETRY_COUNTER how often a connection retry to SSMS shall be tried
 * - AstConfigParameter_CONNECTION_RETRY_INTERVAL time in seconds after a connection retry until a new retry is started
 * - AstConfigParameter_USE_DEVICE_NAME_SOFTWARE "true" or "false" depending whether device name shall be used
 * - AstConfigParameter_USE_DEVICE_NAME_HARDWARE "true" or "false" depending whether device name shall be used
 * - AstConfigParameter_WEB_VIEW_BASIC_AUTH username and password for basic HTTP authentication of the hardened WebView
 * - AstConfigParameter_SUPPORTED_HOST_DEVICE list of iPad/iPhone devices the App is allowed to run on; treated as regular expression; delimeter is ';' 
 *
 * You can call getAppConfigParameterData to get the app_config.xml.
 * @note Don't call getAppConfigParameterData before the first call of getAppConfigParameter. The returned data may be empty.
 *
 * @param[in] type type of parameter
 * @return value(s) for parameter to be filled from application
 */
- (NSArray*)getAppConfigParameter:(AstConfigParameter)type;

/**
 * @brief Set Property Begin<br />
 *        This is the response of doSetPropertyRequest.
 *
 * @post If the status is OK the App can continue to invoke doSetProperty.
 * 
 * @param[in] deviceType
 *            The AstDeviceType for this request.
 * @param[in] status
 *            The AstStatus of the "Set Property" process.<br />
 *            Possible AstStatus values are:
 *            - AstStatus_OK
 *            - AstStatus_INVALID_STATE
 *
 * @see onSetPropertyEnd
 */
- (void)onSetPropertyBegin:(AstDeviceType)deviceType status:(AstStatus)status;

/**
 * @brief Set Property End<br />
 *        This is the response of doSetProperty.
 * 
 * @param[in] deviceType
 *            The AstDeviceType for this request.
 * @param[in] status
 *            The AstStatus of the "Set Property" process. If status is OK the Property was set successfully.<br />
 *            Possible AstStatus values are:
 *            - AstStatus_OK
 *            - AstStatus_TEXT_TOO_LONG   
 *            - AstStatus_INVALID_KEY_LENGTH
 *            - AstStatus_PROPERTY_NOT_EXISTS 
 *            - AstStatus_NOT_UNIQUE
 *            - AstStatus_NEGATIVE_STATUS
 *            - AstStatus_READ_ONLY
 *            - AstStatus_INVALID_STATE
 *            - AstStatus_INVALID_PARAMETER
 * @param[in] subSystem
 *            Only valid for AstStatus_NEGATIVE_STATUS
 * @param[in] errorCode
 *            Only valid for AstStatus_NEGATIVE_STATUS
 *
 * @see onSetPropertyBegin
 */
- (void)onSetPropertyEnd:(AstDeviceType)deviceType status:(AstStatus)status subSystem:(uint32_t)subSystem errorCode:(uint32_t)errorCode;

/**
 * @brief Get Property Begin<br />
 *        This is the response of doGetPropertyRequest.
 *
 * @post If the status is OK the App can continue to invoke doGetProperty.
 * 
 * @param[in] deviceType
 *            The AstDeviceType for this request.
 * @param[in] status
 *            The AstStatus of the "Get Property" process.<br />
 *            Possible AstStatus values are:
 *            - AstStatus_OK
 *            - AstStatus_INVALID_STATE
 *
 * @see onGetPropertyEnd
 */
- (void)onGetPropertyBegin:(AstDeviceType)deviceType status:(AstStatus)status;

/**
 * @brief Get Property End<br />
 *        This is the response of doGetProperty.
 * 
 * @param[in] deviceType
 *            The AstDeviceType for this request.
 * @param[in] status
 *            The AstStatus of the "Get Property" process. If status is OK the Property was obtained successfully.<br />
 *            Possible AstStatus values are:
 *            - AstStatus_OK
 *            - AstStatus_TEXT_TOO_LONG   
 *            - AstStatus_INVALID_KEY_LENGTH
 *            - AstStatus_NOT_UNIQUE 
 *            - AstStatus_INVALID_STATE 
 *            - AstStatus_INVALID_PARAMETER 
 * @param[in] propertyData
 *            The raw Data of the obtained Property.
 * @param[in] propertyType
 *            The Type of the Property.<br />
 *            Possible AstPropertyType values are:
 *            - PropertyType_OCTET_STRING
 *            - PropertyType_INTEGER
 *            - PropertyType_BOOLEAN
 *            - PropertyType_UTF8STRING
 *            - PropertyType_DATE
 * @param[in] propertyTTL
 *            The time-to-live of the Property.
 * @param[in] propertyFlags
 *            Property Flags.<br />
 *            Possible AstPropertyFlags values are:
 *            - AstPropertyFlags_NON_PERSISTANCE
 *            - AstPropertyFlags_VALUE_ENCRYPTED
 *            - AstPropertyFlags_CONFIDENTIAL
 *            - AstPropertyFlags_UNIQUE_TO_USER
 *            - AstPropertyFlags_IMMEDIATE
 *
 * @see onGetPropertyBegin
 */
- (void)onGetPropertyEnd:(AstDeviceType)deviceType status:(AstStatus)status propertyData:(id)propertyData propertyType:(AstPropertyType)propertyType propertyTTL:(uint32_t)propertyTTL propertyFlags:(uint32_t) propertyFlags;

/**
 * Will be called upon a successful call of doDeactivate.
 * The parameter userIdList will be valid even for an error status.
 *
 * @param[in] status
 *            - AstStatus_OK: successfully selected userId
 *            - AstStatus_INVALID_STATE
 *            - AstStatus_INVALID_USER_ID: given userId cannot be found
 * @param[in] userIdList contains the updated list of userIds
 */
- (void)onDeactivateEnd:(AstStatus)status userIdList:(NSArray*)userIdList;

/**
 * @brief make several information available for App
 *
 * This method makes the following information available to the App:
 * - local DeviceName: locally cached copy of the DeviceName (may be empty, if not yet set); will only be called, if DeviceName shall be used (see getAppConfigParameter)
 * - device serial number: serial number of the used mIDentity device (only if mIDentity is used)
 * - server supports properties: boolean value indicating wether SSMS supports device properties
 * - device hardware version: hardware version of the mIDentity device (only if mIDentity is used)
 * - unsupported host device: AstSdk is not allowed to run on current device; there will be no further call to teh listener (e.g. onLoginBegin or onActivationBegin); list of allowed devices may be set in getAppConfigParameter
 *
 * @param[in] context
 *            Gives contexts information about the given property. <br />
 * @param[in] informationKey
 *            information name.<br />
 *            Possible AstInformationKey values are:
 *            - AstInformationKey_LOCAL_KS_DEVICE_NAME (informationValue has class NSString)
 *            - AstInformationKey_DEVICE_SERIAL_NUMBER (informationValue has class NSString)
 *            - AstInformationKey_SERVER_SUPPORTS_PROPERTIES (informationValue has class NSNumber containing an boolean)
 *            - AstInformationKey_DEVICE_HARDWARE_VERSION (informationValue has class NSData)
 *            - AstInformationKey_UNSUPPORTED_HOST_DEVICE (informationValue is nil)
 * @param[in] informationValue
 *            the value of the information
 */
- (void)onInformationAvailable:(AstContextType)context informationKey:(AstInformationKey)informationKey informationValue:(id)informationValue;

/**
 * @brief Provides list of mIDentity devices conncted to the system.
 *
 * This method is called as answer to doDetectHardwareDevices. It provides a list of names of mIDentity devices conncted to the system.
 *
 * This method is called as answer to doDetectHardwareDevices. The returned list may be empty, if no mIDentity devices are currently
 *          connected to the system. The devices name in the list are the Bluetooth names (not
 *          DeviceName, as those must only be unique per user).
 *
 * @param[in] status
 *        status code indicating whether call to doDetectHardwareDevices was successful<br />
 *        Following status codes are possible:
 *        - AstStatus_OK: search for devices was successful, list may be empty.
 *        - AstStatus_INVALID_STATE: call to doDetectHardwareDevices was not allowed; possible reasons: a mIDentity is already connected to the App (see
 *                         doConnectHardwareDevice), certificatePolicy is "software", in case of certififcatePolicy "both" on
 *                         SmartPhone: virtualDevices is not yet logged in
 *        - AstStatus_INTERNAL_ERROR: Bluetooth problem (SmartPhones only)
 * @param[in] availableDevices
 *        NSAarray of NSString with names of available devices
 */
- (void)onDetectHardwareDevicesEnd:(AstStatus)status availableDevices:(NSArray*)availableDevices;
			
/**
 * @brief Reports whether connecting mIDentity to App was successful.
 *
 * This method is the response to doConnectHardwareDevice. The AstSdk may only send onCertificateAvailable or onInformationAvailable between the call to doConnectHardwareDevice
 * and onConnectHardwareDeviceEnd, but all other onXxx-methods will be called later (e.g. onDeviceConnection or onLoginBegin).
 *
 * @param[in] status
 *            status code indicating whether call to doConnectHardwareDevice was successful<br />
 *            Following status codes are possible:
 *            - AstStatus_OK: mIDentity is successfully connceted to App
 *            - AstStatus_INVALID_STATE: call to doConnectHardwareDevice was not allowed; possible reasons: a mIDentity is already connected to the App, there was
 *                         no successful onDetectHardwareDevicesEnd yet, certificate policy is "software", on PC with certificate policy "both": virtualDevice
 *                         not yet logged in
 *            - AstStatus_DEVICE_NOT_FOUND: selected mIDentity device is not connected to the system
 */		
- (void)onConnectHardwareDeviceEnd:(AstStatus)status;

/**
 * @brief Reports whether disconnecting mIDentity from App was successful.
 *
 * This method is the response to doDisconnectHardwareDevice.
 *
 * @param[in] status
 *            status code indicating whether call to doDisconnectHardwareDevice was successful<br />
 *            Following status codes are possible:
 *            - AstStatus_OK: mIDentity is successfully disconnected from the App
 *            - AstStatus_INVALID_STATE: call to doDisconnectHardwareDevice was not allowed; possible reasons: no mIDentity was connected to the App, certificate policy is "software" 
 */
- (void)onDisconnectHardwareDeviceEnd:(AstStatus)status;

 /**
 * @brief detailed reporting
 *
 * This methods allows to get detailed information an certain problem or error cases. Some possible values are for KOBIL internal debugging.
 *
 * @param[in] deviceType
 *            The AstDeviceType for this request.
 * @param[in] reportId
 *            event that has been occured
 */
- (void)onReport:(AstDeviceType)deviceType reportId:(int)reportId;

/**
 * @brief notification that a DisplayMessage is shown on mIDentity
 *
 * This method is invoked by the SSMS and sends a message to the app, e.g. some informational text of the server's administrator and the connected
 * device is a mIDentity Air+. The app should open a dialog and call on the user to confirm the message on the Air+.
 *
 * The method is an asynchronous call. The corresponding callback onInfoHardwareDisplayMessageEnd will be automatically invoked
 * by the AstSdk when the user has confirmed the message on the Air+.
 */
- (void)onInfoHardwareDisplayMessageBegin;

/**
 * @brief notification DisplayMessage is not shown on mIDentity anymore
 *
 * This method is invoked by the AstSdk when the user has confirmed the display message on the Air+.
 *
 * The method is an asynchronous call. It is the response for onInfoHardwareDisplayMessageBegin.
 */
- (void)onInfoHardwareDisplayMessageEnd;

@end
