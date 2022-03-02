#include "app.h"

int application::appRun(){
    
    int retVal = 1;
    ui::options_t opt =  interfaz.getMenuOptions();
    switch (opt - 48)
    {
    case ui::ADD:
        usuario.setVariables( interfaz.getInputForAdd() );
        usuario.add() ;
        std::cout << KGRN << "Creation Successful.!"<< KNRM <<std::endl;

        opt = ui::SHOW;
        break;

    case ui::DELETE:{
        usuario.list();
        int id = interfaz.getIdWithException();
        if( true == usuario.iSFound(id) ){
            if(id >= 0){
                auto res = usuario.erase(id);
                if(1 == res)
                    std::cout << KGRN <<"Erase Successful.!"<< KNRM <<std::endl;
                }
        }
        }
        break;
    case ui::MODIFY:{
        struct person_t p ;
        usuario.list();
        int id = interfaz.getIdWithException();
        if( true == usuario.iSFound(id) ){
            p = interfaz.getInputForUpdate(id); 
            usuario.setVariables(p);
            if(p.id >= 0){
                usuario.update(p.id);
                std::cout << KGRN << "Update Successful.!"<<  KNRM <<std::endl;
                }
        }
    }
        break;
    case ui::SHOW:{
        usuario.list();
        std::cout<< "Entry any key and hit enter to continue: "<<std::endl ;
        std::string in;
        std::cin >> in ;
        }
        break;      
    case ui::CLEAR:
        interfaz.clearScreen();
        break;   
    case ui::EXIT:
        std::cout << KGRN << " end: EXIT" << KNRM << std::endl;
        retVal =  0;
        break;                       
    
    default:               
        break;
    }     
    return retVal;
}