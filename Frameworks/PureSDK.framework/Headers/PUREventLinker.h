//
//  PUREventLinker.h
//  PureSDK
//
//  Created by Hakon Hanesand on 1/9/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

#import <PureSDK/PURService.h>
#import <PureSDK/PURDatedConnectionInformation.h>
#import <PureSDK/PURBaseDataStore.h>

#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

@class PUREventLinkerState;

@interface PUREventLinker : PURService

// These methods create database events, and dispatch live events.
- (void)insertLocationEvents:(NSArray<CLLocation *> *)locations
                      modify:(nullable PURModifyEventBlock)modify
                  completion:(nullable PURModifyEventBlock)completion;

- (void)insertVisitEvent:(CLVisit *)visit
                  modify:(nullable PURModifyEventBlock)modify
              completion:(nullable PURModifyEventBlock)completion;

- (void)insertConnectionEvent:(PURDatedConnectionInformation *)connectionInformation
                       modify:(nullable PURModifyEventBlock)modify
                   completion:(nullable PURModifyEventBlock)completion;

// Identical behavior as above, except without modify: completion: blocks.
- (void)insertLocationEvents:(NSArray<CLLocation *> *)locations;
- (void)insertVisitEvent:(CLVisit *)visit;
- (void)insertConnectionEvent:(PURDatedConnectionInformation *)connectionInformation;

@end

NS_ASSUME_NONNULL_END
