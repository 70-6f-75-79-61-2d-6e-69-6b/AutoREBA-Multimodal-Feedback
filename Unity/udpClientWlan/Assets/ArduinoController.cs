using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ArduinoController : MonoBehaviour
{
    private ArduinoCommunication arduinoComm;

    private void Start()
    {
        arduinoComm = new ArduinoCommunication("192.168.2.58", 8888);
        Debug.Log("Server startet:");
    }

    private void Update()
    {
        if (Input.GetKeyDown(KeyCode.Alpha1))
        {
            string response = arduinoComm.SendCommandToArduino("1");
            Debug.Log("Arduino Antwort: " + response);
        }
        else if (Input.GetKeyDown(KeyCode.Alpha0))
        {
            string response = arduinoComm.SendCommandToArduino("0");
            Debug.Log("Arduino Antwort: " + response);
        }
    }
}
