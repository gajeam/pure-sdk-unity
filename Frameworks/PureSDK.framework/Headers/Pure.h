//
//  Pure.h
//  PureSDK
//
//  Created by Hakon Hanesand on 2/2/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#include <AvailabilityMacros.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^PURSuccessBlock)(void);
typedef void(^PURErrorBlock)(NSError * _Nullable error);

/// All methods require that initializeWithLaunchOptions: has been called.
/// Errors will be printed to the console if the SDK is not initialized.
@interface Pure : NSObject

/// Initializes the SDK. This call takes less than 80 ms (0.08 sec) to complete.
/// You can call via dispatch_async(dispatch_get_main_queue(), ...), but this is rarely needed.
/// We instrument this call on our test devices to ensure it never slows down your application.
/// If the launch info dictionary is not included, we could miss out on location events.
+ (void)initializeWithLaunchOptions:(nullable NSDictionary<UIApplicationLaunchOptionsKey, id> *)launchOptions
    NS_SWIFT_NAME(initialize(with:));

/// Must be called to enable tracking. The state is remembered between launches.
/// Remember, [Pure initializeWithLaunchOptions] must be called before this method!
+ (void)startTracking;

/// Immediately stops collecting events. The state is remembered between launches.
/// Events that are already collected will still be uploaded.
+ (void)stopTracking;

/// If YES, then the SDK is actively collecting events.
/// The method is asynchronous since the SDK may not be done initializing when this method is called.
+ (void)isSDKTracking:(void (^)(BOOL))isTracking;

/// The current session's Pure Identifier. Will be nil until `initializeWithLaunchOptions` is called.
/// The method is asynchronous since the SDK may not be done initializing when this method is called.
+ (void)fetchPureIdentifier:(void (^)(NSString * _Nullable))pureIdentifier;

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

/// We log calls to `initializeWithLaunchOptions:`, `startTracking`, and `stopTracking` in order to provide our clients with
/// a more complete picture of the devices which have PureSDK enabled. If lightweight analytics are enabled, session lengths
/// are also included in some payloads.
+ (void)setLightweightAnalyticsEnabled:(BOOL)lightweightAnalyticsEnabled;

#pragma mark - Deprecated

// Following methods deprecated in 1.0.90

@property (nonatomic, class) BOOL loggingEnabled __attribute__((deprecated));

// Following methods deprecated in 1.0.74

+ (BOOL)isTracking __attribute__((deprecated("Use +isSDKTracking:")));
+ (NSString * _Nullable)pureId __attribute__((deprecated("Use +fetchPureIdentifier:")));

// Following methods deprecated in 1.0.60

+ (void)startWithLaunchOptions:(NSDictionary *)launchOptions
    __attribute__((deprecated("Use +initializeWithLaunchOptions:")));

@end

NS_ASSUME_NONNULL_END

