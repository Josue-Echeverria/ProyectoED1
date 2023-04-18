#include "Cliente.h"


//DEFINICION D FUNCIONES DE CLASE CLIENTE--------------------------------------------------------------------

std::string Cliente::to_string(){
    return "Codigo: "+Codigo+"\nNombre: "+Nombre+"\nPrioridad: "+std::to_string(Prioridad)+"\n";
}

//----------------------------------------------------------------------------------------------

std::string *adv_tokenizer(std::string s, char del)
{
    std::string *str_return = new std::string[5];
    std::stringstream ss(s);
    std::string word;
    int counter = 0;
    while (!ss.eof()) {
        getline(ss, word, del);
        str_return[counter]= word;
        counter++;
    }
    return str_return;
}




int pos_d_cliente(std::string nombre_x_buscar,Cliente* Clientes,int largo){
    if(Clientes){// Confirma que el array de clientes no sea NULL
        for(int i = 0;i<largo;i++){
            if (Clientes[i].Codigo == nombre_x_buscar){
                return i;
            }
        }
    }
    return -1;
}
