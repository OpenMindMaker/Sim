
import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author sim
 */
public class AesEncrypt {

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
