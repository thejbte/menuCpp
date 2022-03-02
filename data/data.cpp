#include <iostream>
#include "data.h"
#include "../single_include/nlohmann/json.hpp"
#include <string>
#include <exception>
#include "../common.h"

#include <fstream>
namespace JSONUTILS 
{
    static const nlohmann::json openfile(const std::string& filename)
    {
        std::ifstream i(filename);
        nlohmann::json j; 
        i >> j;
        return j;
    }

    static void writeTofile(const std::string& filename , nlohmann::json data )
    {
        std::ofstream o(filename);
        //nlohmann::json j; 
        o << std::setw(4)  << data << std::endl;
    }
}

user::user(){
    /*constructor*/
        try{
            storage = JSONUTILS::openfile("../storage.json");
        }
        catch (nlohmann::json::exception& e) {
            this->person.id = 0;
            person_t person ={.name ="Julian", .lastName="Narvaez", .email="thejbte@gmail.com", .age=30,.id=0};
            setVariables(person);

            storage = {
                { std::to_string( this->person.id), {
                    {"name",  this->person.name},
                    {"last_name", this->person.lastName},
                    {"email",  this->person.email},
                    {"age",  this->person.age}
                    }
                }
            };
            JSONUTILS::writeTofile("../storage.json",storage );
            std::cout << KRED << "File empty: " << KNRM << std::endl ;

        }
        this->person.age =0;

        //buscar en el archivo json el ultimo dato  por objetos
        int i=0;
        for(  i =0; (this->iSFound(i) > 0 ) ; i++){
        }
        this->person.id =i;
        


}

bool user::add(){
    if(this->iSFound(person.id) == 0){
        nlohmann::json data= {
            { std::to_string(person.id++), {
                {"name", person.name},
                {"last_name", person.lastName},
                {"email", person.email},
                {"age", person.age}
                }
            }
        };
        
        storage.insert(data.begin() , data.end());
        JSONUTILS::writeTofile("../storage.json",storage );
        return 1;
    }

    return 0;
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
        JSONUTILS::writeTofile("../storage.json",storage );
    return 1;
}

bool user::iSFound(int id){
    bool retVal = false;
    auto var = storage.find(std::to_string(id));
    if( (var != storage.end()) == true )
        retVal = true;
    else{
        std::cout << KRED << "Id: \""<< id <<"\" Do not was found. " << KNRM << '\n';
        retVal = false;
    }
    return retVal;
    
}

bool user::erase(int id){
    auto retVal = storage.erase(std::to_string(id));
    JSONUTILS::writeTofile("../storage.json",storage );
    return retVal;
}
void user::list(){
    std::cout << std::setw(4) << storage << '\n';
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