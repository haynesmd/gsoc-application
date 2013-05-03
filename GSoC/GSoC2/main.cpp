#include <stdio.h>

#include <prussdrv.h>
#include <pruss_intc_mapping.h>

#define PRU_NUM 	0
#define AM33XX

#include <stdlib.h>
#include <stdio.h>

#include <Utility.h>
#include <Primary.h>

using namespace std;

// #define PRUSS0_PRU0_DATARAM 0 
// #define PRUSS0_PRU1_DATARAM 1 
// #define PRUSS0_PRU0_IRAM 2 
// #define PRUSS0_PRU1_IRAM 3 

int main (void)
{

    printf("\nMy name is Mark Haynes\n");
    printf("Kansas State University\n");
    printf("Manhattan, KS\n");
    printf("5/2/2013\n\n");
    // printf("Program Start\n");
    // Utility::Test();

    // Primary PrimaryInstance;
    // PrimaryInstance.Initiate();
    // PrimaryInstance.Execute();

    unsigned int ret;
    tpruss_intc_initdata pruss_intc_initdata = PRUSS_INTC_INITDATA;
    
    printf("\nINFO: Starting %s example.\r\n", "blink");
    /* Initialize the PRU */

    prussdrv_init ();		

    /* Open PRU Interrupt */
    ret = prussdrv_open(PRU_EVTOUT_0);
    if (ret)
    {
        printf("prussdrv_open open failed\n");
        return (ret);
    }
    // prussdrv_pru_reset ( PRU_NUM );    
    
    // /* Get the interrupt initialized */
    prussdrv_pruintc_init(&pruss_intc_initdata);

    unsigned int data[4];
    data[0] = 0x10000009;
    data[1] = 0x20000006;
    data[2] = 0x00000000;
    data[3] = 0x00000000;
    unsigned int bytes = 32;
    prussdrv_pru_write_memory(PRUSS0_PRU0_DATARAM,0,data,bytes);
    
    // void *pruDataMem;
    // prussdrv_map_prumem(PRUSS0_PRU0_DATARAM, &pruDataMem);
    // printf("\nWhat I read: %x\n\n",  *((int*)pruDataMem));
    // pruDataMem = (void*)((int*)pruDataMem + 1);
    // printf("\nWhat I read: %x\n\n",  *((int*)pruDataMem));//+ sizeof(int*)

    /* Execute example on PRU */
    printf("\tINFO: Executing example.\r\n");

    char Filename[] = "./blink.bin";
    prussdrv_exec_program (PRU_NUM, Filename);
    
    /* Wait until PRU0 has finished execution */
    printf("\tINFO: Waiting for HALT command.\r\n");
    prussdrv_pru_wait_event (PRU_EVTOUT_0);
    printf("\tINFO: PRU completed transfer.\r\n");
    prussdrv_pru_clear_event (PRU0_ARM_INTERRUPT);

    /* Disable PRU and close memory mapping*/
    prussdrv_pru_disable (PRU_NUM);
    prussdrv_exit ();

    return(0);
}

