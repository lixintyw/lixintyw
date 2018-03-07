#include "company.h"
using namespace std;


int position=66;//记录身份

//封装数据库
typedef map<string,string> Record; 			//存储一行数据   
typedef map<string,string>::iterator RecordIter; 
typedef vector<Record> Table;				//存储整张表的数据    
typedef vector<Record>::iterator TableIter;
typedef vector<string> Fields;				//存储每一列的名字    
typedef vector<string>::iterator FieldsIter;

class MysqlDBAccess
{
private:
	MYSQL *mysql;
	MYSQL_RES *result;
	MYSQL_ROW row;							//获取行
	MYSQL_FIELD *field;						//获取列
	bool isSeverConnected;
	bool isDBConnected;
	string dbName;
protected:
	int GetFields(Fields &fields);			//获取列的名字
	void DisplayTable(Fields fd,Table dt);	//打印表dt的数据
public:

	MysqlDBAccess()
	{
		isSeverConnected=isDBConnected=false;
	}
	~MysqlDBAccess()
	{
		if(isSeverConnected) DisconnectSever();
	}
	bool ConnectSever(string serverName,string userName,string pwd="123",int port=3306);//连接服务器
	void DisconnectSever()
	{
		mysql_close(mysql);
	}
	bool ConnectDB(string dbName);//连接数据库
	bool ExcuteSQL(string sql);//执行语句
	void mysqldbinit(MysqlDBAccess &sql);//数据库初始化
	void SelectPrint(char *post);//执行查询语句并显示查询内容
	int login(char *name,char *passwd);//用户名密码验证并返回用户ID
	int change(MysqlDBAccess &sql);//修改函数
	
    void SelectPrintManager(char *post);
    void SelectPrintSalesManager(char *post);
    void SelectPrintSaler(char *post);
    void SelectPrintTechnicians(char *post);
    void printMeSaler(char * name);
    void printMeTechnicians(char *name);
    void changeMoney(MysqlDBAccess &mysql,string name);
};


//密码修改
void changePasswd(MysqlDBAccess &mysql,string name);
//性别修改
void changeSex(MysqlDBAccess &mysql,string name);
//等级修改
void changePost(MysqlDBAccess &mysql,string name);
//月薪修改
void changeMonthSalary(MysqlDBAccess &mysql,string name);
//修改时薪
void changehourSalary(MysqlDBAccess &mysql,string name);
//修改工作时间
void changeHour(MysqlDBAccess &mysql,string name);
//修改销售额
void changeSalesMount(MysqlDBAccess &mysql,string name);
//修改提成
void changeScale(MysqlDBAccess &mysql,string name);


bool MysqlDBAccess::ConnectSever(string serverName,string userName,string pwd,int port)
{
	mysql=mysql_init(NULL);
	if(!mysql_real_connect(mysql,serverName.c_str(),userName.c_str(),pwd.c_str(),NULL,port,NULL,0))
	//为了与 c兼容，在c语言中没有string类型，故必须通过string类对象的成员函数c_str()把string对象转换称c的字符串样式
	{
		cout<<"mysql_real_connect:"<<mysql_error(mysql)<<endl;
		return false;
	}
	else
		isSeverConnected=true;
	return true;
}
//进入数据库
bool MysqlDBAccess::ConnectDB(string dbName)
{
	//mysql_select_db(conn,"dbname");
	if(mysql_select_db(mysql,dbName.c_str()))
	{
		cout<<"mysql_select_db:"<<mysql_error(mysql)<<endl;
		return false;
	}
	isDBConnected=true;
	this->dbName=dbName;   //??
	return true;
}

bool MysqlDBAccess::ExcuteSQL(string sql)
{
	mysql_set_character_set(mysql,"utf8");
	if(mysql_query(mysql,sql.c_str()))
	{
		cout<<"mysql_query:"<<mysql_error(mysql)<<endl;
		return false;
	}
	return true;
}

void MysqlDBAccess::mysqldbinit(MysqlDBAccess &sql)
{
	sql.ConnectSever("localhost","root");
	sql.ExcuteSQL("create database  if not exists Company");
	sql.ConnectDB("Company");

	//创建员工表
	sql.ExcuteSQL("create table if not exists staff(\
				   id int auto_increment primary key,\
                   name varchar(20),\
                   passwd varchar(20) default '123',\
                   sex varchar(20),\
                   post varchar(40))");
    const char *selectSQL="select *from staff where name='root'";
	ExcuteSQL(selectSQL);
	result=mysql_store_result(mysql);
	row=mysql_fetch_row(result); //查询是否有root用户
	if(row==NULL)
	 	ExcuteSQL("insert into staff(id,name,post) values(1,'root','root')");
	else
		mysql_free_result(result);
    sql.ExcuteSQL("create table if not exists manager(\
                    name varchar(20) primary key,\
                    passwd varchar(20) default '123',\
                    sex varchar(20),\
                    monthSalary float default 5000,\
                    month double default 10,\
                    allSalary float default 50000,\
                    remark varchar(200) default 'a')");
    
    sql.ExcuteSQL("create table if not exists salesManager(\
                    name varchar(20),\
                    passwd varchar(20) default '123',\
                    sex varchar(20),\
                    monthSalary float default 3000,\
                    salesMount float default 0,\
                    scale float default 0.08,\
                    month float default 10,\
                    allSalary float default 30000,\
                    remark varchar(200) default 'b')");
                
    sql.ExcuteSQL("create table if not exists saler(\
                    name varchar(20),\
                    passwd varchar(20) default '123', \
                    sex varchar(20) ,\
                    salesMount float default 0,\
                    scale float default 0.1,\
                    allSalary float default 0,\
                    remark varchar(150) default 'c')");

    sql.ExcuteSQL("create table if not exists technicians(\
                    name varchar(20),\
                    passwd varchar(20) default '123',\
                    sex varchar(20),\
                    hourSalary float default 500,\
                    hour float default 8,\
                    allSalary float default 4000,\
                    remark varchar(200) default 'd')");                                
}


