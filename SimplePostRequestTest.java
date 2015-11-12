import java.io.File;
import java.io.IOException;
import java.io.UnsupportedEncodingException;

import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.HttpClient;
import org.apache.http.client.ResponseHandler;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.entity.mime.MultipartEntity;
import org.apache.http.entity.mime.content.FileBody;
import org.apache.http.entity.mime.content.StringBody;
import org.apache.http.impl.client.BasicResponseHandler;
import org.apache.http.impl.client.DefaultHttpClient;

public class SimplePostRequestTest {

    public static void main(String[] args) throws UnsupportedEncodingException, IOException {
        HttpClient httpclient = new DefaultHttpClient();
        HttpPost httppost = new HttpPost("http://192.168.0.102/uploadtest/upload_photo");

        try {
            FileBody bin = new FileBody(new File("/home/ubuntu/cd.png"));
            StringBody id = new StringBody("3");
            MultipartEntity reqEntity = new MultipartEntity();
            reqEntity.addPart("upload_image", bin);
            reqEntity.addPart("id", id);
            reqEntity.addPart("image_title", new StringBody("CoolPic"));

            httppost.setEntity(reqEntity);
            System.out.println("Requesting : " + httppost.getRequestLine());
            ResponseHandler<String> responseHandler = new BasicResponseHandler();
            String responseBody = httpclient.execute(httppost, responseHandler);
            System.out.println("responseBody : " + responseBody);
        } catch (ClientProtocolException e) {

        } finally {
            httpclient.getConnectionManager().shutdown();
        }
    }
