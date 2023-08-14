import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.Array;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static List[] list;
    static int[] check;
    static int[] parent;

    public static void main(String[] args)throws IOException {
        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());

        StringTokenizer st;
        list=new ArrayList[n+1];
        for(int i=0;i<n+1;i++){
            list[i]=new ArrayList<Integer>();
        }
        check=new int[n+1];
        parent=new int[n+1];
        for(int i=0;i<n-1;i++){
            st=new StringTokenizer(br.readLine()," ");
            int x=Integer.parseInt(st.nextToken());
            int y=Integer.parseInt(st.nextToken());

            list[x].add(y);
            list[y].add(x);
        }

        recursion(1);

        for(int i=2;i<n+1;i++){
            System.out.println(parent[i]);
        }
    }

    static void recursion(int data) {
        check[data]=1;
        List<Integer> stack=new ArrayList<>();

       for(int i=0;i<list[data].size();i++){
          // System.out.print(list[data].get(i)+" ");
           int k=(int)list[data].get(i);
           if(check[k]==0){
               parent[k]=data;
               stack.add(k);
           }
       }

       for(int i=0;i<stack.size();i++){
           recursion(stack.get(i));
       }
    }

}