
#include <stdlib.h> //system
#include <iomanip>
#include <iostream>
#include  <stdint.h>

#define MAX_AGE     128

// interfaz de usuario consola
class ui {
    public:
       typedef enum {
            EXIT = 0,
            ADD = 1,
            MODIFY,
            DELETE,
            SHOW,
            CLEAR,
            MENU,

        }options_t;

        ui();

        void clearScreen();
        options_t getMenuOptions();
        struct person_t getInputForAdd();
        struct person_t getInputForUpdate(int id);
        int getIdWithException();

    private:
        uint8_t indexPage;
        options_t opt;
        int16_t getAgeWithException();
        int16_t getAgeWithException(const int val );


};