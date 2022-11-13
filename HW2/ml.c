#include <stdlib.h>
#include <stdio.h>

void freeArray(double** A, int row);
void printArray(double** A, int row, int col);
void transpose(double** AT, double** A, int row, int col);
double** multiply(double** resultOfMul, double** A, double** B, int rowA, int colA, int rowB, int colB);
double** createIdentityMatrix(double** A, int n);
void divideRow(double** A, int p, double f, int size);
void inverse(double** M, double** N, int row, int col);

void freeArray(double** A, int row)
{
    for(int i=0; i<row; i++)
    {
        free(A[i]);
    }
    free(A);
}

void printArray(double** A, int row, int col)
{
        for(int i=0; i<row; i++)
        {
                for(int j=0; j<col; j++)
                {
                        printf("%0.0lf ", A[i][j]);

                        if(j==(col-1))
                        {
                                printf("\n");
                        }
                }
        }
}

void transpose(double** XT, double** X, int row, int col)
{
        for (int i=0; i<row; i++)
        {
                for (int j=0; j<col; j++)
                {
                        //printf("j= %d\n",j);
                        XT[j][i] = X[i][j];
                }
        }
}

double** multiply(double** resultOfMul, double** A, double** B, int rowA, int colA, int rowB,int colB)
{	
	int  i,j,k;
        double temp;
	for (i = 0; i < rowA; i++)
        {
                for (j = 0; j < colB; j++)
                {
                        temp=0.000000;
                        for (k = 0; k < colA; k++)
                        {
                                temp += (A[i][k]) * (B[k][j]);
                        }
                        resultOfMul[i][j]=temp;
                }
        }
        return resultOfMul;
}

double** createIdentityMatrix(double** A, int n)
{
        for (int i=0; i<n; i++)
        {
                for (int j=0; j<n; j++)
                {
                        if (i == j)
                                A[i][j] = 1;
                        else
                                A[i][j] = 0;
                }
        }
        return A;
}

void divideRow(double** A, int p, double f, int size )
{
	for(int i = 0; i<size; i++)
	{
		A[p][i]=A[p][i]/f;
        }
}

void inverse(double** M, double** N, int row, int col)
{
	//printf("Entering Inverse Function\n");
	//printArray(M, row, col);
        N = createIdentityMatrix(N, row);
	for(int p=0; p<row; p++)
	{
                double f = M[p][p];
		
	//	printf("i==%d f == %lf\n",p, f);
        	divideRow(M, p, f,row);
	//	printf("Aftering dividing Mp by f\n");
	//	printArray(M,row,col);
                divideRow(N, p, f,row);
	//	printf("Aftering dividing N by f\n");
	//	printArray(N, row, row);	
		
		for(int i=p+1; i<row; i++)
		{
                        double f1 = M[i][p];
	//		printf("F1 = %lf",f1);

                        for(int a=0; a<row ;a++){
                                M[i][a]= M[i][a] - (M[p][a]*f1);
                        }
	//		printf("M After subtraction\n");
	//		printArray(M, row, col);
                        for(int a=0; a<row ;a++){
                                N[i][a]= N[i][a] - (N[p][a]*f1);
                        }
	//		printf("N after subtraction\n");
	//		printArray(N, row, row);
		}
        }

	for(int p=row-1;p>=0;p--)
	{
                for(int i=p-1; i>=0; i--)
		{
                        double f2 =M[i][p];

                        for(int a=0; a<row ;a++){
                                M[i][a]= M[i][a] - (M[p][a]*f2);
                        }
                        for(int a=0; a<row ;a++){
                                N[i][a]= N[i][a] - (N[p][a]*f2);
                        }
                }
        }
	//printf("Exiting Inverse Function");
}

