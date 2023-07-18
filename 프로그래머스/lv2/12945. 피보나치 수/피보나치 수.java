class Solution {
    public int F[];
    
	public int solution(int n) {
		F=new int[n+1];
		F[0]=0;
		F[1]=1;
		recursion(n);
		
		
		int answer=F[n]%1234567;
		
		return answer;
	}
	
	public void recursion(int n) {
		for(int i=2;i<=n;i++) {
			F[i]=F[i-1]%1234567+F[i-2]%1234567;
		}
	}
}