

#ifndef TUBO_H
#define TUBO_H

//==============================================================================
//                              INCLUDE C++
//============================================================================== 

#include <Ponto2D.h>
#include <Geometria.h>
#include <iostream>

//==============================================================================
//                                typedef
//============================================================================== 
typedef double Real;



class Tubo {
    
//==============================================================================
//                             função friend
//==============================================================================
    friend std :: ostream& operator << (std:: ostream&, const Tubo&);
    friend std :: istream& operator >> (std:: istream&,  Tubo&);
    
public:
    
    
//==============================================================================
//                       CONSTRUTORES E DESTRUTORA
//============================================================================== 
    
    Tubo() : esp (0), diametro (0), altura (0), centro () {};
    
    Tubo(const Tubo& _orig): esp (_orig.esp), diametro (_orig.diametro),
            altura(_orig.altura), centro (_orig.centro) {};
    
    Tubo (const Real _esp, const Real _dia, const Real _alt, 
                const Ponto2D _centro): 
         esp (_esp), diametro (_dia), altura (_alt), centro (_centro) {};
            
    Tubo (const Real _esp, const Real _dia, const Real _alt,
       const Real _x, const Real _y) : 
           esp (_esp), diametro (_dia), altura (_alt), centro (_x,_y) {};
            
    virtual ~Tubo() {};
    
    
//==============================================================================
//                              FUNÇÕES INLINE
//============================================================================== 
    
    inline  const Real ESP() const {return esp;};   //exibir apenas espessura
    inline  const Ponto2D CTR() const {return centro;};   //exibir apenas centro  
    inline  const Real ALT() const {return altura;};   //exibir apenas altura
    inline  const Real DMT() const {return diametro;}; //exibir apenas diâmetro
    
//==============================================================================
//                        SOBRECARGA DE OPERADORES
//============================================================================== 
    
    const Tubo& operator= (const Tubo&);
    
    
//==============================================================================
//                          VARIÁVEIS PRIVADAS
//==============================================================================    
    
private:
    Real     esp, altura, diametro; 
    Ponto2D  centro;

};

#endif /* TUBO_H */

