class Solution {
    public String solution(String s, int n) {
        String answer = "";
        char[] ch=s.toCharArray();
        StringBuilder sb=new StringBuilder();
        
        for(int i=0;i<s.length();i++){
            if(ch[i]>='a'&&ch[i]<='z'){
                int k=ch[i]+n;
                if(k>'z'){
                    ch[i]=(char)(k-(int)'z'+(int)'a'-1);   
                }else{
                    ch[i]=(char)k;
                }
                sb.append(ch[i]);
            }else if(ch[i]>='A'&&ch[i]<='Z'){
                int k=ch[i]+n;
                if(k>'Z'){
                    ch[i]=(char)((int)'A'+k-(int)'Z'-1);
                }else{
                    ch[i]=(char)k;
                }
                sb.append(ch[i]);          
            }else if(ch[i]==' '){
                sb.append(ch[i]);
            }
        }
        answer=sb.toString();
        return answer;
    }
}