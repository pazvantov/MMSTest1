#include<stdio.h>
#include<math.h>

int cylinder(double r, double h, double* V, double* S);

int main()
{

    double r,h,V,S;

    while(scanf("%lf %lf",&r,&h) != EOF)
    {
        int result;
        result = cylinder(r,h,&V,&S);
        if(!result)
            printf("V = %lf, S = %lf\n",V,S);
    }
    return 0;
}

int cylinder(double r, double h, double* V, double* S)
{
    if((r <= 0) || (h <= 0))
    {
        fprintf(stderr,"Invalid data!\n");
        return -1;
    }
            
    *S = 2 * (3.14 * pow(r,2)) + (2 * 3.14 *r *h);
    *V = 3.14 * pow(r,2)*h;

    return 0;
}