using Unaty.PureSDK;
using UnityEngine;

[RequireComponent(typeof(HexEmitter))]
public class LocationIncome : MonoBehaviour
{
    public PureSDKComponent tracking;
    public GameState gameState;
    
    public float secondsBetweenIncomes = 1;
    private HexEmitter _emitter;
    
    private float _nextEmission;

    void Start()
    {
        _emitter = GetComponent<HexEmitter>();
        _nextEmission = Time.realtimeSinceStartup + secondsBetweenIncomes;
        AddBackgroundEarnedIncome(); 
    }

    //Checks to see if game has been closed while tracking was enabled and awards the corresponding income.
    private void AddBackgroundEarnedIncome()
    {
        if (tracking.IsTracking() && gameState.secondsSincePreviousPlaySession > 0)
        {
            gameState.GainIncome(gameState.secondsSincePreviousPlaySession);
        }
    }
    

    //Awards income every second while tracking is enabled
    void Update()
    {
        if (!tracking.IsTracking())
        {
            //Using realtime causes this code to give a "burst" of income if game has been paused.
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
