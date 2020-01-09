//
//  PURAPIClient.h
//  PureSDK
//
//  Created by Hakon Hanesand on 12/7/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PURService.h>

NS_ASSUME_NONNULL_BEGIN

@class PURAPIRequestTemplate, PURURLSessionManager, PURRequestResponse;

typedef void(^PURNetworkBeganBlock)(NSURLSessionTask *task);
typedef void(^PURNetworkSuccessBlock)(PURRequestResponse *response);
typedef void(^PURNetworkFailureBlock)(PURRequestResponse *response);

@interface PURAPIClient : PURService

- (void)performSimpleRequest:(PURAPIRequestTemplate *)request
                       began:(nullable PURNetworkBeganBlock)began
                     success:(void (^ _Nullable)(void))success
                     failure:(void (^ _Nullable)(NSError *))failure
               responseQueue:(PURQueue *)queue;

- (void)performRequest:(PURAPIRequestTemplate *)requestTemplate
                 began:(nullable PURNetworkBeganBlock)began
               success:(PURNetworkSuccessBlock)success
               failure:(PURNetworkFailureBlock)failure
         responseQueue:(PURQueue *)queue;

- (instancetype)initWithLocator:(PURServiceLocator *)locator
                 sessionManager:(PURURLSessionManager * (^)(void))manager;

- (void)getSessionManager:(void (^)(PURURLSessionManager *sessionManager))block;

- (void)networkTasksForIdentifiers:(NSArray<NSNumber *> *)taskIdentifiers
                             queue:(PURQueue *)queue
                        completion:(void (^)(NSArray<NSURLSessionTask *> *tasks, NSSet<NSNumber *> *invalidIdentifiers))completion;

- (void)debug_printActiveNetworkTasks;

@end

NS_ASSUME_NONNULL_END
