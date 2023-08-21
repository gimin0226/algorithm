import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static PriorityQueue<Node> pq;
    static int[] distance;
    static ArrayList<Node>[] list;

    static int INF=Integer.MAX_VALUE;
    public static void main(String[] args)throws IOException{
        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());
        int m=Integer.parseInt(br.readLine());
        StringTokenizer st;
        list=new ArrayList[n+1];
        for(int i=1;i<=n;i++){
            list[i]=new ArrayList<>();
        }

        for(int i=0;i<m;i++){
            st=new StringTokenizer(br.readLine()," ");
            int a=Integer.parseInt(st.nextToken());
            int b=Integer.parseInt(st.nextToken());
            int c=Integer.parseInt(st.nextToken());
            list[a].add(new Node(b,c));
        }

        pq=new PriorityQueue<>((o1, o2) -> Integer.compare(o1.cost,o2.cost));

        distance=new int[n+1];

        Arrays.fill(distance,INF);

        st=new StringTokenizer(br.readLine()," ");
        int start=Integer.parseInt(st.nextToken());
        int end=Integer.parseInt(st.nextToken());
        Dijkstra(start,end);

        System.out.println(distance[end]);
    }

    static void Dijkstra(int start,int end){
        distance[start]=0;
        pq.add(new Node(start,distance[start]));

        while(!pq.isEmpty()){
            Node node=pq.poll();
            
            if(node.cost>distance[node.idx]){
                continue;
            }
            for(int i=0;i<list[node.idx].size();i++){
                Node node2=list[node.idx].get(i);
                if(node.cost+node2.cost<distance[node2.idx]){
                    distance[node2.idx]=node.cost+node2.cost;
                    pq.add(new Node(node2.idx,distance[node2.idx]));
                }
            }
        }
    }
    static class Node{
        int cost;
        int idx;

        public Node(int idx,int cost){
            this.cost=cost;
            this.idx=idx;
        }
    }
}
