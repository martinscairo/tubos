/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tubos.h
 * Author: Leonardo
 *
 * Created on 19 de Abril de 2016, 11:15
 */

#ifndef TUBOS_H
#define TUBOS_H

//==============================================================================
//                              INCLUDE C++
//============================================================================== 
#include <iostream>
#include <cstdlib>
//==============================================================================
//                              TYPEDEF
//==============================================================================
typedef double      Real;

//==============================================================================
//                            CLASSE TUBOS
//==============================================================================

class Tubos {
//==============================================================================
//                           FUNÇÕES FRIEND
//==============================================================================
   
    friend std :: ostream& operator << (std :: ostream&, const Tubos&);
    friend std :: istream& operator >> (std :: istream&,  Tubos&);
    
public:

    
//==============================================================================
//                     CONSTRUTORES E DESTRUTORES
//==============================================================================
    // Construtor Default
    Tubos(): pos_x(0), pos_y(0), comprimento(0), espessura(0), diametro(0){};
    // Construtor Cópia
    Tubos(const Tubos& _orig): pos_x(_orig.pos_x), 
                               pos_y(_orig.pos_y), 
                               comprimento(_orig.comprimento), 
                               espessura(_orig.espessura),
                               diametro(_orig.diametro){};
    // Construtor Específico
    Tubos(const Real&,const Real&,const Real&,const Real&,const Real&);
    // Destrutor
    virtual ~Tubos(){};
    
//==============================================================================
//                        SOBRECARGA DE OPERADORES
//============================================================================== 
    
    const Tubos& operator= (const Tubos&);
    
//==============================================================================
//                            FUNÇÕES INLINE
//==============================================================================
    
    inline const Real X()const {return pos_x;}
    inline const Real Y()const {return pos_y;}
    inline const Real Comprimento()const {return comprimento;}
    inline const Real Espessura()const {return espessura;}
    inline const Real Diametro()const {return diametro;}
    
private:
    Real pos_x;
    Real pos_y;
    Real comprimento;
    Real espessura;
    Real diametro;

};

#endif /* TUBOS_H */

