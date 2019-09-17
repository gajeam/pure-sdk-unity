using System;
using UnityEngine;
using UnityEngine.UI;

public class AgeDropdown : MonoBehaviour
{
    public Dropdown age;

    public Button submitButton;
    public GameState gameState;

    // Start is called before the first frame update
    void Start()
    {
        if (gameState.IsAgeSubmitted())
        {
            gameObject.SetActive(false);
        }

        submitButton.onClick.AddListener(TaskOnClick);

        for (int i = 1; i <= 120; i++)
        {
            age.options.Add(new Dropdown.OptionData(i.ToString()));
        }

        age.value = 0;
    }

    void TaskOnClick()
    {
        gameState.RegisterAge(Int32.Parse(age.options[age.value].text));
        gameObject.SetActive(false);
    }

}