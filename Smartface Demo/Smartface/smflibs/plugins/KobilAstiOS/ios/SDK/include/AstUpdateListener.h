#import <Foundation/Foundation.h>

#import "AstSdkTypes.h"

/**
 * @brief 
 *
 * This protocol and the corresponding protocol AstUpdate provide the AstSdk update mechanism.
 */
@protocol AstUpdateListener

/**
 * @brief Response to {@link AstUpdate::doStartUpdate:}
 *
 * Will be called upon a successful call of {@link AstUpdate::doStartUpdate:}
 *
 * @param[in] deviceType
 *            The AstDeviceType for this request.
 * @param[in] status
 *            result of doStartUpdate
 */
-(void)onUpdateBegin:(AstDeviceType)deviceType status:(AstUpdateStatus)status;

/**
 * @brief Provides detailed information on updates.
 *
 * After each status AstStatus_UPDATE_AVAILABLE or AstStatus_UPDATE_NECESSARY during onActivationEnd, onLoginEnd, or
 * onReactivationEnd this callback will follow and provide additional information.
 *
 * @param[in] deviceType
 *            The AstDeviceType for the update information
 * @param[in] status
 *            is the update status that was also signaled in onActivationEnd, onLoginEnd, or onReactivationEnd
 * @param[in] updateUrl
 *            an UTF8 encoded link pointing to the update packet (may be configured in SSMS)
 * @param[in] infoUrl
 *            an UTF8 encoded link to a generic update information page (may be configured in SSMS)
 * @param[in] updateType
 *            target of the upxdate: either the client App or the firmware of the mIDentity device
 * @param[in] expiresInSeconds
 *            remaining seconds the old version can still be used if status was UPDATE_AVAILABLE
 */
-(void)onUpdateInformationAvailable:(AstDeviceType)deviceType status:(AstStatus)status updateUrl:(NSString*)updateUrl infoUrl:(NSString*)infoUrl updateType:(AstUpdateType)updateType expiresInSeconds:(uint32_t)expiresInSeconds;

/**
 * @brief Response to {@link AstUpdate::doOpenInfoUrl:}
 *
 * Will be called upon a call to {@link AstUpdate::doOpenInfoUrl:} and returns its status.
 *
 * @param[in] deviceType
 *            The AstDeviceType for this request.
 * @param[in] status
 *            result of doOpenInfoUrl
 */
-(void)onOpenInfoUrlEnd:(AstDeviceType)deviceType status:(AstUpdateStatus)status;

@end
