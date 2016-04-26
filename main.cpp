
//Desenvolver classe Geometria para criar tubos e poço, bem como
//suas propriedades;
//Autores: Leonardo Thimoteo e Cairo Martins
//Status: Completo
//Created on 17 de Abril de 2016, 11:05
 

//******************************************************************************
//                             C++ INCLUDES
//******************************************************************************
#include <cstdlib>
#include <Geometria.h>
#include <Tubo.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>

//******************************************************************************
//                                typedef
//******************************************************************************

    typedef std :: vector <Tubo>                Vector; //declara vetor de tubos
    
//******************************************************************************
//                               protótipos
//******************************************************************************   
    const bool Furo_Tubo (const Geometria, const Tubo);
    
//******************************************************************************
//                            Main function
//******************************************************************************
int main() {
    
    Geometria g1(100,100);                   //variável que contêm o valor e dimensão do poço
    Tubo t2, t6 (1,2,3);                     //variável que vai assumir os valores do arquivo externo
    Vector vetor_Tubos, tubos;               //declaração do vetor tubos, que será compostos por elementos do tipo tubo
    
    std :: ifstream input("tubos.txt"); //PRECISA EXISTIR
    if (!input){
        std :: cerr << "Arquivo inexistente" << std :: endl;
        abort ();
    }

//Assimilando tubos do arquivo externo
    
    for (int i=0; !input.eof(); i++){
           if (Furo_Tubo(g1, t2)){
            input >> t2;           
            vetor_Tubos.push_back(concentrico (g1, t2));  //preenchendo o vetor com os tubos
        } 
    }
    input.close ();
    
//Imprime vetores do arquivo externo
    
    for(int i=0; i<vetor_Tubos.size(); i++){
        std :: cout << "item: " << vetor_Tubos[i];
    }
    
   
//Ordenando os tubos por ordem de diâmetro
    
   Tubo t1;      //variável auxiliar, tipo tubo
   
   for(int i=0; i<vetor_Tubos.size(); i++){
        for (int m=0; m<vetor_Tubos.size(); m++){
           if (vetor_Tubos[i].DMT() > vetor_Tubos[m].DMT()){
                t1 = vetor_Tubos[i];
                vetor_Tubos[i] = vetor_Tubos[m];
                vetor_Tubos[m] = t1;
          }
       }
    }
    
    std:: cout << "\n\n";
    
//Imprime vetor ordenado
    
     for(int i=0; i<vetor_Tubos.size(); i++){
        std :: cout << "item: " << vetor_Tubos[i];
    }

    std:: cout << "\n\n";
    
//Ordenando tubos no poço

    Real forasolo(-2);   //altura acima do solo
    
    tubos.push_back(PrimeiroTubo(vetor_Tubos[0], forasolo));
    
    Real alturatotal (tubos[0].CMP() + forasolo);
    Tubo aux;
    
    
 for(int i=0; i<vetor_Tubos.size(); i++){
     for (int m=1; m<vetor_Tubos.size(); m++){
         if (vetor_Tubos[i].DMT()> 
             (vetor_Tubos[m].DMT() + 2*vetor_Tubos[m].ESP()) && m>i && 
                 g1.ALT() > alturatotal){
             
             tubos.push_back(continuidade(tubos[i], vetor_Tubos[m]));
             alturatotal+=(continuidade(tubos[i], vetor_Tubos[m])).CMP();
             m=vetor_Tubos.size();        //critério de parada
            } 

    }
}
    
for(int i=0; i<tubos.size(); i++){
    std :: cout << "item: " << tubos[i];
}
 
std :: cout << "\n Altura total: " << alturatotal << std :: endl;
   

    return 0;
    
   
}
    

const bool Furo_Tubo (const Geometria _geo, const Tubo _tubo){
    
    return _geo.DMT() >= (_tubo.DMT() + 2*_tubo.ESP()) 
            && _geo.ALT() > _tubo.CMP();
}