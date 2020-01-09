//
//  PURDefaultsService+Internal.h
//  PureSDKTests
//
//  Created by Hakon Hanesand on 8/22/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PURDefaultsService.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURDefaultsService (Internal)

@property (nonatomic, readonly) NSLock *stateLock;

- (nullable id)locked_readValueFromFileWithKey:(PURDefaultsKey *)defaultKey
                                isInBackground:(BOOL)isInBackground;

- (void)flushWritesToDiskWithCompletion:(void (^ _Nullable)(void))completion;

- (void)writeValue:(NSData *)data forKey:(NSString *)key;

@property (nonatomic) NSLock *scheduledWritesLock;
@property (nonatomic) NSMutableDictionary *scheduledWrites;

@end

NS_ASSUME_NONNULL_END
