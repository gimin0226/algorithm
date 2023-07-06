class Solution {
    public int[][] solution(int[][] arr1, int[][] arr2) {
        //arr1의 크기가 a*b , arr2의 크기가 b*c라 하자
        //곱한 결과 행렬의 크기는 a*c이다.
        int a=arr1.length; 
        int b=arr1[0].length;
        int c=arr2[0].length;  
        int[][] answer= new int[a][c];
        for(int i=0;i<a;i++){
            for(int j=0;j<c;j++){
                int sum=0;
                for(int t=0;t<b;t++){
                    sum+=arr1[i][t]*arr2[t][j];
                }
                answer[i][j]=sum;
            }
        }
            
            
        return answer;
    }
}