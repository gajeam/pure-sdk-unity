//
//  PURMovementClassifier.h
//  PureSDK
//
//  Created by Hakon Hanesand on 1/7/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import <PureSDK/PURTrackingEnums.h>
#import <PureSDK/PURLocationTracker.h>

@protocol PURMovementClassifier;

@class PURInterruptibleTimer, PURLocationCache, PURMotionCache;
@class PURServiceLocator, PURMessageEvent, PURSwitch, PURQueue;

NS_ASSUME_NONNULL_BEGIN

typedef void(^PURClassifierDebugEventModifyBlock)(PURMessageEvent *, id<PURLocationTracker>);

@protocol PURMovementClassifierDelegate // The location tracking service

@property (nonatomic, readonly) PURTransportMethod transportMethod;
@property (nonatomic, readonly) PURTrackingAccuracy trackingAccuracy;

@property (nonatomic, getter=isTrackingInSleepMode) BOOL shouldTrackInSleepMode;

- (void)classifierDidPredictTransportMethod:(PURTransportMethod)transportMethod;

@end

@protocol PURMovementClassifier

- (instancetype)initWithDelegate:(id<PURMovementClassifierDelegate>)delegate
                         locator:(PURServiceLocator *)locator
                           queue:(PURQueue *)queue;

@property (nonatomic, readonly, nullable) PURMotionCache *motionCache;
@property (nonatomic, readonly, nullable) PURLocationCache *locationCache;

@property (nonatomic, weak) id<PURMovementClassifierDelegate> delegate;
@property (nonatomic, readonly, weak) PURServiceLocator *locator;

@property (nonatomic) PURQueue *queue;
@property (nonatomic, readonly, getter=isClassifying) PURSwitch *classifying;

- (void)startClassifyingForceTracking:(BOOL)tracking;
- (void)stopClassifying;

- (void)applicationWillTerminate;

- (void)updateLocations:(NSArray<CLLocation *> *)locations NS_SWIFT_NAME(update(locations:));

- (void)didExitCloseStationaryRegion:(CLCircularRegion *)circularRegion;

- (void)locationIdleTimerDidTriggerWithIdleDuration:(NSTimeInterval)duration;

#pragma mark - Testing Support

// Provided only for testing, not guaranteed to be implemented on all interfaces.
- (void)useClassificationTimer:(PURInterruptibleTimer *)timer;

@end

NS_ASSUME_NONNULL_END
