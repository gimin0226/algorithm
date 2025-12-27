import java.util.*;
import java.lang.*;
import java.io.*;

// The main method must be in a class named "Main".
class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st;
        List<Pair> pairs = new ArrayList<>();
        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            int x =Integer.parseInt(st.nextToken());
            int y =Integer.parseInt(st.nextToken());
            Pair pair = new Pair(x,y);
            pairs.add(pair);
        }

        pairs.sort(new Comparator<Pair>(){
             @Override
             public int compare(Pair a, Pair b){
                int q= Integer.compare(a.getY(),b.getY());
                if(q!=0) return q;
                return Integer.compare(a.getX(),b.getX());
             }
        });

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for(Pair p:pairs){
            bw.write(p.getX()+" "+p.getY());
            bw.newLine();
        }
        bw.flush();
        
    }

    public static class Pair{
        private int x;
        private int y;

        public Pair(int x, int y){
            this.x = x;
            this.y = y;
        }

        public int getX(){
            return x;
        }
        public int getY(){
            return y;
        }
    }
}