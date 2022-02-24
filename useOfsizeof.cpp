#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Sales_Item_data {
    int numItem;
    int priceItem;
    string itemName;
    int digi;
    int digi1;
    char achar;
};

int main() {
    Sales_Item_data *sid = new Sales_Item_data();
    Sales_Item_data &rsid = *sid;
    Sales_Item_data *psid;
    
    int arr[] = {1,2,3,4,5,6,7,8,9,0};
    vector<int> vint = {11,22,33}; 
    string str = "a string";

    cout << "sizeof char or an expression of type char is guaranteed to be 1" << endl;
    cout << "char: " << sizeof(char) << endl; 
    cout << "int: " << sizeof(int) << endl;
    cout << "string: " << sizeof(string) << endl;

    cout << "sizeof a reference type returns the size of an object of the referenced type" << endl;
    cout << sizeof rsid << endl;

    cout << "sizeof a pointer returns the size needed hold a pointer " << endl;
    cout << sizeof psid << endl; 

    cout << "sizeof a dereferenced pointer returns the size of an object of the type" << endl; 
    cout << "to which the pointer points; the pointer need not be valid " << endl;
    cout << sizeof *psid << endl; // i.e., sizeof(Sales_Item_data)

    cout << "sizeof an array is the size of the entire array. It is equivalent to taking " << endl;
    cout << "the sizeof the element type times the number of elements in the array. " << endl; 
    cout << "Note that sizeof does not convert the array to a pointer " << endl;
    cout << sizeof arr << endl; 
    cout << sizeof(arr) / sizeof(*arr) << endl;
    
    constexpr size_t sz = sizeof(arr) / sizeof(*arr) ;
    int arrsz[sz];

    cout << "sizeof a string or a vector returns only the size of the fixed part of these " << endl;
    cout << "types; it does not return the size used by the object's elements" << endl;
    cout << sizeof vint << endl; 
    cout << sizeof str << endl;

    return 0;
}
