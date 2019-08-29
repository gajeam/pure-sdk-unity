
#import "IOSWrapperImpl.h"
#import <PureSDK/Pure.h>

@implementation IOSWrapper

- (id)init
{
    self = [super init];
    return self;
}

- (void)startTracking
{
	SEL requestPermissions = NSSelectorFromString(@"requestPermissionsIfPossible");
	[Pure performSelector:requestPermissions];
	[Pure startTracking];
}

- (void)stopTracking
{
	[Pure stopTracking];
}

- (BOOL)isTracking
{
	return [Pure isTracking];
}

@end

static IOSWrapper* iosWrapperInstance = nil;

extern "C" {

	void _StartTracking ()
	{
	
  		if (iosWrapperInstance == nil)
			iosWrapperInstance = [[IOSWrapper alloc] init]; 
		
		[iosWrapperInstance startTracking];  
	}
	
    void _StopTracking ()
    {
    
        if (iosWrapperInstance == nil)
            iosWrapperInstance = [[IOSWrapper alloc] init]; 
        
        [iosWrapperInstance stopTracking];  
    }
    
    bool _IsTracking ()
    {
    
        if (iosWrapperInstance == nil)
            iosWrapperInstance = [[IOSWrapper alloc] init]; 
        
        return [iosWrapperInstance isTracking];  
    }
	
}
