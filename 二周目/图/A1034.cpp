//A1034

#include <iostream>
#include <map>
using namespace std;
#define maxn 2005
int N,K;
map<string, int> strToInt;
map<int, string> intToStr;
map<string,int> result;
int cnt=0;
int e[maxn][maxn];
int v[maxn];
bool vis[maxn];
void change(string x){
    if (strToInt.find(x)==strToInt.end()) {
        strToInt[x]=cnt;
        intToStr[cnt]=x;
        cnt++;
    }

}
bool checked[maxn][maxn];
void DFS(int now, int &head, int &total,int &peopleNum){
    vis[now]=true;
    if(v[now]>v[head]){
        head=now;
    }
    for(int i=0;i<cnt;i++){
        if(!checked[now][i] && e[now][i]!=0){
            total+=e[now][i];
            checked[i][now]=checked[now][i]=true;
        }
        if (e[now][i]!=0 && !vis[i]) {
//            DFS(i, head, total, peopleNum+1);
            peopleNum++;
            DFS(i, head, total, peopleNum);
        }
    }
}

int main(int argc, const char * argv[]) {
    cin>>N>>K;
    for (int i=0; i<N; i++) {
        string a,b;
        int time;
        cin>>a>>b>>time;
        change(a);
        change(b);
        e[strToInt[a]][strToInt[b]]+=time;
        e[strToInt[b]][strToInt[a]]+=time;
        v[strToInt[a]]+=time;
        v[strToInt[b]]+=time;
    }
    for (int i=0; i<cnt; i++) {
        if(!vis[i]){
            int head=i;
            int total=0;
            int peopleNum=1;
            DFS(i, head, total, peopleNum);
            if(total > K && peopleNum>2){
                result[intToStr[head]]=peopleNum;
            }
        }
    }
    
    cout<<result.size()<<endl;
    
    for(map<string,int>::iterator it=result.begin();it!=result.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}

