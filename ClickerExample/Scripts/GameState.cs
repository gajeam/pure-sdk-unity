using System;
using System.Collections;
using System.Collections.Generic;
using Unaty.PureSDK;
using UnityEngine;

public class GameState : MonoBehaviour
{
    public bool clearPlayerPrefsOnStartup = false;
    public int credits;
    public int income = 1;
    public int upgradeCost = 10;
    public int nextUpgradeSize = 1;
    public PureSDKComponent tracker;
    
    public void GainIncome()
    {
        credits += income;
    }

    public void Upgrade()
    {
        if (credits >= upgradeCost)
        {
            income += nextUpgradeSize;
            nextUpgradeSize *= 2;
            credits -= upgradeCost;
            upgradeCost *= 3;
        }
        
    }

    public bool CanAffordUpgrade()
    {
        return credits >= upgradeCost;
    }

    private void Start()
    {
        if (clearPlayerPrefsOnStartup)
        {
            PlayerPrefs.DeleteAll();
        }
        
        if (PlayerPrefs.HasKey("credits"))
        {
            var savedCredits = PlayerPrefs.GetInt("credits");
            credits = savedCredits;
        }

        if (tracker.IsTracking())
        {
            if (PlayerPrefs.HasKey("lastShutdown"))
            {
                var lastShutdownTimeStr = PlayerPrefs.GetString("lastShutdown");
                var lastShutdownTime = DateTime.Parse(lastShutdownTimeStr);
                var secondsSinceLastShutdown = (DateTime.Now - lastShutdownTime).Seconds;
                credits += income * secondsSinceLastShutdown;
            }
        }
        
    }

    private void OnApplicationQuit()
    {
        PlayerPrefs.SetInt("credits",credits);
        PlayerPrefs.SetString("lastShutdown",DateTime.Now.ToString());
    }
    
}
