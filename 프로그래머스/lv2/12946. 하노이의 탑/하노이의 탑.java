import java.util.*;

class Solution {
    
    ArrayList<int[]> al = new ArrayList<>();;
    public int[][] solution(int n) {
        
        hanoi(n, 1, 3, 2);       
        int[][] answer = new int[al.size()][2];
        for(int i = 0 ; i < al.size() ; i++){
            int[] arr = al.get(i);
            answer[i][0] = arr[0];
            answer[i][1] = arr[1];  
        }
        
        return answer;
    }
    
    public void hanoi(int n, int from, int to, int through){
        int[] move = {from, to};
        
        if(n == 1) {
            al.add(move);
        } else {
            hanoi(n - 1, from, through, to);
            al.add(move);
            hanoi(n - 1, through, to, from);   
        }
    }
}