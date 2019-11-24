#include <iostream>
#include <cmath>
using namespace std;
/**************************************************
.cppһ���ʵ�� 
.hһ������� 
.hpp�ļ����Խ�������ʵ��д��һ�� 
*************************************************/ 
class circle
{
	private:
		double x,y,r;
	public:
		circle(double px,double py,double radius);
		bool isCross(circle another);
}; 
circle::circle(double px,double py,double radius)
{
	//cout<<"Plase input one obj's x,y,r in here"<<endl;
	x=px,y=py,r=radius;
}
bool circle::isCross(circle another)
{
	//��public�������Է���private��Ա���� 
	double dx=x-another.x;
	double dy=y-another.y;
	double dist=sqrt(dx*dx+dy*dy);
	if((dist<r+another.r)&&(dist>fabs(r-another.r)))
		return 1;
	else
		return 0;
}

int main()
{
	cout<<"Input x1,y1,r1,x2,y2,r2 in a line"<<endl;
	double a,b,c,d,r1,r2;
	cin>>a>>b>>r1>>c>>d>>r2;
	circle A(a,b,r1);
	circle B(c,d,r2);
	//cout<<A.r; private��Ա������ֱ�ӷ��� 
	if(A.isCross(B)==1)
		cout<<"They r crossed"<<endl;
	else
		cout<<"They r not crossed"<<endl;
}
