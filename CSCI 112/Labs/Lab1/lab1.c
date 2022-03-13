#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// Defining Sales Tax
#define TAX 0.05

// Calculates discount in $
double discountCalc(double cost, double discountPercent) {
    double discount;

    discount = cost * discountPercent;

    return discount;
}

// Caclulates initial cost minus discount for total before tax
double discountTotalCalc(double discount, double cost) {
    double discountTotal;

    discountTotal = cost - discount;

    return discountTotal;
}

// Calculates Sales Tax in $
double salesTaxCalc(double discountTotal) {
    double salesTax;

    salesTax = discountTotal * TAX;

    return salesTax;
}

// Calculates total cost with discountTotal and salesTax
double totalCost(double discountTotal, double salesTax) {
    double total;

    total = discountTotal + salesTax;

    return total;
}

// Main Function
int main() {
    
    // Defining Variables
    double cost;
    double total;
    char discountStatus;
    double discount;
    double salesTax;
    double discountPercent;
    double discountTotal;

    // Getting Cost
    printf("Cost of Purchase:\t\t$");
    scanf("%lf", &cost);

    // Catching \n so the second scan doesnt get skipped
    getchar();

    // Getting military status
    printf("In military (y or n)?\t\t");
    scanf("%c", &discountStatus);

    // Checking if military status input is either a y or a n
    if (tolower(discountStatus) != 'y' && tolower(discountStatus) != 'n') {
        printf("Error: bad input\n");
        exit(1);
    } else {
        discountStatus = tolower(discountStatus);
    }
    

    // Determines Discount %
    if (discountStatus == 'n') {
        discountPercent = 0;
    } else if (discountStatus == 'y' && cost > 150) {
        discountPercent = 0.15;
    } else {
        discountPercent = 0.1;
    }

    // Calculating all variables
    discount = discountCalc(cost, discountPercent);
    discountTotal = discountTotalCalc(discount, cost);
    salesTax = salesTaxCalc(discountTotal);
    total = totalCost(discountTotal, salesTax);
    discountPercent = discountPercent * 100;
    
    // Output
    if (discountPercent != 0) {
        printf("Military discount (%.0lf%%)\t\t$%.2lf\n", discountPercent, discount);
        printf("Discounted total\t\t$%.2lf\n", discountTotal);
    }
    printf("Sales tax (5%%)\t\t\t$%.2lf\n", salesTax);
    printf("Total\t\t\t\t$%.2lf\n", total);

}


