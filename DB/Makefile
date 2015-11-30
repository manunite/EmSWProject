libDB.a : DB.o
	ar rv libDB.a DB.o

DB.o : DB.cpp
	g++ -c DB.cpp -I/usr/include/cppconn

clean :
	rm -rf *.o *.a
