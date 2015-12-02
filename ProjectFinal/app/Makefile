gtk = `pkg-config --cflags --libs gtk+-2.0`
DBINCLUDE = /usr/include/cppconn
DBLIBPATH = /usr/lib
DBLIB = mysqlcppconn
LIB = ../lib
INC = ../inc

startPage : $(LIB)/libQuiz.a
	g++ -o startPage startPage.cpp -L./$(LIB) -L$(DBLIBPATH) -lQuiz -lDB -l$(DBLIB) -I./$(INC) $(gtk)

clean :
	rm -rf *.o *.a
