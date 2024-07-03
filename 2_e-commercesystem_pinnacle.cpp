#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Structure to represent a product
struct Product {
    string name;
    double price;
    int quantity;
};

// Structure to represent a cart
struct Cart {
    vector<Product> products;
    double total;
};

// Function to display products
void displayProducts(const vector<Product> &products) {
    cout << "Available Products:" << endl;
    for (int i = 0; i < products.size(); i++) {
        cout << i + 1 << ". " << products[i].name << " - Rs." << products[i].price << " (Quantity: " << products[i].quantity << ")" << endl;
    }
}

// Function to add product to cart
void addToCart(Cart &cart, const vector<Product> &products, int choice) {
    cart.products.push_back(products[choice - 1]);
    cart.total += products[choice - 1].price;

   
    cout << "Product added to cart!" << endl;
}

// Function to display cart
void displayCart(const Cart &cart) {
    cout << "Cart:" << endl;
    for (int i = 0; i < cart.products.size(); i++) {
        cout << i + 1 << ". " << cart.products[i].name << " - $" << cart.products[i].price << endl;
    }
    cout << "Total: Rs." << cart.total << endl;
}

// Function to complete purchase
void completePurchase(const Cart &cart) {
    cout << "Purchase complete! Total: $" << cart.total << endl;
    cout << "Thank you for shopping with us!" << endl;
}

int main() {
    // Initialize products
    vector<Product> products = {
        {"Apple", 89.00, 10},
        {"Banana", 69.00, 20},
        {"Orange", 99.00, 15},
        {"Grapes", 110.00, 5}
    };

    // Initialize cart
    Cart cart;
    cart.total = 0.0;

    while (true) {
        cout << "Welcome to the e-commerce system!" << endl;
        cout << "1. Browse products" << endl;
        cout << "2. View cart" << endl;
        cout << "3. Checkout" << endl;
        cout << "4. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayProducts(products);
                cout << "Enter the number of the product you want to add to cart: ";
                int productChoice;
                cin >> productChoice;
                addToCart(cart, products, productChoice);
                break;
            case 2:
                displayCart(cart);
                break;
            case 3:
                if (cart.products.size() == 0) {
                    cout << "Your cart is empty. Please add some products to cart." << endl;
                } else {
                    completePurchase(cart);
                    return 0;
                }
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}