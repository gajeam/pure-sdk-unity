using UnityEditor;
using UnityEngine;

public class IOSMenu : EditorWindow
{
    private const string IOSPostProcessingMenuPath = "Unacast Pure SDK/Configure Project/iOS/Information Property List Entries ...";

    
    [MenuItem(IOSPostProcessingMenuPath)]
    static void Init()
    {
        // Get existing open window or if none, make a new one:
        IOSMenu window = (IOSMenu)GetWindow(typeof(IOSMenu), false, "iOS - Override PList Entries", true);
        window.Show();
    }
    
    void OnGUI()
    {
        EditorStyles.textArea.wordWrap = true;
        GUILayout.Label("Override PList Entries", EditorStyles.boldLabel);
        EditorGUILayout.HelpBox("For the Unacast Pure SDK to be able to work on iOS, three keys needs to be added to the Information Property List.\n\n" +
                                "Checking \"Genereate entries on build\" this will add/override the needed keys:\n NSLocationWhenInUseUsageDescription\n NSLocationAlwaysUsageDescription\n NSLocationAlwaysAndWhenInUseUsageDescription ", MessageType.Info);

        IOSPostProcessor.generatePlistEntries = EditorGUILayout.ToggleLeft("Generate entries on build", IOSPostProcessor.generatePlistEntries);
        

        if (IOSPostProcessor.generatePlistEntries)
        {
            EditorGUILayout.LabelField("Usage Description (shared for all 3 entries):");
            IOSPostProcessor.usageDescription = EditorGUILayout.TextArea(IOSPostProcessor.usageDescription, EditorStyles.textArea, GUILayout.Height(60));
            EditorGUILayout.HelpBox("If you already define all or some of these PList entries elsewhere, you should handle this manually by editing your .plist files directly in XCode.", MessageType.Warning);
        }
    }
}
