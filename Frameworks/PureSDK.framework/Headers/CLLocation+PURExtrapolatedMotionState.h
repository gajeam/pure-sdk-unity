//
//  CLLocation+PURExtrapolatedMotionState.h
//  PureSDK
//
//  Created by Hakon Hanesand on 11/8/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>

#import <PureSDK/PURTrackingEnums.h>

NS_ASSUME_NONNULL_BEGIN

@interface CLLocation (PURExtrapolatedMotionState)

- (PURTransportMethod)pur_mostLikelyEquivalentMotionState;

- (NSString *)pur_displayDescriptionWithLastLocation:(nullable CLLocation *)previous;

- (NSString *)pur_infoString;

- (BOOL)pur_isEqualToLocation:(nullable CLLocation *)location;

- (BOOL)pur_isAdjacentToLocation:(CLLocation *)otherLocation;

+ (NSString *)pur_coordinateStringsFrom:(NSArray<CLLocation *> *)locations;

- (NSDictionary *)pur_serialized;

@end

NS_ASSUME_NONNULL_END
