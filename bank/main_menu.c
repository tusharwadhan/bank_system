#include<stdio.h>
#include<string.h>

struct {
    char user[15];
    char name[50];
    char dob[15];
    char date[15];
    char pass[15];
    char ac[10];
    int bal;
    char no[11];
    char sq[15];
} add3[100],check3;

void atm();
void atmdep();
void atmwid();
void atmbal();
void info();

int j;

void mainMenu(int* ptr3){
    char* a[4]={"(1) ATM Feature","(2) A/C Information","(3) Transactions","(4) EXIT"};
    int choice2;

    j=*ptr3;

    printf("\n\n====================MAIN MENU====================\n\n");

    for(int i=0;i<4;i++){
        printf("\n%s",a[i]);
    }
    printf("\n\n  Enter Choice : ");
    scanf("%d",&choice2);

    switch(choice2){
        case 1:atm();
            break;
        
        case 2:info();
            break;
        
        case 3:printf("\n\n\tcoming soon");
            mainMenu(&j);
            break;

        case 4:exit(1);
            break;

        default:printf("\n\n\tError Choice!!\n\nTry again");
            mainMenu(&j);
    }
}

void atm(){
    char* b[3]={"(1) Deposit money","(2) Withdraw money","(3) Check balance"};
    int choice3,rtn4;
    char another='y';

    for(int i=0;i<3;i++){
        printf("\n\t%s",b[i]);
    }
printf("\n\n\tEnter Choice : ");
scanf("%d",&choice3);

switch(choice3){

    case 1:atmdep();
    break;

    case 2:atmwid();
    break;

    case 3:atmbal();
    break;

    default:printf("\n\tError choice");
}

}
void atmdep(){
    FILE* ptr1,*ptr2;
    char another='y';
    do{
        ptr1=fopen("record.dat","r");
        ptr2=fopen("new.dat","w");
        int i;
        i=0;
            while(fscanf(ptr1,"%s %s %s %s %s %d %s %s %s\n",add3[i].user,add3[i].name,add3[i].dob,add3[i].date,add3[i].ac,&add3[i].bal,add3[i].pass,add3[i].no,add3[i].sq)!=EOF){
                if(i==j){
                    printf("\n\tEnter how much money you want to deposit :$");
                    scanf("%d",&check3.bal);
                    add3[i].bal+=check3.bal;
                    fprintf(ptr2,"%s %s %s %s %s %d %s %s %s\n",add3[i].user,add3[i].name,add3[i].dob,add3[i].date,add3[i].ac,add3[i].bal,add3[i].pass,add3[i].no,add3[i].sq);
                }
                else{
                    fprintf(ptr2,"%s %s %s %s %s %d %s %s %s\n",add3[i].user,add3[i].name,add3[i].dob,add3[i].date,add3[i].ac,add3[i].bal,add3[i].pass,add3[i].no,add3[i].sq);
                    
                }
            i++;
            }
        
    printf("\n\n\tAdded Successfully!");
    printf("\n\tYour balance is => $%d",add3[j].bal);
    printf("\n\n\tWant another deposit transaction(y/n) : ");
        scanf(" %c",&another);
        fclose(ptr1);
        fclose(ptr2);
        remove("record.dat");
        rename("new.dat","record.dat");
}while(another=='y');
mainMenu(&j);
}
void atmwid(){
    FILE* ptr1,*ptr2;
    char another='y';
    do{
         ptr1=fopen("record.dat","r");
        ptr2=fopen("new.dat","w");
        int i;
        i=0;
            while(fscanf(ptr1,"%s %s %s %s %s %d %s %s %s\n",add3[i].user,add3[i].name,add3[i].dob,add3[i].date,add3[i].ac,&add3[i].bal,add3[i].pass,add3[i].no,add3[i].sq)!=EOF){
                if(i==j){
                    printf("\n\n\tEnter how much money you want to withdraw :$");
                    scanf("%d",&check3.bal);
                    if(check3.bal>add3[i].bal){
                        printf("\n\n\tYou dont have enough money to withdraw!!\n\tTransaction failed!!");
                        printf("\n\n\tYour balance is => %d",add3[i].bal);
                        fclose(ptr1);
                        fclose(ptr2);
                        remove("new.dat");
                        atmwid();
                    }
                    add3[i].bal-=check3.bal;
                    fprintf(ptr2,"%s %s %s %s %s %d %s %s %s\n",add3[i].user,add3[i].name,add3[i].dob,add3[i].date,add3[i].ac,add3[i].bal,add3[i].pass,add3[i].no,add3[i].sq);
                }
                else{
                    fprintf(ptr2,"%s %s %s %s %s %d %s %s %s\n",add3[i].user,add3[i].name,add3[i].dob,add3[i].date,add3[i].ac,add3[i].bal,add3[i].pass,add3[i].no,add3[i].sq);
                    
                }
            i++;
            }
    printf("\n\n\tWithdrawn Successfully!");
    printf("\n\tYour balance is => $%d",add3[j].bal);
    printf("\n\n\tWant another deposit transaction(y/n) : ");
        scanf(" %c",&another);
        fclose(ptr1);
        fclose(ptr2);
        remove("record.dat");
        rename("new.dat","record.dat");
}while(another=='y');
mainMenu(&j);
}
void atmbal(){
    int i=0,m;
    FILE* ptr;
    ptr=fopen("record.dat","r");
        while(fscanf(ptr,"%s %s %s %s %s %d %s %s %s\n",add3[i].user,add3[i].name,add3[i].dob,add3[i].date,add3[i].ac,&add3[i].bal,add3[i].pass,add3[i].no,add3[i].sq)!=EOF){
                if(i==j){
                printf("\n\n\tYour balance is => $%d",add3[i].bal);
                break;
                }
            i++;
            }
            printf("\n\n\tenter 0 to continue ");
    scanf("%d",&m);
    mainMenu(&j);
}
void info(){
    int i=0,m;
    FILE* ptr;
    ptr=fopen("record.dat","r");
        while(fscanf(ptr,"%s %s %s %s %s %d %s %s %s\n",add3[i].user,add3[i].name,add3[i].dob,add3[i].date,add3[i].ac,&add3[i].bal,add3[i].pass,add3[i].no,add3[i].sq)!=EOF){
            if(i==j){
                printf("\n\tUsername => %10s",add3[i].user);
                printf("\n\tName => %10s",add3[i].name);
                printf("\n\tDate of birth => %10s",add3[i].dob);
                printf("\n\tDate of registration => %10s",add3[i].date);
                printf("\n\tAccount No. => %10s",add3[i].ac);
                printf("\n\tMobile No. => %10s",add3[i].no);
                break;
            }
          i++;  
        }
    printf("\n\n\tEnter 0 to continue ");
    scanf("%d",&m);
mainMenu(&j);
}