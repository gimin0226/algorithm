class Solution {
    public int[] solution(int brown, int yellow) {
        
        for(int m=0;m<10000;m++){   
            for(int n=m;n<10000;n++){        
                if(n>=m&&2*n+2*m+4==brown&&n*m==yellow){
                    return new int[]{n+2,m+2};
                }
            }
        }
        return null;
    }
}
