/*
5.2 ��Point�����أ����ͨD�D�����     ��дC++����������¹��ܣ�
 ��1�� Point ������԰���������꣨x��y���� 
 ��2�� ʵ�� Point �����أ����ͨD�D������� ? ++p��--p��p++��p--��ע�������ǲ�һ���ģ����� 
											 ? �����ͨD�D�ֱ��ʾ x��y ���ӻ���� 1�� 
*/ 

//�Ժ��п���ϸ����
 
#include <iostream>
using namespace std;

class point
{
      private:
         int x;
         int y;
      public:
         void setpoint(int a,int b)
         {
              x=a;
              y=b;
         }
         
         void output()
         {
              cout<<"("<<x<<","<<y<<")"<<endl;
         }
         
         point()
         {}//���캯�� 
         ~point()
         {}//��������
         
         point operator ++ (int)
         {
               point r;
               r.x=x+1;
               r.y=y+1;
               return r;
         }
         
         point operator --(int)
         {
               point r;
               r.x=x-1;
               r.y=y-1;
               return r;
         }
         
         point operator ++()
         {
               point r;
               x=x+1;
               y=y+1;
               r.x=x;
               r.y=y;
               return r;
         }
         
         point operator --()
         {
               point r;
               x=x-1;
               y=y-1;
               r.x=x;
               r.y=y;
               return r;
         }         
} ;
         
int main()
{
      point o,t;
      int m,n;
      cout<<"�����������꣺"<<endl;
      cin>>m>>n;
      o.setpoint(m,n);
      while(1){
      int choose;
      cout<<"��ѡ������:1.p++ 2.p-- 3.++p 4.--p 0.exit()"<<endl;
      cin>>choose;
      
      if(choose==1)
      {
           t=(o++);
           cout<<"����������Ϊ��"<<endl;
           t.output();
      }
      if(choose==2)
      {
           t=(o--);
           cout<<"����������Ϊ��"<<endl;
           t.output();  
      }
      if(choose==3)
      {
           t=(++o);
           cout<<"����������Ϊ��"<<endl;
           t.output();       
      }
      if(choose==4)
      {
           t=(--o);
           cout<<"����������Ϊ��"<<endl;
           t.output();                   
      }  
      if(choose==0)
      	break;
  }
      system("pause");
      return 0;
} 
