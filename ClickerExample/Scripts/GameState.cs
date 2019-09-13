using System;
using System.Collections;
using System.Collections.Generic;
using System.Globalization;
using Unaty.PureSDK;
using UnityEngine;
using UnityEngine.Serialization;

public class GameState : MonoBehaviour
{
    public int credits;
    public int income = 1;
    public int upgradeCost = 10;
    public int nextUpgradeSize = 1;
    public int secondsSincePreviousPlaySession;
    public int secondsPaused;
    public PureSDKComponent tracker;
    public AudioSource sfx;
    public AudioClip upgradeSound;
    [HideInInspector] public int age = -1;
    public GameObject[] removeIfUnderAged;


    public void GainIncome(int times = 1)
    {
        credits += income * times;
    }

    public string GetCreditsForDisplay()
    {
        return GameStateUtil.FormatNumber(this.credits);
    }
    
    public void Upgrade()
    {
        if (credits >= upgradeCost)
        {
            income += nextUpgradeSize;
            nextUpgradeSize *= 2;
            credits -= upgradeCost;
            upgradeCost *= 3;
            sfx.PlayOneShot(upgradeSound);
        }
    }

    public void RegisterAge(int age)
    {
        this.age = age;
        if (!DisplayTrackingFeature())
        {
            foreach (var obj in removeIfUnderAged)
            {
                Destroy(obj);
            }
        }
    }

    public bool DisplayTrackingFeature()
    {
        return IsAgeSubmitted() && age >= 16;
    }

    public bool IsAgeSubmitted()
    {
        return age != -1;
    }

    public bool CanAffordUpgrade()
    {
        return credits >= upgradeCost;
    }

    private void Awake()
    {
        LoadState();
    }

    public bool showTutorial
    {
        get => bool.Parse(PlayerPrefs.GetString("showTutorial", true.ToString()));
        set
        {
            PlayerPrefs.SetString("showTutorial", value.ToString());
            PlayerPrefs.Save();
        }
    }

    private void OnApplicationQuit()
    {
        SaveState();
        PersistShutdownTime();
    }

    private void OnApplicationFocus(bool hasFocus)
    {
        if (hasFocus)
        {
            if (PlayerPrefs.HasKey("lastPause"))
            {
                secondsPaused = (int) (DateTime.Now - DateTime.Parse(PlayerPrefs.GetString("lastPause"))).TotalSeconds;
            }
        }
        else
        {
            SaveOnPause();
        }
    }

    private void LateUpdate()
    {
        secondsPaused = 0;
    }

    private void OnApplicationPause(bool pauseStatus)
    {
        if (!pauseStatus)
        {
            if (PlayerPrefs.HasKey("lastPause"))
            {
                secondsPaused = (int) (DateTime.Now - DateTime.Parse(PlayerPrefs.GetString("lastPause"))).TotalSeconds;
            }

            LoadState();
        }
        else
        {
            SaveOnPause();
        }
    }

    private void OnDisable()
    {
        SaveState();
    }

    private void SaveState()
    {
        PlayerPrefs.SetInt("credits", credits);
        PlayerPrefs.SetInt("income", income);
        PlayerPrefs.SetInt("upgradeCost", upgradeCost);
        PlayerPrefs.SetInt("nextUpgradeSize", nextUpgradeSize);
        PlayerPrefs.SetInt("age", age);
        PlayerPrefs.Save();
    }

    private void PersistShutdownTime()
    {
        PlayerPrefs.SetString("lastShutdown", DateTime.Now.ToString());
    }

    private void SaveOnPause()
    {
        PlayerPrefs.SetString("lastPause", DateTime.Now.ToString());
        SaveState();
    }

    [ContextMenu("Clear Player Preferences")]
    public void ClearPlayerPrefs()
    {
        PlayerPrefs.DeleteAll();
    }

    private void LoadState()
    {
        credits = PlayerPrefs.GetInt("credits", credits);
        upgradeCost = PlayerPrefs.GetInt("upgradeCost", upgradeCost);
        income = PlayerPrefs.GetInt("income", income);
        nextUpgradeSize = PlayerPrefs.GetInt("nextUpgradeSize", nextUpgradeSize);
        LoadAge();

        var now = DateTime.Now;
        var lastShutdown = DateTime.Parse(PlayerPrefs.GetString("lastShutdown", now.ToString()));
        secondsSincePreviousPlaySession = (now - lastShutdown).Seconds;
    }

    private void LoadAge()
    {
        var loadedAge = PlayerPrefs.GetInt("age", this.age);
        if (loadedAge != -1)
        {
            RegisterAge(loadedAge);
        }
    }
}