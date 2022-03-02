#include "../common.h"
#include "../data/data.h"
#include "../ui/ui.h"


class application {
    private:
        user usuario;
        ui interfaz;

    public:
        application(const std::string& filename): usuario(filename){}
        int appRun();
        
};