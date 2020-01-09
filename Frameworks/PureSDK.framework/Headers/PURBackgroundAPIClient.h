//
//  PURBackgroundAPIClient.h
//  PureSDK
//
//  Created by Hakon Hanesand on 6/8/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PURAPIClient.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURRequestResponse : NSObject

@property (nonatomic, readonly) NSURLSessionTask *task;
@property (nonatomic, nullable, readonly) NSURLResponse *URLResponse;
@property (nonatomic, nullable, readonly) NSError *error;
@property (nonatomic, nullable, readonly) id responseObject;

@property (nonatomic, readonly) NSInteger responseStatusCode;
@property (nonatomic, readonly) BOOL has200sStatusCode;

- (instancetype)initWithTask:(NSURLSessionTask *)task
                 URLResponse:(NSURLResponse * _Nullable)repsonse
              responseObject:(id _Nullable)responseObject
                       error:(NSError * _Nullable)error;

- (instancetype)initWithError:(NSError *)error;

@end

@interface PURBackgroundAPIClient : PURAPIClient

- (instancetype)initWithLocator:(PURServiceLocator *)locator
                 sessionManager:(NSURLSessionConfiguration * (^)(void))configuration NS_UNAVAILABLE;

// All observers deregistered after first message sent - no need for caller to deregister.
- (void)registerDidSendAllCompleteTaskMessagesObserver:(void (^)(void))didSendAllCompleteTasks
                                               onQueue:(PURQueue *)queue;

- (nullable NSString *)registerDidCompleteTaskObserver:(void (^)(PURRequestResponse *, NSString *))didCompleteTaskCallback
                                               onQueue:(PURQueue *)queue;

- (void)deregisterDidCompleteTaskObserverWithToken:(NSString *)token;

- (NSString *)storeDownloadLocationReturningOld:(NSString * _Nullable)downloadLocationPath
                              forTaskIdentifier:(NSNumber *)taskIdentifier;

@end

NS_ASSUME_NONNULL_END
