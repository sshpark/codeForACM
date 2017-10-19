import java.util.*;
class Main
{
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		String str;
		str = cin.nextLine();
		int a = 0, b = 0;
		for (int i = 0; i <  str.length() ; i++)
			if (str.charAt(i) == 'F') a++;
			else b++;
		System.out.println(a < b ? "YES" : "NO");
	}
}