import java.util.*;
class Main
{
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		String str = cin.next();
		int a = 0;
		for (int i = 1; i < str.length(); i++)
			if (str.charAt(i) == 'F' && str.charAt(i-1) == 'S') a++;
			else if (str.charAt(i) == 'S' && str.charAt(i-1) == 'F') a--;
		System.out.println(a > 0 ? "YES" : "NO");
	}
}