//登录验证
int MysqlDBAccess::login(char *name,char *passwd)
{
    char str[150];
    sprintf(str,"select *from staff where name=\'%s\'",name);
    ExcuteSQL(str);
    result=mysql_store_result(mysql);
	row=mysql_fetch_row(result);
    if(row==NULL)
    {
        cout<<"姓名输入错误"<<endl;
        return -1;//表示姓名输入错误
    }
    
    mysql_free_result(result);
    if(strcmp(row[2],passwd)==0)
    {

        if(strcmp(row[4],"root")==0)
        {
            position=1;            
            return 1;//表示是root
        }
        if(strcmp(row[4],"manager")==0)
        {
            position=2;
            return 2;//表示是经理
        }
        if(strcmp(row[4],"salesManager")==0)
        {
            position=3;
            return 3;//表示是销售经理
        }
        if(strcmp(row[4],"technicians")==0)
        {
            position=4;
            return 4;//表示是兼职技术人员
        }
        if(strcmp(row[4],"saler")==0)
        {
            position=5;
            return 5;//表示是兼职销售人员
        }
    }
    cout<<"密码错误"<<endl;
    return 0;
}



//修改工资
void MysqlDBAccess::changeMoney(MysqlDBAccess &sql,string name)
{
    char str[200];
    char str1[200];
    float a,b,c,d,e;
    if(position==1)
    {
        sprintf(str,"select * from manager where name=\'%s\'",name.c_str());        
        ExcuteSQL(str);
        result=mysql_store_result(mysql);
        while((row=mysql_fetch_row(result))!=NULL)
        {
            a=atof(row[3]);
            b=atof(row[4]);
            c=a*b;
            sprintf(str1,"update manager set allSalary=%.2f where name=\'%s\'",c,name.c_str());
            ExcuteSQL(str1);            
        }
    }
    if(position==8)
    { 
        sprintf(str,"select * from salesManager where name=\'%s\'",name.c_str());   

        ExcuteSQL(str);
        result=mysql_store_result(mysql);
        while((row=mysql_fetch_row(result))!=NULL)
        {
            a=atof(row[3]);
            b=atof(row[6]);
            c=atof(row[4]);
            d=atof(row[5]);
            e=a*b+c*d;
            sprintf(str1,"update salesManager set allSalary=%.2f where name=\'%s\'",e,name.c_str());
            ExcuteSQL(str1);
        }
    }
    if(position==2)//说明是经理
    {
        sprintf(str,"select * from technicians where name=\'%s\'",name.c_str());        
        ExcuteSQL(str);
        result=mysql_store_result(mysql);
        while((row=mysql_fetch_row(result))!=NULL)
        {
            a=atof(row[3]);
            b=atof(row[4]);
            c=a*b;
            sprintf(str1,"update technicians set allSalary=%.2f where name=\'%s\'",c,name.c_str());
            ExcuteSQL(str1);            
        }
    }
    if(position==3)//说明是销售经理
    {
        sprintf(str,"select * from saler where name=\'%s\'",name.c_str());        
        ExcuteSQL(str);
        result=mysql_store_result(mysql);
        while((row=mysql_fetch_row(result))!=NULL)
        {
            a=atof(row[3]);
            b=atof(row[4]);
            c=a*b;
            sprintf(str1,"update saler set allSalary=%.2f where name=\'%s\'",c,name.c_str());
            ExcuteSQL(str1);            
        }
        //修改销售额对销售经理销售额的影响
        string str2="select salesMount from saler";
        float sum=0;
        float temp;
        ExcuteSQL(str2);
        result=mysql_store_result(mysql);
        while((row=mysql_fetch_row(result))!=NULL)
        {
            temp=atof(row[0]);
            sum+=temp;
        }
        sprintf(str1,"update salesManager set salesMount=%f ",sum);
        ExcuteSQL(str1);

        str2="select * from salesManager";      
        ExcuteSQL(str2);
        result=mysql_store_result(mysql);
        while((row=mysql_fetch_row(result))!=NULL)
        {
            a=atof(row[3]);
            b=atof(row[4]);
            c=a*b;
            sprintf(str1,"update technicians set allSalary=%.2f",c);
            ExcuteSQL(str1);            
        }
    }
}  



//查看人员信息
void MysqlDBAccess::SelectPrint(char *post)
{
    char str[150];
    sprintf(str,"select * from staff where post=\'%s\'",post);
    ExcuteSQL(str);
    result=mysql_store_result(mysql);
    while((row=mysql_fetch_row(result))!=NULL)
    {
        cout<<"编号:"<<row[0]<<" "<<"姓名:"<<row[1]<<" "<<"密码:"<<row[2]<<" "
        <<"性别:"<<row[3]<<" "<<"职位:"<<row[4]<<endl;
    }
}



