class Solution {
    public String solution(String s) {
		String answer = "";
		StringBuilder sb=new StringBuilder();
		char[] charArr=s.toCharArray();
		int num=0;	
		for(int i=0;i<charArr.length;i++) {
			
			if(charArr[i]==' ') {
				charArr[i]=' ';
				num=0;
			}
			else if(num%2==0) {
				charArr[i]=Character.toUpperCase(charArr[i]);
				num++;
			}else if(num%2==1) {
				charArr[i]=Character.toLowerCase(charArr[i]);
				num++;
			}
		}
		for(int i=0;i<charArr.length;i++) {
			sb.append(charArr[i]);
		}
		answer=sb.toString();
		return answer;
	}
}