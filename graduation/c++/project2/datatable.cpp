#include"datatable.h"
#include<string>
#include<string.h>
void DataTable::PALL()
{
	if(mysql_query(m_conn,"select * from info"))
	{
		cout<<"send sql is failed 8"<<endl;
		exit(1);
	}
	m_res=mysql_use_result(m_conn);
	int i=0;
	while((m_row=mysql_fetch_row(m_res))!=NULL)
	{
		cout<<"工号\t姓名\t级别\t月薪\t密码\t上级\t工时\t时薪\t销售额\t销售提成(件)\t备注"<<endl;
		for(int i=0;i<11;i++)
		{
			if(m_row[i]==NULL)
			{
				if(9==i)
				{
					cout<<"NULL\t\t";
				}
				else
				{
					cout<<"NULL\t";
				}
			}
			else
			{
				if(9==i)
				{
					cout<<m_row[i]<<"\t\t";
				}
				else
				{
					cout<<m_row[i]<<"\t";
				}
			}
		}
		cout<<endl;
	}
	mysql_free_result(m_res);
}
void DataTable::PTP()
{
	if(mysql_query(m_conn,"select * from info where level=3"))
	{
		cout<<"send sql is failed 49"<<endl;
		exit(1);
	}
	m_res=mysql_use_result(m_conn);
	int i=0;
	while((m_row=mysql_fetch_row(m_res))!=NULL)
	{
		cout<<"工号\t姓名\t级别\t月薪\t密码\t上级\t工时\t时薪\t销售额\t销售提成(件)\t备注"<<endl;
		for(int i=0;i<11;i++)
		{
			if(m_row[i]==NULL)
			{
				if(9==i)
				{
					cout<<"NULL\t\t";
				}
				else
				{
					cout<<"NULL\t";
				}
			}
			else
			{
				if(9==i)
				{
					cout<<m_row[i]<<"\t\t";
				}
				else
				{
					cout<<m_row[i]<<"\t";
				}
			}
		}
		cout<<endl;
	}
	mysql_free_result(m_res);

}
void DataTable::PSP()
{
	if(mysql_query(m_conn,"select * from info where level=4"))
	{
		cout<<"send sql is failed 91"<<endl;
		exit(1);
	}
	m_res=mysql_use_result(m_conn);
	int i=0;
	while((m_row=mysql_fetch_row(m_res))!=NULL)
	{
		cout<<"工号\t姓名\t级别\t月薪\t密码\t上级\t工时\t时薪\t销售额\t销售提成(件)\t备注"<<endl;
		for(int i=0;i<11;i++)
		{
			if(m_row[i]==NULL)
			{
				if(9==i)
				{
					cout<<"NULL\t\t";
				}
				else
				{
					cout<<"NULL\t";
				}
			}
			else
			{
				if(9==i)
				{
					cout<<m_row[i]<<"\t\t";
				}
				else
				{
					cout<<m_row[i]<<"\t";
				}
			}
		}
		cout<<endl;
	}
	mysql_free_result(m_res);

}
void DataTable::time()
{
	//mysql_free_result(m_res);
	if(mysql_query(m_conn,"select current_timestamp"))
	{
		cout<<"send sql is failed 13333345"<<endl;
		cout<<mysql_error(m_conn)<<endl;
		exit(1);
	}
	m_res=mysql_use_result(m_conn);
	if((m_row=mysql_fetch_row(m_res))!=NULL)
	{
		cout<<m_row[0]<<endl;
	}
	//do
	//{
	//	m_res=mysql_store_result(m_conn);
	mysql_free_result(m_res);
	//}while(!mysql_next_result(m_conn));

}
bool DataTable::isEmpty()
{
	bool bOk=false;
	if(mysql_query(m_conn,"select * from info"))
	{
		cout<<"error"<<endl;
	}
	m_res=mysql_use_result(m_conn);
	if((m_row=mysql_fetch_row(m_res))==NULL)
	{
			bOk=true;
	}
	mysql_free_result(m_res);
	return bOk;
}
/*员工登陆*/
void DataTable::loginBoss()
{
	int i=0;
	while(1)
	{
	char name[10]={'\0'};
	char *pwd;
	cout<<"姓名:";
	cin>>name;
	pwd=getpass("密码:");
	char sql_select[1000]={'\0'};
	sprintf(sql_select,"select *from info where name=\'%s\' and pwd=\'%s\' and level=0",name,pwd);
	//cout<<sql_select<<endl;
	if((mysql_query(m_conn,sql_select)))
	{
		cout<<"send sql is error 175"<<endl;
	}
	m_res=mysql_use_result(m_conn);
	if((m_row=mysql_fetch_row(m_res))==NULL)
	{
		cout<<"用户名或密码错误！"<<endl;
		i++;
		if(1==i)
		{
			cout<<"只有三次机会!"<<endl;
		}
		if(3==i)
		{
			exit(1);
		}
	}
	else
	{
		break;
	}
	}
	mysql_free_result(m_res);

}

uint DataTable::loginTP()
{   
	int i=0;
	uint num=0;
	while(1)
	{
	char n[10]={'\0'};
	char *p;
	cout<<"姓名:";
	cin>>n;
	p=getpass("密码:");
	char mysql_select[1000]={'\0'};
	sprintf(mysql_select,"select * from info where name=\'%s\' and pwd=\'%s\' and level=3",n,p);
	if(mysql_query(m_conn,mysql_select))
	{
		cout<<"sql send is failed 216"<<endl;
	}
	m_res=mysql_use_result(m_conn);
	if((m_row=mysql_fetch_row(m_res))!=NULL)
	{
		cout<<"****欢迎技术人员"<<n<<"登陆公司员工系统****"<<endl;
		num=atoi(m_row[0]);
		break;
	}
	else
	{
		cout<<"用户名或密码错误!"<<endl;
		i++;
		if(1==i)
		{
			cout<<"只有三次机会!"<<endl;
		}
	}
	if(3==i)
	{
		exit(1);
	}
	mysql_free_result(m_res);
	}
	return num;
}

uint DataTable::loginTPMA()
{
	int i=0;
	uint num=0;
	while(1)
	{
	char n[10]={'\0'};
	char *p;
	cout<<"姓名:";
	cin>>n;
	p=getpass("密码:");
	char mysql_select[128]={'\0'};
	sprintf(mysql_select,"select * from info where name=\'%s\' and pwd=\'%s\' and level=1",n,p);
	if(mysql_query(m_conn,mysql_select))
	{
		cout<<"send sql is failed 259"<<endl;
		cout<<mysql_error(m_conn)<<endl;
		exit(1);
	}	
	m_res=mysql_use_result(m_conn);
	if((m_row=mysql_fetch_row(m_res))!=NULL)
	{
		num=atoi(m_row[0]);
		cout<<"****欢迎技术经理"<<n<<"登陆公司员工系统****"<<endl;
		break;
	}
	else
	{
		cout<<"用户名或密码错误！"<<endl;
		i++;
		if(1==i)
		{
			cout<<"只有三次机会!"<<endl;
		}
		if(3==i)
		{
			exit(1);
		}
	}
	mysql_free_result(m_res);
	}
	return num;
}

