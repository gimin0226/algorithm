import java.util.*;
import java.lang.*;
import java.io.*;

// The main method must be in a class named "Main".
class Main {
    public static String original;
    public static String current_string;
    public static String min_string;
    public static String parts[] =new String[4];
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        original = br.readLine();
        current_string = original;
        f(1);
        System.out.println(min_string);
    }

    public static void f(int depth){
        if(depth==3){
            parts[3]=current_string;
        //    System.out.println("depth: 3, parts[3]"+parts[3]);
            String candidate = reverse();
            updateMin(candidate);
            return;
        }
        for(int i=1;i<=current_string.length()-(3-depth);i++){
            String copy_string = current_string;
            parts[depth]= copy_string.substring(0,i);
          //  System.out.println("depth: "+depth+ ", parts[depth]:"+parts[depth]);
            current_string = copy_string.substring(i);
            f(depth+1);
            current_string = copy_string;
        }
    }

    public static String reverse(){
        return new StringBuilder(parts[1]).reverse().toString()
            + new StringBuilder(parts[2]).reverse().toString()
            + new StringBuilder(parts[3]).reverse().toString();
    }
    
    public static void updateMin(String candidate){
        if(min_string==null||min_string.isBlank()||candidate.compareTo(min_string)<0){
            min_string=candidate;
        }
    }
}
