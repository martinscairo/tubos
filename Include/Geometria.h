#ifndef GEOMETRIA_H
#define GEOMETRIA_H

//==============================================================================
//                              INCLUDE C++
//============================================================================== 

#include <Ponto2D.h>

//==============================================================================
//                                typedef
//============================================================================== 

typedef double     Real;



class Geometria {
    
//==============================================================================
//                             função friend
//==============================================================================
    
    friend std :: ostream& operator << (std :: ostream&, const Geometria&); 
    
public:
    
//==============================================================================
//                       CONSTRUTORES E DESTRUTORA
//============================================================================== 
    
    Geometria() : altura(0), diametro (0), ptr () {};                            //construtora default
    
    Geometria (const Real _alt, const Real _diam) : altura (_alt), 
            diametro (_diam), ptr () {};
    
    Geometria(const Geometria &_orig) : altura(_orig.altura), 
            diametro (_orig.diametro), ptr (_orig.ptr) {};                       //construtora de cópia
            
    Geometria (const Real _alt, const Real _dia, const Ponto2D _ptr) :           //construtora específica
            altura (_alt), diametro (_dia), ptr(_ptr) {};
            
    Geometria (const Real _alt, const Real _dia, const Real _x, const Real _y) : //construtora específica
            altura (_alt), diametro (_dia), ptr(_x,_y) {};
            
    virtual ~Geometria() {};                                                     //destrutora
    
//==============================================================================
//                        SOBRECARGA DE OPERADORES
//============================================================================== 
    
    const Geometria& operator= (const Geometria&);
    
    
//==============================================================================
//                              FUNÇÕES INLINE
//============================================================================== 
    
    inline  const Real ALT() const {return altura;};   //exibir apenas altura
    inline  const Real DMT() const {return diametro;}; //exibir apenas diâmetro
    inline  const Ponto2D PTR() const {return ptr;};      //exibir apenas PTR   
    
    
//==============================================================================
//                          VARIÁVEIS PRIVADAS
//============================================================================== 
private:
    
    Real altura, diametro;
    Ponto2D ptr;           //localização no espaço

};

#endif /* GEOMETRIA_H */

