using System.Collections;
using System.Collections.Generic;
using Unaty.PureSDK;
using UnityEngine;

public class OptInToInGameReward : MonoBehaviour
{
    public PureSDKComponent tracker;
    public OptInToGDPR optInToGDPR;
    
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
