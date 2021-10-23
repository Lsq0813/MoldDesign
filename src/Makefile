INCLUDE=-I libs/
LDFALG=-lGL -lglut -lGLU

MoldDesign:main.o jwwlib.o
	g++ -o MoldDesign *.o ${LDFALG}

main.o: 
	g++ -c *.cpp ${INCLUDE}

jwwlib.o:
	g++ -c libs/jwwlib/*.cpp

clean:
	rm *.o -f
