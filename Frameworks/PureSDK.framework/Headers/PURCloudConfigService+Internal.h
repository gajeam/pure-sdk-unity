//
//  PURCloudConfigService.h
//  PureSDKTests
//
//  Created by Hakon Hanesand on 1/18/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PURCloudConfigService.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURCloudConfigService (Internal)

+ (PURDefaultsKey *)lastConfigFetchTimestampKey;

- (void)pur_applyFetchedCloudConfigToDefaultsStore:(NSDictionary<NSString *, NSObject *> *)config;

@end

NS_ASSUME_NONNULL_END
