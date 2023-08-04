import java.util.Scanner;

public class Main {
    public static final int NO= -99999999;

    public static void main(String[] args) {
        Scanner sca = new Scanner(System.in);
        int n = sca.nextInt();
        int m = sca.nextInt();

        int[][] arr = new int[n+2][m+2];
        int[][] up = new int[n+2][m+2];
        int[][] right=new int[n+2][m+2];
        int[][] left= new int[n+2][m+2];

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                arr[i][j]=sca.nextInt();
            }
        }

        for(int i=0;i<n+2;i++){
            up[i][0]=NO;
            left[i][0]=NO;
            right[i][0]=NO;
            up[i][m+1]=NO;
            left[i][m+1]=NO;
            right[i][m+1]=NO;
        }
        for(int i=0;i<m+2;i++){
            up[0][i]=NO;
            left[0][i]=NO;
            right[0][i]=NO;
            up[n+1][i]=NO;
            left[n+1][i]=NO;
            right[n+1][i]=NO;
        }
        left[1][1]=arr[1][1];right[1][1]=arr[1][1];up[1][1]=arr[1][1];
        //System.out.println(up[1][1]+" "+left[1][1]+" "+right[1][1]);
        for(int i=1;i<n+1;i++){

            for(int j=1;j<m+1;j++){
                if(i==1){
                    if(j==1){
                        continue;
                    }
                    up[i][j]=NO;
                    left[i][j]=left[i][j-1]+arr[i][j];
                    //System.out.println("i:"+i+"j:"+j+" "+left[i][j]);
                    continue;
                }
                if(j==1){
                    left[i][j]=NO;
                    up[i][j]=arr[i][j]+Math.max(right[i-1][j],up[i-1][j]);
                    continue;
                }

                up[i][j]=arr[i][j]+Math.max(Math.max(right[i-1][j],left[i-1][j]),up[i-1][j]);
                left[i][j]=arr[i][j]+Math.max(left[i][j-1],up[i][j-1]);
            }

            for(int j=m;j>=1;j--){
                if(i==1){
                    if(j==1){
                        continue;
                    }
                    right[i][j]=NO;
                    continue;
                }
                if(j==m){
                    right[i][j] =NO;
                    continue;
                }
                right[i][j]= arr[i][j]+Math.max(right[i][j+1],up[i][j+1]);
            }
        }
       // System.out.println(up[2][2]+" "+left[2][2]+" "+right[2][2]);
        //System.out.println(up[n][m]+" "+left[n][m]+" "+right[n][m]);
        System.out.println(Math.max(Math.max(up[n][m],left[n][m]),right[n][m]));


    }
}