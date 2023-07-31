

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static class Node{
        public Node left;
        public Node right;
        public int data;
        public Node(int data){
            this.data = data;
        }

    }

    static void LinkedNode(Node move,Node node){
        while(true) {
            if (node.data < move.data) {
                if (move.left == null) {
                    move.left = node;
                    break;
                } else {
                    move = move.left;
                }
            } else if (node.data > move.data) {
                if (move.right==null){
                    move.right=node;
                    break;
                }else{
                    move=move.right;
                }
            }
        }
    }

    static void PostOrder(Node node){
        if(node==null){
            return;
        }
        PostOrder(node.left);
        PostOrder(node.right);
        System.out.println(node.data);
    }

    public static void main (String[] args) throws IOException {
       BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
       List<Integer> list= new ArrayList<Integer>();
       String input;
       Node root=new Node(Integer.valueOf(br.readLine()));
       while (true) {
            input = br.readLine();
            if (input == null || input.equals(""))
                break;
            int a = Integer.valueOf(input);
            LinkedNode(root,new Node(a));
       }

       PostOrder(root);




    }
}
