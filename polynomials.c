#include <stdio.h>
#define MAX 100 // Maximum degree of the polynomial
void inputPolynomial(int poly[], int degree)
{
    for (int i = degree; i >= 0; i--)
    {
        printf("Enter coefficient for x^%d: ", i);
        scanf("%d", &poly[i]);
    }
}
void addPolynomials(int poly1[], int poly2[], int result[], int maxDegree)
{
    for (int i = 0; i <= maxDegree; i++)
        result[i] = poly1[i] + poly2[i];
}
void printPolynomial(int poly[], int degree)
{
    for (int i = degree; i >= 0; i--)
    {
        if (poly[i] != 0)
        {
            printf("%d", poly[i]);
            if (i > 0)
                printf("x^%d", i);
            if (i > 0 && poly[i - 1] > 0)
                printf(" + ");
        }
    }
    printf("\n");
}
void main()
{
    int poly1[MAX] = {0}, poly2[MAX] = {0}, result[MAX] = {0};
    int degree1, degree2, maxDegree;
    // Input first polynomial
    printf("Enter degree of the first polynomial: ");
    scanf("%d", &degree1);
    printf("Enter coefficients for the first polynomial:\n");
    inputPolynomial(poly1, degree1);
    // Input second polynomial
    printf("Enter degree of the second polynomial: ");
    scanf("%d", &degree2);
    printf("Enter coefficients for the second polynomial:\n");
    inputPolynomial(poly2, degree2);
    // Determine maximum degree
    if (degree1 > degree2)
        maxDegree = degree1;
    else
        maxDegree = degree2;
    // Add the polynomials
    addPolynomials(poly1, poly2, result, maxDegree);
    // Print result
    printf("First polynomial is: ");
    printPolynomial(poly1, maxDegree);
    printf("Second polynomial is: ");
    printPolynomial(poly2, maxDegree);
    printf("Sum of the polynomials is: ");
    printPolynomial(result, maxDegree);
}