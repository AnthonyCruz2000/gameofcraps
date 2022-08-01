#include <stdio.h>
#include <stdlib.h>


void enter_show()
{
const int p = 5, pr = 6;
double sales[p][pr],value,totalSales[p],productSales[pr],sumprsales=0;
int salesPerson, product;

printf("Enter the salesperson (1 - 4), product number (1 - 5), and total sales.\n ");
printf("Enter 0 for the salesperson to end input.\n");
scanf("%d",&salesPerson);

while (salesPerson != 0)
{
scanf("%d",&product);
scanf("%lf",&value);
sales[salesPerson][product] += value;
scanf("%d",&salesPerson);
}
printf("\nThe total sales for each salesperson are displayed at the end of each row,\n");
printf("and the total sales for each product are displayed at the bottom of each\n");
printf("\t    1\t\t    2\t\t    3\t\t    4\t\t  5\t\t  Total\n");

for (int i = 1; i < p; ++i) {
    printf("%d\t",i);
    for (int j = 1; j < pr; ++j){
        totalSales[i] += sales[i][j];
        printf("%lf\t",sales[i][j]);
        productSales[j] += sales[i][j];
    }
    printf("%lf\t\n",totalSales[i]);
}
     printf("\t\t\t\t\t\t\t\t\t\t\tGrand Total:");
    printf("\nTotal\t%lf",productSales[1]);
for (int j = 2; j < pr; ++j) {
        printf("\t%lf",productSales[j]);
}

for (int i = 1;i < p;i++) {
    sumprsales = sumprsales + totalSales[i];
}
printf("\t%1f",sumprsales);
putchar('\n');

}

int main()
{
    enter_show();
return 0;

}
