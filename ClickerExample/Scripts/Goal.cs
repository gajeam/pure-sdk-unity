using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Goal : MonoBehaviour
{
    // Destroy everything that enters the trigger
    void OnTriggerEnter(Collider other)
    {
        
        var hexParticle = other.gameObject.GetComponentInParent<HexParticle>();
        hexParticle.Swap();
    }
    
}
