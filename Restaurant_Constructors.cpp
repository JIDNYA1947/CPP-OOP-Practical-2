#include <iostream>
#include <string>
using namespace std;

class Restaurant
{
private:
    string customerName;
    int orderNumber;
    float totalBill;

public:

    Restaurant()
    {
        customerName = "Not Assigned";
        orderNumber = 0;
        totalBill = 0.0;

        cout << "\nDefault Constructor Called!" << endl;
    }

    Restaurant(string name, int number, float bill)
    {
        customerName = name;
        orderNumber = number;
        totalBill = bill;

        cout << "\nParameterized Constructor Called!" << endl;
    }

    Restaurant(const Restaurant &obj)
    {
        customerName = obj.customerName;
        orderNumber = obj.orderNumber;
        totalBill = obj.totalBill;

        cout << "\nCopy Constructor Called!" << endl;
    }

    void addItem(float amount)
    {
        if (amount > 0)
        {
            totalBill = totalBill + amount;
            cout << "Item Added Successfully!" << endl;
        }
        else
        {
            cout << "Invalid Amount!" << endl;
        }
    }

    void removeItem(float amount)
    {
        if (amount > 0 && amount <= totalBill)
        {
            totalBill = totalBill - amount;
            cout << "Item Removed Successfully!" << endl;
        }
        else
        {
            cout << "Invalid Amount!" << endl;
        }
    }

    void display()
    {
        cout << "\n----- RESTAURANT BILL DETAILS -----" << endl;
        cout << "Customer Name : " << customerName << endl;
        cout << "Order Number  : " << orderNumber << endl;
        cout << "Total Bill    : Rs. " << totalBill << endl;
    }
};

int main()
{
    cout << "===== RESTAURANT BILLING MANAGEMENT SYSTEM =====" << endl;

    Restaurant order1;

    order1.display();

    Restaurant order2("Jidnya", 101, 500);

    order2.display();

    cout << "\nAdding Rs. 200 to the bill..." << endl;
    order2.addItem(200);

    cout << "\nRemoving Rs. 100 from the bill..." << endl;
    order2.removeItem(100);

    order2.display();

    cout << "\nCreating Copy of Order..." << endl;

    Restaurant order3(order2);

    order3.display();

    return 0;
}
