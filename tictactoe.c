#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int x,y;
char p1[30], p2[30];
int game[3][3] = {
        {225,225,225},
        {225,225,225},
        {225,225,225}
    };

void refresh(){
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            game[i][j]=225;
        }
        
    }
    
}
void print_array(){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char c = (char)game[i][j];
            printf("%c \t",c);
        }
        printf("\n");
    }
}

void player1(){
    printf("Player of current turn : %s \n",p1);
    pp1:printf("choose a row number (0 to 2): ");
    scanf("%d",&x);
    if((x>2)||(x<0)){
        printf("%d is not a valid row.");
        goto pp1;
    }
    pp2:printf("Choose a column number (0 to 2) : ");
    scanf("%d",&y);
    if((y>2)||(y<0)){
        printf("%d is not a valid row.");
        goto pp2;
    }
    if(game[x][y]==225){
        game[x][y] = 88;
    }
    else
    {
        printf("The space is occupied please try again.");
        goto pp1;
    }
    print_array();
}
void player2(){
    printf("Player of current turn : %s \n",p2);
    p21:printf("choose a row number (0 to 2): ");
    scanf("%d",&x);
    if((x>2)||(x<0)){
        printf("%d is not a valid row.");
        goto p21;
    }
    p22:printf("Choose a column number (0 to 2) : ");
    scanf("%d",&y);
    if((y>2)||(y<0)){
        printf("%d is not a valid row. \n");
        goto p22;
    }
    if(game[x][y]==225){
        game[x][y] = 79;
    }
    else
    {
        printf("The space is occupied please try again. \n");
        goto p21;
    }
    print_array();
}

void bot(){
    printf("Player of current turn : Bot \n");
    int a;
    srand(time(0));
    bot2:a = rand();
    if (a>10)
    {
        a = a%10;
        while (a>3)
        {
            a = a/2;
        }
        
    }
    else
    {
        while (a>3)
        {
            a = a/2;
        }
        
    }
    if(a>2){
        a = a - 1;
        x = a;
    }
    else
    {
        x = a; 
    }
    srand(time(0));
    a = rand();
    if (a>10)
    {
        a = a%10;
        while (a>3)
        {
            a = a/2;
        }
        
    }
    else
    {
        while (a>3)
        {
            a = a/2;
        }
        
    }
    if(a>2){
        a = a - 1;
        y = a;
    }
    if(game[x][y]==225){
        game[x][y] = 79;
    }
    else
    {
        goto bot2;
    }
    print_array();
}

