//
//  Pure.h
//  PureSDK
//
//  Created by Hakon Hanesand on 2/2/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import <AvailabilityMacros.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^PURSuccessBlock)(void);
typedef void(^PURErrorBlock)(NSError * _Nullable error);

@interface PURTrackingInfo : NSObject

@property (nonatomic, readonly) BOOL isTrackingEnabled;
@property (nonatomic, readonly) BOOL locationServicesEnabled;
@property (nonatomic, readonly) CLAuthorizationStatus locationAuthorization;

@property (nonatomic, readonly) BOOL isUserMonitized;

@end

/// All methods require that initializeWithLaunchOptions: has been called.
/// Errors will be printed to the console if the SDK is not initialized.
@interface Pure : NSObject

/// Initializes the SDK. This call takes less than 80 ms (0.08 sec) to complete.
/// You can call via dispatch_async(dispatch_get_main_queue(), ...), but this is rarely needed.
/// We instrument this call on our test devices to ensure it never slows down your application.
/// If the launch info dictionary is not included, we could miss out on some location events.
+ (void)initializeWithLaunchOptions:(nullable NSDictionary<UIApplicationLaunchOptionsKey, id> *)launchOptions
    NS_SWIFT_NAME(initialize(with:));

/// Must be called to enable tracking. The state is remembered between launches.
/// Remember, [Pure initializeWithLaunchOptions] must be called before this method!
+ (void)startTracking;

/// Immediately stops collecting events. The state is remembered between launches.
/// Events that are already collected will still be uploaded.
+ (void)stopTracking;

/// If YES, then the SDK is actively collecting events.
@property (class, nonatomic, readonly) BOOL isTracking;

/// Use this method if you want to check whether the SDK is delivering data.
/// SDK is collecting & delivering data if `trackingInfo.isUserMonitized` is `YES`.
/// Will be nil until `initializeWithLaunchOptions` is called.
@property (class, nonatomic, readonly, nullable) PURTrackingInfo *trackingInfo;

/// The current session's Pure Identifier. Will be nil until `initializeWithLaunchOptions` is called.
@property (class, nonatomic, readonly, nullable) NSString *pureIdentifier;

/// See documentation below. Defaults to force = NO.
+ (void)createEventWithType:(NSString *)type payload:(NSDictionary *)payload
                    success:(nullable PURSuccessBlock)success failure:(nullable PURErrorBlock)failure;

/// Publishes a custom event to the cloud, associated with the current session.
/// Events are grouped by `type`. Subsequent calls with the equal `type` keys will result in one entry per call.
/// An error will be returned if `initializeWithLaunchOptions:` has not been called.
/// Normally, this method will return an error if it is called while the SDK is not tracking.
/// Pass YES to the `force` parameter to override this behavior, and send the event regardless of tracking state.
+ (void)createEventWithType:(NSString *)type payload:(NSDictionary *)payload force:(BOOL)force
                    success:(nullable PURSuccessBlock)success failure:(nullable PURErrorBlock)failure;

/// See documentation below. Defaults to force = NO.
+ (void)associateMetadataWithType:(NSString *)type payload:(NSDictionary *)payload
                          success:(nullable PURSuccessBlock)success failure:(nullable PURErrorBlock)failure;

/// Associates a payload with the current user session. Data will be available in the cloud.
/// Events are grouped by `type`. Subsequent calls with the equal `type` keys will overwrite eachother.
/// An error will be returned if `initializeWithLaunchOptions:` has not been called.
/// Normally, this method will return an error if it is called while the SDK is not tracking.
/// Pass YES to the `force` parameter to override this behavior, and send the event regardless of tracking state.
+ (void)associateMetadataWithType:(NSString *)type payload:(NSDictionary *)payload force:(BOOL)force
                          success:(nullable PURSuccessBlock)success failure:(nullable PURErrorBlock)failure;

/// Returns YES if initializeWithLaunchOptions has already been called.
/// It's safe to call `initializeWithLaunchOptions:` multiple times.
@property (nonatomic, class, readonly) BOOL isInitialized;

/// Apps with the same publisherId will have their data linked.
/// By default, we use the `PURPublisherId` in your Info.plist.
/// Setting this in code will override the id in the plist.
@property (nonatomic, class) NSString *publisherId;

/// The PureSDK version.
@property (nonatomic, class, readonly) NSString *version;

/// We log calls to `initializeWithLaunchOptions:`, `startTracking`, and `stopTracking` in order to provide our clients with
/// a more complete picture of the devices which have PureSDK enabled. If lightweight analytics are enabled, session lengths
/// are also included in some payloads.
+ (void)setLightweightAnalyticsEnabled:(BOOL)lightweightAnalyticsEnabled;

#pragma mark - Deprecated

// Following methods deprecated in 1.0.95

+ (void)fetchPureIdentifier:(void (^)(NSString * _Nullable))pureIdentifierBlock __attribute__((deprecated));

+ (void)isSDKTracking:(void (^)(BOOL))isTracking __attribute__((deprecated));

+ (void)fetchTrackingStatus:(void (^)(BOOL isTrackingEnabled,
                                      BOOL locationServicesEnabled,
                                      CLAuthorizationStatus authorization))trackingStatus __attribute__((deprecated));

// Following methods deprecated in 1.0.90

@property (nonatomic, class) BOOL loggingEnabled __attribute__((deprecated));

@end

NS_ASSUME_NONNULL_END

