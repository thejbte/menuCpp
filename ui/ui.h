
#include <stdlib.h> //system
#include <iomanip>
#include <iostream>
#include  <stdint.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"


#define LOGO        \
                    " █████╗ ████████╗██╗  ██╗███╗   ███╗ ██████╗ ███████╗""\n"\
                    "██╔══██╗╚══██╔══╝██║  ██║████╗ ████║██╔═══██╗██╔════╝""\n"\
                    "███████║   ██║   ███████║██╔████╔██║██║   ██║███████╗""\n"\
                    "██╔══██║   ██║   ██╔══██║██║╚██╔╝██║██║   ██║╚════██║""\n"\
                    "██║  ██║   ██║   ██║  ██║██║ ╚═╝ ██║╚██████╔╝███████║""\n"\
                    "╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝     ╚═╝ ╚═════╝ ╚══════╝""\n"

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


    private:
        uint8_t indexPage;
        options_t opt;
        int getMenuInput(){
            return 1;
        }

};