uint DataTable::loginSP()
{
	int i=0;
	uint num=0;
	char n[10]={'\0'};
	char *p;
	char mysql_select[64]={'\0'};
	while(1)
	{
	cout<<"姓名:";
	cin>>n;
	p=getpass("密码:");
	sprintf(mysql_select,"select * from info where name=\'%s\' and pwd=\'%s\' and level=4",n,p);
	if(mysql_query(m_conn,mysql_select))
	{
		cout<<"send sql is failed 303"<<endl;
		exit(1);
	}	
	m_res=mysql_use_result(m_conn);
	if((m_row=mysql_fetch_row(m_res))!=NULL)
	{
		num=atoi(m_row[0]);
		cout<<"****欢迎销售人员"<<n<<"登陆公司员工系统****"<<endl;
		break;
	}
	else
	{
		cout<<"登陆失败"<<endl;
		i++;
		if(1==i)
		{
			cout<<"只有三次机会!"<<endl;
		}
		if(3==i)
		{
			exit(1);
		}
	}
	mysql_free_result(m_res);
	}
	return num;
}

uint DataTable::loginSPMA()
{
	int i=0;
	int num=0;
	char n[10]={'\0'};
	char *p;
	char mysql_select[64]={'\0'};
	while(1)
	{
	cout<<"姓名:";
	cin>>n;
	p=getpass("密码:");
	sprintf(mysql_select,"select * from info where name=\'%s\' and pwd=\'%s\' and level=2",n,p);
	if(mysql_query(m_conn,mysql_select))
	{
		cout<<"send sql is failed 347"<<endl;
		exit(1);
	}	
	m_res=mysql_use_result(m_conn);
	if((m_row=mysql_fetch_row(m_res))!=NULL)
	{
		num=atoi(m_row[0]);
		cout<<"****欢迎销售经理"<<n<<"登陆公司员工系统****"<<endl;
		break;
	}
	else
	{
		cout<<"登陆失败"<<endl;
		i++;
		if(1==i)
		{
			cout<<"只有三次机会!"<<endl;
		}
		if(3==i)
		{
			exit(1);
		}
	}
	//cout<<num<<endl;
	mysql_free_result(m_res);
	}
	return num;
}
void DataTable::myfree()
{
	mysql_free_result(m_res);
}
/*其实可以只写一个登陆函数，根据帐号密码到数据库查询，根据level的不同调用相应的操作菜单*/
/*对公司员工操作*/
void DataTable::addBoss()
{
	if(mysql_query(m_conn,"insert into info(code,name,level) values(1000,'Boss',0)"))
	{
		cout<<"send sql is failed 381\n";
		exit(1);
	}
	else
	{
		cout<<"Welcome!"<<endl;
	}
}
/*对技术人员的增删改查*/
void DataTable::addTP(uint uiId)
{
	char n[10]={'\0'};
	cout<<"请输入你想添加的技术人员姓名:";
	cin>>n;
	char mysql_insert[128]={'\0'};
	sprintf(mysql_insert,"insert into info(name,level,leaderid,hourpay) values(\'%s\',3,%d,50)",n,uiId);
	if((mysql_query(m_conn,mysql_insert)))
	{
		cout<<"send sql is failed 399\n";
		exit(1);
	}
	m_res=mysql_use_result(m_conn);
	if((m_row=mysql_fetch_row(m_res))==NULL)
	{
		cout<<"添加失败"<<endl;
	}
	else
	{
		cout<<"添加成功"<<endl;
	}
	mysql_free_result(m_res);
}

