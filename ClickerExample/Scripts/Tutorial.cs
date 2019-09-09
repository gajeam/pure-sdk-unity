using UnityEngine;
using UnityEngine.EventSystems;

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

        gameObject.transform.GetChild(currentStep).gameObject.SetActive(true);
    }

    private void ShowNext()
    {
        gameObject.transform.GetChild(currentStep).gameObject.SetActive(false);
        currentStep++;
        if (currentStep >= gameObject.transform.childCount)
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
