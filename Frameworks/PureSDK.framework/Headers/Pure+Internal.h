//
//  Pure+Internal.h
//  PureSDKTests
//
//  Created by Hakon Hanesand on 6/5/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <PureSDK/Pure.h>

NS_ASSUME_NONNULL_BEGIN

@interface Pure (Internal)

+ (void)pur_stubInitialize;

+ (void)requestPermissionsIfPossible;

@end

NS_ASSUME_NONNULL_END
