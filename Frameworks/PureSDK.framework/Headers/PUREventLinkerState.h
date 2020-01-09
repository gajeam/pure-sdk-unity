//
//  PUREventLinkerState.h
//  PureSDK
//
//  Created by Hakon Hanesand on 11/16/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

@class PURDatedConnectionInformation, PURQueue, PURMutableEventLinkerState;

NS_ASSUME_NONNULL_BEGIN

@interface PUREventLinkerState : NSObject <NSCoding>

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithVisit:(CLVisit * _Nullable)visit
                     location:(CLLocation * _Nullable)location
        connectionInformation:(PURDatedConnectionInformation *)connectionInfo;

// Mandatory properties.
@property (nonatomic, readonly) PURDatedConnectionInformation *connectionInfo;

// Properties storing the most recent event information.
// These may be nil as we may not have permission or haven't received them yet.
@property (nonatomic, readonly, nullable) CLVisit *visit;
@property (nonatomic, readonly, nullable) CLLocation *location;

- (PURMutableEventLinkerState *)makeMutableOnQueue:(PURQueue *)queue;

@end

@interface PURMutableEventLinkerState : NSObject <NSCopying>

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithVisit:(CLVisit * _Nullable)visit
                     location:(CLLocation * _Nullable)location
        connectionInformation:(PURDatedConnectionInformation *)connectionInfo NS_UNAVAILABLE;

- (instancetype)initWithVisit:(CLVisit * _Nullable)visit
                     location:(CLLocation * _Nullable)location
        connectionInformation:(PURDatedConnectionInformation *)connectionInfo
                        queue:(PURQueue *)queue;

// These types require that the most recent location be included in the API call.
// Whenever any of these are YES, then we've delayed sending an event type because
// we haven't gotten a location event yet. If we receive more than one
// event while we still haven't gotten location, we keep the latest.

@property (nonatomic) BOOL waitingOnLocationForConnectionEvent;
@property (nonatomic) BOOL waitingOnLocationForVisitEvent;

@property (nonatomic, nullable) CLVisit *visit;
@property (nonatomic, nullable) CLLocation *location;
@property (nonatomic, nullable) PURDatedConnectionInformation *connectionInfo;

@end

NS_ASSUME_NONNULL_END
