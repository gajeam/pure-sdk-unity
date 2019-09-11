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
        BackgroundIncome(gameState.secondsSincePreviousPlaySession);
    }

    //Checks to see if game has been closed while tracking was enabled and awards the corresponding income.
    private void BackgroundIncome(int seconds)
    {
        if (tracking.IsTracking() && seconds > 0)
        {
            gameState.GainIncome(seconds);
            backgroundRewardDialog.Show(seconds * gameState.income);
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
        BackgroundIncome(gameState.secondsPaused);

        if (Time.time < _nextEmission)
        {
            return;
        }

        _emitter.Emit();
        gameState.GainIncome();
        _nextEmission += secondsBetweenIncomes;

    }
}