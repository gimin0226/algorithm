
import java.util.*;
class Solution {
    class Node{
        public Node left;
        public Node right;
        
        public final int data;
        public final int x;
        public final int y;
        
        public Node(int data,int x,int y){
            this.data = data;
            this.x = x;
            this.y = y;
        }
    }
    
    public void LinkedNode(Node move,Node node){ 
        while(true){
            if(node.x>move.x){
                if(move.right==null){
                    move.right=node;
                    break;
                }else{
                    move=move.right;
                }
            }else if(node.x<move.x){
                if(move.left==null){
                    move.left=node;
                    break;
                }else{
                    move=move.left;
                }
            }
        }
    }
    
    
    public Node MakeTree(Node[] nodes){
        Node root= nodes[0];
        for(int i=1;i<nodes.length;i++){
            LinkedNode(root,nodes[i]);
        }
        return root;
    }
    
    
    public void preorder(Node node,List<Integer> list){
        if(node==null) return;
        
        list.add(node.data);
        preorder(node.left,list);
        preorder(node.right,list);
    }
    
    
    public void postorder(Node node,List<Integer> list){
        if(node==null){
           return;
        }
        
        postorder(node.left, list);
        postorder(node.right, list);
        list.add(node.data);
    }
    
    
    public int[][] solution(int[][] arr) {
        /*
        Arrays.sort(arr,new Comparator<int[]>() {
				public int compare(int[] o1,int[] o2) {
					if(o1[1]==o2[1]) {
						return o2[0]-o1[0];
					}else {
						return o2[1]-o1[1];
					}
				}
			});
			
        for(int i = 0; i < arr.length; i++) {
				for(int j = 0; j < 2; j++) {
					System.out.print(arr[i][j] + " ");
				}
				System.out.println();
        }
        
        Node[] nodes= new Node[arr.length];
        for(int i=0;i<nodes.length;i++){
            nodes[i]=new Node(i+1,arr[i][0],arr[i][1]);
        }*/
        
        Node[] nodes= new Node[arr.length];
        for(int i=0;i<nodes.length;i++){
            nodes[i] = new Node(i+1,arr[i][0],arr[i][1]);
        }
        Arrays.sort(nodes, (a,b)->b.y-a.y);
	/*
	    a와 b의 y필드 값을 비교하는 Comparator을 람다 표현식으로 정의
	    b.y - a.y >0 이면 b가 a보다 뒤에 위치하게 된다.
        */
        Node root=MakeTree(nodes);
        
        List<Integer> preorderList = new ArrayList<Integer>();
        preorder(root,preorderList);
        
        List<Integer> postorderList=new ArrayList<Integer>();
        postorder(root,postorderList);
        
        return new int[][]{
            preorderList.stream().mapToInt(Integer::intValue).toArray(),
            postorderList.stream().mapToInt(Integer::intValue).toArray(),
	//List를 스트림으로 변환-> mapToInt()메소드를 통해 Integer객체의 intValue메소드를 호출하여 그 결과인 int 값을 요소로 하는 새로운 IntStream을 생성->그 후 스트림의 모든 요소를 배열로 모아서 반환
        };
    }
}
