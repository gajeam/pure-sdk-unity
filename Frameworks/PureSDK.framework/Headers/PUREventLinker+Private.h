//
//  PUREventLinker+Private.h
//  PureSDK
//
//  Created by Hakon Hanesand on 6/19/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PUREventLinker.h>

#import <PureSDK/PUREventSerializer.h>
#import <PureSDK/PUREventLinkerState.h>

NS_ASSUME_NONNULL_BEGIN

@interface PUREventLinker (Private)

@property (nonatomic, readonly) PUREventSerializer *eventSerializer;
@property (nonatomic, readonly) PURMutableEventLinkerState *mutableEventState;

@end

NS_ASSUME_NONNULL_END
