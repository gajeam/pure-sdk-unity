using System.Collections;
using System.Collections.Generic;
using Unaty.PureSDK;
using UnityEngine;

public class OptInToGDPR : MonoBehaviour
{
    public PureSDKComponent tracker;
    
    public void Accept()
    {
        tracker.StartTracking();
        Hide();
    }

    public void Reject()
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