//查看经理信息
void MysqlDBAccess::SelectPrintManager(char *post)
{
    char str[200];
    sprintf(str,"select * from %s",post);
    ExcuteSQL(str);
    result=mysql_store_result(mysql);
    while((row=mysql_fetch_row(result))!=NULL)
    {
        cout<<"月薪:"<<row[3]<<" "<<"工时（月）:"<<row[4]<<" "<<"薪资:"<<row[5]<<" "<<"remark:"<<row[6]<<endl;
    }
}



//查看销售经理信息
void MysqlDBAccess::SelectPrintSalesManager(char *post)
{
    char str[180];
    sprintf(str,"select monthSalary,salesMount,scale,month,allSalary,remark from %s",post);
    ExcuteSQL(str);
    result=mysql_store_result(mysql);
    while((row=mysql_fetch_row(result))!=NULL)
    {
        cout<<"月薪:"<<row[0]<<" "<<"销售额:"<<row[1]<<" "<<"提成:"<<row[2]<<" "<<"工时（月）:"<<row[3]<<" "<<"薪资:"<<row[4]<<" "<<"remark:"<<row[5]<<endl;
    }
}



//查看销售员信息
void MysqlDBAccess::SelectPrintSaler(char *post)
{
    char str[150];
    sprintf(str,"select salesMount,scale,allSalary,remark from %s",post);
    ExcuteSQL(str);
    result=mysql_store_result(mysql);
    while((row=mysql_fetch_row(result))!=NULL)
    {
        cout<<"销售额:"<<row[0]<<" "<<"提成:"<<row[1]<<" "<<"薪资:"<<row[2]<<" "<<"remark:"<<row[3]<<endl;
    }
}




//查看技术员信息
void MysqlDBAccess::SelectPrintTechnicians(char * post)
{
    char str[200];
    sprintf(str,"select hourSalary,hour,allSalary,remark from %s",post);
    ExcuteSQL(str);
    result=mysql_store_result(mysql);
    while((row=mysql_fetch_row(result))!=NULL)
    {
        cout<<"时薪:"<<row[0]<<" "<<"工时（小时）:"<<row[1]<<" "<<"薪资:"<<row[2]<<" "<<"remark:"<<row[3]<<endl;
    }
}



class root
{
public:
    void addManager(MysqlDBAccess &mysql);
    void deleteManager(MysqlDBAccess &mysql);
    void changeManager(MysqlDBAccess &mysql);
    void printManager(MysqlDBAccess &mysql);
    void addSalesManager(MysqlDBAccess &mysql);
    void deleteSalesManager(MysqlDBAccess &mysql);
    void changeSalesManager(MysqlDBAccess &mysql);
    void printSalesManager(MysqlDBAccess &mysql);
};


class manager
{
public:
    void addTechnicians(MysqlDBAccess &mysql);
    void deleteTechnicians(MysqlDBAccess &mysql);
    void changeTechnicians(MysqlDBAccess &mysql);
    void printTechnicians(MysqlDBAccess &mysql);
};


class salesManager
{
public:
    void addSaler(MysqlDBAccess &mysql);
    void deleteSaler(MysqlDBAccess &mysql);
    void changeSaler(MysqlDBAccess &mysql);
    void printSaler(MysqlDBAccess &mysql);
};



