//
//  PURLiveEventService.h
//  PureSDK
//
//  Created by Hakon Hanesand on 9/5/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PURService.h>

#import <CoreLocation/CoreLocation.h>

@class PURDatedConnectionInformation, PUREventDescription;

NS_ASSUME_NONNULL_BEGIN

@interface PURLiveEventService : PURService

- (void)postLiveLocationWithEventDescription:(PUREventDescription *)description;
- (void)postLiveVisitWithEventDescription:(PUREventDescription *)description;
- (void)postLiveConnectionWithEventDescription:(PUREventDescription *)description;

@end

NS_ASSUME_NONNULL_END
