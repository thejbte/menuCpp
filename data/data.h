#include <string>
#include <stdint.h>
#include "../single_include/nlohmann/json.hpp"
/*
La prueba en cuestión es la siguiente: 
·        Desarrolle una clase que cumpla con las siguientes funciones para crear, modificar, eliminar,
         listar el modelo. (Para el proceso de guardado puede usar archivos locales con Pickle o JSON)
·        Generar UI vía interfaz de comandos para usar las diferentes funciones. 
El modelo para la clase es un usuario con datos simples como:

·        Nombres ,Apellidos , Edad,  Email
*/
class user {
    public:
        bool add();
        bool update(int id);
        bool erase(int id);
        void list();

        void setVariables(std::string name, std::string lastName, std::string email, uint8_t age);
        void getInputForAdd();
        int getInputForUpdate();
        user(){
            /*constructor*/
            age =0;
            id =0;

            storage = {
                { std::to_string(id), {
                    {"name", name},
                    {"last_name", lastName},
                    {"email", email},
                    {"age", age}
                    }
                }
            };
        }

        ~user(){
            /*destructor*/
        }
    private:
        nlohmann::json storage;
        std::string name;
        std::string lastName;
        std::string email;
        uint8_t age;
        int id;
        // overload function
        void getAgeWithException();
        void getAgeWithException(const int val );
        int getIdWithException();
};

