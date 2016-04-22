#include <Tubo.h>

std :: ostream& operator << (std:: ostream& _os, const Tubo& _tubo) {        
    _os << "Espessura:  " << _tubo.esp << "   Diâmetro:  " << _tubo.diametro
            <<"   Altura: " << _tubo.altura << "   Centro:"  
                  << _tubo.centro <<  std :: endl;
    
    return _os;
}

std :: istream& operator >> (std:: istream& _os,  Tubo& _tubo) {
    _os >> _tubo.esp >> _tubo.diametro >> _tubo.altura >> _tubo.centro;
    return _os;
}


const Tubo& Tubo:: operator= (const Tubo& _tubo) {
    if (this != &_tubo){
        altura = _tubo.altura;
        esp = _tubo.esp;
        diametro = _tubo.diametro;
        centro = _tubo.centro;
    }
    
    return *this;
}