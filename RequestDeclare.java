
import java.net.*;
import java.io.*;
import java.util.ArrayList;
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author sim
 */
public class RequestDeclare {
    private ArrayList urlArr = new ArrayList();
    private String url;
    private URL responeseURL;
    private String readline;

    
    public RequestDeclare(String url) {
        this.url = url;
    }
    public RequestDeclare(String usrHpNo,String usrName,String ServiceKey,String appName,
            String dscfNtTypeCode,String dscfNtTitleCode,String dscfNtTitle,String dscfNtContent,
            String longitude,String latitude,String dscfNtOpenYn,String videoTakeGbn,String videoTakeTime,
            String videoPath,String testYn){
        this.url =  "http://openapi.gmap.go.kr/service/rest/"
                    + "dspsnZoneUnlawParkngRegService/"
                    + "setUnlawInfomation?"+
                    "usrHpNo="+usrHpNo+
                    "&usrName="+usrName+
                    "&ServiceKey=c137qWbA6aouSHoH3YOKHDqQSpRG"+
                    "0K7RMQfu3bHBAuEvTYO03J29drJhGW1%2FYnKhXa"+
                    "YSx%2FmNxmeEIJewTw9phw%3D%3D"+
                    "&appName="+appName+
                    "&dscfNtTypeCode="+dscfNtTypeCode+
                    "&dscfNtTitleCode="+dscfNtTitleCode+
                    "&dscfNtTitle="+dscfNtTitle+
                    "&dscfNtContent="+dscfNtContent+
                    "&longitude="+longitude+
                    "&latitude="+latitude+
                    "&dscfNtOpenYn="+dscfNtOpenYn+
                    "&videoTakeGbn="+videoTakeGbn+
                    "&videoTakeTime="+videoTakeTime+
                    "&videoPath="+videoPath+
                    "&testYn="+testYn;
    }
    
    public void readURL() throws MalformedURLException, IOException {
        responeseURL = new URL(url);
        BufferedReader in = new BufferedReader(new InputStreamReader(responeseURL.openStream()));
        while ((readline = in.readLine()) != null) {
            urlArr.add(readline);
            //System.out.println(messageBuf);
        };
    }
    
    /**
     *
     * @param index :type : int  읽을 라인
     * @return 읽은 URL 라인 String 반환(라인번호 초과시 "NULL" 리턴)
     */
    public String getUrlLine(int index){
        try{
            return (String) urlArr.get(index);
        }
        catch(Exception e){
            return "NULL";
        }
        
    }
    /**
     *
     * @param cmpWord : type : String 비교할 문자
     * @return 읽은 URL중 cmpWord내용이있으면 bealon  
     */
    public boolean getUrlContains(String cmpWord) {
        return urlArr.contains(cmpWord);
    }
}
