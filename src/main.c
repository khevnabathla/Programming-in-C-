
#include "spendwise.h"
#include <stdio.h>
#include <stdlib.h>

// Function to display the main menu
void displayMenu(void) {

    printf("\n");
    printf("========================================\n");
    printf("              SPENDWISE                 \n");
    printf("       PERSONAL FINANCE MANAGER         \n");
    printf("========================================\n");

    printf("\n");
    printf("  1. Add Transaction\n");
    printf("  2. View Transactions\n");
    printf("  3. Financial Summary\n");
    printf("  4. Set Monthly Budget\n");
    printf("  5. Monthly Report\n");
    printf("  6. Search Transactions\n");
    printf("  7. Delete Transaction\n");
    printf("  8. Exit\n");

    printf("\n");
    printf("----------------------------------------\n");
}

// Main function
int main(void) {
    struct Transaction transactions[MAX_TRANSACTIONS];
int count = loadTransactions(transactions);

printf("\nWelcome to SpendWise!\n");
printf("Loaded %d saved transaction(s).\n", count);

    int choice;
    char input[20];

   

    do {

        displayMenu();

        printf("Enter your choice (1-8): ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        choice = atoi(input);
        

        switch (choice) {

           case 1:
    addTransaction(transactions, &count);
    saveTransactions(transactions, count);
    displayBudgetStatus(transactions, count);
    break;
            case 2:
             viewTransactions(transactions, count);
             break;

            case 3:
    showFinancialSummary(transactions, count);
    break;

           case 4:
    setMonthlyBudget(transactions, count);
    break;

         case 5:
    generateMonthlyReport(transactions, count);
    break;

case 6:
    searchTransactions(transactions, count);
    break;

          case 7:
    deleteTransaction(transactions, &count);
    saveTransactions(transactions, count);
    break;

            case 8:
                printf("\nThank you for using SpendWise!\n");
                printf("Exiting application...\n");
                break;

            default:
                printf("\nInvalid choice! Please enter 1-8.\n");
        }

    } while (choice != 8);

    return 0;
}
