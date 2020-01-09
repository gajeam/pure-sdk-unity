//
//  PURLoggingService+Internal.h
//  PureSDKTests
//
//  Created by Hakon Hanesand on 8/29/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PURLoggingService.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURLoggingService (Internal)

- (void)log:(NSString *)log;
- (void)logError:(NSString *)error NS_SWIFT_NAME(log(error:));

- (void)setMuted:(BOOL)muted;

@property (nonatomic, readonly) PURIntervalUploadOrchestrator *orchestrator;

@end

NS_ASSUME_NONNULL_END
