import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int m;
    static int[] arr;

    static Deque<Integer> deque;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n];
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);

        deque = new LinkedList<>();

        backTracking(0, 0);
    }

    static void backTracking(int n, int length) {

        if (length == m) {
            Iterator<Integer> iterator=deque.iterator();
            while(iterator.hasNext()){
                System.out.print(iterator.next()+" ");
            }System.out.println();
            return;
        }
        for (int i = 0; i < arr.length; i++) {
            if(deque.contains(arr[i])){
                continue;
            }
            deque.add(arr[i]);
            backTracking(arr[i],length+1);
            deque.removeLast();
        }
    }
}
