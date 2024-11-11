#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int factorial(int n);

int main(void)
{
 int i, order;
 double e, *terms;

 printf("Enter the required polynomial order\n");
 if (scanf("%d", &order) !=1)
 {
	 printf("Did not enter a number\n");
	 return 1;
 }

terms = (double *)malloc(order * sizeof(double));
for(i=0; i<order; i++)
{
    terms[i] = 1.0/ (double)factorial(i+1);
    printf("%.16lf\n", terms[i]);

}

e=1.0;
for (i=0; i<order; i++)
{
    e = e + terms[i];
}

free(terms);

printf(" e is estimated as %.10lf, with difference %e\n", e, e-exp(1.0));

return 0;
}

int factorial(int n)
{
    if (n<0)
    {
        printf("! ! Error: negative number passed to factorial\n");
        return(-1);
    }
else if (n==0)
{
    return 1;
}
else
{
    return (n * factorial(n-1));
}
}
