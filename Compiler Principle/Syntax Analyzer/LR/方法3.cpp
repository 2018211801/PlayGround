#include<iostream>
#include<iomanip>
#include<stack>
#include<string> 
using namespace std;

stack<char> s;                                           //ջ 
char terminal[9]={'+','-','*','/','(',')','i','n','$'};  //�ս���� 
char unterminal[3]={'E','T','F'};                        //���ս���� 
char grammar[10][10]={                                   //�������ʽ 
     "SE","EE+T","EE-T","ET","TT*F",
     "TT/F","TF","Fi","F(E)","Fn"
     };
int Goto[17][3]={                           //�ֶ�����LR()�﷨Ԥ�������
     1,2,3,0,0,0,0,0,0,0,0,0,
     0,0,0,11,2,3,0,0,0,0,12,3,
     0,13,3,0,0,14,0,0,15,0,0,0,
     0,0,0,0,0,0,0,0,0,0,0,0,
     0,0,0,
     };
int Action[17][9]={
     0,0,0,0,5,0,4,6,0,
     7,8,0,0,0,0,0,0,-10,
     -3,-3,9,10,0,-3,0,0,-3,
     -6,-6,-6,-6,0,-6,0,0,-6,
     -7,-7,-7,-7,0,-7,0,0,-7,
     0,0,0,0,5,0,4,6,0,
     -9,-9,-9,-9,0,-9,0,0,-9,
     0,0,0,0,5,0,4,6,0,
     0,0,0,0,5,0,4,6,0,
     0,0,0,0,5,0,4,6,0,
     0,0,0,0,5,0,4,6,0,
     7,8,0,0,0,16,0,0,0,
     -1,-1,9,10,0,-1,0,0,-1,
     -2,-2,9,10,0,-1,0,0,-2,
     -4,-4,-4,-4,0,-4,0,0,-4,
     -5,-5,-5,-5,0,-5,0,0,-5,
     -8,-8,-8,-8,0,-8,0,0,-8,
     };
char str[30];                       //��������������ʽ
int len;                            //��������������ʽ�ĳ��� 

void Get_str(void)                  //��ȡ������������ʽ 
{ 
    printf("������������ı��ʽ��");
    scanf("%s",&str);
    
    for(len=0;str[len]!='\0';len++);
    str[len]='$';
    str[len+1]='\0';
    len++;
    s.push('0');
    }

int Judge_id(char ch)  //�ж��ַ��Ƿ�Ϊ����id����ĸ
{
    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
        return 1;
    else
        return 0;
    }

int Judge_num(char ch)  //�ж��ַ��Ƿ�Ϊ����num������                
{
    if(ch>='0'&&ch<='9')
        return 1;
    else
        return 0;   
    }

void Output_stack(void)  //��ӡ��ǰջ�еķ���
{
	char st[30];
	int i,j=0,number=s.size();
	
    for(i=0;i<number;i++)
    {
        st[i]=s.top();
        s.pop();
        }
    for(i=number-1;i>=0;i--)
    {
        if(st[i]=='i')
        {
           cout<<"id";
           j+=1;
           }
        else if(st[i]=='n')
        {
           cout<<"num";         
           j+=2;
           }
        else if(st[i]>'9'&&st[i]<'9'+10)
           cout<<st[i]-'0';
        else
           cout<<st[i];
        s.push(st[i]);
        }
    for(i=0;i<8-j-number;i++)
        cout<<" ";
    }

void Output_buffer(int ip)  //��ӡ��ǰ���뻺�����еķ��Ŵ�
{
    int i,j;
    
    cout<<"\t";
    for(i=ip;str[i]!='$';i++)
        cout<<str[i];
    cout<<"$";
    for(j=0;j<8-i+ip;j++)
        cout<<" ";
    }

int Get_ternum(char ch)   //�����ս�����ս�����е��±� 
{
    int i;
    for(i=0;i<9;i++)
       if(ch==terminal[i])
          return i;
    return -1;
    }

