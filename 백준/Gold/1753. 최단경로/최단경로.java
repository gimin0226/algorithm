import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int INF = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int start = Integer.parseInt(br.readLine());

        int[] distance = new int[n + 1];
        Arrays.fill(distance, INF);
        PriorityQueue<Node> pq = new PriorityQueue<>((o1, o2) -> Integer.compare(o1.cost, o2.cost));
        List<Node>[] list = new List[n + 1];
        distance[start] = 0;
        for (int i = 1; i <= n; i++) {
            list[i] = new ArrayList<>();
        }
        for (int i = 1; i <= m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            list[a].add(new Node(b, c));
        }

        pq.add(new Node(start, 0));
        while (!pq.isEmpty()) {
            Node ptr = pq.poll();
            if (ptr.cost > distance[ptr.idx])
                continue;
            for (int i = 0; i < list[ptr.idx].size(); i++) {
                Node ptr2 = list[ptr.idx].get(i);
                if (distance[ptr2.idx] > ptr.cost + ptr2.cost) {
                    distance[ptr2.idx] = ptr.cost + ptr2.cost;
                    pq.add(new Node(ptr2.idx, distance[ptr2.idx]));
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (distance[i] == INF) {
                System.out.println("INF");
            } else {
                System.out.println(distance[i]);
            }
        }


    }

    static class Node {
        int idx;
        int cost;

        Node(int idx, int cost) {
            this.idx = idx;
            this.cost = cost;
        }
    }
}
