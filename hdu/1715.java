import java.math.*;
import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int T, n;
        T = cin.nextInt();
        for (int i = 0; i < T; i++) {
            BigInteger[] ans = new BigInteger[1005];
            n = cin.nextInt();
            ans[1] = ans[2] = BigInteger.ONE;
            for (int j = 3; j <= n; j++)
                ans[j] = ans[j-1].add(ans[j-2]);
            System.out.println(ans[n]);
        }
    }
}