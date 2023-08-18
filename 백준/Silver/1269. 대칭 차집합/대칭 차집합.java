import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine()," ");
        int n=Integer.parseInt(st.nextToken());
        int m=Integer.parseInt(st.nextToken());
        int[] arr1=new int[n];
        int[] arr2=new int[m];

        HashMap<Integer,Boolean> hm1=new HashMap<>();
        HashMap<Integer,Boolean> hm2=new HashMap<>();
        st=new StringTokenizer(br.readLine()," ");
        for(int i=0;i<n;i++){
            int t=Integer.parseInt(st.nextToken());
            hm1.put(t,true);
            arr1[i]=t;
        }
        st=new StringTokenizer(br.readLine()," ");
        for(int i=0;i<m;i++){
            int t=Integer.parseInt(st.nextToken());
            hm2.put(t,true);
            arr2[i]=t;
        }

        int num=n+m;
        for(int i=0;i<n;i++){
            num-=(hm2.get(arr1[i])!=null)?1:0;
        }
        //System.out.println(num);
        for(int i=0;i<m;i++){
            num-=(hm1.get(arr2[i])!=null)?1:0;
        }
        System.out.println(num);

    }

}
