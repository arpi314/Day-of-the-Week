#include<stdio.h>

int numDay(int, int, int);
int leapYear(int);
int day(int, int, int);
void dayOfWeek(int);
void suffix(int);
int main(){

    int year, date, month, a, b, c;
    
    //gets input from users
    do{
        printf("Year: ");
        scanf("%i", &year);

    }while(year > 9999 || year < 1000); 

    do{
        printf("Month: ");
        scanf("%i", &month);
    }while(month > 12 || month < 1);

    do{
        printf("Day: ");
        scanf("%i", &date);
    }while(date > 31 || date < 1 );

    //calling functions
    a = leapYear(year);

    b = numDay(month, date, a);

    c = day(date, month, year);

    dayOfWeek(c);

    suffix(b);

    return 0;
}


//whether the year is a leap year or not
int leapYear(int a){
    int x = 0;

    if(a%4 == 0 || a%400 == 0){
        x = 1;
    }else if(a%100 == 0){
        x = 0;
    }

    return x;
}

//number of days within the year
int numDay(int a, int b, int c){
    int x = 0, i;

    if(a == 1){
        x = b;
    }else{
        for(i = 1; i < a; i++){
            if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12 ){
                x = x + 31;
            }else if(i == 2 && c == 1){
                x = x + 29;
            }else if(i == 2 && c == 0){
                x = x + 28;
            }else if(i == 4 || i == 6 || i == 9 || i == 11){
                x = x + 30;
            }
        }
    }

    x = x + b;

    return x;
}

//determines the day of the week.
int day(int a, int b, int c){

    int x;

    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; 
    c -= b < 3; 
    x = ( c + c/4 - c/100 + c/400 + t[b-1] + a) % 7;

    return x; 
}

//outputs word form of the day of the week from day() function.
void dayOfWeek(int c){
    if(c == 0){
        printf("Sun, ");
    }else if(c == 1){
        printf("Mon, ");
    }else if(c == 2){
        printf("Tue, ");
    }else if(c == 3){
        printf("Wed, ");
    }else if(c == 4){
        printf("Thu, ");
    }else if(c == 5){
        printf("Fri, ");
    }else if(c == 6){
        printf("Sat, ");
    }
}

//inserts the appropriate suffixes for the number from the numDay() function.
void suffix(int b){

    int x;

    x = b%10;
    if(b != 11 && x == 1){
        printf("%ist day of the year.", b);
    }else if(b != 12 && x == 2){
        printf("%ind day of the year.", b);
    }else if(b != 13 && x == 3){
        printf("%ird day of the year.", b);
    }else{
        printf("%ith day of the year.", b);
    }

}
