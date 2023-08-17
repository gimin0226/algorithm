import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        //System.out.println(t);
        for (int k = 0; k < t; k++) {
            int n = Integer.parseInt(br.readLine());
            List<Pair> list=new ArrayList<>();
            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine(), " ");
                int x=Integer.parseInt(st.nextToken());
                int y=Integer.parseInt(st.nextToken());
                list.add(new Pair(x,y));
            }
            Collections.sort(list,Collections.reverseOrder());

            int i=1;
            int num=n;
            while(true){
                if(i==list.size()){
                    break;
                }
                if (list.get(i).getY()>list.get(i-1).getY()) {
                    list.remove(i);
                    num-=1;
                }else{
                    i++;
                }
            }
            System.out.println(num);
        }
    }

    static class Pair implements Comparable<Pair> {
        private int x;
        private int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getX(){
            return this.x;
        }

        public int getY(){
            return this.y;
        }

        public int compareTo(Pair pair){
            if(pair.getX()>this.getX()){
                return 1;
            }else if(pair.getX()<this.getX()){
                return -1;
            }
            return 0;
        }

    }
}