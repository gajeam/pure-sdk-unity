using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UIElements;

public class Tutorial : MonoBehaviour, IPointerDownHandler
{

    public GameState state;
    private int currentStep = 0;
    private int childCount;
    // Start is called before the first frame update
    private void Start()
    {
        if (!state.showTutorial)
        {
            gameObject.SetActive(false);
        }

        childCount = gameObject.transform.childCount;
        gameObject.transform.GetChild(currentStep).gameObject.SetActive(true);
    }

    private void ShowNext()
    {
        gameObject.transform.GetChild(currentStep).gameObject.SetActive(false);
        currentStep++;
        if (currentStep >= childCount)
        {
            gameObject.SetActive(false);
            state.showTutorial = false;
        }
        else
        {
            gameObject.transform.GetChild(currentStep).gameObject.SetActive(true);
        }
        
    }

    public void OnPointerDown(PointerEventData eventData)
    {
        ShowNext();
    }
}
