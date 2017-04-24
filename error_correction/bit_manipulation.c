
/*

File bit_manipulation.c

Purpose :
contains helper functions for manipulating bits


Revisions:
file created: Doron Nussbaum

* /

/************************************************************************/

// INCLUDE FILES

#include "bit_manipulation.h"


/************************************************************************/
//MACROS  / DEFINES



/************************************************************************/
// FUNCTION PROTOTYPES
long int_to_bin(short k);
short bin_to_int(long k);


/***************************************************/

//example of a testing function main();
#if 0

int main(int argc, char *argv[])

{
	int rc = 0;		// return code


	short test = 0;
	short modified;
	int bitNum;		// bit number to be used
	
	
	test = 0;
	bitNum = 2;
	modified = test;
	flipBitShort(bitNum, &modified);
	printf("test_int=%d, flipping bit #=%d, answer should be=%d, test_modified=%d\n", test, bitNum, 4, modified);

	rc = isShortBitSet(modified, 3);
	printf("Bit 3 in %d should not be set.  Answer is %d \n", modified, rc);

	rc = isShortBitSet(modified, 2);
	printf("Bit 2 in %d should  be set.  Answer is %d \n", modified, rc);

   getchar();
   
	return(0);
}


#endif

long int_to_bin(short k) {
    if (k == 0) return 0;
    if (k == 1) return 1;
    return (k % 2) + 10 * int_to_bin(k / 2);
}

short bin_to_int(long k) {
    long m = 1;
    short result = 0;
    while (k != 0) {
        result += (k % 10) * m;
        k = k / 10;
        m *= 2;
    }
    return(result);
}

/*************************************************************************************/
/* purpose: checks if bit i is set

input:
c - the character to be checked
bitNum - the bit number to be checked

return:
1 if the bit is set to 1
0 if the bit is not set (bit is 0)

*/

int isCharBitSet(char c, int bitNum)

{
    long output = int_to_bin(c);
    int i = 7;
    while (i >= 0)
    {
        if (bitNum == 0)
        {
            if ((output % 10) == 1) {
                return(1);
            } else {
                 return(0);
            }
        }
        output = output / 10;
        bitNum--;
    }
}




/*************************************************************************************/

/* purpose: checks if bit i is set

input: 
num - the number to be checked
bitNum - the bit number to be checked 

return:
1 if the bit is set to 1
0 if the bit is not set (bit is 0)

*/
int isShortBitSet(short num, int bitNum)

{
    long n = int_to_bin(num);
    while (bitNum >= 0) {
        if (bitNum == 0) {
            return (n % 10);
        }
        n = n / 10;
        bitNum--;
    }
}

/*************************************************************************************/
/* purpose: sets bit bitNum to 1 

input:
num - the address of the short integer
bitNum - the bit number to be checked



*/

void setShortBit(int bitNum, short *num)

{
    long n = int_to_bin(*num);
    long m = 1;
    long result = 0;
    int actual_bit;
    while ((n != 0) || (bitNum >= 0)) {
        actual_bit = n % 10;
        if (bitNum == 0) {
            actual_bit = 1;
        }
        result += actual_bit * m;
        n = n / 10;
        m *= 10;
        bitNum--;
    }
    (*num) = bin_to_int(result);
}

/*************************************************************************************/


/* purpose: sets bit bitNum to 1

input:
c - address of character 
bitNum - the bit number to be checked

return:
1 if the bit is set to 1
0 if the bit is not set (bit is 0)

*/
void setCharBit(int bitNum, char *c)

{
    short num = (short) (*c);
    setShortBit(bitNum, &num);
    *c = (char) num;
}

/*************************************************************************************/


/*  count the number of bits in a short

input: 
num - a short interger

return
the numer of bits that are set to 1 in num



*/
int countBits(short num)

{
    int aux = 0;
    long n = int_to_bin(num);
    while (n != 0) {
        aux += n % 10;
        n = n / 10;
    }
    return aux;
}






/*************************************************************************************/

/* purpose:
flips bit i in num (set bit i to 1 if the bit is 0 or set bit i to 0 if the bit is 1)

input:
bitNum - the bit number to be flipped
num - address of the short integer

*/
void flipBitShort(int bitNum, short *num)

{
    long n = int_to_bin(*num);
    long m = 1;
    long result = 0;
    int actual_bit;
    while ((n != 0) || (bitNum >= 0)) {
        actual_bit = n % 10;
        if (bitNum == 0) {
            actual_bit = actual_bit ? 0 : 1;
        }
        result += actual_bit * m;
        n = n / 10;
        m *= 10;
        bitNum--;
    }
    (*num) = bin_to_int(result);
}