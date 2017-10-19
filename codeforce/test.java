import java.io.*;   
import java.math.*;  
import java.util.*;   
<<<<<<< HEAD
public class test  
=======
public class Main   
>>>>>>> 02e7b292c22cd01a743f264a7ae673b2a984c5d2
{   
    public static void main(String args[]) throws Exception   
    {   
        Scanner cin=new Scanner(System.in);   
<<<<<<< HEAD
        BigInteger []a = new BigInteger [1000000];  
        BigInteger mm = new BigInteger("1000000007");
        a[0] = BigInteger.ONE;  
        a[1] = BigInteger.ONE;  
        for(int i = 2; i <= 1000000; i++)  
=======
        BigInteger []a = new BigInteger [105];  
        a[0] = BigInteger.ONE;  
        a[1] = BigInteger.ONE;  
        for(int i = 2; i <= 100; i++)  
>>>>>>> 02e7b292c22cd01a743f264a7ae673b2a984c5d2
            a[i] = a[i - 1].multiply(BigInteger.valueOf(4 * i - 2)).divide(BigInteger.valueOf(i+1));  
        int n;  
        while(cin.hasNext())  
        {  
            n = cin.nextInt();  
<<<<<<< HEAD
            System.out.println(a[n-1].mod(mm));  
        }  
    }   
}
=======
            System.out.println(a[n]);  
        }  
    }   
}   
>>>>>>> 02e7b292c22cd01a743f264a7ae673b2a984c5d2