//修改函数
int MysqlDBAccess::change(MysqlDBAccess &sql)
{  
    if(position==1) //说明是root
    {
        cout<<"修改经理信息"<<endl;

        if(position==8)
        {
           cout<<"2.修改销售经理信息"<<endl;
            char name[20];
            cout<<"请输入需要修改的销售经理的姓名"<<endl;
            cin>>name;
            char str[150];
            sprintf(str,"select *from salesManager where name=\'%s\'",name);
            ExcuteSQL(str);
            result=mysql_store_result(mysql);
            row=mysql_fetch_row(result);
            if(row==NULL)
            {
                cout<<"姓名输入错误"<<endl;
                return -1;//表示姓名输入错误
            }
            while((row=mysql_fetch_row(result))!=NULL)
            {
                cout<<"name:"<<row[0]<<"passwd"<<row[1]<<"sex:"<<row[2]<<"monthSalary"<<row[3]<<"salesMount"<<row[4]<<"scale"<<row[5]<<"allSally"<<row[6]<<"remark"<<row[7]<<endl;
            }
            int key;
            while(1)
            {            
                cout<<"1.修改密码"<<endl;
                cout<<"2.修改性别"<<endl;
                cout<<"3.修改身份"<<endl;
                cout<<"4.修改工资"<<endl;
                cout<<"5.修改提成比例"<<endl;
                cout<<"0.退出"<<endl;    
                cout<<"请输入你的选择";
                cin>>key;
                switch(key)
                {
                    case 1:
                        changePasswd(sql,name);
                        break;
                    case 2:
                        changeSex(sql,name);
                        break;
                    case 3:
                        changePost(sql,name);
                        break;
                    case 4:
                        changeMonthSalary(sql,name);
                        break;
                    case 5:
                        changeScale(sql,name);
                    case 0:
                        return 0;
                    default:
                        cout<<"输入有误,请重新输入"<<endl;
                        break;
                }
            }
        }
        if(position==1)
        {
            position=1;
            char name[20];
            cout<<"请输入需要修改人员的姓名"<<endl;
            cin>>name;
            char str[150];
            sprintf(str,"select *from manager where name=\'%s\'",name);
            ExcuteSQL(str);
            result=mysql_store_result(mysql);
            row=mysql_fetch_row(result);
            if(row==NULL)
            {
                cout<<"姓名输入错误"<<endl;
                return -1;//表示姓名输入错误
            }
            while((row=mysql_fetch_row(result))!=NULL)
            {
                cout<<"name:"<<row[0]<<"passwd"<<row[1]<<"sex:"<<row[2]<<"monthSalary"<<row[3]<<"allSalary"<<row[4]<<"remark"<<row[5]<<endl;
            }
            int key;
            while(1)
            {            
                cout<<"1.修改密码"<<endl;
                cout<<"2.修改性别"<<endl;
                cout<<"3.修改身份"<<endl;
                cout<<"4.修改工资"<<endl;
                cout<<"0.退出"<<endl;    
                cout<<"请输入你的选择";
                cin>>key;
                switch(key)
                {
                    case 1:
                        changePasswd(sql,name);
                        break;
                    case 2:
                        changeSex(sql,name);
                        break;
                    case 3:
                        changePost(sql,name);
                        break;
                    case 4:
                        changeMonthSalary(sql,name);
                        break;
                    case 0:
                        return 0;
                    default:
                        cout<<"输入有误,请重新输入"<<endl;
                        break;
                }
            }
        }
    }
    if(position==2) //说明是经理
    {
        char name[20];
        cout<<"请输入需要修改人员的姓名"<<endl;
        cin>>name;
        char str[150];
        sprintf(str,"select *from technicians where name=\'%s\'",name);
        ExcuteSQL(str);
        MYSQL_RES *result=mysql_store_result(mysql);
        MYSQL_ROW row=mysql_fetch_row(result);
        if(row==NULL)
        {
            cout<<"姓名输入错误"<<endl;
            return -1;//表示姓名输入错误
        }
        while((row=mysql_fetch_row(result))!=NULL)
        {
            cout<<"name"<<row[0]<<"passwd"<<row[1]<<"sex"<<row[2]<<"hourSalary"<<row[3]<<"hour"<<row[4]<<"remark"<<row[5]<<endl;
        }
        int key;
        while(1)
        {            
            cout<<"1.修改密码"<<endl;
            cout<<"2.修改性别"<<endl;
            cout<<"3.修改身份"<<endl;
            cout<<"4.修改时工资"<<endl;
            cout<<"5.修改工作时长"<<endl;
            cout<<"0.退出"<<endl;    
            cout<<"请输入你的选择";
            cin>>key;
            switch(key)
            {
                case 1:
                    changePasswd(sql,name);
                    break;
                case 2:
                    changeSex(sql,name);
                    break;
                case 3:
                    changePost(sql,name);
                    break;
                case 4:
                    changehourSalary(sql,name);
                    break;
                case 5:
                    changeHour(sql,name);
                    break;
                case 0:
                    return 0;
                default:
                    cout<<"输入有误,请重新输入"<<endl;
                    break;
            }
        }
    }
    if(position==3) //说明是销售经理
    {
        char name[20];
        cout<<"请输入需要修改人员的姓名"<<endl;
        cin>>name;
        char str[150];
        sprintf(str,"select *from saler where name=\'%s\'",name);
        ExcuteSQL(str);
        MYSQL_RES* result=mysql_store_result(mysql);
        MYSQL_ROW row=mysql_fetch_row(result);
        if(row==NULL)
        {
            cout<<"姓名输入错误"<<endl;
            return -1;//表示姓名输入错误
        }
        while((row=mysql_fetch_row(result))!=NULL)
        {
            cout<<"name"<<row[0]<<"passwd"<<row[1]<<"sex"<<row[2]<<"slaesMount"<<row[3]<<"scale"<<row[4]<<endl;
        }
        int key;
        while(1)
        {            
            cout<<"1.修改密码"<<endl;
            cout<<"2.修改性别"<<endl;
            cout<<"3.修改身份"<<endl;
            cout<<"4.修改销售额"<<endl;
            cout<<"5.修改提成"<<endl;
            cout<<"0.退出"<<endl;    
            cout<<"请输入你的选择";
            cin>>key;
            switch(key)
            {
                case 1:
                    changePasswd(sql,name);
                    break;
                case 2:
                    changeSex(sql,name);
                    break;
                case 3:
                    changePost(sql,name);
                    break;
                case 4:
                    changeSalesMount(sql,name);
                    break;
                case 5:
                    changeScale(sql,name);
                    break;
                case 0:
                    return 0;
                default:
                    cout<<"输入有误,请重新输入"<<endl;
                    break;
            }        
        }
    }
}




//密码修改
void changePasswd(MysqlDBAccess &mysql,string name)
{
    string passwd;
    char str[120];
    char str1[120];
    string post1;
    cout<<"请输入修改后的密码:";
    cin>>passwd;
    if(position==1)
    {
        post1="manager";
    }
    if(position==2)
    {
        post1="technicians";
    }
    if(position==3)
    {
        post1="saler";
    }
    if(position==8)
    {
        post1="salesManager";
    }
    sprintf(str,"update %s set passwd=\'%s\' where name=\'%s\'",post1.c_str(),passwd.c_str(),name.c_str());
    sprintf(str1,"update staff set passwd=\'%s\' where name=\'%s\'&&post=\'%s\'",passwd.c_str(),name.c_str(),post1.c_str());
    if(mysql.ExcuteSQL(str)==false||mysql.ExcuteSQL(str1)==false)
    {
        cout<<"修改失败"<<endl;
    }
    else
        cout<<"修改成功"<<endl;
}




