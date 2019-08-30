using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Random = UnityEngine.Random;

public class ParticleSounds : MonoBehaviour
{
    private AudioSource sfx;
    public AudioClip spawnSound;
    public AudioClip hitSound;

    private void Awake()
    {
        sfx = GameObject.Find("SoundPlayer").GetComponent<AudioSource>();
    }

    // Start is called before the first frame update
    void Start()
    {
        if (spawnSound != null)
        {
            sfx.pitch = Random.Range(0.8f, 1.2f);
            sfx.PlayOneShot(spawnSound);
        }
    }

    private void OnCollisionEnter(Collision other)
    {
        if (hitSound != null)
        {
            sfx.pitch = 1;
            sfx.PlayOneShot(hitSound);
            
        }
    }
}
