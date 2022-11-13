#include <stdio.h>
#include <stdlib.h>

/*
void bin(unsigned n) 
{ 
    // step 1 
    if (n > 1) 
        bin(n/2); 
  
    //step 2 
    printf("%d", n % 2); 
} 
*/

int main(int argc, char* argv[])
{
	unsigned short x,y,z;
        int size=0;
	int a=0,b=0;
	int ans=0;
	int count1=0,count0=0;

	sscanf(argv[1],"%hu",&x);
        //printf("Num = %d\n",x);
	
	//bin(x);
	//printf("\n");
	
	z=x;
	while(z != 0)
	{
		size = size+1;
		z = z >> 1;
	}
	//printf("Size = %d\n",size);
	
	count1=16;
	
	for(int i=0; i<16; i++)
	{
		a = (x >> i) & 1;
		//printf("a = %d\n",a);
		
		b = (x >> count1-1) & 1;
		//printf("b = %d\n",b);
		
		//printf("\n");
		
		count1--;

		if(a == b)
			ans = 1;

		else {
			ans = 0;
			break;
		}
	}
	
	if(ans == 1)
		printf("Is-Palindrome\n");

	else
		printf("Not-Palindrome\n");

	return 0;
}

