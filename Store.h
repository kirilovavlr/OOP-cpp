#ifndef STORE_H
#define STORE_H
#include"Product.h"
//#include"Cart.h"
//#include"User.h"
#include<iostream>
#include<stdexcept>
#include<vector>
//#include"String.h"
class Store{
    std::vector<Product*> products;
public:
    Store();
    Store(const Store& s);
    Store& operator=(const Store& s);
    ~Store();
	bool exists(const Product& pr) const;
	void add(const Product& _product);
	void remove(std::size_t index);
	void editProduct(std::size_t index, const Product& _product);
    //void print() const;
	//friend std::ostream& operator<<(std::ostream& out, const Store& _store);
	void filterByPrice(double minPr, double maxPr) const;
    void filterByBrand(const std::string& brand) const;
    void filterByCategory(Product::Type t) const;
    void buyProduct(const Product& p);
    void listAllItems() const;
    const Product& productByInd(std::size_t ind) const;
};

#endif // STORE_H


