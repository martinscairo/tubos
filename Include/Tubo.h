

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



class Tubo{
    
//==============================================================================
//                             função friend
//==============================================================================
    friend std :: ostream& operator << (std:: ostream&, const Tubo&);
    friend std :: istream& operator >> (std:: istream&,  Tubo&);
    friend Tubo concentrico (const Geometria&, const Tubo&);
    friend Tubo continuidade (const Tubo&, const Tubo&);
    friend Tubo PrimeiroTubo (const Tubo&, const Real&);
    
public:
    
    
//==============================================================================
//                       CONSTRUTORES E DESTRUTORA
//============================================================================== 
    
    Tubo() : esp (0), diametro (0), comprimento (0), ptr () {};
    
    Tubo(const Tubo& _orig): esp (_orig.esp), diametro (_orig.diametro),
        comprimento(_orig.comprimento), ptr (_orig.ptr) {};
            
    Tubo (const Real _esp, const Real _dia, const Real _alt) :
        esp (_esp), diametro (_dia), comprimento (_alt), ptr () {};
    
    Tubo (const Real _esp, const Real _dia, const Real _alt, 
                const Ponto2D _centro): 
         esp (_esp), diametro (_dia), comprimento (_alt), ptr (_centro) {};
            
    Tubo (const Real _esp, const Real _dia, const Real _alt,
       const Real _x, const Real _y) : 
           esp (_esp), diametro (_dia), comprimento (_alt), ptr (_x,_y) {};
            
    virtual ~Tubo() {};
    
    
//==============================================================================
//                              FUNÇÕES INLINE
//============================================================================== 
    
    inline  const Real ESP() const    {return esp;};   //exibir apenas espessura
    inline  Ponto2D PTR()    const  {return ptr;};   //exibir apenas centro  
    inline  const Real CMP() const    {return comprimento;};   //exibir apenas altura
    inline  const Real DMT() const    {return diametro;}; //exibir apenas diâmetro
    
//==============================================================================
//                        SOBRECARGA DE OPERADORES
//============================================================================== 
    
    const Tubo& operator= (const Tubo&);
    
    
//==============================================================================
//                          VARIÁVEIS PRIVADAS
//==============================================================================    
 
 private:
    Real     esp, comprimento, diametro; //DIAMETRO INTERNO
    Ponto2D  ptr;

};

#endif /* TUBO_H */

