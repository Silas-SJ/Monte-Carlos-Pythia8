/* Compile usando:
 g++ -o exer1 exer1.cc -pthread -std=c++1z -m64 -I/home/silas/miniconda3/envs/my_root_env/include -L/home/silas/miniconda3/envs/my_root_env/lib -lCore -lImt -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lROOTVecOps -lTree -lTreePlayer -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -lMultiProc -lROOTDataFrame -Wl,-rpath,/home/silas/miniconda3/envs/my_root_env/lib -pthread -lm -ldl -rdynamic
 
*/
//Bibliotecas utilizadas
#include "TRandom3.h"
#include <iostream> 
#include <cmath>
TRandom3 rd3; //para criar os números randômicos
int nev = 10000; // número de eventos, no caso pontos
//iniciando a construção da lógica
int main ()
{
//Declarando as variáveis
double a;
double x;
double y;
double r;
double j=0.0; //casos favoráveis

//iniciando a contagem
for (int i=0;i<nev;i++) {
// números randômicos x e y
x = rd3.Uniform(-1.,1.);

y = rd3.Uniform(-1.,1.);
// raio do circulo
r = sqrt(pow(x,2) + pow(y,2));
// Condição principal do problema, os pontos que estão dentro do circulo
if (r<=1.){
j = j +1;
}
}
a = 4*j/nev; // valor de pi, mas como o circulo é unitário, fica sendo valor da área
std::cout << "Área do circulo unitário= " << a << " u.a   (unidades de área)" << std::endl;
}


