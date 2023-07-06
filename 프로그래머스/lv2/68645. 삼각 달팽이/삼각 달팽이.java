class Solution {
    public int[] solution(int n) {
      int[] answer= new int[n*(n+1)/2];
		int [][] arr =new int[n][n];
		int i=0,j=0;
		arr[0][0]=1;
		int num=2;
		//1<=num<=n(n+1)/2
		
		if(n==1) {
			answer[0]=1;
			return answer;
		}
		loopOut:
		while(true) {
			//세로(행)이동 시작
			while(i+1<n&&arr[i+1][j]==0) {
				arr[++i][j]=num++;
				//System.out.println("i:"+i+"j:"+j);
				if(num>n*(n+1)/2) {
					break loopOut;
				}
			}
			//가로(열)이동 시작
			while(j+1<n&&arr[i][j+1]==0) {
				arr[i][++j]=num++;
				//System.out.println("i:"+i+"j:"+j);
				if(num>n*(n+1)/2) { 
					break loopOut;
				}
			}
			//대각선 이동 시작
			while(arr[i-1][j-1]==0) {
				arr[--i][--j]=num++;
				//System.out.println("i:"+i+"j:"+j);
				if(num>n*(n+1)/2) { 
					break loopOut;
				}
			}
			
		}
		int ptr=0;
		for(int x=0;x<n;x++) {
			for(int y=0;y<=x;y++) {
				answer[ptr++]=arr[x][y];
			}
		}
		return answer;
    
    
    }
    
}