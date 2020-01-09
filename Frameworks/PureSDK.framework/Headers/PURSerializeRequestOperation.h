//
//  PURBatchEventSerializationOperation.h
//  PureSDK
//
//  Created by Hakon Hanesand on 1/10/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

#import <PureSDK/PUROperation.h>
#import <PureSDK/PURExportableEvent.h>

@class PUREventStore, PURLogEvent;

NS_ASSUME_NONNULL_BEGIN

// Fetches log events based on provided fetchRequest, collects their serialized JSON representations (NSData instances)
// and then merges them into a single NSData object which is ready to be consumed as NSURLRequest.HTTPBody when
// posting events to the backend.
//
// Data flow:
//              1                           2                      3                   4
//      NSFetchRequest (input) -> NSArray<PURLogEvent *> -> NSArray<NSData *> -> NSData (merged output)
//
// Serialized JSON representations of log events (step #3 above) are arbitrary JSON dictionaries that are composed
// by PUREventSerializer.
//
// If exportAsObject=true, then objects are exported as described below.
// Output NSData value is a result of concatenation "{ 'events' : [" and all serialized representations of
// the log events separated by ",\n" and closing "] }" thus the final structure looks like this:
//
//      {
//         "events" : [
//             { ... },
//             { ... },
//          ]
//      }
//
// If exportAsObject=false, the same representation is used except the outer container is not a dictionary
// but an array (hence there is no "events" key:value pair) :
//
//      [
//          { ... },
//          { ... },
//      ]
//
@interface PURSerializeRequestOperation<SerializableObject: NSManagedObject<PURExportableEvent> *> : PUROperation

@property (nonatomic, readonly) NSFetchRequest *fetchRequest;

- (nullable instancetype)initWithEventStore:(PUREventStore *)eventStore
                                      queue:(PURQueue *)queue
                                       name:(NSString *)name
                               fetchRequest:(NSFetchRequest *)request
                        exportAsEventsArray:(BOOL)exportAsObject
                      deleteExportedObjects:(BOOL)deleteExportedObjects
                     outputFirstLastResults:(void (^)(SerializableObject first,
                                                      SerializableObject last,
                                                      NSUInteger count))outputFirstLastResults;

@end

NS_ASSUME_NONNULL_END
