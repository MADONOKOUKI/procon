import java.util.ArrayList;
import java.util.Scanner;

public class KamokuSummary{
  public static void main(String[] args){
    int l=0;
    Scanner sc = new Scanner(System.in);
    ArrayList<Integer> list = new ArrayList<Integer>();
    for(int i=0;i<4;i++){
      list.add(sc.nextInt());
    }
    for(int n : list){
      l+=n;
    }

    System.out.println("合計:"+l);
    System.out.println("平均:"+l/4);
  }
}