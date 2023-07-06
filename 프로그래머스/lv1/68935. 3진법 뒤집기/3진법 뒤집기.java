import java.util.Vector;

class Solution {
    	public long solution(int n) {
	
		Vector<Integer> vec=new Vector<Integer>();
		Base10ToBase3(n,vec);
		long answer=Base3ToBase10(vec);
		
		
		return answer;
	}
	
	public int Base10ToBase3(int n,Vector<Integer> vec) {
		
		if(n<3) {
			vec.add(n);
		}else if(n>=3) {
			Base10ToBase3(n/3,vec);
			vec.add(n%3);
		}
		return 0;
		
	}
	
	public long Base3ToBase10(Vector<Integer> vec){
		
		long k=1;
		long sum=0;
		for(int i=0;i<vec.size();i++)
		{
			sum+=k*vec.get(i);
			k*=3;
		}	
		return sum;
	}
}