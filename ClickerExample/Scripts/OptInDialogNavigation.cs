using UnityEngine;

public class OptInDialogNavigation : MonoBehaviour
{
    
    public GameObject learnMore1;
    public GameObject learnMore2;

    public void ShowLearnMore1()
    {
        learnMore1.SetActive(true);
    }
    
    public void HideLearnMore1()
    {
        learnMore1.SetActive(false);
    }
    
    public void ShowLearnMore2()
    {
        learnMore2.SetActive(true);
    }
    
    public void HideLearnMore2()
    {
        learnMore2.SetActive(false);
    }
    
}