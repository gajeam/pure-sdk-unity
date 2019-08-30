using System;
using UnityEngine;
using UnityEngine.EventSystems;

public class DragToRotate : MonoBehaviour, IPointerDownHandler, IDragHandler
{
    private Rigidbody body;
    private Vector2 cursorPoint;

    public float force = 10;

    // Start is called before the first frame update
    void Start()
    {
        body = GetComponent<Rigidbody>();
    }
    public void OnPointerDown(PointerEventData eventData)
    {
        cursorPoint = new Vector2(Input.mousePosition.y, Input.mousePosition.x);
    }

    public void OnDrag(PointerEventData eventData)
    {
        var mousePos = new Vector2(Input.mousePosition.y, Input.mousePosition.x);
        var diff = cursorPoint - mousePos;
        body.angularVelocity = new Vector2(-diff.x, diff.y) * force;
        cursorPoint = mousePos;
    }
}
