
#include <iostream>
#include "single_include/nlohmann/json.hpp"
#include "app/app.h"
using json = nlohmann::json;

int main(){

application app;
int ret = 1;

while(ret){
    ret = app.appRun();
}
    return 0;
}