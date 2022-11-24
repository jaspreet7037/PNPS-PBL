#include <stdio.h>
#include <conio.h>
#include <string.h>

#define ESC 27
#define F1 59
#define F2 60

void signup(void);
void login(void);


struct
{
	char password[20];
	char username[20];
}s;

FILE *fp;

void main()
{
    int ch;
    while(1)
    {
        clrscr();
        gotoxy(20,5);
        printf("___________________________________CODE EXPRESS____________________________________");
        gotoxy(28,7);
        printf("Yours Welcome Here......");
        gotoxy(28,9);
        printf("Press F1 for Login");
        gotoxy(28,11);
        printf("Press F2 for Signup");
        gotoxy(28,13);
        printf("Press ESC for Exit");
        gotoxy(20,15);
        printf("_____________________________*_*_*_*_*_*_*_*_*_*_*_*_*_____________________________");
        getch();
        ch=getch();
        switch(ch)
        {
	        case F1:
	        clrscr();
	        gotoxy(10,14);
	        for(int i=0;i<40;i++)
            {
                printf("_");
                sleep(40);
            }
            login();
            break;
            case F2:
            clrscr();
            gotoxy(10,14);
            for(int i=0;i<40;i++)
            {
                printf("_");
                delay(40);
            }
            signup();
            break;
            case ESC:
            exit(0);
            break;
        }
    }
    getch();
}

//login function
void login()
{
    int c,i;
    char username[20];
    char pass[20];
    char chkp;
    char chku;
    clrscr();
    gotoxy(23,5);
    printf("_______Login Zone______");
    gotoxy(23,7);
    fp=fopen("record.bin","rb");
    printf("Enter Your Username : ");
    gets(username);
    gotoxy(23,9);
    printf("Enter Password : ");
    for(i=0;c=getch()!=13;i++)
    {
        pass[i]=c;
        printf("*");
    }
    pass[i]='\0';
    while(!feof(fp))
    {
        fread(&s,sizeof(s),1,fp);
        chku=strcmp(username,s.username);
        chkp=strcmp(pass,s.password);
        if(chku==0&&chkp!=0)
        {
            printf("Invalid password!!!!!!!!!!!!");
            break;
        }
        else if(chku!=0&&chkp==0)
        {
            printf("\n\tInvalid Username!!!!!!!!");
            break;
        }
        else if(chku==0&&chkp==0)
        {
            clrscr();
            gotoxy(20,10);
            printf("_Hello %s Welcome Here_ ",s.username);
            break;
        }
    }
    getch();
}

//signup function
void signup()
{
    int i;
    char c;
    fp=fopen("record.bin","ab");
    clrscr();
    gotoxy(23,5);
    printf("______________SignUp Page______________");
    gotoxy(23,7);
    printf("Set UserName : ");
    gets(s.username);
    gotoxy(23,9);
    printf("Set Password : ");
    for(i=0;c=getche()!=13;i++)
    {
        s.password[i]=c;
    }
    gotoxy(23,11);
    printf("Press Enter to Continue : ");
    if(getch()==13)
    {
        fwrite(&s,sizeof(s),1,fp);
        gotoxy(23,13);
        cprintf("\nInformations Saved.....");
    }
    else
    return;
    fclose(fp);

    getch();
}

