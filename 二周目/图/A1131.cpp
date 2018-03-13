#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
#define maxn 10000
int line[maxn][maxn];
vector<int> v[maxn];
vector<int> tempPath,path;
int minTransfer=100000000;

void DFS(int index, int ending){
    if (index==ending) {
        tempPath.push_back(index);
        //遍历路径，求出换乘次数
        int transfer=0;
        int nowLine=line[tempPath[0]][tempPath[1]];
        for (int i=1; i<tempPath.size()-1; i++) {
            int id1=tempPath[i],id2=tempPath[i+1];
            if (nowLine!=line[id1][id2]) {
                nowLine=line[id1][id2];
                transfer++;
            }
        }
        if(path.size()==0 || tempPath.size()<path.size()){
            path=tempPath;
            minTransfer=transfer;
        }else if(tempPath.size()==path.size() && transfer<minTransfer){
            path=tempPath;
            minTransfer=transfer;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(index);
    for(int i=0;i<v[index].size();i++){
        int next = v[index][i];
        DFS(next, ending);
    }
    tempPath.pop_back();
}

int main(int argc, const char * argv[]) {
    int N,K;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        int M,a,b;
        scanf("%d",&M);
        scanf("%d",&a);
        for (int j=1; j<M; j++) {
            scanf("%d",&b);
            v[a].push_back(b);
            v[b].push_back(a);
            line[a][b]=line[b][a]=i;
            a=b;
        }
    }
    scanf("%d",&K);
    for(int i=0;i<K;i++){
        int start,ending;
        scanf("%d%d",&start,&ending);
        path.clear();
        tempPath.clear();
        minTransfer=100000000;
        DFS(start,ending);
        printf("%d\n",path.size());
        int lastIndex=start;
        int lastLine=line[path[0]][path[1]];
        for (int i=1; i<path.size()-1; i++) {
            if (line[path[i]][path[i+1]]!=lastLine) {
                printf("Take Line#%d from %04d to %04d.\n",lastLine,lastIndex,path[i]);
                lastIndex=path[i];
                lastLine=line[path[i]][path[i+1]];
            }
            if (path[i+1]==ending) {
                printf("Take Line#%d from %04d to %04d.\n",lastLine,lastIndex,path[i+1]);
            }
        }
    }
}

