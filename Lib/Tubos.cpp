/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tubos.cpp
 * Author: Leonardo
 * 
 * Created on 19 de Abril de 2016, 11:15
 */

#include <Tubos.h>


//==============================================================================
//                           FUNÇÕES FRIEND
//==============================================================================
   
std :: ostream& operator << (std :: ostream& _os, const Tubos& _tubos)
{
    _os << "Coordenada do tubo: ("<< _tubos.pos_x <<"," << _tubos.pos_y <<")" 
        << " Comprimento do Tubo:" << _tubos.comprimento 
        << " Expessura do Tubo:"   << _tubos.espessura   
        << " Diâmetro do Tubo:"    << _tubos.diametro << std:: endl;
    return _os;
}

std :: istream &operator >> (std :: istream&_os,  Tubos &_ret){
	_os >> _ret.pos_x >> _ret.pos_y >> _ret.comprimento >> _ret.espessura >> _ret.diametro;
	return _os;
}

//==============================================================================
//                     CONSTRUTORES E DESTRUTORES
//==============================================================================

//Construtor Específico
Tubos:: Tubos(const Real& _posx,const Real& _posy,const Real&_comp,const Real&_exp,const Real&_dia)
{
    pos_x = _posx;
    pos_y = _posy;
    comprimento = _comp;
    espessura = _exp;
    diametro = _dia;
}

//==============================================================================
//                        SOBRECARGA DE OPERADORES
//============================================================================== 
    
const Tubos& Tubos :: operator= (const Tubos&_tubo)
{
    if(this != &_tubo)
    {
    pos_x = _tubo.pos_x;
    pos_y = _tubo.pos_y;
    comprimento = _tubo.comprimento;
    espessura = _tubo.espessura;
    diametro = _tubo.diametro;
    }
return *this;
}


