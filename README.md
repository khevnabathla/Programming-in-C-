# SpendWise — Personal Finance Manager

A command-line Personal Expense Management System built using C.

## Overview

SpendWise is a C-based application designed to help users manage their personal finances by tracking income, expenses, and monthly budgets.

It provides transaction management, financial summaries, monthly reports, and budget alerts through a simple command-line interface.

## Features

- **Transaction Management:** Add, view, and delete income and expense transactions.
- **Data Persistence:** Automatically save and load transactions using file handling.
- **Financial Summary:** Calculate total income, expenses, and remaining balance.
- **Expense Categorization:** Organize transactions by category and identify the highest spending category.
- **Monthly Budget:** Set a monthly spending limit.
- **Budget Alerts:** Receive warnings when spending reaches 80% or exceeds the budget.
- **Monthly Reports:** Generate financial summaries for a selected month.
- **Transaction Search:** Search transactions by category.

## Technologies Used

- C Programming
- GCC Compiler
- Structures and Arrays
- Functions and Pointers
- File Handling
- String Manipulation
- Git and GitHub

## Project Structure

```text
SpendWise/
├── src/
├── include/
├── data/
├── README.md
└── .gitignore
```

## How to Run

### Requirements
- GCC Compiler
- Windows / PowerShell
- VS Code (recommended)

### Compile

```bash
gcc -Wall -Wextra -std=c11 -Iinclude src/main.c src/transaction.c src/storage.c src/budget.c src/reports.c -o spendwise.exe
```

### Run

```powershell
.\spendwise.exe
```

## Concepts Demonstrated

This project demonstrates practical applications of:
- Structures
- Arrays
- Modular programming
- Pointers
- File operations
- Searching
- Input validation

## Project Status

**Completed:** Core transaction management, persistent storage, financial summaries, monthly budgeting, reports, and category-based search.

## Author

Developed as a C Programming project by Khevna Bathla.
