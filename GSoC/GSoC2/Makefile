# usage: type "make" to compile your program
# 	   type "make clean" to compile your program and remove all .o files
# 	   keep a list of all .cpp files in the SOURCES section
# 	   keep a list of all directories in the ADDLIBS section


CC=g++
CFLAGS=-c -Wall
LDFLAGS= -Wall -D__DEBUG -O2 -mtune=cortex-a8 -march=armv7-a -lprussdrv -lpthread

ASSEMBLIES=\
	PRU/blink.p
SOURCES=\
	Primary/Primary.cpp\
	Utility/Utility.cpp\
	main.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main
PASM= PRU/PRUUtility/utils/pasm

LINKERLIB=\
	-L/home/ubuntu/GSoC2/PRU/PRUUtility/app_loader/lib

ADDLIBS=\
	-I/home/ubuntu/GSoC2/PRU/PRUUtility/app_loader/include\
	-I/home/ubuntu/GSoC2/Utility\
	-I/home/ubuntu/GSoC2/Primary\
	-I/home/ubuntu/GSoC2/Secondary\



all: $(ASSEMBLIES) $(SOURCES) $(EXECUTABLE) 

$(EXECUTABLE): $(OBJECTS) 

	$(CC)  $(ADDLIBS) $(OBJECTS) -o $@  $(LINKERLIB) $(LDFLAGS) 

	$(PASM) -b $(ASSEMBLIES)

blink.bin: blink.p

.cpp.o:
	$(CC)  $(ADDLIBS) $(CFLAGS)  $< -o $@  



clean: $(SOURCES) $(EXECUTABLE)
	rm -f $(OBJECTS) 


	

