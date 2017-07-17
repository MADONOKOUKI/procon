import java.util.*;
import java.util.Scanner;

public class dis{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n=sc.nextInt();
    int r=0;
   ArrayList<Integer> x = new ArrayList<Integer>();
   ArrayList<Integer> y = new ArrayList<Integer>();
   while(n>r){
    x.add(sc.nextInt());
    y.add(sc.nextInt());
    r++;
   }
   int max=0;
   for(int o:x){
    for(int p:y){
      if(o+p>max){
        max=o+p;
      }
    }
   }
   System.out.println(max);
}
}