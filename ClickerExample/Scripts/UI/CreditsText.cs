using UnityEngine;
using UnityEngine.UI;

public class CreditsText : MonoBehaviour
{
    public GameState gameState;
    private Text _text;

    // Start is called before the first frame update
    void Start()
    {
        _text = GetComponent<Text>();
    }

    // Update is called once per frame
    void Update()
    {
        _text.text = gameState.GetCreditsForDisplay();
    }
}
