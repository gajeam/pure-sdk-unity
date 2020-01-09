//
//  PURMacros.h
//  PureSDK
//
//  Created by Hakon Hanesand on 12/12/17.
//  Copyright © 2017 fluxLoop AS. All rights reserved.
//

#pragma once

#import <PureSDK/PURAssertMacros.h>
#import <PureSDK/PURCocoaLumberjack.h>
#import <PureSDK/PURKeypathMacros.h>
#import <PureSDK/PURSelectorChecking.h>
#import <PureSDK/PURWeakifyMacros.h>
#import <PureSDK/PURFunctions.h>
#import <PureSDK/PURLoggingService.h>

#import <PureSDK/NSError+PURCoreDataError.h>

#if DEBUG
static PURLogLevel ddLogLevel = PURLogLevelVerbose;
#else
static PURLogLevel ddLogLevel = PURLogLevelInfo;
#endif

extern id private_PURRequireNonNilAssert(char *file, int line, NSArray *);

#define PURRequireNonNil(obj) (typeof(obj))(obj == nil ? private_PURRequireNonNilAssert(__FILE__, __LINE__, [NSThread callStackSymbols]) : obj)

// Checks if the block exists before calling the block
#define pur_safeBlockCall(block, ...) \
    (block ? (block(__VA_ARGS__)) : nil)

