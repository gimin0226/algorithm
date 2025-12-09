import java.io.*;

class Main {
    static String original;
    static String best;
    static String[] parts = new String[3];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        original = br.readLine();

        dfsSplit(0, original);
        System.out.println(best);
    }

    static void dfsSplit(int depth, String remain) {
        if (depth == 2) {
            parts[2] = remain;
            String candidate = buildReversed();
            updateBest(candidate);
            return;
        }

        // 남은 부분에서 이번 조각 길이 선택
        // depth 0이면 앞으로 2조각이 더 필요 -> 최소 2글자 남겨야 함
        // depth 1이면 앞으로 1조각 더 필요 -> 최소 1글자 남겨야 함
        int need = 2 - depth;

        for (int i = 1; i <= remain.length() - need; i++) {
            parts[depth] = remain.substring(0, i);
            dfsSplit(depth + 1, remain.substring(i));
        }
    }

    static String buildReversed() {
        return new StringBuilder(parts[0]).reverse().toString()
             + new StringBuilder(parts[1]).reverse().toString()
             + new StringBuilder(parts[2]).reverse().toString();
    }

    static void updateBest(String candidate) {
        if (best == null || candidate.compareTo(best) < 0) {
            best = candidate;
        }
    }
}