int Get_unternum(char ch)  //���ط��ս���ڷ��ս�����е��±� 
{
    int i;
    for(i=0;i<3;i++)
       if(ch==unterminal[i])
          return i;
    return -1;
    }

int Judge_ter(char ch)      //�ж��ַ��Ƿ�Ϊ�ս�� 
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')'||ch=='i'||ch=='n'||ch=='$')
       return 1;
    else
       return 0;    
    }

int Judge_unter(char ch)    //�ж��ַ��Ƿ�Ϊ���ս�� 
{
    if(ch=='E'||ch=='P'||ch=='T'||ch=='Q'||ch=='F')
       return 1;
    else
       return 0;
    }

void Analyse_output(void)      //ʹ��LR()�﷨Ԥ��������������ı��ʽ������������ 
{
    int i,j,n,m;
    int S,step=0,ip=0,length=0;  
    int tag1=0,tag2=0;
    char a,c,b[20],st[20];
    
    cout<<"����"<<"\tջ\t\t"<<"����\t"<<"\t��������\t\n";
    do 
	{
        step++;
        printf ("��%d��\t",step);
        S=s.top()-'0';          //��ȡջ������ 
        a=str[ip];              //��ȡ���봮�н�Ҫ���з����ķ���
        for(i=0;i<=20;i++)
            b[i]='\0';
        if(a=='+'||a=='-'||a=='*'||a=='/'||a=='('||a==')'||a=='$')
            length=1;
        else                    //����������ʽ�д���id��num���Ӵ����ֱ�����ת��Ϊ'i'��'n'���з���     
		{
            j=ip; 
            length=0;    
            if(Judge_id(a)) 
                tag1=tag2=1;
            if(Judge_num(a))
                tag1=tag2=2;
            j++;
            c=a;
            do 
			{
                length++;
                b[length-1]=c;
                c=str[j];
                if(Judge_id(c))
                    tag2=1;
                else if(Judge_num(c))
                    tag2=2;
                else
                    tag2=0;
                j++;
                } while (tag1==tag2);
            if(tag1==1) 
                a='i';
            if(tag1==2)
                a='n';    
            }
        Output_stack();              //��ӡ��ǰջ�еķ���
        Output_buffer(ip);           //��ӡ��ǰ���뻺�����еķ��Ŵ�          
        m=Get_ternum(a);
        if(Action[S][m]>0)   
		{
            s.push(a);               //��a��ջ 
            c='0'+Action[S][m];
            s.push(c);               //��S'��ջ 
            ip+=length;              //�ƽ�ip��ʹ��ָ����һ��������� 
            cout<<"\tShift"<<Action[S][m]<<"\t";
            }
        else if(Action[S][m]<0&&Action[S][m]!=-10)
		{
            i=0-Action[S][m];
            for(j=1;grammar[i][j]!='\0';j++)          //��ջ������2*|B|���� 
            {
               s.pop();
               s.pop();
               }
            m=s.top()-'0';
            s.push(grammar[i][0]);                    //��ջ 
            j=Get_unternum(grammar[i][0]);
            c='0'+Goto[m][j];
            s.push(c);
            cout<<"\treduce by "<<grammar[i][0]<<"��";
            for(j=1;grammar[i][j]!='\0';j++)          //�������ʽ 
            {
               if(grammar[i][j]=='i')
                  cout<<"id";
               else if(grammar[i][j]=='n')
                  cout<<"num";
               else
                  cout<<grammar[i][j];
               }
            cout<<"\t";
            }
        else if(Action[S][m]==-10)
        {
            cout<<"\tacc\t\n";
            return; 
            }
        else
        {
            cout<<"\t����!\t\n";
            return;
            }
        cout<<"\n";         
        }while(1);
    }

int main()
{
    Get_str();
    Analyse_output();
    
    system("pause");
    return 0;
    }
