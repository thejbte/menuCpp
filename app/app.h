#include "../data/data.h"
#include "../ui/ui.h"

class application {
    private:
        user usuario;
        ui interfaz;
    
    public:
        int appRun(){
            
            int retVal = 1;
            ui::options_t opt =  interfaz.getMenuOptions();
            //std::cout << "opt " <<opt -48<<std::endl;
            switch (opt - 48)
            {
            case ui::ADD:
                usuario.getInputForAdd();
                usuario.add();
                opt = ui::SHOW;
                break;
            case ui::DELETE:
                usuario.erase(0);
                break;
            case ui::MODIFY:
                int id;
                usuario.list();
                id = usuario.getInputForUpdate();  //USAR esta para delete el capturar
                if(id >= 0)
                    usuario.update(id);

                break;
            case ui::SHOW:
                usuario.list();
                break;      
            case ui::CLEAR:
                interfaz.clearScreen();
                break;   
            case ui::EXIT:
                std::cout << " end: EXIT" << std::endl;
                retVal =  0;
                break;                       
            
            default:               
                break;
            }     
            return retVal;
        }
        
};