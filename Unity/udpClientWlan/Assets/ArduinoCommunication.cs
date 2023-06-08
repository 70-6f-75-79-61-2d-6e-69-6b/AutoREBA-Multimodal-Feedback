using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

public class ArduinoCommunication
{
    private UdpClient udpClient;
    private IPEndPoint arduinoEndpoint;

    public ArduinoCommunication(string arduinoIPAddress, int arduinoPort)
    {
        udpClient = new UdpClient();
        arduinoEndpoint = new IPEndPoint(IPAddress.Parse(arduinoIPAddress), arduinoPort);
    }

    public string SendCommandToArduino(string command)
    {
        byte[] commandBytes = Encoding.ASCII.GetBytes(command);
        udpClient.Send(commandBytes, commandBytes.Length, arduinoEndpoint);

        byte[] receivedBytes = udpClient.Receive(ref arduinoEndpoint);
        string response = Encoding.ASCII.GetString(receivedBytes);
        return response;
    }
}
