import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        int[] up = new int[n];
        int[] down = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
            up[i]=1;down[i]=1;
        }


        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i] && up[j] >= up[i]) {
                    up[i] = up[j]+1;
                }

                if (arr[j] > arr[i]) {
                    if (down[j] >= down[i]) {
                        down[i] = down[j]+1;
                    }
                    if (up[j] >= down[i]) {
                        down[i] = up[j]+1;
                    }

                }


            }
        }

        int max=up[0];

        for(int i=0;i<n;i++){
            if (max<up[i]) {
                max=up[i];
            }
            if(max<down[i]){
                max=down[i];
            }
        }

        System.out.println(max);
    }
}