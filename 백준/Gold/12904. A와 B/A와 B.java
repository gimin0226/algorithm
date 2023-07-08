import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sca=new Scanner(System.in);
        String x=sca.nextLine();
        String y=sca.nextLine();
        StringBuilder sb=new StringBuilder(y);
        while(true){
            if(sb.length()==x.length()){
                if(sb.toString().equals(x)){
                    System.out.println(1);
                    return;
                }else {
                    System.out.println(0);
                    return;
                }
            }
            if(sb.charAt(sb.length()-1)=='B'){
            	//System.out.println("daf");
                sb.deleteCharAt(sb.length()-1);
                sb.reverse();
              //  System.out.println(sb.toString());
            }else if(sb.charAt(sb.length()-1)=='A'){
                sb.deleteCharAt(sb.length()-1);
            }

        }

    }
}