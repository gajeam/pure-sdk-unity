//
//  PURAnalyticsEvent.h
//  PureSDK
//
//  Created by Hakon Hanesand on 6/17/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <CoreData/CoreData.h>

#import <PureSDK/PURExportableEvent.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(int64_t, PURAnalyticsEventType) {
    PURAnalyticsEventTypePreInit = 1, // sent when the SDK is loaded into memory
    PURAnalyticsEventTypeInit, // sent when the client calls `[Pure initWithLaunchOptions:]`
    PURAnalyticsEventTypeStartTracking, // sent when the client calls `[Pure startTracking]`
    PURAnalyticsEventTypeStopTracking, // sent when the client calls `[Pure stopTracking]`
    PURAnalyticsEventTypeSessionStart, // sent when the user opens the app
    PURAnalyticsEventTypeSessionEnd, // sent when the user backgrounds the app
    PURAnalyticsEventTypeTerminate // sent when the user force quits
};

extern BOOL pur_isSessionAnalyticsEvent(PURAnalyticsEventType type);
extern NSString *pur_analyticsEventTypeToString(PURAnalyticsEventType type);

@interface PURAnalyticsEvent : NSManagedObject <PURExportableEvent>

// included only for eventType == SessionStart | SessionEnd
@property (nonatomic) BOOL wasLastSessionTerminated;

// if eventType == SessionStart, time since last SessionEnd
// if eventType == SessionEnd, time since last SessionStart
@property (nonatomic) NSTimeInterval timeSinceLastSessionEvent;

@property (nonatomic) float batteryLevel;
@property (nonatomic) BOOL background;

@property (nonatomic) NSTimeInterval timestamp;
@property (nonatomic) int64_t unixMillis;
@property (nonatomic) PURAnalyticsEventType eventType;

- (NSDictionary *)dictionaryRepresentation;

@end

NS_ASSUME_NONNULL_END
