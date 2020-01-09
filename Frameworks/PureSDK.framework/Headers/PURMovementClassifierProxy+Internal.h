//
//  PURMovementClassifierProxy+Internal.h
//  PureSDKTests
//
//  Created by Hakon Hanesand on 1/8/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

@import Foundation;

#import <PureSDK/PURMovementClassifierProxy.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURMovementClassifierProxy (Internal)

- (id<PURMovementClassifier>)currentClassifier;

@end

NS_ASSUME_NONNULL_END
