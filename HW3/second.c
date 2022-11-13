#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	unsigned short x;
	int numOfOne =0,pairs=0,temp=0,temp1=0;
	sscanf(argv[1],"%hi",&x);
	//printf("Num = %d\n",x);
	
	int prev = x;
	int curr = x >> 1;


	while(curr)
        {
                if(((prev & 1) == 1) && ((curr & 1 == 1))) 
		{
			pairs = pairs + 1;
                	prev = curr >> 1;
			curr = prev >> 1;
		}
		else
		{
                	prev = prev >> 1;
			curr = curr >> 1;
        	}
	}
	
	while(x != 0)
	{
		if((x & 1) == 1)
		{
			numOfOne = numOfOne + 1;
		}
		x = x >> 1;
	}

	//printf("Number of pairs = %d\n",pairs);
 	//printf("Number of 1s = %d\n",numOfOne);
	
	if(numOfOne % 2 == 0)
	{
		printf("Even-Parity\t%d\n",pairs);
	}
	else
	{
		printf("Odd-Parity\t%d\n",pairs);
	}

	return 0;
}

