#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PRODUCTS 100
struct Product {
int id;
char name[50];
int quantity;
};
struct Inventory {
struct Product products[MAX_PRODUCTS];
int count;
};
void addProduct(struct Inventory* inventory) {
if (inventory->count == MAX_PRODUCTS) {
    printf("Inventory is full. Cannot add more products.\n");
    return;
    }
struct Product newProduct;
printf("Enter product ID: ");
scanf("%d", &newProduct.id);
printf("Enter product name: ");
scanf(" %[^\n]s", newProduct.name);
printf("Enter product quantity: ");
scanf("%d", &newProduct.quantity);
inventory->products[inventory->count++] = newProduct;
printf("Product added successfully!\n");
}
void updateQuantity(struct Inventory* inventory) {
int productId;
printf("Enter product ID to update quantity: ");
scanf("%d", &productId);
for (int i = 0; i < inventory->count; i++) 
{
    if (inventory->products[i].id == productId)
	{
    int newQuantity;
	printf("Enter updated quantity: ");
    scanf("%d", &newQuantity);
	inventory->products[i].quantity = newQuantity;
	printf("Quantity updated successfully!\n");
    return;
    }
}
    printf("Product not found.\n");
}
void displayInventory(struct Inventory* inventory) {
    printf("--- Inventory ---\n");
    for (int i = 0; i < inventory->count; i++) 
	{
    printf("Product ID: %d\n", inventory->products[i].id);
    printf("Product Name: %s\n", inventory->products[i].name);
    printf("Quantity: %d\n", inventory->products[i].quantity);
    printf("-----------------------\n");
    }
}
void searchProduct(struct Inventory* inventory) {
    int productId;
    printf("Enter product ID to search: ");
    scanf("%d", &productId);

for (int i = 0; i < inventory->count; i++) {
    if (inventory->products[i].id == productId) 
	{
	printf("Product ID: %d\n", inventory->products[i].id);
    printf("Product Name: %s\n", inventory->products[i].name);
    printf("Quantity: %d\n", inventory->products[i].quantity);
    return;
    }
    }
printf("Product not found.\n");
}
int main() {
struct Inventory inventory;
inventory.count = 0;
int choice;
do {
    printf("<<<< INVENTORY MANAGEMENT SYSTEM >>>>\n");
    printf("1. Add Product\n");
    printf("2. Update Quantity\n");
    printf("3. Display Inventory\n");
    printf("4. Search Product\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
    addProduct(&inventory);
    break;
    case 2:
    updateQuantity(&inventory);
    break;
    case 3:
    displayInventory(&inventory);
    break;
    case 4:
    searchProduct(&inventory);
    break;
    case 0:
    printf("******************************************* EXIT PROGRAM *******************************************\n");
    break;
    default:
    printf("Invalid choice. Please try again.\n");
    break;
}
} while (choice != 0);
return 0;
}
