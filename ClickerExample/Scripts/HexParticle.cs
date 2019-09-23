using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HexParticle : MonoBehaviour
{
    public GameObject swapsTo;
    
    public void Swap()
    {
        var original = gameObject;
        var originalTransform = original.transform;
        var newObject = Instantiate(swapsTo, originalTransform.position, originalTransform.rotation);
        var rigidBody = newObject.GetComponent<Rigidbody>();
        var originalRigidBody = original.GetComponent<Rigidbody>();
        rigidBody.velocity = originalRigidBody.velocity;
        rigidBody.angularVelocity = originalRigidBody.angularVelocity;
        
        Destroy(original);
        
    }
}
