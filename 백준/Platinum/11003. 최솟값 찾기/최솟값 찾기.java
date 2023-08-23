import java.io.*;
import java.util.Deque;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static Deque<Node> deque;
    public static void main(String[] args) throws IOException {
        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw= new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st=new StringTokenizer(br.readLine()," ");
        int n=Integer.parseInt(st.nextToken());
        int m=Integer.parseInt(st.nextToken());

        st=new StringTokenizer(br.readLine()," ");
        int t=st.countTokens();
        int[] arr=new int[n];
        Node[] node= new Node[n];
        for(int i=0;i<t;i++){
            arr[i]=Integer.parseInt(st.nextToken());
            node[i]=new Node(arr[i],i);
        }
        deque=new LinkedList<>();
        for(int i=0;i<n;i++){
            if(i>=m){
                if(deque.getFirst().idx<=i-m){
                    deque.removeFirst();
                }
            }
            if(deque.isEmpty()){
                deque.addFirst(new Node(arr[i],i));
            }else if(deque.getFirst().data>=arr[i]){
               while(!deque.isEmpty()){
                   deque.removeFirst();
               }
               deque.add(new Node(arr[i],i));

            }
            else{
                while(deque.getLast().data>arr[i]){
                    deque.removeLast();
                }
                deque.addLast(new Node(arr[i],i));
            }

            bw.write(deque.getFirst().data+" ");
        }

        bw.flush();
        bw.close();
    }

    static class Node{
        public int data;
        public int idx;
        public Node(int data,int idx){
            this.data=data;
            this.idx=idx;
        }
    }
}
