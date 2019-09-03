using System.IO;
using UnityEditor;
using UnityEngine;

public class AndroidMenu
{
    
    [MenuItem("Unacast Pure SDK/Configure Project/Android/Create mainTemplate.gradle")]
    static void AddAndroidFiles()
    {
        copyGradleFile();
        AssetDatabase.Refresh();
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

   
}
