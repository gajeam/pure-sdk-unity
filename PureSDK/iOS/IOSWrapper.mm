
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

- (void)setPublisherId:(NSString *) id
{
	Pure.publisherId = id;
}

@end

static IOSWrapper* iosWrapperInstance = nil;

// Converts C style string to NSString
NSString* CreateNSString (const char* string)
{
	if (string)
	return [NSString stringWithUTF8String: string];
	else
	return [NSString stringWithUTF8String: ""];
}

extern "C" {

	void _SetPublisherID (const char* publisherID)
	{
		if (iosWrapperInstance == nil)
			iosWrapperInstance = [[IOSWrapper alloc] init];
		
		[iosWrapperInstance setPublisherId: CreateNSString(publisherID)];
	}

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