//性别修改
void changeSex(MysqlDBAccess &mysql,string name)
{
    string sex;
    cout<<"请输入修改后的性别:";
    cin>>sex;
    char str[120];
    char str1[120];
    string post1;
    if(position==1)
    {
        post1="manager";
    }
    if(position==2)
    {
        post1="technicians";
    }
    if(position==3)
    {
        post1="saler";
    }
    if(position==8)
    {
        post1="salesManager";
    }
    sprintf(str,"update %s set sex=\'%s\' where name=\'%s\'",post1.c_str(),sex.c_str(),name.c_str());
    sprintf(str1,"update staff set sex=\'%s\' where name=\'%s\'&&post=\'%s\'",sex.c_str(),name.c_str(),post1.c_str());
    
    if(mysql.ExcuteSQL(str)==false||mysql.ExcuteSQL(str1)==false)
    {
        cout<<"修改失败"<<endl;
    }
    else
        cout<<"修改成功"<<endl;
}




//等级修改
void changePost(MysqlDBAccess &mysql,string name)
{
    string post;
    cout<<"请输入修改后的等级:";
    cin>>post;
    char str[120];
    char str1[120];
    string post1;
    if(position==1)
    {
        post1="manager";
    }
    if(position==2)
    {
        post1="technicians";
    }
    if(position==3)
    {
        post1="saler";
    }
    if(position==8)
    {
        post1="salesManager";
    }
    sprintf(str,"delete from %s  where name=\'%s\'",post1.c_str(),name.c_str());
    sprintf(str1,"update staff set post=\'%s\' where name=\'%s\'&&post=\'%s\'",post.c_str(),name.c_str(),post1.c_str());

    if(mysql.ExcuteSQL(str)==false||mysql.ExcuteSQL(str1)==false)
    {
        cout<<"修改失败"<<endl;
    }
    else
        cout<<"修改成功"<<endl;
}




//月薪修改
void changeMonthSalary(MysqlDBAccess &mysql,string name)
{
    float monthSalary;
    cout<<"请输入修改后的月薪:";
    cin>>monthSalary;
    char str[120];
    string post1;
    if(position==1)
    {
       post1="manager";
    }
    if(position==8)
    {
        post1="salesManager";
    }
    sprintf(str,"update %s set monthSalary=%f where name=\'%s\'",post1.c_str(),monthSalary,name.c_str());

    if(mysql.ExcuteSQL(str)==false)
    {
        cout<<"修改失败"<<endl;
    }
    else
        mysql.changeMoney(mysql,name);
        cout<<"修改成功"<<endl;
        
}




//修改时薪
void changehourSalary(MysqlDBAccess &mysql,string name)
{
    float hourSalary;
    cout<<"请输入修改后的时薪:";
    cin>>hourSalary;
    char str[120]; 
    string post1="technicians";
    sprintf(str,"update %s set hourSalary=%f where name=\'%s\'",post1.c_str(),hourSalary,name.c_str());
    if(mysql.ExcuteSQL(str)==false)
    {
        cout<<"修改失败"<<endl;
    }
    else
        mysql.changeMoney(mysql,name.c_str());
        cout<<"修改成功"<<endl;
}



//修改工作时间
void changeHour(MysqlDBAccess &mysql,string name)
{
    float hour;
    cout<<"请输入修改后的工作时长:";
    cin>>hour;
    
    char str[120];
    string post1="technicians"; 
    sprintf(str,"update %s set hour=%f where name=\'%s\'",post1.c_str(),hour,name.c_str());
    if(mysql.ExcuteSQL(str)==false)
    {
        cout<<"修改失败"<<endl;
    }
    else
        mysql.changeMoney(mysql,name.c_str());
        cout<<"修改成功"<<endl;
}




//修改销售额
void changeSalesMount(MysqlDBAccess &mysql,string name)
{
    float salesMount;
    cout<<"请输入修改后的销售额:";
    cin>>salesMount;  
    char str[120];
    string post1="saler";
    sprintf(str,"update %s set salesMount=%f where name=\'%s\'",post1.c_str(),salesMount,name.c_str());

    if(mysql.ExcuteSQL(str)==false)
    {
        cout<<"修改失败"<<endl;
    }
    
    else
        mysql.changeMoney(mysql,name);
        cout<<"修改成功"<<endl;
    //修改后工资的变化

}




//修改提成
void changeScale(MysqlDBAccess &mysql,string name)
{
    float scale;
    cout<<"请输入修改后的提成:";
    cin>>scale;
    char str[120];
    string post1;
    if(position==3)
    {
        post1="saler";
    }
    if(position==8)
    {
        post1="salesManager";
    }
    sprintf(str,"update %s set scale=%f where name=\'%s\'",post1.c_str(),scale,name.c_str());

    if(mysql.ExcuteSQL(str)==false)
    {
        cout<<"修改失败"<<endl;
    }
    else
        mysql.changeMoney(mysql,name.c_str());
        cout<<"修改成功"<<endl;
}



