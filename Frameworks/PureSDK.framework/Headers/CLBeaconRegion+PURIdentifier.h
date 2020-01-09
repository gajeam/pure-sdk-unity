//
//  CLBeaconRegion+PURIdentifier.h
//  PureSDK
//
//  Created by Hakon Hanesand on 5/18/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CLBeaconRegion (PURIdentifier)

@property (nonatomic, readonly) NSString *pur_regionIdentifier;
@property (nonatomic, readonly) NSString *pur_shortenedRegionIdentifier;

@property (nonatomic, readonly) BOOL pur_isFluxloopRegion;

// Checks that object is an CLBeaconRegion
// AND that the proximityUUID has proper prefix.
+ (NSPredicate *)pur_fluxloopBeaconRegionPredicate;

+ (CLBeaconRegion * _Nullable)pur_fluxloopBeaconRegionFromConfig:(NSDictionary *)beaconRegionConfig;
- (NSDictionary *)pur_fluxloopBeaconRegionConfig;

@end

@interface CLCircularRegion (PURIdentifier)

+ (CLCircularRegion *)pur_fluxloopCircularRegionForLocation:(CLLocation *)location
                                                     radius:(CLLocationDistance)radius
                                                       name:(NSString *)name;

+ (NSPredicate *)pur_fluxloopCircularRegionPredicate;

- (NSString *)pur_displayDescription;

@end

NS_ASSUME_NONNULL_END
