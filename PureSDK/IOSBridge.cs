using System.Collections;
using System.Linq;
using System.Runtime.InteropServices;
using PureSDK;
using UnityEngine;

internal class IosBridge : IPureSdk
{
    #if UNITY_IOS
    [DllImport("__Internal")]
    private static extern void _StartTracking();

    [DllImport("__Internal")]
    private static extern void _StopTracking();

    [DllImport("__Internal")]
    private static extern bool _IsTracking();

    [DllImport("__Internal")]
    private static extern void _SetPublisherID(string publisherId);

    #endif
    
    private bool _isTracking;
    
    public IosBridge(string publisherId)
    {
        #if UNITY_IOS
        Debug.Log("Setting publisher ID to " + publisherId);
        _SetPublisherID(publisherId);
        _isTracking = _IsTracking();
        #endif
    }

    public void StartTracking()
    {
        Debug.Log("Start tracking");
        #if UNITY_IOS
        _StartTracking();
        _isTracking = true;
        #endif
    }
    
    public void StopTracking()
    {
        #if UNITY_IOS
        Debug.Log("Stop tracking");
        _StopTracking();
        _isTracking = false;
        #endif
    }

    public bool IsTracking()
    {
        #if UNITY_IOS
        return _isTracking;
        #endif
        #if !UNITY_IOS
        return false;
        #endif

    }
}