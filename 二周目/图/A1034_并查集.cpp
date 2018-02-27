#include <iostream>
#include <map>
using namespace std;
#define maxn 2005
int N,K;
map<string, int> strToInt;
map<int, string> intToStr;
map<string,int> result;
int cnt=0;
int v[maxn];
bool vis[maxn];

int father[maxn];

void init(){
    for (int i=0; i<maxn; i++) {
        father[i]=i;
    }
}

int findFather(int x){
    int a=x;
    while (x!=father[x]) {
        x=father[x];
    }
    while (a!=father[a]) {
        int z=a;
        a=father[a];
        father[z]=x;
    }
    return x;
}

void Union(int a, int b){
    int fa=findFather(a);
    int fb=findFather(b);
    if(fa!=fb){
        if (v[fa]>v[fb]) {
            father[fb]=fa;
        }else{
            father[fa]=fb;
        }
    }
}

void change(string x){
    if (strToInt.find(x)==strToInt.end()) {
        strToInt[x]=cnt;
        intToStr[cnt]=x;
        cnt++;
    }
}

int peopleNum[maxn],totalLength[maxn];
string str1[maxn],str2[maxn];
int main(int argc, const char * argv[]) {
    cin>>N>>K;
    init();
    for (int i=0; i<N; i++) {
        string a,b;
        int time;
        cin>>a>>b>>time;
        str1[i]=a;
        str2[i]=b;
        change(a);
        change(b);
        v[strToInt[a]]+=time;
        v[strToInt[b]]+=time;
    }
    for (int i=0; i<N; i++) {
        Union(strToInt[str1[i]], strToInt[str2[i]]);
    }
    int setNum=0;
    for (int i=0; i<cnt; i++) {
        if(i==findFather(i)){
            setNum++;
        }
        peopleNum[findFather(i)]++;
        totalLength[findFather(i)]+=v[i];
    }
    
    
    
    for (int i=0; i<cnt; i++) {
        for (int i=0; i<cnt; i++) {
            if(i==findFather(i)){
                if(totalLength[i]>2*K && peopleNum[i]>2){
                    result[intToStr[i]]=peopleNum[i];
                }
            }
        }
    }
    
    cout<<result.size()<<endl;
    
    for(map<string,int>::iterator it=result.begin();it!=result.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}

