import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static List<Node>[] list;
    static int INF=Integer.MAX_VALUE;
    static int n;
    static class Node{
        int idx;
        int cost;
        public Node(int idx,int cost){
            this.idx=idx;
            this.cost=cost;
        }
    }
    public static void main(String[] args)throws IOException {

        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer(br.readLine());
        n=Integer.parseInt(st.nextToken());
        int e=Integer.parseInt(st.nextToken());

        list=new List[n+1];
        for(int i=1;i<n+1;i++){
            list[i]=new ArrayList<>();
        }
        for(int i=0;i<e;i++){
            st=new StringTokenizer(br.readLine());
            int a=Integer.parseInt(st.nextToken());
            int b=Integer.parseInt(st.nextToken());
            int c=Integer.parseInt(st.nextToken());
            list[a].add(new Node(b,c));
            list[b].add(new Node(a,c));
        }
        st=new StringTokenizer(br.readLine());
        int first=1;
        int second=Integer.parseInt(st.nextToken());
        int third=Integer.parseInt(st.nextToken());
        int fourth=n;
        int[] destination=new int[]{1,second,third,fourth};
        Long answer1=(long)dijkstra(1,second)+dijkstra(second,third)+dijkstra(third,n);
        Long answer2=(long)dijkstra(1,third)+dijkstra(third,second)+dijkstra(second,n);
        Long answer=(answer1>answer2)?answer2:answer1;

        if(answer>=INF){
            System.out.println("-1");
        }
        else {
            System.out.println(answer);
        }
    }

    static int dijkstra(int start , int end){
        int[] distance=new int[n+1];
        Arrays.fill(distance,INF);
        PriorityQueue<Node> pq=new PriorityQueue<>(((o1, o2) -> Integer.compare(o1.cost,o2.cost)));
        distance[start]=0;
        pq.add(new Node(start,distance[start]));

        while(!pq.isEmpty()){
            Node node=pq.poll();
            if(distance[node.idx]<node.cost)
                continue;
            for(int i=0;i<list[node.idx].size();i++){
                Node child_node=list[node.idx].get(i);
                if(distance[child_node.idx]>node.cost+ child_node.cost){
                    distance[child_node.idx]=node.cost+child_node.cost;
                    pq.add(new Node(child_node.idx,distance[child_node.idx]));
                }
            }
        }
        return distance[end];
    }
}
