using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;

public class BackgroundLocationRewardDialog : MonoBehaviour, IPointerClickHandler
{
    public Text _text;

    public void Show(string nrOfGems)
    {
        _text.text = nrOfGems;
        gameObject.SetActive(true);
    }

    public void OnPointerClick(PointerEventData eventData)
    {
        gameObject.SetActive(false);
    }
}