/*
	@��ҵҪ��
	 ��д C++������ɲ¼۸���Ϸ�����¹��ܣ�
	��1�� �ٶ���һ����Ʒ�������������ָ������Ʒ�ļ۸�1-1000 ����������
	��2�� ��ʾ�û��¼۸񣬲����룺���û��µļ۸����Ʒ�۸�߻�ͣ����û�����
	��Ӧ����ʾ��
	��3�� ֱ���¶�Ϊֹ����������ʾ��
	����ʾ��Ҫ��1��Ҫ��ʹ�� C++�����������ʽ��cin, cout��������ʹ�� C ��
	�Ե� printf �ȣ�2��ע��������ĺϷ��ԣ�
*/ 
#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;

int main()
{
	srand((unsigned)time(NULL));
    
    int price=rand()%1000+1;
    //@refer to
	//https://blog.csdn.net/cmm0401/article/details/54599083
	int cprice;
	int judge=0;
	
	cout<<"������۸�(1-1000������):"<<endl;
	cin>>cprice;
	
	while(judge!=1)
	{
		if(cprice==price)
		{
			judge=1;
			cout<<"��ϲ��������ļ۸���ȷ"<<endl; 
		}
		if(cprice>price)
		{
			judge=0;
			cout<<"������ļ۸����ȷ�۸��,���������룺"<<endl;
			cin>>cprice;
		}
		if(cprice<price)
		{
			judge=0;
			cout<<"������ļ۸����ȷ�۸�ͣ����������룺"<<endl;
			cin>>cprice; 
		}
	}
	
	system("pause");
	return 0;
}
