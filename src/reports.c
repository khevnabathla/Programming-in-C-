#include "spendwise.h"

void showFinancialSummary(const struct Transaction transactions[], int count) {

    float totalIncome = 0;
    float totalExpenses = 0;

    char categories[MAX_TRANSACTIONS][30];
    float categoryTotals[MAX_TRANSACTIONS] = {0};
    int categoryCount = 0;

    printf("\n========== FINANCIAL SUMMARY ==========\n");

    for (int i = 0; i < count; i++) {

        if (strcmp(transactions[i].type, "Income") == 0) {
            totalIncome += transactions[i].amount;
        }

        else if (strcmp(transactions[i].type, "Expense") == 0) {

            totalExpenses += transactions[i].amount;

            int found = 0;

            for (int j = 0; j < categoryCount; j++) {
                if (strcmp(categories[j], transactions[i].category) == 0) {
                    categoryTotals[j] += transactions[i].amount;
                    found = 1;
                    break;
                }
            }

            if (!found && categoryCount < MAX_TRANSACTIONS) {
                strcpy(categories[categoryCount], transactions[i].category);
                categoryTotals[categoryCount] = transactions[i].amount;
                categoryCount++;
            }
        }
    }

    printf("\nTotal Income   : Rs. %.2f\n", totalIncome);
    printf("Total Expenses : Rs. %.2f\n", totalExpenses);
    printf("Balance        : Rs. %.2f\n", totalIncome - totalExpenses);

    if (categoryCount > 0) {

        int highestIndex = 0;

        for (int i = 1; i < categoryCount; i++) {
            if (categoryTotals[i] > categoryTotals[highestIndex]) {
                highestIndex = i;
            }
        }

        printf("\nHighest Spending Category: %s", categories[highestIndex]);
        printf("\nAmount Spent: Rs. %.2f\n", categoryTotals[highestIndex]);
    }
    else {
        printf("\nNo expense categories recorded yet.\n");
    }
}
// Generate a report for a selected month
void generateMonthlyReport(const struct Transaction transactions[], int count) {

    char month[20];
    float income = 0;
    float expenses = 0;

    printf("\n========== MONTHLY REPORT ==========\n");
    printf("Enter month (YYYY-MM): ");

    if (fgets(month, sizeof(month), stdin) == NULL) {
        return;
    }

    month[strcspn(month, "\n")] = '\0';

    if (strlen(month) != 7 || month[4] != '-') {
        printf("\nInvalid format! Use YYYY-MM.\n");
        return;
    }

    for (int i = 0; i < count; i++) {

        if (strncmp(transactions[i].date, month, 7) == 0) {

            if (strcmp(transactions[i].type, "Income") == 0) {
                income += transactions[i].amount;
            }
            else if (strcmp(transactions[i].type, "Expense") == 0) {
                expenses += transactions[i].amount;
            }
        }
    }

    printf("\n========== REPORT: %s ==========\n", month);
    printf("Total Income   : Rs. %.2f\n", income);
    printf("Total Expenses : Rs. %.2f\n", expenses);
    printf("Net Balance    : Rs. %.2f\n", income - expenses);
}


// Search transactions by category
void searchTransactions(const struct Transaction transactions[], int count) {

    char category[30];
    int found = 0;

    printf("\n========== SEARCH TRANSACTIONS ==========\n");
    printf("Enter category to search: ");

    if (fgets(category, sizeof(category), stdin) == NULL) {
        return;
    }

    category[strcspn(category, "\n")] = '\0';

    printf("\nSearch results for: %s\n", category);

    for (int i = 0; i < count; i++) {

        if (strcmp(transactions[i].category, category) == 0) {

            printf("\nID: %d", transactions[i].id);
            printf("\nType: %s", transactions[i].type);
            printf("\nAmount: Rs. %.2f", transactions[i].amount);
            printf("\nDate: %s", transactions[i].date);
            printf("\nDescription: %s\n", transactions[i].description);

            found = 1;
        }
    }

    if (!found) {
        printf("\nNo transactions found in this category.\n");
    }
}