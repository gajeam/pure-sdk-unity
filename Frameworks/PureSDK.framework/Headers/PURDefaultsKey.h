//
//  PURDefaultsKey.h
//  PureSDK
//
//  Created by Hakon Hanesand on 1/5/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURDefaultsKey<T> : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@property (nonatomic, readonly) NSString *key;
@property (nonatomic, readonly) Class type;
@property (nonatomic, readonly, nullable) T defaultValue;
@property (nonatomic, readonly) BOOL allowsBufferingWrites;

- (instancetype)initWithKey:(NSString *)key
                       type:(Class)type
               defaultValue:(nullable T)defaultValue;

- (instancetype)initWithKey:(NSString *)key
                       type:(Class)type
               defaultValue:(nullable T)defaultValue
             allowBuffering:(BOOL)allowBuffering;

- (void)assertValidValue:(nullable id)object;

@end

NS_ASSUME_NONNULL_END
