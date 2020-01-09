//
//  PURGeohashLocationFilter+Internal.h
//  PureSDKTests
//
//  Created by Hakon Hanesand on 5/13/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PURGeohashLocationFilter.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURGeohashLocationFilter (Internal)

- (instancetype)initWithWhitelist:(NSArray<NSString *> *)whitelist
                        blacklist:(NSArray<NSString *> *)blacklist
                            queue:(PURQueue *)queue;

- (BOOL)isGeohashWhitelisted:(NSString *)geohash;

@end

NS_ASSUME_NONNULL_END
