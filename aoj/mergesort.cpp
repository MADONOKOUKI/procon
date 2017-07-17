#include <iostream>
#define REP(I,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
using namespace std;

int COUNT = 0;

void Merge(int a[],int left , int mid ,int right){
  int i,j,k;
  int n1 = mid - left;//配列の長さ
  int n2 = right - mid;//配列の長さ
  int L[n1+1],R[n2+1];//
  rep(i,n1) L[i] = a[left+i];//一番左の要素から順に代入していく
  rep(i,n2) R[i] = a[mid+i];//一番左の要素から順に代入していく
  L[n1]=R[n2]=0x7FFFFFFF;//一番最後にめっちゃでかい数字を代入しておく
  //これによって片方の配列の要素をすべて代入し終えたら、その後にもう片方の要素を代入していくことが出来る
  i=j=0;
  for(k=left;k<right;k++){
    COUNT++;
    if(L[i]<R[j]){
      a[k]=L[i];
      i++;
    } else {
      a[k] = R[j];
      j++;
    }
  }
}


void MergeSort(int a[],int left,int right){
  if(left+1<right){
    int mid = (left+right)/2;
    MergeSort(a,left,mid);//ソート
    MergeSort(a,mid,right);//ソート
    Merge(a,left,mid,right);//ソートした２つの列を統治する
  }
}

int main(){
  //速度を早める
  cin.tie(0);//tie
  ios::sync_with_stdio(false);//sync
  int n,i;

  //input
  cin>>n;
  int A[n];
  rep(i,n) cin >> A[i];
  MergeSort(A,0,n);

  //output
  rep(i,n){
    cout << A[i];
    if(i<n-1){
      cout<<" ";
    }
  }
    cout<<endl<<COUNT<<endl;
  return 0;
}