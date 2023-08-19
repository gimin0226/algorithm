import java.io.*;
import java.util.Deque;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
    static int n;
    static int m;

    static Deque<Integer> deque;

    public static void main(String[] args)throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st=new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());
        deque=new LinkedList<>();
        recursion(0,0);

    }

    static void recursion(int x,int y){

        if(y==m){
            Iterator<Integer> iterator = deque.iterator();
            while(iterator.hasNext()){
                System.out.print(iterator.next()+" ");
            }
            System.out.println();
            return;
        }
        for(int i=1;i<=n;i++){
            if(i>=x){
                deque.addLast(i);
                recursion(i,y+1);
                deque.removeLast();
            }
        }

    }

}
