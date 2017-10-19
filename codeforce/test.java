import java.io.*;   
import java.math.*;  
import java.util.*;   
public class test  
{   
    public static void main(String args[]) throws Exception   
    {   
        Scanner cin=new Scanner(System.in);   
        BigInteger []a = new BigInteger [1000000];  
        BigInteger mm = new BigInteger("1000000007");
        a[0] = BigInteger.ONE;  
        a[1] = BigInteger.ONE;  
        for(int i = 2; i <= 1000000; i++)  
            a[i] = a[i - 1].multiply(BigInteger.valueOf(4 * i - 2)).divide(BigInteger.valueOf(i+1));  
        int n;  
        while(cin.hasNext())  
        {  
            n = cin.nextInt();  
            System.out.println(a[n-1].mod(mm));  
        }  
    }   
}