#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;          
    struct node *next;
}*head;
void createList(int n) //creating n nodes
{
    struct node *newNode, *temp;
    int data, i;
    head = (struct node *)malloc(sizeof(struct node));
    if(head == NULL)
    {
        printf("UNABLE TO ALLOCATE MEMORY!");
    }
    else
    {      
        printf("Enter data of node 1: ");
        scanf("%d", &data);

        head->data = data;
        head->next = NULL;  
        temp = head;
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            if(newNode == NULL)
            {
                printf("UNABLE TO ALLOCATE MEMORY!\n");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data;
                newNode->next = NULL;

                temp->next = newNode;
                temp = temp->next;
            }
        }

        printf("LINKEDLIST CREATED\n");
    }
}
void deleteFirstNode() //delete from first
{
    struct node *toDelete;

    if(head == NULL)
    {
        printf("List is already empty!\n");
    }
    else
    {
        toDelete = head;
        head = head->next;

        printf("\nData deleted = %d\n", toDelete->data);

        free(toDelete); //clear memory

        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
}
void deleteLastNode() //delete from end
{
    struct node *toDelete, *secondLastNode;

    if(head == NULL)
    {
        printf("List is already empty.\n");
    }
    else
    {
        toDelete = head;
        secondLastNode = head;

        while(toDelete->next != NULL)
        {
            secondLastNode = toDelete;
            toDelete = toDelete->next;
        }

        if(toDelete == head)
        {
            head = NULL;
        }
        else
        {
            secondLastNode->next = NULL;
        }
        free(toDelete);

        printf("SUCCESSFULLY DELETED LAST NODE OF LIST\n");
    }
}
void deleteNode(int position) //deleting form given position
{
    int i;
    struct node *toDelete, *prevNode;

    if(head == NULL)
    {
        printf("List is already empty!\n");
    }
    else
    {
        toDelete = head;
        prevNode = head;

        for(i=2; i<=position; i++)
        {
            prevNode = toDelete;
            toDelete = toDelete->next;

            if(toDelete == NULL)
                break;
        }

        if(toDelete != NULL)
        {
            if(toDelete == head)
                head = head->next;

            prevNode->next = toDelete->next;
            toDelete->next = NULL;
            free(toDelete);

            printf("SUCCESSFULLY DELETED NODE FROM MIDDLE OF LIST\n");
        }
        else
        {
            printf("Invalid position unable to DELETE.\n");
        }
    }
}

void displayList()
{
    struct node *temp;
    int j=1;
    if(head == NULL)
    {
        printf("List is empty!");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data %d = %d\n",j++, temp->data);
            temp = temp->next;                
        }
    }
}
int main()
{
    int n, choice,pos,ele;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);
    printf("\nData in the list :\n");
    displayList();
    while(1)
{
  printf("-------------------------------------------------\n");
printf("1.DELETE FORM FRONT\n2.DELETE FROM END\n3.DELETE FROM POSITION\n4.DISPLAY LIST\n5.EXIT\n");
printf("Enter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:deleteFirstNode();
displayList();
break;
case 2:deleteLastNode();
displayList();
break;
case 3:printf("Enter the position:\n");
scanf("%d",&pos);
deleteNode(pos);
displayList();
break;
case 4:displayList();
break;
case 5:exit(0);
default : printf("INVAILD CHOICE");
break;
}
}

    return 0;
}