import java.util.*;
import java.lang.*;
import java.io.*;

// The main method must be in a class named "Main".
class Main {
    public static void main(String[] args) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int arr1[] = new int[n];
        int arr2[] = new int[m];
        st= new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++){
            arr1[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<m;i++){
            arr2[i]= Integer.parseInt(st.nextToken());
        }
        int x1=0;
        int x2=0;
    
    //    System.out.println(Arrays.toString(arr1));
      //  System.out.println(Arrays.toString(arr2));

        int result[] = new int[n+m];
        int index=0;
        while(true){
            if(x1==n){
               for(int i=x2;i<m;i++){
                   result[index++]= arr2[i];
               } 
                break;
            }
            if(x2==m){
                for(int i=x1;i<n;i++){
                    result[index++]= arr1[i];
                }
                break;
            }
            if(arr1[x1]<arr2[x2]){
                result[index++]= arr1[x1++];
            }else{
                result[index++]=arr2[x2++];
            }
        }
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<n+m;i++){
            sb.append(result[i]).append(' ');
        }
        System.out.println(sb);
    }
}