using PureSDK;
using UnityEngine;

namespace Unaty.PureSDK
{
    public class PureSDK : IPureSdk
    {
        
        private readonly IPureSdk _bridge;

        public PureSDK(string publisherID)
        {
            switch (Application.platform)
            {
                case RuntimePlatform.Android:
                    #if UNITY_ANDROID
                    _bridge = new AndroidBridge(publisherID);
                    #endif
                    break;
                case RuntimePlatform.IPhonePlayer:
                    #if UNITY_IOS
                    _bridge = new IosBridge();
                    #endif
                    break;
                default:
                    Debug.Log("Unacast SDK only available on iOS/Android - unsupported platform [" + Application.platform +
                              "] using mocked functionality.");
                    _bridge = new FakeBridge();
                    break;
            }
        }
        
        /// <summary>
        /// Starts gathering and shipping location data from this device to the Unacast API
        /// Will ask for location permissions if this is the first call to this method from this app.
        /// </summary>
        public void StartTracking()
        {
            _bridge.StartTracking();
        }

        /// <summary>
        /// Stops gathering and shipping location data
        /// </summary>
        public void StopTracking()
        {
            _bridge.StopTracking();
        }

        /// <summary>
        /// Checks whether tracking is turned on
        /// </summary>
        /// <returns>true if tracking is enabled</returns>
        public bool IsTracking()
        {
            return _bridge.IsTracking();
        }
    }
}