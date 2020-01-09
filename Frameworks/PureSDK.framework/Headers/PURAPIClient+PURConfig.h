//
//  PURAPIClient+PURConfig.h
//  PureSDK
//
//  Created by Hakon Hanesand on 12/12/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PURAPIClient.h>

@class PURAsyncBlockOperation;

NS_ASSUME_NONNULL_BEGIN

@interface PURAPIClient (PURConfig)

- (PURAsyncBlockOperation *)getConfigWithEarliestBeginDate:(NSDate *)earliestBeginDate
                                           writingConfigTo:(NSString *)downloadLocationPath
                                             responseQueue:(PURQueue *)responseQueue;

- (void)getConfigWithSuccess:(void (^)(NSDictionary *))success
                       began:(void (^ _Nullable)(NSURLSessionTask *))began
                     failure:(void (^)(NSError * _Nullable))failure
               responseQueue:(PURQueue *)queue;

- (void)getConfigAt:(NSString *)configEndpoint
              began:(void (^ _Nullable)(NSURLSessionTask *))began
            success:(void (^)(NSDictionary *))success
            failure:(void (^)(NSError * _Nullable))failure
      responseQueue:(PURQueue *)queue;

@end

NS_ASSUME_NONNULL_END
