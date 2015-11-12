
import java.io.IOException;




/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author sim
 */

public class StartTest {
    public static void main(String [] argv) throws IOException, Exception {
    RequestDeclare a = new RequestDeclare("http://openapi.gmap.go.kr/service/rest/dspsnZoneUnlawParkngRegService/setUnlawInfomation?usrHpNo=J7ImzWbyyPg69KtTrv/9rA&usrName=r74Rmfm+/h+aZkwgwgyGmg&ServiceKey=c137qWbA6aouSHoH3YOKHDqQSpRG0K7RMQfu3bHBAuEvTYO03J29drJhGW1%2FYnKhXaYSx%2FmNxmeEIJewTw9phw%3D%3D&appName=테스트app&dscfNtTypeCode=D01&dscfNtTitleCode=D01T03&dscfNtTitle=장애인구역불법주차신고&dscfNtContent=불법주차신고내용&longitude=123.123&latitude=38.123&dscfNtOpenYn=Y&videoTakeGbn=A01&videoTakeTime=2011121311031110&videoPath=C:\\Users\\sim\\Desktop\\2015.mp4&testYn=Y");
    //RequestDeclare a = new RequestDeclare("http://www.naver.com");
    a.readURL();
    System.out.println(a.getUrlLine(0));
    
    AES128 b = new AES128("심형석","01077742849");
    b.encoding();
    System.out.println(b.getDecoName());
    System.out.println(b.getDecoTel());
    }
}
