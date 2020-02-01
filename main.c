#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<mmsystem.h>
int mus=0;
void SetColor(int ForgC)
{
     WORD wColor;
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
int main()
{
    SetColor(9);
    hidecursor();
    system("cls");
    start:
	printf("                                                                                             \n");
    int cd=4;
    boun(3,4,113,26,5,'$');
    SetColor(13);
    gotoxy(23,13);
    printf("W    W    W   EEEEEE   L        CCCCCC   OOOOOO   MM         MM   EEEEEE\n");
    gotoxy(23,14);
    printf("W   W W   W   E        L        C        O    O   M  M      M M   E     \n");
    gotoxy(23,15);
    printf("W  W   W  W   EEEEEE   L        C        O    O   M   M    M  M   EEEEEE\n");
    gotoxy(23,16);
    printf("W W     W W   E        L        C        O    O   M    M  M   M   E     \n");
    gotoxy(23,17);
    printf("WW       WW   EEEEEE   LLLLLL   CCCCCC   OOOOOO   M     M     M   EEEEEE\n");
    delay(1000);
    gotoxy(50,19);
    printf("GATHERING RESOURCES");
    delay(2000);
    gotoxy(50,19);
    printf("                                ");
    gotoxy(50,19);
    printf("BUILDING GRID    ");
    gotoxy(46,19);
    delay(2000);
    printf("   SETTING UP MUSIC    ");
    delay(2000);
    gotoxy(46,19);
    printf("                              ");
    gotoxy(50,19);
    printf("    ALL SET               ");
    while(cd!=-1)
    {
        gotoxy(51,20);
        printf("Starting in %d",cd);
        if(cd==0)
        {
            delay(500);
            goto s1;
        }
        delay(1000);
        cd--;
    }
    s1:
    system("cls");
    int offset=0;
    gotoxy(57,0);
    SetColor(9);
    printf("TIC TAC TOE");
    gotoxy(50,1);
    printf("Developed by VAIBHAV BAHL");
    char ch,name[10],name1[10],con,p1s,p2s,str[6],un;
    PlaySound(TEXT("Converted Audio\\bbb.wav"),NULL,SND_ASYNC);
    gotoxy(0,3);
    name2:
    gotoxy(0,3);
    printf("Enter name of player 1 : ");
    ch=fgetc(stdin);
    if(ch=='\n')goto name2;
    while(ch!='\n')
    {
        name[offset]=ch;
        offset++;
        ch=fgetc(stdin);
    }
    name[offset]='\0';
    name3:
    gotoxy(0,4);
    printf("Enter name of player 2 : ");
    ch=fgetc(stdin);
    offset=0;
    if(ch=='\n')goto name3;
    while(ch!='\n')
    {
        name1[offset]=ch;
        offset++;
        ch=fgetc(stdin);
    }
    name1[offset]='\0';
    n3:
    gotoxy(0,5);
    fflush(stdin);
    printf("                                ");
    gotoxy(0,5);
    printf("%s enter ur symbol : ",name);
    ch=fgetc(stdin);
    if(ch=='\n') goto n3;
    offset=0;
    while(ch!='\n')
    {
        str[offset++]=ch;
        ch=fgetc(stdin);
    }
    if(offset==1)
    {
        p1s=str[0];
    }
    else
    {
        gotoxy(0,7);
        printf("Enter one character ");
        delay(1000);
        gotoxy(0,7);
        printf("                       ");
        goto n3;
    }
    fflush(stdin);
    symb:
    gotoxy(0,6);
    printf("                                           ");
    gotoxy(0,6);
    offset=0;
    fflush(stdin);
    while(name1[offset]!='\0')
    {
        printf("%c",name1[offset]);
        offset++;
    }
    printf(" enter ur symbol : ");
    ch=fgetc(stdin);
    if(ch=='\n') goto symb;
    offset=0;
    while(ch!='\n')
    {
        str[offset++]=ch;
        ch=fgetc(stdin);
    }
    if(offset==1)
    {
        p2s=str[0];
    }
    else
    {
        gotoxy(0,7);
        printf("Enter one character ");
        delay(1000);
        gotoxy(0,7);
        printf("                       ");
        goto symb;
    }
    fflush(stdin);
    if(p1s==p2s)
    {
        gotoxy(0,7);
        printf("Entered symbol is taken by %s so take another symbol",name);
        delay(2000);
        gotoxy(0,7);
        printf("                                                                 ");
        goto symb;
    }
    gotoxy(0,9);
    printf("%s is assigned %c",name,p1s);
    gotoxy(0,10);
    printf("%s is assigned %c",name1,p2s);
    gotoxy(0,17);
    printf("\n%s goes first",name);
    gotoxy(0,12);
    printf("Enter R to restart the game");
    start1:
    gotoxy(0,21);
    printf("                             ");
    gotoxy(0,13);
    printf("Enter E to exit the game\nEnter U to undo last move\nEnter M to change music");
    gotoxy(52,2);
    printf("LET THE GAME BEGIN!!!");
    int j=0,i=0,top=5,left=58,count=1,count1=1,p1,p2,lp1=0,lp2=0,u1=0,u2=0;
    int arr[10]={0};
    int choice;
    int array[10]={0};
    p1=1;
    p2=0;
    while(top<16)
    {
        gotoxy(left,top);
        printf("!!");
        top++;
    }
    top=5,left=68;
    while(top<16)
    {
        gotoxy(left,top);
        printf("!!");
        top++;
    }
    top=8,left=49;
    while(left<78)
    {
        gotoxy(left,top);
        printf("!");
        left++;
    }
    top=12,left=49;
    while(left<78)
    {
        gotoxy(left,top);
        printf("!");
        left++;
    }
    count=1;
    top=6,left=53;
    while(top!=15)
    {
        while(count1!=4)
        {
            gotoxy(left,top);
            printf("%d",count);
            count1++;
            count++;
            left=left+10;
        }
        left=53;
        top=10;
        count1=1;
        while(count1!=4)
        {
            gotoxy(left,top);
            printf("%d",count);
            count1++;
            count++;
            left=left+10;
        }
        count1=1;
        left=53;
        top=14;
        while(count1!=4)
        {
            gotoxy(left,top);
            printf("%d",count);
            count1++;
            count++;
            left=left+10;
        }
        top++;
    }
    count=1;
    count1=0;
    cont:
    gotoxy(0,19);
    printf("ALL THE BEST");
    while(count1<5)
    {
        if(p1==1)
        {
            valid:
            gotoxy(0,21);
            printf("                                         ");
            fflush(stdin);
            gotoxy(0,21);
            printf("%s enter ur choice : ",name);
            ch=fgetc(stdin);
            if(ch=='\n') goto valid;
            offset=0;
            while(ch!='\n')
            {
                str[offset++]=ch;
                ch=fgetc(stdin);
            }
            if(offset==1)
            {
                ch=str[0];
            }
            else
            {
                gotoxy(0,23);
                printf("Enter one character ");
                delay(1000);
                gotoxy(0,23);
                printf("                       ");
                goto valid;
            }
            if(ch=='r' || ch=='R')
                {
                co:
                gotoxy(0,23);
                printf("Are u sure u really want to restart the game ?\n");
                printf("Enter Y to confirm Or enter N to continue\n");
                fflush(stdin);
                scanf("%c",&con);
                if(con=='y' || con=='Y')
                {
                    gotoxy(0,23);
                    printf("                                                         \n");
                    printf("                                                         \n");
                    printf("                                                         \n");
                    goto start1;
                }
                else if(con=='n' || con=='N')
                {
                    gotoxy(0,21);
                    printf("                                  ");
                    gotoxy(0,23);
                    printf("                                                         \n");
                    printf("                                                         \n");
                    printf("                                                         \n");
                    goto cont;
                }
                else
                {
                    gotoxy(0,25);
                    printf("        ");
                    gotoxy(0,26);
                    printf("Enter valid input");
                    delay(1000);
                    gotoxy(0,26);
                    printf("                 ");
                    goto co;
                }
            }
            else if(ch=='e' || ch=='E')
            {
                co3:
                gotoxy(0,23);
                printf("Are u sure u really want to exit the game ?\n");
                printf("Enter Y to confirm or enter N to continue\n");
                fflush(stdin);
                scanf("%c",&con);
                if(con=='y' || con=='Y')
                {
                    gotoxy(0,23);
                    printf("                                                         \n");
                    printf("                                                         \n");
                    printf("                                                         \n");
                    goto end;
                }
                else if(con=='n' || con=='N')
                {
                    gotoxy(0,21);
                    printf("                                  ");
                    gotoxy(0,23);
                    printf("                                                         \n");
                    printf("                                                         \n");
                    printf("                                                         \n");
                    goto cont;
                }
                else
                {
                    gotoxy(0,25);
                    printf("        ");
                    gotoxy(0,26);
                    printf("Enter valid input");
                    delay(1000);
                    gotoxy(0,26);
                    printf("                 ");
                    goto co3;
                }
            }
            else if(ch=='m' || ch=='M')
            {
                mus1:
                gotoxy(0,23);
                printf("Enter 1 for Get Down\n");
                printf("Enter 2 for Riddim\n");
                printf("Enter 3 for King Drop\n");
                printf("Enter 4 for Origin\n");
                printf("Enter 5 for Latency\n");
                scanf("%d",&mus);
                switch(mus)
                {
                    case 1:
                    {
                        PlaySound(TEXT("Converted Audio\\GD.wav"),NULL,SND_ASYNC);
                        break;
                    }
                    case 2:
                    {
                        PlaySound(TEXT("Converted Audio\\Mr.wav"),NULL,SND_ASYNC);
                        break;
                    }
                    case 3:
                    {
                        PlaySound(TEXT("Converted Audio\\Kb.wav"),NULL,SND_ASYNC);
                        break;
                    }
                    case 4:
                    {
                        PlaySound(TEXT("Converted Audio\\Mo.wav"),NULL,SND_ASYNC);
                        break;
                    }
                    case 5:
                    {
                        PlaySound(TEXT("Converted Audio\\La.wav"),NULL,SND_ASYNC);
                        break;
                    }
                    default:
                        {
                            gotoxy(0,22);
                            printf("Enter valid input");
                            delay(1000);
                            gotoxy(0,22);
                            printf("                                ");
                            goto mus1;
                        }
                }
                gotoxy(0,23);
                printf("                                        \n");
                printf("                                        \n");
                printf("                                        \n");
                printf("                                        \n");
                printf("                                        \n");
                printf("                                        \n");
                printf("                                        \n");
                gotoxy(0,21);
                printf("                                        \n");
                goto valid;
            }
            fflush(stdin);
            if((ch>='1')&&(ch<='9'))
            {
                if(array[ch-48]==0)
                {
                    array[ch-48]=1;
                    gotoxy(0,21);
                    arr[ch-48]=1;
                    lp1=ch-48;
            switch(ch)
            {
            case '1':
                {
                    left=53,top=6;
                    gotoxy(left,top);
                    printf("%c",p1s);
                    break;
                }
            case '2':
                {
                    left=63,top=6;
                    gotoxy(left,top);
                    printf("%c",p1s);
                    break;
                }
            case '3':
                {
                    left=73,top=6;
                    gotoxy(left,top);
                    printf("%c",p1s);
                    break;
                }
            case '4':
                {
                    left=53,top=10;
                    gotoxy(left,top);
                    printf("%c",p1s);
                    break;
                }
            case '5':
                {
                    left=63,top=10;
                    gotoxy(left,top);
                    printf("%c",p1s);
                    break;
                }
            case '6':
                {
                    left=73,top=10;
                    gotoxy(left,top);
                    printf("%c",p1s);
                    break;
                }
            case '7':
                {
                    left=53,top=14;
                    gotoxy(left,top);
                    printf("%c",p1s);
                    break;
                }
            case '8':
                {
                    left=63,top=14;
                    gotoxy(left,top);
                    printf("%c",p1s);
                    break;
                }
            case '9':
                {
                    left=73,top=14;
                    gotoxy(left,top);
                    printf("%c",p1s);
                    break;
                }
            }
                }
                else
                    {
                        gotoxy(0,21);
                        printf("                         ");
                        gotoxy(0,23);
                        printf("Enter valid Option");
                        delay(1000);
                        gotoxy(0,23);
                        printf("                   ");
                        goto valid;
                    }
            gotoxy(0,21);
            printf("                                                   \n");
            }
            else
            {
                gotoxy(0,23);
                printf("Enter valid option");
                delay(1000);
                gotoxy(0,23);
                printf("                  ");
                goto valid;
            }
        }
        re:
        if(arr[1]==arr[2] && arr[2]==arr[3] && arr[3]==1)
        {
            i=1;
            goto res;
        }
        else if(arr[4]==arr[5] && arr[5]==arr[6] && arr[6]==1)
        {
            i=1;
            goto res;
        }
        else if(arr[7]==arr[8] && arr[8]==arr[9] && arr[9]==1)
        {
            i=1;
            goto res;
        }
        else if(arr[1]==arr[4] && arr[4]==arr[7] && arr[7]==1)
        {
            i=1;
            goto res;
        }
        else if(arr[2]==arr[5] && arr[5]==arr[8] && arr[8]==1)
        {
            i=1;
            goto res;
        }
        else if(arr[3]==arr[6] && arr[6]==arr[9] && arr[9]==1)
        {
            i=1;
            goto res;
        }
        else if(arr[1]==arr[5] && arr[5]==arr[9] && arr[9]==1)
        {
            i=1;
            goto res;
        }
        else if(arr[3]==arr[5] && arr[5]==arr[7] && arr[7]==1)
        {
            i=1;
            goto res;
        }
        else
        {
        }
        if(u1==0)
        {
            gotoxy(0,23);
            printf("If u want to undo press u : ");
            scanf("%c",&un);
            gotoxy(0,23);
            printf("                                              ");
            if(un=='u' || un=='U')
            {
                u1++;
                arr[lp1]=0;
                array[lp1]=0;
                gotoxy(0,21);
                printf("                                 ");
                switch(lp1)
                {
                    case 1:
                    {
                        gotoxy(53,6);
                        printf("1");
                        break;
                    }
                    case 2:
                    {
                        gotoxy(63,6);
                        printf("2");
                        break;
                    }
                    case 3:
                    {
                        gotoxy(73,6);
                        printf("3");
                        break;
                    }
                    case 4:
                    {
                        gotoxy(53,10);
                        printf("4");
                        break;
                    }
                    case 5:
                    {
                        gotoxy(63,10);
                        printf("5");
                        break;
                    }
                    case 6:
                    {
                        gotoxy(73,10);
                        printf("6");
                        break;
                    }
                    case 7:
                    {
                        gotoxy(53,14);
                        printf("7");
                        break;
                    }
                    case 8:
                    {
                        gotoxy(63,14);
                        printf("8");
                        break;
                    }
                    case 9:
                    {
                        gotoxy(73,14);
                        printf("9");
                        break;
                    }
                }
                 goto valid;
            }
            else
            {
                //goto re;
            }
        }
        p1=0;
        p2=1;
        cont1:
        if(count1==4)break;
        if(p2==1)
        {
            valid1:
            gotoxy(0,21);
            fflush(stdin);
            printf("                                  ");
            gotoxy(0,21);

            printf("%s enter ur choice : ",name1);
            ch=fgetc(stdin);
            if(ch=='\n') goto valid1;
            offset=0;
            while(ch!='\n')
            {
                str[offset++]=ch;
                ch=fgetc(stdin);
            }
            if(offset==1)
            {
                ch=str[0];
            }
            else
            {
                gotoxy(0,23);
                printf("Enter one character ");
                delay(1000);
                gotoxy(0,23);
                printf("                       ");
                goto valid1;
            }
            if(ch=='r' || ch=='R')
            {
                co1:
                gotoxy(0,23);
                printf("Are u sure u really want to restart the game ?\n");
                printf("Enter Y to confirm or enter N to continue\n");
                fflush(stdin);
                scanf("%c",&con);
                if(con=='y' || con=='Y')
                {
                    gotoxy(0,23);
                    printf("                                                         \n");
                    printf("                                                         \n");
                    printf("                                                         \n");
                    goto start1;
                }
                else if(con=='n' || con=='N')
                {
                    gotoxy(0,21);
                    printf("                                  ");
                    gotoxy(0,23);
                    printf("                                                         \n");
                    printf("                                                         \n");
                    printf("                                                         \n");
                    goto cont1;
                }
                else
                {
                    gotoxy(0,25);
                    printf("        ");
                    gotoxy(0,26);
                    printf("Enter valid input");
                    delay(1000);
                    gotoxy(0,26);
                    printf("                 ");
                    goto co1;
                }
            }
            else if(ch=='e' || ch=='E')
            {
                co2:
                gotoxy(0,23);
                printf("Are u sure u really want to exit the game ?\n");
                printf("Enter Y to confirm or enter N to continue\n");
                fflush(stdin);
                scanf("%c",&con);
                if(con=='y' || con=='Y')
                {
                    gotoxy(0,23);
                    printf("                                                         \n");
                    printf("                                                         \n");
                    printf("                                                         \n");
                    goto end;
                }
                else if(con=='n' || con=='N')
                {
                    gotoxy(0,21);
                    printf("                                  ");
                    gotoxy(0,23);
                    printf("                                                         \n");
                    printf("                                                         \n");
                    printf("                                                         \n");
                    goto cont1;
                }
                else
                {
                    gotoxy(0,25);
                    printf("        ");
                    gotoxy(0,26);
                    printf("Enter valid input");
                    delay(1000);
                    gotoxy(0,26);
                    printf("                 ");
                    goto co2;
                }
            }
            else if(ch=='m' || ch=='M')
            {
                mus2:
                gotoxy(0,23);
                printf("Enter 1 for Get Down\n");
                printf("Enter 2 for Riddim\n");
                printf("Enter 3 for King Drop\n");
                printf("Enter 4 for Origin\n");
                printf("Enter 5 for Latency\n");
                scanf("%d",&mus);
                switch(mus)
                {
                    case 1:
                    {
                        PlaySound(TEXT("Converted Audio\\GD.wav"),NULL,SND_ASYNC);
                        break;
                    }
                    case 2:
                    {
                        PlaySound(TEXT("Converted Audio\\Mr.wav"),NULL,SND_ASYNC);
                        break;
                    }
                    case 3:
                    {
                        PlaySound(TEXT("Converted Audio\\Kb.wav"),NULL,SND_ASYNC);
                        break;
                    }
                    case 4:
                    {
                        PlaySound(TEXT("Converted Audio\\Mo.wav"),NULL,SND_ASYNC);
                        break;
                    }
                    case 5:
                    {
                        PlaySound(TEXT("Converted Audio\\La.wav"),NULL,SND_ASYNC);
                        break;
                    }
                    default:
                        {
                            gotoxy(0,22);
                            printf("Enter valid input");
                            delay(1000);
                            gotoxy(0,22);
                            printf("                                ");
                            goto mus2;
                        }
                }
                gotoxy(0,23);
                printf("                                        \n");
                printf("                                        \n");
                printf("                                        \n");
                printf("                                        \n");
                printf("                                        \n");
                printf("                                        \n");
                printf("                                        \n");
                gotoxy(0,21);
                printf("                                        \n");
                goto valid1;
            }
            fflush(stdin);
            if((ch>='1')&&(ch<='9'))
            {
                 if(array[ch-48]==0)
                {
                    array[ch-48]=1;
                    gotoxy(0,21);
                    arr[ch-48]=2;
                    lp2=ch-48;
            switch(ch)
            {
            case '1':
                {
                    left=53,top=6;
                    gotoxy(left,top);
                    printf("%c",p2s);
                    break;
                }
            case '2':
                {
                    left=63,top=6;
                    gotoxy(left,top);
                    printf("%c",p2s);
                    break;
                }
            case '3':
                {
                    left=73,top=6;
                    gotoxy(left,top);
                    printf("%c",p2s);
                    break;
                }
            case '4':
                {
                    left=53,top=10;
                    gotoxy(left,top);
                    printf("%c",p2s);
                    break;
                }
            case '5':
                {
                    left=63,top=10;
                    gotoxy(left,top);
                    printf("%c",p2s);
                    break;
                }
            case '6':
                {
                    left=73,top=10;
                    gotoxy(left,top);
                    printf("%c",p2s);
                    break;
                }
            case '7':
                {
                    left=53,top=14;
                    gotoxy(left,top);
                    printf("%c",p2s);
                    break;
                }
            case '8':
                {
                    left=63,top=14;
                    gotoxy(left,top);
                    printf("%c",p2s);
                    break;
                }
            case '9':
                {
                    left=73,top=14;
                    gotoxy(left,top);
                    printf("%c",p2s);
                    break;
                }
            }
                }
                else
                {
                    gotoxy(0,21);
                    printf("                         ");
                    gotoxy(0,23);
                    printf("Enter valid option");
                    delay(1000);
                    gotoxy(0,23);
                    printf("                   ");
                    goto valid1;
                }
            gotoxy(0,21);
            printf("                                                   \n");
            }
            else
            {
                gotoxy(0,23);
                printf("Enter valid option");
                delay(1000);
                gotoxy(0,23);
                printf("                   ");
                goto valid1;
            }
        p1=1;
        p2=0;
        }
        re1:
        if(arr[1]==arr[2] && arr[2]==arr[3] && arr[3]==2)
        {
            j=1;
            goto res;
        }
        else if(arr[4]==arr[5] && arr[5]==arr[6] && arr[6]==2)
        {
            j=1;
            goto res;
        }
        else if(arr[7]==arr[8] && arr[8]==arr[9] && arr[9]==2)
        {
            j=1;
            goto res;
        }
        else if(arr[1]==arr[4] && arr[4]==arr[7] && arr[7]==2)
        {
            j=1;
            goto res;
        }
        else if(arr[2]==arr[5] && arr[5]==arr[8] && arr[8]==2)
        {
            j=1;
            goto res;
        }
        else if(arr[3]==arr[6] && arr[6]==arr[9] && arr[9]==2)
        {
            j=1;
            goto res;
        }
        else if(arr[1]==arr[5] && arr[5]==arr[9] && arr[9]==2)
        {
            j=1;
            goto res;
        }
        else if(arr[3]==arr[5] && arr[5]==arr[7] && arr[7]==2)
        {
            j=1;
            goto res;
        }
        else
        {
        }
        if(u2==0)
        {
            gotoxy(0,23);
            printf("If u want to undo press u : ");
            scanf("%c",&un);
            gotoxy(0,23);
            printf("                                              ");
            if(un=='u' || un=='U')
            {
                u2++;
                arr[lp2]=0;
                array[lp2]=0;
                gotoxy(0,21);
                printf("                                 ");
                switch(lp2)
                {
                    case 1:
                    {
                        gotoxy(53,6);
                        printf("1");
                        break;
                    }
                    case 2:
                    {
                        gotoxy(63,6);
                        printf("2");
                        break;
                    }
                    case 3:
                    {
                        gotoxy(73,6);
                        printf("3");
                        break;
                    }
                    case 4:
                    {
                        gotoxy(53,10);
                        printf("4");
                        break;
                    }
                    case 5:
                    {
                        gotoxy(63,10);
                        printf("5");
                        break;
                    }
                    case 6:
                    {
                        gotoxy(73,10);
                        printf("6");
                        break;
                    }
                    case 7:
                    {
                        gotoxy(53,14);
                        printf("7");
                        break;
                    }
                    case 8:
                    {
                        gotoxy(63,14);
                        printf("8");
                        break;
                    }
                    case 9:
                    {
                        gotoxy(73,14);
                        printf("9");
                        break;
                    }
                }
                 goto valid1;
            }
            else
            {
                //goto re1;
            }
        }
        count1++;
    }
    res:
    if(i==1)
    {
        gotoxy(0,22);
        printf("\nCongo %s u are the winner\n",name);
    }
    else if(j==1)
    {
        gotoxy(0,22);
        printf("\nCongo %s u are the winner\n",name1);
    }
    else if(count1==4)
    {
        gotoxy(0,22);
        printf("\nGame is Draw\n\n");
    }
    else
    {
    }
    now:
    gotoxy(0,25);
    printf("If u want to play again enter Y else N\n");
    fflush(stdin);
    scanf("%c",&ch);
    if(ch=='Y' || ch=='y')
    {
        u1=0;
        u2=0;
        system("cls");
        gotoxy(53,13);
        printf("Restarting");
        gotoxy(53,14);
        printf("Please wait");
        delay(2000);
        system("cls");
         goto s1;
    }
    else if(ch=='N' || ch=='n')
    {
        end:
        printf("Thanks for playing\n");
    }
    else
    {
        gotoxy(0,25);
        printf("If u want to play again enter Y else N");
        gotoxy(0,26);
        printf("Enter valid input");
        delay(1000);
        gotoxy(0,26);
        printf("                 ");
        goto now;
    }
    return 0;
}
void boun(int left,int top,int left1,int top1,int del,char ch)
{
    int temp;
    temp=left;
    while(temp<left1)
    {
        gotoxy(temp,top);
        printf("%c",ch);
        delay(del);
        temp++;
    }
    temp=top;
    while(temp<top1)
    {
        gotoxy(left1,temp);
        printf("%c",ch);
        delay(del);
        temp++;
    }
    temp=left1;
    while(temp>left)
    {
        gotoxy(temp,top1);
        printf("%c",ch);
        delay(del);
        temp--;
    }
    temp=top1;
    while(temp>top)
    {
        gotoxy(left,temp);
        printf("%c",ch);
        delay(del);
        temp--;
    }
}
