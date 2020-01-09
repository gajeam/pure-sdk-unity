//
//  UIApplication+PURApplication.h
//  PureSDK
//
//  Created by Hakon Hanesand on 12/23/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PURQueue;

NS_ASSUME_NONNULL_BEGIN

@interface PURBackgroundTask : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@property (nonatomic) NSString *name;

- (instancetype)initWithName:(NSString *)name queue:(PURQueue *)queue;

@end

@interface UIApplication (PURApplication)

+ (PURBackgroundTask *)pur_backgroundTaskWithName:(NSString *)name
                                expirationHandler:(void (^ _Nullable)(void))expiration;

+ (void)pur_endBackgroundTask:(PURBackgroundTask *)task;

@end

NS_ASSUME_NONNULL_END
