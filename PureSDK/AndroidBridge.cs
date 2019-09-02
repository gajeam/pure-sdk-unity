using System;
using PureSDK;
using UnityEngine;
using UnityEngine.Android;

namespace Unaty.PureSDK
{
    internal class AndroidBridge : IPureSdk
    {
        private readonly AndroidJavaObject sdk;
        private bool isTracking;

        private bool _waitingForUserToAcceptLocation;
        public AndroidBridge(String publisherId)
        {
#if UNITY_ANDROID
            var unityPlayer = new AndroidJavaClass("com.unity3d.player.UnityPlayer");
            var activity = unityPlayer.GetStatic<AndroidJavaObject>("currentActivity");
            var context = activity.Call<AndroidJavaObject>("getApplicationContext");

            var sdkClass = new AndroidJavaClass("com.pure.sdk.Pure");
            sdk = sdkClass.CallStatic<AndroidJavaObject>("getInstance", context);
            sdk.Call("init",publisherId, null);
            isTracking = sdk.Call<bool>("isTracking");
#endif
        }

        public void StartTracking()
        {
#if UNITY_ANDROID
            if (!Permission.HasUserAuthorizedPermission(Permission.FineLocation))
            {
                Permission.RequestUserPermission(Permission.FineLocation);
                _waitingForUserToAcceptLocation = true;
            }

            Debug.Log("Start tracking");
            sdk.Call("startTracking");
            isTracking = true;
#endif
        }
    
        public void StopTracking()
        {
#if UNITY_ANDROID
            sdk.Call("stopTracking");
#endif
            isTracking = false;
        }

        public bool IsTracking()
        {
            if (isTracking && _waitingForUserToAcceptLocation)
            {
                _waitingForUserToAcceptLocation = !Permission.HasUserAuthorizedPermission(Permission.FineLocation);
            }
            return isTracking && !_waitingForUserToAcceptLocation;
        }
    }
}
