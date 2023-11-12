#include <stdio.h>
#include <stdlib.h>
#define CAMEROON 1
#define DEUTSCHLAND 2
#define TOGO 3
#define FRANCE 4
#define BRAZIL 5

int datumPruefer(int day, int month, int year);

int main(){

    int day, month, year, country;
    do {
        printf("geben sie ein Datum  und eine Zahl zwischen 1 und 5 so ein: day month year zahl \n");
        scanf("%d %d %d %d", &day, &month, &year , &country);

    } while (!datumPruefer(day,month,year) );

    if(country==CAMEROON){
        printf("das Datum ist : %d-%d-%d CAMEROON" ,year,month,day);
    }
    else if(country==DEUTSCHLAND){
        printf("Das Datum ist : %d.%d.%d DEUTSCHLAND",day,month,year);
    }
    else if(country==TOGO){
        printf("Das Datum ist : %d/%d/%d  TOGO",month,day,year);
    }
    else if(country==FRANCE){
        printf("Das Datum ist : %d-%d-%d FRANCE",year,month,day);
    }
    else if (country == BRAZIL){
        printf("Das Datum ist : %d/%d/%d BRAZIL", day, month, year);
    } else{
        printf("Das Datum ist : %d.%d.%d (keine spezifische Sprache)",day,month,year);
    }

    return 0;

}
int ist_schaltjahr(int year){
    return (year%4==0 && !year%100==0) || year%400==0;
}

int datumPruefer(int day, int month, int year){
    if (day < 1 || month< 1  || month > 12|| year < 0){
        return 0;
    }
    // die Monate die 0 als erstes, damit man direkt mit dem monat zugreifen kann
    int months[] = { 0 ,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (ist_schaltjahr(year)){
        months[2] += 1;
    }
    return day <= months[month];
}



