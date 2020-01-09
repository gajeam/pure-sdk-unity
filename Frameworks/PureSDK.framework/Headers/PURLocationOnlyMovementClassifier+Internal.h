//
//  PURLocationOnlyMovementClassifier+Internal.h
//  PureSDKTests
//
//  Created by Hakon Hanesand on 5/21/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

@import Foundation;

#import <PureSDK/PURLocationOnlyMovementClassifier.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURLocationOnlyMovementClassifier (Internal)

@property (nonatomic, class, readonly) PURDefaultsKey *significantLocationActivationLocationKey;

@end

NS_ASSUME_NONNULL_END
