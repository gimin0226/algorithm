import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
        String[] str=br.readLine().split(" ");
        int n=Integer.parseInt(str[0]);
        int m=Integer.parseInt(str[1]);


        str=new String[n];
        for(int i=0;i<n;i++){
            str[i]=br.readLine();
        }
        int [][] arr= new int[n+2][m+2];

        int[][] left_up=new int[n+2][m+2];
        int[][] right_up=new int[n+2][m+2];
        int[][] left_down=new int[n+2][m+2];
        int[][] right_down=new int[n+2][m+2];

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                arr[i][j]=str[i-1].charAt(j-1)-'0';
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(arr[i][j]==0){
                    left_up[i][j]=0;right_up[i][j]=0;
                }else if(arr[i][j]==1){
                    left_up[i][j]=(left_up[i-1][j-1]==0)?1:(left_up[i-1][j-1]+1);
                    right_up[i][j]=(right_up[i-1][j+1]==0)?1:(right_up[i-1][j+1]+1);
                }
            }
        }

        for(int i=n;i>=1;i--){
            for(int j=1;j<=m;j++){
                if(arr[i][j]==0){
                    left_down[i][j]=0;right_down[i][j]=0;
                }else if(arr[i][j]==1){
                    left_down[i][j]=(left_down[i+1][j-1]==0)?1:(left_down[i+1][j-1]+1);
                    right_down[i][j]=(right_down[i+1][j+1]==0)?1:(right_down[i+1][j+1]+1);
                }
            }
        }

        int max_size= 0;

        for(int i=1;i<=n;i++){
            int length;

            for(int j=1;j<=m;j++){
                if((length=Math.min(left_down[i][j],right_down[i][j]))>max_size){
                   
                   for(int t=length;t>max_size;t--) {
                       int ptr=(t-1)*2;
                       if (i + ptr <= n && Math.min(left_up[i + ptr][j], right_up[i + ptr][j]) >= t) {
                           max_size = t;
                          // System.out.println("가i:" + i + "j:" + j + "size" + max_size);
                           break;
                       }

                   }
                }
            }
        }
        System.out.println(max_size);


    }
}