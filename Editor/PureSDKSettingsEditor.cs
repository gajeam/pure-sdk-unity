using System.IO;
using UnityEditor;
using UnityEngine;

namespace PureSDK
{
    public class PureSDKSettingsEditor : ScriptableObject
    {

        public static PureSDKSettings GetOrCreateSettings()
        {
            var settingsPath = PureSDKSettings.settingsPath;
            var settings = AssetDatabase.LoadAssetAtPath<PureSDKSettings>(settingsPath);
            if (settings == null)
            {
                
                Directory.CreateDirectory(Path.GetDirectoryName(settingsPath));
                settings = CreateInstance<PureSDKSettings>();
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