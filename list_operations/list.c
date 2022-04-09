//including libraries
#include <stdio.h>
#include <stdlib.h>

//define the structure of a node
struct node {
    int data;
    struct node* nlink;
};

//Define the functions
struct node* insertdata(int getdata, struct node* hlink);

void printList(struct node* hlink);

void srhnode(struct node* hlink);

int updatenode(struct node* hlink);

void addnode(struct node** head);

void comprenode(struct node* hlink);

void displaynode(struct node* hlink);

int countlistsize(struct node* hlink);

int sortList(struct node* hlink);

void deleteNode(struct node **head);

void removeList(struct node **hlink);

//main function
int main(){
	int cmdint,numofnodes;
	struct node* headp = NULL;  		//Start with empty list
	
	headp = insertdata(123, headp);		//Inserting first five nodes
	headp = insertdata(32, headp);
	headp = insertdata(-5, headp);
	headp = insertdata(123, headp);
	headp = insertdata(-23, headp);

	printf("\n");
	printf("Welcome to linked list");
	printf("\n");
	printf("----------------------");
	printf("\n");

	while (cmdint!=99){
		
		printf("\n");
		printf("Print List ----------- 0");
		printf("\n");
		printf("Search Node ---------- 1");
		printf("\n");
		printf("Update a node -------- 2");
		printf("\n");
		printf("Add a node ----------- 3");
		printf("\n");
		printf("Compere 2 nodes ------ 4");
		printf("\n");
		printf("Display a node ------- 5");
		printf("\n");
		printf("Count the list size -- 6");
		printf("\n");
		printf("Sort the list -------- 7");
		printf("\n");
		printf("Delete a node -------- 8");
		printf("\n");
		printf("Remove the list ------ 9");
		printf("\n");

		printf("\n");
		printf("Exit the programe press - 99 ");
		printf("\n");
		printf("\n");
		printf("Give command number : ");
    	scanf("%d", &cmdint);
		printf("\n");


		if(cmdint==0){
			printList(headp); 	
			printf("\n");
		}else if(cmdint==1){
			srhnode(headp); 	
			printf("\n");
		}else if(cmdint==2){
			updatenode(headp);
			printf("\n");
			printList(headp); 
			printf("\n");
		}else if(cmdint==3){
            addnode(&headp);
			printf("\n");
			printList(headp); 
			printf("\n");
		}else if(cmdint==4){
			comprenode(headp);
			printf("\n");
		}else if(cmdint==5){
			displaynode(headp);
			printf("\n");
		}else if(cmdint==6){
			numofnodes = countlistsize(headp);
            printf("List size is: %d \n",numofnodes);
			printf("\n");
		}else if(cmdint==7){
			sortList(headp);
			printList(headp); 
			printf("\n");
		}else if(cmdint==8){
			deleteNode(&headp);
			printList(headp);
			printf("\n");
		}else if(cmdint==9){
			removeList(&headp);
			printf("\n");
		}else if(cmdint !=99){
			printf("\n");
			printf("Command Not Found.");
			printf("\n");
		}
		printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
		printf("\n");
		printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
		printf("\n");
		printf("\n");

	}
	
	return 0;
}

//Function for create nodes
struct node* insertdata (int getdata, struct node* hlink){
    struct node* loop = NULL; 
    struct node* prev = NULL;

	//Alocating memory for new node
    struct node* newnode = malloc(sizeof(struct node));

	//Assigning value for new node
    (*newnode).data = getdata;
    (*newnode).nlink = NULL;

    if(hlink == NULL){				//If list is empty make the new node as first node
        hlink = newnode; 
    }else{							//If the list has nodes
        loop = hlink;
        while(loop!=NULL){			//Find the last node
            prev = loop;
            loop=(*loop).nlink;
        }
        (*prev).nlink = newnode;	//Add new node as last node
    }
    return hlink;					//Update the list
}

//function for print the list
void printList(struct node* hlink){			
	struct node*loop = NULL;
	loop = hlink;						//Assigning head node
	while(loop!=NULL){
		printf("| %d |",(*loop).data);	//Print the node data part
		printf(" %p |",(*loop).nlink);	//Print the next node address
		loop=(*loop).nlink;				//go to next node
		if(loop != NULL){				//Arrow printing mechanism
			printf(" --> ");
		}else{
			printf(" - End of the List -");
		}
	}
	printf("\n");
}

