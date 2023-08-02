import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main{

    static class Node{
        int count;
        char data;
        Map<Character,Node> child;

        public Node(){
            child=new HashMap<>();
            this.count=0;
        }
        public Node(char data){
            this.data = data;
            child=new HashMap<>();
            this.count=0;
        }

    }

    static boolean makeTree(Node move,String str){
        for(int i=0;i<str.length();i++){

            if(!move.child.containsKey(str.charAt(i))) {
                Node node=new Node(str.charAt(i));
                move.child.put(str.charAt(i),node);
                move=node;
            }else{

                if(i==str.length()-1){
                    return false;
                }
                Node node=move.child.get(str.charAt(i));
                if(node.count==1){
                    return false;
                }
                move= node;
            }
            if(i==str.length()-1){
                move.count=1;
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());
        boolean check=true;

        for(int i=0;i<n;i++){
            check=true;
            Node root= new Node();
            //트리를 초기화 해줘야하므로 반복문 안에 넣어줘야 함
            int k=Integer.parseInt(br.readLine());
            for(int j=0;j<k;j++){
                String str=br.readLine();
                if(!makeTree(root,str)){
                    System.out.println("NO");
                    check=false;
                    for(int t=0;t<k-j-1;t++){
                        br.readLine();
                        //문자열을 모두 확인하기 전에 NO가 발생한다면
                        //남아있는 문자열을 읽어서 없애줘야함
                    }
                    break;
                }
            }
            if(check==true){
                System.out.println("YES");
            }
        }
    }
}