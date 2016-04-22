/* 
 * File:   Geometria.h
 * Author: Leonardo
 *
 * Created on 19 de Abril de 2016, 11:08
 */

#ifndef GEOMETRIA_H
#define GEOMETRIA_H

//==============================================================================
//                              INCLUDE C++
//============================================================================== 
#include <iostream>
#include <cstdlib>
//==============================================================================
//                              TYPEDEF
//==============================================================================

typedef double      Real;

class Geometria {
//==============================================================================
//                           FUNÇÕES FRIEND
//==============================================================================

friend std :: ostream& operator << (std :: ostream&, const Geometria&);

public:
    

    
//==============================================================================
//                     CONSTRUTORES E DESTRUTORES
//==============================================================================
    //Construtor Default
    Geometria():pos_x_poco(0),pos_y_poco(0),altura_poco(0),diametro_poco(0){} ;
    //Construtor Cópia
    Geometria(const Geometria& _orig): pos_x_poco(_orig.pos_x_poco),
                                       pos_y_poco(_orig.pos_y_poco),
                                       altura_poco(_orig.altura_poco),
                                       diametro_poco(_orig.diametro_poco){} ;
    //Construtor Específico
    Geometria (const Real& _altpoco, const Real&_diapoco):pos_x_poco(0),
                                       pos_y_poco(0),
                                       altura_poco(_altpoco),
                                       diametro_poco(_diapoco){} ;
    //Destrutor
    virtual ~Geometria(){};
    
//==============================================================================
//                       SOBRECARGA DE OPERADORES
//==============================================================================
    
    const Geometria& operator = (const Geometria &); 
    
//==============================================================================
//                           FUNÇÕES INLINE
//==============================================================================
    
    inline const Real POSX() const {return pos_x_poco;}
    inline const Real POSY() const {return pos_y_poco;}
    inline const Real Alt_Poco() const {return altura_poco;}
    inline const Real Diam_Poco() const {return diametro_poco;}
    
private:
    Real pos_x_poco;
    Real pos_y_poco;
    Real altura_poco;
    Real diametro_poco;
    
    

};

#endif /* GEOMETRIA_H */

