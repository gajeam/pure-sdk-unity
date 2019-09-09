using System;
using System.Collections;
using System.Collections.Generic;
using Unaty.PureSDK;
using UnityEngine;
using UnityEngine.Serialization;

public class GameState : MonoBehaviour
{
    public bool clearPlayerPrefsOnStartup = false;
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
        get
        {
            if (!PlayerPrefs.HasKey("showTutorial"))
            {
                PlayerPrefs.SetString("showTutorial", true.ToString());
            }

            return bool.Parse(PlayerPrefs.GetString("showTutorial"));
        }
        set
        {
            PlayerPrefs.SetString("showTutorial", value.ToString());
            PlayerPrefs.Save();
        }
    }

    private void OnApplicationQuit()
    {
        SaveState();
        SaveOnShutdown();
    }

    private void OnApplicationFocus(bool hasFocus)
    {
        if (hasFocus)
        {
            if (PlayerPrefs.HasKey("lastPause"))
            {
                secondsPaused = (DateTime.Now - DateTime.Parse(PlayerPrefs.GetString("lastPause"))).Seconds;
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
        SaveState();
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

    private static void SaveOnShutdown()
    {
        PlayerPrefs.SetString("lastShutdown", DateTime.Now.ToString());
    }

    private static void SaveOnPause()
    {
        PlayerPrefs.SetString("lastPause", DateTime.Now.ToString());
    }

    [ContextMenu("Clear Player Preferences")]
    public void ClearPlayerPrefs()
    {
        PlayerPrefs.DeleteAll();
    }
    
    private void LoadState()
    {
        if (clearPlayerPrefsOnStartup)
        {
            PlayerPrefs.DeleteAll();
        }

        if (PlayerPrefs.HasKey("credits"))
        {
            credits = PlayerPrefs.GetInt("credits");
        }

        if (PlayerPrefs.HasKey("upgradeCost"))
        {
            upgradeCost = PlayerPrefs.GetInt("upgradeCost");
        }

        if (PlayerPrefs.HasKey("income"))
        {
            income = PlayerPrefs.GetInt("income");
        }
        
        if (PlayerPrefs.HasKey("age"))
        {
            var age = PlayerPrefs.GetInt("age");
            RegisterAge(age);
        }

        if (PlayerPrefs.HasKey("nextUpgradeSize"))
        {
            nextUpgradeSize = PlayerPrefs.GetInt("nextUpgradeSize");
        }

        if (PlayerPrefs.HasKey("lastShutdown"))
        {
            secondsSincePreviousPlaySession =
                (DateTime.Now - DateTime.Parse(PlayerPrefs.GetString("lastShutdown"))).Seconds;
        }
    }
}