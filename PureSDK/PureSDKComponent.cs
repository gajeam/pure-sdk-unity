﻿using PureSDK;
using UnityEngine;

namespace Unaty.PureSDK
{
    public class PureSDKComponent : MonoBehaviour, IPureSdk
    {

        [Header("Your Unacast SSP Publisher ID")]
        [Tooltip("Your publisher ID, as defined in the Unacast SSP")]
        public string publishedID;

        private PureSDK sdk;

        void Awake()
        {
            Init();
        }

        private void Init()
        {
            sdk = new PureSDK(publishedID);
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