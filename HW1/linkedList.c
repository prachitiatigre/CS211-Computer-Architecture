#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
        int data;
        struct Node* next;
};
 
 
struct Node* newNode(int data)
{
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
}
struct Node* printList(struct Node* head)
{
        //printf("Inside print\n");

        if( head == NULL){
                //printf("List is empty \n");
                return 0;
	}

        struct Node* ptr = head;

        while (ptr != NULL)
        {
                int number = ptr->data;
                printf("%d\t", number);
                ptr = ptr->next;
        }
        return 0;
}
//Add to the beginning of the Linked List & then sort the Linked List
struct Node* insert(struct Node *head, int num)
{
        //printf("\n");
        //printf("When you enter insert method,value of num\t%d\n",num);
 
        struct Node *newAdd = newNode(num);
 
        if(head == NULL)
        {
                //printf("Inside head == Null\n");
 
                //head = malloc(sizeof(struct Node));
                head = newAdd;
                //head->data = num;
                //head->next = NULL;
 
                //printf("First entry\t%d\n",head->data);
 
                //struct Node *newAdd = newNode(num);
                //return head;
        }
 
        else
        {
                newAdd->data = num;
                newAdd->next = head;
                head = newAdd;
 
                //printf("Value of newAdd data\t%d\n",newAdd->data);
        }
 
        return head;
        //free(head);
        //free(newAdd);
}
void sort(struct Node *head)
{
        int swapped;
        struct Node *ptr1;
        struct Node *lptr = NULL;
 
        if (head == NULL)
                return;
 
        do
        {
                swapped = 0;
                ptr1 = head;
 
                while (ptr1->next != lptr)
                {
                        if (ptr1->data > ptr1->next->data)
                        {
                                int temp = ptr1->data;
                                ptr1->data = ptr1->next->data;
                                ptr1->next->data = temp;
 
                                swapped = 1;
                        }
                        ptr1 = ptr1->next;
                }
                lptr = ptr1;
        }
        while (swapped);
}
struct Node* delete(struct Node *head, int num)
{
        //printf("Inside delete\t%d\n",num);
        struct Node* prev = NULL;

	struct Node* curr;


        if(head != NULL){
		curr = head;

		while(curr != NULL){
			//printf("Temp %d",curr->data);
			if(curr->data == num){

				if(prev == NULL){//This will happen when first node is a match
					if(curr->next == NULL)
					{
						free(curr);
						return NULL;
					}
					else
					{
						struct Node* temp;
						temp = curr->next;
						free(curr);
						return temp;
					}
				}
				prev->next = curr->next;
				free(curr);
				break;
			}
			else{
				prev=curr;
				curr = curr->next;
			}
		}
	}
	return head;
}

void freeTheNode(struct Node *head)
{
        struct Node *ptr = head;
 
        while (ptr!=NULL)
        {
              struct Node* next = ptr->next;
                free(ptr);
              ptr = next;
                //ptr = head;
        }
}

/*
struct Node* printList(struct Node* head)
{
        //printf("Inside print\n");
 
        if( head == NULL)
                //printf("End\n");
                return 0;
 
        struct Node* ptr = head;
 
        while (ptr != NULL)
        {
                int number = ptr->data;
                printf("%d\t", number);
                ptr = ptr->next;
        }
        return 0;
}*/
void removeDuplicates(struct Node* head)
{
        struct Node* current = head;
        struct Node* deleteNext;
 
        if (current == NULL)
                return;
 
        while (current->next != NULL)
        {
                if (current->data == current->next->data)
                {
                        deleteNext = current->next->next;
                        free(current->next);
                        current->next = deleteNext;
                }
                else
                {
                        current = current->next;
                }
        }
}
 
struct Node* getCount(struct Node* head)
{
    int count = 0;
    struct Node* current = head;
 
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    printf("%d\n",count);
        return 0;
}
int main(int argc, char** argv)
{
        struct Node *head = NULL;
 
        if (argc != 2){
        return 0;
        }
 
        FILE *fp = fopen(argv[1], "r");
        char action;
        int num;
 
        if (fp== NULL)
        {
                printf("error\n");
                return 0;
        }
 
 
        while(1)
        {
                int n = fscanf(fp, "%c\t%d\n", &action, &num);
                if(n != 2)
                {
                        break;
                }
                else
                {
                        if(action == 'i')
                        {
				//printf("Inserting %d\n",num);
                                head = insert(head,num);
				//printf("List after inserting:");
				//printList(head);
				//printf("\n");
                                sort(head);
                        }
 
                        else if(action == 'd')
                        {
				//printf("Deleting %d\n",num);
                                sort(head);
                                head = delete(head, num);
				//printf("List after deleting:");
				//printList(head);
				//printf("\n");
                        }
                        else
                        {
                                printf("error");
                                return 0;
                        }
                }
        }
 
        if(!feof(fp))
        {
                printf("error");
                return 0;
        }
 
        fclose(fp);
        getCount(head);
        removeDuplicates(head);
        printList(head);
        freeTheNode(head);
        return 0;
}

