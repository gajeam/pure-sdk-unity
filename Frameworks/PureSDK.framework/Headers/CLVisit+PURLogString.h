//
//  CLVisit+PURLogString.h
//  PureSDK
//
//  Created by Hakon Hanesand on 5/23/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CLVisit (PURLogString)

- (NSString *)pur_coordinateString;

@end

NS_ASSUME_NONNULL_END
