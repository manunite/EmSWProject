#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <mysql_connection.h>
#include <driver.h>
#include <exception.h>
#include <resultset.h>
#include <statement.h>
#include <sstream>
#include "../inc/DB.h"
#include "../inc/Quiz.h"

using namespace sql;
using namespace std;
int Id_R;

struct node{
	int value_1;
	int value_2;
	int value_3;
};

struct node Values;


template <class T>
const string& operator+=(string &str, const T &_ty)
{
	ostringstream os;
	os << _ty;
	str += os.str();
	return str;
}
struct node DBcon_R(char *user)
{
	int rate=0;
	int totalQuiz=0;
	int CorrectNum = 0;
	int WrongNum=0;
	int levels=0;
	
try{
	sql::Driver *driver;
	sql::Connection *con;
	Statement * stmt;
	ResultSet * rs;
	
	printf("\nI am DBConnect Function\n");
	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306/EmbeProject","root","1111"); //DB 커넥터 생성
	
	string StrQuery = "select UserId from userInfo where UserName = '";
		   StrQuery += user;
		   StrQuery += "'";
	stmt = con->createStatement();
	rs = stmt->executeQuery(StrQuery);
	rs->next();
	Id_R = rs->getInt("UserId");
	
	
	StrQuery = "select totalQuiz,Correct,Wrong,level from userInfo where UserId = ";
	StrQuery += Id_R;
	StrQuery += "";
	       
	       
	cout << StrQuery << endl;
	stmt = con->createStatement();
	rs = stmt->executeQuery(StrQuery);
	
	rs->next();
	totalQuiz = rs->getInt("totalQuiz");
	cout << "totalQuiz : " << totalQuiz << endl;
	//rs->next();
	CorrectNum = rs->getInt("Correct");
	cout << "Correct : " << CorrectNum << endl;
	//rs->next();
	WrongNum = rs->getInt("Wrong");
	cout << "WrongNum : " << WrongNum << endl;
	levels = rs->getInt("level");
	cout << "level : " << levels << endl;
	
	////////////////////////////////////////////////////////////////////////////////////////////
	Values.value_1 = CorrectNum;
	Values.value_2 = WrongNum;
	Values.value_3 = levels;
	
	cout << "@@@@" << endl;
	//printf("$$%d %d$$\n",head->value,head->next->value);
	
	
	con->close();
	delete rs;
	delete stmt;
	delete con;
	
	} catch (sql::SQLException &e) {
	  	cout << "# ERR: SQLException in " << __FILE__;
	  	cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
	  	cout << "# ERR: " << e.what();
	  	cout << " (MySQL error code: " << e.getErrorCode();
	  	cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}
	
	return Values;
}
