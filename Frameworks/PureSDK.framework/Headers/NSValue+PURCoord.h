//
//  NSValue+PURCoord.h
//  PureSDK
//
//  Created by Hakon Hanesand on 12/9/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

@import Foundation;
@import CoreLocation;

NS_ASSUME_NONNULL_BEGIN

@interface NSValue (PURCoord)

+ (NSValue *)pur_valueWithCoodinate:(CLLocationCoordinate2D)coordinate;

- (CLLocationCoordinate2D)pur_coordinateValue;

@end

NS_ASSUME_NONNULL_END
