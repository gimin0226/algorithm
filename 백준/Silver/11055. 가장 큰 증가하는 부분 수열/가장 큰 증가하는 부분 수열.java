import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner scanner= new Scanner(System.in);
        int n= scanner.nextInt();
        int[] arr=new int[n];
        int[] size = new int[n];

        for(int i=0;i<n;i++){
            arr[i]=scanner.nextInt();
        }

        size[0]=arr[0];

        for(int i=1;i<n;i++){
            int max=0;
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j]){
                    if(size[j]>max){
                        max=size[j];
                    }
                }
                if(j==i-1){
                    size[i]=arr[i]+max;
                }
            }
        }

        int max=size[0];
        for(int i=0;i<n;i++){
         
            if(max<size[i]){
                max=size[i];
            }
        }

       System.out.println(max);
    }
}
