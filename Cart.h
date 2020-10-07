#ifndef CART_H
#define CART_H
#include"Product.h"
#include"Store.h"
//#include"Vector.h"
#include<vector>
#include<string>
class Cart{
    std::vector<Product*> cart;
    double price;
    bool payment;//=false;
public:
    Cart();
    Cart(const Cart& s);
    Cart& operator=(const Cart& s);
    ~Cart();
    unsigned int getCnt() const;
    double getPrice() const;
    void addProduct(const Product& p);
    void removeProduct(const Product& p);
    bool pay(Store& s);
    void clearCart();
    void printCart() const;
    void removeProductByInd(std::size_t ind);
};

#endif // CART_H
