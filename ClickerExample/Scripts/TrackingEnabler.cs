using System.Collections;
using System.Collections.Generic;
using Unaty.PureSDK;
using UnityEngine;

public class TrackingEnabler : MonoBehaviour
{
    public PureSDKComponent tracking;

    public bool enableIfTracking;

    // Update is called once per frame
    void Update()
    {
        transform.GetChild(0).gameObject.SetActive(enableIfTracking == tracking.IsTracking());
    }
}