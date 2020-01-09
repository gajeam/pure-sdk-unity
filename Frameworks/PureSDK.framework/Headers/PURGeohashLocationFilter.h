//
//  PURGeohashLocationFilter.h
//  PureSDK
//
//  Created by Hakon Hanesand on 5/13/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import <PureSDK/PURDefaultsService.h>
#import <PureSDK/PURCommittableFlagWrapper.h>

NS_ASSUME_NONNULL_BEGIN

// Observes the current location, the blacklist and whitelist.
// Updates `insideWhitelistedAreaDefaultKey` according to the lists.
@interface PURGeohashLocationFilter : NSObject

@property (nonatomic, readonly) PURCommittableValueWrapper<NSNumber *> *inWhitelistedAreaWrapper;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithDefaults:(PURDefaultsService *)defaults
                        tokenBag:(PURDefaultsTokenBag *)tokenBag
                           queue:(PURQueue *)queue;

- (BOOL)didUpdateLocation:(CLLocation *)mostRecentLocation;

- (BOOL)didUpdateCoordinate:(CLLocationCoordinate2D)coordinate;

- (BOOL)isCoordinateWhitelisted:(CLLocationCoordinate2D)coordinate;


@end

NS_ASSUME_NONNULL_END

