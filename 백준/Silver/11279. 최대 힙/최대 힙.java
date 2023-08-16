import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {
        PriorityQueue<Integer> pq= new PriorityQueue<>(Collections.reverseOrder());
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());

        for(int i=0;i<n;i++){
            int ptr= Integer.parseInt(br.readLine());
            if(ptr==0){
                Integer t=pq.poll();
                if(t==null){
                    System.out.println("0");
                }else{
                    System.out.println(t);
                }
            }else{
                pq.add(ptr);
            }
        }
    }
}
