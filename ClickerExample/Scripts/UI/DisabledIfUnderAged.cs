using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class DisabledIfUnderAged : MonoBehaviour
{
    public GameState gameState;

    // Update is called once per frame
    void Update()
    {
        if (!gameState.DisplayTrackingFeature())
        {
            Destroy(gameObject);
        }
    }
}
