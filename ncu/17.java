import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int k = cin.nextInt();
        int month = cin.nextInt();
        double rate = cin.nextDouble();
        double sum = 0.0, ans = 0.0;
        for (int i = 0; i < month; i++) {
            sum += k;
            ans += sum*rate;
            sum += ans;
            System.out.printf("%.2f\n", sum);
        }
    }
}