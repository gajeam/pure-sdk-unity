using System.IO;
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;
using UnityEditor.iOS.Xcode;
using UnityEngine;

public class UnatyHelpers : IPostprocessBuildWithReport
{

    [MenuItem("Unaty/Android/Create Files")]
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
            Debug.LogError("File already exists: "+targetPath);
            Debug.Log("Please see refer to readme on how to add needed dependencies manually.");
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

    public int callbackOrder { get; }
    public void OnPostprocessBuild(BuildReport report)
    {
        if (report.summary.platform == BuildTarget.iOS) {
            processIOS(report);
        }
    }

    private void processIOS(BuildReport report)
    {
        var pathToBuiltProject = report.summary.outputPath;
        string projPath = PBXProject.GetPBXProjectPath(report.summary.outputPath);

        PBXProject proj = new PBXProject ();
        proj.ReadFromString (File.ReadAllText (projPath));
        string target = proj.TargetGuidByName ("Unity-iPhone");
        
        var plist = new PlistDocument();
        var plistPath = pathToBuiltProject+"/Info.plist";
        plist.ReadFromFile(plistPath);
        PlistElementDict rootDict = plist.root;
        
        rootDict.SetString("NSLocationWhenInUseUsageDescription","We'll show you interesting things around you.");
        rootDict.SetString("NSLocationAlwaysUsageDescription","We'll show you interesting things around you.");
        rootDict.SetString("NSLocationAlwaysAndWhenInUseUsageDescription","We'll show you interesting things around you.");
       
        // Write to file
        File.WriteAllText(plistPath, plist.WriteToString());
    } 
}
