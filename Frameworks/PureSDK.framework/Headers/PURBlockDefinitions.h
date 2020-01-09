//
//  PURBlockDefinitions.h
//  PureSDK
//
//  Created by Hakon Hanesand on 12/1/18.
//  Copyright © 2018 fluxLoop AS. All rights reserved.
//

@class PURLogEvent;

#ifndef PURBlockDefinitions_h
#define PURBlockDefinitions_h

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^PURCompletion)(void);
typedef void (^PURErrorCompletion)(NSError * _Nullable error);
typedef void (^PURSingleCompletion)(NSManagedObject * _Nullable context, NSError * _Nullable error);
typedef void (^PURCountCompletion)(NSUInteger count);
typedef void (^PURArrayResultCompletion)(NSArray<__kindof NSManagedObject *> *result);
typedef void (^PURArrayContextCompletion)(NSArray<__kindof NSManagedObject *> *result, NSManagedObjectContext *context);

typedef void (^PURModifyBlock)(__kindof NSManagedObject *object);
typedef void (^PURModifyEventBlock)(PURLogEvent *event);

NS_ASSUME_NONNULL_END

#endif /* PURBlockDefinitions_h */
