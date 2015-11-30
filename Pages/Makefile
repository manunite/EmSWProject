gtk = `pkg-config --cflags --libs gtk+-2.0`
DBINCLUDE = /usr/include/cppconn
DBLIBPATH = /usr/lib
DBLIB = mysqlcppconn

startPage : libQuiz.a
	g++ -o startPage startPage.cpp -L. -lQuiz -L/home/heo/EmProject/DB -lDB -L$(DBLIBPATH) -l$(DBLIB) $(gtk)

libQuiz.a : gtk_Main.o voca.o
	ar rv libQuiz.a gtk_Main.o voca.o

gtk_Main.o : gtk_Main.cpp
	g++ -c gtk_Main.cpp `pkg-config --cflags --libs gtk+-2.0`

voca.o : voca.cpp
	g++ -c voca.cpp

clean :
	rm -rf *.o *.a
