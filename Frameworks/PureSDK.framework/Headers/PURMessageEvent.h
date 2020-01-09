//
//  PURMessageEvent.h
//
//  Created by Hakon Hanesand on 11/17/17.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import <CoreLocation/CoreLocation.h>

#import <PureSDK/PURLocationCache.h>
#import <PureSDK/PURTrackingEnums.h>
#import <PureSDK/PURExportableEvent.h>

#import <PureSDK/PURLocationTracker.h>
#import <PureSDK/PURCocoaLumberjack.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURMessageEvent : NSManagedObject <NSFetchRequestResult, PURExportableEvent>

- (instancetype)init NS_UNAVAILABLE;

- (void)configureWithLogMessage:(PURLogMessage *)message;

@property (nonatomic) NSString *message;
@property (nonatomic) NSTimeInterval timestamp;
@property (nonatomic) int64_t level;
@property (nonatomic) int64_t offset;

@end

NS_ASSUME_NONNULL_END
