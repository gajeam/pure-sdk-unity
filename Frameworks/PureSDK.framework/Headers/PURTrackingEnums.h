//
//  PURTrackingEnums.h
//  PureSDK
//
//  Created by Hakon Hanesand on 11/8/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

@import Foundation;
@import CoreLocation;

#pragma once

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(int64_t, PURTransportMethod) {
    PURTransportMethodWalking,
    PURTransportMethodRunning,
    PURTransportMethodCycling,
    PURTransportMethodDriving,
    PURTransportMethodDrivingHighway,
    PURTransportMethodFlying
};

typedef NS_ENUM(int64_t, PURTrackingAccuracy) {
    PURTrackingAccuracyLow,
    PURTrackingAccuracyMed,
    PURTrackingAccuracyHigh
};

typedef NS_ENUM(NSInteger, PURTrackingState) {
    PURTrackingStateOff,
    PURTrackingStateSleeping,
    PURTrackingStateContinuous,
    PURTrackingStatePeriodic,
};

extern NSString *trackingStateToString(PURTrackingState state);

extern BOOL isRegularTrackingEnabledForState(PURTrackingState state);
extern BOOL isEfficientTrackingEnabledForState(PURTrackingState state, CLAuthorizationStatus status);

extern CLLocationDistance pur_distanceFilterForTrackingState(PURTrackingState state,
                                                             PURTransportMethod transport,
                                                             PURTrackingAccuracy accuracy);

extern CLLocationDistance pur_desiredAccuracyForTrackingState(PURTrackingState state);

extern CLLocationDistance trackingDistanceFilterFor(PURTransportMethod state, PURTrackingAccuracy accuracy);

NS_ASSUME_NONNULL_END
