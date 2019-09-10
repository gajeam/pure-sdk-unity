using PureSDK;
using UnityEngine;

namespace Unaty.PureSDK
{
    public class PureSDKComponent : MonoBehaviour, IPureSdk
    {
        private PureSDK sdk;

        void Awake()
        {
            Init();
        }

        private void Init()
        {
            sdk = new PureSDK();
        }

        public void StartTracking()
        {
            Debug.Log("Start tracking");
            sdk.StartTracking();
        }

        public void StopTracking()
        {
            Debug.Log("Stop tracking");
            sdk.StopTracking();
        }

        public bool IsTracking()
        {
            return sdk.IsTracking();
        }
    }
}