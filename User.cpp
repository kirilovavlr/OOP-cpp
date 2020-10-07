#include"User.h"
#include<fstream>
User::User() {}
User::User(const std::string& un, const std::string& pass): username(un), password(pass) {}
User::User(const std::string& un, const std::string& pass, const std::string& address, const std::string& phone):
    username(un), password(pass), address(address), phone(phone) {}
bool User::Register(const std::string& un, const std::string& pass, const std::string& address, const std::string& phone){
    username=un;
    password=pass;
    setAddress(address);
    setPhone(phone);
    return true;
}
bool User::changeUsername(const std::string& newName, const std::string& pass){
    if(pass!=password) return false;
    username=newName;
    return true;
}
bool User::changePass(const std::string& oldPass, const std::string& newPass){
    if(oldPass!=password) return false;
    password=newPass;
    return true;
}
bool User::logIn(const std::string& un, const std::string& pass) const{
    if(un==username && pass==password) return true;
    return false;
}
void User::setAddress(const std::string& ad){
    address=ad;
}
void User::setPhone(const std::string& ph){
    phone=ph;
}
const std::string& User::getUsername() const{
    return username;
}
const std::string& User::getAddress() const{
    return address;
}
const std::string& User::getPhone() const{
    return phone;
}
const Cart& User::getCart() const{
    return cart;
}
Cart& User::getCart(){
    return cart;
}
void User::printUserInfo() const{
    std::cout << getUsername() << std::endl;
    std::cout << getAddress() << std::endl;
    std::cout << getPhone() << std::endl;
}
std::ostream& operator<<(std::ostream& output, const User& u){
    output << u.getUsername() << std::endl;
    output << u.password << std::endl;
    output << u.getAddress() << std::endl;
    output << u.getPhone() << std::endl;
    return output;
}
