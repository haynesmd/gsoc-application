#ifndef FileIO_h
#define FileIO_h
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class FileIO
{
public:
    
	FileIO();
	void Initiate( void);
	void Verbose ( void);
	void Execute ( string FileName, vector < vector < int > > &data);
	void Execute ( string FileName, vector < vector < float > > &data);
	void Execute ( string FileName, vector < vector < double > > &data);
};



#endif
