//
//  PURAPIClient+PUREventPost.h
//  PureSDK
//
//  Created by Hakon Hanesand on 12/7/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PURAPIClient.h>
#import <PureSDK/PURAsyncBlockOperation.h>

#import <PureSDK/PURDefaultsKey.h>

@class PUREventInterval;

NS_ASSUME_NONNULL_BEGIN

@interface PURAPIClient (PUREventPost)

// Creates an upload request from the specified `fileURLString`.
// `uploadTaskIdentifierOut` is called with the uploadTaskIdentifier of the network task when it is created.
- (PURAsyncBlockOperation *)postSerializedIntervalAtURL:(NSURL *)fileURL
                                    toEndpointAtDefault:(PURDefaultsKey<NSString *> *)endpoint
                                          fileSizeAtURL:(int64_t)bytes
                                           requiresWiFi:(BOOL)requiresWiFi
                                             identifier:(NSString *)identifier
                                            contentHash:(NSString *)contentHash
                                          responseQueue:(PURQueue *)queue;


- (NSArray<PUROperation *> *)forcePostPayload:(NSArray<NSDictionary *> *)payload
                          toEndpointAtDefault:(PURDefaultsKey<NSString *> *)endpoint
                                   identifier:(NSString *)blobIdentifier
                                responseQueue:(PURQueue *)responseQueue;

// Alternative to `postSerializedIntervalAtURL`, used to force push data to server opportunistically.
- (PURAsyncBlockOperation *)forcePostSerializedIntervalAtURL:(NSURL *)fileURL
                                         toEndpointAtDefault:(PURDefaultsKey<NSString *> *)endpoint
                                                  identifier:(NSString *)blobIdentifier
                                                 contentHash:(NSString *)contentHash
                                               responseQueue:(PURQueue *)queue;

// Jarle: "Data should be sent as single events (not arrays). The headers should be the same as with other requests.
//         If the device is offline, ignore the event. The batching and interval upload should continue as previously
//         regardless of if live sending is enabled or not."
- (PURAsyncBlockOperation *)postLiveEventOperationWithData:(NSData *)data
                                             responseQueue:(PURQueue *)queue;

@end

NS_ASSUME_NONNULL_END
