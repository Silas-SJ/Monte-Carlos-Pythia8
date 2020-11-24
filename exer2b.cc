/* Compile usando:
 g++ -o exer2b exer2b.cc -pthread -std=c++1z -m64 -I/home/silas/miniconda3/envs/my_root_env/include -L/home/silas/miniconda3/envs/my_root_env/lib -lCore -lImt -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lROOTVecOps -lTree -lTreePlayer -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -lMultiProc -lROOTDataFrame -Wl,-rpath,/home/silas/miniconda3/envs/my_root_env/lib -pthread -lm -ldl -rdynamic
 
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
int a=0;
int b=3;
double sum=0; // é para calcular a soma
double I;
double x;
//iniciando a contagem
for (int i=0;i<nev;i++) {
// número randômico x 
x = rd3.Uniform(0.,1.); // lembrando que x está no intervalo [0,1]
// função para ser calculada, lembrando que a integral é (1-x²)². 
// Ou seja, substituir x(b-a)+a em (1-x²)²
sum = sum+pow((1-pow((x*(b-a)+a),2)),2);
I = sum*(b-a)/nev; // valor da integral
}
std::cout << "integral de (1-x²)² dx = " << I << std::endl;
}

