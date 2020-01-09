//
//  PURForegroundIntervalUploader.h
//  PureSDK
//
//  Created by Hakon Hanesand on 6/23/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <PureSDK/PURDefaultsKey.h>

@class PURServiceLocator, PUREventIntervalProducer, PUREventIntervalSerializer;
@class PURBackgroundIntervalUploader, PURQueue, PURAPIClient;

NS_ASSUME_NONNULL_BEGIN

// NOTE : "Foreground" and "Force" mean the same thing in the code.

@interface PURForegroundIntervalUploader : NSObject

- (instancetype)initWithLocator:(PURServiceLocator *)locator
                  intervalClass:(Class)intervalClass
                      logPrefix:(NSString *)logPrefix
               intervalProducer:(PUREventIntervalProducer *)intervalProducer
             intervalSerializer:(PUREventIntervalSerializer *)intervalSerializer
               intervalUploader:(PURBackgroundIntervalUploader *)intervalUploader
          uploadEndpointDefault:(PURDefaultsKey<NSString *> *)uploadEndpointDefault
                          queue:(PURQueue *)queue
                concurrentQueue:(PURQueue *)concurrentQueue;

- (void)foregroundPushPendingIntervalsForceBatch:(BOOL)force
                                      completion:(void (^ _Nullable)(void))completion;

@end

NS_ASSUME_NONNULL_END
