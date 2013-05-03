#include <stdio.h>
#include <stdlib.h>

#include "Primary.h"


Primary::Primary()
{
    // Initialize
}
void  LocalFunction(void )
{
	int i = 0;
	i++;

}
void  Primary::Initiate( void)
{
	printf("Primary Initiated\n");
}
void  Primary::Execute ( void)
{
	LocalFunction();
	printf("Primary Executed\n");
}
