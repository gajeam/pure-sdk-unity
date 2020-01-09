//
//  PUREventSerializer.h
//  PureSDK
//
//  Created by Kir on 2/6/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

#import <PureSDK/PURLogEvent.h>
#import <PureSDK/PURTrackingEnums.h>
#import <PureSDK/PURConnectionDefines.h>
#import <PureSDK/PURCurrentConnectionProvider.h>
#import <PureSDK/PUREventDescription.h>

@class PURDeviceInformationService, PURSystemStateService, PURDefaultsService;

NS_ASSUME_NONNULL_BEGIN

extern NSString *kPUREventAttributeDictionaryKeyDevice;      // common
extern NSString *kPUREventAttributeDictionaryKeyConnection;  // common
extern NSString *kPUREventAttributeDictionaryKeyState;       // common
extern NSString *kPUREventAttributeDictionaryKeyLocation;    // common
extern NSString *kPUREventAttributeDictionaryKeyEvent;

// Used for serializing analytical info into PURLogEvent instances.
//
// Main point is initializing `serializedJSONData` of PURLogEvent which is a dictionary representation
// of an event in serialized JSON form.
// Dictionary representation of all events have a fixed set of keys (see kPUREventAttributeDictionaryKey* constants):
//
//      - common (same structure for all events):
//                device
//                connection
//                state
//                location
//
//      - event specific (location, iBeacon, visit):
//                event
//
// Connection change events are stored as additional location change events (where 'location' info would be unchanged
// but connection info would).
//
@interface PUREventSerializer : NSObject

@end

@class PURLogEvent;

@interface PUREventSerializer (StatsToEvent)

- (void)fillLocationEvent:(PURLogEvent *)event eventDescription:(PUREventDescription *)description;
- (void)fillVisitEvent:(PURLogEvent *)event eventDescription:(PUREventDescription *)description;
- (void)fillConnectionEvent:(PURLogEvent *)event eventDescription:(PUREventDescription *)eventState;

@end

@interface PUREventSerializer (StatsToLiveEvent)

- (NSData * _Nullable)liveLocationEventAttributesDataWithFields:(NSArray<NSString *> *)fields eventState:(PUREventDescription *)description;
- (NSData * _Nullable)liveVisitEventAttributesDataWithFields:(NSArray<NSString *> *)fields eventState:(PUREventDescription *)description;

@end

@interface PUREventSerializer (Utility)

+ (nullable NSString *)timestampStringFromNumericTimestamp:(NSTimeInterval)updated;
+ (nullable NSString *)timestampStringFromDate:(NSDate *)date;

@end

#pragma mark - String conversion

extern NSString *pur_humanReadableLocationAuthorizationString(CLAuthorizationStatus status);
extern NSString *pur_appleLocationAuthorizationToString(CLAuthorizationStatus status);

extern PURTrackingAccuracy pur_trackingAccuracyFromString(NSString *accuracy);
extern NSString *pur_trackingAccuracyToString(PURTrackingAccuracy accuracy);

extern NSString *pur_transportMethodToString(PURTransportMethod state);

extern PURConnectionType pur_stringToConnectionType(NSString *connectionType);
extern NSString *pur_connectionTypeToString(PURConnectionType connectionType);

extern NSString *pur_proximityToString(CLProximity proximity);

extern NSString *pur_activityTypeToString(CLActivityType activity);

NS_ASSUME_NONNULL_END
