#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* nlink;
};

struct node* insertdata(int getdata, struct node* hlink);

void printList(struct node* hlink);

void srhnode(struct node* hlink);

int updatenode(struct node* hlink);

int addnode(struct node* hlink);

void comprenode(struct node* hlink);

void displaynode(struct node* hlink);

int countlistsize(struct node* hlink);

int sortList(struct node* hlink);

void deleteNode(struct node **head);

void removeList(struct node **hlink);

int main(){
	struct node* headp = NULL;
	
	headp = insertdata(12, headp);
	headp = insertdata(32, headp);
	headp = insertdata(-5, headp);
	headp = insertdata(123, headp);
	headp = insertdata(-23, headp);
	
	printList(headp);
	printf("\n");
	//srhnode(headp);
	
	//updatenode(headp);
	//printList(headp);
	//countlistsize(headp);
	//addnode(headp);
	deleteNode(&headp);
	printList(headp);
	printf("\n");
	
	removeList(&headp);
	//sortList(headp);
	printList(headp);
	printf("\n");
	
	//comprenode(headp);
	//displaynode(headp);
	
	return 0;
}


struct node* insertdata (int getdata, struct node* hlink){
    struct node* loop = NULL;
    struct node* prev = NULL;

    struct node* newnode = malloc(sizeof(struct node));

    (*newnode).data = getdata;
    (*newnode).nlink = NULL;

    if(hlink == NULL){
        hlink = newnode;
    }else{
        loop = hlink;
        while(loop!=NULL){
            prev = loop;
            loop=(*loop).nlink;
        }
        (*prev).nlink = newnode;
    }
    return hlink;
}

void printList(struct node* hlink){
	struct node*loop = NULL;
	loop = hlink;
	while(loop!=NULL){
		printf("| %d |",(*loop).data);
		printf(" %p |",(*loop).nlink);
		loop=(*loop).nlink;
		if(loop != NULL){
			printf(" --> ");
		}else{
			printf(" - End of the List -");
		}
	}
	printf("\n");
}

void srhnode(struct node* hlink){
	int srhval,nodenum,fudornot;
	struct node*loop = NULL;
	loop = hlink;
	
	printf("Enter a value for search: ");
    scanf("%d", &srhval);
    
    while(loop!=NULL){
    	nodenum ++;
    	if(srhval == (*loop).data){
    		fudornot = 1;
    		break;	
		}
		loop=(*loop).nlink;	
	}
	
	if(fudornot == 1){
		printf("Value found in: %d node ",nodenum);
	}else{
		printf("Value not found in list.");
	}
	printf("\n");
}

int updatenode(struct node* hlink){
	int nodenum,upval,getnum,fudornot;
	struct node*loop = NULL;
	loop = hlink;
	
	printf("Enter updating node number: ");
    scanf("%d", &getnum);
    
    printf("Enter updating value : ");
    scanf("%d", &upval);
    
    while(loop!=NULL){
    	nodenum ++;
    	if(nodenum == getnum){
    		(*loop).data = upval;
    		fudornot = 1;
    		break;	
		}
		loop=(*loop).nlink;	
	}
	if(fudornot == 1){
		printf("Node %d value is updated to %d ",getnum,upval);
	}else{
		printf("Node is not found");
	}
	printf("\n");
	return 0;	
}

int addnode(struct node* hlink){
	int newval;
	
	printf("Enter new value : ");
    scanf("%d", &newval);
    
    struct node* loop = NULL;
    struct node* prev = NULL;

    struct node* newnode = malloc(sizeof(struct node));

    (*newnode).data = newval;
    (*newnode).nlink = NULL;

    if(hlink == NULL){
        hlink = newnode;
    }else{
        loop = hlink;
        while(loop!=NULL){
            prev = loop;
            loop=(*loop).nlink;
        }
        (*prev).nlink = newnode;
    }
    return 0;
}

