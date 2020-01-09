//
//  PURPlistConfiguration+Internal.h
//  PureSDKTests
//
//  Created by Hakon Hanesand on 5/19/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

@import Foundation;

#import <PureSDK/PURPlistConfiguration.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURPlistConfiguration (Internal)

+ (void)useMockedSharedConfigObject:(PURPlistConfiguration *)mocked;

@end

NS_ASSUME_NONNULL_END
