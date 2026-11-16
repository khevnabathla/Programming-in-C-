#include "spendwise.h"
#include <time.h>

#define BUDGET_FILE "data/monthly_budget.dat"

void displayBudgetStatus(const struct Transaction transactions[], int count) {

    FILE *file = fopen(BUDGET_FILE, "rb");
    float budget;

    if (file == NULL) {
        printf("\nNo monthly budget has been set yet.\n");
        return;
    }

    if (fread(&budget, sizeof(float), 1, file) != 1) {
        fclose(file);
        printf("\nCould not read monthly budget.\n");
        return;
    }

    fclose(file);

    time_t now = time(NULL);
    struct tm *currentTime = localtime(&now);

    if (currentTime == NULL) {
        printf("\nCould not determine current month.\n");
        return;
    }

    char currentMonth[8];
    strftime(currentMonth, sizeof(currentMonth), "%Y-%m", currentTime);

    float monthlyExpenses = 0;

    for (int i = 0; i < count; i++) {

        if (strcmp(transactions[i].type, "Expense") == 0 &&
            strncmp(transactions[i].date, currentMonth, 7) == 0) {

            monthlyExpenses += transactions[i].amount;
        }
    }

    float remaining = budget - monthlyExpenses;
    float percentage = (monthlyExpenses / budget) * 100;

    printf("\n========== MONTHLY BUDGET STATUS ==========\n");
    printf("Monthly Budget  : Rs. %.2f\n", budget);
    printf("Amount Spent    : Rs. %.2f\n", monthlyExpenses);
    printf("Remaining       : Rs. %.2f\n", remaining);
    printf("Budget Used     : %.1f%%\n", percentage);

    if (percentage >= 100) {
        printf("\nWARNING: You have exceeded your monthly budget!\n");
    }
    else if (percentage >= 80) {
        printf("\nWARNING: You have used 80%% or more of your budget!\n");
    }
    else {
        printf("\nYou are within your monthly budget.\n");
    }
}

void setMonthlyBudget(const struct Transaction transactions[], int count) {

    float budget;
    char input[100];

    printf("\n========== SET MONTHLY BUDGET ==========\n");
    printf("Enter your monthly budget (INR): ");

    if (fgets(input, sizeof(input), stdin) == NULL ||
        sscanf(input, "%f", &budget) != 1 ||
        budget <= 0) {

        printf("\nInvalid budget amount!\n");
        return;
    }

    FILE *file = fopen(BUDGET_FILE, "wb");

    if (file == NULL) {
        printf("\nError saving budget!\n");
        return;
    }

    fwrite(&budget, sizeof(float), 1, file);
    fclose(file);

    printf("\nMonthly budget saved successfully!\n");

    displayBudgetStatus(transactions, count);
}