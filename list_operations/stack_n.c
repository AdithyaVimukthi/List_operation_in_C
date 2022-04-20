#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node *nlink;
};

struct node*head = NULL;

void push();
void pop();
void display();

int main() {
    int cmd;

    while(cmd !=99){
        printf("\n");
		printf("Add Node(Push) ----------- 1");
		printf("\n");
		printf("Delete top Node(Pop) ----- 2");
		printf("\n");
		printf("Print list --------------- 3");
		printf("\n");

        printf("\n");
		printf("Exit the programe press - 99 ");
		printf("\n");

        printf("Give command number : ");
    	scanf("%d", &cmd);
		printf("\n");


        if(cmd==1){
			push(); 	
			printf("\n");
		}else if(cmd==2){
			pop(); 	
			printf("\n");
		}else if(cmd==3){
			display();
			printf("\n");
		}
        
    }
    return 0;
}


void push()
{
    int data;

    printf("\nEnter new value : ");	    //Ask for new value
    scanf("%d", &data);
    printf("\n");

    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    
    if(head == NULL){
        newNode->nlink = NULL;
    }else{
        newNode->nlink = head;
    }
        
    head = newNode;

    printf("\nInsertion is Success!!!\n");
}

void pop()
{
    int val;
    if(head == NULL)
        printf("\nList is Empty!!!\n");
    else{
        struct node *temp = head;
        temp->data = val;
        printf("\nDeleted top node: %d",val);
        head = temp->nlink;
        free(temp);
    }
}

void display()
{
   if(head == NULL)
      printf("\nList is Empty!!!\n");
   else{
      struct node *temp = head;
      while(temp != NULL){
        printf("| %d |",(*temp).data);	//Print the node data part
		printf(" %p |",(*temp).nlink);	//Print the next node address
		temp=(*temp).nlink;				//go to next node
		if(temp != NULL){				//Arrow printing mechanism
			printf(" --> ");
		}else{
			printf(" - End of the List -");
		}
      }
   }
}