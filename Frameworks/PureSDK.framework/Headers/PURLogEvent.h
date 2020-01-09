//
//  PURLogEvent.h
//
//  Created by Hakon Hanesand on 11/9/17.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

#import <PureSDK/PURExportableEvent.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(int16_t, PURLogEventType) {
    PURLogEventTypeLocation = 0,
    // deleted element, skipped for consistency
    PURLogEventTypeVisit = 2,
    PURLogEventTypeConnection,
};

extern NSString *pur_logEventTypeToString(PURLogEventType eventType);

@interface PURLogEvent : NSManagedObject <NSFetchRequestResult, PURExportableEvent>

#pragma mark - Request body (related: PUREventSerializer, PURBatchEventSerializationOperation, -[PUR*APIClient postEventsOperation])

// Serialized JSON representation in a format required by the backend.
// PUREventSerializer is used to fill it based on system info stats, location data etc.
@property (nonatomic, nullable) NSData *serializedJSONData;

#pragma mark - Shortcuts for local use

// type: location (location change or connection change),
//       iBeacon (CLBeacon),
//       visit (CLVisit)
//
// Used by: the segment control UI within the demo app
@property (nonatomic) PURLogEventType type;

// Location info
// Used by: map view within the demo app
@property (nonatomic) double latitude;
@property (nonatomic) double longitude;
@property (nonatomic) double hacc;

// Creation timestamp
// Refers to a moment when the event was created/recorded by the SDK (location data may have
// a different timestamp).
//
// Used by: the demo app, for filtering/sorting for organizing events in batches for upload
@property (nonatomic) NSTimeInterval timestamp;

// Timestamp from a CLLocation object associated with the event
@property (nonatomic) NSTimeInterval locationTimestamp;

@end

@interface PURLogEvent (Shortcuts)

+ (NSPredicate *)locationEventTypePredicate;
+ (NSPredicate *)visitEventTypePredicate;
+ (NSPredicate *)connectionEventTypePredicate;

+ (NSArray<NSPredicate *> *)allEventTypePredicates;

+ (NSPredicate *)eventTypePredicateWithType:(PURLogEventType)type;

@end

NS_ASSUME_NONNULL_END
