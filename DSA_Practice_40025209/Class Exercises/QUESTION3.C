#include <stdio.h>

int main() {
    char gender;
    double hours, gross_pay, regular_pay, overtime_pay;
    int children, excess_children;
    double reg_rate, ot_rate, edu_fund_rate;
    double total_tax, edu_fund_total, net_pay;

    printf("Enter Gender (M/F): ");
    scanf(" %c", &gender);
    printf("Enter total hours worked: ");
    scanf("%lf", &hours);
    printf("Enter number of children: ");
    scanf("%d", &children);

    if (gender == 'M' || gender == 'm') {
        reg_rate = 500.0;
        edu_fund_rate = 10.0;
    } else {
        reg_rate = 550.0;
        edu_fund_rate = 20.0;
    }
    ot_rate = reg_rate * 1.5;

    if (hours <= 40) {
        regular_pay = hours * reg_rate;
        overtime_pay = 0;
    } else {
        regular_pay = 40 * reg_rate;
        overtime_pay = (hours - 40) * ot_rate;
    }
    gross_pay = regular_pay + overtime_pay;

    total_tax = gross_pay * (0.15 + 0.025 + 0.01);
    
    if (children > 3) {
        excess_children = children - 3;
        edu_fund_total = excess_children * edu_fund_rate;
    } else {
        edu_fund_total = 0;
    }

    net_pay = gross_pay - total_tax - edu_fund_total;

    printf("\n--- Pay Slip ---\n");
    printf("Gross Pay:      GHS %.2f\n", gross_pay);
    printf("Tax Deductions: GHS %.2f\n", total_tax);
    printf("Edu. Fund:      GHS %.2f\n", edu_fund_total);
    printf("--------------------------\n");
    printf("NET PAY:        GHS %.2f\n", net_pay);

    return 0;
}