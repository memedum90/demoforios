#import <Foundation/Foundation.h>

#import "AstSdkTypes.h"

/**
 * @brief This protocol and the corresponding callback protocol AstUpdateListener provide the AstSdk update mechanism.
 */
@protocol AstUpdate

/**
 * @brief Start the update procedure.
 * 
 * Start the update procedure. This function may only after receiving onUpdateInformation with status AstStatus_UPDATE_AVAILABLE and with an non-empty
 * updateUrl. This will call the devices App store at the app entry pointed to by the updateUrl.
 *
 * @param[in] deviceType
 *            The AstDeviceType for this request.
 */
-(void)doStartUpdate:(AstDeviceType)deviceType;

/**
 * @brief Open the received info URL in browser.
 *
 * Open the received info URL in the default system browser if the info URL was not empty. This will be answered with callback {@link AstUpdateListener::onOpenInfoUrlEnd:status:}.
 *
 * @param[in] deviceType
 *            The AstDeviceType for this request.
 */
-(void)doOpenInfoUrl:(AstDeviceType)deviceType;

@end
