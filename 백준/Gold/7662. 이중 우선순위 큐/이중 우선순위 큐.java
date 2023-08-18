import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int k = 0; k < t; k++) {
            int n = Integer.parseInt(br.readLine());
            StringTokenizer st;
            TreeMap<Integer, Integer> map = new TreeMap<>();

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine(), " ");
                String op = st.nextToken();
                int num = Integer.parseInt(st.nextToken());

                if (op.equals("I")) {
                    map.put(num, map.getOrDefault(num, 0) + 1);
                } else if (op.equals("D")) {
                    if (map.isEmpty()) continue;
                    int keyToRemove;
                    if (num == 1) {
                        keyToRemove = map.lastKey();
                    } else {
                        keyToRemove = map.firstKey();
                    }
                    int count = map.get(keyToRemove);
                    if (count == 1) {
                        map.remove(keyToRemove);
                    } else {
                        map.put(keyToRemove, count - 1);
                    }
                }
            }

            if (map.isEmpty()) {
                System.out.println("EMPTY");
            } else {
                System.out.println(map.lastKey() + " " + map.firstKey());
            }
        }
    }
}
