#ifndef PRODUCT_H
#define PRODUCT_H
#include<iostream>
#include<string>
//using namespace std;

class Product
{
    std::string SKU, Brand, Model, Color;
    double Price;
    int Count;
public:
    enum class Type{
        Shoes, Belts, Jeans
    };
private:
    Type T;
public:
    Product();
    Product(const std::string& sku, const std::string& brand, const std::string& model, const std::string& color, double price, int cnt, Type t);
    void setSKU(const std::string& sku);
    void setBrand(const std::string& brand);
    void setModel(const std::string& model);
    void setColor(const std::string& color);
    void setPrice(double price);
    void setT(Type t);
    void setCount(int cnt);
    const std::string& getSKU() const;
    const std::string& getBrand() const;
    const std::string& getModel() const;
    const std::string& getColor() const;
    double getPrice() const;
    Type getT() const;
    int getCount() const;
    void buyProduct();
    //friend std::istream& operator>>(std::istream& input, Product& p);
    friend std::ostream& operator<<(std::ostream& output, const Product& p);
    virtual Product* clone() const=0;
    bool operator==(const Product& p) const;
    virtual ~Product()=default;
    virtual void print(std::ostream& os) const;

};
#endif

