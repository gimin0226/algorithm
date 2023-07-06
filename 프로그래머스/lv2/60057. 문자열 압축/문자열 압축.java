import java.util.Arrays;

class Solution {
 	public int solution(String s) {
		int answer=0;
		//StringBuilder sb=new StringBuilder(s);
		int n=s.length()/2;
		//문자열이 "abcabcabcabcdededededede"라 하자 
		//s.length()=24; n=s.length()/2=12;
		//만약 n=13이면 24=13+11로 절대로 두 개로 나눠질 수 없다.
		///따라서 n=s.length()/2까지만 체크해도 된다.
		int len=s.length();
		if(len==1) {
			answer=1;
			return answer;
		}
		int result[]=new int[n];
		for(int i=1;i<=n;i++) {
			int n2=s.length()/i;
			//i=3이면 n2=24/3=8 8번 나눠서 비교하면 됨
			
			String[] str=new String[n2];
			for(int j=0;j<n2;j++) {
				
				str[j]=s.substring(i*(j),i*(j+1));
				//0~3,3~6, ... ,18~21
			//	if(i==2)System.out.print(str[j]+" ");
				
			}//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
			//ab ca bc ab ca bc de de de de de 
			//abc abc abc abc ded ede ded ede
			int check=1;
			int len2=len;
			for(int j=0;j<n2-1;j++) {
				if(str[j].equals(str[j+1])) {
					if(check==1) {
						check++;
						len2-=i;
						len2+=1;
					}else if(check==9||check==99) {
						check++;
						len2+=1;
						//System.out.println("sdaf");
						len2-=i;
					}else if(check>1) {
						check++;
						len2-=i;
					}
					
				}else {
					check=1;
				}
			}
			result[i-1]=len2;
		//	System.out.println("i:"+i+" len:"+len2);
		}
		
		//abcabcabcabc6de
		Arrays.sort(result);
		answer=result[0];
		
		
		
		
		return answer;
	}
}