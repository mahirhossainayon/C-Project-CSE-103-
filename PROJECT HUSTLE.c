#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include <signal.h>
#include <conio.h>

char signupin(char userName[],char password[]);
char request();
void addList(char list[100][20], int size);
void remo(char list[100][20], int size);
void printLists(char list[100][20], int size);
void quitlist();
void calculator();
void consoleDelete();
void countdown();
void pomodoro();
void bre(int timehb,int timemb);
void cgpaCounter();

int main() {
    char list[100][20];
    int size = 0;
    char userName[30],password[30];
    signupin(userName,password);
    printf("\n\t\t\t\t\t\t%s\t\t\t\t\t\t", "~~LET'S START~~ \n");
    printf("\n");
    do {
        char req = request();
        if (req == 'a') {
            addList(list,size);
            size++;
            continue;
        }
        if (req == 'd') {
            remo(list,size);
            size--;
            continue;
        }
        else if (req == 'l') {
            printLists(list, size);
            continue;
        }
        else if (req == 'q') {
            quitlist();
            break;
        }
        else if (req == 'c') {
            calculator();
            continue;
        }
        else if (req == 's') {
            consoleDelete();
            continue;
        }
         else if (req == 't') {
            countdown();
            continue;
        }
         else if (req == 'p') {
            pomodoro();
            continue;
        }
        else if (req == 'o') {
            cgpaCounter();
            continue;
        }
        else {
            printf("Your request is invalid \n");
            continue;
        }
    } while (1);

      return 0;
}
char signupin(char userName[],char password[]){
int i =0;
char salt[]="#a$4d+";
char newpass[37];
printf("Enter your username : ");
fgets(userName,30,stdin);
printf("Enter your password : ");
while(1){
char c = getch();
if(c == 13){
    break;
}
password[i++] = c;
printf("*");
}
printf("\nYour Password : ");
strcpy(newpass,password);
strcat(newpass,salt);
puts(newpass);
printf("\n\t\t\t\t\t\t%s\t\t\t\t\t\t", "WELCOME TO HUSTLE \n ");
printf("\n\t\t\t\t\t\t ");
printf(" signing in...");
Sleep(2000);
consoleDelete();
}
char request() {
    char req;
    printf("What is your request? : ");
    scanf(" %c", &req);
    return req;
}

void addList(char list[100][20], int size) {
    if (size < 100) {
        printf("Enter your task to add to the list: ");
        scanf("%s", list[size]);

    } else {
        printf("List is full, cannot add more elements.\n");
    }
}
void remo(char list[100][20], int size){
        int idx;
        printf("index of your done task : ");
        scanf("%d",&idx);
        for (int i= idx-1;i<size;i++){
                for (int j=0;j<21;j++){
            list[i][j]=list[i+1][j];}
        }

}
void printLists(char list[100][20], int size) {
    printf("List contents:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", list[i]);
    }
}

void quitlist() {
    printf("\n\tYou quit. \n\n\n THANK YOU FOR USING HUSTLE \n\n LIFE IS VERY SHORT \n NEVER GIVE UP \n ALWAYS HUSTLE \n\n\nTHIS CODE WAS MADE BY TASMIA TASNIM & MAHIR HOSSAIN AYON....1DEC23 \n");
}
void calculator(){
    char op;
    int a,b;
printf("enter your first value a = ");
scanf("%d",&a);
printf("enter a operator between +,-,*,/ = ");
scanf(" %c",&op);
printf("enter your first value b = ");
scanf("%d",&b);
switch(op){
case '+' : printf("sum = %d \n",a+b);
break;
case '-' : printf("sub = %d \n",a-b);
break;
case '*' : printf("mul = %d \n",a*b);
break;
case '/' : if (b!=0){printf("div = %d \n",a/b);}
           else {printf("b can not be zero");}
break;
case '%' : if (b!=0){printf("mod = %d \n",a%b);}
           else {printf("b can not be zero");}
break;
default : printf ("recheck");
}
}
void consoleDelete(){
 Sleep(2000);
 system("cls");
 printf("\n\t\t\t\t%s\t     HERE IS YOUR HUSTLE APP \n");
 printf(" \n INSTRUCTIONS :\n a = ADD, l = SHOW THE LIST, q = QUIT, d = REMOVE A TASK, c = SIMPLE CALCULATOR, s = CLEAR CONSOLE, o = CHECK YOUR CGPA, t = COUNTDOWN TIMER, p = POMODORO TIMER \n ");//,M

}
void countdown(){

int hour=0,minute=0,second=0,timeh,timem;
printf("Enter Hour Count : ");
scanf("%d",&timeh);
printf("Enter minute Count : ");
scanf("%d",&timem);

do{
    printf("\n\n      *YOUR TIMER IS ON*  \n\n          %02d:%02d:%02d  \n\n      *PRESS Q TO QUIT*  \n\n",hour,minute,second);

        if(second<60){
        Sleep(1000);
        second++;
        system("cls");
        }

        if(second==60){
            minute++;
            second=0;
        }
        else if(minute==60){
            hour++;
            minute=0;
        }
         else if(hour == timeh && minute == timem ){
            second=0;
            minute=0;
            hour=0;
            printf("Your Time is Over \a\n");
            Sleep(3000);
            consoleDelete();
            request();
            break;
        }
        if (_kbhit()) {
            char input = _getch();
            if (input == 'q' || input == 'Q') {
                printf("\nCountdown interrupted. You quit.\n");
                consoleDelete();
                request();
                return;
            }
        }


        }

while(1);
}


