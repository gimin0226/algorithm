import java.io.*;
import java.util.*;

public class Main {

    static int arr[][];
    static int arr2[][];

    static HashMap<Integer, Boolean>[] width;
    static HashMap<Integer, Boolean>[] length;
    static HashMap<Integer, Boolean>[][] map;

    static ArrayList<int[][]> list;

    static Deque<Pair> deque;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        arr = new int[9][9];
        arr2 = new int[9][9];
        width = new HashMap[9];
        length = new HashMap[9];
        map = new HashMap[3][3];
        deque=new LinkedList<>();
        int num = 0;

        for (int i = 0; i < 9; i++) {
            width[i] = new HashMap<>();
            length[i] = new HashMap<>();
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                map[i][j] = new HashMap<>();
            }
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 1; j < 10; j++) {
                width[i].put(j, false);
                length[i].put(j, false);
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int t = 1; t < 10; t++) {
                    map[i][j].put(t, false);
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            st=new StringTokenizer( br.readLine()," ");
            for (int j = 0; j < 9; j++){
                int t=Integer.parseInt(st.nextToken());
                arr[i][j] = t;
                arr2[i][j] = t;
                if (arr[i][j] == 0) {
                    num++;
                    deque.add(new Pair(i,j));
                } else {
                    width[i].put(arr[i][j], true);
                    length[j].put(arr[i][j], true);
                    map[i / 3][j / 3].put(arr[i][j], true);
                    //       System.out.println(i+" "+j+" "+arr[i][j]);
                }

            }
        }


        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(arr[i][j]==0){
                    BackTracking();
                }
            }
        }

    }

    static void BackTracking() {
        if(deque.isEmpty()){
            //성공적으로 다 채움
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    System.out.print(arr2[i][j]+" ");
                }
                System.out.println();
            }
            System.exit(0);
        }
        Pair pair=deque.removeFirst();
        // System.out.println(pair.x+" "+pair.y);
        int check=0;
        for(int i=1;i<=9;i++){
            if(width[pair.x].get(i)==false&&length[pair.y].get(i)==false&&map[pair.x/3][pair.y/3].get(i)==false){
                check++;
                arr2[pair.x][pair.y]=i;
                width[pair.x].put(i,true);
                length[pair.y].put(i,true);
                map[pair.x/3][pair.y/3].put(i,true);
                BackTracking();
                arr2[pair.x][pair.y]=0;
                width[pair.x].put(i,false);
                length[pair.y].put(i,false);
                map[pair.x/3][pair.y/3].put(i,false);
            }
        }
        deque.addFirst(pair);

    }

    static class Pair{
        int x;
        int y;
        public Pair(int x,int y ){
            this.x=x;
            this.y=y;
        }
    }
}