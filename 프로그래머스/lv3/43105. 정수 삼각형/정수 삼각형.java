class Solution {

    public int solution(int[][] triangle) {
        int n=triangle.length-1;
        for(int j=n;j>0;j--){
            for(int i=0;i<j;i++){
                triangle[j-1][i]+=(triangle[j][i]>triangle[j][i+1])?triangle[j][i]:triangle[j][i+1];
            }
        }
        
        int answer=triangle[0][0];
        return answer;
    }

}