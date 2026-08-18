import java.util.*;
public class J01009 {
    public static void main (String [] args){
        Scanner sc = new Scanner (System.in);
        int n = sc.nextInt();
        long gt = 1;
        long sum  =0 ;
        for (int i = 1; i<= n ;i++){
            gt *=i;
            sum += gt;
        }
        System.out.println (sum);
    }
}
