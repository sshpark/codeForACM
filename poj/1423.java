import java.util.*;

class Main {
	public static double strling(int n) {
		return 0.5*Math.log10(2*Math.PI*n) + n*Math.log10(n/Math.E);
	}
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int T = cin.nextInt();
		int n;
		for (int i = 0; i < T; i++) {
			n = cin.nextInt();
			System.out.println((int)strling(n)+1);
		}	
	}
}