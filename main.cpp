
/* 
 * Objetivo: Desenvolver classe Geometria para armazenar tubos e furos, assim como
 * suas proporções;
 * Author: Leonardo Oliveira Thimoteo
 * Status: Em andamento
 * Created on 19 de Abril de 2016, 11:05
 */

#include <cstdlib>
#include <Geometria.h>
#include <Tubos.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>

//******************************************************************************
//                                typedef
//******************************************************************************

    typedef std :: vector <Tubos>                Vector;
    
//******************************************************************************
//                      FUNÇÃO CONTINUIDADE DE TUBOS
//******************************************************************************   
    int Furo_Tubo (const Geometria, const Tubos);
    const bool Conti (const Tubos, const Tubos);
    
int main(int argc, char** argv) {
    
    Geometria g1(100,100); //variável que contêm o valor e dimensão do poço
    Tubos t2, t6;              //variável que vai assumir os valores do arquivo externo
    Vector vetor_Tubos, tubos;    //declaração do vetor tubos, que será compostos por elementos do tipo tubo
    
    std :: ifstream input("tubos.txt"); //PRECISA EXISTIR
    if (!input){
        std :: cerr << "Arquivo inexistente" << std :: endl;
        abort ();
    }
    for (int i=0; !input.eof(); i++){
       input >> t2;
        if (Furo_Tubo(g1, t2)==1 || Furo_Tubo(g1, t2) ==2){
         vetor_Tubos.push_back(t2); // neste ponto estou inicializando o tamanho o meu vetor
        } 
    }
    input.close ();
    
    //std:: cout << vetor_Tubos.size();
    std:: cout << Conti (vetor_Tubos[0], vetor_Tubos[1]);
    for (int i=0;i<vetor_Tubos.size();i++){ 
        if (vetor_Tubos[i].Y()<= g1.POSY() && 
            vetor_Tubos[i].Diametro()>t6.Diametro())
        {
            t6= vetor_Tubos[i];
        } 
    }
    tubos.push_back(t6);
    t6;
    //std:: cout << tubos.size();
   
    for (int i=0;i<vetor_Tubos.size();i++){ 
        for (int n=0;n<vetor_Tubos.size();n++){ 
            
            
    }
    }

    return 0;
    
   
}
    


const bool Conti (const Tubos _t1, const Tubos _t2){
    return _t1.Y() + _t1.Comprimento() == _t2.Y() && 
           _t1.Diametro() > _t2.Diametro();
    
}
int Furo_Tubo (const Geometria _geo, const Tubos _tubo){
    
    if(_geo.Diam_Poco()>= _tubo.Diametro()+ (2*_tubo.Espessura()) &&
       _geo.Alt_Poco() >= _tubo.Comprimento() &&
       _geo.POSX() <= _tubo.X() && _tubo.X() <= _geo.POSX()+_geo.Diam_Poco() &&
       _geo.POSY() <= _tubo.Y() && _tubo.Y() <= _geo.POSY()+_geo.Alt_Poco())
    {
        return 1;
    }
    else if ((_geo.Diam_Poco()>= _tubo.Diametro()+ (2*_tubo.Espessura()) &&
       _geo.POSY()+_geo.Alt_Poco() >= _tubo.Y() + _tubo.Comprimento() &&
       _geo.POSX() <= _tubo.X() && _tubo.X() <= _geo.POSX()+_geo.Diam_Poco()))
    {
        return 2;
    }
}