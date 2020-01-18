#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
    array number i{1,2,3,5,3}
    array number p{1,2,3,5}
*/

void banner(){
    cout << R"(
     __  __                 _            ______ _  _____                        _     _            _            
    |  \/  |               | |          |  ____| |/ ____|                      (_)   | |          | |           
    | \  / | __ _ _   _  __| | ___  _ __| |__  | | |     ___  _ __   __ _ _   _ _ ___| |_ __ _  __| | ___  _ __ 
    | |\/| |/ _` | | | |/ _` |/ _ \| '__|  __| | | |    / _ \| '_ \ / _` | | | | / __| __/ _` |/ _` |/ _ \| '__|
    | |  | | (_| | |_| | (_| | (_) | |  | |____| | |___| (_) | | | | (_| | |_| | \__ \ || (_| | (_| | (_) | |   
    |_|  |_|\__,_|\__,_|\__,_|\___/|_|  |______|_|\_____\___/|_| |_|\__, |\__,_|_|___/\__\__,_|\__,_|\___/|_|   
                                                                        | |                                      
                                                                        |_|                                      
<<=============================================================================================================>
    )"<< endl;
}

bool is_capi(string capicua){
    int n;
    int longitud = capicua.size() - 1;
    if (longitud%2 != 0){
        n = (longitud +1)/2;
    }
    n = longitud/2;
    for (int i = 0; i <= n; i++){
        if (capicua[i] != capicua[longitud-i]){
            return false;
        }
    }
    return true;
}

float gen_capi(string cap){
    float capicua = 1;
    string capr = cap;
    if (is_capi(cap)){
        return stof(cap);
    }
    reverse(capr.begin(), capr.end());
    string res = to_string(stof(cap) + stof(capr));
    cout << "Numero suma " << res.substr(0, res.find(".")) << endl;
    return gen_capi(res.substr(0, res.find(".")));
}

int main(){
    banner(); 
    string capicua;
    cout << "Ingresa el numero del cual quieras generar un capicua" << endl;
    cin >> capicua;
    float resultado = gen_capi(capicua);
    cout << "El resultado es " << resultado << endl ;
    return 0;
}