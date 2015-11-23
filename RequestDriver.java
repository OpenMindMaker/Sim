
import java.io.*;
import java.net.*;

public class RequestDriver {

    private String usrHpNo, usrName, longitude, latitude, dscfNtOpenYn, videoPath;
    private String xml;
    private String result;
    private String zz = "null";

    public RequestDriver(String usrHpNo, String usrName, String longitude, String latitude, String dscfNtOpenYn, String videoPath) {
        this.usrHpNo = usrHpNo;
        this.usrName = usrName;
        this.longitude = longitude;
        this.latitude = latitude;
        this.dscfNtOpenYn = dscfNtOpenYn;
        this.videoPath = videoPath;
        this.xml = "";
        String zz = "null";
    }

    // 파싱부분 앞으로 수정요망
    //
    //
    //
    public void parsingXml() {
        if (xml == null) {
            System.out.println("정상등록 되었따!!!");
            result = "TRUE";
        } else {
            //파싱해야됨 나중에 ㄱㄱ
            result = xml;
        }
    }

    public String getResult() {
        return result;
    }

    public void declare() throws IOException {
        URL myUrl = new URL("http://openapi.gmap.go.kr/service/rest/dspsnZoneUnlawParkngRegService/setUnlawInfomation");
        HttpRequestor requestor = new HttpRequestor(myUrl);

        //고정 parameter
        /**
         *
         * requestor.addParameter("ServiceKey",
         * "c137qWbA6aouSHoH3YOKHDqQSpRG0K7RMQfu3bHBAuEvTYO03J29drJhGW1/YnKhXaYSx/mNxmeEIJewTw9phw==");
         * requestor.addParameter("appName", "테스트app");
         * requestor.addParameter("dscfNtTypeCode", "D01");
         * requestor.addParameter("dscfNtTitleCode", "D01T03");
         * requestor.addParameter("dscfNtTitle", "테스트");
         * requestor.addParameter("dscfNtContent", "테스트");
         * requestor.addParameter("videoTakeGbn", "A01");
         * requestor.addParameter("videoTakeTime", "2011121311031110");
         * requestor.addParameter("testYn", "Y");
        *
         */
        requestor.addParameter("ServiceKey", "c137qWbA6aouSHoH3YOKHDqQSpRG0K7RMQfu3bHBAuEvTYO03J29drJhGW1/YnKhXaYSx/mNxmeEIJewTw9phw==");
        requestor.addParameter("appName", "테스트app");
        requestor.addParameter("dscfNtTypeCode", "D01");
        requestor.addParameter("dscfNtTitleCode", "D01T03");
        requestor.addParameter("dscfNtTitle", "테스트");
        requestor.addParameter("dscfNtContent", "테스트");
        requestor.addParameter("videoTakeGbn", "A01");
        requestor.addParameter("videoTakeTime", "2011121311031110");
        requestor.addParameter("testYn", "Y");

        //사용자 입력 parameter
        requestor.addParameter("usrHpNo", usrHpNo);
        requestor.addParameter("usrName", usrName);
        requestor.addParameter("longitude", longitude);
        requestor.addParameter("latitude", latitude);
        requestor.addParameter("dscfNtOpenYn", dscfNtOpenYn);
        requestor.addFile("videoPath", new File(videoPath));

        InputStream is = requestor.sendMultipartPost();
        BufferedReader br;
        br = new BufferedReader(new InputStreamReader(is));
        for (int i = 0; i < 6; i++) {
            xml = br.readLine();
            System.out.println(xml);
        }
        br.close();
        parsingXml();
    }
}
