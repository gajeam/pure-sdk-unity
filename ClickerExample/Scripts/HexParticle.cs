using System;
using UnityEngine;

public class HexParticle : MonoBehaviour
{
    public GameObject swapsTo;
    public GameState gameState;
    private int income;
    private int level;
    public bool isColoredByValue;

    public void Start()
    {
        income = gameState.income;
        level = gameState.level;

        if (isColoredByValue)
        {
            colorByValue();
        }
    }

    private void colorByValue()
    {
        var mesh = gameObject.GetComponentInChildren<MeshRenderer>();

        var newMaterial = Instantiate(mesh.material);
        var newMaterialColor = Color.HSVToRGB((level * 100 % 255) / 255f, 1f, 0.78f, true);

        newMaterial.color = newMaterialColor;
        newMaterial.SetColor("_EmissionColor", newMaterialColor);

        mesh.material = newMaterial;
    }


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

        gameState.GainIncome(income);
    }
}