class Solution {
    public int solution(String word) {
        String str = "AEIOU";
        int[] RateOfIncrease = {781,156,31,6,1};
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