using System.Collections;
using System.Collections.Generic;
using Unaty.PureSDK;
using UnityEngine;

public class LearnMore : MonoBehaviour
{
    
    public void GoBack()
    {
        gameObject.SetActive(false);
    }

    public void Show()
    {
        gameObject.SetActive(true);
    }
    
}
