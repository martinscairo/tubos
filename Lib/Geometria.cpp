/* 
 * File:   Geometria.cpp
 * Author: Leonardo
 * 
 * Created on 19 de Abril de 2016, 11:08
 */

#include <Geometria.h>

//==============================================================================
//                           FUNÇÕES FRIEND
//==============================================================================


std :: ostream& operator << (std :: ostream& _os, const Geometria& _geo)
{
    _os << "Coordenada do Poço: ("<< _geo.pos_x_poco <<"," << _geo.pos_y_poco <<")"
        << " Altura do Poço:" << _geo.altura_poco    
        << " Diâmetro do Poço:"    << _geo.diametro_poco<< std:: endl;
    return _os;
}

//==============================================================================
//                       SOBRECARGA DE OPERADORES
//==============================================================================
    
    const Geometria& Geometria :: operator = (const Geometria &_geo)
    {
        if (this!=&_geo)
        {
        pos_x_poco = _geo.pos_x_poco;
        pos_y_poco = _geo.pos_y_poco;
        altura_poco = _geo.altura_poco;
        diametro_poco = _geo.diametro_poco ;   
        }
        return *this;
    }