#define PURAssertMainThread(frmt, ...) \
    PURAssert(NSThread.isMainThread, frmt, ## __VA_ARGS__);

#define PURAssertCondition(cond) \
    PURAssert(cond, @"Condition not satisfied: %s (location: %s:%d)", #cond, __FILE__, __LINE__);

#define PURSafeCast(targetClass, name, value, return)                 \
    PURAssertReturn([value isKindOfClass:targetClass.class], return); \
    targetClass *name = (targetClass *)value;

#define PURAssertReturn(cond, returnValue) \
    PURAssertCondition(cond);              \
    if ((cond) == NO) {                    \
        return returnValue;                \
    }

#define PURAssertReturnUnlock(cond, lock, returnValue) \
    PURAssertCondition(cond);                          \
    if ((cond) == NO) {                                \
        [lock unlock];                                 \
        return returnValue;                            \
    }

#define PURAssertReturnDesc(cond, returnValue, fmt, ...) \
    PURAssert(cond, fmt, ##__VA_ARGS__);                 \
    if ((cond) == NO) {                                  \
        return returnValue;                              \
    }

#define PURAssertReturnDescUnlock(cond, lock, returnValue, fmt, ...) \
    PURAssert(cond, fmt, ##__VA_ARGS__);                             \
    if ((cond) == NO) {                                              \
        [lock unlock];                                               \
        return returnValue;                                          \
    }

#define PURAssertSkipIteration(cond) \
    PURAssertCondition(cond)         \
    if ((cond) == NO) {              \
        continue;                    \
    }

#define PURSimpleCatchExceptionsRunning(protectedCode, prefix)                                               \
    @try {                                                                                                   \
        do { protectedCode } while (NO);                                                                     \
    } @catch (NSException *exception) {                                                                      \
        NSArray *callstack = [NSThread callStackSymbols];                                                    \
        NSArray *args = @[pur_NSNullWrapped(exception), pur_NSNullWrapped(callstack)];                       \
        __unused NSError *exceptionError = [NSError pur_errorWithCode:PURErrorException args:args];          \
        LogWhenInitialized(PURLogFlagError, @"%@ EXCEPTION_THROWN %@, callstack : \n%@",                     \
                                prefix, exception, callstack);                                               \
    }

#define PURCatchExceptionsRunning(protectedCode, prefix, handleError, handleFinally)                         \
    @try {                                                                                                   \
        do { protectedCode } while (NO);                                                                     \
    } @catch (NSException *exception) {                                                                      \
        NSArray *callstack = [NSThread callStackSymbols];                                                    \
        NSArray *args = @[pur_NSNullWrapped(exception), pur_NSNullWrapped(callstack)];                       \
        __unused NSError *exceptionError = [NSError pur_errorWithCode:PURErrorException args:args];          \
                                                                                                             \
        LogWhenInitialized(PURLogFlagError, @"%@ EXCEPTION_THROWN %@, callstack : \n%@",                     \
                            prefix, exception, callstack);                                                   \
                                                                                                             \
        do { handleError } while (NO);                                                                       \
                                                                                                             \
    } @finally {                                                                                             \
        do { handleFinally } while (NO);                                                                     \
    }

#define PURAssertReturnNil(cond) PURAssertReturn(cond, nil)
#define PURAssertReturnNilDesc(cond, fmt, ...) PURAssertReturnDesc(cond, nil, fmt, ##__VA_ARGS__)

// C Variations of above Macros

#define PURCAssertCondition(cond) \
    PURCAssert(cond, @"Condition not satisfied: %s (location: %s:%d)", #cond, __FILE__, __LINE__);\

#define PURCAssertReturnNil(cond)               PURCAssertReturn(cond, nil)
#define PURCAssertReturnNilDesc(cond, fmt, ...) PURCAssertReturnDesc(cond, nil, fmt, ##__VA_ARGS__)

#define PURCAssertReturn(cond, returnValue) \
    PURCAssertCondition(cond);              \
    if ((cond) == NO) {                     \
        return returnValue;                 \
    }

#define PURCAssertReturnDesc(cond, returnValue, fmt, ...) \
    PURCAssert(cond, fmt, ##__VA_ARGS__);                 \
    if ((cond) == NO) {                                   \
        return returnValue;                               \
    }

#define PURCAssertSkipIteration(cond) \
    PURAssertCondition(cond);         \
    if ((cond) == NO) {               \
        continue;                     \
    }

#define PURCAssertReturnNil(cond)               PURCAssertReturn(cond, nil)
#define PURCAssertReturnNilDesc(cond, fmt, ...) PURCAssertReturnDesc(cond, nil, fmt, ##__VA_ARGS__)

#define pur_addDictionaryValue(dictionary, key, value) \
    if (key != nil) { dictionary[key] = value; }

#define pur_addArrayValue(array, value) \
    if (value != nil) {                 \
        [array addObject:value];        \
    }

#define create_dict_1(name, key1, value1)                  \
    NSMutableDictionary *name = [NSMutableDictionary new]; \
    pur_addDictionaryValue(name, key1, value1);

#define create_dict_2(name, key1, value1, key2, value2)    \
    NSMutableDictionary *name = [NSMutableDictionary new]; \
    pur_addDictionaryValue(name, key1, value1);            \
    pur_addDictionaryValue(name, key2, value2);            \

#define create_dict_3(name, key1, value1, key2, value2, key3, value3) \
    NSMutableDictionary *name = [NSMutableDictionary new];            \
    pur_addDictionaryValue(name, key1, value1);                       \
    pur_addDictionaryValue(name, key2, value2);                       \
    pur_addDictionaryValue(name, key3, value3);                       \

#define create_dict_4(name, key1, value1, key2, value2, key3, value3, key4, value4) \
    NSMutableDictionary *name = [NSMutableDictionary new];                          \
    pur_addDictionaryValue(name, key1, value1);                                     \
    pur_addDictionaryValue(name, key2, value2);                                     \
    pur_addDictionaryValue(name, key3, value3);                                     \
    pur_addDictionaryValue(name, key4, value4);                                     \

#define create_dict_5(name, key1, value1, key2, value2, key3, value3, key4, value4, key5, value5)  \
    NSMutableDictionary *name = [NSMutableDictionary new];                                         \
    pur_addDictionaryValue(name, key1, value1);                                                    \
    pur_addDictionaryValue(name, key2, value2);                                                    \
    pur_addDictionaryValue(name, key3, value3);                                                    \
    pur_addDictionaryValue(name, key4, value4);                                                    \
    pur_addDictionaryValue(name, key5, value5);                                                    \

#define create_dict_6(name, key1, value1, key2, value2, key3, value3, key4, value4, key5, value5, key6, value6)  \
    NSMutableDictionary *name = [NSMutableDictionary new];                                                       \
    pur_addDictionaryValue(name, key1, value1);                                                                  \
    pur_addDictionaryValue(name, key2, value2);                                                                  \
    pur_addDictionaryValue(name, key3, value3);                                                                  \
    pur_addDictionaryValue(name, key4, value4);                                                                  \
    pur_addDictionaryValue(name, key5, value5);                                                                  \
    pur_addDictionaryValue(name, key6, value6);                                                                  \

// https://fluxloop.slack.com/archives/C7KNWDMRC/p1523366670000330
#define pur_trimFractional(v) (round((v) * 10000000) / 10000000.)
#define pur_trimFractionalf(v) (roundf((v) * 10000000) / 10000000.)

#define pur_twoDigitFractional(v) (round((v) * 100) / 100.)
