import java.util.HashMap;
import java.util.Scanner;

public class Main {
    static Long n;
    static Long p;
    static Long q;

    static HashMap<Long,Long> hm;

    public static void main(String[] args){
        Scanner sca=new Scanner(System.in);
        n= sca.nextLong();
        p= sca.nextLong();
        q=sca.nextLong();

        hm=new HashMap<>();
        hm.put((long)0,(long)1);
        recursion(n);
        System.out.println(hm.get(n));

    }

    static Long recursion(Long n){
        if(hm.get(n)==null) {
            Long x=recursion(n / p);
            Long y=recursion(n / q);
            hm.put(n,(x+y));
            return x+y;
        }else{
            return hm.get(n);
        }

    }
}