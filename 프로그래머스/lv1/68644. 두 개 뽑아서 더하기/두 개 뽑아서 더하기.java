import java.util.Arrays;
import java.util.Vector;


class Solution {
    public int[] solution(int[] numbers) {
       Vector<Integer> vec=new Vector<Integer>();
        for(int i=0;i<numbers.length-1;i++){
            for(int j=i+1;j<numbers.length;j++){
                int num= numbers[i]+numbers[j];
                if(!vec.contains(num)){
                    vec.add(num);
                }
            }
        }
        
        int[] result=vec.stream().mapToInt(i->i).toArray();
        Arrays.sort(result);
  
        return result;
    }
}