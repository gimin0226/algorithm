import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int m;
    static char[] arr;

    static Deque<Character> deque;
    public static void main(String[] args)throws IOException {
        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw= new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st= new StringTokenizer(br.readLine()," ");
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());
        arr=new char[m];
        st=new StringTokenizer(br.readLine()," ");
        for(int i=0;i<m;i++){
            arr[i]=st.nextToken().charAt(0);
        }
        Arrays.sort(arr);
        deque=new LinkedList<>();

        BackTracking(-1,0,0,0);
    }

    static void BackTracking(int k,int length,int count,int count2){

        if(length==n){
            if(count==0||count2<2){
                return;
            }
            Iterator<Character> iterator=deque.iterator();
            while(iterator.hasNext()){
                System.out.print(iterator.next());
            }System.out.println();
            return;
        }

        for(int i=k+1;i<=m-n+length;i++){
            deque.add(arr[i]);
            if(arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u')
                BackTracking(i,length+1,count+1,count2);
            else{
                BackTracking(i,length+1,count,count2+1);
            }
            deque.removeLast();
        }
    }
}