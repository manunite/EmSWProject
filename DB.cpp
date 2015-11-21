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

using namespace sql;
using namespace std;
int flag = 0;

template <class T>
const string& operator+=(string &str, const T &_ty)
{
	ostringstream os;
	os << _ty;
	str += os.str();
	return str;
}

int DBcon(int Id,int QuizNum,int Correct,int Wrong)
{
	int totalQuiz=0;
	int CorrectNum = 0;
	int WrongNum=0;
	
try{
	sql::Driver *driver;
	sql::Connection *con;
	Statement * stmt;
	ResultSet * rs;
	
	printf("\nI am DBConnect Function\n");
	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306/userInfo","root","1111"); //DB 커넥터 생성
	cout << "SUCCESS Connection" << endl;
	cout << "SUCCESS_Heart" << endl;
	string StrQuery = "select totalQuiz,Correct,Wrong from userTable where UserId = ";
           StrQuery += Id;
	       StrQuery += "";
	//cout << StrQuery << endl;
	stmt = con->createStatement();
	rs = stmt->executeQuery(StrQuery);
	
	rs->next();
	totalQuiz = rs->getInt("totalQuiz");
	cout << "totalQuiz : " << totalQuiz << endl;
	rs->next();
	CorrectNum = rs->getInt("Correct");
	cout << "Correct : " << CorrectNum << endl;
	rs->next();
	WrongNum = rs->getInt("Wrong");
	cout << "WrongNum : " << WrongNum << endl;
	
	////////////////////////////////////////////////////////////////////////////////////////////
	
	totalQuiz += QuizNum;
	CorrectNum += Correct;
	WrongNum += Wrong;
	
	StrQuery = "update userInfo set totalQuiz = ";
	StrQuery += totalQuiz;
	StrQuery += ",Correct = ";
	StrQuery += CorrectNum;
	StrQuery += ",Wrong = ";
	StrQuery += WrongNum;
	StrQuery += " where UserId = ";
	StrQuery += Id;
	StrQuery += "";
	
	stmt->executeUpdate(StrQuery);
	
	cout << StrQuery << endl;
	
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
	
	return 0;
}
