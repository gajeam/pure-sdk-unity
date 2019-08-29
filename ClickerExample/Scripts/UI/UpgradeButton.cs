using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class UpgradeButton : MonoBehaviour
{
    public GameState state;
    private Button _button;

    void Start()
    {
        _button = GetComponent<Button>();
    }

    // Update is called once per frame
    void Update()
    {
        _button.interactable = state.CanAffordUpgrade();
    }
}
