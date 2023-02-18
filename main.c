#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct flat
{
    int floor;
    int number;
    char family[100];
};

#include "headder.h"

struct flat
{
    int floor;
    int number;
    char family[100];
};

int input_check()
{
    int val;
    while (scanf("%d", &val) != 1 || getchar()!='\n') {
        printf("Wrong! Try again.\n");
        rewind(stdin);
    }
    return val;
}

void input_struct(struct flat *skyscraper, int n)
{
    for (int i=0; i<n; i++) {
        printf("Enter the floor: ");
        skyscraper[i].floor=input_check();
        printf("Enter the number of flat: ");
        skyscraper[i].number=input_check();
        printf("Enter the last name of the family that lives in flat: ");
        scanf("%s", &skyscraper[i].family);
    }
}

void typeSort(struct flat *skyscraper, int n)
{
    int t=1;
    while (t!=0) {
        printf("\nPress the button. \nIf you want to sort by floor - 1, by number - 2, by family - 3, if you don't want to sort - 0: ");
        fflush(stdin);
        scanf("%d", &t);
        if (t==1 || t==2 || t==3) {sortBuble(skyscraper, t, n);}
    }
}

void output(struct flat *skyscraper, int n)
{
    //printf("\nInformations about flat: \n");
    for (int i=0; i<n; i++) {
        printf("%d. family: %s, floor: %d, number: %d; \n", i+1, skyscraper[i].family, skyscraper[i].floor, skyscraper[i].number);
    }
}

void sortBuble(struct flat *skyscraper, int t, int n)
{
    struct flat tmp;

    for (int i=n-1; i>=0; i--) {
        for (int j=0; j<i; j++)
        {
            if ((skyscraper[j].floor > skyscraper[j + 1].floor && t==1) ||
                (skyscraper[j].number > skyscraper[j + 1].number && t==2) ||
                (strcmp(skyscraper[j].family, skyscraper[j + 1].family)>0  && t==3) ) //strcmp(strings[j], strings[j+1]) > 0
            {
                tmp = skyscraper[j];
                skyscraper[j] = skyscraper[j + 1];
                skyscraper[j + 1] = tmp;
            }
        }
    }

    printf("\nAfter sort: \n");
    output(skyscraper,n);
}

int main()
{
    struct flat *skyscraper;
    printf("Enter the number of apartments in skyscraper: ");
    int n=input_check();

    skyscraper=(struct flat*)calloc(n, sizeof(struct flat));

    printf("Enter information about apartments: \n");
    input_struct(skyscraper, n);

    typeSort(skyscraper,n);

    printf("Final information about flats:\n");
    output(skyscraper,n);
    return 0;
}
