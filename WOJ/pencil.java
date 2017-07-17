import java.util.*;
import java.util.Scanner;

public class pencil{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int m=sc.nextInt();
    int n=sc.nextInt();
    int num=sc.nextInt();
    int total=0;
    int unuse=0;
    while(true){
      //販売するから代入
      //鉛筆を作る
        System.out.println(num);
        total+=num;
      if(num<m){
        if((unuse+num)>m){
          num+=unuse;
          unuse=0;
          unuse=num%m;
          num=(num/m)*n;
        } else {
        break;
      }
    } else {
      unuse+=num%m;
      num=(num/m)*n;
    }
  }
    System.out.println(total);
}
}