int check(){
    if((game[0][0]==game[0][1])&&(game[0][1]==game[0][2])&&(game[0][0]!=225)){
        if(game[0][0]==88){
        return 1;
        }
        if(game[0][0]==79)
        {
            return 2;
        }
    }
    else if((game[1][0]==game[1][1])&&(game[1][1]==game[1][2])&&(game[1][0]!=225)){
        if(game[1][0]==88){
        return 1;
        }
        else
        {
            return 2;
        }
    }
    else if((game[2][0]==game[2][1])&&(game[2][1]==game[2][2])&&(game[2][0]!=225)){
        if(game[2][0]==88){
        return 1;
        }
        else
        {
            return 2;
        }
    }
    else if((game[0][0]==game[1][1])&&(game[1][1]==game[2][2])&&(game[0][0]!=225)){
        if(game[0][0]==88){
        return 1;
        }
        else
        {
            return 2;
        }
    }
    else if((game[0][2]==game[1][1])&&(game[1][1]==game[2][0])&&(game[0][2]!=225)){
        if(game[0][2]==88){
        return 1;
        }
        else
        {
            return 2;
        }
    }
     else if((game[0][0]==game[1][0])&&(game[1][0]==game[2][0])&&(game[0][0]!=225)){
        if(game[0][0]==88){
        return 1;
        }
        else
        {
            return 2;
        }
    }
     else if((game[0][1]==game[1][1])&&(game[1][1]==game[2][1])&&(game[0][1]!=225)){
        if(game[0][1]==88){
        return 1;
        }
        else
        {
            return 2;
        }
    }
    else if((game[0][2]==game[1][2])&&(game[1][2]==game[2][2])&&(game[0][2]!=225)){
       if(game[0][2]==88){
        return 1;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        return 0; 
    }
    
}

int main(){
    int x = 0, ch = 3, o;
    char a[30] , p[1];
    pa:printf("Select the mode you want to play : \n 1. Player vs Player \n 2. Player vs Bot \n");
    printf("Enter your choice : ");
    scanf("%d",&o);
    while ((getchar()) != '\n');
    refresh();
    if (o==2)
    {
       printf("Enter a name for the player : \n");
       gets(p1);
       bot1:printf("Do you want to play first (y or n) : ");
       gets(p2);
       if (p2[0]=='y')
       {
           player1();
           for (int k = 0; k < 4; k++)
           {
               bot();
               player1();
               if(k==1||k==2||k==3){
                   ch = check();
               }
               if(ch==1){
                   printf("The player %s has Won.\n",p1);
                   break;
               }
               if(ch==2){
                   printf("The Bot has won.\n");
                   break;
               }
           }
           if(ch==0){
               printf("The game was a tie.\n");
           }
           printf("Do you want to play again (Y/N): \n");
           scanf("%s",p);
           if(p[0]=='Y'){
               goto pa;
           }
           else
           {
               printf("Have a good day.\n");
               return 0;
           }
       }

       else if(p2[0]=='n'){
           bot();
           for (int k = 0; k < 4; k++)
           {
               player1();
               bot();
               if(k==1||k==2||k==3){
                   ch = check();
               }
               if(ch==1){
                   printf("The player %s has Won.\n",p1);
                   break;
               }
               if(ch==2){
                   printf("The Bot has won.\n");
                   break;
               }
           }
            if(ch==0){
               printf("The game was a tie.\n");
           }
           printf("Do you want to play again (Y/N): ");
           scanf("%s",p);
           if(p[0]=='Y'){
               goto pa;
           }
           else
           {
               printf("Have a good day.\n");
               return 0;
           }
           
        }
    }
    else{
    printf("Enter a name for the X player : \n");
    gets(p1);
    printf("Enter the name for the O player : \n");
    gets(p2);
    g1:printf("Who plays first %s or %s ? \n",p1,p2);
    gets(a);
    if(strcmp(p1,a)==0){
        x = 1;
    }
    else if(strcmp(p2,a)==0){
        x = 2;
    }
    else
    {
        printf("%s is not a registered player. \n",a);
        goto g1;
    }
    print_array();
    if(x==1){
        player1();
        for(int k = 0; k<4; k++){
            player2();
            player1();
            if(k==1||k==2||k==3){
                ch = check();
            }
            if(ch==1){
                printf("The player %s has won.\n",p1);
                break;
            }
            if(ch==2){
                printf("The player %s has won.\n",p2);
                break;
            }
        }
        if(ch==0){
            printf("The game was tie.\n");
        }
        printf("Do you want to play again (Y/N) :");
        scanf("%s",p);
        if(p[0]=='Y'){
               goto pa;
           }
           else
           {
               printf("Have a good day.\n");
               return 0;
           }
    }
    else{
        player2();
        for (int k = 0; k < 4; k++)
        {
            player1();
            player2();
            if(k==1||k==2||k==3){
                ch = check();
            }
            if(ch==1){
                printf("The %s player has won.\n",p1);
                break;
            }
            if(ch==2){
                printf("The %s player has won.\n",p2);
                break;
            }
        }
        if (ch==0)
        {
            printf("The game was tie.\n");
        }
        printf("Do you want to play again (Y/N) : ");
        scanf("%s",p);
        if(p[0]=='Y'){
               goto pa;
           }
           else
           {
               printf("Have a good day.\n");
               return 0;
           }
    }
    }
}