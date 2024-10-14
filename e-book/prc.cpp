#include <iostream>
#include <string>
using namespace std;

class Watch {
private:
    string brand;
    double price; // Price in dollars
    int stock;    // Number of items in stock

public:
    // Constructor
    Watch(string b, double p, int s) : brand(b), price(p), stock(s) {}

    // Copy Constructor
    Watch(const Watch& other) : brand(other.brand), price(other.price), stock(other.stock) {}

    // Friend functions for operator overloading
    friend Watch operator+(const Watch& w1, const Watch& w2);
    friend Watch operator-(const Watch& w1, const Watch& w2);
    friend bool operator==(const Watch& w1, const Watch& w2);
    friend bool operator<(const Watch& w1, const Watch& w2);
    friend ostream& operator<<(ostream& os, const Watch& w);

    // Static function to create a luxury watch
    static Watch createLuxuryWatch(string brand, double price) {
        return Watch(brand, price, 10); // Limited stock for luxury watches
    }

    // Method to update stock (overloading)
    void updateStock(int newStock) {
        stock = newStock;
    }

    void updateStock(int change, bool isIncrease) {
        if (isIncrease) {
            stock += change;
        } else {
            stock -= change;
        }
    }

    // Display function
    void display() const {
        cout << "Brand: " << brand << ", Price: $" << price << ", Stock: " << stock << endl;
    }
};

// Operator overloads
Watch operator+(const Watch& w1, const Watch& w2) {
    return Watch(w1.brand + " & " + w2.brand, w1.price + w2.price, w1.stock + w2.stock);
}

Watch operator-(const Watch& w1, const Watch& w2) {
    return Watch(w1.brand, w1.price - w2.price, w1.stock - w2.stock);
}

bool operator==(const Watch& w1, const Watch& w2) {
    return (w1.brand == w2.brand && w1.price == w2.price && w1.stock == w2.stock);
}

bool operator<(const Watch& w1, const Watch& w2) {
    return w1.price < w2.price;
}

ostream& operator<<(ostream& os, const Watch& w) {
    os << "Watch(Brand: " << w.brand << ", Price: $" << w.price << ", Stock: " << w.stock << ")";
    return os;
}

// Call by value
void callByValue(Watch w) {
    w.updateStock(5); // Modify a copy
    cout << "Inside callByValue: " << w << endl;
}

// Call by reference
void callByReference(Watch& w) {
    w.updateStock(5, true); // Modify original watch
    cout << "Inside callByReference: " << w << endl;
}

int main() {
    Watch w1("Rolex", 10000, 5);
    Watch w2("Seiko", 500, 20);

    cout << "Watch 1: ";
    w1.display();
    cout << "Watch 2: ";
    w2.display();

    // Demonstrate operator overloading
    Watch w3 = w1 + w2;
    cout << "Combined Watch: " << w3 << endl;

    Watch w4 = w1 - w2;
    cout << "Price Difference Watch: " << w4 << endl;

    // Comparison
    cout << (w1 < w2 ? "Watch 1 is cheaper than Watch 2." : "Watch 1 is more expensive than or equal to Watch 2.") << endl;

    // Call by value
    callByValue(w1);
    cout << "After call by value, Watch 1: " << w1 << endl;

    // Call by reference
    callByReference(w2);
    cout << "After call by reference, Watch 2: " << w2 << endl;

    // Static function
    Watch luxuryWatch = Watch::createLuxuryWatch("Patek Philippe", 50000);
    cout << "Luxury Watch: " << luxuryWatch << endl;

    return 0;
}