//Function for search node
void srhnode(struct node* hlink){
	
	int srhval,nodenum,fudornot;			//Creating variables
	struct node*loop = NULL;
	loop = hlink;
	
	printf("Enter a value for search: ");	//Ask searching value from user
    scanf("%d", &srhval);
	printf("\n");

    nodenum,fudornot = 0;
    while(loop!=NULL){
    	nodenum ++;
    	if(srhval == (*loop).data){	
			//Check whether any node value is equal to given search value
			printf("Value found in: %d node ",nodenum);
			printf("\n");
			fudornot = 1;	
		}
		loop=(*loop).nlink;					//Go to next node
	}
	
	if(fudornot == 0){						//Publish the results of search
		printf("Value not found in list.");
	}

	printf("\n");
}

//function for update exsisting node
int updatenode(struct node* hlink){

	int nodenum,upval,getnum;
	struct node*loop = NULL;
	loop = hlink;

    int size = countlistsize(hlink);
	
	printf("Enter updating node number: "); //Get updating node number
    scanf("%d", &getnum);
    if(getnum > size || getnum < 1){
       	printf("\nInvalid node number to update\n");
    }else{
        printf("Enter updating value : ");		//Get updating value
        scanf("%d", &upval);
    
        while(loop!=NULL){		
    	    nodenum ++;
    	    if(nodenum == getnum){		
    		    (*loop).data = upval;			//Updating the node value
    		    break;	
		    }
		    loop=(*loop).nlink;
	
        }
        printf("Node %d value is updated to %d ",getnum,upval);
    
    }
	printf("\n");
	return 0;	
}

//Add node to the list with user input
void addnode(struct node** hlink){   
    int n,data,nodenum,confmint;
	struct node* prev = NULL;

    int size = countlistsize(*hlink);
    // temp used to traverse the Linked List
    struct node* temp = *hlink; 

    printf("Enter position number : "); //Get node numbers
    scanf("%d", &n);

    nodenum = 1;
    // Can't insert if position to insert is greater than size of Linked List
    // can insert after negative pos

    if(n < 0 || n > size){
        printf("\nList has only %d nodes.\nIf you want to add your node to end of the list press 1 : ",size);
		scanf("%d", &confmint);

		if(confmint == 1){
			printf("\nEnter new value : ");	    //Ask for new value
        	scanf("%d", &data);
        	printf("\n");

        	struct node* newNode = malloc(sizeof(struct node));

        	(*newNode).data = data;
        	(*newNode).nlink = NULL;

        	while(temp!=NULL){			//Find the last node
            	prev = temp;
            	temp=(*temp).nlink;
        	}
        	(*prev).nlink = newNode;

		}else{
			printf("\nNode not added to the list.\n");
		}
    } else{
        printf("Enter new value : ");	    //Ask for new value
        scanf("%d", &data);
        printf("\n");

        struct node* newNode = malloc(sizeof(struct node));

        (*newNode).data = data;
        (*newNode).nlink = NULL;

        if(n == 1){                  // inserting first node
            (*newNode).nlink = *hlink; 
            *hlink = newNode;
        }else {
            // traverse till the nth node
            while(nodenum < n-1){
                nodenum++;
                temp=(*temp).nlink;
            }
            // assign newNode's next to nth node's next
            (*newNode).nlink= (*temp).nlink;
            // assign nth node's next to this new node
            (*temp).nlink = newNode;
            // newNode inserted b/w 3rd and 4th node
        }
    } 
}

//Function for compering 2 node values
void comprenode(struct node* hlink){
	int val1, val2, node1, node2, nodenum ; //Creating variables
	struct node*loop = NULL;
	loop = hlink;

    int size = countlistsize(hlink);
	
	printf("Enter node number 1 : "); //Get node numbers
    scanf("%d", &node1);
    if(node1 > size || node1 < 1){
        printf("\nInvalid node number to compare\n");
    }else{
        printf("Enter node number 2 : ");
        scanf("%d", &node2);
        if(node2 > size || node2 < 1){
            printf("\nInvalid node number to compare\n");
        }else{
            nodenum = 0 , val1 = 0, val2 = 0;
            while(loop!=NULL){
    	        nodenum ++;
    	        if(nodenum == node1){			//Assign node values to variables
    		        val1 = (*loop).data;
		        }else if(nodenum == node2){
			        val2 = (*loop).data;
		        }
		        loop=(*loop).nlink;	
	        }
            printf("\n");
	        printf("Node %d value = %d , Node %d value = %d ",node1,val1,node2,val2); 
	        printf("\n");
	        if (val1 > val2){					
    	        printf("Node %d  value is grater than node %d  value ", node1, node2);
	        }else if (val1 == val2){
		        printf("Node %d  value is equals to node %d  value ", node1, node2);
	        }else if (val1 < val2){
		        printf("Node %d  value is lower than node %d  value ", node1, node2);
	        }
        }
    }
	printf("\n");
}

