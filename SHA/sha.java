package sha1;
import java.util.Scanner;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class Sha_main {
	public static String hashPassword(String password) throws NoSuchAlgorithmException
	{
		MessageDigest md = MessageDigest.getInstance("SHA-1");
		md.update(password.getBytes());
		byte[] b = md.digest();
		StringBuffer sb = new StringBuffer();
		for(byte b1 : b)
		{
			sb.append(Integer.toHexString(b1 & 0xff).toString());
		}
		return sb.toString();
	}
	public static void main(String[] args)
	{
		String password;
		Scanner in = new Scanner(System.in);
		
		System.out.println("\n\tEnter a string: ");
	    password = in.nextLine();
		//System.out.println(password);
		try
		{
			System.out.println("\n\tHashed string: ");
			System.out.println(hashPassword(password));
		}
		catch(NoSuchAlgorithmException e)
		{
			System.out.println(e);
		}
	}
}

OUTPUT 

	-----------SHA1 IN JAVA-----------

	Enter a string: 
khandelwal

	Hashed string: 
2b83d698b4849e930fffabcf8208121028dac
