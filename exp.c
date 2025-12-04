#include <stdio.h>
#include <string.h>

#define MAX_EXPENSES 50
#define MAX_DESC_LENGTH 40

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
    char category[MAX_DESC_LENGTH];
} Expense;

Expense expenses[MAX_EXPENSES];
int expenseCount = 0;

void addExpense();
void viewAllExpenses();
void calculateTotal();
void viewByCategory();
void displayMenu();

void addExpense() {
    if (expenseCount >= MAX_EXPENSES) {
        printf("\nExpense list is full! Cannot add more expenses.\n");
        return;
    }
   
    printf("\n--- Add New Expense ---\n");
   
    printf("Enter description: ");
    scanf(" %[^\n]", expenses[expenseCount].description);
   
    printf("Enter amount: ₹");
    if (scanf("%f", &expenses[expenseCount].amount) != 1) {
        printf("Invalid amount entered. Please try again.\n");
        while(getchar() != '\n');
        return;
    }
   
    printf("Enter category (e.g., Food, Bills): ");
    scanf(" %[^\n]", expenses[expenseCount].category);
   
    expenseCount++;
    printf("\nExpense added successfully!\n");
}

void viewAllExpenses() {
    if (expenseCount == 0) {
        printf("\nNo expenses recorded yet.\n");
        return;
    }
   
    printf("\n=== ALL EXPENSES ===\n");
    printf("%-5s %-20s %-15s %-10s\n", "No.", "Description", "Category", "Amount");
    printf("---------------------------------------------------\n");
   
    for (int i = 0; i < expenseCount; i++) {
        printf("%-5d %-20s %-15s ₹%.2f\n",
               i + 1,
               expenses[i].description,
               expenses[i].category,
               expenses[i].amount);
    }
    printf("---------------------------------------------------\n");
}

void calculateTotal() {
    if (expenseCount == 0) {
        printf("\nNo expenses recorded yet.\n");
        return;
    }
   
    float total = 0;
    for (int i = 0; i < expenseCount; i++) {
        total += expenses[i].amount;
    }
   
    printf("\n=== TOTAL EXPENSES ===\n");
    printf("Total Amount Spent: ₹%.2f\n", total);
}

void viewByCategory() {
    if (expenseCount == 0) {
        printf("\nNo expenses recorded yet.\n");
        return;
    }
   
    char searchCategory[MAX_DESC_LENGTH];
    printf("\nEnter category to view (must match case exactly): ");
    scanf(" %[^\n]", searchCategory);
   
    float categoryTotal = 0;
    int found = 0;
   
    printf("\n=== EXPENSES IN '%s' ===\n", searchCategory);
    printf("%-20s %-10s\n", "Description", "Amount");
    printf("------------------------------------\n");
   
    for (int i = 0; i < expenseCount; i++) {
        if (strcmp(expenses[i].category, searchCategory) == 0) {
            printf("%-20s ₹%.2f\n", expenses[i].description, expenses[i].amount);
            categoryTotal += expenses[i].amount;
            found = 1;
        }
    }
   
    if (found) {
        printf("------------------------------------\n");
        printf("Category Total: ₹%.2f\n", categoryTotal);
    } else {
        printf("No expenses found in the category '%s'.\n", searchCategory);
    }
}

void displayMenu() {
    printf("\n=== MENU ===\n");
    printf("1. Add Expense\n");
    printf("2. View All Expenses\n");
    printf("3. View Total\n");
    printf("4. View by Category\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
   
    printf("======================================\n");
    printf("   SIMPLE EXPENSE TRACKER \n");
    printf("======================================\n");
   
    while (1) {
        displayMenu();
       
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            while(getchar() != '\n');
            continue;
        }
       
        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewAllExpenses();
                break;
            case 3:
                calculateTotal();
                break;
            case 4:
                viewByCategory();
                break;
            case 5:
                printf("\nExiting program. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please select a valid option (1-5).\n");
        }
    }
}