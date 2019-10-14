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
    public int rewardedBackgroundTicks;
    public PureSDKComponent tracker;
    public AudioSource sfx;
    public AudioClip upgradeSound;

    public void GainIncome(int incomeSize, int times = 1)
    {
        credits += incomeSize * times;
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
        var totalSecondsSinceLastUpdate = (int) (DateTime.Now - DateTime.Parse(PlayerPrefs.GetString("lastPause"))).TotalSeconds;
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

        var now = DateTime.Now;
        var lastShutdown = DateTime.Parse(PlayerPrefs.GetString("lastShutdown", now.ToString()));
        secondsSincePreviousPlaySession = (now - lastShutdown).Seconds;
    }

}