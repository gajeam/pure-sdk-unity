//
//  PURLocationTrackingService+Internal.h
//  PureSDKTests
//
//  Created by Hakon Hanesand on 5/21/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

@import Foundation;

#import <PureSDK/PURLocationTrackingService.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURLocationTrackingService (Internal)

@property (nonatomic) id<PURLocationTracker> locationTracker;
@property (nonatomic) id<PURMovementClassifier> classifier;

@property (nonatomic, readonly) PURInterruptibleTimer *whenInUseWaitBetweenScansTimer;
@property (nonatomic, readonly) PURInterruptibleTimer *gpsIdleTimer;
@property (nonatomic, readonly) PURInterruptibleTimer *highPriorityTrackingTimer;

@property (nonatomic, readonly) PURLocationTrackingStateObserver *stateObserver;

@property (nonatomic, copy) void (^gpsStateObserverBlock)(PURLocationServiceState trackingState);

- (void)sendTrackingUpdateCallback;

- (void)useClassificationTimer:(nullable PURInterruptibleTimer *)timer;

@end

NS_ASSUME_NONNULL_END
