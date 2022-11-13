#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define LSIZ 100
#define RSIZ 50

typedef struct node {
	int value;
	char varName[500];
	struct node *next;
} node;

//GLOBAL VARIALBLES
node *firstNode = NULL;
node *lastNode = NULL;

int getValue(char someVariable[500]) {
	
	//printf("Inside getValue %s\n", someVariable);
	node *p;

	if(firstNode == NULL)
		return -1;
	
	else {
		p = firstNode;
		while (p != NULL) {

			if(strcmp(someVariable, p->varName) == 0) {
				
				//printf("Found Value %d\n",p->value);
				return p->value;
			}
			else {
				p = p->next;
			}
		}
	}
	return -1;
}

void putValue(char someVariable[500], int val) {
	//printf("Inside putValue %s %d \n", someVariable, val);
	
	node *p;
	
        if(firstNode == NULL) { 
		
		//printf("firstNode is null\n");
		
		node *temp = NULL;
        	temp = (node*)malloc(sizeof(node));
        	strcpy(temp->varName,someVariable);
        	temp->value = val;
        	temp->next = NULL;
		firstNode=temp;
		lastNode=temp;
	}
        else {
		//printf("firstNode is not null\n");
                p = firstNode;
                
		while (p != NULL) {
                        if(strcmp(someVariable, p->varName) == 0) {
                                
				p->value = val;
				break;
			}
                        else {
                                p = p->next;
			}
                }
		if(p == NULL) { //node was not found. So create a new one
			
			//printf("Node was not found. So create a new one\n");
			
			node *temp = NULL;
                	temp = (node*)malloc(sizeof(node));
                	strcpy(temp->varName,someVariable);
                	temp->value = val;
                	temp->next = NULL;
			lastNode->next=temp;
			lastNode=temp;

		}
        }
	return;
}

void executeCommandNOT(char opr[4], char inputVariable1[500], char outputVariable[500]) {
	
	//printf("Inside executeCommandNOT %s %s %s\n", opr, inputVariable1, outputVariable);
	
	int var1value = getValue(inputVariable1);
	int outputValue = -1;

	if(strcmp(opr, "NOT") == 0) {
                
		if(var1value == 1)
                        outputValue = 0;
                else
                        outputValue = 1;
        }
	putValue(outputVariable, outputValue);
}

void executeCommand(char opr[4], char inputVariable1[10], char inputVariable2[500], char outputVariable[500])
{
	//printf("Inside executeCommand %s %s %s %s\n", opr, inputVariable1, inputVariable2, outputVariable);

	// If opr == AND, then fetch the value of inputVariable1 from Hashmap. Fetch the value of Inputvariable2 from Hashmap. Do the AND operation and store the result in outputVariable in Hashmap
	
	int var1value = getValue(inputVariable1);
        int var2value = getValue(inputVariable2);
	int outputValue = -1;

	if(strcmp(opr,"AND") == 0) {
		outputValue = var1value && var2value;
	}
	if(strcmp(opr,"OR") == 0) {
                outputValue = var1value || var2value;
        }
	if(strcmp(opr,"NAND") == 0) {
		if(var1value == 1 && var2value == 1)
			outputValue = 0;
		else
			outputValue = 1;
        }
	if(strcmp(opr, "NOR") == 0) {
		if(var1value == 0 && var2value == 0)
                        outputValue = 1;
                else    
                        outputValue = 0;
	}
	if(strcmp(opr, "XOR") == 0) {		
		if( (var1value == 1 && var2value == 1) || (var1value == 0 && var2value == 0) )
			outputValue = 0;
		else
			outputValue = 1;	
	}

	putValue(outputVariable, outputValue);
}


int main(int argc, char* argv[])
{

	FILE *fp = fopen(argv[1], "r");
	FILE *fp1 = fopen(argv[1], "r");

        if(fp == NULL)
        {
		return -1;
        }
	
	int i = 0, total = 0;

	//CALCULATE # OF LINES
	
	char line[RSIZ][LSIZ];
	while(fgets(line[i], LSIZ, fp1)) {
		line[i][strlen(line[i]) - 1] = '\0';
		i++;
	}
	total = i;
	
	//printf("Total = %d\n", total);
	
	int numOfInputs = 0;
        int numOfOutputs = 0;

	//SCANNING INPUT VARS & ADDING VARS TO LL

	fscanf(fp, "INPUTVAR\t%d", &numOfInputs);
        //printf("Num Of Inputs = %d\n", numOfInputs);

	char inputVar[500];
	char inputVarNames[500][500];

        for(int i = 0; i < numOfInputs; i++) {
                
		fscanf(fp," %s",inputVar);
		strcpy(inputVarNames[i],inputVar);
                //printf("%s",inputVar);

        }
	
	fscanf(fp, "\n");
	//printf("\n");

	//SCANNING OUTPUT VARS

	fscanf(fp, "OUTPUTVAR\t%d", &numOfOutputs);
        //printf("Num Of Outputs..1 = %d\n", numOfOutputs);

	char outputVar[500];
	char outputVarNames[500][500];
        for(int i = 0; i < numOfOutputs; i++) {
                
		fscanf(fp," %s",outputVar);
		strcpy(outputVarNames[i],outputVar);
                //printf("%s",outputVar);

        }

	fscanf(fp, "\n");
	//printf("\n");

	//CREATING COMBINATIONS

	int rows = (int)(pow(2, numOfInputs));
	int arr[rows][numOfInputs];
	
	for (int i = 0; i < rows; i++) {
		
		for (int j = numOfInputs-1; j >= 0; j--) {
			
			int x = i / (int) (pow(2, j)) % 2 ; 
			arr[i][j] = x;
			//printf("i = %d j = %d x = %d \n", i, j, x);
		}
	}
	
	/*
	for (int i = 0; i < rows; i++)
        {
		for (int j = numOfInputs-1; j >= 0; j--)
		{
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
	*/

	fclose(fp);
	fclose(fp1);
	//SCANNING OPERATIONS

	char opr[5];
	char var1[500];
	char var2[500];
	char output[50];
	
	int tot = total - 2;

	for(int i=0; i<rows; i++){
		
		//Populate IN1, IN2 and IN3 in Hashmap
		//printf("1 starting to populate Input values\n %d", numOfInputs);
		
		for (int j = numOfInputs-1, n = 0; j >= 0; j--, n++) {
			
			printf("%d ", arr[i][j]);
			//printf("%s %d \n", inputVarNames[n], arr[i][j]);
			putValue(inputVarNames[n], arr[i][j]);
		}
		
		//printf("Completed Putting values\n");

		//Start Executing the commands
		
		FILE *fp2 = fopen(argv[1], "r");

		fscanf(fp2, "%*[^\n]\n");
		fscanf(fp2, "%*[^\n]\n");
		
		//Start of 3rd line
		for(int temp1 = 0; temp1 < tot; temp1++) {
			
			fscanf(fp2, "%s ", opr);
			//fscanf(fp2, "%s %s %s %s", opr, var1, var2, output);
			
			if(strcmp(opr, "NOT") == 0) {

				fscanf(fp2, "%s %s", var1, output);
                                //printf("count = %d\n", count);
				executeCommandNOT(opr, var1, output);
			}
			else {
				fscanf(fp2, "%s %s %s", var1, var2, output);
				//printf("count = %d\n", count);
				executeCommand(opr, var1, var2, output);
			}	
		}

		for(int j=0; j<numOfOutputs; j++){
			
			printf("%d ", getValue(outputVarNames[j]));
		}

		printf("\n");
		
		fclose(fp2);
	}
}
