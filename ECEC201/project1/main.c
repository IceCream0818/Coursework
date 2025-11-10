#include <stdio.h>

//calculate tax if single
float calc1(double income){
    double tax;

    if (income <= 11925) {
        tax = income * 0.1;
    } else if (income <= 48475) {
        tax = 1192.5 + 0.12 * (income - 11925);
    } else if (income <= 103350) {
        tax = 5578.5 + 0.22 * (income - 48475);
    } else if (income <= 197300) {
        tax = 17651 + 0.24 * (income - 103350);
    } else if (income <= 250525) {
        tax = 40199 + 0.32 * (income - 197300);
    } else if (income <= 626350) {
        tax = 57231 + 0.35 * (income - 250525);
    } else {
        tax = 188769.75 + 0.37 * (income - 626350);
    }

    return tax;
}

//calculate tax if head of household
float calc2(double income){
    double tax;

    if (income <= 17000) {
        tax = income * 0.1;
    } else if (income <= 64850) {
        tax = 1700 + 0.12 * (income - 17000);
    } else if (income <= 103350) {
        tax = 7442 + 0.22 * (income - 64850);
    } else if (income <= 197300) {
        tax = 15912 + 0.24 * (income - 103350);
    } else if (income <= 250500) {
        tax = 38460 + 0.32 * (income - 197300);
    } else if (income <= 626350) {
        tax = 55484 + 0.35 * (income - 250500);
    } else {
        tax = 187031.5 + 0.37 * (income - 626350);
    }

    return tax;
}

//calculate tax if married filling jointly and surviving spouses
float calc3(double income){
    double tax;

    if (income <= 23850) {
        tax = income * 0.1;
    } else if (income <= 96950) {
        tax = 2385 + 0.12 * (income - 23850);
    } else if (income <= 206700) {
        tax = 11157 + 0.22 * (income - 96950);
    } else if (income <= 394600) {
        tax = 35302 + 0.24 * (income - 206700);
    } else if (income <= 501050) {
        tax = 80398 + 0.32 * (income - 394600);
    } else if (income <= 751600) {
        tax = 114462 + 0.35 * (income - 501050);
    } else {
        tax = 202154.5 + 0.37 * (income - 751600);
    }

    return tax;
}

//calculate tax if married filling separately
float calc4(double income){
    double tax;

    if (income <= 11925) {
        tax = income * 0.1;
    } else if (income <= 48475) {
        tax = 1192.5 + 0.12 * (income - 11925);
    } else if (income <= 103350) {
        tax = 5578.5 + 0.22 * (income - 48475);
    } else if (income <= 197300) {
        tax = 17651 + 0.24 * (income - 103350);
    } else if (income <= 250525) {
        tax = 40199 + 0.32 * (income - 197300);
    } else if (income <= 375800) {
        tax = 57231 + 0.35 * (income - 250525);
    } else {
        tax = 101077.25 + 0.37 * (income - 375800);
    }

    return tax;
}

