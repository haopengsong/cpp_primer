#include <string>
#include <iostream>

class Sales_data {
public:

    // Constructors added
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) : 
        bookNo(s), units_sold(n), revenue(n * p) {}
    Sales_data(std::istream&);
    // other members 
    std::string isbn() const {
        return bookNo;
    }
    Sales_data& combine(const Sales_data&);
private:
    double avg_price() const
    {
        return units_sold ? revenue / units_sold : 0 ;
    }

    // data members
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0;
};

Sales_data::Sales_data(std::istream &is) {
    // when the function body starts executing, bookNo will be empty, units_sold & revenue will be 0.
    // use 'this' to access the object as a whole, rather than a member of the object.
    // use *this to pass "this" object as an argument to the read function.
    read(is, *this); // read a transaction from is into this object.
}

Sales_data& Sales_data::combine( const Sales_data &rhs ) {
    units_sold += rhs.units_sold; // add the members of rhs into the member of 
    revenue += rhs.revenue;       // 'this' object
    return *this;                 // return the object on which the function was called 
                                
}
/*
when the transaction-processing program calls

total.combine( trans ); // update the running total

the address of total is bound to the implicit this parameter and rhs is bound to trans

*/

// non-member functions
Sales_data add(const Sales_data&, const Sales_data&);

// print returns a reference to its stream parameter, so that we can
// use the result of print as the left-hand operand of the << operator;
std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " "
        << item.revenue << " " << item.avg_price();
    return os;
}

std::istream &read(std::istream &is, Sales_data &item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}


























