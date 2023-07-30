import java.util.Stack;
class Solution {
 public int[] solution(int[] prices) {
     
     int num=1;
     int[] answer = new int[prices.length];
     for(int i=0;i<prices.length;i++){
         answer[i]=prices.length-i-1;
     }
     
     Stack<Integer> sta= new Stack<Integer>();
     sta.push(0);
     for(int i=1;i<prices.length;i++){
         if(prices[i]>=prices[sta.peek()]){
             sta.push(i);
         }else if(prices[i]<prices[sta.peek()]){
             while(true){
                 answer[sta.peek()]=i-sta.peek();
                 sta.pop();
                 if(sta.empty()||prices[i]>=prices[sta.peek()]){
                     break;
                 } 
             }
             sta.push(i);
         }
     }        
     return answer; 
        
 }
}
