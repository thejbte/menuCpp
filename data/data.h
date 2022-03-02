#include <string>
#include <stdint.h>
#include "../single_include/nlohmann/json.hpp"

/*data model*/
struct person_t {
    std::string name;
    std::string lastName;
    std::string email;
    uint8_t age;
    int id;
};

class user {
    public:
        bool add();
        bool update(int id);
        bool iSFound(int id);
        bool erase(int id);
        void list();

        void setName( std::string name);
        void setLastName( std::string name);
        void setEmail( std::string name);
        void setAge( uint8_t setAge);
        void setId( int id);
        void setVariables( const struct person_t obj);

        user(){
            /*constructor*/
             this->person.age =0;
             this->person.id =0;

            storage = {
                { std::to_string( this->person.id), {
                    {"name",  this->person.name},
                    {"last_name", this->person.lastName},
                    {"email",  this->person.email},
                    {"age",  this->person.age}
                    }
                }
            };
        }

        ~user(){
            /*destructor*/
        }
    private:
        nlohmann::json storage;
        struct person_t person;
};

