# usage: type "make" to compile your program
# 	   type "make clean" to compile your program and remove all .o files
# 	   keep a list of all .cpp files in the SOURCES section
# 	   keep a list of all directories in the ADDLIBS section


CC=g++
CFLAGS=-c -Wall
LDFLAGS= 
SOURCES=\
	FileIO/FileIO.cpp\
	Primary/Primary.cpp\
	Utility/Utility.cpp\
	main.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main
ADDLIBS=\
	-I/home/mark/Desktop/Resolution/FileIO\
	-I/home/mark/Desktop/Resolution/Utility\
	-I/home/mark/Desktop/Resolution/Primary\
	-I/home/mark/Desktop/Resolution/Secondary


all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS)  $(OBJECTS) -o $@ 

.cpp.o:
	$(CC)  $(ADDLIBS) $(CFLAGS) $< -o $@  

clean: $(SOURCES) $(EXECUTABLE)
	rm -f $(OBJECTS) 


	

