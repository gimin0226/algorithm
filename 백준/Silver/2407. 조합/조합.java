import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    static BigInteger answer=new BigInteger("0");
    static BigInteger[][] arr;
    public static void main(String[] args){
        Scanner sca=new Scanner(System.in);
        int n=sca.nextInt();
        int m=sca.nextInt();
        arr=new BigInteger[n+1][m+1];
        System.out.println( complication(n,m));
    }

    //nCr= n-1Cr-1 + n-1Cr
    static BigInteger complication(int n,int m){
        if(arr[n][m]!=null){
            return arr[n][m];
        }
        else if(n==m){
            arr[n][m]=new BigInteger(String.valueOf(1));
            return arr[n][m];
        }
        else if(m==1) {
            arr[n][m]=new BigInteger(String.valueOf(n));
            return arr[n][m];
        }else{
            BigInteger a=complication(n-1,m-1);
            BigInteger b=complication(n-1,m);
            arr[n][m]=a.add(b);
            return arr[n][m];
        }
    }
}