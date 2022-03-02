
#include <iostream>
#include "single_include/nlohmann/json.hpp"
#include "app/app.h"

int main(){

application app("../storage.json");
int ret = 1;

while(ret){
    ret = app.appRun();
}
    return 0;
}