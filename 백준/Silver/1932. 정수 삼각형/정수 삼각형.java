import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());
        StringTokenizer st;
        int[][] arr=new int[n][n];
        int[][] answer=new int[n][n];
        for(int i=0;i<n;i++){
            st=new StringTokenizer(br.readLine()," ");
            int j=0;
            while(st.hasMoreTokens()){
                arr[i][j]=Integer.parseInt(st.nextToken());
                j++;
            }
        }

        answer[0][0]=arr[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<i+1;j++){
                if(j==0){
                    answer[i][j]=arr[i][j] + answer[i-1][j];
                }else if(j==i){
                    answer[i][j]=arr[i][j] + answer[i-1][j-1];
                }else{
                    answer[i][j]=arr[i][j] + Math.max(answer[i-1][j],answer[i-1][j-1]);
                }
            }
        }

        System.out.println(Arrays.stream(answer[n-1]).max().getAsInt());



    }

}
