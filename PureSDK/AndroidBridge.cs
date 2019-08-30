using PureSDK;
using UnityEngine;
using UnityEngine.Android;

namespace Unaty.PureSDK
{
    internal class AndroidBridge : IPureSdk
    {
        private readonly AndroidJavaObject sdk;
        private bool isTracking;
        public AndroidBridge()
        {
#if UNITY_ANDROID
            AndroidJavaClass unityPlayer = new AndroidJavaClass("com.unity3d.player.UnityPlayer");
            AndroidJavaObject activity = unityPlayer.GetStatic<AndroidJavaObject>("currentActivity");
            AndroidJavaObject context = activity.Call<AndroidJavaObject>("getApplicationContext");

            var sdkClass = new AndroidJavaClass("com.pure.sdk.Pure");
            sdk = sdkClass.CallStatic<AndroidJavaObject>("getInstance", context);
            sdk.Call("init","no-publisher-id");
            isTracking = sdk.CallStatic<bool>("getIsTracking");
#endif
        }

        public void StartTracking()
        {
#if UNITY_ANDROID
            if (!Permission.HasUserAuthorizedPermission(Permission.FineLocation))
            {
                Permission.RequestUserPermission(Permission.FineLocation);
            }

            if (Permission.HasUserAuthorizedPermission(Permission.FineLocation))
            {
                Debug.Log("Start tracking");
                sdk.CallStatic("startTracking");
                isTracking = true;
            }
            else
            {
                Debug.Log("User denied location access");
            }
#endif
        }
    
        public void StopTracking()
        {
#if UNITY_ANDROID
            sdk.CallStatic("stopTracking");
#endif
            isTracking = false;
        }

        public bool IsTracking()
        {
            return isTracking;
        }
    }
}
