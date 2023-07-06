class Solution {
   public int num0=0;
	public int num1=0;
	public int[][] array;
	//문제는 0의 개수와 1의 개수를 원하므로 array를 인스턴스 변수로 선언함
    //재귀를 할 때 매개변수로 배열을 주는 것이 아닌 2차원 배열의 인덱스만 줌
	public int[] solution(int[][] arr) {
		array=arr;
		recursion(arr.length,0,0);
        int[] answer=new int[]{num0,num1};
		return answer;
		
	}

	public void recursion(int n,int x,int y) {
		if(n==1||isAllEquals(n,x,y)) {
			if(array[y][x]==0) {
				num0++;
			}else {
				num1++;
			}
            return;
		}else {
			recursion(n/2,x,y);
			recursion(n/2,x+n/2,y);  
			recursion(n/2,x,y+n/2);
			recursion(n/2,x+n/2,y+n/2);
            return;
		}
	}
    
	//매개변수 n(크기), x(가로 위치), y(세로 위치)를 통해
    //2차원 배열에서 주어진 범위의 수가 모두 같은지 검사
    //같으면 true 리턴 하나라도 다르면 멈추고 false 리턴
	public boolean isAllEquals(int n,int x,int y) {
		int check=array[y][x];
		for(int i=x;i<x+n;i++) {
			for(int j=y;j<y+n;j++) {
				if(check!=array[j][i]) {
					return false;
				}
			}
		}
		return true;
	}
}