int main(int argc, char** argv)
{
	FILE *trainfile = fopen(argv[1], "r");
        FILE *testfile = fopen(argv[2], "r");
        int attributes, numOfHouses, firstNumInTest;

	fscanf(trainfile,"%d\n", &attributes);
        fscanf(trainfile, "%d\n", &numOfHouses);
	fscanf(testfile, "%d\n", &firstNumInTest);
	
	/*
	printf("Number of Attributes = %d\n", attributes); //10
        printf("Number of Houses = %d\n", numOfHouses);    //4
        printf("Number of rows in testing file = %d\n", firstNumInTest);
	*/

	int rowX = numOfHouses;
        int colX = attributes+1;

	int rowY = numOfHouses;
        int colY = 1;

        int rowXT = attributes+1;
        int colXT = numOfHouses;

        int rowMul1 = rowXT; //Mul1 = XT x X
        int colMul1 = colX;

	int rowInv = rowMul1;
        int colInv = colMul1;

        int rowMul2 = rowInv;
        int colMul2 = colXT;

        int rowIden = rowMul1;
        int colIden = colMul1;

	int rowW = rowMul2;
	int colW = colY;

	int rowC = firstNumInTest;
        int colC = attributes+1;

	int rowD = rowC;
	int colD = colW;

	double** X = (double**)malloc(rowX*sizeof(double*));
	double** Y = (double**)malloc(rowY*sizeof(double*));
	double** XT = (double**)malloc((rowXT)*sizeof(double*));
	double** resultOfMul1 = (double**)malloc((rowMul1)*sizeof(double*));//Mul1 = XT x X
	double** resultOfMul2 = (double**)malloc((rowMul2)*sizeof(double*));//Mul2 = (XT x X)^-1 * XT rowMul1 x colMul1 = 
	//double** inverseMatrix = (double**)malloc((rowInv)*sizeof(double*));
	double** identityMatrix = (double**)malloc((rowIden)*sizeof(double*));
	double** W = (double**)malloc((rowW)*sizeof(double*));
	
	double** C = (double**)malloc((rowC)*sizeof(double*));
	double** D = (double**)malloc((rowD)*sizeof(double*));

	int x;
	for(x=0; x<rowX; x++){
                X[x] = (double*)malloc((colX)*sizeof(double));
        }
	for(x=0; x<rowY; x++){
                Y[x] = (double*)malloc(colY*sizeof(double));
        }
	for(x=0; x<rowXT; x++){
                XT[x] = (double*)malloc(colXT*sizeof(double));
        }
        for(x=0; x<rowMul1; x++){
                resultOfMul1[x] = (double*)malloc(colMul1*sizeof(double));
        }
        for(x=0; x<rowMul2; x++){
                resultOfMul2[x] = (double*)malloc(colMul2*sizeof(double));
        }
	/*
        for(x=0; x<rowInv; x++){
                inverseMatrix[x] = (double*)malloc(colInv*sizeof(double));
        }
	*/
	for(x=0; x<rowIden; x++){
                identityMatrix[x] = (double*)malloc(colIden*sizeof(double));
        }
	for(x=0; x<rowW; x++){
		W[x] = (double*)malloc(colW*sizeof(double));
        }
	for(x=0; x<rowC; x++){
                C[x] = (double*)malloc((colC)*sizeof(double));
        }
	for(x=0; x<rowD; x++){
                D[x] = (double*)malloc((colD)*sizeof(double));
        }

	for(int i=0; i<rowX; i++)
        {
                X[i][0] = 1;
	}
	for(int i=0; i<rowC; i++)
        {       
                C[i][0] = 1;
        }
	
	//scanning train file
        for(int x=0; x<numOfHouses; x++)
        {
                for(int y=1; y<attributes+2; y++)
                {
                        if(y==(attributes+1))
                        {
                                fscanf(trainfile, "%lf\n" , &Y[x][0]);
                        }
                        else
                        {
                                fscanf(trainfile, "%lf" , &X[x][y]);
                        }
                        fscanf(trainfile, ",");
                }
        }

	//printf("C is %d x %d\n",rowC,colC);
	//scanning test file
	for(int x=0; x<rowC; x++)
        {
                for(int y=1; y<colC; y++)
                {
			fscanf(testfile, "%lf" , &C[x][y]);
			//printf("C[%d][%d] = %lf\n",x,y,C[x][y]);
			fscanf(testfile, ",");
		}
	}

	/*
	printf("\n");
	printf("X Matrix: \n");
        printArray(X,rowX,colX);

        printf("\n");
	printf("Y Matrix: \n");
        printArray(Y,rowY,colY);
	
	printf("\n");
        printf("C Matrix: \n");
        printArray(C,rowC,colC);

	printf("\n");
        printf("XT Matrix: \n");
	transpose(XT,X,rowX,colX);
        printArray(XT,rowXT,colXT);

	printf("\n"); 
        printf("XT*X Matrix: \n");
	resultOfMul1 = multiply(resultOfMul1, XT, X, rowXT, colXT, rowX, colX);
	printArray(resultOfMul1,rowMul1,colMul1);

	printf("\n");
	printf("Inverse of (XT*X): \n");
	inverseMatrix = inverse(resultOfMul1, identityMatrix, rowMul1, colMul1);
	printArray(inverseMatrix, rowInv, colInv);

	printf("\n");
	printf("Inverse * XT\n");
	resultOfMul2 = multiply(resultOfMul2, inverseMatrix, XT, rowInv, colInv, rowXT, colXT);
	printArray(resultOfMul2, rowMul2, colMul2);
	
	printf("\n");
        printf("Inverse * XT * Y\n");
	W = multiply(W, resultOfMul2, Y, rowMul2, colMul2, rowY, colY);
	printArray(W, rowW, colW);	

	printf("\n");
	printf("C * W\n");
	printf("W: %d x %d\n",rowW, colW);
        printf("C: %d x %d\n",rowC, colC);
        printf("D: %d x %d\n",rowD, colD);
	D = multiply(D, C, W, rowC, colC, rowW, colW);
	printf("\n");
	*/
	
	transpose(XT,X,rowX,colX);
	resultOfMul1 = multiply(resultOfMul1, XT, X, rowXT, colXT, rowX, colX);
	inverse(resultOfMul1, identityMatrix, rowMul1, colMul1);
	resultOfMul2 = multiply(resultOfMul2, identityMatrix, XT, rowInv, colInv, rowXT, colXT);
	W = multiply(W, resultOfMul2, Y, rowMul2, colMul2, rowY, colY);
	D = multiply(D, C, W, rowC, colC, rowW, colW);
		
        printArray(D,rowD,colD);

	freeArray(X,rowX);
        freeArray(Y,rowY);
        freeArray(XT, rowXT);
        freeArray(resultOfMul1, rowMul1);
	freeArray(resultOfMul2, rowMul2);
	//freeArray(inverseMatrix, rowInv);
	freeArray(identityMatrix, rowIden);
	freeArray(W, rowW);
	freeArray(C, rowC);
	freeArray(D, rowD);
	return 0;
}
