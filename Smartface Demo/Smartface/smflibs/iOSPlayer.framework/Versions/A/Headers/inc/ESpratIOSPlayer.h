#import <UIKit/UIKit.h>

#ifdef SMARTFACE_PRODUCTION
#include <iOSPlayer/JavaScriptCore/inc/JavaScriptCore.h>
#else
#import "JavaScriptCore.h"
#endif

__attribute__ ((visibility ("default"))) @protocol ESpratIOSPlayerInterface <NSObject>
-(void) SMFRun;
-(void) SMFAppWillTerminate;
-(void) SMFAppEnteredBackground;
-(void) SMFAppCameFromBackground;
-(void) SMFReceiveNotification :(UILocalNotification*)notification;
-(void) SMFRegisteredNotification:(NSData *)token andError:(NSError *)error;
-(void) SMFSetRemoteTempDict:(NSDictionary *)dictionary;
-(void) SMFHandleRemoteNotification:(UIApplication *)application andDict:(NSDictionary *)dict;
-(void) SMFHandleUrlAppCall:(NSURL *)url;
-(void) SMFSetAppCallUrl:(NSURL *)url;
-(BOOL) SMFIsCameFromBack;
-(void) SMFLoadCustomPluginIdentifier:(const char *)definitonString andDefinition:(const JSClassDefinition *)classDefinition withObject:(void **)privateObject;
-(void) SMFRunJavaScriptSmartface:(JSContextRef)ctx :(JSObjectRef)object :(JSObjectRef)thisObject :(size_t)argumentCount :(const JSValueRef[])args;

@end

__attribute__ ((visibility ("default"))) @interface ESpratIOSPlayer : NSObject{
}

+(id<ESpratIOSPlayerInterface>) SMFGetPlayer;

@end
