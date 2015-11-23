/*
 암호화관련 example
 1. 서비스키에서 암호화 키 발췌
 서비스키 : rIvLQuYURCj4zkoYe3pPuh0HK4XwCULXBeAPa2vZ%2B…..(생략)
 암호화키(ServiceKey 앞 16자리) : rIvLQuYURCj4zkoY

 2. 128bit AES암호화
 이름 : 홍길동 => r74Rmfm+/h+aZkwgwgyGmg==
 전화번호 : 01012340000 => J7ImzWbyyPg69KtTrv/9rA==
 인증키 : 123456 => Px/jHhqHMxD7/j5OqrQLVw==

 3. utf-8 url encode
 이름 : 홍길동 =>r74Rmfm%2B%2Fh%2BaZkwgwgyGmg%3D%3D
 전화번호 : 01012340000 =>J7ImzWbyyPg69KtTrv%2F9rA%3D%3D
 인증키 : 123456 =>Px%2FjHhqHMxD7%2Fj5OqrQLVw%3D%3D

 4. 최종 호출url 예
 http://도메인/service/rest/getSelfCvplDetail.do?ServiceKey=생략..&pageNo=1&numOfRows=10&_type=xml& usrName=r74Rmfm%2B%2Fh%2BaZkwgwgyGmg%3D%3D&usrHpNo=J7ImzWbyyPg69KtTrv%2F9rA%3D%3D&usrAuthKey=Px%2FjHhqHMxD7%2Fj5OqrQLVw%3D%3D

 5. 예제 java source
 */

import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;

import sun.misc.BASE64Encoder;

/**
 * 활용자 AES128 암호화 샘플
 */
public class AES128 {

    // 공유자원포털에서 발급받은 서비스키

    protected static String ServiceKey = "c137qWbA6aouSHoH3YOKHDqQSpRG0K7RMQfu3bHBAuEvTYO03J29drJhGW1%2FYnKhXaYSx%2FmNxmeEIJewTw9phw%3D%3D";

    public static class AesEncrypt {

        private SecretKeySpec secureKey;

        public AesEncrypt(String key16) throws Exception {
            this.secureKey = new SecretKeySpec(key16.getBytes(), "AES");
        }

        public byte[] Encrypt(String data, Cipher cipher) throws Exception {
            cipher.init(Cipher.ENCRYPT_MODE, secureKey); // 암호화 모드로 지정
            byte[] encrypted = cipher.doFinal(data.getBytes());
            return encrypted;
        }

    }

}
