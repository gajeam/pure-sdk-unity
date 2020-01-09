//
//  PURAPIClient+PURUserData.h
//  PureSDK
//
//  Created by Hakon Hanesand on 1/17/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PURAPIClient.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURAPIClient (PURUserData)

- (void)postEvent:(NSString *)type
          payload:(NSDictionary *)payload
          success:(nullable void (^)(void))success
          failure:(nullable void (^)(NSError *))failure;

- (void)associateMetadataWith:(NSString *)type
                      payload:(NSDictionary *)payload
                      success:(nullable void (^)(void))success
                      failure:(nullable void (^)(NSError *))failure;

- (void)latestDemoAppVersionWithSuccess:(nullable void (^)(NSString * _Nullable))success
                                failure:(nullable void (^)(NSError * _Nullable))failure;

@end

NS_ASSUME_NONNULL_END
