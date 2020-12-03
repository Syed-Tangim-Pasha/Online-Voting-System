/*................................STUDENT ASSOCIATION ONLINE VOTING SYSTEM..........................
* 3 CANDIDATES-RAHIM,KARIM,SUMON
* MACHINE SYSTEM PROGRAM
*/
#include<stdio.h>
#include<stdlib.h>
#define n 5        /* DEFINE VOTER NUMBER FOR IDarray SIZE*/

struct Node
{
    int data;
    struct Node *next;
};

/*
*THIS 3 STRUCTURE NODES DECLEARE FOR 3 CANDIDATES TO SEE VOTERS VOTE FOR SPECIFIC CANDIDATES
*BAD SIDES OF USING LINKED LIST
*ONLY FOR ADMIN APPROVAL TO SEE THE LIST
*/

struct Node *head1=NULL;
struct Node *current1=NULL;
struct Node *head2=NULL;
struct Node *current2=NULL;
struct Node *head3=NULL;
struct Node *current3=NULL;

int j=1,k,vote,ID;
double percent,cand1=0.0,cand2=0.0,cand3=0.0; /* * cand1, cand2 AND cand3 ARE 3 CANDIDATES VARIABLES NAME
                                                * percent VARIABLE USE FOR CALCULATING THE PERCENTAGE OF THE VOTE */

/*
*THESE ARE THE FUNCTIONS WHICH CAN ONLY ACCESS BY ADMIN
*THESE FUNCTIONS HELP ADMIN TO SEE THE VOTE OF VOTERS FOR THEIR FAVOURITE CANDIDATES
*/
void CandList1(int );
void CandList2(int );
void CandList3(int );
void ShowList1(struct Node *);
void ShowList2(struct Node *);
void ShowList3(struct Node *);

int WrongSituation(int ID)                      /* THIS IS THE FUNCTION FOR CHECKING ID NUMBER FROM THE LIST OF IDarray OF STUDENT VOTERS */
{
    int IDarray[n]={8631,8632,8633,8634,8635},i;
    for(i=0;i<n;i++){
        if(IDarray[i]==ID)
        {
            return 0;
        }
    }
    return 1;
}

void Voting()                  /* VOTING FUNCTION WHICH WORKS FOR WHOLE VOTING SYSTEM */
{
    printf("\t\t\tWELCOME TO THE  STUDENT ASSOCIATION ONLINE VOTING SYSTEM\n\n");

    do{                         /* *A LOOP WHICH RUNS FOR N TIMES AND N=STUDENT ASSOCIATION VOTERS NUMBER*/
    start:
    printf("\t\t\tCANDIDATE LIST :\n\n");
    printf("\t\t\tCANDIDATE-1:KARIM\n\n");
    printf("\t\t\tCANDIDATE-2:RAHIM\n\n");
    printf("\t\t\tCANDIDATE-3:SUMON\n\n");
    printf("\t\t\tPress 1 or 2 or 3 to voting your favourite Candidate with your ID\n");
    printf("ID NO :\tVOTING NUMBER : \n");

    scanf("%d %d",&ID,&vote);     /* ENTRY STUDENT ID NUMBER AND SPECIFIC FAVOURITE CANDIDATE VOTING NUMBER*/

    while(WrongSituation(ID))     /* CHECKING WHETHER ID IS CORRECT OR NOT*/
    {
        printf("Worng ID,Please Tpye Your ID Correctly\n");
        printf("ID NO :\n");
        scanf("%d",&ID);
    }

    if(vote==1)          /* FIRST CANDIDATE */
    {
        cand1++;
        CandList1(ID);   /* FUNCTION WHERE ID NUMBERS ARE ENTER TO MAKE A LIST FOR FIRST CANDIDATE VOTERS(ADMIN APPROVAL FUNCTION)*/
    }

    else if(vote==2)     /* SECOND CANDIDATE */
    {
        cand2++;
        CandList2(ID);   /* FUNCTION WHERE ID NUMBERS ARE ENTER TO MAKE A LIST FOR SECOND CANDIDATE VOTERS(ADMIN APPROVAL FUNCTION)*/
    }

    else if(vote==3)     /* THIRD CANDIDATE */
    {
        cand3++;
        CandList3(ID);   /* FUNCTION WHERE ID NUMBERS ARE ENTER TO MAKE A LIST FOR THIRD CANDIDATE VOTERS(ADMIN APPROVAL FUNCTION)*/
    }

    percent=(((cand1+cand2+cand3)*100)/n);   /* VALUE OF VOTING PERCENTAGE */

    printf("CANDIDATE-1:KARIM:%d\n",(int)cand1);
    printf("CANDIDATE-2:RAHIM:%d\n",(int)cand2);
    printf("CANDIDATE-3:SUMON:%d\n",(int)cand3);
    printf("Percentage of vote is : %.2lf%%\n",percent);

    if(percent==100.0)
    {
        printf("\t\t\t\t\tThank you for supporting us.\n");
        break;
    }

    else
    {
    printf("Press 1 to continue or 0 to stop\n");    /* ADMIN APPROVAL SECTION,ADMIN CAN EASILY STOP THE VOTING SYSTEM*/
    scanf("%d",&k);

    if(k==0)
    {
        printf("\t\t\t\t\tThank you for supporting us.\n");
               break;
    }

    else if(k==1)
    {
        goto start;
    }
    }
    }while(j<=n);

    ShowList1(head1);
    ShowList2(head2);
    ShowList3(head3);

    return;
}

/* FIRST CANDIDATE VOTERS MAKING LIST THROUGH LINKED LIST */
void CandList1(int id)
{
    struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=id;
    new_node->next=NULL;
    if(head1==NULL)
    {
        head1=new_node;
        current1=new_node;
    }
    else
    {
        current1->next=new_node;
        current1=new_node;
    }
    return;
}

void ShowList1(struct Node *temp)
{
    if(head1==NULL)
    {
        printf("NO ONE VOTE FOR CANDIDATE-1\n\n");
    }
    else{
    printf("CANDIDATE-1 SUPPORTING LIST : ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n\n");
    }
    return;
}

/* SECOND CANDIDATE VOTERS MAKING LIST THROUGH LINKED LIST */
void CandList2(int id)
{
    struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=id;
    new_node->next=NULL;
    if(head2==NULL)
    {
        head2=new_node;
        current2=new_node;
    }
    else
    {
        current2->next=new_node;
        current2=new_node;
    }
    return;
}

void ShowList2(struct Node *temp)
{
    if(head2==NULL)
    {
        printf("NO ONE VOTE FOR CANDIDATE-2\n\n");
    }
    else{
    printf("CANDIDATE-2 SUPPORTING LIST :");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n\n");
    }
    return;
}

/* THIRD CANDIDATE VOTERS MAKING LIST THROUGH LINKED LIST */
void CandList3(int id)
{
    struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=id;
    new_node->next=NULL;
    if(head3==NULL)
    {
        head3=new_node;
        current3=new_node;
    }
    else
    {
        current3->next=new_node;
        current3=new_node;
    }
    return;
}

void ShowList3(struct Node *temp)
{
    if(head3==NULL)
    {
        printf("NO ONE VOTE FOR CANDIDATE-3\n\n");
    }
    else{
    printf("CANDIDATE-3 SUPPORTING LIST :\n");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n\n");
    }
    return;
}

int main()
{
    Voting(); /* VOTING FUNCTION WHICH WORKS FOR WHOLE VOTING SYSTEM */


    return 0;
}
