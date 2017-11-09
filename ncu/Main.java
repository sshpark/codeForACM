import java.util.*;
import java.math.*;
public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n = 0;
        int[] a = new int[100005];
        int[] dp = new int[100005];
        while (cin.hasNext())
            a[n++] = cin.nextInt();
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++)
                if (a[i] <= a[j])
                    dp[i] = Math.max(dp[i], dp[j]+1);
        }
        int maxa = -1;
        for (int i = 0; i < n; i++) maxa = Math.max(maxa, dp[i]);
        System.out.println(maxa);
        maxa = -1;
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++)
                if (a[i] >= a[j])
                    dp[i] = Math.min(dp[i], dp[j]+1);
        }
        for (int i = 0; i < n; i++) maxa = Math.max(maxa, dp[i]);
        System.out.println(maxa);
    }
}