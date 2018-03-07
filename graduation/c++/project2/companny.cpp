#include"companny.h"
Companny::Companny(){}
Companny::~Companny(){}
void Companny::CreateBoss()
{
	if(dt.isEmpty())
	{
	 dt.addBoss();
	}
}
void Companny::work()
{
	while(1)
	{
	cout<<"\t     Welcome To Sq System\n"<<endl;
	cout<<"\t*******************************"<<endl;
	cout<<"\t*1.Boss登陆\t2.技术经理登陆*"<<endl;
	cout<<"\t*3.技术人员登陆\t4.销售经理登陆*"<<endl;
	cout<<"\t*5.销售人员登陆\t0.退出        *"<<endl;
	cout<<"\t*******************************"<<endl;
	char num='\0';
	cout<<"请选择:";
	cin>>num;
	switch(num)
	{
		case '1':
				dt.loginBoss();
				boss.work();
				break;
		case '2':
				{
//					dt.time();
					uint uiId=dt.loginTPMA();
					tpma.work(uiId);
					break;
				}
				break;
		case '3':
				{
				//dt.time();
				uint id=dt.loginTP();
				cout<<"login"<<id<<endl;
				tp.work(id);
				}
				break;
		case '4':
				{
				//dt.time();
				uint id=dt.loginSPMA();
				cout<<id<<endl;
				spma.work(id);
				//cout<<"ok"<<endl;
				}
				break;
		case '5':
				{
				//dt.time();
				uint id=dt.loginSP();
				sp.work(id);
				}
				break;
		case '0':
				return;
				break;
		default:
				cout<<"请输入正确选项!"<<endl;
				break;
	}

	
	}
}