//Function for display single node
void displaynode(struct node* hlink){
	int disnode, nodeval,nodenum;
	struct node*loop = hlink;
	
	int size = countlistsize(hlink);

	printf("Enter node number to display: ");	//Get node number
    scanf("%d", &disnode);
	printf("\n");

	if(disnode > size || disnode < 1){
		printf("\nInvalid node number to display\n");
	}else{
		nodenum = 0;
    	while(loop!=NULL){
    		nodenum ++;
    		if(nodenum == disnode){					//Visit for given node
    			nodeval = (*loop).data;
    			break;	
			}
			loop=(*loop).nlink;	
		}
		printf("Node Vlaue is: %d",nodeval);  //Print the node value
	}
	printf("\n");
}

//Function for count the list size
int countlistsize(struct node* hlink){
	int nodenum;
	struct node*loop = hlink;
	
	while(loop!=NULL){
    	nodenum ++;						//Counting the nodes
		loop=(*loop).nlink;	
	}
	
	// printf("List size is: %d",nodenum);	//Print the results
	// printf("\n");
	return nodenum;
}

int sortList(struct node* hlink) {  
        //Node current will point to head  
        struct node *loop = hlink, *next = NULL, *prev = NULL;  
        int temp,code;  
        
		//Get sorting order
        printf("Sort ascending order (Low to High)  - Enter 1 ");
		printf("\n");
		printf("Sort descending order (High to Low) - Enter 2 ");
		printf("\n");
		printf("Enter command number: ");
    	scanf("%d", &code);
    	
    	if (code == 1){ //Sorting the list to ascending order
    		while(loop != NULL) {  
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
        	
		}else if (code == 2){//Sorting the list to descending order
			while(loop != NULL) {   
            	next = (*loop).nlink;    
            	while(next != NULL) {  
                    //If current node's data is lower than index's node data, swap the data between them  
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
			printf("\nInvalide index!\n"); 
		}
         
    printf("\n");     
    return 0;
}  

//Function for Delete node
void deleteNode(struct node **hlink){
    struct node *temp;
    int val,fudornot;
    struct node *loop  = *hlink;
      
    printf("Enter deleting value : "); //Get deleting value
    scanf("%d", &val);

	fudornot = 0;
    //Move to head node to the next and free the head.
    if((*(*hlink)).data == val)
    {
        temp = *hlink;    //Backup to free the memory
        *hlink = (*(*hlink)).nlink;
        free(temp);
		fudornot = 1;
    }
    else //If deleting middle node or end node
    {
        while((*loop).nlink != NULL)
        {
            if((*(*loop).nlink).data == val)
            {
                temp = (*loop).nlink;
                (*loop).nlink =(*(*loop).nlink).nlink;
                free(temp);
				fudornot = 1;
                break;
            }
            else
                loop = (*loop).nlink;//Go to next node
        }
    }

	if(fudornot == 0){
		printf("\n");
		printf("Node value not found.");
		printf("\n");
	}else if(fudornot == 1){
		printf("\n");
		printf("Node deleted.");
		printf("\n");
	}

	printf("\n");
}

// Function to delete the entire linked list 
void removeList(struct node **hlink){

   struct node* loop = *hlink;
   struct node* nlink;
   int val;

	printf("Press 1 for delete list: "); //Get confirmation for delete list
    scanf("%d", &val);

	if(val == 1){
		while (loop != NULL)
   		{
       		nlink = (*loop).nlink; 		//Deleteing all nodes
       		free(loop);
       		loop = nlink;

   		}
   		*hlink = NULL;
		printf("\n");					//Clear the head node
		printf("List is deleted");
	}
   	
}