int main(){
    double L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13, 
    L14, L15, L16, L17, L18, L19, L20, L21, L22, L23, L24, L25;
    
    double Salary, Interest, Rent, Dividend, Capital_Gain;
    int Case = 0;
    int temp = 0;
    double income;

    double errorCheck;

    printf("\nWhat is your marriage status?\n1. Single\n2. Head of Household\n"
            "3. Married Filing Jointly and Surviving Spouses\n"
            "4. Married Filing Separately\nselect a number: ");
    
    //asks user to enter a marriage status until user enters a valid number
    while (Case == 0){
        
        errorCheck = scanf("%d", &temp);

        //if scanf did not receive a number, clear buffer and try again
        if (errorCheck != 1){
            while(getchar() != '\n'){continue;}
        }

        switch (temp){
            case 1:
                Case = 1;
                break;
            case 2:
                Case = 2;
                break;
            case 3:
                Case = 3;
                break;
            case 4:
                Case = 4;
                break;     
            default:  
                printf("You did not enter a valid number, try again: ");     
        }
    }

    printf("Enter the Salary: ");
    scanf("%lf", &Salary);
    printf("Enter the Interest: ");
    scanf("%lf", &Interest);    
    printf("Enter the Rent: ");
    scanf("%lf", &Rent);
    printf("Enter the Dividend: ");
    scanf("%lf", &Dividend);
    printf("Enter the Capital Gain: ");
    scanf("%lf", &Capital_Gain);

    income = Salary + Interest + Rent + Dividend + Capital_Gain;
    switch (Case){
        case 1:
            income -= 15750;
            break;
        case 2:
            income -= 23625;
            break;
        case 3:
            income -= 31500;
            break;
        case 4:
            income -= 15750;
    }
    L1 = income;
    L2 = Dividend;
    L3 = Capital_Gain;
    L4 = L2 + L3;

    if (L1 - L4 < 0){
        L5 = 0;
    }else{
        L5 = L1 - L4;
    }

    switch (Case){
        case 1:
            L6 = 48475;
            break;
        case 2:
            L6 = 64850;
            break;
        case 3:
            L6 = 96950;
            break;
        case 4:
            L6 = 48475;
    }

    if (L1 < L6){
        L7 = L1;
    }else{
        L7 = L6;
    }

    if (L5 < L7){
        L8 = L5;
    }else{
        L8 = L7;
    }
    L9 = L7 - L8;

    if (L1 < L4){
        L10 = L1;
    }else{
        L10 = L4;
    }
    L11 = L9;
    L12 = L10 - L11;

    switch (Case){
        case 1:
            L13 = 533400;
            break;
        case 2:
            L13 = 566700;
            break;
        case 3:
            L13 = 600050;
            break;
        case 4:
            L13 = 300000;
    }

    if (L1 < L13){
        L14 = L1;
    }else{
        L14 = L13;
    }
    L15 = L5 + L9;

    if (L14 - L15 < 0){
        L16 = 0;
    }else{
        L16 = L14 - L15;
    }

    if (L12 < L16){
        L17 = L12;
    }else{
        L17 = L16;
    }
    L18 = L17 * 0.15;
    L19 = L9 + L17;
    L20 = L10 - L19;
    L21 = L20 * 0.2;
    
    switch (Case){
        case 1:
            L22 = calc1(L5);
            break;
        case 2:
            L22 = calc2(L5);
            break;
        case 3:
            L22 = calc3(L5);
            break;
        case 4:
            L22 = calc4(L5);
    }
    L23 = L18 + L21 + L22;

    switch (Case){
        case 1:
            L24 = calc1(L1);
            break;
        case 2:
            L24 = calc2(L1);
            break;
        case 3:
            L24 = calc3(L1);
            break;
        case 4:
            L24 = calc4(L1);
    }
    if (L23 < L24){
        L25 = L23;
    }else{
        L25 = L24;
    }

    printf("1.  Enter the amount from Form 1040 or 1040-SR, line 15:                %.2lf\n", L1);
    printf("2.  Enter the amount from Form 1040 or 1040-SR, line 3a:                %.2lf\n", L2);
    printf("3.  Enter the amount from Form 1040 or 1040-SR, line 7:                 %.2lf\n", L3);
    printf("4.  Add lines 2 and 3:                                                  %.2lf\n", L4);
    printf("5.  Subtract line 4 from line 1. If zero or less, enter 0:              %.2lf\n", L5);
    printf("6.  Enter:\n"
           "    48475 if single or married filing separately,\n"   
           "    96950 if married filing jointly or qualifying surviving spouse,\n"                          
           "    64850 if head of household.                                         %.2lf\n", L6);
    printf("7.  Enter the smaller of line 1 or line 6:                              %.2lf\n", L7);
    printf("8.  Enter the smaller of line 5 or line 7:                              %.2lf\n", L8);
    printf("9.  Subtract line 8 from line 7. This amount is taxed at 0%%             %.2lf\n", L9);
    printf("10. Enter the smaller of line 1 or line 4:                              %.2lf\n", L10);
    printf("11. Enter the amount from line 9:                                       %.2lf\n", L11);
    printf("12. Subtract line 11 from line 10:                                      %.2lf\n", L12);
    printf("13. Enter:\n"
           "    533400 if single,\n"   
           "    300000 if married filing separately,\n"   
           "    600050 if married filing jointly or qualifying surviving spouse,\n"                          
           "    566700 if head of household.                                        %.2lf\n", L13);
    printf("14. Enter the smaller of line 1 or line 13:                             %.2lf\n", L14);
    printf("15. Add lines 5 and 9:                                                  %.2lf\n", L15);
    printf("16. Subtract line 15 from line 14. If zero or less, enter 0:            %.2lf\n", L16);
    printf("17. Enter the smaller of line 12 or line 16:                            %.2lf\n", L17);
    printf("18. Multiply line 17 by 15%%(0.15):                                      %.2lf\n", L18);
    printf("19. Add lines 9 and 17):                                                %.2lf\n", L19);
    printf("20. Subtract line 19 from line 10:                                      %.2lf\n", L20);
    printf("21. Multiply line 20 by 20%%(0.20):                                      %.2lf\n", L21);
    printf("22. Figure the tax on the amount on line 5:                             %.2lf\n", L22);
    printf("23. Add lines 18, 21, and 22:                                           %.2lf\n", L23);
    printf("24. Figure the tax on the amount on line 1:                             %.2lf\n", L24);
    printf("25. Tax on all taxable income. Enter the smaller of line 23 or line 24: %.2lf\n", L25);

    return 0;
}