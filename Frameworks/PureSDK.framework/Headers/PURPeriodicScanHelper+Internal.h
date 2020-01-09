//
//  PURPeriodicScanHelper+Internal.h
//  PureSDKTests
//
//  Created by Hakon Hanesand on 5/25/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PURPeriodicScanHelper.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURPeriodicScanHelper (Internal)

@property (nonatomic, readonly) PURInterruptibleTimer *pauseBetweenScansTimer;
@property (nonatomic, readonly) PURInterruptibleTimer *ongoingScanTimer;

@end

NS_ASSUME_NONNULL_END
