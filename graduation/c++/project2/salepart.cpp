#include"salepart.h"
SalePart::SalePart(string name,uint level):Employee(name,level)
{
	m_uiTotalSale=0;
	m_PerSalePay=50;
}
SalePart::~SalePart(){}
void SalePart::info()
{}
void SalePart::setTotal()
{}
void SalePart::setPay()
{}
uint SalePart::getTotalSale()
{}
uint SalePart::getPerSalePay()
{}
void SalePart::work(uint id)
{
	while(1)
	{
//	db4.time();
	cout<<"\t             welcome\n"<<endl;
	cout<<"\t******************************"<<endl;
	cout<<"\t*1.查看信息 2.修改密码 0.退出*\n";
	cout<<"\t******************************"<<endl;
	cout<<"请输入选项:";
	char num='\0';
	cin>>num;
	switch(num)
	{
		case '1':
				db4.lookSP(id);
				break;
		case '2':
				db4.changePwdTp();
				break;
		case '0':
				return;
		default:
				cout<<"请输入正确选项"<<endl;
				break;
	}
	}
}
