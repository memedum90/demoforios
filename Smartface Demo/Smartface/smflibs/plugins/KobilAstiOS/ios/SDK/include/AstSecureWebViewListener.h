#import <Foundation/Foundation.h>

@protocol AstSecureWebViewListener

/**
 * @brief callback for deciding on following redirects
 *
 * delegate method which will be called when the WebView needs to decide if a redirect request will be handled by the SDK or
 * if the App wants to preprocess the request (like opening a new window etc)
 *
 * @note The webView detection is not yet implemented. Therefore, the Parameter webView is always nil.
 *
 * @param url the Url thw SDK ask for how to handle it
 * @param mimeType of the target for the redirection
 * @param hdrline http status line of the redirection url
 * @param webView the calling WebView (not yet implemented yet, thus always nil)
 
 * @return whether the App decided to take it's turn: Note: YES implies App will handle it; NO implies SDK will continue
 */
- (BOOL)onBeforeNavigate:(NSString*)url withMimeType:(NSString*)mimeType withHeaderLine:(NSString*)hdrline forSecureWebView:(id)webView;

@end
