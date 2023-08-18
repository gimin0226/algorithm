import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int k = 0; k < t; k++) {
            int n = Integer.parseInt(br.readLine());
            StringTokenizer st;
            PriorityQueue<Integer> minPq = new PriorityQueue<>();
            PriorityQueue<Integer> maxPq = new PriorityQueue<>((a, b) -> Integer.compare(b, a));
            HashMap<Integer, Integer> hm = new HashMap<>();

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine(), " ");
                String operation = st.nextToken();
                int num = Integer.parseInt(st.nextToken());

                if (operation.equals("I")) {
                    minPq.offer(num);
                    maxPq.offer(num);
                    hm.put(num, hm.getOrDefault(num, 0) + 1);
                } else if (operation.equals("D")) {
                    PriorityQueue<Integer> pq = (num == 1) ? maxPq : minPq;
                    while (!pq.isEmpty() && hm.get(pq.peek()) <= 0) {
                        pq.poll();
                    }
                    if (!pq.isEmpty()) {
                        int top = pq.poll();
                        hm.put(top, hm.get(top) - 1);
                    }
                }
            }

            while (!maxPq.isEmpty() && hm.get(maxPq.peek()) <= 0) {
                maxPq.poll();
            }

            while (!minPq.isEmpty() && hm.get(minPq.peek()) <= 0) {
                minPq.poll();
            }

            if (minPq.isEmpty() || maxPq.isEmpty()) {
                System.out.println("EMPTY");
            } else {
                System.out.println(maxPq.peek() + " " + minPq.peek());
            }
        }
    }
}