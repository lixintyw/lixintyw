#ifndef DATATABLE_H_
#define DATATABLE_H_
//#include<unistd.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<mysql/mysql.h>
#include"employee.h"
//#include"companny.h"
using namespace std;
class DataTable
{
		public:
				DataTable()
				{
					char server[20]="localhost";
					char user[20]="root";
					char password[20]="122616";
					char database[20]="companny";
					m_conn=mysql_init(NULL);
					if(!mysql_real_connect(m_conn,server,user,password,database,0,NULL,0))
					{
						cout<<"connect failed!\n";
						exit(1);
					}

					mysql_set_character_set(m_conn,"utf8");
				}
				void myfree();
				void PALL();
				void PTP();
				void PSP();

				void time();
				bool isEmpty();
				void addBoss();
				void loginBoss();

				uint loginTP();
				void addTP(uint uiId);
				void addTP();
				void delTP();
				void lookTP();
				void lookTP(uint uiId);
				void changePwdTp();
				void changeTP();

				uint loginTPMA();
				void addTPMA();
				void delTPMA();
				void lookTPMA();
				void lookTPMA(uint id);
				void changeTPMA();
				
				uint loginSP();
				void addSP();
				void addSP(uint uiId);
				void delSP();
				void lookSP();
				void lookSP(uint id);
				void changeSP();

				uint loginSPMA();
				void addSPMA();
				void delSPMA();
				void lookSPMA(uint id);
				void lookSPMA();
				void changeSPMA();

				
				~DataTable()
				{
					mysql_close(m_conn);
				}
		private:
				MYSQL *m_conn;
				MYSQL_RES *m_res;
				MYSQL_ROW m_row;
};
#endif
