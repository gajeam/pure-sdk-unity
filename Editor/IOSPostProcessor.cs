using PureSDK;
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;

#if UNITY_IOS
using System.IO;
using UnityEditor.iOS.Xcode;
using UnityEngine;

#endif

public class IOSPostProcessor : IPostprocessBuildWithReport
{
    public int callbackOrder { get; }

    public void OnPostprocessBuild(BuildReport report)
    {
        if (report.summary.platform == BuildTarget.iOS)
        {
#if UNITY_IOS
            AddPlistEntries(report);
            AddShellScriptBuildPhase(report);
#endif
        }
    }
#if UNITY_IOS
    private void AddShellScriptBuildPhase(BuildReport report)
    {
        var pathToBuiltProject = report.summary.outputPath;
        string projPath = PBXProject.GetPBXProjectPath(report.summary.outputPath);

        PBXProject proj = new PBXProject();
        proj.ReadFromString(File.ReadAllText(projPath));

        proj.InsertShellScriptBuildPhase(100, proj.TargetGuidByName("Unity-iPhone"),
            "Strip Invalid Archs",
            "/bin/sh",
            "bash \"${BUILT_PRODUCTS_DIR}/${FRAMEWORKS_FOLDER_PATH}/PureSDK.framework/strip-frameworks.sh\"");
        proj.WriteToFile(projPath);
    }

    private void AddPlistEntries(BuildReport report)
    {
        var plistPath = GetPlistPath(report);
        var plist = new PlistDocument();
        plist.ReadFromFile(plistPath);
        var rootDict = plist.root;

        SetPlistKey(rootDict, "PURPublisherId", PureSDKSettingsEditor.GetOrCreateSettings().publisherID);
        
        if (!PureSDKSettingsEditor.GetOrCreateSettings().generateLocationPlistEntries)
        {
            WarnIfMissing(rootDict, "NSLocationWhenInUseUsageDescription");
            WarnIfMissing(rootDict, "NSLocationAlwaysUsageDescription");
            WarnIfMissing(rootDict, "NSLocationWhenInUseUsageDescription");
            return;
        }

        var locationUsageDescription = PlayerSettings.iOS.locationUsageDescription;
        if (locationUsageDescription == null || locationUsageDescription.Trim() == "")
        {
            Debug.LogWarning(
                "Location Usage Description is blank. Make sure you give your users a good description of why you are asking for Location!");
        }

        SetPlistKey(rootDict, "NSLocationWhenInUseUsageDescription", locationUsageDescription);
        SetPlistKey(rootDict, "NSLocationAlwaysUsageDescription", locationUsageDescription);
        SetPlistKey(rootDict, "NSLocationAlwaysAndWhenInUseUsageDescription", locationUsageDescription);

        // Write to file
        File.WriteAllText(plistPath, plist.WriteToString());
    }

    private static void WarnIfMissing(PlistElementDict rootDict, string key)
    {
        if (rootDict[key] == null)
        {
            Debug.LogWarning(
                key +
                " not defined in Info.plist and Entry generation for Unacast Pure SDK is disabled. Please ensure you XCode project is configured correctly before deploying your application.");
        }
    }

    private static string GetPlistPath(BuildReport report)
    {
        var pathToBuiltProject = report.summary.outputPath;
        string projPath = PBXProject.GetPBXProjectPath(report.summary.outputPath);

        PBXProject proj = new PBXProject();
        proj.ReadFromString(File.ReadAllText(projPath));

        var plistPath = pathToBuiltProject + "/Info.plist";
        return plistPath;
    }

    private static void SetPlistKey(PlistElementDict rootDict, string key, string value)
    {
        if (rootDict[key] != null && rootDict[key].AsString() != value)
        {
            Debug.LogWarning("Existing [" + key + "] in Info.plist with value:\n  " +
                             rootDict[key].AsString() +
                             "\noverridden by Unacast Pure SDK using text: \n  " + value + "\n" +
                             "If this was unintended, disable this option under \"Unacast Pure SDK > Configure Project > iOS > Information Property List Entries ...\"");
        }

        rootDict.SetString(key, value);
    }
#endif
}