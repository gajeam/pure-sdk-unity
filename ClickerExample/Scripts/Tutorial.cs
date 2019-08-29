using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UIElements;

public class Tutorial : MonoBehaviour, IPointerDownHandler
{

    private int currentStep = 0;
    private int childCount;
    private bool tutorialComplete;
    // Start is called before the first frame update
    private void Start()
    {
        if (tutorialComplete)
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
            tutorialComplete = true;
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
