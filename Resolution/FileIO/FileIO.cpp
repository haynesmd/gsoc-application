#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>

#include "FileIO.h"
using namespace std;

bool FileIO_Verbose = false;
FileIO::FileIO()
{
    // Initialize
}

void  FileIO::Initiate( void)
{
	printf("FileIO Initiated\n");
}

void FileIO::Verbose(void)
{

	FileIO_Verbose = true;
}
void FindArraySizeNeeded(string FileName, int ij[2])
{
	ifstream file("file.csv");
	int i = 0, j =0, maxj = 0;
	string value;
	while (file.good())
	{
		getline (file, value, ',');
		int n = value.find("\n");
		if ( n >= 0 )
		{
			i++;
			if (j > maxj)
			maxj = j;	
			j = 0;	
		}
		else
		{	

			j++;
			// cout << "*";
		}
	}	
	ij[0] = i + 1;
	ij[1] = maxj + 1;
	if (FileIO_Verbose)
		printf ("The array size is: [%d,%d]\n", ij[0], ij[1]);
}

void readfile ( string FileName, vector < vector < int > > &data )
{

	int ij[2];
	int i = 0, j = 0;
	FindArraySizeNeeded( FileName, ij);
	ifstream file( FileName.c_str() );
	ifstream fileline( FileName.c_str() );
	string value;
	// vector < vector < int > > data ( ij[0], vector < int > ( ij[1])  ) ;
	data.resize(ij[0]);
	for (i = 0; i < ij[0]; i++)
		data[i].resize( ij[1] );
	i = 0;
	while (file.good())
	{
		getline (file, value);
		// cout << value; 

		stringstream ss( value );
		vector<string> result;

		while( ss.good() )
		   {
		   string substr;
		   getline( ss, substr, ',' );
		   if (!substr.empty())
		   {
		   		result.push_back( substr );
		   		data[i][j] = atoi(substr.c_str());
		   }
		   // printf("ij = %d,%d",i,j);
		   j++;
		   }
		   j = 0;
		   i++;		
	}
	if (FileIO_Verbose)
	{	
		printf("The array is: \n");
		for ( i = 0; i < ij[0]; i++)
		{
			for ( j = 0; j < ij[1]; j++)
				printf("%d,", data[i][j]);
			printf("\n");
		}
		printf("--FileIO Executed\n");
	}
}

void readfile ( string FileName, vector < vector < float > > &data )
{

	int ij[2];
	int i = 0, j = 0;
	FindArraySizeNeeded( FileName, ij);
	ifstream file( FileName.c_str() );
	ifstream fileline( FileName.c_str() );
	string value;
	// vector < vector < int > > data ( ij[0], vector < int > ( ij[1])  ) ;
	data.resize(ij[0]);
	for (i = 0; i < ij[0]; i++)
		data[i].resize( ij[1] );
	i = 0;
	while (file.good())
	{
		getline (file, value);
		// cout << value; 

		stringstream ss( value );
		vector<string> result;

		while( ss.good() )
		   {
		   string substr;
		   getline( ss, substr, ',' );
		   if (!substr.empty())
		   {
		   		result.push_back( substr );
		   		data[i][j] = atof(substr.c_str());
		   }
		   // printf("ij = %d,%d",i,j);
		   j++;
		   }
		   j = 0;
		   i++;		
	}
	if (FileIO_Verbose)
	{	
		printf("The array is: \n");
		for ( i = 0; i < ij[0]; i++)
		{
			for ( j = 0; j < ij[1]; j++)
				printf("%5.2f,", data[i][j]);
			printf("\n");
		}
		printf("--FileIO Executed\n");
	}
}

void readfile ( string FileName, vector < vector < double > > &data )
{

	int ij[2];
	int i = 0, j = 0;
	FindArraySizeNeeded( FileName, ij);
	ifstream file( FileName.c_str() );
	ifstream fileline( FileName.c_str() );
	string value;
	// vector < vector < int > > data ( ij[0], vector < int > ( ij[1])  ) ;
	data.resize(ij[0]);
	for (i = 0; i < ij[0]; i++)
		data[i].resize( ij[1] );
	i = 0;
	while (file.good())
	{
		getline (file, value);
		// cout << value; 

		stringstream ss( value );
		vector<string> result;

		while( ss.good() )
		{
		   string substr;

		   getline( ss, substr, ',' );
		   if (!substr.empty())
		   {
		   		result.push_back( substr );
		   		data[i][j] = atof(substr.c_str());
		   }
		   // printf("ij = %d,%d",i,j);
		   j++;
		}
		   j = 0;
		   i++;		
	}
	if (FileIO_Verbose)
	{	
		printf("The array is: \n");
		for ( i = 0; i < ij[0]; i++)
		{
			for ( j = 0; j < ij[1]; j++)
				printf("%5.2lf,", data[i][j]);
			printf("\n");
		}
		printf("--FileIO Executed\n");
	}
}

void  FileIO::Execute ( string FileName, vector < vector < int > > &data)
{
	if (FileIO_Verbose)
		printf("--FileIO Executing...\n");
	readfile( FileName , data);
}
void  FileIO::Execute ( string FileName, vector < vector < float > > &data)
{
	if (FileIO_Verbose)
		printf("--FileIO Executing...\n");
	readfile( FileName , data);
}
void  FileIO::Execute ( string FileName, vector < vector < double > > &data)
{
	if (FileIO_Verbose)
		printf("--FileIO Executing...\n");
	readfile( FileName , data);
}
