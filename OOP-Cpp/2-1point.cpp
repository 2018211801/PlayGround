#include <iostream>
#include <cmath>
using namespace std;

class point 
{
   public:
      double distance(point another);
      void getpoint( void );
      void setpoint(double px,double py);
      point();//�����޲ι��캯�� 
      point(double px,double py);  // ���ǹ��캯��
   private:
      double x;
      double y;
};
 
// ��Ա�������壬�������캯��
point::point(double px,double py)
{
    cout <<"Object is being created, x,y= " << px<<","<<py << endl;
    x = px;
    y=py;
}

point::point()
{
	cout<<"This is no parameter obj(created func)"<<endl;
	x=0;
	y=0;
}
void point::setpoint( double px,double py )
{
    x=px;
    y=py;
}

void point::getpoint( void )
{
    cout<<"The point's position is: "<<x<<","<<y<<endl;
}


double point::distance(point another)
{
	double dx=x-another.x;
	double dy=y-another.y;
	return sqrt(dx*dx+dy*dy);
}
// �����������
int main( )
{
   point C;
   C.getpoint();
   cout<<"Now create 2 objs,input x1,y1,x2,y2 in a line:"<<endl;
   double a,b,c,d;
   cin>>a>>b>>c>>d;
   point A(a,b);
   point B(c,d);
   cout<<"The distance between them is"<<A.distance(B)<<endl;
   return 0;
}
