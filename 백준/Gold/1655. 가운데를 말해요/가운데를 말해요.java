import java.io.*;
import java.nio.Buffer;
import java.util.Collections;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        BufferedWriter bw= new BufferedWriter(new OutputStreamWriter(System.out));
        //낮은 숫자가 우선
        PriorityQueue<Integer> pq2 = new PriorityQueue<>();
        //높은 숫자가 우선
        PriorityQueue<Integer> pq1 = new PriorityQueue<>(Collections.reverseOrder());
        if(arr[1]>=arr[0]){
            pq1.add(arr[0]);
            bw.write(String.valueOf(arr[0])+"\n");
            pq2.add(arr[1]);
            bw.write(String.valueOf(pq1.peek())+"\n");
        }else if(arr[1]<arr[0]){
            pq2.add(arr[0]);
            bw.write(String.valueOf(arr[0])+"\n");
            pq1.add(arr[1]);
            bw.write(String.valueOf(pq1.peek())+"\n");
        }


        for (int i = 2; i < n; i++) {
            if(pq2.peek()<=arr[i]){
                if(pq2.size()==pq1.size()){
                    pq2.add(arr[i]);
                    bw.write(pq2.peek()+"\n");
                }else if(pq2.size()>pq1.size()){
                    pq1.add(pq2.poll());
                    pq2.add(arr[i]);
                    bw.write(pq1.peek()+"\n");
                }else if(pq2.size()<pq1.size()){
                    pq2.add(arr[i]);
                    bw.write(pq1.peek()+"\n");
                }
            }else if(pq1.peek()<arr[i]&&arr[i]<pq2.peek()){
                if(pq2.size()==pq1.size()){
                    pq2.add(arr[i]);
                    bw.write(pq2.peek()+"\n");
                }else if(pq2.size()>pq1.size()){
                    pq1.add(arr[i]);
                    bw.write(pq1.peek()+"\n");
                }else if(pq2.size()<pq1.size()){
                    pq2.add(arr[i]);
                    bw.write(String.valueOf(pq1.peek())+"\n");
                }
            }else if(arr[i]<=pq1.peek()){
                if(pq2.size()==pq1.size()){
                    pq1.add(arr[i]);
                    bw.write(String.valueOf(pq1.peek())+"\n");
                }else if(pq2.size()>pq1.size()){
                    pq1.add(arr[i]);
                    bw.write(String.valueOf(pq1.peek())+"\n");
                }else if(pq2.size()<pq1.size()){
                    pq2.add(pq1.poll());
                    pq1.add(arr[i]);
                    bw.write(String.valueOf(pq1.peek())+"\n");
                }
            }
        }
        bw.flush();
        bw.close();
    }
}
