import java.io.*;
import java.security.*;
import javax.crypto.*;

public class rsa {
	public static void main(String[] args) throws IOException {
		try {
		
			System.out.println("---- RSA in Java ----");
			System.out.println();
			String plainText;
			byte inData[], encrypt[], outData[];
		
			BufferedReader br = new BufferedReader(new InputStreamReader( System.in));
			System.out.println("Enter Plaintext : ");
			plainText = br.readLine();
		
			KeyPairGenerator kpg = KeyPairGenerator.getInstance("RSA");
			kpg.initialize(512);
			KeyPair kp = kpg.generateKeyPair();
			PublicKey publicKey = kp.getPublic();
			System.out.println("Public Key : " + publicKey); 
			
			Cipher cipher = Cipher.getInstance("RSA"); 
			cipher.init(Cipher.ENCRYPT_MODE, publicKey); 
			inData = plainText.getBytes(); 
			encrypt = cipher.doFinal(inData);
			System.out.println("Encrypted Plaintext is : " + encrypt);
			
			PrivateKey privateKey = kp.getPrivate();
			cipher.init(Cipher.DECRYPT_MODE, privateKey); 
			System.out.println("Private key:" + privateKey); 
			outData = cipher.doFinal(encrypt);
			System.out.println("Decrypted Plaintext is : " + new String(outData));
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
}
