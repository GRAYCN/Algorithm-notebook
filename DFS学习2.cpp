//����A��n����ѡk����ʹ�ú�Ϊx�����ƽ����ΪmaxSumSqu
int n,k,x,maxSumSqu=-1,A[maxn];
//temp�����ʱ������ans���ƽ�������ķ���
vector<int>temp, ans;

//��ǰ�������index����������ǰ��ѡ�����������ΪnowK
//��ǰ��ѡ������֮��Ϊsum,��ǰ��ѡ������ƽ����ΪsumSqu 
//void DFS(int index,int nowK,int sum,int sumSqu){
//	if(nowK == k && sum == x){			//�ҵ�k�����ĺ�Ϊx 
//		if(sumSqu > maxSumSqu){
//			maxSumSqu=sumSqu;
//			ans = temp;
//		}
//		return;
//	}
//	//�Ѿ�������n���������߳���k���������ߺͳ���x,����
//	if(index==n || nowK > k || sum>x) return; 
//	//ѡIndex����
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
