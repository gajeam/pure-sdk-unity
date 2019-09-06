using System;
using Unaty.PureSDK;
using UnityEngine;
using UnityEngine.EventSystems;

public class BackgroundLocationReward : MonoBehaviour, IPointerDownHandler
{
    public GameState state;
    public PureSDKComponent tracking;

    private void Start()
    {
    }

    private void OnApplicationFocus(bool hasFocus)
    {
        if (hasFocus)
        {
            if (tracking.IsTracking() && state.secondsSincePreviousPlaySession > 0)
            {
                Debug.Log("Amount: " + state.secondsSincePreviousPlaySession);
                gameObject.transform.GetChild(0).gameObject.SetActive(true);
            }
        }
    }

    public void Upgrade()
    {
        Debug.Log("Upgrade");
    }

    public void OnPointerDown(PointerEventData eventData)
    {
        gameObject.transform.GetChild(0).gameObject.SetActive(false);
    }
}