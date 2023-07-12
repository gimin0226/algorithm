import java.util.stream.IntStream;
import java.util.Arrays;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        
        int [] result=new int[commands.length];
        for(int i=0;i<commands.length;i++){
            int[] array2=IntStream.range(commands[i][0]-1,commands[i][1]).map(num->array[num]).toArray();
            Arrays.sort(array2);
            result[i]=array2[commands[i][2]-1];
           
        }
        
        return result;
    }
}