void comprenode(struct node* hlink){
	int val1, val2, node1, node2, nodenum;
	struct node*loop = NULL;
	loop = hlink;
	
	printf("Enter node number 1 : ");
    scanf("%d", &node1);
    
    printf("Enter node number 2 : ");
    scanf("%d", &node2);
    
    while(loop!=NULL){
    	nodenum ++;
    	if(nodenum == node1){
    		val1 = (*loop).data;
		}else if(nodenum == node2){
			val2 = (*loop).data;
		}
		loop=(*loop).nlink;	
	}
    if (val1 > val2){
    	printf("%d Node value is grater than %d node value ", node1, node2);
	}else if (val1 == val2){
		printf("%d Node value is equals to %d node value ", node1, node2);
	}else{
		printf("%d Node value is lower than %d node value ", node1, node2);
	}
}

void displaynode(struct node* hlink){
	int disnode, nodeval,nodenum;
	struct node*loop = hlink;
	
	printf("Enter node number to display: ");
    scanf("%d", &disnode);
    
    while(loop!=NULL){
    	nodenum ++;
    	if(nodenum == disnode){
    		nodeval = (*loop).data;
    		printf("Node Vlaue is: %d",nodeval);
    		break;	
		}
		loop=(*loop).nlink;	
	}
	printf("\n");
}

int countlistsize(struct node* hlink){
	int nodenum;
	struct node*loop = hlink;
	
	while(loop!=NULL){
    	nodenum ++;
		loop=(*loop).nlink;	
	}
	
	printf("List size is: %d",nodenum);
	printf("\n");
	
	return nodenum;
}

int sortList(struct node* hlink) {  
        //Node current will point to head  
        struct node *loop = hlink, *next = NULL, *prev = NULL;  
        int temp,code;  
          
        printf("Sort Low to High - Enter 1 , Sort High to Low - Enter 2 : ");
    	scanf("%d", &code);
    	
    	if (code == 1){
    		
    		while(loop != NULL) {  
                //Node index will point to node next to current  
            	next = (*loop).nlink;    
            	while(next != NULL) {  
                    //If current node's data is greater than index's node data, swap the data between them  
                	if((*loop).data > (*next).data) {  
                    	temp = (*loop).data;  
                    	(*loop).data = (*next).data;  
                    	(*next).data = temp;  
                	}  
                	next = (*next).nlink;  
            	}  
            	loop = (*loop).nlink;  
        	} 
        	
		}else if (code == 2){
			
			while(loop != NULL) {  
                //Node index will point to node next to current  
            	next = (*loop).nlink;    
            	while(next != NULL) {  
                    //If current node's data is greater than index's node data, swap the data between them  
                	if((*loop).data < (*next).data) {  
                    	temp = (*loop).data;  
                    	(*loop).data = (*next).data;  
                    	(*next).data = temp;  
                	}  
                	next = (*next).nlink;  
            	}  
            	loop = (*loop).nlink;  
        	} 
			
		}else {
			printf("Invalide index!");
		}
         
         printf("\n");     
        return 0;
    }  

void deleteNode(struct node **hlink){
      //temp is used to freeing the memory
      struct node *temp;
      int val;
      struct node *loop  = *hlink;
      
      printf("Enter deleting value : ");
      scanf("%d", &val);

      //key found on the head node.
      //move to head node to the next and free the head.
      if((*(*hlink)).data == val)
      {
          temp = *hlink;    //backup to free the memory
          *hlink = (*(*hlink)).nlink;
          free(temp);
      }
      else
      {
          while((*loop).nlink != NULL)
          {
              //if yes, we need to delete the current->next node
              if((*(*loop).nlink).data == val)
              {
                  temp = loop->nlink;
                  //node will be disconnected from the linked list.
                  (*loop).nlink =(*(*loop).nlink).nlink;
                  free(temp);
                  break;
              }
              //Otherwise, move the current node and proceed
              else
                  loop = (*loop).nlink;
          }
      }
}

/* Function to delete the entire linked list */
void removeList(struct node **hlink){
   /* deref head_ref to get the real head */
   struct node* loop = *hlink;
   struct node* nlink;
 
   while (loop != NULL)
   {
       nlink = (*loop).nlink;
       free(loop);
       loop = nlink;
   }
   
   /* deref head_ref to affect the real head back
      in the caller. */
   *hlink = NULL;
}

