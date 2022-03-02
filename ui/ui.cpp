#include "ui.h"
#include "../data/data.h"
#include "../common.h"
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

    std::cout << std::endl << LOGO 
                        << KBLU <<"V" << athmost_VERSION_MAJOR  << "." 
                        << athmost_VERSION_MINOR  << "." 
                        << athmost_VERSION_PATCH  << KNRM <<std::endl;
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
        std::cout<< KRED << "Retry again, bad option: " << KNRM << std::endl;
        }
    
    return opt;
}


struct person_t ui::getInputForAdd(){
    struct person_t person;

    std::string in;
    std::cout<< "Entry Name: "<<std::endl ;
    std::cin >> person.name;
    

    std::cout<< "Entry last name: "<<std::endl ;
    std::cin.ignore();    // ignorar enter
    std::getline(std::cin, person.lastName);

    std::cout<< "Entry email: "<<std::endl ;
    std::cin >> person.email;

    person.age = getAgeWithException();
    return person;    
}
struct person_t ui::getInputForUpdate(int id){
    struct person_t person;
    std::string in;

    if(id == -1){
        person.id = -1;
        return person;
    }//else positivos
    person.id = id;

    std::cout<< "Entry Name: "<<std::endl ;
    std::cin >> in;
    if( in != "")
        person.name = in;

    std::cout<< "Entry last name: "<<std::endl ;
    std::cin.ignore();    // ignorar enter
    std::getline(std::cin, in);
    if( in != "")
        person.lastName = in;

    std::cout<< "Entry email: "<<std::endl ;
    std::cin >> in;
    if( in != "")
        person.email = in;

    person.age = getAgeWithException(0);
    return person; 
}

int16_t ui::getAgeWithException()
{   std::string in;
    int var =1;
    int16_t age;
    while(var) {
        int count=0;
      try
      { 
         std::cout<< "Entry age: "<<std::endl ;
         std::cin >> in;
         age = std::stoi(in);
         if(age >=0 && age < MAX_AGE ){
            var = 0;
         }else {
            std::cout << KRED << "Invalid Input , should be a valid Age." << KNRM << std::endl ;
            var = 1;
         }
      } 
      catch ( const std::invalid_argument  &e )
      {
         std::cout << KRED << "Invalid Input , should be numeric : " << KNRM << std::endl ;
      } 
    }
    return age;
}

int16_t ui::getAgeWithException(const int val )
{   std::string in;
    int var =1;
    int16_t age;
    while(var) {
        int count=0;
      try
      { 
         std::cout<< "Entry age: "<<std::endl ;
         std::cin >> in;
         if( in != "")
            age = std::stoi(in);
         if(age >=0 && age < MAX_AGE ){
            var = 0;
         }else {
            std::cout << KRED << "Invalid Input , should be a valid Age." << KNRM << std::endl ;
            var = 1;
         }
      } 
      catch ( const std::invalid_argument  &e )
      {
         std::cout << KRED << "Invalid Input , should be numeric : " << KNRM<< std::endl ;
      } 
    }
    return age;
}

int ui::getIdWithException()
{   std::string in;
    int id;
    int var =1;
    while(var) {
        int count=0;
      try
      { //TODO: pendiente validar negativos
         std::cout<< "\nEntry ID for update/delete fields or -1 for return to menu: "<<std::endl ;
         std::cin >> in;
         id = std::stoi(in);
         var = 0;
      } 
      catch ( const std::invalid_argument  &e )
      {
         std::cout << KRED << "Invalid Input , should be numeric : " << KNRM << std::endl ;
      } 
    }
    return id;
}