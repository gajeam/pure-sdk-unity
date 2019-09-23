using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Goal : MonoBehaviour
{
    public GameState gameState;
        
    
    // Destroy everything that enters the trigger
    void OnTriggerEnter(Collider other)
    {
        gameState.GainIncome();
        
        var hexParticle = other.gameObject.GetComponentInParent<HexParticle>();
        hexParticle.Swap();
    }
    
}
