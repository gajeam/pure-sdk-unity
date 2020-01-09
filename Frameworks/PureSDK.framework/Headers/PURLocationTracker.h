//
//  PURLocationTracker.h
//  PureSDK
//
//  Created by Hakon Hanesand on 12/20/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import <PureSDK/PURTrackingEnums.h>
#import <PureSDK/PURCommittableFlagWrapper.h>

@class PURInterruptibleTimer, PURSwitch, PURInterruptibleTimer;

NS_ASSUME_NONNULL_BEGIN

extern BOOL pur_isWhileInUse(CLAuthorizationStatus status);
extern BOOL pur_isWhileInUseOrAlways(CLAuthorizationStatus);
extern BOOL pur_isAlways(CLAuthorizationStatus status);

@protocol PURLocationTracker;

@protocol PURLocationTrackerDelegate

- (void)didUpdateLocation:(CLLocation *)location;
- (void)didUpdateAuthorizationStatus:(CLAuthorizationStatus)status;
- (void)didExitCloseCircularRegion:(CLCircularRegion *)region;
- (void)didVisit:(CLVisit *)visits;

- (NSTimeInterval)locationIdleTimerLengthForAccuracy:(PURTrackingAccuracy)accuracy;
- (void)locationIdleTimerDidTriggerWithIdleDuration:(NSTimeInterval)interval;

@end

@protocol PURLocationTracker

- (void)setState:(PURTrackingState)state
        accuracy:(PURTrackingAccuracy)accuracy
 transportMethod:(PURTransportMethod)transportMethod
      completion:(void (^ _Nullable)(void))completion;

@property (nonatomic, readonly) PURTransportMethod transportMethod;
@property (nonatomic, readonly) PURTrackingAccuracy trackingAccuracy;
@property (nonatomic, readonly) PURTrackingState trackingState;

@property (nonatomic, readonly, weak) id<PURLocationTrackerDelegate> delegate;
@property (nonatomic, readonly, nullable) CLLocation *currentLocation;
@property (nonatomic, readonly) PURInterruptibleTimer *gpsIdleTimer;

// Provided only for testing.
@property (nonatomic) CLLocationManager *locationManager;

- (void)appDidResume;

- (void)setLocationTrackingEnabled:(BOOL)enabled;
- (void)setSleepModeTrackingEnabled:(BOOL)isInSleepState;
- (void)setShowsBackgroundLocationIndicator:(BOOL)showsBackgroundLocationIndicator;
- (void)setVisitTrackingEnabled:(BOOL)enabled;

// Return YES if the request was granted, NO otherwise.
- (BOOL)requestLocationWithCompletion:(void (^ _Nullable)(CLLocation *))completion;
- (void)stopRequestingLocation;

- (void)forceEnableSleepModeTrackingWithDispatchGroup:(dispatch_group_t)dispatchGroup;

// Provided for demo app integration.

@property (nonatomic, readonly) PURSwitch *trackingRegularLocation;
@property (nonatomic, readonly) PURSwitch *trackingInSleepMode;
@property (nonatomic, readonly) PURSwitch *trackingVisits;
@property (nonatomic, readonly) PURSwitch *requestingLocation;
@property (nonatomic, readonly) PURCommittableValueWrapper<CLCircularRegion *> *closeCircularRegionWrapper;

@end

NS_ASSUME_NONNULL_END
