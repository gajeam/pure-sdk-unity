using System.IO;
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;
using UnityEditor.iOS.Xcode;
using UnityEditor.iOS.Xcode.Extensions;
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
        FileUtil.CopyFileOrDirectory("Assets/Unaty/Editor/AndroidFiles/mainTemplate.gradle","Assets/Plugins/Android/mainTemplate.gradle");
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
