#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//ALL METHODS
void calculateFIFO(int numOfLines, unsigned long int set, unsigned long int tagIndex, char readWrite);
void calculateLRU(int numOfLines, unsigned long int set, unsigned long int tagIndex, char readWrite);
int checkPower(int num);
void freeCache(int);

//CACHE STRUCT
typedef struct Cache
{
	long int lruReplace;
	unsigned long int fifoReplace;
	unsigned int empty;
	unsigned long int tag;
} Cache;

//ALL GLOBAL VARIABLES
char *nWay;
int numOfHits = 0;
int numOfMisses = 0;
int numOfReads = 0;
int numOfWrites = 0;
int cacheSize = 0;
int blockSize = 0;
int numOfLines;
int numOfSets;
int replacePolicy;
int offsetSize = 0;
int setSize = 0;
char readWrite;
char counter[20];
long int insert = 0;
unsigned long int tagIndex;
unsigned long int set;
unsigned long int address;
int count;
Cache** cache;

Cache** createCache(int numOfSets, int numOfLines)
{    
    cache =(struct Cache **) malloc(sizeof(struct Cache) * numOfSets);
    
    for(int i = 0; i < numOfSets; i++)
    {
        cache[i] = (struct Cache *) malloc(sizeof(struct Cache) * numOfLines);
        
        for(int j = 0; j < numOfLines; j++)
        {
            cache[i][j].fifoReplace = 0;
	    cache[i][j].lruReplace = 0;
	    cache[i][j].empty = 0;
            cache[i][j].tag = 0;
        }
    }
    
    numOfHits = 0;
    numOfMisses = 0;
    numOfReads = 0;
    numOfWrites = 0;
    insert = 0;
    return cache;
}

void freeCache(int numOfSets)
{
    for(int i=0 ; i < numOfSets; i++)
    {
        free(cache[i]);
    }
}

int checkPower(int num)
{
        if(num == 0)
                return 0;

        while(num != 1)
        {
                if(num % 2 != 0)
                        return 0;
                num = num / 2;
        }
        return 1;
}

void calculateFIFO(int numOfLines, unsigned long int set, unsigned long int tagIndex, char readWrite)
{
	for(int i = 0; i < numOfLines; i++)
	{
		if(cache[set][i].empty == 0)
                {
			//printf("Empty\n");
			numOfMisses++;
			numOfReads++;
			
			if(readWrite == 'W')
			{
				numOfWrites++;
			}
			
			cache[set][i].empty = 1;
			cache[set][i].tag = tagIndex;
			cache[set][i].fifoReplace = insert;
			insert++;
			break;
		}
		else if(cache[set][i].tag == tagIndex && cache[set][i].empty == 1)
		{
			numOfHits++;
			
			if(readWrite == 'W')
			{
				numOfWrites++;
			}
			break;
		}
		
		else if(numOfLines == i+1 && cache[set][i].empty == 1) 
		{
			//printf("Not Empty\n")
			numOfMisses++;
			numOfReads++;
                    	
			if(readWrite == 'W')
			{   
				numOfWrites++;
			}
			
			
			int highestNum = 1000000000;
			
			for(int j = 0; j < numOfLines; j++)
			{
				//printf("%ld\n", cache[set][j].fifoReplace);
				if(cache[set][j].fifoReplace <= highestNum)
				{
					highestNum = cache[set][j].fifoReplace;
				}
			}

			for(int j = 0; j < numOfLines; j++)
			{
				if(cache[set][j].fifoReplace == highestNum)
				{
					cache[set][j].tag = tagIndex;
					cache[set][j].fifoReplace = insert;
					insert++;
					break;
				}
			}
			
			return;
		}
	}
	
}

void calculateLRU(int numOfLines, unsigned long int set, unsigned long int tagIndex, char readWrite)
{
	for(int i = 0; i < numOfLines; i++)
	{
		if(cache[set][i].empty == 0)
		{
                    //printf("Empty\n");
                    numOfMisses++;
                    numOfReads++;

                    if(readWrite == 'W')
		    {
                        numOfWrites++;
                    }
                  
		    cache[set][i].empty = 1;
		    cache[set][i].tag = tagIndex;
		    cache[set][i].lruReplace = 0;
                  
		    for(int j = 0; j < numOfLines; j++)
		    {
			    if(i != j)
			    {
				    cache[set][j].lruReplace--;
			    }
		    }
		    break;
		}

		else if(cache[set][i].tag == tagIndex && cache[set][i].empty == 1)
		{
			numOfHits++;
			
			if(readWrite == 'W')
			{
				numOfWrites++;
			}
			
			cache[set][i].lruReplace = 0;
			
			for(int j = 0; j < numOfLines; j++)
			{
				if(i != j)
				{
					cache[set][j].lruReplace--;
				}
			}
			break;
                }

                else if(numOfLines == i+1 && cache[set][i].empty == 1)
		{
			//printf("Not Empty\n");

			numOfMisses++;
			numOfReads++;
			
			if(readWrite == 'W')
			{
				numOfWrites++;
			}

			int highestNum = 1000000000;
			
			for(int j = 0; j < numOfLines; j++)
			{
				if(cache[set][j].lruReplace <= highestNum)
				{
					highestNum = cache[set][j].lruReplace;
				}
			}
                    	
			for(int j = 0; j < numOfLines; j++)
			{
				if(cache[set][j].lruReplace == highestNum)
				{
					cache[set][j].tag = tagIndex;
					cache[set][j].lruReplace = 0;
					
					for(int k = 0; k < numOfLines; k++)
					{
						if(j != k)
						{
							cache[set][k].lruReplace--;
						}
					}
					break;
				}
			}
			return;
		}
	}
}

