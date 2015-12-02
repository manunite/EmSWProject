appPath = ../app
TARGET = libDB.a libQuiz.a

all : $(TARGET)

libDB.a : DB.o DB_result.o
	ar rv libDB.a DB.o DB_result.o
	
libQuiz.a : gtk_Main.o voca.o endPage.o
	ar rv libQuiz.a gtk_Main.o voca.o endPage.o

endPage.o : $(appPath)/endPage.cpp
	g++ -c $(appPath)/endPage.cpp `pkg-config --cflags --libs gtk+-2.0`

gtk_Main.o : $(appPath)/gtk_Main.cpp
	g++ -c $(appPath)/gtk_Main.cpp `pkg-config --cflags --libs gtk+-2.0`

voca.o : $(appPath)/voca.cpp
	g++ -c $(appPath)/voca.cpp

DB.o : $(appPath)/DB.cpp
	g++ -c $(appPath)/DB.cpp -I/usr/include/cppconn
	
DB_result.o : $(appPath)/DB_result.cpp
	g++ -c $(appPath)/DB_result.cpp -I/usr/include/cppconn

clean :
	rm -rf *.o *.a