void DataTable::changePwdTp()
{
	uint uiId;
	char p[32]={'\0'};
	char newp[32]={'\0'};
	char mysql_select[128]={'\0'};
	cout<<"请输入id:";
	cin>>uiId;
	cout<<"请输入原密码:";
	cin>>p;

	sprintf(mysql_select,"select * from info where code=%d and pwd=\'%s\'",uiId,p);	
	if(mysql_query(m_conn,mysql_select))
	{
		cout<<"send sql is failed 428"<<endl;
		exit(1);
	}
	m_res=mysql_use_result(m_conn);
	if((m_row=mysql_fetch_row(m_res))==NULL)
	{
		cout<<"id或密码错误"<<endl;
		return;
	}
	mysql_free_result(m_res);
	cout<<"请输入新密码:";
	cin>>newp;
	
	char mysql_update[128]={'\0'};
	sprintf(mysql_update,"update info set pwd=\'%s\' where code=%d and pwd=\'%s\'",newp,uiId,p);
	if((mysql_query(m_conn,mysql_update)))
	{
		cout<<"send sql is failed 445"<<endl;
	}
	else
	{
		cout<<"改密成功!"<<endl;
	}
}
void DataTable::addTP()
{
	uint uiId;
	cout<<"输入上级id:";
	cin>>uiId;
	char n[10]={'\0'};
	cout<<"请输入你想添加的技术人员姓名:";
	cin>>n;
	char mysql_select[128]={'\0'};
	sprintf(mysql_select,"select * from info where code=%d and level=1",uiId);
	if((mysql_query(m_conn,mysql_select)))
	{
		cout<<"send sql is failed 464"<<endl;
		cout<<mysql_error(m_conn)<<endl;
		exit(1);
	}
	m_res=mysql_use_result(m_conn);
	if((m_row=mysql_fetch_row(m_res))==NULL)
	{
		cout<<"无id为"<<uiId<<"的技术经理"<<endl;
		return;
	}
	mysql_free_result(m_res);
	char mysql_insert[128]={'\0'};
	sprintf(mysql_insert,"insert into info(name,level,leaderid,hourpay) values(\'%s\',3,%d,50)",n,uiId);
	if((mysql_query(m_conn,mysql_insert)))
	{
		cout<<"send sql is failed 479\n";
		exit(1);
	}
	else
	{
		cout<<"添加成功"<<endl;
	}
}
void DataTable::delTP()
{
		
	uint id;
	cout<<"输入你想删除的技术人员的id:";
	cin>>id;
	char mysql_select[64]={'\0'};
	sprintf(mysql_select,"select * from info where code=%d and level=3",id);
	if(mysql_query(m_conn,mysql_select))
	{
		cout<<"send sql is failed 497"<<endl;
		exit(1);
	}
	m_res=mysql_use_result(m_conn);
	if((m_row=mysql_fetch_row(m_res))==NULL)
	{
		cout<<"无id为"<<id<<"的技术人员"<<endl;
		mysql_free_result(m_res);
		return;
	}
	else
	{
		mysql_free_result(m_res);
		while(1)
		{
		cout<<"你是否确定要删除id为"<<id<<"的技术人员"<<m_row[1]<<"? y/n:";
		char ch='\0';
		cin>>ch;
		switch(ch)
		{
			case 'y':
					{
						char mysql_delete[64]={'\0'};
						sprintf(mysql_delete,"delete from info where code=%d and level=3",id);
						if(mysql_query(m_conn,mysql_delete))
						{
							cout<<"send sql is failed 523"<<endl;
							exit(1);
						}
						else
						{
							cout<<"删除成功!"<<endl;
							return;
						}
					}
					break;
			case 'n':
					return;
					break;
			default:
						cout<<"请按提示输入!"<<endl;
					break;
		}
	  }
	}
}
void DataTable::lookTP()
{
	uint id;
	cout<<"请输入你想查找的技术人员id:";
	cin>>id;
	char mysql_select[64]={'\0'};
	sprintf(mysql_select,"select * from info where code=%d and level=3",id);
	cout<<mysql_select<<endl;
	if(mysql_query(m_conn,mysql_select))
	{
		cout<<"send sql is failed 552\n";
		exit(1);
	}
	m_res=mysql_use_result(m_conn);
	if((m_row=mysql_fetch_row(m_res))!=NULL)
	{
		int i=0;
	//	string n="Null";
		
		cout<<"id:"<<m_row[0]<<endl;
		cout<<"name:"<<m_row[1]<<endl;
		cout<<"level:"<<"技术人员"<<endl;
		
		if(m_row[3]==NULL)
		{
			cout<<"salary:NULL"<<endl;
		}
		else
		{
		cout<<"salary:"<<m_row[3]<<endl;
		}
		
		cout<<"pwd:"<<m_row[4]<<endl;
		cout<<"leaderid:"<<m_row[5]<<endl;
		
		if(m_row[6]==NULL)
		{
			cout<<"worktime:NULL"<<endl;
		}
		else
		{
		cout<<"worktime:"<<m_row[6]<<endl;
		}
		
		cout<<"hourpay:"<<m_row[7]<<endl;
		cout<<"note:"<<m_row[10]<<endl;
	}
	else
	{
		cout<<"无id为"<<id<<"的技术员工"<<endl;
	}
	mysql_free_result(m_res);
}
void DataTable::lookTP(uint id)
{
	//uint id;
	//cout<<"请输入你想查找的技术人员id:";
	//cin>>id;
	char mysql_select[64]={'\0'};
	sprintf(mysql_select,"select * from info where code=%d and level=3",id);
	if(mysql_query(m_conn,mysql_select))
	{
		cout<<"send sql is failed 604\n";
		exit(1);
	}
	m_res=mysql_use_result(m_conn);
	if((m_row=mysql_fetch_row(m_res))!=NULL)
	{
		int i=0;
	//	string n="Null";
		
		cout<<"id:"<<m_row[0]<<endl;
		cout<<"name:"<<m_row[1]<<endl;
		cout<<"level:"<<"技术人员"<<endl;
		
		if(m_row[3]==NULL)
		{
			cout<<"salary:NULL"<<endl;
		}
		else
		{
		cout<<"salary:"<<m_row[3]<<endl;
		}
		
		cout<<"pwd:"<<m_row[4]<<endl;
		cout<<"leaderid:"<<m_row[5]<<endl;
		
		if(m_row[6]==NULL)
		{
			cout<<"worktime:NULL"<<endl;
		}
		else
		{
		cout<<"worktime:"<<m_row[6]<<endl;
		}
		
		cout<<"hourpay:"<<m_row[7]<<endl;
		cout<<"note:"<<m_row[10]<<endl;
	}
	else
	{
		cout<<"无id为"<<id<<"的技术员工"<<endl;
	}
	mysql_free_result(m_res);
}
void DataTable::changeTP()
{
	uint id;
	cout<<"请输入你想修改的技术人员id:";
	cin>>id;
	char mysql_select[64]={'\0'};
	sprintf(mysql_select,"select * from info where code=%d and level=3",id);
	if((mysql_query(m_conn,mysql_select)))
	{
		cout<<"send sql is failed 656"<<endl;
		cout<<mysql_error(m_conn)<<endl;
		exit(1);
	}
	m_res=mysql_use_result(m_conn);
	if((m_row=mysql_fetch_row(m_res))==NULL)
	{
		cout<<"无id为"<<id<<"的技术人员"<<endl;
		return;
	}
	mysql_free_result(m_res);
	cout<<"\tchange menu"<<endl;
	cout<<"\t1.name 2.level 3.salary"<<endl;
	cout<<"\t4.wkti 5.hopa  6.note"<<endl;
    char num='\0';
	cout<<"输入选项:";
	cin>>num;
	switch(num)
	{
		case '1':
				{
					char n[10]={'\0'};
					char mysql_update[64]={'\0'};
					char mysql_sel1[64]={'\0'};
					cout<<"输入新名字:";
					cin>>n;

					sprintf(mysql_update,"update info set name=\'%s\' where code=%d and level=3",n,id);
					if((mysql_query(m_conn,mysql_update)))
					{
						cout<<"send sql is failed 686\n";
						cout<<mysql_error(m_conn)<<endl;
						exit(1);
					}
					sprintf(mysql_sel1,"select * from info where code=%d and name=\'%s\'",id,n);
					if((mysql_query(m_conn,mysql_sel1)))
					{
						cout<<"send sql is failed 693"<<endl;
						exit(1);
					}
					m_res=mysql_use_result(m_conn);
					if((m_row=mysql_fetch_row(m_res))!=NULL)
					{
						cout<<"修改成功!"<<endl;
					}
					else
					{
						cout<<"修改失败!"<<endl;
					}
					mysql_free_result(m_res);
				}
				break;
		case '2':
				{
					uint uilevel;
					char mysql_updat[64]={'\0'};
					char mysql_sel2[64]={'\0'};
					while(1)
					{
					cout<<"\t1.技术经理 2.销售经理 3.销售人员 "<<endl;
					cout<<"输入新级别:";
					cin>>uilevel;
					switch(uilevel)
					{
						case 1:{
								char mysql_ch1[128]={'\0'};
								sprintf(mysql_ch1,"update info set salary=12000,leaderid=0,worktime=0,hourpay=0 where code=%d",id);
								if(mysql_query(m_conn,mysql_ch1))
								{
									cout<<"send sql is failed 725"<<endl;
									exit(1);
								}
							   }
								break;
						case 2:
								{
								char mysql_ch2[128]={'\0'};
								sprintf(mysql_ch2,"update info set salary=10000,leaderid=0,worktime=0,hourpay=0,totalsale=0,salepay=20 where code=%d",id);
								if(mysql_query(m_conn,mysql_ch2))
								{
									cout<<"send sql is failed 736"<<endl;
									exit(1);
								}
								}
								break;
						case 3:
								{
								uint lId;
								cout<<"输入上级id:";
								cin>>lId;
								char mysql_t[128]={'\0'};
								sprintf(mysql_t,"select * from info where code=%d and level=2",lId);
								if(mysql_query(m_conn,mysql_t))
								{
									cout<<"send sql is failed 750"<<endl;
									exit(1);
								}
								m_res=mysql_use_result(m_conn);
								if((m_row=mysql_fetch_row(m_res))==NULL)
								{
									cout<<"无id为"<<lId<<"的销售经理"<<endl;
									return;
								}
								mysql_free_result(m_res);
								char mysql_ch3[128]={'\0'};
								sprintf(mysql_ch3,"update info set salary=0,leaderid=%d,worktime=0,hourpay=0,totalsale=0,salepay=50 where code=%d",lId,id);
								if(mysql_query(m_conn,mysql_ch3))
								{
									cout<<"send sql is failed 764"<<endl;
									exit(1);
								}
								}	
								break;
						default:
								break;
					}
					if(uilevel==1||uilevel==2||uilevel==3)
					{
							break;
					}
					else
					{
						cout<<"请按要求设置级别"<<endl;
						return;
					}
					}

					sprintf(mysql_updat,"update info set level=%d where code=%d and level=3",uilevel,id);
					if((mysql_query(m_conn,mysql_updat)))
					{
						cout<<"send sql is failed 786\n";
						exit(1);
					}
					
					sprintf(mysql_sel2,"select * from info where code=%d and level=%d",id,uilevel);
					if(mysql_query(m_conn,mysql_sel2))
					{
						cout<<"send sql is failed 793"<<endl;
						exit(1);
					}

					m_res=mysql_use_result(m_conn);
					if((m_row=mysql_fetch_row(m_res))!=NULL)
					{
						cout<<"修改成功!"<<endl;
					}
					else
					{
						cout<<"修改失败!"<<endl;
						return;
					}
					
				}
				break;
		case '3':
				{
					int isalary;
					cout<<"输入薪资:";
					cin>>isalary;
					char mysql_upda[128]={'\0'};
					char mysql_sel2[128]={'\0'};
					cout<<"ok"<<endl;
					sprintf(mysql_upda,"update info set salary=%d where code=%d and level=3",isalary,id);
					cout<<"ok"<<endl;
					if((mysql_query(m_conn,mysql_upda)))
					{
						cout<<"ok"<<endl;
						cout<<"send sql is failed 823\n";
						exit(1);
					}
				
					sprintf(mysql_sel2,"select * from info where code=%d and salary=%d",id,isalary);
					if((mysql_query(m_conn,mysql_sel2)))
					{
						cout<<"send sql is failed 830\n";
						exit(1);
					}
					m_res=mysql_use_result(m_conn);
					if((m_row=mysql_fetch_row(m_res))!=NULL)
					{
						cout<<"修改成功"<<endl;
					}
					else
					{
						cout<<"修改失败"<<endl;
						return;
					}
					mysql_free_result(m_res);
					
				}
				break;
		case '4':
				{
					int wktm;
					cout<<"输入工时:";
					cin>>wktm;
					char mysql_upd[64]={'\0'};
					char mysql_sel3[64]={'\0'};
					sprintf(mysql_upd,"update info set worktime=%d where code=%d and level=3",wktm,id);
					if(mysql_query(m_conn,mysql_upd))
					{
						cout<<"send sql is failed 857\n";
						exit(1);
					}
					sprintf(mysql_sel3,"select * from info where code=%d and worktime=%d",id,wktm);
					if(mysql_query(m_conn,mysql_sel3))
					{
						cout<<"send sql is failed 863\n";
						exit(1);
					}
					m_res=mysql_use_result(m_conn);
					if((m_row=mysql_fetch_row(m_res))==NULL)
					{
						cout<<"修改失败!"<<endl;
					}
					else
					{
						cout<<"修改成功!"<<endl;
						return;
					}
					mysql_free_result(m_res);
				}
				break;
		case '5':
				{
					int tsalary;
					cout<<"输入时薪:";
					cin>>tsalary;
					char mysql_up[64]={'\0'};
					char mysql_sel4[64]={'\0'};
					sprintf(mysql_up,"update info set hourpay=%d where code=%d and level=3",tsalary,id);
					if(mysql_query(m_conn,mysql_up))
					{
						cout<<"send sql is failed 889\n";
						exit(1);
					}
					sprintf(mysql_sel4,"select * from info where code=%d and hourpay=%d",id,tsalary);
					if(mysql_query(m_conn,mysql_sel4))
					{
						cout<<"send sql is failed 895\n";
						exit(1);
					}
					m_res=mysql_use_result(m_conn);
					if((m_row=mysql_fetch_row(m_res))==NULL)
					{
						cout<<"修改失败!"<<endl;
					}
					else
					{
						cout<<"修改成功!"<<endl;
						return;
					}
					mysql_free_result(m_res);
				}
				break;
		case '6':
				{
					char nt[216]={'\0'};
					cout<<"输入备注:";
					cin>>nt;
					char mysql_upd[64]={'\0'};
					sprintf(mysql_upd,"update info set note=\'%s\' where code=%d and level=3",nt,id);
					if(mysql_query(m_conn,mysql_upd))
					{
						cout<<"send sql is failed 920\n";
						cout<<mysql_error(m_conn)<<endl;
						exit(1);
					}
					else 
					{
						cout<<"修改成功!\n";
						return;
					}	
				}
				break;
		default:
				cout<<"请输入对应选项!\n";
				break;
	}
}
/*对技术经理的增删改查*/ 
void DataTable::addTPMA()
{
	char na[32]={'\0'};
	cout<<"请输入你想添加的技术经理姓名:";
	cin>>na;
	char mysql_insert[1000]={'\0'};
	sprintf(mysql_insert,"insert into info(name,level,salary) values(\'%s\',1,12000)",na);
	cout<<"............"<<endl;
	if(mysql_query(m_conn,mysql_insert))
	{
		cout<<"send sql is failed 947\n";
		cout<<mysql_error(m_conn)<<endl;
		exit(1);
	}
	else
	{
		cout<<"添加成功"<<endl;
	}
}
void DataTable::delTPMA()
{	
	
	uint id;
	cout<<"输入你想删除的技术经理的id:";
	cin>>id;
	char mysql_select[64]={'\0'};
	sprintf(mysql_select,"select * from info where code=%d and level=1",id);
	if(mysql_query(m_conn,mysql_select))
	{
		cout<<"send sql is failed 966"<<endl;
		exit(1);
	}
	m_res=mysql_use_result(m_conn);
	if((m_row=mysql_fetch_row(m_res))==NULL)
	{
		cout<<"无id为"<<id<<"的技术经理"<<endl;
		return;
	}
	else
	{
		mysql_free_result(m_res);
		while(1)
		{
		cout<<"你是否确定要删除id为"<<id<<"的技术经理"<<m_row[1]<<"? y/n:";
		char ch='\0';
		cin>>ch;
		switch(ch)
		{
			case 'y':
					{
						char mysql_delete[64]={'\0'};
						sprintf(mysql_delete,"delete from info where code=%d and level=1",id);
						if(mysql_query(m_conn,mysql_delete))
						{
							cout<<"send sql is failed 991"<<endl;
							exit(1);
						}
						else
						{
							cout<<"删除成功!"<<endl;
							return;
						}
					}
					break;
			case 'n':
					return;
					break;
			default:
						cout<<"请按提示输入!"<<endl;
					break;
		}
	  }
	}
}
void DataTable::lookTPMA()
{
	uint id;
	cout<<"请输入你想查找的技术经理id:";
	cin>>id;
	char mysql_select[64]={'\0'};
	sprintf(mysql_select,"select * from info where code=%d and level=1",id);
	cout<<mysql_select<<endl;
	if(mysql_query(m_conn,mysql_select))
	{
		cout<<"send sql is failed 1020\n";
		exit(1);
	}
	m_res=mysql_use_result(m_conn);
	if((m_row=mysql_fetch_row(m_res))!=NULL)
	{
		cout<<"id:"<<m_row[0]<<"\nname:"<<m_row[1]<<"\nlevel:"<<"技术经理"<<"\nsalary:"
				<<m_row[3]<<"\nnote:"<<m_row[10]<<endl;
	}
	else
	{
		cout<<"无id为"<<id<<"的技术经理"<<endl;
	}
	mysql_free_result(m_res);
}
void DataTable::lookTPMA(uint id)
{
	//uint id;
	//cout<<"请输入你想查找的技术经理id:";
	//cin>>id;
	char mysql_select[64]={'\0'};
	sprintf(mysql_select,"select * from info where code=%d and level=1",id);
	cout<<mysql_select<<endl;
	if(mysql_query(m_conn,mysql_select))
	{
		cout<<"send sql is failed 1044\n";
		exit(1);
	}
	m_res=mysql_use_result(m_conn);
	if((m_row=mysql_fetch_row(m_res))!=NULL)
	{
		cout<<"id:"<<m_row[0]<<"\nname:"<<m_row[1]<<"\nlevel:"<<"技术经理"<<"\nsalary:"
				<<m_row[3]<<"\nnote:"<<m_row[10]<<endl;
	}
	else
	{
		cout<<"无id为"<<id<<"的技术经理"<<endl;
	}
	mysql_free_result(m_res);
}
void DataTable::changeTPMA()
{
	uint id;
	cout<<"请输入你想修改的技术经理的id:";
	cin>>id;
	
	char mysql_select[64]={'\0'};
	sprintf(mysql_select,"select * from info where code=%d and level=1",id);
	if(mysql_query(m_conn,mysql_select))
	{
		cout<<"send sql is failed 1069"<<endl;
		exit(1);
	}
	m_res=mysql_use_result(m_conn);
	if((m_row=mysql_fetch_row(m_res))==NULL)
	{
		cout<<"查无此人"<<endl;
		return;
	}
	mysql_free_result(m_res);

	cout<<"		\tchange menu"<<endl;
	cout<<"\t1.name 2.level 3.salary 4.note"<<endl;
    char num='\0';
	cout<<"输入选项:";
	cin>>num;
	switch(num)
	{
		case '1':
				{
					char n[24]={'\0'};
					cout<<"输入新名字:";
					cin>>n;
					char mysql_update[64]={'\0'};
					sprintf(mysql_update,"update info set name=\'%s\' where code=%d and level=1",n,id);

					if(mysql_query(m_conn,mysql_update))
					{
						cout<<"send sql is failed 1097\n";
						exit(1);
					}
					else 
					{
						cout<<"修改成功!\n";
						return;
					}
				}
				break;
		case '2':
				{
					uint uilevel;
					char mysql_updat[64]={'\0'};
					char mysql_sel2[64]={'\0'};
					while(1)
					{
					cout<<"\t1.销售经理 2.销售人员 3.技术人员 "<<endl;
					cout<<"输入新级别:";
					cin>>uilevel;
					switch(uilevel)
					{
						case 1:{
								char mysql_ch1[128]={'\0'};
								sprintf(mysql_ch1,"update info set salary=10000,totalsale=0,salepay=20 where code=%d",id);
								if(mysql_query(m_conn,mysql_ch1))
								{
									cout<<"send sql is failed 1124"<<endl;
									exit(1);
								}
							   }
								break;
						case 2:
								{
								uint lId;
								cout<<"输入上级id:";
								cin>>lId;
								char mysql_t[128]={'\0'};
								sprintf(mysql_t,"select * from info where code=%d and level=2",lId);
								if(mysql_query(m_conn,mysql_t))
								{
									cout<<"send sql is failed 1138"<<endl;
									exit(1);
								}
								m_res=mysql_use_result(m_conn);
								if((m_row=mysql_fetch_row(m_res))==NULL)
								{
									cout<<"无id为"<<lId<<"的销售经理"<<endl;
									return;
								}
								mysql_free_result(m_res);
								char mysql_ch3[128]={'\0'};
								sprintf(mysql_ch3,"update info set salary=0,leaderid=%d,totalsale=0,salepay=50,worktime=0,hourpay=0 where code=%d",lId,id);
								if(mysql_query(m_conn,mysql_ch3))
								{
									cout<<"send sql is failed 1152"<<endl;
									exit(1);
								}
								
								}
								break;
						case 3:
								{
								uint lId;
								cout<<"输入上级id:";
								cin>>lId;
								char mysql_t[128]={'\0'};
								sprintf(mysql_t,"select * from info where code=%d and level=1",lId);
								if(mysql_query(m_conn,mysql_t))
								{
									cout<<"send sql is failed 1167"<<endl;
									exit(1);
								}
								m_res=mysql_use_result(m_conn);
								if((m_row=mysql_fetch_row(m_res))==NULL)
								{
									cout<<"无id为"<<lId<<"的技术经理"<<endl;
									return;
								}
								mysql_free_result(m_res);
								char mysql_ch3[128]={'\0'};
								sprintf(mysql_ch3,"update info set salary=0,leaderid=%d,worktime=0,hourpay=50,totalsale=0,salepay=0 where code=%d",lId,id);
								if(mysql_query(m_conn,mysql_ch3))
								{
									cout<<"send sql is failed 1181"<<endl;
									exit(1);
								}
								}
						
								if(uilevel==1||uilevel==2||uilevel==3)
								{
									break;
								}
								else
								{
									cout<<"请按要求设置级别"<<endl;
									return;
								}
					}
					sprintf(mysql_updat,"update info set level=%d where code=%d and level=2",uilevel,id);
					if((mysql_query(m_conn,mysql_updat)))
					{
						cout<<"send sql is failed 1199\n";
						exit(1);
					}
					
					sprintf(mysql_sel2,"select * from info where code=%d and level=%d",id,uilevel);
					if(mysql_query(m_conn,mysql_sel2))
					{
						cout<<"send sql is failed 1206"<<endl;
						exit(1);
					}

					m_res=mysql_use_result(m_conn);
					if((m_row=mysql_fetch_row(m_res))!=NULL)
					{
						cout<<"修改成功!"<<endl;
					}
					else
					{
						cout<<"修改失败!"<<endl;
						return;
					}
			}
				}
				break;
		case '3':
				{
					int isalary;
					cout<<"输入薪资:";
					cin>>isalary;
					char mysql_upda[64]={'\0'};
					sprintf(mysql_upda,"update info set salary=%d where code=%d and level=1",isalary,id);
					if(mysql_query(m_conn,mysql_upda))
					{
						cout<<"send sql is failed 1232\n";
						exit(1);
					}
					else 
					{
						cout<<"修改成功!\n";
						return;
					}

				}
				break;
		case '4':
				{
					char nt[216]={'\0'};
					cout<<"输入备注:";
					cin>>nt;
					char mysql_upd[64]={'\0'};
					sprintf(mysql_upd,"update info set note=\'%s\' where code=%d and level=1",nt,id);
					if(mysql_query(m_conn,mysql_upd))
					{
						cout<<"send sql is failed 1252\n";
						cout<<mysql_error(m_conn)<<endl;
						exit(1);
					}
					else 
					{
						cout<<"修改成功!\n";
						return;
					}	
				}
				break;
		default:
				cout<<"请输入正确选项!"<<endl;
				break;
	}

}

