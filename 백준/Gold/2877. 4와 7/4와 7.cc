#include <bits/stdc++.h>
using namespace std;
int main(){int N,i;cin>>N;N+=1;for(i=log2(N)-1;i>=0;i--){cout<<(N&(1<<i)?7:4);}}
