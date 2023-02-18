#include "headder.h"

struct flat
{
    int floor;
    int number;
    char family[100];
};

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
