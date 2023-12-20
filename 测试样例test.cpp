/*TSP问题采用贪心法的最短链接策略*/
/*
	TSP问题是指旅行家需要旅行n个城市，要求各个城市经过且仅经过一次，
	然后回到出发城市，并且所走的路径最短。
*/
/*
	最短链接策略：每次在整个图的范围内选择最短的边加入到解集合中，保证解集合中的边最终形成一个哈密尔顿回路
*/
#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
using namespace std;
/*TSP类*/
class TSP
{
	public:
        int start_city;		                //起点城市
		int end_city;			//终点城市
		int distance;			//两者之间的距离	
		TSP(int sta,int end,int dis);	//构造函数
		TSP();				//默认构造函数
		void init(int sta,int end,int dis);	//初始化函数
		void printfInfo();			//打印信息	
};
/*函数原型声明*/
int cmp(TSP t1,TSP t2);							//定义排序规则
int TSP2(TSP *t,int city_num,int cities,TSP *process);  //最短链接求TSP
int find(int x,int *pre);						//寻找前置结点
void join(int x,int y,int *pre);					//合并结点
//构造函数
TSP::TSP(int sta,int end,int dis)
{
	start_city=sta;
    end_city=end;
	distance=dis;
}
//默认构造函数
TSP::TSP()
{
}
//初始化函数
void TSP::init(int sta,int end,int dis)
{
    start_city=sta;
    end_city=end;
	distance=dis;
}
//打印信息函数
void TSP::printfInfo()
{
	cout<<start_city<<"\t"<<end_city<<"\t"<<distance<<"\t\n";
}
 
//排序规则
int cmp(TSP t1,TSP t2)
{
	return t1.distance<t2.distance;
}
 
//最短链路求解TSP问题
int TSP2(TSP *t,int city_num,int cities,TSP *process)
{
	int TSPLength=0;
	int i=0,j=0,k=0;
	int *flag=new int[city_num];	//记录结点的度数
	int *pre=new int[city_num];		//记录结点的前置结点
	for(i=0;i<city_num;i++)
	{
		flag[i]=0;					//初始结点度数为0
		pre[i]=i;					//每个结点的前置结点设置为自己
	}
	do{
		for(i=0;i<cities;i++)
		{
			if(find(t[i].start_city,pre)!=find(t[i].end_city,pre))//如果边连接的点属于不同的集合
			{
				if(flag[t[i].start_city]<=2 && flag[t[i].end_city]<=2)//不会产生分支
				{
					flag[t[i].start_city]++;	//度数加1
				    flag[t[i].end_city]++;
					TSPLength+=t[i].distance;	//增加路径长度
					//保存路径
					process[k].start_city=t[i].start_city;
					process[k].end_city=t[i].end_city;
					process[k].distance=t[i].distance;
				//	cout<<"从城市"<<t[i].start_city<<"到城市"<<t[i].end_city<<",距离为"<<t[i].distance<<endl;
					j++;
					k++;
					join(t[i].start_city,t[i].end_city,pre);//两点所在的集合合并
				}
			}
		}
	}while(j<city_num-1);
	//找到度数为1的两个点
	int m,n;
	for(m=0;m<city_num;m++)
		if(flag[m]==1)
		{
			process[k].start_city=m;
			flag[m]++;
			break;
		}
	for(n=0;n<city_num;n++)
		if(flag[n]==1)
		{
			process[k].end_city=n;
			flag[n]++;
			break;
		}
	//找到最后一条边的长度
	for(i=0;i<cities;i++)
		if(t[i].start_city==m && t[i].end_city==n)
			process[k].distance=t[i].distance;
	TSPLength+=process[k].distance;
	return TSPLength;
}
 
//找前置结点
int find(int x,int *pre)
{
    int r=x;
    while(pre[r]!=r)
    r=pre[r];		//找到前导结点
    int i=x,j;
    while(i!=r)		//路径压缩算法
    {
        j=pre[i];	//记录x的前导结点
        pre[i]=r;	//将i的前导结点设置为r根节点
        i=j;
    }
    return r;
}
 
//合并结点
void join(int x,int y,int *pre)
{
    int a=find(x,pre);	//x的根节点为a
    int b=find(y,pre);	//y的根节点为b
    if(a!=b)			//如果a,b不是相同的根节点，则说明ab不是连通的
    {
        pre[a]=b;		//将ab相连 将a的前导结点设置为b
    }
}
 
//主函数
int main()
{
	cout<<"输入城市个数";
	int city_number,cities=0; 
	while(cin>>city_number)
	{
		int i,j,k=0;
		for(i=1;i<city_number;i++)
		   cities+=i;
		//声明
		TSP *tsp=new TSP[cities];			//记录所有城市的路径
		TSP *process=new TSP[city_number];	//最短链接求解的路径
 
	    //初始化代价矩阵
		cout<<"输入城市的代价矩阵"<<endl;
		int **distance;
		distance=new int*[city_number];
		for(i=0;i<city_number;i++)
		{
			distance[i]=new int[city_number];
			for(j=0;j<city_number;j++)
			{
		     	cin>>distance[i][j];
			}
		}
		//生成对象数组 
		for(i=0;i<city_number;i++)
		{
		    for(j=i+1;j<city_number;j++)
			{
			   tsp[k].init(i,j,distance[i][j]);
			   k++;
			 }
		}
		//输出对象数组
		cout<<"起点\t"<<"终点\t"<<"距离\t"<<endl;
		for(i=0;i<cities;i++)
		{
		    tsp[i].printfInfo();	
		}
        cout<<"-------------------------------------"<<endl;
		//排序
		sort(tsp,tsp+cities,cmp);
		cout<<"\n排序后"<<endl;
		cout<<"起点\t"<<"终点\t"<<"距离\t"<<endl;
		for(i=0;i<cities;i++)
		{
		    tsp[i].printfInfo();	
		}
		cout<<"-------------------------------------"<<endl;
		//最短链接求解TSP问题
		cout<<"最短链接求解过程："<<endl;
		int length=TSP2(tsp,city_number,cities,process);
		cout<<"起点\t"<<"终点\t"<<"距离\t"<<endl;
		for(i=0;i<city_number;i++)
		{
		    process[i].printfInfo();	
		}
		cout<<"路径长度:"<<length<<endl;
        delete[] tsp;
	}
	return 0;
}