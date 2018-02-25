//序列A中n个数选k个数使得和为x，最大平方和为maxSumSqu
int n,k,x,maxSumSqu=-1,A[maxn];
//temp存放临时变量，ans存放平方和最大的方案
vector<int>temp, ans;

//当前处理的是index号整数，当前已选择的整数个数为nowK
//当前已选的整数之和为sum,当前已选的整数平方和为sumSqu 
//void DFS(int index,int nowK,int sum,int sumSqu){
//	if(nowK == k && sum == x){			//找到k个数的和为x 
//		if(sumSqu > maxSumSqu){
//			maxSumSqu=sumSqu;
//			ans = temp;
//		}
//		return;
//	}
//	//已经处理完n个数，或者超过k个数，或者和超过x,返回
//	if(index==n || nowK > k || sum>x) return; 
//	//选Index号数
//	temp.push_back(A[index]);
//	DFS(index+1,nowK+1,sum+A[index],sumSqu+A[index]*A[index]);
//	temp.pop_back();
//	DFS(index+1,nowK,sum,sumSqu); 
//} 

void DFS(int index, int nowK, int sum, int sumSqu){
	if(nowK==k && sum==x){
		if(sumSqu>maxSumSqu){
			maxSumSqu=sumSqu;
			ans=temp;
		}
		return;
	}
	if(index==n || sum>x || sumSqu > x) return;
	temp.push_back(index);
	DFS(index+1,nowK+1,sum+A[index],sumSqu+A[index]*A[index]);
	temp.pop_back();
	DFS(index+1,nowK,sum,sumSqu);
}
