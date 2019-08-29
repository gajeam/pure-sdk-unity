using Unaty.PureSDK;
using UnityEngine;

[RequireComponent(typeof(HexEmitter))]
public class EmitIfTracking : MonoBehaviour
{
    private HexEmitter _emitter;
    public PureSDKComponent tracking;
    public GameState gameState;
    public float incomeEveryNSeconds = 1;
    private float nextEmission;

    // Start is called before the first frame update
    void Start()
    {
        _emitter = GetComponent<HexEmitter>();
        nextEmission = Time.realtimeSinceStartup + incomeEveryNSeconds;
    }

    // Update is called once per frame
    void Update()
    {
        if (!tracking.IsTracking())
        {
            nextEmission = Time.realtimeSinceStartup + incomeEveryNSeconds;
        }
        
        if (!tracking.IsTracking() || Time.time < nextEmission)
        {
            return;
        }

        _emitter.Emit();
        gameState.GainIncome();
        nextEmission += incomeEveryNSeconds;
    }
}
