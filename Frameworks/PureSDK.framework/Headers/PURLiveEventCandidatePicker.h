//
//  PURLiveEventCandidatePicker.h
//  PureSDK
//
//  Created by Hakon Hanesand on 6/7/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PURQueue, PURDefaultsService, PURDefaultsTokenBag, PURDefaultsKey;

@protocol PURLiveEventCandidate

@property (nonatomic, readonly) NSString *candidateIdentifier;

- (void)mergeCandidateInformationIfMoreDesirable:(id<PURLiveEventCandidate>)otherCandidate;

@end

@interface PURLiveEventCandidatePicker : NSObject

- (instancetype)initWithQueue:(PURQueue *)queue
               defaultService:(PURDefaultsService *)defaultService
          debounceIntervalKey:(PURDefaultsKey *)debounceIntervalKey
         collectionEnabledKey:(PURDefaultsKey *)enabledKey
                    logPrefix:(NSString *)logPrefix
           postLiveEventBlock:(void (^)(id<PURLiveEventCandidate>))postLiveEventBlock;

- (void)didFindCandidate:(id<PURLiveEventCandidate>)type;

- (void)reset;

@end

NS_ASSUME_NONNULL_END
