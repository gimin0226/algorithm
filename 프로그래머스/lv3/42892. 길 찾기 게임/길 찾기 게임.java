
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
      //  System.out.println(node.data+" ");
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
        
        Node root=MakeTree(nodes);
       // System.out.println(root.right.right.data);
        
        List<Integer> preorderList = new ArrayList<Integer>();
        preorder(root,preorderList);
        
        List<Integer> postorderList=new ArrayList<Integer>();
        postorder(root,postorderList);
        
        return new int[][]{
            preorderList.stream().mapToInt(Integer::intValue).toArray(),
            postorderList.stream().mapToInt(Integer::intValue).toArray(),
        };
    }
}