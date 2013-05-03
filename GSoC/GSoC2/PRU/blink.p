.origin 0
.entrypoint START

#define PRU0_ARM_INTERRUPT          19
#define AM33XX

#define GPIO0                       0x44E07000
#define GPIO1                       0x4804c000
#define GPIO_OE                     0x134
#define GPIO_CLEARDATAOUT           0x190
#define GPIO_SETDATAOUT             0x194

#define NUMBEROFBLINKS              50     //this will toggle pins ON/OFF a million times or 50 whatever
#define DELAYONTIME                 0x00f00000 //0x000000f0  //This is really fast, to fast to see with your eye you will need an oscilloscope
#define DELAYOFFTIME                0x00f00000 //0x000000f0


START:
    //These first 3 lines clear the sysconfig standby init bit
    LBCO r0, c4, 4, 4       //Load Byte Constant Offset 
    CLR r0, r0, 4           //clears r0 and copies to destination r0
    SBCO r0.b0, c4, 4, 4    //Story byte constant table offset


    MOV r2, 0x00000000 
    MOV r3, GPIO1           //loads r3 with the address for GPIO1
    MOV r4, GPIO_OE
    MOV r5, GPIO_SETDATAOUT
    MOV r6, GPIO_CLEARDATAOUT
    SBBO r2, r3, r4, 4      //This sets all of the GPIO1 pins as outputs


    MOV r1, NUMBEROFBLINKS  //This is the number of ON and OFF cycles to occure
BLINK:
    MOV r2, 0xFFFFFFFF      //These are the pins that will be turned on and off.  This will turn all pins of GPIO1 ON and OFF      

    SBBO r2, r3, r5, 4      // stores the 4 bytes from r2 in the address of r3+r5
    MOV r0, DELAYONTIME      //0x00f00000 // store this value in r0
DELAY:
    SUB r0, r0, 1            // r0 = r0 - 1
    QBNE DELAY, r0, 0        //jump to delay if r0 does not equal zero (this creates a delay loop)
                             //delay ON ends
    SBBO r2, r3, r6, 4       //stores the 4 bytes from r2 in the address that is in r3 with no offset

    MOV r0, DELAYOFFTIME     //0x00f00000 //reset r0 for another delay
DELAY2:
    SUB r0, r0, 1
    QBNE DELAY2, r0, 0       //keeps subtracting 1 from r0 until it is zero
                             //delay OFF ends
    SUB r1, r1, 1            //r1 = r1 -1;
    QBNE BLINK, r1, 0        //rebegin the blink operation if r1 is not zero

    MOV R31.b0, PRU0_ARM_INTERRUPT+16  //tell the c program we are done (just remove it if your c program does not handle the interrupt)

HALT
