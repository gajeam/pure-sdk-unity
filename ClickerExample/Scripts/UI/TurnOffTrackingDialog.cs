using System.Collections;
using System.Collections.Generic;
using Unaty.PureSDK;
using UnityEngine;

public class TurnOffTrackingDialog : MonoBehaviour
{
    public PureSDKComponent tracker;
    
    public void TurnOff()
    {
        tracker.StopTracking();
        Hide();
    }

    public void Cancel()
    {
        Hide();
    }

    public void Show()
    {
        gameObject.SetActive(true);
    }
    
    public void Hide()
    {
        gameObject.SetActive(false);
    }
}
