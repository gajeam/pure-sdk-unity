using System;
using Unaty.PureSDK;
using UnityEngine;

[RequireComponent(typeof(HexEmitter))]
public class LocationIncome : MonoBehaviour
{
    public PureSDKComponent tracking;
    public BackgroundLocationRewardDialog backgroundRewardDialog;

    public float secondsBetweenIncomes = 1;
    private HexEmitter _emitter;

    private float _nextEmission;

    void Start()
    {
        _emitter = GetComponent<HexEmitter>();
        _nextEmission = Time.time + secondsBetweenIncomes;
    }

    //Checks to see if game has been closed while tracking was enabled and awards the corresponding income.
    public int CalculateBackgroundIncome(int seconds, int gameIncome)
    {
        var rewardedSeconds = CalculateRewardedSeconds(seconds);

        if (tracking.IsTracking() && rewardedSeconds > 0)
        {
            backgroundRewardDialog.Show(GameStateUtil.FormatNumber(rewardedSeconds * gameIncome));
            return rewardedSeconds;
        }

        return 0;
    }

    private static int CalculateRewardedSeconds(int seconds)
    {
        if (seconds < 60)
        {
            //Rewarding every 4 seconds 
            return seconds / 4;
        }

        //Rewarding every 4 seconds the first minute(+15), then 1 each minute
        return (seconds - 60) / 60 + 15;
    }

    //Awards income every second while tracking is enabled
    void Update()
    {
        if (!tracking.IsTracking())
        {
            _nextEmission = Time.time + secondsBetweenIncomes;
            return;
        }

        if (Time.time < _nextEmission)
        {
            return;
        }

        _emitter.Emit();
        _nextEmission += secondsBetweenIncomes;
    }
}