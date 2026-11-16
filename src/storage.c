#include "spendwise.h"

// Save transactions to a file
void saveTransactions(const struct Transaction transactions[], int count) {

    FILE *file = fopen("data/transactions.dat", "wb");

    if (file == NULL) {
        printf("\nError saving transactions!\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, file);
    fwrite(transactions, sizeof(struct Transaction), count, file);

    fclose(file);

    printf("\nTransactions saved successfully!\n");
}

// Load transactions from a file
int loadTransactions(struct Transaction transactions[]) {

    FILE *file = fopen("data/transactions.dat", "rb");

    if (file == NULL) {
        return 0; // First run: no saved transactions yet
    }

    int count = 0;

    if (fread(&count, sizeof(int), 1, file) != 1 ||
        count < 0 || count > MAX_TRANSACTIONS) {
        fclose(file);
        printf("\nSaved data is invalid. Starting fresh.\n");
        return 0;
    }

    if (fread(transactions, sizeof(struct Transaction), count, file) !=
        (size_t)count) {
        fclose(file);
        printf("\nCould not read saved transactions. Starting fresh.\n");
        return 0;
    }

    fclose(file);

    return count;
}