//
//  PURLocationCache.h
//  PureSDK
//
//  Created by Hakon Hanesand on 11/8/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class PURQueue;

NS_ASSUME_NONNULL_BEGIN

@interface PURLocationCacheAnalysisResult : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@property (nonatomic, readonly) CLLocationDistance totalDistanceMoved;
@property (nonatomic, readonly) CLLocationDistance distanceMovedThreshold;

@property (nonatomic, copy, readonly) NSArray<NSString *> *consideredLocations;

- (instancetype)initWithDistanceMoved:(CLLocationDistance)distanceMoved
                    distanceThreshold:(CLLocationDistance)distanceThreshold
                  consideredLocations:(NSArray<NSString *> *)consideredLocations;

- (NSDictionary *)serialized;

@end

@interface PURLocationCache : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithCacheSize:(NSUInteger)size queue:(PURQueue *)queue;

@property (nonatomic, nullable, readonly) CLLocation *mostRecentlyCachedLocation;
@property (nonatomic, nullable, readonly) CLLocation *oldestCachedLocation;

@property (nonatomic, readonly) NSUInteger cacheSize;

- (void)cacheLocations:(NSArray<CLLocation *> *)locations;

- (void)reset;

- (PURLocationCacheAnalysisResult *)analyzeCachedLocations;

@end

NS_ASSUME_NONNULL_END
