import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
public class Main
{
	public static void main(String[] argv) {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			int n = cin.nextInt();
			BigInteger r = new BigInteger("1");
			for (int i = 1; i <= n; i++)
				r = r.multiply(new BigInteger(String.valueOf(i)));
			System.out.println(r);
		}
	}
}