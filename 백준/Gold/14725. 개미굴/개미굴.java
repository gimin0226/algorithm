import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static class Node{
        String data;
        TreeMap<String,Node> child;

        Node(String data){
            this.data= data;
            child=new TreeMap<>();
        }

        Node(){
            child=new TreeMap<>();
        }
    }

    static void linkedNode(Node move, String str){
        if(!move.child.containsKey(str)){
            Node node=new Node(str);
            move.child.put(str,node);
        }
    }

    static void recursion(int num,Node node){
        for(int i=0;i<num;i++)
            System.out.print("-");
        num+=2;
        System.out.println(node.data);
        for(Map.Entry<String,Node> entry:node.child.entrySet()){
            recursion(num,entry.getValue());
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());

        Node root=new Node();

        for(int i=0;i<n;i++){
            String str=br.readLine();
            StringTokenizer st=new StringTokenizer(str," ");
            int k=Integer.parseInt(st.nextToken());
            Node move=root;
            for(int j=0;j<k;j++){
                String str2=st.nextToken();
                linkedNode(move,str2);
                move=move.child.get(str2);
            }

        }
        for(Map.Entry<String,Node> entry:root.child.entrySet()){
            recursion(0,entry.getValue());
        }


       // System.out.println(root.child.containsKey("B"));

    }

}
