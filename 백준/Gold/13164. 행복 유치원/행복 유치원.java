import java.util.*;
import java.lang.*;
import java.io.*;

// The main method must be in a class named "Main".
class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
        int n,m;
        StringTokenizer st= new StringTokenizer(br.readLine());
        n= Integer.parseInt(st.nextToken());
        m= Integer.parseInt(st.nextToken());
        st =new StringTokenizer(br.readLine());
        int []arr =new int[n];
        int []diff = new int[n-1];
        for(int i=0;i<n;i++){
            arr[i]=Integer.parseInt(st.nextToken());
            if(i==0)continue;
            diff[i-1]=arr[i]-arr[i-1];
        }
        Arrays.sort(diff);
       // System.out.println(Arrays.toString(diff));

        int result = arr[n-1]-arr[0];
       // System.out.println(result);
        for(int i=n-2; i>(n-2)-(m-1) ;i--){
            result-=diff[i];
           // System.out.println(result);
        }
        System.out.println(result);
    }
}