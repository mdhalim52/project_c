#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/*---------Function prototypes----------*/
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b, int *error);
double modulus(double a, double b, int *error);
double power(double base, double exponent);
double squareroot(double a, int *error);

void printMenu(void);
void ClearInputBuffer(void);
int GetValidateNumber(const char *prompt, double *value);

/*------------Main function------------*/
int main()
{
    int choice;
    double num1, num2, result;
    int error;
    char continueChoice;

    printf("==================================");
    printf("\n     PROFFESIONAL CALCULATOR\n");
    printf("==================================");

    do
    {
        printMenu();
        printf("Enter your choice (1-7): ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\n(Error!)Invalid Input. Please enter a valid number.\n\n");
            ClearInputBuffer();
            continue;
        }

        if (choice < 1 || choice > 7)
        {
            printf("\n(Error!) Please choose a valid option (1-7).\n\n");
            continue;
        }
        error = 0;
        
        
        /*Square root only needs one number*/
        if (choice == 7)
        {
            if (!GetValidateNumber("Enter number: ", &num1))
            {
                continue;
            }
            
        }
        else
        {
            if (!GetValidateNumber("Enter first number: ", &num1))
            {
                continue;
            }
            if (!GetValidateNumber("Enter second number: ", &num2))
            {
                continue;
            }
             
        }

        switch (choice)
        {
        case 1:
            result = add(num1, num2);
            printf("\nResult: %.2f + %.2f = %.2f\n\n", num1, num2, result);
            break;

        case 2:
            result = subtract(num1, num2);
            printf("\nResult: %.2f - %.2f = %.2f\n\n",num1, num2, result);
            break;

        case 3:
            result = multiply(num1, num2);
            printf("\nResult: %.2f * %.2f = %.2f\n\n",num1, num2, result);
            break;

        case 4:
            result = divide(num1, num2, &error);
            printf("\nResult: %.2f / %.2f = %.2f\n\n",num1, num2, result);
            break;

        case 5:
            result = modulus(num1, num2, &error);
            if (error)
            {
                printf("\n[Error] Modulus by zero is not allowed.\n\n");
            }
            else
            {
                printf("\nResult: %.0f %% %.0f = %.0f\n\n",num1, num2, result);
                break;
            }

        case 6:
            result = power(num1, num2);
            printf("\nResult: %.2f ^ %.2f = %.2f\n\n",num1, num2, result);
            break;

        case 7:
            result = squareroot(num1, &error);
            
            if (error)
            {
                printf("\n[Error] Cannot compute square root of a negative number.\n\n");
            }
            else
            {
                printf("\nResult: sqrt(%.2f) = %.2f\n\n", num1, result);
                break;
            }
        }
            
        printf("Do you want to perform another calculation? [y/n]: ");
        ClearInputBuffer();
        scanf("%c", &continueChoice);
        ClearInputBuffer();
        printf("\n");
        
    } while (continueChoice == 'y' || continueChoice == 'Y');

    printf("=============================================\n");
    printf("      Thank you for using the calculator\n");
    printf("=============================================\n");

    return  0;
    
}


/*-------------Menu Display--------------*/
void printMenu(void)
{
    printf("\n------------------------------------\n");
    printf(" 1. Addition        (+)\n");
    printf(" 2. Substraction    (-)\n");
    printf(" 3. Multiplication  (*)\n");
    printf(" 4. Division        (/)\n");
    printf(" 5. Modulus         (%%)\n");
    printf(" 6. Power           (^)\n");
    printf(" 7. Square root     (sqrt)\n");
    printf("------------------------------------");
}

/*---------Utility: CLear leftover input----------*/
void ClearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        /*Discard*/
    }
}

/*---------Utility: Get a validated double from user----------*/
int GetValidateNumber(const char *prompt, double *value)
{
    printf("%s", prompt);
    if (scanf("%lf", value) != 1)
    {
        printf("\n[Error!] Invalid number entered.\n\n");

        ClearInputBuffer();
        return 0;
    }
    return 1;
}

/*-----------Arithmatic Operations----------*/
double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b, int *error)
{
    if (b == 0)
    {
        *error = 1;
        
        return 0; 
    }
    *error = 0;
    
    return a / b;
}

double modulus(double a, double b, int *error)
{
    long ia = (long) a;
    long ib = (long) b;

    if (b == 0)   
    {
        *error = 1;

        return 0;
    }
    *error = 0;

    return (double) (ia % ib);
}

double power(double base, double exponent)
{
    return pow(base, exponent);
}

double squareroot(double a, int *error)
{
    if (a < 0)
    {
        *error = 1;

        return 0;
    }
    *error = 0;

    return sqrt(a);
}
