//
//  PURLiveEventService+Private.h
//  PureSDK
//
//  Created by Hakon Hanesand on 6/19/19.
//  Copyright © 2019 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PURLiveEventService.h>

#import <PureSDK/PUREventSerializer.h>

NS_ASSUME_NONNULL_BEGIN

@interface PURLiveEventService (Private)

@property (nonatomic) PUREventSerializer *eventSerializer;

- (void)p_uploadLiveEventWithData:(NSData * _Nullable)data;

- (BOOL)shouldUploadLiveEvent;

@end

NS_ASSUME_NONNULL_END
