#include <iostream>
#include "data.h"
#include "../single_include/nlohmann/json.hpp"
#include <string>
#include <exception>

bool user::add(){


   nlohmann::json data= {
        { std::to_string(++id), {
            {"name", name},
            {"last_name", lastName},
            {"email", email},
            {"age", age}
            }
        }
    };

    storage.insert(data.begin() , data.end());
    return 1;
}

bool user::update(int id ){
    nlohmann::json obj = {
        {std::to_string(id), {
            {"name", name},
            {"last_name", lastName},
            {"email", email},
            {"age", age}
        }}
        };

        storage.update(obj);
    return 1;
}

bool user::erase(int id){
    auto retVal = storage.erase(std::to_string(id));
    return retVal;
}
void user::list(){
    std::cout << storage << '\n';
}

//setter

void user::setVariables(std::string name, std::string lastName, std::string email, uint8_t age){
    this->name = name;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
}


void user::getInputForAdd(){
    std::string in;
    std::cout<< "Entry Name: "<<std::endl ;
    std::cin >> this->name;

    std::cout<< "Entry last name: "<<std::endl ;
    std::cin.ignore();    // ignorar enter
    std::getline(std::cin, this->lastName);

    std::cout<< "Entry email: "<<std::endl ;
    std::cin >> this->email;

    getAgeWithException();

    
}
int user::getInputForUpdate(){
    int retVal = 0;
    std::string in;
    uint8_t inD;

    int id = getIdWithException();
    if(id == -1){
        return -1 ;
    }//else positivos
    this->id = id;

    std::cout<< "Entry Name: "<<std::endl ;
    std::cin >> in;
    if( in != "")
        this->name = in;

    std::cout<< "Entry last name: "<<std::endl ;
    std::cin >> in;
    if( in != "")
        this->lastName = in;

    std::cout<< "Entry email: "<<std::endl ;
    std::cin >> in;
    if( in != "")
        this->email = in;

    getAgeWithException(0);
    
}

void user::getAgeWithException()
{   std::string in;
    int var =1;
    while(var) {
        int count=0;
      try
      { 
         std::cout<< "Entry age: "<<std::endl ;
         std::cin >> in;
         this->age = std::stoi(in);
         var = 0;
      } 
      catch ( const std::invalid_argument  &e )
      {
         std::cout << "Invalid Input , should be numeric : " << std::endl ;
      } 
    }
}

void user::getAgeWithException(const int val )
{   std::string in;
    int var =1;
    while(var) {
        int count=0;
      try
      { 
         std::cout<< "Entry age: "<<std::endl ;
         std::cin >> in;
         if( in != "")
            this->age = std::stoi(in);
         var = 0;
         
      } 
      catch ( const std::invalid_argument  &e )
      {
         std::cout << "Invalid Input , should be numeric : " << std::endl ;
      } 
    }
}

int user::getIdWithException()
{   std::string in;
    int id;
    int var =1;
    while(var) {
        int count=0;
      try
      { //TODO: pendiente validar negativos
         std::cout<< "Entry ID for update fields or -1 for return to menu "<<std::endl ;
         std::cin >> in;
         id = std::stoi(in);
         var = 0;
         return id;
         
      } 
      catch ( const std::invalid_argument  &e )
      {
         std::cout << "Invalid Input , should be numeric : " << std::endl ;
      } 
    }
}