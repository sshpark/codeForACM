import java.util.*;
public class Main
{
	public static void main(String[] argv) {
		Scanner cin = new Scanner(System.in);
		int[] p = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};
		long n;
		while (cin.hasNext()) {
			n = cin.nextLong();
			long ans = 1, temp;
			for (int i = 0; ; i++) {
				temp = (long)(Math.pow(n, 1.0/p[i]));
				if (temp < 2)
					break;
				ans += temp - 1;
				for (int j = i+1; ; j++) {
					temp = (long)(Math.pow(n, 1.0/(p[i]*p[j])));
					if (temp < 2)
						break;
					ans -= temp - 1;
					for (int k = j+1; ; k++) {
						temp =(long)(Math.pow(n, 1.0/(p[i]*p[j]*p[k])));
						if (temp < 2)
							break;
						ans += temp - 1;
					}
				}
			}
			System.out.println(ans);
		}
	}
}