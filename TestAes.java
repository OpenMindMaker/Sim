
import javax.crypto.Cipher;
import sun.misc.BASE64Encoder;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author sim
 */
public class TestAes extends AES128 {

    public static void main(String[] args) throws Exception {
        // 공유자원포털에서 발급받은 서비스키의 0~16 자리 값 셋팅
        String secKey = ServiceKey.substring(0, 16);
        // 암호화 - 초기화
        AES128.AesEncrypt encrypt = new AES128.AesEncrypt(secKey);
        // 암호화 Chiper 생성
        Cipher cipher = Cipher.getInstance("AES");
        String userName = new String(new BASE64Encoder().encode(encrypt.Encrypt("홍길동", cipher)));
        String userTel = new String(new BASE64Encoder().encode(encrypt.Encrypt("01012340000", cipher)));
		// 해당 서비스키(rIvLQuYURCj4zkoY) 기준으로 암호화된 정보는 아래와 같아야 함.
        // 이름 : 홍길동 => r74Rmfm+/h+aZkwgwgyGmg==
        // 전화번호 : 01012340000 => J7ImzWbyyPg69KtTrv/9rA==
        // 인증키 : 123456 => Px/jHhqHMxD7/j5OqrQLVw==
        System.out.println("########## 암호화 데이터 ##########");
        System.out.println("이름 : " + userName);
        System.out.println("전화번호 : " + userTel);
    }

}
