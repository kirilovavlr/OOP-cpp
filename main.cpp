#include"String.h"
#include"Store.h"
#include"Product.h"
#include"Cart.h"
#include"User.h"
#include"Jeans.h"
#include"Belts.h"
#include"Shoes.h"
#include<iostream>
#include<fstream>
#include<vector>

bool Login(std::vector<User>& users, const std::string& un, const std::string& pass){
    for(User& user: users)
        if(user.logIn(un, pass)){
            std::cout << "You are logged in\n" << std::endl;
            return true;
        }
    std::cout << "Wrong username or password\n";
    return false;
}
bool Registration(std::vector<User>& users){
    std::cout << "Enter username, password, address and phone\n";
    std::string un, pass, ad, ph;
    std::cin >> un >> pass >> ad >> ph;
    User u;
    for(auto user: users){
        if(user.getUsername()==un){
            std::cout << "This username is already taken\n";
            return false;
        }
    }
    u.Register(un, pass, ad, ph);
    users.push_back(u);
    std::ofstream ofs("register.txt");
    if(!ofs) throw std::runtime_error("File does not exist\n");
    ofs << users.size() << std::endl;
    for(auto user: users)
        ofs << user << std::endl;
    std::cout << "Login with username and password\n";
    std::cin >> un >> pass;
    return Login(users, un, pass);
}

int main()
{
    try{
        Store s;
        Shoes s1("asdf","a","a1","a2",5.5,3,44);
        //Shoes s2(s1);
        Belts b1("gfds","b","b1","b2",6.6,1,123);
        b1.setSKU("sdfsdf");
        b1.setPrice(10);
        Jeans j1("asdfgfgg","b","c1","c2",23,23,Jeans::Sz::L);
        j1.setSize(Jeans::Sz::S);
        Shoes s2("234567", "brand", "mod", "black", 12, 5, 43);
        Jeans j2("23456", "brand", "model", "blue", 23, 6, Jeans::Sz::S);
        Belts b2("6543", "brand", "m", "white", 14, 2, 123);
        s.add(s1);
        s.add(b1);
        s.add(j1);
        s.add(s2);
        s.add(b2);
        s.add(j2);
        std::vector<User> users;
        User u;//("asdf", "asdd");
        std::ifstream ifs("register.txt");
        if(!ifs) throw std::runtime_error("Can not open file");
        int sz;
        ifs >> sz;
        std::string un, pass, ad, ph;
        while(sz--){
            ifs >> un >> pass >> ad >> ph;
            users.emplace_back(un, pass, ad, ph);
        }
        label:
        std::cout << "Choose option:\n1.Register\n2.Log in\n3.Exit\n";
        int option;
        std::cin >> option;
        switch(option){
            case 1:{
                if(!Registration(users)) goto label;
                else break;
            }
            case 2:{
                std::cout << "Login with username and password\n";
                std::string un, pass;
                std::cin >> un >> pass;
                if(!Login(users, un, pass)) goto label;
                else{
                    User u(un, pass);
                    break;
                }
            }
            case 3:
                return 0;
        }
        while(std::cin){
            std::cout << "Choose option:\n1.List all products\n2.Add product to cart\n3.Print cart\n4.Remove product from cart\n5.View cart price\n6.Pay\n7.Filter By Price\n8.Filter By Category\n9.Filter By Brand\n10.Exit\n";
            int option;
            std::cin >> option;
            //User u;
            switch(option){
                case 1:{
                    s.listAllItems();
                    break;
                }
                case 2:{
                    std::cout << "Choose product by index\n";
                    s.listAllItems();
                    std::size_t ind;
                    std::cin >> ind;
                    u.getCart().addProduct(s.productByInd(ind));
                    break;
                }
                case 3:{
                    u.getCart().printCart();
                    break;
                }
                case 4:{
                    std::cout << "Remove product by index\n";
                    u.getCart().printCart();
                    std::size_t ind;
                    std::cin >> ind;
                    u.getCart().removeProductByInd(ind);
                    break;
                }
                case 5:{
                    std::cout << "Your cart price is " << u.getCart().getPrice() << "\n";
                    break;
                }
                case 6:{
                    u.getCart().pay(s);
                    std::cout << "Payment successful\n";
                    break;
                }
                case 7:{
                    double minPr, maxPr;
                    std::cout << "Enter min price:\n";
                    std::cin >> minPr;
                    std::cout << "Enter max price:\n";
                    std::cin >> maxPr;
                    s.filterByPrice(minPr, maxPr);
                    break;
                }
                case 8:{
                    int type;
                    std::cout << "Select type\n1.Jeans\n2.Shoes\n3.Belts\n";
                    std::cin >> type;
                    switch(type){
                    case 1:
                        s.filterByCategory(Product::Type::Jeans);
                        break;
                    case 2:
                        s.filterByCategory(Product::Type::Shoes);
                        break;
                    case 3:
                        s.filterByCategory(Product::Type::Belts);
                        break;
                    }
                    break;
                }
                case 9:{
                    std::string br;
                    std::cout << "Choose brand: a, b, brand\n";
                    std::cin >> br;
                    s.filterByBrand(br);
                    break;
                }
                case 10:
                    return 0;
            }
        }
    }
    catch(const std::exception& e){
    std::cerr << e.what() << std::endl;
    }
}