void cgpaCounter(){
    printf(" \n\n\n  ");
  int n;
    float number[5][10], credit[5];
    char nameCourse[5][20];
    while (getchar() != '\n');
    printf("Number Of Your Courses : ");
    scanf("%d", &n);
    // Clear input buffer after reading the integer
    while (getchar() != '\n');
    for (int i = 0; i < n; i++) {
        printf("Name of your course %d : ", i + 1);
        fgets(nameCourse[i], sizeof(nameCourse[i]), stdin);
        // Remove the newline character
        nameCourse[i][strcspn(nameCourse[i], "\n")] = '\0';
        printf("Credit of your course %d : ", i + 1);
        scanf("%f", &credit[i]);
        // Clear input buffer after reading the float
        while (getchar() != '\n');
    }
    // step 02
     int i=0;
     float num[n][8],cgpa[n];
     while(i<n){
        printf("%d. MID : ",i+1);
        scanf("%f",&num[i][0]);
        printf("%d. FINAL : ",i+1);
        scanf("%f",&num[i][1]);
        printf("%d. CLASS PERFORMANCE : ",i+1);
        scanf("%f",&num[i][2]);
        printf("%d. SPOKEN PERFORMANCE : ",i+1);
        scanf("%f",&num[i][3]);
        printf("%d. ASSIGNMENT : ",i+1);
        scanf("%f",&num[i][4]);
        printf("%d. QUIZ : ",i+1);
        scanf("%f",&num[i][5]);
        printf("%d. LAB EXAM : ",i+1);
        scanf("%f",&num[i][6]);
        printf("%d. PROJECT : ",i+1);
        scanf("%f",&num[i][7]);
        i++;

        printf("----------------------------\n");
        printf("----------------------------\n");

     }

   //step 03
   int flag=0;
   for(int i=0;i<n;i++){

       float mark=0;
       for(int j=0;j<8;j++){
       mark = mark + num[i][j];}
    if(mark >= 80 && mark <= 100)
    {
        cgpa[i] = 4.0;
    }
    else if(mark >= 75 && mark < 80)
    {
        cgpa[i] = 3.75;
    }
    else if(mark >= 70 && mark < 75)
    {
       cgpa[i] = 3.50;
    }
    else if(mark >= 65 && mark < 70)
    {
        cgpa[i] = 3.25;
    }
    else if(mark >= 60 && mark < 65)
    {
        cgpa[i] = 3.00;
    }
    else if(mark >= 55 && mark < 60)
    {
         cgpa[i] = 2.75;
    }
else if(mark >= 50 && mark < 55)
    {
        cgpa[i] = 2.50;
    }
    else if(mark >= 45 && mark < 50)
    {
         cgpa[i] = 2.25;
    }
    else if(mark >= 40 && mark < 45)
    {
         cgpa[i] = 2.00;
    }
    else if(mark >=0 && mark < 40)
    {
        printf("YOU HAVE FAILED IN COURSE %d \n",i+1);
        cgpa[i] =0.00;
    }
    else
    {
        printf("YOUR GRADE IS INVALID FOR %d \n",i+1);
        cgpa[i] =0.00;

    }
     }

   // step 04
    float total = 0;
    float totalCredits = 0;

    for (int i = 0; i < n; i++) {
        total += credit[i] * cgpa[i];
        totalCredits += credit[i];
    }

    for (int i = 0; i < n; i++) {
        printf("CGPA for %s: %.2f\n", nameCourse[i], cgpa[i]);
    }
    printf("YOUR CGPA : %.2f\n", (total / totalCredits));}



void pomodoro(){
int hour=0,minute=0,second=0,timeh,timem;
printf("Enter Work Hour Count : ");
scanf("%d",&timeh);
printf("Enter Work minute Count : ");
scanf("%d",&timem);
int timehb,timemb;
printf("Enter Break Hour Count : ");
scanf("%d",&timehb);
printf("Enter Break minute Count : ");
scanf("%d",&timemb);
do{
    printf("\n\n      *YOUR TIMER IS ON*  \n\n          %02d:%02d:%02d  \n\n      *PRESS Q TO QUIT*  \n\n",hour,minute,second);

        if(second<60){
        Sleep(1000);
        second++;
        system("cls");
        }
        if(second==60){
            minute++;
            second=0;
        }
        else if(minute==60){
            hour++;
            minute=0;
        }
         else if(hour == timeh && minute == timem ){
            second=0;
            minute=0;
            hour=0;
            printf("Your Time is Over \a\n");
           bre(timehb,timemb);
            break;
        }
         if (_kbhit()) {
            char input = _getch();
            if (input == 'q' || input == 'Q') {
                printf("\nCountdown interrupted. You quit.\n");
                consoleDelete();
                request();
                return;
            }


        }}
while(1);
}


void bre(int timehb,int timemb){
    int hourb=0,minuteb=0,secondb=0;
    do{
    printf("\n\n      *YOUR BREAK IS ON*  \n\n          %02d:%02d:%02d  \n\n      *PRESS Q TO QUIT*  \n\n",hourb,minuteb,secondb);

        if(secondb<60){
        Sleep(1000);
        secondb++;
        system("cls");
        }

        if(secondb==60){
            minuteb++;
            secondb=0;
        }
        else if(minuteb==60){
            hourb++;
            minuteb=0;
        }
         else if(hourb == timehb && minuteb == timemb ){
            secondb=0;
            minuteb=0;
            hourb=0;
            printf("Your Break is Over \a\n");
            Sleep(3000);
            consoleDelete();
            request();
            break;
        }
         if (_kbhit()) {
            char input = _getch();
            if (input == 'q' || input == 'Q') {
                printf("\nCountdown interrupted. You quit.\n");
                consoleDelete();
                request();
                return;
            }

    }}
   while(1);
}








