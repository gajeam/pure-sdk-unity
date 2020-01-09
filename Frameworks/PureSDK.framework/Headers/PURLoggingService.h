//
//  PURLoggingService.h
//  PureSDK
//
//  Created by Hakon Hanesand on 12/11/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PURService.h>
#import <PureSDK/PURMacros.h>
#import <PureSDK/PURLog.h>
#import <PureSDK/PURPlistConfiguration.h>

NS_ASSUME_NONNULL_BEGIN

#define LogDebugAppOnlyToTerminal(lvl, format, ...)                                                                          \
    if (PURPlistConfiguration.shared.isStagingApp) {                                                                         \
        NSString *__message = [NSString stringWithFormat:format, ##__VA_ARGS__];                                             \
        PURLogMessage *__log = [[PURLogMessage alloc] initWithMessage:__message                                              \
                                                                level:LOG_LEVEL_DEF                                          \
                                                                 flag:lvl                                                    \
                                                              context:0                                                      \
                                                                 file:[NSString stringWithFormat:@"%s", __FILE__]            \
                                                             function:[NSString stringWithFormat:@"%s", __PRETTY_FUNCTION__] \
                                                                 line:__LINE__                                               \
                                                                  tag:nil                                                    \
                                                              options:(PURLogMessageOptions)0                                \
                                                            timestamp:nil];                                                  \
                                                                                                                             \
        [[PURTTYLogger sharedInstance] logMessage:__log];                                                                    \
    }

#define LogWhenInitialized(lvl, format, ...)                                                                             \
    NSString *__message = [NSString stringWithFormat:format, ##__VA_ARGS__];                                             \
    PURLogMessage *__log = [[PURLogMessage alloc] initWithMessage:__message                                              \
                                                            level:LOG_LEVEL_DEF                                          \
                                                             flag:lvl                                                    \
                                                          context:0                                                      \
                                                             file:[NSString stringWithFormat:@"%s", __FILE__]            \
                                                         function:[NSString stringWithFormat:@"%s", __PRETTY_FUNCTION__] \
                                                             line:__LINE__                                               \
                                                              tag:nil                                                    \
                                                          options:(PURLogMessageOptions)0                                \
                                                        timestamp:nil];                                                  \
                                                                                                                         \
    [[PURSessionController shared].session.services.logger logWhenInitialized:__log];

@interface PURLoggingService : PURService

- (void)logWhenInitialized:(PURLogMessage *)log;

- (void)waitForLoggingServiceWithTimeout:(NSTimeInterval)timeout;

@end

NS_ASSUME_NONNULL_END
