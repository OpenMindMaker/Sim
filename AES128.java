/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import sun.misc.BASE64Encoder;

/**
 *
 * @author sim
 */
public class AES128 {

    // 공유자원포털에서 발급받은 서비스키

    private String ServiceKey = "c137qWbA6aouSHoH3YOKHDqQSpRG0K7RMQfu3bHBAuEvTYO03J29drJhGW1%2FYnKhXaYSx%2FmNxmeEIJewTw9phw%3D%3D";
    String decoName;
    String decoTel;
    String userName;
    String userTel;

    public AES128(String userName, String userTel) {
        this.userName = userName;
        this.userTel = userTel;
    }
 
    
    
    public void encoding() throws Exception {
        // 공유자원포털에서 발급받은 서비스키의 0~16 자리 값 셋팅
        String secKey = ServiceKey.substring(0, 16);
        // 암호화 - 초기화
        AesEncrypt encrypt = new AesEncrypt(secKey);
        // 암호화 Chiper 생성
        Cipher cipher = Cipher.getInstance("AES");

        decoName = new String(new BASE64Encoder().encode(encrypt.Encrypt(userName, cipher)));
        decoTel = new String(new BASE64Encoder().encode(encrypt.Encrypt(userTel, cipher)));

		// 해당 서비스키(rIvLQuYURCj4zkoY) 기준으로 암호화된 정보는 아래와 같아야 함.
        // 이름 : 홍길동 => r74Rmfm+/h+aZkwgwgyGmg==
        // 전화번호 : 01012340000 => J7ImzWbyyPg69KtTrv/9rA==
        // 인증키 : 123456 => Px/jHhqHMxD7/j5OqrQLVw==
        System.out.println("########## 암호화 데이터 ##########");
        System.out.println("이름 : " + decoName);
        System.out.println("전화번호 : " + decoTel);
    }

    public String getDecoName() {
        return decoName;
    }

    public String getDecoTel() {
        return decoTel;
    }

}
