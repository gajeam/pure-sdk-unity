using UnityEngine;

public class DieOutOfScreen : MonoBehaviour
{
    public float yMin = -10;
    // Update is called once per frame
    void Update()
    {
        if (transform.position.y < yMin)
        {
            Destroy(gameObject);
        }
    }
}
