#include <Tubo.h>

std :: ostream& operator << (std:: ostream& _os, const Tubo& _tubo) {        
    _os << "Espessura:  " << _tubo.esp << "   Diâmetro:  " << _tubo.diametro
            <<"   Altura: " << _tubo.comprimento << "   Coord: "  
                  << _tubo.ptr <<  std :: endl;
    
    return _os;
}

std :: istream& operator >> (std:: istream& _os,  Tubo& _tubo) {
    _os >> _tubo.esp >> _tubo.diametro >> _tubo.comprimento;
    return _os;
}

Tubo concentrico (const Geometria& _geo, const Tubo& _tubo) {
         return Tubo (_tubo.esp, _tubo.diametro, _tubo.comprimento,
         (_geo.DMT()*0.5) - (_tubo.diametro*0.5 + _tubo.esp), _tubo.PTR().Y());
}


Tubo continuidade (const Tubo& _t1, const Tubo& _t2) {
          return Tubo (_t2.esp, _t2.diametro, _t2.comprimento,
                  _t2.PTR().X(), _t1.comprimento + _t1.PTR().Y());
}

Tubo PrimeiroTubo (const Tubo& _tubo, const Real& _a) {
    return Tubo (_tubo.esp, _tubo.diametro, _tubo.comprimento,
         _tubo.PTR().X(), _a);
    
}
const Tubo& Tubo:: operator= (const Tubo& _tubo) {
    if (this != &_tubo){
        comprimento = _tubo.comprimento;
        esp = _tubo.esp;
        diametro = _tubo.diametro;
        ptr = _tubo.ptr;
    }
    
    return *this;
}