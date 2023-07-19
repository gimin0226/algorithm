class Solution {
    public int solution(int[][] triangle) {
        for(int j=triangle.length-1;j>0;j--){
            for(int i=0;i<j;i++){
                triangle[j-1][i]+=(triangle[j][i]>triangle[j][i+1])?triangle[j][i]:triangle[j][i+1];
            }
        }
        return triangle[0][0];   
    }
}