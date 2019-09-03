using System;
using System.IO;
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;
using UnityEditor.iOS.Xcode;
using UnityEngine;

public class IOSPostProcessor : IPostprocessBuildWithReport
{
    public static bool generatePlistEntries = false;

    public static string usageDescription =
        "By allowing us to collect this information, you earn income every second, even when not playing!";

    public int callbackOrder { get; }

    public void OnPostprocessBuild(BuildReport report)
    {
        if (report.summary.platform == BuildTarget.iOS)
        {
            AddPlistEntries(report);
        }
    }

    private void AddPlistEntries(BuildReport report)
    {

        var plistPath = GetPlistPath(report);
        var plist = new PlistDocument();
        plist.ReadFromFile(plistPath);
        var rootDict = plist.root;

        if (!generatePlistEntries)
        {
            WarnIfMissing(rootDict, "NSLocationWhenInUseUsageDescription");
            WarnIfMissing(rootDict, "NSLocationAlwaysUsageDescription");
            WarnIfMissing(rootDict, "NSLocationWhenInUseUsageDescription");
            return;
        }

        SetPlistKey(rootDict, "NSLocationWhenInUseUsageDescription", usageDescription);
        SetPlistKey(rootDict, "NSLocationAlwaysUsageDescription", usageDescription);
        SetPlistKey(rootDict, "NSLocationAlwaysAndWhenInUseUsageDescription", usageDescription);

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
            Debug.LogWarning("Existing ["+key+"] in Info.plist with value:\n  " +
                             rootDict[key].AsString() +
                             "\noverridden by Unacast Pure SDK using text: \n  " + value + "\n" +
                             "If this was unintended, disable this option under \"Unacast Pure SDK > Configure Project > iOS > Information Property List Entries ...\"");
        }

        rootDict.SetString(key, value);
    }
}