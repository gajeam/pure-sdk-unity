using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using Unaty.PureSDK;
using UnityEngine;
using UnityEngine.Serialization;
using Debug = UnityEngine.Debug;

public class GameState : MonoBehaviour
{
    public int credits;
    public int income = 1;
    public int level = 1;
    private int nrOfUpgrades = 0;
    public int upgradeCost = 10;
    public int nextUpgradeSize = 1;
    private int _backgroundSeconds = 0;
    public PureSDKComponent tracker;
    public AudioSource sfx;
    public AudioClip upgradeSound;
    public ParticleSystem upgradeEffect;
    public ParticleSystem levelEffect;
    public LevelUpScript levelUpDialog;
    public AudioClip levelUpSound;

    public Material skybox2;
    public Material skybox3;
    public Material skybox4;
    public Material skybox5;
    public Material skybox6;
    public Material skybox7;
    public Material skybox8;
    public Material skybox9;
    public Material skybox10;

    public static int upgradesToReachLevel = 5;

    public void GainIncome(int incomeSize, int times = 1)
    {
        credits += incomeSize * times;
    }

    public string GetCreditsForDisplay()
    {
        return GameStateUtil.FormatNumber(this.credits);
    }

    public int GetNrToNextUpgrade()
    {
        return nrOfUpgrades;
    }

    public void Upgrade()
    {
        if (credits >= upgradeCost)
        {
            income += nextUpgradeSize;
            nextUpgradeSize *= 2;
            credits -= upgradeCost;
            upgradeCost *= 3;
            nrOfUpgrades += 1;

            if (GetNrToNextUpgrade() == upgradesToReachLevel)
            {
                nrOfUpgrades = 0;
                level += 1;
                levelEffect.Play();
                sfx.PlayOneShot(levelUpSound);
                var dialogText = ChangesForLevel();
                levelUpDialog.DisplayLevelUpDialog(dialogText);
            }
            else
            {
                sfx.PlayOneShot(upgradeSound);
                upgradeEffect.Play();
            }
        }
    }

    private string ChangesForLevel()
    {
        switch (level)
        {
            case 2:
                RenderSettings.skybox = skybox2;
                return "Amazing!!! You clicked your way to level " + level + "!";
            case 3:
                RenderSettings.skybox = skybox3;
                return "You are clicking it!!! Please enter level " + level + "!";
            case 4:
                RenderSettings.skybox = skybox4;
                return "LEVEL " + level + "!!! Click, click, click ... ";
            case 5:
                RenderSettings.skybox = skybox5;
                return "Your clicking skills earned you entrance to level " + level + "!!!";
            case 6:
                RenderSettings.skybox = skybox6;
                return "You are now royal clicker champ, do your best at level " + level + ".";
            case 7:
                RenderSettings.skybox = skybox7;
                return "Level " + level + " is reached!!!";
            case 8:
                RenderSettings.skybox = skybox8;
                return "Clickastic this is fantastic! Proceed to level " + level + "!";
            case 9:
                RenderSettings.skybox = skybox9;
                return "I ran out of stupid things to say, but you reached level " + level + "!";
            case 10:
                RenderSettings.skybox = skybox10;
                return "You reached the final level, you are now king or queen of clicking!";
                break;
            default:
                Debug.Log("Reached level " + level + " no new skyboxes available");
                return "Congratulations you reached level " + level + "!!!";
        }
    }

    public bool CanAffordUpgrade()
    {
        return credits >= upgradeCost;
    }

    private void Awake()
    {
        LoadState();
        ChangesForLevel();
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

    public int ResetBackgroundSeconds()
    {
        var tempBackgroundSeconds = _backgroundSeconds;
        _backgroundSeconds = 0;
        return tempBackgroundSeconds;
    }

    private void OnApplicationFocus(bool hasFocus)
    {
        if (hasFocus)
        {
            LoadState();
        }
        else
        {
            SaveOnPause();
        }
    }

    private static int CalculateBackgroundIncomeTicks(string dateTimeLastRegistration)
    {
        return (int) (DateTime.Now - DateTime.Parse(dateTimeLastRegistration)).TotalSeconds;
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
        PlayerPrefs.SetInt("level", level);
        PlayerPrefs.SetInt("nrOfUpgrades", nrOfUpgrades);
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
        nrOfUpgrades = PlayerPrefs.GetInt("nrOfUpgrades", nrOfUpgrades);
        level = PlayerPrefs.GetInt("level", level);

        LoadBackgroundIncome();
    }

    private void LoadBackgroundIncome()
    {
        int incomeFromShutDown = 0;
        if (PlayerPrefs.HasKey("lastShutdown"))
        {
            incomeFromShutDown = CalculateBackgroundIncomeTicks(PlayerPrefs.GetString("lastShutdown"));
            PlayerPrefs.DeleteKey("lastShutdown");
        }

        int incomeFromPause = 0;
        if (PlayerPrefs.HasKey("lastPause"))
        {
            incomeFromPause = CalculateBackgroundIncomeTicks(PlayerPrefs.GetString("lastPause"));
            PlayerPrefs.DeleteKey("lastPause");
        }

        if (incomeFromPause > 0 || incomeFromShutDown > 0)
        {
            if (incomeFromPause > incomeFromShutDown)
            {
                _backgroundSeconds = incomeFromPause;
            }
            else
            {
                _backgroundSeconds = incomeFromShutDown;
            }
        }
    }
}