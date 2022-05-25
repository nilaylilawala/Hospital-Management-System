#include<stdio.h>
#include<string.h>

//structure
struct patient
{
    char name[30];
    char disease[30];
    int cabin,phone,age;
}
person[100];

int n,i,sum=0,g,flag,num;
void read();
void add();
void view();
void search();
void edit();
void del();
void show();

int main()
{
    read();
    int c,i,q;
    printf("\t\t\t\t\t---Hospital Management System---\n");

    //making out the pattern
    int j;
    for(j=1;j<=5;j++)
    {
        if(j==3)
            printf("\t\t\t\t\t\t\t*********");
        else
            printf("\t\t\t\t\t\t\t    *");
        printf("\n");
    }
    while(c!=6)
    {

        printf("*Enter your choice*\n\n1. Add New Patient Record\n2. View Details Of Existing Patient Record\n3. Search\n4. Edit Patient's Records\n5. Delete Patient's Record\n6. Exit\n");
        printf("\nOption = ");
        scanf("%d",&c); //option
        getchar();//to clear a newline character in buffer.

        //using switch
        switch (c)
        {
            case 1://add
                system("cls");
                add();
                break;

            case 2://view
                system("cls");
                view();
                break;

            case 3://search
                system("cls");
                search();
                break;

            case 4://edit
                system("cls");
                edit();
                break;

            case 5://delete
                system("cls");
                del();
                break;

            case 6://exit
                write();
                return 0;
                break;

            default:
                printf("\n---Invalid input, Try again by using valid inputs---");
        }
        printf("\n\n");
    }
}
void add()
{
    printf("\n\n");
    printf("Existing Entries : %d\n\n",num);
    printf("How many entry do you want to add : ");
    scanf("%d",&n);
    getchar(); //to clear a newline character in buffer.
    sum=n+num;

    for(i=num; i<sum; i++)
    {
        printf("Enter patient's Name = ");
        gets(person[i].name);
        printf("Enter disease = ");
        gets(person[i].disease);
        printf("Enter the age = ");
        scanf("%d",&person[i].age);
        getchar();//to clear a newline character in buffer.
        printf("Enter cabin no = ");
        scanf("%d",&person[i].cabin);
        getchar();//to clear a newline character in buffer.
        printf("Enter phone number = ");
        scanf("%d",&person[i].phone);
        getchar();//to clear a newline character in buffer.
        printf("\n");
        num++;
    }
}
void view()
{
    for(i=0; i<num; i++)
    {
        printf("\n");
        printf("---Serial Number=%d---\n",i+1);
        printf("Name = ");
        puts(person[i].name);
        printf("Disease = ");
        puts(person[i].disease);
        printf("Age = %d\nCabin no. = 0%d\nPhone no.=%d",person[i].age,person[i].cabin,person[i].phone);
        printf("\n");
        for(int x=0; x<21; x++)
            printf("-");
    }
}
void edit()
{
    int q,p;
    printf("What do you want to edit ?\n");
    printf("1.Name\n2.Disease\n3.Age\n4.Cabin no.\n5.Phone no.\n");
    printf("Enter your Option = ");
    scanf("%d",&q);//option
    getchar();
    if(q<=5)
    {
        printf("\n\nEnter the serial no. of that patient = ");
        scanf("%d",&p);//serial number
        getchar();
        p -= 1;
        if(p<num)
        {
            if(q==1)
            {
                printf("\nEnter the new Name = ");
                gets(person[p].name);
                printf("\n---Name has been successfully changed---");
            }
            else if(q==2)
            {
                printf("Enter the new Disease = ");
                gets(person[p].disease);
                printf("\n---Disease has been successfully changed---");
            }
            else if(q==3)
            {
                printf("Enter the new Age = ");
                scanf("%d",&person[p].age);
                printf("\n---Age has been successfully changed---");
            }
            else if(q==4)
            {
                printf("Enter the new Cabin no=");
                scanf("%d",&person[p].cabin);
                printf("\n---Cabin no. has been successfully changed---");
            }
            else if(q==5)
            {
                printf("Enter the new Phone no = ");
                scanf("%d",&person[p].phone);
                printf("\n---Phone no. has been successfully changed---");
            }
        }
        else
        {
            printf("\n\nInvalid Serial no.\nTry Again!!\n\n");
        }
    }
    else
    {
        printf("\n\nInvalid option\nTry Again!!\n\n");
    }
}
void search()
{
    int s, h, cn, pn, ag, flag=1, g=0;
    //pointers
    int *c, *p, *a;
    c = &cn, p = &pn; a = &ag;
    char u[100];
    printf("What do you want to search ?\n");
    printf("1.Serial no.\n2.Name\n3.Disease\n4.Age\n5.Cabin no.\n6.Phone no.\n\nOption = ");
    scanf("%d",&h);
    getchar();
    if(h==1)
    {
        int f=0;
        printf("Enter Serial number of the patient = ");
        scanf("%d",&s);
        getchar();
        s-=1;
        if(s<num)
        {
            printf("\n");
            printf("---Serial Number = %d---\n",s+1);
            printf("Name = ");
            puts(person[s].name);
            printf("Disease = ");
            puts(person[s].disease);
            printf("Cabin no = %d\nPhone number = %d\nAge = %d",person[s].cabin,person[s].phone,person[s].age);
            for(int x=0; x<21; x++)
                printf("-");
            printf("\n\n");
        }
        else
            printf("\n\n!--Not Found--!\n\n");
        flag = 0;
    }
    else if(h==2)
    {
        printf("Enter your name = ");
        gets(u);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,person[g].name)==0)
            {
                goto print; //goto statement
            }
        }
    }
    else if(h==3)
    {
        printf("Enter Disease = ");
        gets(u);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,person[g].disease)==0)
            {
                goto print;
            }
        }
    }
    else if(h==4)
    {
        printf("Enter Age = ");
        scanf("%d",a);
        for(g=0; g<num; g++)
        {
            if(ag==person[g].age)
            {
                goto print;
            }
        }
    }
    else if(h==5)
    {
        printf("Enter Cabin no. = ");
        scanf("%d",c);
        for(g=0; g<num; g++)
        {
            if(cn==person[g].cabin)
            {
                goto print;
            }
        }
    }
    else if(h==6)
    {
        printf("Enter Phone no. = ");
        scanf("%d",p);
        for(g=0; g<num; g++)
        {
            if(pn==person[g].phone)
            {
               goto print;
            }
        }
    }
    else
    {
        printf("\n\n!--Invalid Input--!\n\n");
        flag = 0;
    }

    if(g==num)
    {
        printf("\n\n!--Not Found--!");
        flag = 0;
    }
    if(flag!=0)
    {
        print:
            printf("\n");
            printf("---Serial Number = %d---\n",g+1);
            printf("Name = ");
            puts(person[g].name);
            printf("Disease = ");
            puts(person[g].disease);
            printf("Cabin no = %d\nPhone number = 0%d\nAge = %d",person[g].cabin,person[g].phone,person[g].age);
            printf("\n");
            for(int x=0; x<21; x++)
                printf("-");
            printf("\n\n");
    }
}
void del()
{
    int f,h;
    printf("Enter the serial number of the patient that you want to delete = ");
    scanf("%d",&f);
    f-=1;
    if(f<num)
    {
        printf("What do you want ?\n");
        printf("1.Remove the whole record\n2.Remove Name\n3.Remove Disease\n4.Remove age\n5.Remove Cabin\n6.Remove phone number\nOption = ");
        scanf("%d",&h);
        if(h==1)
        {
            while(f<num)
            {
                strcpy(person[f].name,person[f+1].name);
                strcpy(person[f].disease,person[f+1].disease);
                person[f].age=person[f+1].age;
                person[f].cabin=person[f+1].cabin;
                person[f].phone=person[f+1].phone;
                f++;
            }
            printf("\n---Record deleted Successfully---\n");
            num--; //1 record deleted
        }
        else if(h==2)
        {
            strcpy(person[f].name,"--Deleted--");
            printf("\n---Name deleted Successfully---\n");

        }
        else if(h==3)
        {
            strcpy(person[f].disease,"--Deleted--");
            printf("\n---Disease deleted Successfully---\n");
        }
        else if(h==4)
        {
            person[f].age=0;
            printf("\n---Age deleted Successfully---\n");
        }
        else if(h==5)
        {
            person[f].cabin=0;
            printf("\n---Cabin no. deleted Successfully---\n");

        }
        else if(h==6)
        {
            person[f].phone=0;
            printf("\n---Phone no. deleted Successfully---\n");
        }
    }
    else
        printf("\n\n!--Invalid Serial number--!\n");
}

//file
void read()
{
    FILE *fp = fopen("patient.txt","r");
    num = fread(person, sizeof(struct patient),100, fp);
    fclose(fp);
}
void write()
{
    FILE *fp = fopen("patient.txt","w");
    fwrite(person, sizeof(struct patient),num, fp);
    fclose(fp);
}