//root查看经理信息
void root::printManager(MysqlDBAccess &mysql)
{
    char post[20]="manager";
    mysql.SelectPrint(post);
    mysql.SelectPrintManager(post);
}



//root添加经理信息
void root::addManager(MysqlDBAccess &mysql)
{
    char name[20];
    char sex[20];
    char post[20]="manager";
   
    char str[150];
    char str1[200];
    cout<<"请输入姓名:";
    cin>>name;
    cout<<"请输入性别:";
    cin>>sex;
    sprintf(str,"insert into staff(name,sex,post) values (\'%s\',\'%s\',\'%s\')",name,sex,post);
    sprintf(str1,"insert into manager(name,sex) values(\'%s\',\'%s\')",name,sex);

    if(mysql.ExcuteSQL(str)==false||mysql.ExcuteSQL(str1)==false)
    {
        cout<<"添加失败"<<endl;
    }
    else
        cout<<"添加成功"<<endl;
}



//root删除经理信息
void root::deleteManager(MysqlDBAccess &mysql)
{
    string name;
    cout<<"请输入需要删除的姓名:";
    char str[150];
    char str1[150];
    cin>>name;
    sprintf(str,"delete from staff where name=\'%s\'",name.c_str());
    sprintf(str1,"delete from manager where name=\'%s\'",name.c_str());
    if(mysql.ExcuteSQL(str)==false||mysql.ExcuteSQL(str1)==false)
    {
        cout<<"删除失败"<<endl;
    }
    else
        cout<<"删除成功"<<endl;
};



//root修改经理信息
void root::changeManager(MysqlDBAccess &mysql)
{ 
    mysql.change(mysql);
}




//root查看销售经理
void root::printSalesManager(MysqlDBAccess &mysql)
{
    char post[20]="salesManager";
    mysql.SelectPrint(post);
    mysql.SelectPrintSalesManager(post);
}



//root添加销售经理
void root::addSalesManager(MysqlDBAccess &mysql)
{
    string name;
    string sex;
    string post="salesManager";
   
    char str[150];
    char str1[200];
    cout<<"请输入姓名:";
    cin>>name;
    cout<<"请输入性别:";
    cin>>sex;
    sprintf(str,"insert into staff(name,sex,post) values (\'%s\',\'%s\',\'%s\')",name.c_str(),sex.c_str(),post.c_str());
    sprintf(str1,"insert into salesManager(name,sex) values(\'%s\',\'%s\')",name.c_str(),sex.c_str());
    if(mysql.ExcuteSQL(str)==false||mysql.ExcuteSQL(str1)==false)
    {
        cout<<"添加失败"<<endl;
    }
    cout<<"添加成功"<<endl;
}



//root删除销售经理
void root::deleteSalesManager(MysqlDBAccess &mysql)
{
    string name;
    cout<<"请输入需要删除的姓名:";
    char str[150];
    char str1[150];
    cin>>name;
    sprintf(str,"delete from staff where name=\'%s\'",name.c_str());
    sprintf(str1,"delete from salesManager where name=\'%s\'",name.c_str());
    if(mysql.ExcuteSQL(str)==false||mysql.ExcuteSQL(str1)==false)
    {
        cout<<"删除失败"<<endl;
    }
    else
        cout<<"删除成功"<<endl;
};



//root修改销售经理
void root::changeSalesManager(MysqlDBAccess &mysql)
{
    mysql.change(mysql);
}



//经理查看技术员信息
void manager::printTechnicians(MysqlDBAccess &mysql)
{
    char post[20]="technicians";
    mysql.SelectPrint(post);
    mysql.SelectPrintTechnicians(post);
}



//经理添加技术员信息
void manager::addTechnicians(MysqlDBAccess &mysql)
{
    string name;
    string sex;
    string post="technicians";
   
    char str[150];
    char str1[200];
    cout<<"请输入姓名:";
    cin>>name;
    cout<<"请输入性别:";
    cin>>sex;
    sprintf(str,"insert into staff(name,sex,post) values (\'%s\',\'%s\',\'%s\')",name.c_str(),sex.c_str(),post.c_str());
    sprintf(str1,"insert into technicians(name,sex) values(\'%s\',\'%s\')",name.c_str(),sex.c_str());
    if(mysql.ExcuteSQL(str)==false||mysql.ExcuteSQL(str1)==false)
    {
        cout<<"添加失败"<<endl;
    }
    cout<<"添加成功"<<endl;
}



//经理删除技术员信息
void manager::deleteTechnicians(MysqlDBAccess &mysql)
{
    string name;
    cout<<"请输入需要删除的姓名:";
    char str[150];
    char str1[150];
    cin>>name;
    sprintf(str,"delete from staff where name=\'%s\'",name.c_str());
    sprintf(str1,"delete from technicians where name=\'%s\'",name.c_str());
    if(mysql.ExcuteSQL(str)==false||mysql.ExcuteSQL(str1)==false)
    {
        cout<<"删除失败"<<endl;
    }
    cout<<"删除成功"<<endl;
};



//经理修改技术员信息
void manager::changeTechnicians(MysqlDBAccess &mysql)
{
     mysql.change(mysql);
}



//销售经理查看销售员信息
void salesManager::printSaler(MysqlDBAccess &mysql)
{
    char post[20]="saler";
    mysql.SelectPrint(post);
    mysql.SelectPrintSaler(post);
}



