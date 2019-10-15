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
    public int secondsSincePreviousPlaySession;
    public int rewardedBackgroundTicks;
    public PureSDKComponent tracker;
    public AudioSource sfx;
    public AudioClip upgradeSound;
    public ParticleSystem upgradeEffect;
    
    public ParticleSystem levelEffect;

    public Material skybox2;
    public Material skybox3;
    public Material skybox4;
    public Material skybox5;
    public Material skybox6;
    public Material skybox7;
    public Material skybox8;
    public Material skybox9;
    public Material skybox10;


    public static int upgradesToReachLevel = 2;

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
                Debug.Log("Reached new level!");
                nrOfUpgrades = 0;
                level += 1;
                levelEffect.Play();
                ChangesForLevel();
            }
            else
            {
                sfx.PlayOneShot(upgradeSound);
                upgradeEffect.Play();
            }
        }
    }

    private void ChangesForLevel()
    {
        switch (level)
        {
            case 2:
                RenderSettings.skybox = skybox2;
                break;
            case 3:
                RenderSettings.skybox = skybox3;
                break;
            case 4:
                RenderSettings.skybox = skybox4;
                break;
            case 5:
                RenderSettings.skybox = skybox5;
                break;
            case 6:
                RenderSettings.skybox = skybox6;
                break;
            case 7:
                RenderSettings.skybox = skybox7;
                break;
            case 8:
                RenderSettings.skybox = skybox8;
                break;
            case 9:
                RenderSettings.skybox = skybox9;
                break;
            case 10:
                RenderSettings.skybox = skybox10;
                break;
            default:
                Debug.Log("Reached level " + level + " no new skyboxes available");
                break;
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

    private void OnApplicationFocus(bool hasFocus)
    {
        if (hasFocus)
        {
            if (PlayerPrefs.HasKey("lastPause"))
            {
                rewardedBackgroundTicks = CalculateBackgroundIncomeTicks();
            }
        }
        else
        {
            SaveOnPause();
        }
    }

    private static int CalculateBackgroundIncomeTicks()
    {
        var totalSecondsSinceLastUpdate =
            (int) (DateTime.Now - DateTime.Parse(PlayerPrefs.GetString("lastPause"))).TotalSeconds;
        var addedBackgroundReward = totalSecondsSinceLastUpdate / 10;

        return addedBackgroundReward;
    }

    private void LateUpdate()
    {
        rewardedBackgroundTicks = 0;
    }

    private void OnApplicationPause(bool pauseStatus)
    {
        if (!pauseStatus)
        {
            if (PlayerPrefs.HasKey("lastPause"))
            {
                rewardedBackgroundTicks = CalculateBackgroundIncomeTicks();
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

        var now = DateTime.Now;
        var lastShutdown = DateTime.Parse(PlayerPrefs.GetString("lastShutdown", now.ToString()));
        secondsSincePreviousPlaySession = (now - lastShutdown).Seconds;
    }
}