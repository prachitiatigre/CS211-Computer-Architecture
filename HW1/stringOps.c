#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	char s;
	int i;

	for(i=1; i<argc; ++i)
	{
		int j=0;
		while((s=argv[i][j]))
		{
			if(s == 'A' || s == 'E' || s == 'I' || s  == 'O' || s  == 'U' || 
				s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')		
			printf("%c",s);
			
			else
			{
				//do nothing
			}		
			j++;
		}
	}	
}
