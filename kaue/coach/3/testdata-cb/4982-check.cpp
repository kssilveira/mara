/*
  Sprawdzarka, byc moze trzeba ja jeszcze troche przyspieszyc, w tej chwili dziala mi maks 5 sekund na jednym tescie.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cassert>
#include<bitset>
using namespace std;
#define MAX 200
#define MAX_ANS 1000000
int n,seen[MAX],next_seen,matched[2][MAX],pre[1<<16];
char e[MAX][MAX];
bool dfs(int x){
  if(seen[x]==next_seen)return false;
  seen[x]=next_seen;
  for(int y=0;y<n;y++)if(e[x][y]=='1'&&(matched[1][y]==-1||dfs(matched[1][y]))){
    matched[0][x]=y;
    matched[1][y]=x;
    return true;
  }
  return false;
}
int ee[MAX][8],dead[8],dest,stack[MAX*MAX],stack_size,ans;
bool cycle(int x){
  stack[stack_size++]=x;
  seen[x]=next_seen;
  for(int i=(n-1)/32;i>=0;i--){
    int mask=ee[x][i]&~dead[i],pos;
    while(pos=__builtin_ffs(mask)){
      pos--;
      int y=32*i+pos;
      if(y!=matched[0][x]&&(y==dest||seen[matched[1][y]]<next_seen&&cycle(matched[1][y]))){
        matched[0][x]=y;
        matched[1][y]=x;
        return true;
      }
      mask^=1<<pos; 
    }
  }
  stack_size--;
  return false;
}
void process(int a){
  if(ans>MAX_ANS)throw 0xdead;
//niezmiennik: mamy perfect matching na wierzcholkach
  if(!a){ans++;return;}
  if(a==3){
    int code=0;
    for(int i=0;i<4;i++)for(int j=0;j<4;j++)if(e[i][matched[0][j]]=='1')code|=1<<4*i+j;
    ans+=pre[code];
    return;
  }
  int b=matched[0][a];
  dead[b/32]^=1<<b%32;
  process(a-1);
  dead[b/32]^=1<<b%32;
  dest=b;
  next_seen++;
  int stack_begins=stack_size;
  if(cycle(a)){
    e[a][b]='0';
    ee[a][b/32]^=1<<b%32;
    process(a);
    for(int i=stack_size-2;i>=stack_begins;i--){
      int x=stack[i+1],y=matched[0][stack[i]];
      matched[0][x]=y;
      matched[1][y]=x;
    }
    stack_size=stack_begins;
    matched[0][a]=b;
    matched[1][b]=a;
    e[a][b]='1';
    ee[a][b/32]^=1<<b%32;
  }
  stack_size=stack_begins;
}
int calc(){
  for(int i=0;i<n;i++)matched[0][i]=matched[1][i]=-1;
  for(int i=0;i<n;i++){
    next_seen++;
    if(!dfs(i))return 0;
  }
  ans=0;
  try{
    memset(ee,0,sizeof(ee));
    memset(dead,0,sizeof(dead));
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(e[i][j]=='1')ee[i][j/32]|=1<<j%32;
    process(n-1);
    return ans;
  }catch(...){return MAX_ANS+1;}
}
bool calc2(){
  bitset<MAX> t[n];
  for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(e[i][j]=='1')t[i].set(j);
  for(int i=0;i<n;i++){
    int j=i;
    while(j<n&&!t[j].test(i))j++;
    if(j==n)return 0;
    swap(t[i],t[j]);
    for(int j=0;j<n;j++)if(i!=j&&t[j].test(i))t[j]^=t[i]; 
  }
  return 1;
}
int main(int argc,char *argv[]){
  for(int code=0;code<(1<<16);code++){
    int t[4]={0,1,2,3};
    do{
      for(int i=0;i<4;i++)if(!(code&1<<4*i+t[i]))goto fail; 
      pre[code]++;
fail:;
    }while(next_permutation(t,t+4));
  }
  FILE *in=fopen(argv[1],"r"),*out=fopen(argv[2],"r"),*correct_out=fopen(argv[3],"r");
  int Z,C;
  fscanf(in,"%d",&Z);
  for(int z=1;z<=Z;z++){
    fscanf(in,"%d",&C);
    assert(1<=C&&C<=MAX_ANS);
    if(fscanf(out,"%d",&n)!=1){printf("WRONG\nIncorrect answer format.\n");return 0;}
    if(n<1||MAX<n){printf("WRONG\nIncorrect number of vertices.\n");return 0;}
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(fscanf(out," %c",&e[i][j])!=1||(e[i][j]!='0'&&e[i][j]!='1')){printf("WRONG\nIncorrect graph description.\n");return 0;}
//    fprintf(stderr,"%d %d\n",C,n);
    if(calc2()!=C%2){printf("WRONG\nIncorrect number of perfect matchings mod 2.\n");return 0;}
    if(calc()!=C){printf("WRONG\nIncorrect number of perfect matchings.\n");return 0;}
  }
  puts("OK");
}

