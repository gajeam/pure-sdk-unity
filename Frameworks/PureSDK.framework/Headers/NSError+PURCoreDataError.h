//
//  NSError+PURCoreDataError.h
//  PureSDK
//
//  Created by Hakon Hanesand on 1/11/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSError (PURCoreDataError)

@property (nonatomic, readonly) BOOL pur_isCoreDataMigrationError;

@end

extern NSString * const kPURStatusCodeUserInfoKey;

typedef NS_ENUM(NSInteger, PURErrorCode) {
    PURErrorCodeMissingComponent,
    PURErrorSessionNotReady,
    PURErrorDeprecatedMethodSessionNotReady,
    PURErrorSDKNotActiveAndNotForced,
    PURErrorMainThreadOnly,
    PURErrorGeneric,

    PURErrorMissingEvents,
    PURErrorMissingUploadFile,
    PURErrorException
};

extern NSString *pur_errorCodeDescription(PURErrorCode error, NSArray * _Nullable args);

@interface NSError (PURShortcuts)

+ (nullable instancetype)pur_errorWithCode:(PURErrorCode)errorCode args:(nullable NSArray *)args;

- (nullable NSString *)pur_locationErrorCodeDescription;

@end

NS_ASSUME_NONNULL_END
