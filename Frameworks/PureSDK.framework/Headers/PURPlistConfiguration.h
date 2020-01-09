//
//  PURPlistConfiguration.h
//  PureSDK
//
//  Created by Hakon Hanesand on 12/7/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <CoreLocation/CoreLocation.h>

@class PURQueue;

NS_ASSUME_NONNULL_BEGIN

@interface PURPlistConfiguration : NSObject

- (instancetype)initWithQueue:(PURQueue *)queue;

@property (nonatomic, class, readonly) PURPlistConfiguration *shared;

@property (nonatomic, readonly) NSString *frameworkVersion;
@property (nonatomic, readonly) NSString *frameworkBuild;

@property (nonatomic, readonly) NSString *clientVersion;
@property (nonatomic, readonly) NSString *clientBuild;

// Returns True for both debug demo and demo app. And if defaultStore debug = YES.
@property (nonatomic, readonly) BOOL isAnyDevEnvironment;

@property (nonatomic, readonly) BOOL isDebugApp;
@property (nonatomic, readonly) BOOL isStagingApp;

@property (nonatomic, readonly, nullable) NSString *frameworkBundleId;
@property (nonatomic, readonly, nullable) NSString *clientBundleId;

@property (nonatomic, readonly, nullable) NSString *publisherId;
@property (nonatomic, readonly) NSString *defaultConfigEndpoint;

// True only if the client app has NSLocationAlwaysAndWhenInUseUsageDescription
// and NSLocationWhenInUseUsageDescription set in their Info.plist.
@property (nonatomic, readonly) BOOL couldAskForLocationPermissions;

@property (nonatomic, readonly) BOOL hasBackgroundLocationMode;
@property (nonatomic, readonly) BOOL hasBackgroundBluetoothCentralMode;

// Proxied methods. Indirection used for testing purposes.
@property (nonatomic, readonly) CLAuthorizationStatus locationAuthorizationStatus;
@property (nonatomic, readonly) BOOL locationServicesEnabled;
@property (nonatomic, readonly) BOOL significantLocationServicesEnabled;
@property (nonatomic, readonly) BOOL isRangingAvailable;
@property (nonatomic, readonly) BOOL isAuthorizedToTrackActivities;
@property (nonatomic, readonly) BOOL isCircularRegionMonitoringAvailable;
@property (nonatomic, readonly) BOOL isBeaconRegionMonitoringAvailable;

@end

NS_ASSUME_NONNULL_END