int main(int argc, char** argv)
{ 
	if(argc != 6)
	{
		printf("error");
		return 0;
	}
	
	//CACHE SIZE
	cacheSize = atoi(argv[1]);
	
		//Check if cacheSize it is a power of 2
		int c = checkPower(cacheSize);
		if(c == 0) { printf("error"); return 0; }

	//BLOCK SIZE
	blockSize = atoi(argv[4]);

		//Check if blockSize it is a power of 2
                int b = checkPower(blockSize);
                if(b == 0) { printf("error"); return 0; }
	
	//BLOCK SIZE CAN'T BE LARGER THAN CACHE SIZE, RETURN error IF IT IS
	if(blockSize > cacheSize)
        {
                printf("error");
                return 0;
        }
	
	//NUM OF SETS & NUM OF LINES aka ASSOCIATIVITY
	char* assoc = argv[2];
	
	if(strcmp("direct", assoc) == 0)
	{
		//printf("Direct\n");
		numOfSets = (cacheSize / blockSize);
		numOfLines = 1;
	}
	else if(strcmp("assoc", assoc) == 0)
	{
		//printf("Assoc\n");
		numOfSets = 1;
		numOfLines = (cacheSize / blockSize);
	}
	else
	{
		//printf("Assoc:n\n");
		int num;
		sscanf(assoc, "assoc:%d", &num);
		
		int n = checkPower(num);

		if(n == 0)
		{
			printf("error");
			return 0;
		}
		numOfSets = (cacheSize / (blockSize * num));
		numOfLines = num;
	}
	
	//REPLACEMENT POLICY
	char* replacement = argv[3];
	
	if(strcmp("fifo", replacement) == 0)
	{
		replacePolicy = 0;
	}
	else if(strcmp("lru", replacement) == 0)
	{
		replacePolicy = 1;
	}
	else
	{
		printf("error");
		return 0;
	}
	
	//READING FILE
	FILE *fp = fopen(argv[5], "r");

	cache = createCache(numOfSets, numOfLines);

        offsetSize = (log2(blockSize));
        setSize = (log2(numOfSets));

	while(1)
	{
		count = (fscanf(fp, "%s %c %lx", counter, &readWrite, &address));
		
		if(count != 3)
		{	
			break;
		}
		
		else
		{
			int xyz = offsetSize + setSize;
			tagIndex = address >> xyz;
			set = (address >> (xyz - setSize)) & ((1 << (xyz - offsetSize)) - 1);
			
			if(replacePolicy == 0)
			{
                        	//printf("FIFO\n");
                        	calculateFIFO(numOfLines, set, tagIndex, readWrite);
                	}
                
                	else if(replacePolicy == 1)
                	{
                        	//printf("LRU\n");
                        	calculateLRU(numOfLines, set, tagIndex, readWrite);
                	}
		}
	}
	
	/*
	printf("Cache Size      = %d\n", cacheSize);
        printf("Block Size      = %d\n", blockSize);
        printf("Number of Lines = %d\n", numOfLines);
        printf("Number of Sets  = %d\n", numOfSets);
        printf("Replace Policy  = %d\n", replacePolicy);
        printf("Offset Size     = %d\n", offsetSize);
        printf("Set Size        = %d\n", setSize);
        printf("Read/Write      = %s\n", &readWrite);
        printf("Tag Index       = %ld\n", tagIndex);
        printf("Set Index       = %ld\n", set);
        printf("Count           = %d\n", count);
        printf("\n");
	*/

	printf("Memory reads: %d\n", numOfReads);
        printf("Memory writes: %d\n", numOfWrites);
        printf("Cache hits: %d\n", numOfHits);
        printf("Cache misses: %d\n", numOfMisses);
	
	freeCache(numOfSets);
	free(cache);
	fclose(fp);
	return 0;
}
