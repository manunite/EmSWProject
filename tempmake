tempMain : DB.o gtk_Main.o voca.o
	g++ -o tempMain tempMain.cpp gtk_Main.o voca.o DB.o -I/usr/include/cppconn `pkg-config --cflags --libs gtk+-2.0` -L/usr/lib -lmysqlcppconn

DB.o : DB.cpp
	g++ -c DB.cpp -I/usr/include/cppconn
	
gtk_Main.o : gtk_Main.cpp
	g++ -c gtk_Main.cpp `pkg-config --cflags --libs gtk+-2.0`

voca.o : voca.cpp
	g++ -c voca.cpp
