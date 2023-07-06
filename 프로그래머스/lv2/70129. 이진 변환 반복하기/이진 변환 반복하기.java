class Solution {
    	public int turn=0;
	public int RemovedNumber0=0;
	
	public int[] solution(String s) {
		
		String string=s;
		while(true) {
			string=BinaryConversion(string);
			turn+=1;
			//System.out.println("s:"+string+"turn:"+turn+"RemovedNumber0:"+RemovedNumber0);
			if(string.equals("1")) {
				break;
			}
		}
		int[] answer=new int[] {turn,RemovedNumber0};
		return answer;
	}
	
	public String BinaryConversion(String str) {
		int length=countChar(str);
		str=Integer.toString(length,2);
		return str;
	}
	
	public int countChar(String str) {
		int len=str.length();
		int len2=str.replace("1", "").length();
		RemovedNumber0+=len2;
		return len-len2;
	}
}