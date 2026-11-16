
#include "spendwise.h"

// Function to add a new transaction
void addTransaction(struct Transaction transactions[], int *count) {

    if (*count >= MAX_TRANSACTIONS) {
        printf("\nTransaction limit reached!\n");
        return;
    }

    struct Transaction newTransaction;
    char input[100];
    int typeChoice;

    printf("\n========== ADD TRANSACTION ==========\n");

    // Choose transaction type
    printf("1. Income\n");
    printf("2. Expense\n");
    printf("Enter transaction type: ");

    fgets(input, sizeof(input), stdin);
    typeChoice = atoi(input);

    if (typeChoice == 1) {
        strcpy(newTransaction.type, "Income");
    }
    else if (typeChoice == 2) {
        strcpy(newTransaction.type, "Expense");
    }
    else {
        printf("\nInvalid transaction type!\n");
        return;
    }

    // Enter amount
    printf("Enter amount (INR): ");
    if (fgets(input, sizeof(input), stdin) == NULL ||
        sscanf(input, "%f", &newTransaction.amount) != 1 ||
        newTransaction.amount <= 0) {
        printf("\nInvalid amount!\n");
        return;
    }

    // Enter category
    printf("Enter category: ");
    if (fgets(newTransaction.category,
              sizeof(newTransaction.category), stdin) == NULL) {
        printf("\nInput error!\n");
        return;
    }
    newTransaction.category[strcspn(newTransaction.category, "\n")] = '\0';

    // Enter date
    printf("Enter date (YYYY-MM-DD): ");
    if (fgets(newTransaction.date,
              sizeof(newTransaction.date), stdin) == NULL) {
        printf("\nInput error!\n");
        return;
    }
    newTransaction.date[strcspn(newTransaction.date, "\n")] = '\0';

    // Enter description
    printf("Enter description: ");
    if (fgets(newTransaction.description,
              sizeof(newTransaction.description), stdin) == NULL) {
        printf("\nInput error!\n");
        return;
    }
    newTransaction.description[strcspn(newTransaction.description, "\n")] = '\0';

    // Generate transaction ID
    newTransaction.id = 1;

    for (int i = 0; i < *count; i++) {
        if (transactions[i].id >= newTransaction.id) {
            newTransaction.id = transactions[i].id + 1;
        }
    }

    // Store transaction
    transactions[*count] = newTransaction;
    (*count)++;

    printf("\nTransaction added successfully!\n");
    printf("Transaction ID: %d\n", newTransaction.id);
}


// Function to display all transactions
void viewTransactions(const struct Transaction transactions[], int count) {

    printf("\n========== TRANSACTION HISTORY ==========\n");

    if (count == 0) {
        printf("No transactions found.\n");
        return;
    }

    printf("\n%-5s %-10s %-12s %-15s %-12s %s\n",
           "ID", "Type", "Amount", "Category", "Date", "Description");

    printf("--------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {

        printf("%-5d %-10s Rs.%-9.2f %-15s %-12s %s\n",
               transactions[i].id,
               transactions[i].type,
               transactions[i].amount,
               transactions[i].category,
               transactions[i].date,
               transactions[i].description);
    }
}
// Function to delete a transaction
void deleteTransaction(struct Transaction transactions[], int *count) {

    int id;
    int found = 0;
    char input[20];

    if (*count == 0) {
        printf("\nNo transactions available to delete.\n");
        return;
    }

    printf("\n========== DELETE TRANSACTION ==========\n");

    printf("Enter Transaction ID to delete: ");

    if (fgets(input, sizeof(input), stdin) == NULL ||
        sscanf(input, "%d", &id) != 1) {
        printf("\nInvalid ID!\n");
        return;
    }

    // Search for the transaction
    for (int i = 0; i < *count; i++) {

        if (transactions[i].id == id) {

            found = 1;

            // Shift remaining transactions to fill the gap
            for (int j = i; j < *count - 1; j++) {
                transactions[j] = transactions[j + 1];
            }

            (*count)--;

            printf("\nTransaction deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nTransaction ID not found!\n");
    }
}

