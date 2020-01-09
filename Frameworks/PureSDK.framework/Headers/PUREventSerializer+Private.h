//
//  PUREventSerializer+Private.h
//  PureSDK
//
//  Created by Hakon Hanesand on 6/19/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PUREventSerializer.h>
#import <PureSDK/PUREventDescription.h>

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface PUREventSerializer (Private)

- (NSMutableDictionary *)commonAttributesForKeys:(NSArray * _Nullable)keys
                                        forState:(PUREventDescription *)state;

- (void)finalizeSerializedEvent:(PURLogEvent *)event
                       description:(PUREventDescription *)state
          byMergingDictionaries:(NSArray *)attributeDictionaries;

- (NSData *)mergeSerializedAttributes:(NSArray<NSDictionary *> *)listOfAttributeDictionaries;

@end

NS_ASSUME_NONNULL_END
