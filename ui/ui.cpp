#include "ui.h"
#include "../data/data.h"
ui::ui(){
    indexPage = MENU;
    opt = MENU;
}

void ui::clearScreen(){
    //mi OS es linux, esto es por si tienen mac o win
    #if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
        system("cls"); 
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || defined (__APPLE__)
        system("clear");
    #endif
}

ui::options_t ui::getMenuOptions(){

    std::cout << std::endl << LOGO ;
    std::cout << KYEL << "------------------------------------------------------------"<<std::endl;
    std::cout<< std::setw(39) << "* Available options *"  <<std::endl;
    std::cout<< "------------------------------------------------------------" <<std::endl;
    
    std::cout<< "1. Create" << std::endl;
    std::cout<< "2. Modify" << std::endl;
    std::cout<< "3. Delete" << std::endl;
    std::cout<< "4. Show" << std::endl;
    std::cout<< "5. Clear screen" << std::endl <<std::endl;

    std::cout<< "0. Exit" << std::endl;

    std::cout<< "------------------------------------------------------------"<< KNRM <<std::endl<<std::endl;

    std::cout<< "Type the option: " ;

    std::cin >> indexPage;
    opt =options_t(indexPage) ;

    if( ( opt - 48 != ADD) && ( opt - 48 != DELETE) && ( opt-48 != MODIFY) && ( opt-48 != SHOW) && ( opt-48 != EXIT) && ( opt-48 != CLEAR)){
        opt = MENU;
        std::cout<< "Retry again, bad option: " << std::endl;
        }
    
    return opt;
}

