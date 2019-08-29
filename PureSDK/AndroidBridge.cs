using PureSDK;
using UnityEngine;
using UnityEngine.Android;

namespace Unaty.PureSDK
{
    internal class AndroidBridge : IPureSdk
    {
        private readonly AndroidJavaClass sdk;
        private bool isTracking;
        public AndroidBridge()
        {
#if UNITY_ANDROID
            sdk = new AndroidJavaClass("com.pure.sdk.Pure");
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
