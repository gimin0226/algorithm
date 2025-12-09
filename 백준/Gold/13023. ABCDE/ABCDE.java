import java.io.*;
import java.lang.*;
import java.util.*;


class Main {

    public static boolean found = false;
    public static boolean[] check;
    public static List<Integer>[] graph; 
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        check = new boolean[n];
        graph = new ArrayList[n];
        for(int i=0;i<n;i++) graph[i] = new ArrayList<>();
        for(int i=0;i<m;i++){
            st=new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            graph[x].add(y);
            graph[y].add(x);
        }
  //      for(int i=0;i<n;i++){
     //       System.out.println(graph[i]);
     //   }
        for(int i=0;i<n;i++){
            check[i]=true;
            backTracking(0,i);
            check[i]=false;
        }
        
        if(found){
            System.out.println(1);
        }else{
            System.out.println(0);
        }
        
        return;
    }

    public static void backTracking(int depth,int parent_node){
       // for(int i=0;i<depth;i++)System.out.print("-");
       // System.out.println(parent_node);
        if(depth==4){
            found= true;
            return;
        }

        for(int i=0;i<graph[parent_node].size();i++){
            int child_node = graph[parent_node].get(i);
            if(check[child_node])continue;
            check[child_node] = true;
            backTracking(depth+1, child_node);
            if(found)return;
            check[child_node] = false;
        }
    }

  
}

