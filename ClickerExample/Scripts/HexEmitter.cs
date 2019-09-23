using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Random = UnityEngine.Random;

public class HexEmitter : MonoBehaviour
{
    public HexParticle particleToSpawn;
    public float emissionPower = 10;
    public float powerRandomness = 1;
    public GameState gameState;


    [ContextMenu("Emit")]
    public void Emit()
    {
        var spawned = Instantiate(particleToSpawn, transform.position, transform.rotation);
        spawned.gameState = gameState;
        var body = spawned.GetComponent<Rigidbody>();
        body.velocity = transform.forward * emissionPower + Random.insideUnitSphere * powerRandomness;
        body.angularVelocity = Random.insideUnitSphere;
        
    }

    void OnDrawGizmos()
    {
        Gizmos.color = Color.yellow;
        Gizmos.DrawWireSphere(transform.position, 1);
        Gizmos.DrawRay(transform.position, transform.forward * 20);
    }
}
