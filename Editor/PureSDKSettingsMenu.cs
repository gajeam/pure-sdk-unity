
using System.Collections.Generic;
using System.IO;
using PureSDK;
using UnityEditor;
using UnityEngine;
using UnityEngine.UIElements;

class PureSDKSettingsMenu : SettingsProvider
{
    private const string SettingsMenuPath = "Project/Pure SDK";
    private PureSDKSettings settings;

    private int tab;

    public PureSDKSettingsMenu(string path, SettingsScope scope = SettingsScope.User)
        : base(path, scope) {}

    public override void OnActivate(string searchContext, VisualElement rootElement)
    {
        // This function is called when the user clicks on the MyCustom element in the Settings window.
        settings = PureSDKSettingsEditor.GetOrCreateSettings();
    }

    public override void OnDeactivate()
    {
        AssetDatabase.SaveAssets();
    }
    public override void OnGUI(string searchContext)
    {
        GUILayout.Label("Pure SDK Configuration", EditorStyles.boldLabel);
        EditorGUILayout.HelpBox(
            "PublisherID is the ID that ties the location data to you as a publisher. Get your publisherID by registrating to the Unacast Self-service platform",
            MessageType.Info);
        settings.publisherID = EditorGUILayout.TextField("PublisherID", settings.publisherID);
        GUILayout.Space(20);
        
        tab = GUILayout.Toolbar(tab, new[]{"iOS","Android"});

        switch (tab)
        {
            case 0: 
                iOSMenu();
                break;
            case 1:
                AndroidMenu();
                break;
            default:
                iOSMenu();
                break;
        }

//        AssetDatabase.SaveAssets();
    }
    
      private void iOSMenu()
    {
        EditorStyles.textArea.wordWrap = true;
        GUILayout.Label("Background location information", EditorStyles.boldLabel);
        EditorGUILayout.HelpBox(
            "For the Unacast Pure SDK to be able to work on iOS, three keys needs to be added to the Information Property List.\n\n" +
            "Checking \"Genereate entries on build\" will add/override the needed keys:\n - NSLocationWhenInUseUsageDescription\n - NSLocationAlwaysUsageDescription\n - NSLocationAlwaysAndWhenInUseUsageDescription\n" +
            "using the Location Usage Description from your player settings.", MessageType.Info);
        settings.generateLocationPlistEntries =
            EditorGUILayout.ToggleLeft("Generate location usage entries on build", settings.generateLocationPlistEntries);

        if (settings.generateLocationPlistEntries)
        {
            EditorGUILayout.LabelField("Location Usage Description (updates your player settings):");
            PlayerSettings.iOS.locationUsageDescription = EditorGUILayout.TextArea(
                PlayerSettings.iOS.locationUsageDescription, EditorStyles.textArea, GUILayout.Height(60));
            EditorGUILayout.HelpBox(
                "If you already define all or some of these PList entries elsewhere, you should handle this by editing your .plist files directly.",
                MessageType.Warning);
        }   
    }

    private void AndroidMenu()
    {
        GUILayout.Label("Generate custom gradle file", EditorStyles.boldLabel);
        EditorGUILayout.HelpBox("Pure SDK needs to be added as a dependency to the project. This is done by adding a dependency to the gradle-file used when building the project. " +
                                "If you do not already have a mainTemplate.gradle file in your project, you can click below to generate one with the needed dependencies already added.",MessageType.Info);
        var btn = GUILayout.Button("Generate mainTemplate.gradle", GUILayout.Width(300));
        if (btn)
        {
            copyGradleFile();
        }
    }
    
    private static void copyGradleFile()
    {
        var targetUnderAssets = "/Plugins/Android/mainTemplate.gradle";
        var targetPath = "Assets"+targetUnderAssets;
        if (File.Exists(Application.dataPath + targetUnderAssets))
        {
            EditorUtility.DisplayDialog("Custom gradle file already exists in project",
                "File already exists:\n" + 
                targetPath + 
                "\n\n" +
                "Did you already do this?\n" +
                "If not, please see refer to readme on how to add needed dependencies manually.", 
                "Ok, I will do it manually.");
            return;
        }

        var pathOfFolder = Application.dataPath + "/Plugins/Android";
        if (!Directory.Exists(pathOfFolder))
        {
            Directory.CreateDirectory(pathOfFolder);
            Debug.Log(pathOfFolder + " created");
        }
        
        var pathToGradleFile = AssetDatabase.GUIDToAssetPath(AssetDatabase.FindAssets("puresdk_mainTemplate")[0]);
        Debug.Log("Created "+targetPath);
        FileUtil.CopyFileOrDirectory(pathToGradleFile,targetPath);
        
        AssetDatabase.Refresh();
    }

    
    // Register the SettingsProvider
    [SettingsProvider]
    public static SettingsProvider Create()
    {
        var provider = new PureSDKSettingsMenu(SettingsMenuPath, SettingsScope.Project)
        {
            keywords = new HashSet<string>(new[]
            {
                "SDK", "Pure", "PublisherID", "mainTemplate", "gradle", "NSLocationWhenInUseUsageDescription",
                "NSLocationAlwaysUsageDescription", "NSLocationAlwaysAndWhenInUseUsageDescription"
            })
        };

        return provider;

    }
    
    [MenuItem("Window/Unacast Pure SDK/Configure ...")]
    static void OpenSettings()
    {
        // Get existing open window or if none, make a new one:
        SettingsService.OpenProjectSettings(SettingsMenuPath);
    }
}