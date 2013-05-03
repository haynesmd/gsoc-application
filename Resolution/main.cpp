#include <stdlib.h>
#include <stdio.h>

#include <Utility.h>
#include <Primary.h>
#include <FileIO.h>
#include <vector>
using namespace std;

struct worker
{
	float x;
	float v;
	int state; //1,2,3 forward back wait
	int zone;  //1-6 even are work stations
};

int main(int argc, char *argv[])
{
	vector < vector < float > > data;

	printf("Program Start\n");
	FileIO ReadF;

	ReadF.Verbose();
	ReadF.Execute("file.csv", data);	
}

	// Primary PrimaryInstance;
	// PrimaryInstance.Initiate();
	// PrimaryInstance.Execute();

