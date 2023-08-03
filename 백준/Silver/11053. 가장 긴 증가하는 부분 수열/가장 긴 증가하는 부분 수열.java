import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
       Scanner scanner = new Scanner(System.in);
        int n=scanner.nextInt();
        int[] arr=new int[n];
        int[] length=new int[n];  length[0]=1;
        for(int i=0;i<n;i++){
            arr[i]=scanner.nextInt();
        }

        for(int i=1;i<n;i++){
            length[i]=1;
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i]&&length[j]>=length[i]){
                    length[i]=length[j]+1;
                }
            }
        }

        int max=length[0];
        for(int i=0;i<n;i++){
            if(max<length[i]){
                max=length[i];
            }
        }

        System.out.println(max);
    }
}
