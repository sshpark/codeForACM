import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int a, b, d, e;
		while (cin.hasNext()) {
			a = cin.nextInt();
			b = cin.nextInt();
			d = cin.nextInt();
			e = cin.nextInt();			
			String str = cin.next();
			int ans = a*b%d;
			System.out.println(str.substring(ans-1, ans+e));
		}
	}
}