#import <Foundation/Foundation.h>

@interface IOSWrapper : NSObject

// Must be called to enable tracking. State is remembered between launches.
- (void)startTracking;

// Must be called to disable tracking. State is remembered between launches.
- (void)stopTracking;

// To check if we are tracking. State is remembered between launches.
- (BOOL)isTracking;

@end

