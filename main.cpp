
#include <iostream>
#include "single_include/nlohmann/json.hpp"
#include "app/app.h"
using json = nlohmann::json;

int main(){
   /* user usuario;
    ui interfaz;
    usuario.setVariables("julian","Bustamante","@gmai.com",29);
    usuario.add();
    usuario.list();

    usuario.setVariables("Isaac","Bustamante","isaac@gmail.com",2);
    usuario.update(0);
    usuario.list();

    if(usuario.erase(3) == 1 )
        usuario.list();
    interfaz.clearScreen();*/

application app;
int ret = 1;
while(ret){
    ret = app.appRun();
}
    return 0;
}