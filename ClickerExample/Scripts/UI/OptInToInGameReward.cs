using UnityEngine;

public class OptInToInGameReward : MonoBehaviour
{
    public OptInToGDPR optInToGDPR;
    
    public void Accept()
    {
        optInToGDPR.Show();
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
