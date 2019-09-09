using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Experimental.PlayerLoop;
using UnityEngine.UI;

public class AgeDropdown : MonoBehaviour
{
    public Dropdown year;
    public Dropdown month;
    public Dropdown day;

    public Button submitButton;
    public GameState gameState;


    // Start is called before the first frame update
    void Start()
    {
        Debug.Log("START! Check that age is set. Age=" + gameState.age);
        if (gameState.IsAgeSubmitted())
        {
            gameObject.SetActive(false);
        }

        submitButton.onClick.AddListener(TaskOnClick);

        for (int i = DateTime.Now.Year; i >= 1920; i--)
        {
            year.options.Add(new Dropdown.OptionData(i.ToString()));
        }

        for (int j = 1; j <= 12; j++)
        {
            month.options.Add(new Dropdown.OptionData(j.ToString()));
        }

        for (int j = 1; j <= 31; j++)
        {
            day.options.Add(new Dropdown.OptionData(j.ToString()));
        }

        year.value = 2;
        month.value = 11;
        day.value = 29;
    }

    void TaskOnClick()
    {
        var birthdate = GetBirthdate();
        var today = DateTime.Today;

        var age = today.Year - birthdate.Year;
        if (birthdate.Date > today.AddYears(-age))
        {
            age--;
        }

        gameState.RegisterAge(age);
        Debug.Log("Your age is " + age);
        gameObject.SetActive(false);
    }

    private DateTime GetBirthdate()
    {
        return new DateTime(
            Int32.Parse(year.options[year.value].text),
            Int32.Parse(month.options[month.value].text),
            Int32.Parse(day.options[day.value].text));
    }
}