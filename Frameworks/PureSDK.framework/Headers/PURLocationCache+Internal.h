//
//  PURLocationCache+Internal.h
//  PureSDKTests
//
//  Created by Hakon Hanesand on 12/15/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

@import Foundation;

#import <PureSDK/PURLocationCache.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURLocationCache (Internal)

- (NSArray<CLLocation *> *)cachedLocations;

@end

NS_ASSUME_NONNULL_END
