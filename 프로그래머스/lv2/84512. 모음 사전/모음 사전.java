class Solution {
    public int solution(String word) {
        String str = "AEIOU";
        int[] RateOfIncrease = {781,156,31,6,1};
        //aaaaa -> aaaae 1회
        //aaaa-> aaae  (aaaa-> (aaaaa->aaaae->aaaai->aaaao->aaaau) ->aaae ) 
        //길이가 4일 때는 길이가 5에서 총 5번 변화한 후 길이가 4로 돌아옴
        //따라서 5+1
        //aaa-> aae 
        //길이가 3일 때는 길이가 4일때의 증가율 *5+1
        //따라서 길이가 n일 때는 (길이가 n-1일때의 증가율)*5 + 1 이다.
        int answer=0;
        int index;
        
        answer+=word.length();
        for(int i=0;i<word.length();i++){
            index=str.indexOf(word.charAt(i));
            answer+=RateOfIncrease[i] * index;
        }
        return answer;
    }
}
