//
//  PURDebugNotificationService.h
//  IssueReporter
//
//  Created by Hakon Hanesand on 8/30/18.
//

#import <PureSDK/PURService.h>

#import <CoreLocation/CoreLocation.h>

@class PURHighPriorityBeaconRegion, PURLocationCacheAnalysisResult;

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(10.0))
@interface PURDebugNotificationService : PURService

- (void)sendDidEnterSleepTrackingState:(PURLocationCacheAnalysisResult *)analysis;

- (void)sendDidReceiveSignificantLocationChangeDistance:(CLLocationDistance)distance
                                              threshold:(CLLocationDistance)threshold
                                     horizontalAccuracy:(CLLocationAccuracy)hacc;

- (void)sendDidReceiveSignificantLocationNoPreviousLocation;

- (void)sendDidExitCloseCircularRegion:(CLCircularRegion *)region;

- (void)sendGotSigLocInitialLocationDistance:(CLLocationDistance)distance
                                   threshold:(CLLocationDistance)threshold
                                        hacc:(CLLocationAccuracy)hacc;

- (void)sendDidEnterSleepBecauseIdleFor:(NSTimeInterval)timeSinceLocation timerLength:(NSTimeInterval)timerLength;

- (void)sendGotVisit:(CLVisit *)visit;

@end

NS_ASSUME_NONNULL_END
