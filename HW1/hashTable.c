#include<stdio.h>
#include<stdlib.h>
#define SIZE 10000

typedef struct linkedList
{
	int data;
	struct linkedList *next;
}List;

List* bucket[SIZE];

List* newNode(int value)
{
	List *node = (List*)calloc(1,sizeof(List));
	node->data = value;
	node->next = NULL;
	return node;
}
int search(int num)
{
	//printf("here");
        int hashNum = num % SIZE;
        if(hashNum < 0)
        {
                hashNum += SIZE;
        }

	//printf("here");
        List *curr = bucket[hashNum];
        int yay=0;

        while(curr!=NULL)
        {
                if(curr-> data == num)
                {
                        //printf("here");
			yay = 1;
                }
                curr = curr->next;
        }
        return yay;
}

int insert(int num)
{
	//printf("here");
	int hashNum = num % SIZE;
	if(hashNum < 0)
	{
		hashNum += SIZE;
	}
	
	int collisions;
	int same = 0;
	
	if(bucket[hashNum]==NULL)
	{
		//printf("here0");
		bucket[hashNum] = newNode(num);
		collisions = 0;
	}
	else
	{
		//printf("here1");
		collisions = 1;
		List *prev = NULL, *curr = bucket[hashNum];
		while(curr != NULL)
		{
			//printf("here1");
			if(curr->data == num)
			{
				//printf("here1");
				same = 1;
				break;
			}
			prev = curr;
			curr = curr->next;
		}
		if(same == 0)
		{
			prev->next = newNode(num);
		}
	}
	return collisions;
}

/*
int search(int num)
{
	int hashNum = num % SIZE;
	if(hashNum < 0)
	{
		hashNum += SIZE;
	}
	
	List *curr = bucket[hashNum];
	int yay=0;
	
	while(curr!=NULL)
	{
		if(curr-> data == num)
		{
			yay = 1;
		}
		curr = curr->next;
	}
	return yay;
}
*/
int main(int argc,char *argv[])
{
	if(argc != 2)
	{
		printf("error\n");
	}
	else
	{
		FILE * pf = fopen (argv[1], "r");
		if(pf == NULL)
		{
			printf("error\n");
		}
		else
		{
			int i,num;
			char temp;
			int collisions = 0;
			int searches = 0;
			
			for(i = 0; i < SIZE; i++)
			{
				bucket[i] = NULL;
			}
			
			int x = fscanf(pf, "%c\t%d\n", &temp, &num);
			
			while(x == 2)
			{
				//printf("here");
				if(temp =='i')
				{
					//printf("inside");
					collisions += insert(num);
				}
				else if(temp =='s')
				{
					//printf("inside");
					searches += search(num);
				}
				x = fscanf(pf, "%c\t%d\n", &temp, &num);
			}
			printf("%d\n%d\n", collisions, searches);
			fclose(pf);
		}
	}
}
