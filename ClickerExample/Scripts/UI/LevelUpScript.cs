using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;

public class LevelUpScript : MonoBehaviour, IPointerDownHandler
{
    // Start is called before the first frame update
    public void DisplayLevelUpDialog(string levelUpText)
    {
        var childGameObject = gameObject.transform.GetChild(0).gameObject;
        var childText = childGameObject.GetComponentInChildren<Text>();
        childText.text = levelUpText;
        gameObject.SetActive(true);
    }

    public void OnPointerDown(PointerEventData eventData)
    {
        gameObject.SetActive(false);
    }
}