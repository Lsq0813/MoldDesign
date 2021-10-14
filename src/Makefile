jwwlib=libs/jwwlib/src/*.cpp
parser=parser/*.cpp
design=design/*.cpp

INCLUDE=-I libs/jwwlib/src -I parser

MoldDesign: jwwlib.o parser.o design.o
	g++ -o MoldDesign *.o

jwwlib.o:
	g++ -c ${jwwlib}

parser.o:
	g++ -c ${parser} ${INCLUDE}

design.o:
	g++ -c ${design} ${INCLUDE} 

clean:
	rm *.o
