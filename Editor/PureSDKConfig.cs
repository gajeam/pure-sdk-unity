using System.IO;
using UnityEditor;
using UnityEngine;

namespace PureSDK
{
    public class PureSDKConfig : ScriptableObject
    {
        private const string settingsPath = "Assets/Editor/PureSDKSettings.asset";

        [SerializeField] 
        public string publisherID;

        [SerializeField]
        public bool generateLocationPlistEntries;

        public static PureSDKConfig GetOrCreateSettings()
        {
            var settings = AssetDatabase.LoadAssetAtPath<PureSDKConfig>(settingsPath);
            if (settings == null)
            {
                
                Directory.CreateDirectory(Path.GetDirectoryName(settingsPath));
                settings = CreateInstance<PureSDKConfig>();
                settings.generateLocationPlistEntries = true;
                
                AssetDatabase.CreateAsset(settings, settingsPath);
                AssetDatabase.SaveAssets();
            }
            return settings;
        }

        public static SerializedObject GetSerializedSettings()
        {
            return new SerializedObject(GetOrCreateSettings());
        }
    }
}