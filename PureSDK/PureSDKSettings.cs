using UnityEngine;

namespace PureSDK
{
    public class PureSDKSettings : ScriptableObject
    {
        private const string resourceName = "PureSDK/PureSDKSettings";
        public const string settingsPath = "Assets/Resources/" + resourceName + ".asset";

        [SerializeField] public string publisherID;

        [SerializeField] public bool generateLocationPlistEntries;

        public static PureSDKSettings ReadOnlyCopy()
        {
            var pureSdkSettings = Resources.Load<PureSDKSettings>(resourceName);
            return Instantiate(pureSdkSettings);
        }
    }
}