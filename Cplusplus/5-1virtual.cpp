/*
5.1 �麯�� �����Ŀ3�� ����״ ���࣬��дC++����������¹��ܣ�
 ��1�� ������״�� �еĻ����������ķ�������Ϊ�麯�����Ƚ��롾��״��A������ ��Ĳ��죻 
 ��2�� ������״���еĻ��ඨ��Ϊ�����࣬�Ƚ��롾��״��A��������Ĳ��졣 
*/

#include <iostream>
const double PI=3.14;
using namespace std;

class shape
{
	public:
		virtual float area()
		{
			
		}
		shape()
		{
			cout<<"����һ��shape����"<<endl;
		}
		
		~shape(){
			cout<<"����һ��shape����"<<endl; 
		}
		
 };
 
 class rectangle:public shape//extends shape
 {
 	private:
 		float length,width;
 	public:
 		rectangle(float a,float b)
 		{
 			//�������Ĺ��캯��,this����ʽָ�� 
 			cout<<"���������쳤����"<<endl;
 			this->length=a;
 			this->width=b;
		 }
		rectangle()
		{
			cout<<"����һ��������"<<endl;
		}
		
		void set(float a,float b)
		{
			//set����
			this->length=a;
			this->width=b; 
		}
		
		~rectangle(){
			cout<<"����������"<<endl; 
		}
		
		float area()
		{
			return length*width;
		}
  }; 
  
  class circle:public shape
  {
  	private:
  		float radius;
  		float x,y;
  	public:
  		circle()
  		{
  			cout<<"����һ��Բ"<<endl;
		  }
		~circle()
		{
			cout<<"����һ��Բ"<<endl;
		}
		circle(float radius,float x,float y)
		{
			cout<<"���ι���һ��Բ"<<endl;
			this->radius=radius;
			this->x=x;
			this->y=y;
		}
		void set(float radius,float x,float y)
		{
			this->radius=radius;
			this->x=x;
			this->y=y;
		}
		
		float area()
		{
			return PI*radius*radius;
		}
  };
  
  class square:public rectangle
  {
  	friend class circle; //test
  	private:
         float bianchang;
    public:
    	 square(float a):rectangle(a,a)
         {
         	 cout<<"���������������"<<endl;
             bianchang=a;
         }
         ~square()
         {
         	cout<<"����������"<<endl;
		 }
  };
  int main()
{
     float a,b;
     cout<<"��������εĳ��Ϳ�:"<<endl;
     cin>>a>>b;
     rectangle M(a,b);
     cout<<"���ε����Ϊ��"<<M.area()<<endl; 
     
     float r,x,y;
     cout<<"������Բ�İ뾶,x,y position��"<<endl;
     cin>>r>>x>>y;
     circle C(r,x,y);
     cout<<"Բ�����Ϊ��"<<C.area()<<endl;
     
     float c;
     cout<<"�����������α߳���"<<endl;
     cin>>c;
     square Z(c);
     cout<<"�����ε����Ϊ��"<<Z.area()<<endl;
     
     system("pause");
     return 0; 
}
