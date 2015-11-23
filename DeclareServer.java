

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author sim
 */
import java.io.*;
import java.net.*;
import java.util.ArrayList;

public class DeclareServer {

    public static void main(String argv[]) throws Exception {
        String clientSentence;
        String toClientStr;
        ServerSocket welcomeSocket = new ServerSocket(6789);
        while (true) {
            Socket connectionSocket = welcomeSocket.accept();
            BufferedReader inFromClient = new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));
            DataOutputStream outToClient = new DataOutputStream(connectionSocket.getOutputStream());

            //클라이언트에게 string받은부분
            clientSentence = inFromClient.readLine();
            System.out.println("Received: " + clientSentence);

            //토크나이저 실행후  list에 parameter 전부를 저장
            ParamTokenizer tokenDriver = new ParamTokenizer(clientSentence, " ");
            ArrayList list = new ArrayList(20);
            list = tokenDriver.EnableUse();
            System.out.println(list);

            //API서버에 접수할 파라메타 데이터 삽입
            for (int i = 0; i < 5; i++) {
                System.out.println(list.get(i));
            }
            
            RequestDriver api = new RequestDriver((String) list.get(0), (String) list.get(1), (String) list.get(2), (String) list.get(3), (String) list.get(4), (String) list.get(5));
            
            
            
            //API 서버에 응답 요청 후 클라이언트에게 메시지 전달
            api.declare();
            System.out.println("to client  :" + api.getResult());
            if (api.getResult().equals("TRUE")) {
                toClientStr = api.getResult();
                outToClient.writeBytes(toClientStr + "\n");
            } else {
                toClientStr = api.getResult();
                outToClient.writeBytes(toClientStr + "\n");
            }

        }
    }

}
