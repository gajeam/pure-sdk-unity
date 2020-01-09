//
//  PURIntervalProtocol.h
//  PureSDK
//
//  Created by Hakon Hanesand on 6/7/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

@import CoreData;

NS_ASSUME_NONNULL_BEGIN

static int64_t const kNoTaskIdentifier = 0;
static int64_t const kErroredTaskIdentifier = -1;
static int64_t const kWaitingForTaskIdentifier = -2;
static int64_t const kFinishedTaskIdentifier = -3;

@interface PURIntervalDefinitions : NSObject

@property (class, readonly) NSPredicate *unserializedPredicate;
@property (class, readonly) NSPredicate *preparedForUploadPredicate;
@property (class, readonly) NSPredicate *uploadingPredicate;
@property (class, readonly) NSPredicate *finishedUploadingPredicate;
@property (class, readonly) NSPredicate *erroredUploadingPredicate;

@end

@protocol PURIntervalProtocol

@property (nonatomic) NSTimeInterval start;
@property (nonatomic) NSTimeInterval end;
@property (nonatomic) int64_t intervalEventCount;
@property (nonatomic) NSString *relativeFilePath;
@property (nonatomic) NSString *relativeBackupFilePath;
@property (nonatomic) int64_t compressedFileSize;
@property (nonatomic) int64_t uploadTaskIdentifier;
@property (nonatomic) NSTimeInterval uploadTaskBeginTimestamp;
@property (nonatomic) NSTimeInterval uploadTaskCompletionTimestamp;
@property (nonatomic) NSString *identifier;
@property (nonatomic) NSString *contentHash;
@property (nonatomic) BOOL attemptingForceUpload;

@property (nonatomic) int64_t uploadErrorCount;
@property (nonatomic) NSString *errorReason;

- (NSString *)description;

@property (nonatomic, readonly, assign, nullable) NSManagedObjectContext *managedObjectContext;

@end

typedef NSManagedObject<PURIntervalProtocol> PURIntervalObject;

NS_ASSUME_NONNULL_END
