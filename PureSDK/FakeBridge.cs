using PureSDK;
using UnityEngine;

namespace Unaty.PureSDK
{
    internal class FakeBridge : IPureSdk
    {

        public void StartTracking()
        {
            PlayerPrefs.SetInt("mockedIsTracking", 1);
        }

        public void StopTracking()
        {
            PlayerPrefs.SetInt("mockedIsTracking", 0);
        }

        public bool IsTracking()
        {
            return PlayerPrefs.GetInt("mockedIsTracking") == 1;
        }
    }
}