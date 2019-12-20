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
    
    public IosBridge()
    {
        #if UNITY_IOS
        _isTracking = _IsTracking();
        Debug.Log("Checking the SDK if we are tracking. SDK reports isTracking = " + _isTracking);
        #endif
    }

    public void StartTracking()
    {
        Debug.Log("Start tracking");
        #if UNITY_IOS
        _StartTracking();
        _isTracking = true;
        Debug.Log("Start tracking setting tracking = " + _isTracking);
        #endif
    }
    
    public void StopTracking()
    {
        #if UNITY_IOS
        _StopTracking();
        _isTracking = false;
        Debug.Log("Stop tracking setting tracking = " + _isTracking);
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