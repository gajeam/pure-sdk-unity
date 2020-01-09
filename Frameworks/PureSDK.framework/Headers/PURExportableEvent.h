//
//  PURExportableEvent.h
//  PureSDK
//
//  Created by Hakon Hanesand on 8/29/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#ifndef PURExportableEvent_h
#define PURExportableEvent_h

@import Foundation;
@import CoreData;

NS_ASSUME_NONNULL_BEGIN

@protocol PURExportableEvent

- (NSString *)description;

@property (nonatomic, readonly) NSTimeInterval timestamp;
@property (nonatomic, readonly, nullable) NSData *serializedJSONData;

- (NSDictionary *)dictionaryRepresentation;

@end

NS_ASSUME_NONNULL_END

#endif /* PURExportableEvent_h */
