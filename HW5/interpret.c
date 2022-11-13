#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LSIZ 100 
#define RSIZ 50 

void checkCombinationAndCompute(int arr[4], int a, int b, char *opr, char *var1, char *var2);
void readVar(int arr[4], char *var);
int checkVar(char *var);
int checkJumps(int arr[4], int a, int b, char *opr, char *var1, char *var2);

void checkCombinationAndCompute(int arr[4], int a, int b, char *opr, char *var1, char *var2)
{
	int num;
	if(a == 5)
	{
		num = atoi(var1);
		if(b == 1) // num ax
		{
			if(strcmp(opr,"mul")==0) arr[0] = num * arr[0]; 
			if(strcmp(opr,"add")==0) arr[0] = num + arr[0];
			if(strcmp(opr,"sub")==0) arr[0] = arr[0] - num;
			if(strcmp(opr,"div")==0) arr[0] = num / arr[0];
			if(strcmp(opr,"mov")==0) arr[0] = num;
		}
		else if(b == 2) //num bx
		{
			if(strcmp(opr,"mul")==0) arr[1] = num * arr[1];
                        if(strcmp(opr,"add")==0) arr[1] = num + arr[1];
                        if(strcmp(opr,"sub")==0) arr[1] = arr[1] - num;
                        if(strcmp(opr,"div")==0) arr[1] = num / arr[1];
			if(strcmp(opr,"mov")==0) arr[1] = num;
		}
		else if(b == 3) //num cx
                {
                        if(strcmp(opr,"mul")==0) arr[2] = num * arr[2];
                        if(strcmp(opr,"add")==0) arr[2] = num + arr[2];
                        if(strcmp(opr,"sub")==0) arr[2] = arr[2] - num;
                        if(strcmp(opr,"div")==0) arr[2] = num / arr[2];
                	if(strcmp(opr,"mov")==0) arr[2] = num;
		}
		else if(b == 4) //num dx
                {
                        if(strcmp(opr,"mul")==0) arr[3] = num * arr[3];
                        if(strcmp(opr,"add")==0) arr[3] = num + arr[3];
                        if(strcmp(opr,"sub")==0) arr[3] = arr[3] - num;
                        if(strcmp(opr,"div")==0) arr[3] = num / arr[3];
                	if(strcmp(opr,"mov")==0) arr[3] = num;
		}
	}
	else if(a == 1)
	{
		if(b == 1) //ax ax
		{	
			if(strcmp(opr,"mul")==0) arr[0] = arr[0] * arr[0];
			if(strcmp(opr,"add")==0) arr[0] = arr[0] + arr[0];
			if(strcmp(opr,"sub")==0) arr[0] = arr[0] - arr[0];
			if(strcmp(opr,"div")==0) arr[0] = arr[0] / arr[0];
			if(strcmp(opr,"mov")==0) arr[0] = arr[0];
		}
		else if(b == 2) //ax bx
                {
                        if(strcmp(opr,"mul")==0) arr[1] = arr[0] * arr[1]; 
                        if(strcmp(opr,"add")==0) arr[1] = arr[0] + arr[1]; 
			if(strcmp(opr,"sub")==0) arr[1] = arr[1] - arr[0];
                        if(strcmp(opr,"div")==0) arr[1] = arr[0] / arr[1];
			if(strcmp(opr,"mov")==0) arr[1] = arr[0];
                }
		else if(b == 3) //ax cx
                {
                        if(strcmp(opr,"mul")==0) arr[2] = arr[0] * arr[2];
                        if(strcmp(opr,"add")==0) arr[2] = arr[0] + arr[2];
                        if(strcmp(opr,"sub")==0) arr[2] = arr[2] - arr[0];
                        if(strcmp(opr,"div")==0) arr[2] = arr[0] / arr[2];
                	if(strcmp(opr,"mov")==0) arr[2] = arr[0];
		}
		else if(b == 4) //ax dx
                {
                        if(strcmp(opr,"mul")==0) arr[3] = arr[0] * arr[3];
                        if(strcmp(opr,"add")==0) arr[3] = arr[0] + arr[3];
                        if(strcmp(opr,"sub")==0) arr[3] = arr[3] - arr[0];
                        if(strcmp(opr,"div")==0) arr[3] = arr[0] / arr[3];
                	if(strcmp(opr,"mov")==0) arr[3] = arr[0];
		}
	}
	else if(a == 2)
	{
		if(b == 1) //bx ax
                {
                        if(strcmp(opr,"mul")==0) arr[0] = arr[1] * arr[0];
                        if(strcmp(opr,"add")==0) arr[0] = arr[1] + arr[0];
                        if(strcmp(opr,"sub")==0) arr[0] = arr[0] - arr[1];
                        if(strcmp(opr,"div")==0) arr[0] = arr[1] / arr[0];
                	if(strcmp(opr,"mov")==0) arr[0] = arr[1];
		}
		else if(b == 2) //bx bx
                {
                        if(strcmp(opr,"mul")==0) arr[1] = arr[1] * arr[1];
                        if(strcmp(opr,"add")==0) arr[1] = arr[1] + arr[1];
                        if(strcmp(opr,"sub")==0) arr[1] = arr[1] - arr[1];
                        if(strcmp(opr,"div")==0) arr[1] = arr[1] / arr[1];
                	if(strcmp(opr,"mov")==0) arr[1] = arr[1];
		}
		else if(b == 3) //bx cx
                {
                        if(strcmp(opr,"mul")==0) arr[2] = arr[1] * arr[2];
                        if(strcmp(opr,"add")==0) arr[2] = arr[1] + arr[2];
                        if(strcmp(opr,"sub")==0) arr[2] = arr[2] - arr[1];
                        if(strcmp(opr,"div")==0) arr[2] = arr[1] / arr[2];
                	if(strcmp(opr,"mov")==0) arr[2] = arr[1];
		}
		else if(b == 4) //bx dx
                {
                        if(strcmp(opr,"mul")==0) arr[3] = arr[1] * arr[3];
                        if(strcmp(opr,"add")==0) arr[3] = arr[1] + arr[3];
                        if(strcmp(opr,"sub")==0) arr[3] = arr[3] - arr[1];
                        if(strcmp(opr,"div")==0) arr[3] = arr[1] / arr[3];
                	if(strcmp(opr,"mov")==0) arr[3] = arr[1];
		}
	}
	else if(a == 3)
        {
		if(b == 1) //cx ax
                {
                        if(strcmp(opr,"mul")==0) arr[0] = arr[2] * arr[0];
                        if(strcmp(opr,"add")==0) arr[0] = arr[2] + arr[0];
                        if(strcmp(opr,"sub")==0) arr[0] = arr[0] - arr[2];
                        if(strcmp(opr,"div")==0) arr[0] = arr[2] / arr[0];
                	if(strcmp(opr,"mov")==0) arr[0] = arr[2];
		}
		else if(b == 2) //cx bx
                {
                        if(strcmp(opr,"mul")==0) arr[1] = arr[2] * arr[1];
                        if(strcmp(opr,"add")==0) arr[1] = arr[2] + arr[1];
                        if(strcmp(opr,"sub")==0) arr[1] = arr[1] - arr[2];
                        if(strcmp(opr,"div")==0) arr[1] = arr[2] / arr[1];
                	if(strcmp(opr,"mov")==0) arr[1] = arr[2];
		}
		else if(b == 3) //cx cx
                {
                        if(strcmp(opr,"mul")==0) arr[2] = arr[2] * arr[2];
                        if(strcmp(opr,"add")==0) arr[2] = arr[2] + arr[2];
                        if(strcmp(opr,"sub")==0) arr[2] = arr[2] - arr[2];
                        if(strcmp(opr,"div")==0) arr[2] = arr[2] / arr[2];
                	if(strcmp(opr,"mov")==0) arr[2] = arr[2];
		}
		else if(b == 4) //cx dx
                {
                        if(strcmp(opr,"mul")==0) arr[3] = arr[2] * arr[3];
                        if(strcmp(opr,"add")==0) arr[3] = arr[2] + arr[3];
                        if(strcmp(opr,"sub")==0) arr[3] = arr[3] - arr[2];
                        if(strcmp(opr,"div")==0) arr[3] = arr[2] / arr[3];
                	if(strcmp(opr,"mov")==0) arr[3] = arr[2];
		}
        }
	else if(a == 4)
        {
		if(b == 1) //dx ax
                {
                        if(strcmp(opr,"mul")==0) arr[0] = arr[3] * arr[0];
                        if(strcmp(opr,"add")==0) arr[0] = arr[3] + arr[0];
                        if(strcmp(opr,"sub")==0) arr[0] = arr[0] - arr[3];
                        if(strcmp(opr,"div")==0) arr[0] = arr[3] / arr[0];
                	if(strcmp(opr,"mov")==0) arr[0] = arr[3];
		}
		else if(b == 2) //dx bx
                {
                        if(strcmp(opr,"mul")==0) arr[1] = arr[3] * arr[1];
                        if(strcmp(opr,"add")==0) arr[1] = arr[3] + arr[1];
                        if(strcmp(opr,"sub")==0) arr[1] = arr[1] - arr[3];
                        if(strcmp(opr,"div")==0) arr[1] = arr[3] / arr[1];
                	if(strcmp(opr,"mov")==0) arr[1] = arr[3];
		}
		else if(b == 3) //dx cx
                {
                        if(strcmp(opr,"mul")==0) arr[2] = arr[3] * arr[2];
                        if(strcmp(opr,"add")==0) arr[2] = arr[3] + arr[2];
                        if(strcmp(opr,"sub")==0) arr[2] = arr[2] - arr[3];
                        if(strcmp(opr,"div")==0) arr[2] = arr[3] / arr[2];
                	if(strcmp(opr,"mov")==0) arr[2] = arr[3];
		}
		else if(b == 4) //dx dx
                {
                        if(strcmp(opr,"mul")==0) arr[3] = arr[3] * arr[3];
                        if(strcmp(opr,"add")==0) arr[3] = arr[3] + arr[3];
                        if(strcmp(opr,"sub")==0) arr[3] = arr[3] - arr[3];
                        if(strcmp(opr,"div")==0) arr[3] = arr[3] / arr[3];
                	if(strcmp(opr,"mov")==0) arr[3] = arr[3];
		}
        }
}

