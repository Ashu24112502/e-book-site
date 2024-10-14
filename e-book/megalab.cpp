#include<iostream>
using namespace std;

class Laptop{
    private:
    int price;
    string brand;

    public:
        Laptop(int p, string b) : price(p), brand(b) {}

        Laptop(const Laptop& other) : price(other.price),brand(other.brand){}

        friend Laptop operator+(const Laptop& L1, const Laptop& L2);
        friend Laptop operator-(const Laptop& L1, const Laptop& L2);
       
    static Laptop createAdvanceLaptop(int price,string brand) {
        return Laptop( price, brand);
}
     
        void display() const {
        cout << "Brand: " << brand << ", Price: $" << price << endl;
    }
};
     int main () {
        Laptop L1(10000, "HP");
        Laptop L2(15000,"LENOVO");
         cout << "Watch 1: ";
    L1.display();
    cout << "Laptop 2: ";
    L2.display();

    
      return  0;
    }
