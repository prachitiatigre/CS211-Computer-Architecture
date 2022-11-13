#include <stdio.h>

int main(int argc, char* argv[])
{
	int n,v,ans;
	int nthBit;
	char opr[10]; //opr = operation
	unsigned short x;
	FILE *fp = fopen(argv[1], "r");
	fscanf(fp,"%hi\n", &x);
	//printf("x = %u\n",x);
	
	while(1)
	{
		int count = fscanf(fp, "%s\t%d\t%d", opr, &n, &v);

		if(count != 3)
                break;

	//	printf("Operation = %s\n",opr);
	//	printf("n = %d\n",n);
	//	printf("v = %d\n",v);	
		
		if(opr[0] == 's')
		{
			if(v == 1)
			{
				//set(nthBit, n, x);
				nthBit = 1 << n;
				x = nthBit | x;
				printf("%d\n",x);
				nthBit = 0;
			}
			else
			{
				nthBit = 1 << n;
				nthBit = ~nthBit;
				x = x & nthBit;
				printf("%d\n",x);
				nthBit = 0;
			}
		}
		
		else if(opr[0] == 'c')
                {
			nthBit = 1 << n;
			x = x^nthBit;
			printf("%d\n", x);
			nthBit = 0;
                }
		
		else if(opr[0] == 'g')
                {
                        nthBit = (x >> n) & 1;
			printf("%d\n",nthBit);
                	nthBit = 0;
		}
	}

	return 0;
}
