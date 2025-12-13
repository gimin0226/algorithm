import java.util.*;
import java.lang.*;
import java.io.*;

// The main method must be in a class named "Main".
class Main {
    public static void main(String[] args)throws IOException {

        int n;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n= Integer.parseInt(br.readLine());
        int m =Integer.parseInt(br.readLine());

        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(int i=0;i<n-1;i++){
            int x= Integer.parseInt(br.readLine());
            pq.add(x);
        }
        int max;
        int count =0;
        while(true){
            if(pq.isEmpty()){
                break;
            }
            max = pq.poll();
            //  System.out.println("max: "+max);
            if(max<m)break;
            max--;
            count++;
            m++;
            pq.add(max);
        }
        System.out.println(count);

        
    }
}