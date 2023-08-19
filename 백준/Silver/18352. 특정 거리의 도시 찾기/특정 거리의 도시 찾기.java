import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static List<Integer>[] list;
    static final int INF =Integer.MAX_VALUE;
    public static void main(String[] args) throws IOException {
        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        int n=Integer.parseInt(st.nextToken());
        int m=Integer.parseInt(st.nextToken());
        int k=Integer.parseInt(st.nextToken());
        int x=Integer.parseInt(st.nextToken());
        list=new List[n+1];
        for(int i=1;i<=n;i++){
            list[i]=new ArrayList<>();
        }
        for(int i=0;i<m;i++){
            st=new StringTokenizer(br.readLine()," ");
            int X=Integer.parseInt(st.nextToken());
            int Y=Integer.parseInt(st.nextToken());
            list[X].add(Y);
        }

        int[] distance= new int[n+1];
        Arrays.fill(distance,INF);
        distance[x]=0;
        Deque<Integer> deque=new LinkedList<>();
        deque.add(x);

        while(!deque.isEmpty()){
            int t= deque.removeFirst();
            for(int i=0;i<list[t].size();i++){
                int p=list[t].get(i);
                if(distance[p]<=distance[t]+1){

                }else{
                    distance[p]=distance[t]+1;
                    deque.add(p);
                }

            }
        }

        int num=0;
        for(int i=1;i<n+1;i++){
            if(distance[i]==k){
                System.out.println(i);
                num++;
            }
        }
        if(num==0){
            System.out.println("-1");
        }
    }


}
