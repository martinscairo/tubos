#include <Geometria.h>

std :: ostream& operator << (std :: ostream& _os, const Geometria& _geo) {
    
    _os << "Altura:  " << _geo.altura << "   Diâmetro:  " << _geo.diametro
            <<"   PTR: " << _geo.ptr << std :: endl;
    
    return _os;
}


const Geometria& Geometria :: operator= (const Geometria& _geo) {
    if (this != &_geo) {
        altura = _geo.altura;
        diametro = _geo.diametro;
        ptr = _geo.ptr;
    }
    
    return *this;
}