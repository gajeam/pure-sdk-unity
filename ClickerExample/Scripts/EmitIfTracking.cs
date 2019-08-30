using System;
using Unaty.PureSDK;
using UnityEngine;

[RequireComponent(typeof(HexEmitter))]
public class EmitIfTracking : MonoBehaviour
{
    public PureSDKComponent tracking;
    public GameState gameState;
    
    public float secondsBetweenIncomes = 1;
    private HexEmitter _emitter;
    
    private float _nextEmission;
    

    // Start is called before the first frame update
    void Start()
    {
        _emitter = GetComponent<HexEmitter>();
        _nextEmission = Time.realtimeSinceStartup + secondsBetweenIncomes;
        AddBackgroundEarnedIncome();
    }

    private void AddBackgroundEarnedIncome()
    {
        if (tracking.IsTracking() && gameState.secondsSincePreviousPlaySession > 0)
        {
            gameState.GainIncome(gameState.secondsSincePreviousPlaySession);
        }
    }
    

    // Update is called once per frame
    void Update()
    {
        if (!tracking.IsTracking())
        {
            _nextEmission = Time.realtimeSinceStartup + secondsBetweenIncomes;
            return;
        }
        
        if (Time.time < _nextEmission)
        {
            return;
        }

        _emitter.Emit();
        gameState.GainIncome();
        _nextEmission += secondsBetweenIncomes;
    }
}
