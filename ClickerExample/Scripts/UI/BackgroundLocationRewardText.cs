using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class BackgroundLocationRewardText : MonoBehaviour
{
    public GameState gameState;
    private Text _text;

    // Start is called before the first frame update
    void Start()
    {
        _text = GetComponent<Text>();
    }

    // Update is called once per frame
    void Update()
    {
        _text.text = "Background location just earned you  " + gameState.secondsSincePreviousPlaySession;
    }
}
