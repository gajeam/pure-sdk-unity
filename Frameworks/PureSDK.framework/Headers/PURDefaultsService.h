//
//  PURDefaultsService.h
//  PureSDK
//
//  Created by Hakon Hanesand on 11/20/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PURService.h>
#import <PureSDK/PURDefaultsKey.h>
#import <PureSDK/PURLoggingService.h>
#import <PureSDK/PURDefaultsNotificationTracker.h>

@class CLLocation, PURQueue;

// While operating in background, NSUserDefaults may or may not be unaccessible, due to the folders
// it uses to store being marked with a NSFileProtectionType that prevents access while locked.
// See https://forums.developer.apple.com/thread/15685#discussion-45849
// We use our own defaults service to circumvent this problem.

NS_ASSUME_NONNULL_BEGIN

typedef void(^PURDefaultChangeNotificationBlock)(id _Nullable value);

extern NSString * const PURDefaultsDirectory;

@interface PURDefaultsService : PURService

// Use only if the value type is unknown.
- (void)setValue:(nullable id)value forDefault:(PURDefaultsKey *)defaultKey;

// If queue is nil, callback is run on the thread on which the change occurred.
- (nullable NSString *)observeKeyForChanges:(PURDefaultsKey *)defaultsKey
                                      queue:(PURQueue * _Nullable)queue
                             withBlockToken:(PURDefaultChangeNotificationBlockWithToken)block;

- (nullable NSString *)observeKeyForChanges:(PURDefaultsKey *)defaultsKey
                                      queue:(PURQueue * _Nullable)queue
                                  withBlock:(PURDefaultChangeNotificationBlock)block;

- (nullable NSString *)observeBooleanDefault:(PURDefaultsKey *)defaultsKey
                                       queue:(PURQueue * _Nullable)queue
                                   didUpdate:(void (^)(BOOL))didUpdateBlock;

- (void)stopObservingKey:(PURDefaultsKey *)defaultsKey withToken:(NSString *)token;

- (nullable NSObject *)valueForDefault:(PURDefaultsKey *)defaultKey;

- (void)disableBufferingAndFlush;
- (void)flushAllWrites;

- (void)migrateDefaultStorageFormatWithCompletion:(void (^)(void))completion;

@end

@interface PURDefaultsService (SharedDefaultKeys)

// The user's most recent location that the SDK has logged.
@property (nonatomic, readonly, class) PURDefaultsKey *mostRecentLocationDefaultKey;

@property (nonatomic, readonly, class) PURDefaultsKey *mostRecentConnectionDefaultKey;

// YES if the user's most recent location was inside a whitelisted area.
// Whitelisted areas are defined in the config, and used for GDPR compliance.
@property (nonatomic, readonly, class) PURDefaultsKey *insideWhitelistedAreaDefaultKey;

// Initially NO, but set to YES the first time the user calls [PureSDK init..]
// Several services wait for this default to be YES before starting tracking.
@property (nonatomic, readonly, class) PURDefaultsKey *isSDKActiveDefaultKey;

@end

@interface PURDefaultsService (Overrides)

- (void)startOverridingDefaultKey:(PURDefaultsKey *)key withValue:(nullable id)value;
- (void)stopOverridingDefaultKey:(PURDefaultsKey *)key;

// Returns a list of the currently overridden config keys and their ORIGINAL values.
- (NSDictionary<NSString *, NSObject *> *)currentlyOverriddenConfigKeys;

@end

@interface PURDefaultsService (Accessors)

- (nullable NSDate *)dateForDefault:(PURDefaultsKey *)key;
- (nullable NSString *)stringForDefault:(PURDefaultsKey *)key;
- (nullable NSNumber *)numberForDefault:(PURDefaultsKey *)key;
- (nullable CLLocation *)locationForDefault:(PURDefaultsKey *)key;
- (nullable NSArray *)arrayForDefault:(PURDefaultsKey *)key;
- (nullable NSDictionary *)dictionaryForDefault:(PURDefaultsKey *)key;
- (BOOL)boolForDefault:(PURDefaultsKey *)key;

@end

@interface PURDefaultsService (Setters)

- (void)setDate:(nullable NSDate *)date forDefault:(PURDefaultsKey *)key;
- (void)setString:(nullable NSString *)string forDefault:(PURDefaultsKey *)key;
- (void)setNumber:(nullable NSNumber *)number forDefault:(PURDefaultsKey *)key;
- (void)setInteger:(NSInteger)integer forDefault:(PURDefaultsKey *)key;
- (void)setDouble:(double)dbl forDefault:(PURDefaultsKey *)key;
- (void)setLocation:(nullable CLLocation *)location forDefault:(PURDefaultsKey *)key;
- (void)setArray:(nullable NSArray *)array forDefault:(PURDefaultsKey *)key;
- (void)setDictionary:(nullable NSDictionary *)dictionary forDefault:(PURDefaultsKey *)key;
- (void)setBool:(BOOL)kool forDefault:(PURDefaultsKey *)key;

@end

@interface PURDefaultsService (TestSupport)

- (void)resetDefaultsServiceShouldRecreateDirectory:(BOOL)shouldDelete;

- (void)deleteDefaultsDirectoryShouldRecreate:(BOOL)recreate;

- (NSDictionary<NSString *, id> *)dumpDefaults;

- (NSArray<NSString *> *)overridenDefaultKeys;

- (NSArray<PURDefaultsKey *> *)knownDefaultKeys;

@end

NS_ASSUME_NONNULL_END
