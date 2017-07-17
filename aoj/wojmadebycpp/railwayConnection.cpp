// g++ temp.cpp
// C++ includes used for precompiling -*- C++ -*-

// Copyright (C) 2003-2013 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/** @file stdc++.h
 *  This is an implementation file for a precompiled header.
 */

// 17.4.1.2 Headers

// C
//#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
/*
//#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
*/

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
/*
//#if __cplusplus >= 201103L
#include <array>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
*/
using namespace std;
#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define mp(a,b) make_pair(a,b)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;

#define INF INT_MAX/3
#define MAX_M 120
#define MAX_N 20
int n,m,c,s,g;
//会社数とノードの番号
int d[MAX_N+5][MAX_M+5][MAX_M+5];
int cost[22][22222];
int dc[111][111];
void init(){
  rep(i,MAX_N+5){
    rep(j,MAX_M+5){
      rep(k,MAX_M+5){
        d[i][j][k]=(j==k?0:INF);
      }
    }
  }
}

void solve(){
    while(cin>>n>>m>>c>>s>>g){
      if(n==0) break;
    s--;
    g--;
    init();
    rep(i,m){
      int x,y,cmp,dd;
      //最小距離で入力する
      cin>>x>>y>>dd>>cmp;
      x--;
      y--;
      cmp--;
      d[cmp][x][y]=d[cmp][y][x]=min(dd,d[cmp][x][y]);
    }
    int p[MAX_N+5];
    rep(i,c) cin>>p[i];
    rep(i,c){
      int q[55],r[55];
      rep(j,p[i]-1) cin>>q[j];
      rep(j,p[i]) cin>>r[j];
      int nq=0;
      cost[i][0]=0;
      rep(dd,20010){
        if(nq<p[i]-1&&dd==q[nq]) nq++;
        //nqをプラスにすることで運賃が距離によって安くなっているのを
        //更新することが出来る。
        cost[i][dd+1] = cost[i][dd]+r[nq];
      }
    }
    //ワ-シャルフロイド
    rep(cmp,c){
      rep(k,n){
        rep(i,n){
          rep(j,n){
            minch(d[cmp][i][j],d[cmp][i][k]+d[cmp][k][j]);
          }
        }
      }
    }
    //会社を考慮しない金額の計算
    rep(i,n){
      rep(j,n){
        dc[i][j]=(i==j?0:INF);
      }
    }
    rep(i,c){
      rep(j,n){
        rep(k,n){
          //d[i][j][k]が会社iが保有するj~kの道のりの長さ
          //道があったら計算する
         if(d[i][j][k]!=INF) minch(dc[j][k],cost[i][d[i][j][k]]);
        }
      }
    }
    //ワ～シャルフロイド
    rep(k,n){
        rep(i,n){
          rep(j,n){
            minch(dc[i][j],dc[i][k]+dc[k][j]);
          }
        }
      }
      if(dc[s][g]==INF) cout<<"-1"<<endl;
      else cout<<dc[s][g]<<endl;
  }
  }
int main(){
  solve();
  return 0;
}