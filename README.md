# Unacast Pure SDK Unity SDK
**IMPORTANT: This asset is only useful if you are a registered data partner of Unacast Inc.**

This asset contains Unacast's Pure SDK, along with example code showing how to use the SDK. 

## Install

### Git submodule
    
### Manual copy

## Update

### Git submodule

### Manual copy

## Usage
To use the Unacast you must first [register as a Unacast Data Partner](https://unacastssp.itera-research.com).

### Quick ref

```csharp
using Unaty.PureSDK;
using UnityEngine;

public class ExampleBehaviour : MonoBehaviour
{
    public PureSDKBridge sdk; 
    
    public void DummyUsage()
    {
        sdk.isTracking() // false
        
        // Start tracking and shipping of location data (if user accepts system dialog)
        sdk.startTracking()
        
        sdk.isTracking() // true
        
        // Stop tracking and sending of location data
        sdk.stopTracking() 
        
        sdk.isTracking() // false
    } 
}
```

The `PureSDKBridge` class exposes three functions.

### `startTracking()`
This function start location tracking and shipping of data to the Unacast APIs from the device. If the user has not (yet) accepted 
location usage for the application, a system dialog will be shown, asking permission.

### `stopTracking()`
Stops tracking and sending data to the Unacast APIs. 

### `isTracking()`
Returns `true` if the user has accepted location tracking.

## Folder Structure
Below is a description of the structure and contents of this asset.

### ClickerExample
An example application demonstrating use of the Unacast Pure SDK. 
Open the scene `ClickerExample/UnacastClicker` to test the application.

### Editor
Scripts adding helper functionality to the Unity editor to make it easier to use the SDK.

### Frameworks
The PureSDK code used when building applications targeting iOS.
When building for Android, the SDK is downloaded as part of the Gradle build.

### PureSDK
C# source code the Unacast Pure Unity SDK.
