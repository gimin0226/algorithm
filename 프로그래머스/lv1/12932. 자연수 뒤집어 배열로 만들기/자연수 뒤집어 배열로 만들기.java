

class Solution {
	public int[] solution(long n) {
		String str = Long.toString(n);
        int[] result=new int[str.length()];
       
		for(int i=str.length()-1,j=0;i>=0;i--,j++){
            result[j]=str.charAt(i)-'0';
            
        }
		return result;
	}
}
    
    
    