void DataTable::addSP()
{	uint id;
	char n[10]={'\0'};
	char mysql_insert[128]={'\0'};
	char mysql_select[128]={'\0'};
	cout<<"输入上级id:";
	cin>>id;
	cout<<"姓名:";
	cin>>n;
	sprintf(mysql_select,"select * from info where code=%d and level=2",id);
	m_res=mysql_use_result(m_conn);
	if((m_row=mysql_fetch_row(m_res))==NULL)
	{
		cout<<"无id为"<<id<<"的销售经理"<<endl;
		return;
	}
	mysql_free_result(m_res);
	sprintf(mysql_insert,"insert into info(name,level,salary,pwd,leaderid,totalsale,salepay,note) values(\'%s\',4,0,'123456',%d,0,20,'good')",n,id);
	if(mysql_query(m_conn,mysql_insert))
	{
		cout<<"send sql is failed 1290"<<endl;
		exit(1);
	}
	else
	{
		cout<<"添加成功!"<<endl;
	}
}
void DataTable::addSP(uint id)
{
	char n[10]={'\0'};
	char mysql_insert[512]={'\0'};
	//cin>>id;
	cout<<"姓名:";
	cin>>n;
	sprintf(mysql_insert,"insert into info(name,level,salary,pwd,leaderid,totalsale,salepay,note) values(\'%s\',4,0,'123456',%d,0,20,'good')",n,id);
	if(mysql_query(m_conn,mysql_insert))
	{
		cout<<"send sql is failed 1308"<<endl;
		exit(1);
	}
	else
	{
		cout<<"添加成功!"<<endl;
	}
}
void DataTable::delSP()
{
	uint id;
	cout<<"输入你想删除的销售人员的的id:";
	cin>>id;
	char mysql_select[64]={'\0'};
	sprintf(mysql_select,"select * from info where code=%d and level=4",id);
	if(mysql_query(m_conn,mysql_select))
	{
		cout<<"send sql is failed 1325"<<endl;
		exit(1);
	}
	m_res=mysql_use_result(m_conn);
	if((m_row=mysql_fetch_row(m_res))==NULL)
	{
		cout<<"无id为"<<id<<"的销售人员"<<endl;
		return;
	}
	else
	{
		mysql_free_result(m_res);
		while(1)
		{
		cout<<"你是否确定要删除id为"<<id<<"的销售人员"<<m_row[1]<<"? y/n:";
		char ch='\0';
		cin>>ch;
		switch(ch)
		{
			case 'y':
					{
						char mysql_delete[64]={'\0'};
						sprintf(mysql_delete,"delete from info where code=%d and level=4",id);
						if(mysql_query(m_conn,mysql_delete))
						{
							cout<<"send sql is failed 1350"<<endl;
							exit(1);
						}
						else
						{
							cout<<"删除成功!"<<endl;
							return;
						}
					}
					break;
			case 'n':
					return;
					break;
			default:
						cout<<"请按提示输入!"<<endl;
					break;
		}
	  }
	}
	
}
void DataTable::lookSP(uint id)
{
	//uint id;
	//cout<<"请输入你想查找的销售人员id:";
	//cin>>id;
	//	cout<<id<<endl;
	char mysql_select[64]={'\0'};
	sprintf(mysql_select,"select * from info where code=%d and level=4",id);
	if(mysql_query(m_conn,mysql_select))
	{
		cout<<"send sql is failed 1381\n";
		exit(1);
	}
	m_res=mysql_use_result(m_conn);
	if((m_row=mysql_fetch_row(m_res))!=NULL)
	{
		int i=0;
	//	string n="Null";
		
		cout<<"id:"<<m_row[0]<<endl;
		cout<<"name:"<<m_row[1]<<endl;
		cout<<"level:"<<"销售人员"<<endl;
		
		if(m_row[3]==NULL)
		{
			cout<<"salary:NULL"<<endl;
		}
		else
		{
		cout<<"salary:"<<m_row[3]<<endl;
		}
		
		cout<<"pwd:"<<m_row[4]<<endl;
		if(m_row[5]==NULL)
		{
			cout<<"leaderid:NULL"<<endl;
		}
		else
		{
		cout<<"leaderid:"<<m_row[5]<<endl;
		}
		
		if(m_row[8]==NULL)
		{
			cout<<"totalsale:NULL"<<endl;
		}
		else
		{
		cout<<"totalsale:"<<m_row[8]<<endl;
		}
		
		cout<<"salepay:"<<m_row[9]<<endl;
		cout<<"note:"<<m_row[10]<<endl;
	}
	else
	{
		cout<<"无id为"<<id<<"的销售人员"<<endl;
	}
	mysql_free_result(m_res);
}
void DataTable::lookSP()
{
	uint id;
	cout<<"请输入你想查找的销售人员id:";
	cin>>id;
	char mysql_select[64]={'\0'};
	sprintf(mysql_select,"select * from info where code=%d and level=4",id);
	if(mysql_query(m_conn,mysql_select))
	{
		cout<<"send sql is failed 1440\n";
		exit(1);
	}
	m_res=mysql_use_result(m_conn);
	if((m_row=mysql_fetch_row(m_res))!=NULL)
	{
		int i=0;
	//	string n="Null";
		
		cout<<"id:"<<m_row[0]<<endl;
		cout<<"name:"<<m_row[1]<<endl;
		cout<<"level:"<<"销售人员"<<endl;
		
		if(m_row[3]==NULL)
		{
			cout<<"salary:NULL"<<endl;
		}
		else
		{
		cout<<"salary:"<<m_row[3]<<endl;
		}
		
		cout<<"pwd:"<<m_row[4]<<endl;
		if(m_row[5]==NULL)
		{
			cout<<"leaderid:NULL\n";
		}
		else
		{
		cout<<"leaderid:"<<m_row[5]<<endl;
		}
		if(m_row[8]==NULL)
		{
			cout<<"totalsale:NULL"<<endl;
		}
		else
		{
		cout<<"totalsale:"<<m_row[8]<<endl;
		}
		
		cout<<"salepay:"<<m_row[9]<<endl;
		cout<<"note:"<<m_row[10]<<endl;
	}
	else
	{
		cout<<"无id为"<<id<<"的销售人员"<<endl;
	}
	mysql_free_result(m_res);
}
void DataTable::changeSP()
{

	uint id;
	cout<<"请输入你想修改的销售人员id:";
	cin>>id;
	char mysql_select[64]={'\0'};
	sprintf(mysql_select,"select * from info where code=%d and level=4",id);
	if((mysql_query(m_conn,mysql_select)))
	{
		cout<<"send sql is failed 1493"<<endl;
		cout<<mysql_error(m_conn)<<endl;
		exit(1);
	}
	m_res=mysql_use_result(m_conn);
	if((m_row=mysql_fetch_row(m_res))==NULL)
	{
		cout<<"无id为"<<id<<"的销售人员"<<endl;
		return;
	}
	mysql_free_result(m_res);
	cout<<"\t          change menu"<<endl;
	cout<<"\t1.名字   2.级别         3.薪水"<<endl;
	cout<<"\t4.销售额 5.销售提成(件) 6.备注"<<endl;
    char num='\0';
	cout<<"输入选项:";
	cin>>num;
	switch(num)
	{
		case '1':
				{
					char n[10]={'\0'};
					char mysql_update[64]={'\0'};
					char mysql_sel1[64]={'\0'};
					cout<<"输入新名字:";
					cin>>n;

					sprintf(mysql_update,"update info set name=\'%s\' where code=%d and level=4",n,id);
					if((mysql_query(m_conn,mysql_update)))
					{
						cout<<"send sql is failed 1523\n";
						cout<<mysql_error(m_conn)<<endl;
						exit(1);
					}
					sprintf(mysql_sel1,"select * from info where code=%d and name=\'%s\'",id,n);
					if((mysql_query(m_conn,mysql_sel1)))
					{
						cout<<"send sql is failed 1530"<<endl;
						exit(1);
					}
					m_res=mysql_use_result(m_conn);
					if((m_row=mysql_fetch_row(m_res))!=NULL)
					{
						cout<<"修改成功!"<<endl;
					}
					else
					{
						cout<<"修改失败!"<<endl;
					}
					mysql_free_result(m_res);
				}
				break;
		case '2':
				{
					uint uilevel;
					char mysql_updat[64]={'\0'};
					char mysql_sel2[64]={'\0'};
					while(1)
					{
					cout<<"\t1.技术经理 2.销售经理 3.技术人员 "<<endl;
					cout<<"输入新级别:";
					cin>>uilevel;
					switch(uilevel)
					{
						case 1:{
								char mysql_ch1[128]={'\0'};
								sprintf(mysql_ch1,"update info set salary=12000,leaderid=0,worktime=0,hourpay=0 where code=%d",id);
								if(mysql_query(m_conn,mysql_ch1))
								{
									cout<<"send sql is failed 1562"<<endl;
									exit(1);
								}
							   }
								break;
						case 2:
								{
								char mysql_ch2[128]={'\0'};
								sprintf(mysql_ch2,"update info set salary=10000,leaderid=0,worktime=0,hourpay=0,totalsale=0,salepay=20 where code=%d",id);
								if(mysql_query(m_conn,mysql_ch2))
								{
									cout<<"send sql is failed 1573"<<endl;
									exit(1);
								}
								}
								break;
						case 3:
								{
								uint lId;
								cout<<"输入上级id:";
								cin>>lId;
								char mysql_t[128]={'\0'};
								sprintf(mysql_t,"select * from info where code=%d and level=1",lId);
								if(mysql_query(m_conn,mysql_t))
								{
									cout<<"send sql is failed 1587"<<endl;
									exit(1);
								}
								m_res=mysql_use_result(m_conn);
								if((m_row=mysql_fetch_row(m_res))==NULL)
								{
									cout<<"无id为"<<lId<<"的技术经理"<<endl;
									return;
								}
								mysql_free_result(m_res);
								char mysql_ch3[128]={'\0'};
								sprintf(mysql_ch3,"update info set salary=0,leaderid=%d,worktime=0,hourpay=50,totalsale=0,salepay=0 where code=%d",lId,id);
								if(mysql_query(m_conn,mysql_ch3))
								{
									cout<<"send sql is failed 1601"<<endl;
									exit(1);
								}
								}	
								break;
						default:
								break;
					}
					if(uilevel==1||uilevel==2||uilevel==3)
					{
							break;
					}
					else
					{
						cout<<"请按要求设置级别"<<endl;
						return;
					}
					}

					sprintf(mysql_updat,"update info set level=%d where code=%d and level=4",uilevel,id);
					if((mysql_query(m_conn,mysql_updat)))
					{
						cout<<"send sql is failed 1623\n";
						exit(1);
					}
					
					sprintf(mysql_sel2,"select * from info where code=%d and level=%d",id,uilevel);
					if(mysql_query(m_conn,mysql_sel2))
					{
						cout<<"send sql is failed 1630"<<endl;
						exit(1);
					}

					m_res=mysql_use_result(m_conn);
					if((m_row=mysql_fetch_row(m_res))!=NULL)
					{
						cout<<"修改成功!"<<endl;
					}
					else
					{
						cout<<"修改失败!"<<endl;
						return;
					}
					mysql_free_result(m_res);
				}
				break;
		case '3':
				{
					int isalary;
					cout<<"输入薪资:";
					cin>>isalary;
					char mysql_upda[128]={'\0'};
					char mysql_sel2[128]={'\0'};
					cout<<"ok"<<endl;
					sprintf(mysql_upda,"update info set salary=%d where code=%d and level=4",isalary,id);
					cout<<"ok"<<endl;
					if((mysql_query(m_conn,mysql_upda)))
					{
						cout<<"ok"<<endl;
						cout<<"send sql is failed 1660\n";
						exit(1);
					}
				
					sprintf(mysql_sel2,"select * from info where code=%d and salary=%d",id,isalary);
					if((mysql_query(m_conn,mysql_sel2)))
					{
						cout<<"send sql is failed 1667\n";
						exit(1);
					}
					m_res=mysql_use_result(m_conn);
					if((m_row=mysql_fetch_row(m_res))!=NULL)
					{
						cout<<"修改成功"<<endl;
					}
					else
					{
						cout<<"修改失败"<<endl;
						return;
					}
					mysql_free_result(m_res);
					
				}
				break;
		case '4':
				{
					int wktm;
					cout<<"输入销售额:";
					cin>>wktm;
					char mysql_upd[64]={'\0'};
					char mysql_sel3[64]={'\0'};
					sprintf(mysql_upd,"update info set totalsale=%d where code=%d and level=4",wktm,id);
					if(mysql_query(m_conn,mysql_upd))
					{
						cout<<"send sql is failed 1694\n";
						exit(1);
					}
					sprintf(mysql_sel3,"select * from info where code=%d and totalsale=%d",id,wktm);
					if(mysql_query(m_conn,mysql_sel3))
					{
						cout<<"send sql is failed 1700\n";
						exit(1);
					}
					m_res=mysql_use_result(m_conn);
					if((m_row=mysql_fetch_row(m_res))==NULL)
					{
						cout<<"修改失败!"<<endl;
					}
					else
					{
						cout<<"修改成功!"<<endl;
						return;
					}
					mysql_free_result(m_res);
				}
				break;
		case '5':
				{
					int tsalary;
					cout<<"输入提成(件):";
					cin>>tsalary;
					char mysql_up[64]={'\0'};
					char mysql_sel4[64]={'\0'};
					sprintf(mysql_up,"update info set salepay=%d where code=%d and level=4",tsalary,id);
					if(mysql_query(m_conn,mysql_up))
					{
						cout<<"send sql is failed 1726\n";
						exit(1);
					}
					sprintf(mysql_sel4,"select * from info where code=%d and salepay=%d",id,tsalary);
					if(mysql_query(m_conn,mysql_sel4))
					{
						cout<<"send sql is failed 1732\n";
						exit(1);
					}
					m_res=mysql_use_result(m_conn);
					if((m_row=mysql_fetch_row(m_res))==NULL)
					{
						cout<<"修改失败!"<<endl;
					}
					else
					{
						cout<<"修改成功!"<<endl;
						return;
					}
					mysql_free_result(m_res);
				}
				break;
		case '6':
				{
					char nt[216]={'\0'};
					cout<<"输入备注:";
					cin>>nt;
					char mysql_upd[64]={'\0'};
					sprintf(mysql_upd,"update info set note=\'%s\' where code=%d and level=4",nt,id);
					if(mysql_query(m_conn,mysql_upd))
					{
						cout<<"send sql is failed 1757\n";
						cout<<mysql_error(m_conn)<<endl;
						exit(1);
					}
					else 
					{
						cout<<"修改成功!\n";
						return;
					}	
				}
				break;
		default:
				cout<<"请输入对应选项!\n";
				break;
}
}
void DataTable::addSPMA()
{
	char n[10]={'\0'};
	char mysql_insert[128]={'\0'};
	cout<<"姓名:";
	cin>>n;
	sprintf(mysql_insert,"insert into info(name,level,salary,pwd,totalsale,salepay,note) values(\'%s\',2,10000,'123456',0,20,'good')",n);
	if(mysql_query(m_conn,mysql_insert))
	{
		cout<<"send sql is failed 1782"<<endl;
		exit(1);
	}
	else
	{
		cout<<"添加成功"<<endl;
	}
}
void DataTable::delSPMA()
{
	uint id;
	cout<<"输入你想删除的销售经理的id:";
	cin>>id;
	char mysql_select[64]={'\0'};
	sprintf(mysql_select,"select * from info where code=%d and level=2",id);
	if(mysql_query(m_conn,mysql_select))
	{
		cout<<"send sql is failed 1799"<<endl;
		exit(1);
	}
	m_res=mysql_use_result(m_conn);
	if((m_row=mysql_fetch_row(m_res))==NULL)
	{
		cout<<"无id为"<<id<<"的销售经理"<<endl;
		return;
	}
	else
	{
		mysql_free_result(m_res);
		while(1)
		{
		cout<<"你是否确定要删除id为"<<id<<"的销售经理"<<m_row[1]<<"? y/n:";
		char ch='\0';
		cin>>ch;
		switch(ch)
		{
			case 'y':
					{
						char mysql_delete[64]={'\0'};
						sprintf(mysql_delete,"delete from info where code=%d and level=2",id);
						if(mysql_query(m_conn,mysql_delete))
						{
							cout<<"send sql is failed 1824"<<endl;
							exit(1);
						}
						else
						{
							cout<<"删除成功!"<<endl;
							return;
						}
					}
					break;
			case 'n':
					return;
					break;
			default:
						cout<<"请按提示输入!"<<endl;
					break;
		}
	  }
	}
}
void DataTable::lookSPMA()
{
	uint id;
	cout<<"输入你想查找的销售经理的id:";
	cin>>id;
	char mysql_select[64]={'\0'};
	sprintf(mysql_select,"select * from info where code=%d and level=2",id);
	if(mysql_query(m_conn,mysql_select))
	{
		cout<<"send sql is failed 1853"<<endl;
		exit(1);
	}
	m_res=mysql_use_result(m_conn);
	if((m_row=mysql_fetch_row(m_res))!=NULL)
	{
		cout<<"id:"<<m_row[0]<<endl;	
		cout<<"name:"<<m_row[1]<<endl;	
		cout<<"level:"<<m_row[2]<<endl;	
		cout<<"salary:"<<m_row[3]<<endl;	
		cout<<"pwd:"<<m_row[4]<<endl;	
		cout<<"totalsale:"<<m_row[8]<<endl;	
		cout<<"salepay:"<<m_row[9]<<endl;	
		cout<<"note:"<<m_row[10]<<endl;	
	}
	else
	{
		cout<<"无id为"<<id<<"的销售经理"<<endl;
	}
	mysql_free_result(m_res);
}
void DataTable::lookSPMA(uint id)
{
	char mysql_select[64]={'\0'};
	sprintf(mysql_select,"select * from info where code=%d and level=2",id);
	if(mysql_query(m_conn,mysql_select))
	{
		cout<<"send sql is failed 1880"<<endl;
		cout<<mysql_error(m_conn)<<endl;
		exit(1);
	}
	m_res=mysql_use_result(m_conn);
	if((m_row=mysql_fetch_row(m_res))!=NULL)
	{
		cout<<"id:"<<m_row[0]<<endl;	
		cout<<"name:"<<m_row[1]<<endl;	
		cout<<"level:"<<m_row[2]<<endl;	
		cout<<"salary:"<<m_row[3]<<endl;	
		cout<<"pwd:"<<m_row[4]<<endl;	
		cout<<"totalsale:"<<m_row[8]<<endl;	
		cout<<"salepay:"<<m_row[9]<<endl;	
		cout<<"note:"<<m_row[10]<<endl;	
	}
	mysql_free_result(m_res);
}
void DataTable::changeSPMA()
{
	uint id;
	cout<<"请输入你想修改的销售经理的id:";
	cin>>id;
	
	char mysql_select[64]={'\0'};
	sprintf(mysql_select,"select * from info where code=%d and level=2",id);
	if(mysql_query(m_conn,mysql_select))
	{
		cout<<"send sql is failed 1908"<<endl;
		exit(1);
	}
	m_res=mysql_use_result(m_conn);
	if((m_row=mysql_fetch_row(m_res))==NULL)
	{
		cout<<"查无此人"<<endl;
		return;
	}
	mysql_free_result(m_res);

	cout<<"		\tchange menu"<<endl;
	cout<<"\t1.name 2.level 3.salary 4.note 5.totalsale"<<endl;
    char num='\0';
	cout<<"输入选项:";
	cin>>num;
	switch(num)
	{
		case '1':
				{
					char n[24]={'\0'};
					cout<<"输入新名字:";
					cin>>n;
					char mysql_update[64]={'\0'};
					sprintf(mysql_update,"update info set name=\'%s\' where code=%d and level=2",n,id);

					if(mysql_query(m_conn,mysql_update))
					{
						cout<<"send sql is failed 1936\n";
						exit(1);
					}
					else 
					{
						cout<<"修改成功!\n";
						return;
					}
				}
				break;
		case '2':
				{
					uint uilevel;
					char mysql_updat[64]={'\0'};
					char mysql_sel2[64]={'\0'};
					while(1)
					{
					cout<<"\t1.技术经理 2.销售人员 3.技术人员 "<<endl;
					cout<<"输入新级别:";
					cin>>uilevel;
					switch(uilevel)
					{
						case 1:{
								char mysql_ch1[128]={'\0'};
								sprintf(mysql_ch1,"update info set salary=12000,leaderid=0,worktime=0,hourpay=0 where code=%d",id);
								if(mysql_query(m_conn,mysql_ch1))
								{
									cout<<"send sql is failed 1963"<<endl;
									exit(1);
								}
							   }
								break;
						case 2:
								{
								uint lId;
								cout<<"输入上级id:";
								cin>>lId;
								char mysql_t[128]={'\0'};
								sprintf(mysql_t,"select * from info where code=%d and level=2",lId);
								if(mysql_query(m_conn,mysql_t))
								{
									cout<<"send sql is failed 1977"<<endl;
									exit(1);
								}
								m_res=mysql_use_result(m_conn);
								if((m_row=mysql_fetch_row(m_res))==NULL)
								{
									cout<<"无id为"<<lId<<"的销售经理"<<endl;
									return;
								}
								mysql_free_result(m_res);
								char mysql_ch3[128]={'\0'};
								sprintf(mysql_ch3,"update info set salary=0,leaderid=%d,totalsale=0,salepay=50,worktime=0,hourpay=0 where code=%d",lId,id);
								if(mysql_query(m_conn,mysql_ch3))
								{
									cout<<"send sql is failed 1991"<<endl;
									exit(1);
								}
								
								}
								break;
						case 3:
								{
								uint lId;
								cout<<"输入上级id:";
								cin>>lId;
								char mysql_t[128]={'\0'};
								sprintf(mysql_t,"select * from info where code=%d and level=1",lId);
								if(mysql_query(m_conn,mysql_t))
								{
									cout<<"send sql is failed 2006"<<endl;
									exit(1);
								}
								m_res=mysql_use_result(m_conn);
								if((m_row=mysql_fetch_row(m_res))==NULL)
								{
									cout<<"无id为"<<lId<<"的技术经理"<<endl;
									return;
								}
								mysql_free_result(m_res);
								char mysql_ch3[128]={'\0'};
								sprintf(mysql_ch3,"update info set salary=0,leaderid=%d,worktime=0,hourpay=50,totalsale=0,salepay=0 where code=%d",lId,id);
								if(mysql_query(m_conn,mysql_ch3))
								{
									cout<<"send sql is failed 2020"<<endl;
									exit(1);
								}
								}	
								break;
						default:
								break;
					}
					if(uilevel==1||uilevel==2||uilevel==3)
					{
							break;
					}
					else
					{
						cout<<"请按要求设置级别"<<endl;
						return;
					}
					}

					sprintf(mysql_updat,"update info set level=%d where code=%d and level=2",uilevel,id);
					if((mysql_query(m_conn,mysql_updat)))
					{
						cout<<"send sql is failed\n";
						exit(1);
					}
					
					sprintf(mysql_sel2,"select * from info where code=%d and level=%d",id,uilevel);
					if(mysql_query(m_conn,mysql_sel2))
					{
						cout<<"send sql is failed 2049"<<endl;
						exit(1);
					}

					m_res=mysql_use_result(m_conn);
					if((m_row=mysql_fetch_row(m_res))!=NULL)
					{
						cout<<"修改成功!"<<endl;
					}
					else
					{
						cout<<"修改失败!"<<endl;
						return;
					}
					
				}
				break;
		case '3':
				{
					int isalary;
					cout<<"输入薪资:";
					cin>>isalary;
					char mysql_u[64]={'\0'};
					sprintf(mysql_u,"update info set salary=%d where code=%d and level=2",isalary,id);
					if(mysql_query(m_conn,mysql_u))
					{
						cout<<"send sql is failed 2075\n";
						exit(1);
					}
					else 
					{
						cout<<"修改成功!\n";
						return;
					}

				}
				break;
		case '4':
				{
					char nt[216]={'\0'};
					cout<<"输入备注:";
					cin>>nt;
					char mysql_upd[64]={'\0'};
					sprintf(mysql_upd,"update info set note=\'%s\' where code=%d and level=2",nt,id);
					if(mysql_query(m_conn,mysql_upd))
					{
						cout<<"send sql is failed 2095\n";
						cout<<mysql_error(m_conn)<<endl;
						exit(1);
					}
					else 
					{
						cout<<"修改成功!\n";
						return;
					}	
				}
				break;
		case '5':
				{
					int isale;
					cout<<"输入总销量:";
					cin>>isale;
					char mysql_upda[64]={'\0'};
					sprintf(mysql_upda,"update info set salary=%d where code=%d and level=2",isale,id);
					if(mysql_query(m_conn,mysql_upda))
					{
						cout<<"send sql is failed 2115\n";
						exit(1);
					}
					else 
					{
						cout<<"修改成功!\n";
						return;
					}

				}
				break;
		default:
				cout<<"请输入正确选项!"<<endl;
				break;
	}
}

