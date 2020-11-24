/* Compile usando:
 g++ -o exer3 exer3.cc -pthread -std=c++1z -m64 -I/home/silas/miniconda3/envs/my_root_env/include -L/home/silas/miniconda3/envs/my_root_env/lib -lCore -lImt -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lROOTVecOps -lTree -lTreePlayer -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -lMultiProc -lROOTDataFrame -Wl,-rpath,/home/silas/miniconda3/envs/my_root_env/lib -pthread -lm -ldl -rdynamic
 
*/
//Bibliotecas utilizadas
#include "TRandom3.h"
#include "TH1F.h"
#include "TROOT.h"
#include "TFile.h"
#include "TMath.h"
#include <iostream> 
#include <cmath>
TRandom3 rd3; //para criar os números randômicos
int nev = 100000; // número de eventos, no caso pontos
//iniciando a construção da lógica
int main ()
{
//Declarando as variáveis
double e=1.6*10e-19; // carga elétrica do elétron em Coulumb
double m=3.73*10e9; // massa da partícula alfa em eV
double vi=1.5*10e7; //velocidade inicial média da partícula alfa
double ep= 8.854*10e-12; // valor da permissividade elétrica no vácuo em C²/N.m²
double teta;
double x;
double k;
double y;
double j;
double sigmachoque;// seção de choque diferencial

//Seria interessante representar esse resultado na forma de um histograma pois se trata de uma seção de choque diferencial

TH1F *   hist = new TH1F("teta","Secao de Choque Diferencial",100,-TMath::Pi(),TMath::Pi());
hist->GetXaxis()->SetTitle("teta");
hist->GetYaxis()->SetTitle("Secao de Choque");
TFile * fp = new TFile("hist_exer3.root","recreate");
//iniciando a contagem
for (int i=0;i<nev;i++) {
teta= rd3.Uniform(-TMath::Pi()/2,TMath::Pi()/2); // teta randômico no intervalo de [-pi/2, pi/2]
k = pow((e*e/(8*m*ep*vi*vi*TMath::Pi())),2); //constante k, só para simplificar os cálculos
y = 1/pow(sin(teta/2),4);
j = k*(1/pow(sin(0.1/2),4)); // valor máximo
x = rd3.Uniform(0,j); // lembrando que x está no intervalo [0,j]
sigmachoque = k*y; // valor da seção de choque diferencial
if (x <= sigmachoque){
hist->Fill(teta);
}
}
hist->Write();
fp->Close();
}


