import java.util.*;
import java.lang.*;
import java.io.*;

// The main method must be in a class named "Main".
class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st= new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        int[] result = new int[n];
        Map<Integer,List<Integer>> map = new HashMap<>();
        
        for(int i=0;i<n;i++){
            arr[i]= Integer.parseInt(st.nextToken());
            List<Integer> list = map.get(arr[i]);
            if(list==null){
                list= new ArrayList<>();
                map.put(arr[i],list);
            }
            list.add(i);
        }
        /*
        for(Map.Entry<Integer, List<Integer>> e:map.entrySet()){
            Integer key = e.getKey();
            List<Integer> value= e.getValue();
            System.out.println("key:"+key);
            for(int i=0;i<value.size();i++){
                System.out.print(value.get(i)+" ");
            }
            System.out.println();     
        }*/
        
        List<Integer> keys = new ArrayList<>(map.keySet());
        Collections.sort(keys);

        for(int i=0;i<keys.size();i++){
            List<Integer> list = map.get(keys.get(i));
            for(int j=0;j<list.size();j++){
                result[list.get(j)]=i;
            }
        }
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<n;i++){
            sb.append(result[i]).append(' ');
        }
        System.out.println(sb);
    }


}  