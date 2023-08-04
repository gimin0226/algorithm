import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int n=scanner.nextInt();
        int[][] arr= new int[n][3];
        int[][] cost= new int[n][3];


        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                arr[i][j]=scanner.nextInt();
            }
        }

        cost[0][0]=arr[0][0];cost[0][1]=arr[0][1];cost[0][2]=arr[0][2];

        for(int i=1;i<n;i++){
            cost[i][0]=arr[i][0]+((cost[i-1][1]>cost[i-1][2])?cost[i-1][2]:cost[i-1][1]);
            cost[i][1]=arr[i][1]+((cost[i-1][0]>cost[i-1][2])?cost[i-1][2]:cost[i-1][0]);
            cost[i][2]=arr[i][2]+((cost[i-1][1]>cost[i-1][0])?cost[i-1][0]:cost[i-1][1]);
        }

        int min=cost[n-1][0];
        for(int i=1;i<3;i++){
            if(min>cost[n-1][i]){
                min=cost[n-1][i];
            }
        }

        System.out.println(min) ;


    }
}
