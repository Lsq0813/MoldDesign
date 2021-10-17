INCLUDE=-I libs/jwwlib/src

MoldDesign: jwwlib.o 
	g++ -o MoldDesign *.o *.cpp ${INCLUDE}

jwwlib.o:
	g++ -c libs/jwwlib/src/*.cpp

clean:
	rm *.o
