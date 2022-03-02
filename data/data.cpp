#include <iostream>
#include "data.h"
#include "../single_include/nlohmann/json.hpp"
#include <string>
#include <exception>
#include "../common.h"

bool user::add(){

   nlohmann::json data= {
        { std::to_string(++person.id), {
            {"name", person.name},
            {"last_name", person.lastName},
            {"email", person.email},
            {"age", person.age}
            }
        }
    };

    storage.insert(data.begin() , data.end());
    return 1;
}

bool user::update(int id ){
    nlohmann::json obj = {
        {std::to_string(id), {
            {"name", person.name},
            {"last_name", person.lastName},
            {"email", person.email},
            {"age", person.age}
        }}
        };
        
        storage.update(obj);
    return 1;
}

bool user::iSFound(int id){
    bool retVal = false;
    auto var = storage.find(std::to_string(id));
    if( (var != storage.end()) == true )
        retVal = true;
    else{
        std::cout << KNRM << "Id: \""<< id <<"\" Do not was found. " << '\n';
        retVal = false;
    }
    return retVal;
    
}

bool user::erase(int id){
    auto retVal = storage.erase(std::to_string(id));
    return retVal;
}
void user::list(){
    std::cout << storage << '\n';
}
void user::setName( std::string name){
    this->person.name = name;
}

void user::setLastName( std::string lastName){
    this->person.lastName = lastName;
}

void user::setEmail( std::string email){
    this->person.email = email;
}

void user::setAge( uint8_t age){
    this->person.age = age;
}

void user::setId( int id){
    this->person.id = id;
}

void user::setVariables( const struct person_t obj){
    this->person.name = obj.name;
    this->person.lastName = obj.lastName;
    this->person.email = obj.email;
    this->person.age = obj.age;
}