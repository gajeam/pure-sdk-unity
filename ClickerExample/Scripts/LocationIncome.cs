using System;
using Unaty.PureSDK;
using UnityEngine;

[RequireComponent(typeof(HexEmitter))]
public class LocationIncome : MonoBehaviour
{
    public PureSDKComponent tracking;
    public GameState gameState;
    public BackgroundLocationRewardDialog backgroundRewardDialog;

    public float secondsBetweenIncomes = 1;
    private HexEmitter _emitter;

    private float _nextEmission;

    void Start()
    {
        _emitter = GetComponent<HexEmitter>();
        _nextEmission = Time.time + secondsBetweenIncomes;
    }

    private void OnApplicationFocus(bool hasFocus)
    {
        if (hasFocus)
        {
            var secondsSinceLastPause = gameState.ResetBackgroundSeconds();
            BackgroundIncome(secondsSinceLastPause);
        }
    }

    //Checks to see if game has been closed while tracking was enabled and awards the corresponding income.
    private void BackgroundIncome(int seconds)
    {
        var rewardedSeconds = seconds / 60;
        
        if (tracking.IsTracking() && rewardedSeconds > 0)
        {
            gameState.GainIncome(gameState.income, rewardedSeconds);
            backgroundRewardDialog.Show(GameStateUtil.FormatNumber(rewardedSeconds * gameState.income));
        }
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