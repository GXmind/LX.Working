#include <bits/stdc++.h>
using namespace std;
 

class Square
{

public:
	void setradius (double rad1,double abs1,double crd1,double rad2,double abs2, double crd2);                        
	void location();                                   
private:
	double radius1;       
	double abscissa1;
	double ordinate1;
    double radius2;       
	double abscissa2;
	double ordinate2;
};

//定义类函数
void Square::setradius (double rad1,double abs1, double crd1,double rad2,double abs2, double crd2)
{
	radius1=rad1;
	abscissa1=abs1;
	ordinate1=crd1;
    radius2=rad2;
	abscissa2=abs2;
	ordinate2=crd2;
}

void Square::location ()
{
    if(abscissa1<abscissa2)
    {
        swap(abscissa1,abscissa2);
    }
    if(abscissa1<abscissa2)
    {
        swap(ordinate1,ordinate2);
    }
    if(radius1<radius2)
    {
        swap(radius1,radius2);
    }
    int a=(abscissa1-abscissa2)*2;
    int b=(ordinate1-ordinate2)*2;
    int c=(radius1+radius2);
    if(a<c&&b<c)
    {
        std::cout << "They are intersectant"<<endl;
    }
    
    
    
    
    else
    {
        std::cout << "They are disjoint"<<endl;
    }
    
    
}


int main()
{
    int i=0;	
    scanf("%d",&i);
	Square Circular[i];
	double r1,x1,y1,r2,x2,y2;
    
    while(i--)
    {
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        Circular[i].setradius (r1,x1,y1,r2,x2,y2);
	    Circular[i].location();
        i++;
    }
	return 0;
}
