
import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int[][] solution(int[][] arr) {
        
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
        int[][] answer = {};
        return answer;
    }
}