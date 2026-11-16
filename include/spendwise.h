#ifndef SPENDWISE_H
#define SPENDWISE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 500

// Structure to store transaction details
struct Transaction {
    int id;
    char type[10];
    float amount;
    char category[30];
    char date[11];
    char description[100];
};

// Menu function
void displayMenu(void);

// Transaction functions
void addTransaction(struct Transaction transactions[], int *count);
void viewTransactions(const struct Transaction transactions[], int count);
void deleteTransaction(struct Transaction transactions[], int *count);

void saveTransactions(const struct Transaction transactions[], int count);
int loadTransactions(struct Transaction transactions[]);


// Financial summary
void showFinancialSummary(const struct Transaction transactions[], int count);

// Monthly budget
void setMonthlyBudget(const struct Transaction transactions[], int count);
void displayBudgetStatus(const struct Transaction transactions[], int count);
void generateMonthlyReport(const struct Transaction transactions[], int count);
void searchTransactions(const struct Transaction transactions[], int count);
#endif