//销售经理添加销售员信息
void salesManager::addSaler(MysqlDBAccess &mysql)
{
    string name;
    string sex;
    string post="saler";
   
    char str[150];
    char str1[200];
    cout<<"请输入姓名:";
    cin>>name;
    cout<<"请输入性别:";
    cin>>sex;
    sprintf(str,"insert into staff(name,sex,post) values (\'%s\',\'%s\',\'%s\')",name.c_str(),sex.c_str(),post.c_str());
    sprintf(str1,"insert into saler(name,sex) values(\'%s\',\'%s\')",name.c_str(),sex.c_str());
    if(mysql.ExcuteSQL(str)==false||mysql.ExcuteSQL(str1)==false)
    {
        cout<<"添加失败"<<endl;
    }
    cout<<"添加成功"<<endl;
}



//销售经理删除销售员信息
void salesManager::deleteSaler(MysqlDBAccess &mysql)
{
    string name;
    cout<<"请输入需要删除的姓名:";
    char str[150];
    char str1[150];
    sprintf(str,"delete from staff where name=\'%s\'",name.c_str());
    sprintf(str1,"delete from  saler where name=\'%s\'",name.c_str());
    if(mysql.ExcuteSQL(str)==false||mysql.ExcuteSQL(str1)==false)
    {
        cout<<"删除失败"<<endl;
    }
    cout<<"删除成功"<<endl;
};



//销售经理修改销售员信息
void salesManager::changeSaler(MysqlDBAccess &mysql)
{
     mysql.change(mysql);
}



//销售员查看自己信息
void MysqlDBAccess::printMeSaler(char *name)
{
    char str[150];
    sprintf(str,"select * from saler where name=\'%s\'",name);
    ExcuteSQL(str);
    result=mysql_store_result(mysql);
    while((row=mysql_fetch_row(result))!=NULL)
    {
        cout<<"姓名:"<<row[0]<<" "<<"密码:"<<row[1]<<" "<<"性别:"<<row[2]<<" "<<"销售额:"<<row[3]<<" "<<"提成"<<row[4]<<" "<<"薪资"<<row[5]<<"remark"<<row[6]<<endl;
    }
}



//技术员查看自己信息
void MysqlDBAccess::printMeTechnicians(char *name)
{
    char str[150];
    sprintf(str,"select * from technicians where name=\'%s\'",name);
    ExcuteSQL(str);
    result=mysql_store_result(mysql);
    while((row=mysql_fetch_row(result))!=NULL)
    {
        cout<<"姓名:"<<row[0]<<" "<<"密码:"<<row[1]<<" "<<"性别:"<<row[2]<<" "<<"时薪:"<<row[3]<<" "<<"工时（小时）:"<<row[4]<<" "<<"薪资:"<<row[5]<<" "<<"remark:"<<row[6]<<endl;
    }
}



//隐藏密码
char Getch()    
{  
    int c = 0;    
    int res = 0;      
    struct termios org_opts, new_opts;   
    res = tcgetattr(STDIN_FILENO, &org_opts); 	//用于获取与终端相关的参数  
	if(res == -1)
	{
		printf("tcgetattr error! Error code: %d，Error message: %s\n", errno, strerror(errno)); 
		c = '\n';
		return c;
	}
    
    memcpy(&new_opts, &org_opts, sizeof(new_opts));  
    new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL); 
	
    res = tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);   //用于设置终端参数
	if(res == -1)
	{
		printf("tcsetattr error! Error code: %d，Error message: %s\n", errno, strerror(errno)); 
		c = '\n';
		return c;
	}
    c = getchar();      
    res = tcsetattr(STDIN_FILENO, TCSANOW, &org_opts); 
	if(res == -1)
	{
		printf("tcsetattr error! Error code: %d，Error message: %s\n", errno, strerror(errno)); 
		c = '\n';
		return c;
	}
	
    return c;  
}  


char *GetPasswd()
{
	char *strRet = (char *)malloc(64);
    memset(strRet, 0, 64);
	
    unsigned char c;
    int i = 0;
    
    while ((c = Getch()) != '\n')
    {
        if (i<64 && isprint(c))
        {
            strRet[i++] = c;
            putchar('*');
        }
        else if ((i>0) && (c == '\b'))
        {
            --i;
            putchar('\b');
            putchar(' ');
            putchar('\b');
        }
    }
    strRet[i] = '\0';
    
    return strRet;
}