void readVar(int arr[4], char *var)
{
	signed int temp;
	scanf("%d", &temp);

        int a = checkVar(var); 

	if(a == 1) arr[0] = temp;
	if(a == 2) arr[1] = temp;
	if(a == 3) arr[2] = temp;
	if(a == 4) arr[3] = temp;
}

int checkVar(char *var)
{
        int num;
	
	if((strcmp(var,"ax")) == 0) return 1;
        else if((strcmp(var,"bx")) == 0) return 2;
        else if((strcmp(var,"cx")) == 0) return 3;
        else if((strcmp(var,"dx")) == 0) return 4;
	else if((strcmp(var,"ax")) != 0 && (strcmp(var,"bx")) != 0 && (strcmp(var,"cx")) != 0 && (strcmp(var,"dx")) != 0) 
		return 5;
}

int checkJumps(int arr[4], int a, int b, char *opr, char *var1, char *var2)
{
	int num;
        if(a == 5)
        {
                num = atoi(var1);
                if(b == 1) // num ax
                {
                	if(strcmp(opr,"je")==0) { if(num == arr[0]) return 6; else return 7; }
                        if(strcmp(opr,"jne")==0) { if(num != arr[0]) return 6; else return 7; }
                        if(strcmp(opr,"jg")==0) { if(num > arr[0]) return 6; else return 7; }
                        if(strcmp(opr,"jge")==0) { if(num >= arr[0]) return 6; else return 7; }
                        if(strcmp(opr,"jl")==0) { if(num < arr[0]) return 6; else return 7; }
                        if(strcmp(opr,"jle")==0) { if(num <= arr[0]) return 6; else return 7; }
		}
                else if(b == 2) //num bx
                {
			if(strcmp(opr,"je")==0) { if(num == arr[1]) return 6; else return 7; }
                        if(strcmp(opr,"jne")==0) { if(num != arr[1]) return 6; else return 7; }
                        if(strcmp(opr,"jg")==0) { if(num > arr[1]) return 6; else return 7; }
                        if(strcmp(opr,"jge")==0) { if(num >= arr[1]) return 6; else return 7; }
                        if(strcmp(opr,"jl")==0) { if(num < arr[1]) return 6; else return 7; }
                        if(strcmp(opr,"jle")==0) { if(num <= arr[1]) return 6; else return 7; }
                }
                else if(b == 3) //num cx
                {
			if(strcmp(opr,"je")==0) { if(num == arr[2]) return 6; else return 7; }
                        if(strcmp(opr,"jne")==0) { if(num != arr[2]) return 6; else return 7; }
                        if(strcmp(opr,"jg")==0) { if(num > arr[2]) return 6; else return 7; }
                        if(strcmp(opr,"jge")==0) { if(num >= arr[2]) return 6; else return 7; }
                        if(strcmp(opr,"jl")==0) { if(num < arr[2]) return 6; else return 7; }
                        if(strcmp(opr,"jle")==0) { if(num <= arr[2]) return 6; else return 7; }
                }
                else if(b == 4) //num dx
                {
			if(strcmp(opr,"je")==0) { if(num == arr[3]) return 6; else return 7; }
                        if(strcmp(opr,"jne")==0) { if(num != arr[3]) return 6; else return 7; }
                        if(strcmp(opr,"jg")==0) { if(num > arr[3]) return 6; else return 7; }
                        if(strcmp(opr,"jge")==0) { if(num >= arr[3]) return 6; else return 7; }
                        if(strcmp(opr,"jl")==0) { if(num < arr[3]) return 6; else return 7; }
                        if(strcmp(opr,"jle")==0) { if(num <= arr[3]) return 6; else return 7; }
                }
        }
	else if(a == 1)
        {
                if(b == 1) //ax ax
                {
			if(strcmp(opr,"je")==0) { if(arr[0] == arr[0]) return 6; else return 7; }
                        if(strcmp(opr,"jne")==0) { if(arr[0] != arr[0]) return 6; else return 7; }
                        if(strcmp(opr,"jg")==0) { if(arr[0] > arr[0]) return 6; else return 7; }
                        if(strcmp(opr,"jge")==0) { if(arr[0] >= arr[0]) return 6; else return 7; }
                        if(strcmp(opr,"jl")==0) { if(arr[0] < arr[0]) return 6; else return 7; }
                        if(strcmp(opr,"jle")==0) { if(arr[0] <= arr[0]) return 6; else return 7; }
                }
                else if(b == 2) //ax bx
                {
			//printf("add ax bx\n");
			if(strcmp(opr,"je")==0) { if(arr[0] == arr[1]) return 6; else return 7; }
                        if(strcmp(opr,"jne")==0) { if(arr[0] != arr[1]) return 6; else return 7; }
                        if(strcmp(opr,"jg")==0) { if(arr[0] > arr[1]) return 6; else return 7; }
                        if(strcmp(opr,"jge")==0) { if(arr[0] >= arr[1]) return 6; else return 7; }
                        if(strcmp(opr,"jl")==0) { if(arr[0] < arr[1]) return 6; else return 7; }
                        if(strcmp(opr,"jle")==0) { if(arr[0] <= arr[1]) return 6; else return 7; }
                }
                else if(b == 3) //ax cx
                {
			if(strcmp(opr,"je")==0) { if(arr[0] == arr[2]) return 6; else return 7; }
                        if(strcmp(opr,"jne")==0) { if(arr[0] != arr[2]) return 6; else return 7; }
                        if(strcmp(opr,"jg")==0) { if(arr[0] > arr[2]) return 6; else return 7; }
                        if(strcmp(opr,"jge")==0) { if(arr[0] >= arr[2]) return 6; else return 7; }
                        if(strcmp(opr,"jl")==0) { if(arr[0] < arr[2]) return 6; else return 7; }
                        if(strcmp(opr,"jle")==0) { if(arr[0] <= arr[2]) return 6; else return 7; }
                }
                else if(b == 4) //ax dx
                {
			if(strcmp(opr,"je")==0) { if(arr[0] == arr[3]) return 6; else return 7; }
                        if(strcmp(opr,"jne")==0) { if(arr[0] != arr[3]) return 6; else return 7; }
                        if(strcmp(opr,"jg")==0) { if(arr[0] > arr[3]) return 6; else return 7; }
                        if(strcmp(opr,"jge")==0) { if(arr[0] >= arr[3]) return 6; else return 7; }
                        if(strcmp(opr,"jl")==0) { if(arr[0] < arr[3]) return 6; else return 7; }
                        if(strcmp(opr,"jle")==0) { if(arr[0] <= arr[3]) return 6; else return 7; }
                }
		else if(b == 5) //ax num
		{
			num = atoi(var2);
			if(strcmp(opr,"je")==0) { if(arr[0] == num) return 6; else return 7; }
                        if(strcmp(opr,"jne")==0) { if(arr[0] != num) return 6; else return 7; }
                        if(strcmp(opr,"jg")==0) { if(arr[0] > num) return 6; else return 7; }
                        if(strcmp(opr,"jge")==0) { if(arr[0] >= num) return 6; else return 7; }
                        if(strcmp(opr,"jl")==0) { if(arr[0] < num) return 6; else return 7; }
                        if(strcmp(opr,"jle")==0) { if(arr[0] <= num) return 6; else return 7; }
		}
        }
	else if(a == 2)
        {
                if(b == 1) //bx ax
                {
			if(strcmp(opr,"je")==0) { if(arr[1] == arr[0]) return 6; else return 7; }
                        if(strcmp(opr,"jne")==0) { if(arr[1] != arr[0]) return 6; else return 7; }
                        if(strcmp(opr,"jg")==0) { if(arr[1] > arr[0]) return 6; else return 7; }
                        if(strcmp(opr,"jge")==0) { if(arr[1] >= arr[0]) return 6; else return 7; }
                        if(strcmp(opr,"jl")==0) { if(arr[1] < arr[0]) return 6; else return 7; }
                        if(strcmp(opr,"jle")==0) { if(arr[1] <= arr[0]) return 6; else return 7; }
                }
                else if(b == 2) //bx bx
                {
			if(strcmp(opr,"je")==0) { if(arr[1] == arr[1]) return 6; else return 7; }
                        if(strcmp(opr,"jne")==0) { if(arr[1] != arr[1]) return 6; else return 7; }
                        if(strcmp(opr,"jg")==0) { if(arr[1] > arr[1]) return 6; else return 7; }
                        if(strcmp(opr,"jge")==0) { if(arr[1] >= arr[1]) return 6; else return 7; }
                        if(strcmp(opr,"jl")==0) { if(arr[1] < arr[1]) return 6; else return 7; }
                        if(strcmp(opr,"jle")==0) { if(arr[1] <= arr[1]) return 6; else return 7; }
                }
                else if(b == 3) //bx cx
                {
			if(strcmp(opr,"je")==0) { if(arr[1] == arr[2]) return 6; else return 7; }
                        if(strcmp(opr,"jne")==0) { if(arr[1] != arr[2]) return 6; else return 7; }
                        if(strcmp(opr,"jg")==0) { if(arr[1] > arr[2]) return 6; else return 7; }
                        if(strcmp(opr,"jge")==0) { if(arr[1] >= arr[2]) return 6; else return 7; }
                        if(strcmp(opr,"jl")==0) { if(arr[1] < arr[2]) return 6; else return 7; }
                        if(strcmp(opr,"jle")==0) { if(arr[1] <= arr[2]) return 6; else return 7; }
                }
                else if(b == 4) //bx dx
                {
			if(strcmp(opr,"je")==0) { if(arr[1] == arr[3]) return 6; else return 7; }
                        if(strcmp(opr,"jne")==0) { if(arr[1] != arr[3]) return 6; else return 7; }
                        if(strcmp(opr,"jg")==0) { if(arr[1] > arr[3]) return 6; else return 7; }
                        if(strcmp(opr,"jge")==0) { if(arr[1] >= arr[3]) return 6; else return 7; }
                        if(strcmp(opr,"jl")==0) { if(arr[1] < arr[3]) return 6; else return 7; }
                        if(strcmp(opr,"jle")==0) { if(arr[1] <= arr[3]) return 6; else return 7; }
                }
		else if(b == 5) //bx num
                {
                        num = atoi(var2);
                        if(strcmp(opr,"je")==0) { if(arr[1] == num) return 6; else return 7; }
                        if(strcmp(opr,"jne")==0) { if(arr[1] != num) return 6; else return 7; }
                        if(strcmp(opr,"jg")==0) { if(arr[1] > num) return 6; else return 7; }
                        if(strcmp(opr,"jge")==0) { if(arr[1] >= num) return 6; else return 7; }
                        if(strcmp(opr,"jl")==0) { if(arr[1] < num) return 6; else return 7; }
                        if(strcmp(opr,"jle")==0) { if(arr[1] <= num) return 6; else return 7; }
                }
        }
	else if(a == 3)
        {
                if(b == 1) //cx ax
                {
			if(strcmp(opr,"je")==0) { if(arr[2] == arr[0]) return 6; else return 7; }
                        if(strcmp(opr,"jne")==0) { if(arr[2] != arr[0]) return 6; else return 7; }
                        if(strcmp(opr,"jg")==0) { if(arr[2] > arr[0]) return 6; else return 7; }
                        if(strcmp(opr,"jge")==0) { if(arr[2] >= arr[0]) return 6; else return 7; }
                        if(strcmp(opr,"jl")==0) { if(arr[2] < arr[0]) return 6; else return 7; }
                        if(strcmp(opr,"jle")==0) { if(arr[2] <= arr[0]) return 6; else return 7; }
                }
                else if(b == 2) //cx bx
                {
			if(strcmp(opr,"je")==0) { if(arr[2] == arr[1]) return 6; else return 7; }
                        if(strcmp(opr,"jne")==0) { if(arr[2] != arr[1]) return 6; else return 7; }
                        if(strcmp(opr,"jg")==0) { if(arr[2] > arr[1]) return 6; else return 7; }
                        if(strcmp(opr,"jge")==0) { if(arr[2] >= arr[1]) return 6; else return 7; }
                        if(strcmp(opr,"jl")==0) { if(arr[2] < arr[1]) return 6; else return 7; }
                        if(strcmp(opr,"jle")==0) { if(arr[2] <= arr[1]) return 6; else return 7; }
                }
                else if(b == 3) //cx cx
                {
			if(strcmp(opr,"je")==0) { if(arr[2] == arr[2]) return 6; else return 7; }
                        if(strcmp(opr,"jne")==0) { if(arr[2] != arr[2]) return 6; else return 7; }
                        if(strcmp(opr,"jg")==0) { if(arr[2] > arr[2]) return 6; else return 7; }
                        if(strcmp(opr,"jge")==0) { if(arr[2] >= arr[2]) return 6; else return 7; }
                        if(strcmp(opr,"jl")==0) { if(arr[2] < arr[2]) return 6; else return 7; }
                        if(strcmp(opr,"jle")==0) { if(arr[2] <= arr[2]) return 6; else return 7; }
                }
                else if(b == 4) //cx dx
                {
			if(strcmp(opr,"je")==0) { if(arr[2] == arr[3]) return 6; else return 7; }
                        if(strcmp(opr,"jne")==0) { if(arr[2] != arr[3]) return 6; else return 7; }
                        if(strcmp(opr,"jg")==0) { if(arr[2] > arr[3]) return 6; else return 7; }
                        if(strcmp(opr,"jge")==0) { if(arr[2] >= arr[3]) return 6; else return 7; }
                        if(strcmp(opr,"jl")==0) { if(arr[2] < arr[3]) return 6; else return 7; }
                        if(strcmp(opr,"jle")==0) { if(arr[2] <= arr[3]) return 6; else return 7; }
                }
		else if(b == 5) //cx num
                {
                        num = atoi(var2);
                        if(strcmp(opr,"je")==0) { if(arr[2] == num) return 6; else return 7; }
                        if(strcmp(opr,"jne")==0) { if(arr[2] != num) return 6; else return 7; }
                        if(strcmp(opr,"jg")==0) { if(arr[2] > num) return 6; else return 7; }
                        if(strcmp(opr,"jge")==0) { if(arr[2] >= num) return 6; else return 7; }
                        if(strcmp(opr,"jl")==0) { if(arr[2] < num) return 6; else return 7; }
                        if(strcmp(opr,"jle")==0) { if(arr[2] <= num) return 6; else return 7; }
                }
        }
	else if(a == 4)
        {
                if(b == 1) //dx ax
                {
			if(strcmp(opr,"je")==0) { if(arr[3] == arr[0]) return 6; else return 7; }
                        if(strcmp(opr,"jne")==0) { if(arr[3] != arr[0]) return 6; else return 7; }
                        if(strcmp(opr,"jg")==0) { if(arr[3] > arr[0]) return 6; else return 7; }
                        if(strcmp(opr,"jge")==0) { if(arr[3] >= arr[0]) return 6; else return 7; }
                        if(strcmp(opr,"jl")==0) { if(arr[3] < arr[0]) return 6; else return 7; }
                        if(strcmp(opr,"jle")==0) { if(arr[3] <= arr[0]) return 6; else return 7; }
                }
                else if(b == 2) //dx bx
                {
			if(strcmp(opr,"je")==0) { if(arr[3] == arr[1]) return 6; else return 7; }
                        if(strcmp(opr,"jne")==0) { if(arr[3] != arr[1]) return 6; else return 7; }
                        if(strcmp(opr,"jg")==0) { if(arr[3] > arr[1]) return 6; else return 7; }
                        if(strcmp(opr,"jge")==0) { if(arr[3] >= arr[1]) return 6; else return 7; }
                        if(strcmp(opr,"jl")==0) { if(arr[3] < arr[1]) return 6; else return 7; }
                        if(strcmp(opr,"jle")==0) { if(arr[3] <= arr[1]) return 6; else return 7; }
                }
                else if(b == 3) //dx cx
                {
			if(strcmp(opr,"je")==0) { if(arr[3] == arr[2]) return 6; else return 7; }
                        if(strcmp(opr,"jne")==0) { if(arr[3] != arr[2]) return 6; else return 7; }
                        if(strcmp(opr,"jg")==0) { if(arr[3] > arr[2]) return 6; else return 7; }
                        if(strcmp(opr,"jge")==0) { if(arr[3] >= arr[2]) return 6; else return 7; }
                        if(strcmp(opr,"jl")==0) { if(arr[3] < arr[2]) return 6; else return 7; }
                        if(strcmp(opr,"jle")==0) { if(arr[3] <= arr[2]) return 6; else return 7; }
                }
                else if(b == 4) //dx dx
                {
			if(strcmp(opr,"je")==0) { if(arr[3] == arr[3]) return 6; else return 7; }
                        if(strcmp(opr,"jne")==0) { if(arr[3] != arr[3]) return 6; else return 7; }
                        if(strcmp(opr,"jg")==0) { if(arr[3] > arr[3]) return 6; else return 7; }
                        if(strcmp(opr,"jge")==0) { if(arr[3] >= arr[3]) return 6; else return 7; }
                        if(strcmp(opr,"jl")==0) { if(arr[3] < arr[3]) return 6; else return 7; }
                        if(strcmp(opr,"jle")==0) { if(arr[3] <= arr[3]) return 6; else return 7; }
                }
		else if(b == 5) //dx num
                {
                        num = atoi(var2);
                        if(strcmp(opr,"je")==0) { if(arr[3] == num) return 6; else return 7; }
                        if(strcmp(opr,"jne")==0) { if(arr[3] != num) return 6; else return 7; }
                        if(strcmp(opr,"jg")==0) { if(arr[3] > num) return 6; else return 7; }
                        if(strcmp(opr,"jge")==0) { if(arr[3] >= num) return 6; else return 7; }
                        if(strcmp(opr,"jl")==0) { if(arr[3] < num) return 6; else return 7; }
                        if(strcmp(opr,"jle")==0) { if(arr[3] <= num) return 6; else return 7; }
                }
        }
}

