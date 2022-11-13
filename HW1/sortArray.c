#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int size,x,i,j,temp;
        FILE *fp = fopen(argv[1],"r");

        if(fp == NULL)
        {
                printf("Error\n");
                        return 0;
        }

        // size = fgetc(fp);
        fscanf(fp, "%d\t\n", &x);
        size = x;

        int a[size];

        for(int i=0; i<size; i++)
        {
                fscanf(fp, "%d\t\n", &x);
                a[i]=x;
        }

        //printf("Size is %d\n",size);

        //printf("Elements are:\n");
        for(int i=0; i<size; i++)
        {
        //        printf("%d\n",a[i]);
        }

        for (i = 0; i < size; ++i) {
                for (j = i + 1; j < size; ++j) {
                        if (a[i] > a[j]) {
                                temp =  a[i];
                                a[i] = a[j];
                                a[j] = temp;
                        }
                }
        }
	//printf("Elements in ascending order are:\n");
        for(int i=0; i<size; i++)
        {
        //        printf("%d\n",a[i]);
        }

        int even[size];
        int odd[size];

	int count1=0;
	int count2=0;

        for(int i=0; i<size; i++)
        {
		if( (a[i]%2) == 0 )
                {
                        even[count1] = a[i];
			count1++;
                }
                else if( (a[i]%2) !=0 )
                {
                        odd[count2] = a[i];
			count2++;
		}
		else
		{
			break;
		}
	}

        //EVEN
	
	//printf("Number of Evens are: %d\n",count1);
	//printf("Number of Odds are: %d\n",count2);
	

	//printf("The even elements are:\n");
        for(int i=0; i<count1; i++)
        {
        //        printf("%d\n",even[i]);
        }

        //ODD

        //printf("The odd elements are:\n");
        for(int i=0; i<count2; i++)
        {
        //        printf("%d\n",odd[i]);
        }
	
	//printf("Even numbers in ascending order are:\n");
	for(int i=0; i<count1; i++)
        {
                printf("%d\t",even[i]);
        }

	//printf("Odd numbers in descending order are:\n");
	for(int i=(count2-1); i>=0; i--)
        {
                printf("%d\t",odd[i]);
        }

	fclose(fp);
}
