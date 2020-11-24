/* Compile usando:
 g++ -o exer2a exer2a.cc -pthread -std=c++1z -m64 -I/home/silas/miniconda3/envs/my_root_env/include -L/home/silas/miniconda3/envs/my_root_env/lib -lCore -lImt -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lROOTVecOps -lTree -lTreePlayer -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -lMultiProc -lROOTDataFrame -Wl,-rpath,/home/silas/miniconda3/envs/my_root_env/lib -pthread -lm -ldl -rdynamic
 
 Exercício 2 (parte 1)
 
 
*/

//Bibliotecas utilizadas
#include "TRandom3.h"
#include <iostream> 
#include <cmath>
TRandom3 rd3; //para criar os números randômicos
int nev = 100000; // número de eventos, no caso pontos
//iniciando a construção da lógica
int main ()
{
//Declarando as variáveis
double a;
double x;
double y;
double funcao;
double j=0.0; //casos favoráveis

//iniciando a contagem
for (int i=0;i<nev;i++) {
// números randômicos x e y
x = rd3.Uniform(0.,3.);

y = rd3.Uniform(0.,64.);
// função para ser calculada
funcao = pow((1-x*x),2);
// Condição principal do problema
if (y<=funcao){
j = j +1;
}
}
a = 3*64*j/nev; // valor da integral
std::cout << "integral de (1-x²)² dx = " << a << std::endl;
}


