class Solution {
   
    int[][] arr;
    public int solution(int[][] triangle) {
        
        int n=triangle.length;
      //  System.out.println(n);
        arr=triangle;
       
        recursion(n-1);
        int answer=arr[0][0];
        return answer;
    }
     /*
      0 1 2 3 4
   0  7
   1  3 8
   2  8 1 0
   3  2 7 4 4
   4  4 5 2 6 5
    */
    public void recursion(int n){
        for(int j=n;j>0;j--){
            for(int i=0;i<j;i++){
                arr[j-1][i]+=(arr[j][i]>arr[j][i+1])?arr[j][i]:arr[j][i+1];
            }
        }
    }
}