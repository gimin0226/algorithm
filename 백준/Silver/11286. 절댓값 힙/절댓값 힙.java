import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Main {

    static class Node implements Comparable<Node>{
        public int data;
        public int abs_data;

        public Node(int data, int abs_data){
            this.data= data;
            this.abs_data= abs_data;
        }

        @Override
        public int compareTo(Node node){
            if(this.abs_data>node.abs_data)
                return 1;
            else if(this.abs_data<node.abs_data)
                return -1;
            else if(this.abs_data==node.abs_data){
                if(this.data>node.data)
                    return 1;
                else if(this.data<node.data)
                    return -1;
            }
            return 0;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
        PriorityQueue<Node> pq= new PriorityQueue<>();
        int n=Integer.parseInt(br.readLine());
        for(int i=0;i<n;i++){
            int ptr=Integer.parseInt(br.readLine());
            if(ptr==0){
                Node node=pq.poll();
                if(node==null)System.out.println("0");
                else{
                    System.out.println(node.data);
                }
            }else {
                Node node = new Node(ptr, Math.abs(ptr));
                pq.add(node);

            }
        }
    }
}
