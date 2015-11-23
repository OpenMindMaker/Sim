/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.*;
import java.net.*;

/**
 *
 * @author sim
 */
public class DeclareClients {

    public static void main(String argv[]) throws Exception {
        String sentence;
        String fromServerStr;
        BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));
        Socket clientSocket = new Socket("localhost", 6789);
        DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());
        BufferedReader inFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
        sentence = inFromUser.readLine();
        outToServer.writeBytes(sentence + '\n');
        fromServerStr = inFromServer.readLine();
        System.out.println("FROM SERVER: " + fromServerStr);
        clientSocket.close();
    }
}

//usrHpNo,  usrName,  longitude,  latitude,  dscfNtOpenYn,  videoPath 순서대로 보내야 한다!!!
//"GTG1uB9vgEVMTQ0ZRVQ/1w== cXrMtRMPuw3bEQbJVD0Zfw== 126:29 36:36 Y c:\\2015.mp4"