int main()
{
    MysqlDBAccess mysql;
    mysql.mysqldbinit(mysql);
    char name[20];
    int num=0;
    system("clear");
	cout<<"*****************欢迎来到公司管理系统*****************"<<endl;
    cout<<"请输入姓名:";
    cin>>name;
    cout<<"请输入密码:";
    char *passwd = (char *)malloc(64);
    Getch();
    passwd = GetPasswd();
    
    num=mysql.login(name,passwd);


    if(num==1)//root
    {
        root root;
		
		cout<<"\n登录成功！3秒后即将进入公司管理系统..."<<endl;
		cout<<"3s"<<endl;
		sleep(1);
		cout<<"2s"<<endl;
		sleep(1);
		cout<<"1s"<<endl;
		sleep(1);
		system("clear");
    
        while(1)
        {
            cout<<"\n**********欢迎管理员**********"<<endl;
            cout<<"1.查看经理信息"<<endl;
            cout<<"2.修改经理信息"<<endl;
            cout<<"3.删除经理信息"<<endl;
            cout<<"4.增加经理信息"<<endl;
            cout<<"5.查看销售经理信息"<<endl;
            cout<<"6.修改销售经理信息"<<endl;
            cout<<"7.删除销售经理信息"<<endl;
            cout<<"8.增加销售经理信息"<<endl;
            cout<<"0.退出"<<endl;
            cout<<"请输入你的选择:";
            int key;
            cin>>key;
            system("clear");
            switch(key)
            {
                case 1:
                    root.printManager(mysql);
                    break;
                case 2:
                    root.changeManager(mysql);
                    break;
                case 3:
                    root.deleteManager(mysql);
                    break;
                case 4:
                    root.addManager(mysql);
                    break;
                case 5:
                    root.printSalesManager(mysql);
                    break;
                case 6:
                	position=8;
                    root.changeSalesManager(mysql);
                    break;
                case 7:
                    root.deleteSalesManager(mysql);
                    break;
                case 8:
                    root.addSalesManager(mysql);
                    break;
                case 0:
                    exit(0);

                default:
                cout<<"输入有误，请重试"<<endl;
            }
        }
    }
    
    if(num==2)//经理
    {
        manager manager;

		cout<<"\n登录成功！3秒后即将进入公司管理系统..."<<endl;
		cout<<"3s"<<endl;
		sleep(1);
		cout<<"2s"<<endl;
		sleep(1);
		cout<<"1s"<<endl;
		sleep(1);
		system("clear");
    
        while(1)
        {
            cout<<"\n**********欢迎经理**********"<<endl;
            cout<<"1.查看技术员信息"<<endl;
            cout<<"2.修改技术员信息"<<endl;
            cout<<"3.删除技术员信息"<<endl;
            cout<<"4.增加技术员信息"<<endl;      
            cout<<"0.退出"<<endl;
            cout<<"请输入你的选择:";
            int key;
            cin>>key;
            system("clear");
            switch(key)
            {
                case 1:
                    manager.printTechnicians(mysql);
                    break;
                case 2:
                    manager.changeTechnicians(mysql);
                    break;
                case 3:
                    manager.deleteTechnicians(mysql);
                    break;
                case 4:
                    manager.addTechnicians(mysql);
                    break;
                case 0:
                    exit(0);
                default:
                cout<<"输入有误，请重试"<<endl;
            }
        }
    }
    if(num==3)//销售经理
    {

        salesManager salesManager;

		cout<<"\n登录成功！3秒后即将进入公司管理系统..."<<endl;
		cout<<"3s"<<endl;
		sleep(1);
		cout<<"2s"<<endl;
		sleep(1);
		cout<<"1s"<<endl;
		sleep(1);
		system("clear");
    
        while(1)
        {
            cout<<"\n**********欢迎销售经理**********"<<endl;
            cout<<"1.查看销售员信息"<<endl;
            cout<<"2.修改销售员信息"<<endl;
            cout<<"3.删除销售员信息"<<endl;
            cout<<"4.增加销售员信息"<<endl;      
            cout<<"0.退出"<<endl;
            cout<<"请输入你的选择:";
            int key;
            cin>>key;
            system("clear");
            switch(key)
            {
                case 1:
                    salesManager.printSaler(mysql);
                    break;
                case 2:
                    salesManager.changeSaler(mysql);
                    break;
                case 3:
                    salesManager.deleteSaler(mysql);
                    break;
                case 4:
                    salesManager.addSaler(mysql);
                    break;
                case 0:
                    exit(0);
                default:
                cout<<"输入有误，请重试"<<endl;
            }
        }
    }
    if(num==4)//说明技术员
    {
     	cout<<"\n登录成功！3秒后即将进入公司管理系统..."<<endl;
		cout<<"3s"<<endl;
		sleep(1);
		cout<<"2s"<<endl;
		sleep(1);
		cout<<"1s"<<endl;
		sleep(1);
		system("clear");
       
        while(1)
        {    
            cout<<"\n**********欢迎技术员**********"<<endl;
            cout<<"1.查看自己的信息"<<endl;
            cout<<"0.退出"<<endl;
            cout<<"请输入你的选择:";
			int key;
			cin>>key;
			system("clear");
            switch(key)
            {
                case 1:
                    mysql.printMeTechnicians(name);
                    break;
                case 0:
                    exit(1);
                default:
                    cout<<"输入有误，请重试"<<endl;
            }
        }
    }
    if(num==5)//说明兼职销售员
    {
        cout<<"\n登录成功！3秒后即将进入公司管理系统..."<<endl;
		cout<<"3s"<<endl;
		sleep(1);
		cout<<"2s"<<endl;
		sleep(1);
		cout<<"1s"<<endl;
		sleep(1);
		system("clear");
    
        while(1)
        {
            cout<<"**********欢迎销售员**********"<<endl;
            cout<<"1.查看自己的信息"<<endl;
            cout<<"0.退出"<<endl;
            cout<<"请输入你的选择:";
 			int key;
 			cin>>key;
 			system("clear");
            switch(key)
            {
                case 1:
                    mysql.printMeSaler(name);
                    break;
                case 0:
                    exit(0);
                default:
                    cout<<"输入有误，请重试"<<endl;
                    break;
            }
        }
    }
    return 0;
}

