import java.util.*;

public class Main {


    static int end;
    static int start;

    static int INF = Integer.MAX_VALUE;
    static PriorityQueue<Node> pq;
    static HashMap<Integer, Integer> hm;

    public static void main(String[] args) {
        Scanner sca = new Scanner(System.in);
        start = sca.nextInt();
        end = sca.nextInt();
        hm = new HashMap<>();
        pq = new PriorityQueue<>();
        hm.put(start, 0);
        pq.add(new Node(start, hm.get(start)));
        int[] distance = new int[100001];
        Arrays.fill(distance, INF);
        if (start >= end) {
            System.out.println(start - end);
            return;
        }
        while (!pq.isEmpty()) {
            Node node = pq.poll();

            if (node.idx > 100000 || node.idx < 0) {
                continue;
            }
            //System.out.println("poll" + node.idx + " " + node.time);
            if (node.idx * 2 <= 100000 && distance[node.idx * 2] > node.time) {
                distance[node.idx * 2] = node.time;
                pq.add(new Node(node.idx * 2, node.time));
                // System.out.println("1 "+node.idx*2+" "+node.time);

            }
            if (node.idx + 1 <= 100000 && distance[node.idx + 1] > node.time + 1) {
                distance[node.idx + 1] = node.time + 1;
                pq.add(new Node(node.idx + 1, node.time + 1));
                //  System.out.println("2 "+(node.idx+1)+" "+(node.time+1));

            }
            if (node.idx - 1 >= 0 && distance[node.idx - 1] > node.time + 1) {
                distance[node.idx - 1] = node.time + 1;
                pq.add(new Node(node.idx - 1, node.time + 1));
                //System.out.println("3 "+(node.idx-1)+" "+(node.time+1));

            }
        }
        System.out.println(distance[end]);
    }

    static class Node implements Comparable<Node> {
        int idx;
        int time;

        public Node(int idx, int time) {
            this.idx = idx;
            this.time = time;
        }

        public int compareTo(Node node) {
            if (node.time < this.time) {
                return 1;
            } else if (node.time > this.time) {
                return -1;
            }
            else{
                if(Math.abs(end-this.time)<Math.abs(end-node.time)){
                    return -1;
                }else{
                    return 1;
                }
            }

        }
    }
}