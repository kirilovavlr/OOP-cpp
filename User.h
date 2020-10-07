#ifndef USER_H
#define USER_H
#include<string>
#include"Cart.h"
//#include"Store.h"

class User{
    std::string username, password, address, phone;
    Cart cart;
public:
    User();
    User(const std::string& un, const std::string& pass);
    User(const std::string& un, const std::string& pass, const std::string& address, const std::string& phone);
    bool Register(const std::string& un, const std::string& pass, const std::string& address, const std::string& phone);
    bool changeUsername(const std::string& newName, const std::string& pass);
    bool changePass(const std::string& oldPass, const std::string& newPass);
    //bool buyProduct(const std::string& sku, const std::string& color, const std::string& sz, const std::string& cnt);
    bool logIn(const std::string& un, const std::string& pass) const;
    void setAddress(const std::string& address);
    void setPhone(const std::string& phone);
    const std::string& getUsername() const;
    const std::string& getAddress() const;
    const std::string& getPhone() const;
    const Cart& getCart() const;
    Cart& getCart();
    void printUserInfo() const;
    friend std::ostream& operator<<(std::ostream& output, const User& u);

};
#endif // USER_H
