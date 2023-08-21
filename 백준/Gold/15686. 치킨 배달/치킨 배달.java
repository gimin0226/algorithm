import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static List<Pair> chicken;
    static List<Pair> home;

    static int n;
    static int m;
    static Deque<Integer> deque;
    static int[] arr2;

    static int min=Integer.MAX_VALUE;
    static int[][] distance;

    public static void main(String[] args)throws IOException {
        chicken=new ArrayList<Pair>();
        home= new ArrayList<Pair>();

        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st= new StringTokenizer(br.readLine()," ");
        n=Integer.parseInt(st.nextToken());
        m=Integer.parseInt(st.nextToken());
        deque=new LinkedList<>();
        int [][]arr=new int[n][n];

        for(int i=0;i<n;i++){
            st=new StringTokenizer(br.readLine()," ");
            int count=st.countTokens();
            for(int j=0;j<count;j++){
                arr[i][j]=Integer.parseInt(st.nextToken());
                if(arr[i][j]==1){
                    home.add(new Pair(i,j));
                }else if(arr[i][j]==2){
                    chicken.add(new Pair(i,j));
                }
            }
        }
        
        distance= new int[chicken.size()][home.size()];

        for(int i=0;i<chicken.size();i++){
            for(int j=0;j<home.size();j++){
                distance[i][j]=Math.abs(home.get(j).getX()-chicken.get(i).getX())+
                        Math.abs(home.get(j).getY()-chicken.get(i).getY());
            }
        }

        backTracking(-1,0);
        System.out.println(min);
    }

    static void backTracking(int n,int t){

        if(t==m){
            Iterator<Integer> iterator2=deque.iterator();
            int ptr=0;
            for(int i=0;i<home.size();i++){

                int min2=Integer.MAX_VALUE;
                Iterator<Integer> iterator  = deque.iterator();
                while(iterator.hasNext()){
                    int q=distance[iterator.next()][i];
                    if(q<min2){
                        min2=q;
                    }
                }
                ptr+=min2;
             //   System.out.println("home"+ptr);
            }
            if(ptr<min){
                min=ptr;
             //   System.out.println(min);

            }
        }
        for(int i=0;i<chicken.size();i++){
            if(i>n){
                deque.add(i);
                backTracking(i,t+1);
                deque.removeLast();
            }
        }
    }
    static class Pair{
        private int x;
        private int y;
        public Pair(int x,int y){
            this.x=x;
            this.y=y;
        }

        public int getX(){
            return x;
        }
        public int getY(){
            return y;
        }


    }
}
