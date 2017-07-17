import java.util.*;
import java.util.Scanner;

public class KamokuSummary2{
  public static void main(String[] args){
    int l=0;
    Scanner sc = new Scanner(System.in);
    Map<String,Integer> map= new HashMap<String,Integer>();
    map.put("田中",80);
    map.put("佐藤",100);
    map.put("渡辺",90);
    map.put("山本",75);
    map.put("高橋",90);
    for(String name:map.keySet()){
      System.out.println(name+"->"+map.get(name));
    }
    for(String name:map.keySet()){
      l+=map.get(name);
    }
    System.out.println("合計:"+l);
    System.out.println("平均:"+l/5);
  }
}