int main(int argc, char* argv[])
{
	char opr[10];
	FILE *fp = fopen(argv[1], "r");
	int i = 0, total = 0;
	
	//PUT INTO ARRAY
	char line[RSIZ][LSIZ];
	while(fgets(line[i], LSIZ, fp)) 
	{
		line[i][strlen(line[i]) - 1] = '\0';
		i++;
	}
	total = i;
	
	//printf("Num of lines = %d\n",total);
	
	char lineNo[5];
	char string[100];
	char var[10], var2[10], var1[10];
	int arr[4]; arr[0] = 0, arr[1] = 0, arr[2] = 0, arr[3] = 0;
	
	int k=0;
	for(k = 0; k < total; ++k)
	{	
		strcpy(string, line[k]);
		sscanf(string, "%s", opr);

		if(strcmp(string, "\0") == 0)
                {
                        //printf("Blank Line\n");
			continue;
                }

		else if(strcmp(opr, "read") == 0)
		{
			sscanf(string, "%s\t%s",opr, var);
			
			signed int temp;
                        scanf("%d", &temp);
                        	
                        int a = checkVar(var);
                        if(a == 1) arr[0] = temp;
                        if(a == 2) arr[1] = temp;
                        if(a == 3) arr[2] = temp;
                        if(a == 4) arr[3] = temp;
		}

		else if(strcmp(opr, "add") == 0 || strcmp(opr, "div") == 0 || 
				strcmp(opr, "mul") == 0 || strcmp(opr, "sub") == 0 || strcmp(opr, "mov") == 0)
		{
			sscanf(string, "%s\t%s\t%s",opr, var1, var2);

			int b = checkVar(var1);
                        int c = checkVar(var2);	
			
			checkCombinationAndCompute(arr, b, c, opr, var1, var2);
		}
		
		else if(strcmp(opr, "print") == 0)
		{
			sscanf(string, "%s\t%s",opr, var);

			int a = checkVar(var);
                 	//printf("a = %d\n", a); 
		 	//printf("var = %s\n", var);	

			if(a == 1) printf("%d",arr[0]);	
			else if(a == 2) printf("%d",arr[1]);
			else if(a == 3) printf("%d",arr[2]);
			else if(a == 4) printf("%d",arr[3]);
			else if(a == 5) printf("%s",var);
		}
		
		else if(strcmp(opr, "jmp") == 0)
		{
			sscanf(string, "%s\t%s",opr, lineNo);	
			k = (atoi(lineNo)) - 1;
		}

		else if(strcmp(opr, "je") == 0 || strcmp(opr, "jne") == 0 || strcmp(opr, "jg") == 0 || 
				strcmp(opr, "jge") == 0 || strcmp(opr, "jl") == 0 || strcmp(opr, "jle") == 0)
		{
			sscanf(string, "%s\t%s\t%s\t%s",opr, lineNo, var1, var2);
			int a = checkVar(var1);
                        int b = checkVar(var2);
			
			int ans = checkJumps(arr, a, b, opr, var1, var2);
			if(ans == 6) k = (atoi(lineNo)) - 1;
		}
	}
	fclose(fp);	
}
