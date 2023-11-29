/*TSP�������̰�ķ���������Ӳ���*/
/*
	TSP������ָ���м���Ҫ����n�����У�Ҫ��������о����ҽ�����һ�Σ�
	Ȼ��ص��������У��������ߵ�·����̡�
*/
/*
	������Ӳ��ԣ�ÿ��������ͼ�ķ�Χ��ѡ����̵ı߼��뵽�⼯���У���֤�⼯���еı������γ�һ�����ܶ��ٻ�·
*/
#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
using namespace std;
/*TSP��*/
class TSP
{
	public:
        int start_city;		                //������
		int end_city;			//�յ����
		int distance;			//����֮��ľ���	
		TSP(int sta,int end,int dis);	//���캯��
		TSP();				//Ĭ�Ϲ��캯��
		void init(int sta,int end,int dis);	//��ʼ������
		void printfInfo();			//��ӡ��Ϣ	
};
/*����ԭ������*/
int cmp(TSP t1,TSP t2);							//�����������
int TSP2(TSP *t,int city_num,int cities,TSP *process);  //���������TSP
int find(int x,int *pre);						//Ѱ��ǰ�ý��
void join(int x,int y,int *pre);					//�ϲ����
//���캯��
TSP::TSP(int sta,int end,int dis)
{
	start_city=sta;
    end_city=end;
	distance=dis;
}
//Ĭ�Ϲ��캯��
TSP::TSP()
{
}
//��ʼ������
void TSP::init(int sta,int end,int dis)
{
    start_city=sta;
    end_city=end;
	distance=dis;
}
//��ӡ��Ϣ����
void TSP::printfInfo()
{
	cout<<start_city<<"\t"<<end_city<<"\t"<<distance<<"\t\n";
}
 
//�������
int cmp(TSP t1,TSP t2)
{
	return t1.distance<t2.distance;
}
 
//�����·���TSP����
int TSP2(TSP *t,int city_num,int cities,TSP *process)
{
	int TSPLength=0;
	int i=0,j=0,k=0;
	int *flag=new int[city_num];	//��¼���Ķ���
	int *pre=new int[city_num];		//��¼����ǰ�ý��
	for(i=0;i<city_num;i++)
	{
		flag[i]=0;					//��ʼ������Ϊ0
		pre[i]=i;					//ÿ������ǰ�ý������Ϊ�Լ�
	}
	do{
		for(i=0;i<cities;i++)
		{
			if(find(t[i].start_city,pre)!=find(t[i].end_city,pre))//��������ӵĵ����ڲ�ͬ�ļ���
			{
				if(flag[t[i].start_city]<=2 && flag[t[i].end_city]<=2)//���������֧
				{
					flag[t[i].start_city]++;	//������1
				    flag[t[i].end_city]++;
					TSPLength+=t[i].distance;	//����·������
					//����·��
					process[k].start_city=t[i].start_city;
					process[k].end_city=t[i].end_city;
					process[k].distance=t[i].distance;
				//	cout<<"�ӳ���"<<t[i].start_city<<"������"<<t[i].end_city<<",����Ϊ"<<t[i].distance<<endl;
					j++;
					k++;
					join(t[i].start_city,t[i].end_city,pre);//�������ڵļ��Ϻϲ�
				}
			}
		}
	}while(j<city_num-1);
	//�ҵ�����Ϊ1��������
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
	//�ҵ����һ���ߵĳ���
	for(i=0;i<cities;i++)
		if(t[i].start_city==m && t[i].end_city==n)
			process[k].distance=t[i].distance;
	TSPLength+=process[k].distance;
	return TSPLength;
}
 
//��ǰ�ý��
int find(int x,int *pre)
{
    int r=x;
    while(pre[r]!=r)
    r=pre[r];		//�ҵ�ǰ�����
    int i=x,j;
    while(i!=r)		//·��ѹ���㷨
    {
        j=pre[i];	//��¼x��ǰ�����
        pre[i]=r;	//��i��ǰ���������Ϊr���ڵ�
        i=j;
    }
    return r;
}
 
//�ϲ����
void join(int x,int y,int *pre)
{
    int a=find(x,pre);	//x�ĸ��ڵ�Ϊa
    int b=find(y,pre);	//y�ĸ��ڵ�Ϊb
    if(a!=b)			//���a,b������ͬ�ĸ��ڵ㣬��˵��ab������ͨ��
    {
        pre[a]=b;		//��ab���� ��a��ǰ���������Ϊb
    }
}
 
//������
int main()
{
	cout<<"������и���";
	int city_number,cities=0; 
	while(cin>>city_number)
	{
		int i,j,k=0;
		for(i=1;i<city_number;i++)
		   cities+=i;
		//����
		TSP *tsp=new TSP[cities];			//��¼���г��е�·��
		TSP *process=new TSP[city_number];	//�����������·��
 
	    //��ʼ�����۾���
		cout<<"������еĴ��۾���"<<endl;
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
		//���ɶ������� 
		for(i=0;i<city_number;i++)
		{
		    for(j=i+1;j<city_number;j++)
			{
			   tsp[k].init(i,j,distance[i][j]);
			   k++;
			 }
		}
		//�����������
		cout<<"���\t"<<"�յ�\t"<<"����\t"<<endl;
		for(i=0;i<cities;i++)
		{
		    tsp[i].printfInfo();	
		}
        cout<<"-------------------------------------"<<endl;
		//����
		sort(tsp,tsp+cities,cmp);
		cout<<"\n�����"<<endl;
		cout<<"���\t"<<"�յ�\t"<<"����\t"<<endl;
		for(i=0;i<cities;i++)
		{
		    tsp[i].printfInfo();	
		}
		cout<<"-------------------------------------"<<endl;
		//����������TSP����
		cout<<"������������̣�"<<endl;
		int length=TSP2(tsp,city_number,cities,process);
		cout<<"���\t"<<"�յ�\t"<<"����\t"<<endl;
		for(i=0;i<city_number;i++)
		{
		    process[i].printfInfo();	
		}
		cout<<"·������:"<<length<<endl;
        delete[] tsp;
	}
	return 0;
}