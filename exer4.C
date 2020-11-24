
/* Ative o root e Compile usando: 

rootcint -f pythiaDict.cxx -c -I$PYTHIA8/include pythiaROOT.h   pythiaLinkdef.h

g++ -o exer4 exer4.C pythiaDict.cxx -I$PYTHIA8/include `root-config --cflags --glibs` -lEG -lEGPythia8 -L$PYTHIA8/lib -lpythia8
*/
#include "Pythia8/Pythia.h"
#include "TH1.h"
#include "TTree.h"
#include "TFile.h"
#include <math.h>
#include "TSystem.h"
#include "TStyle.h"
using namespace Pythia8;
int main() {


 Pythia pythia;


// Os processos a serem considerados são:

  pythia.readString("HardQCD:qqbar2bbbar = on");
  pythia.readString("HardQCD:gg2bbbar = on");
  pythia.readString("HardQCD:gg2qqbarg = on");
  pythia.readString("HardQCD:qqbar2qqbargDiff = on");
  pythia.readString("HardQCD:qqbar2qqbargSame = on");
  pythia.readString("HardQCD:nQuarkNew = 5");

// Gerando as colisões e os niveis de exergia: colisões proton proton que irão ocorrer

  pythia.readString("Beams:eCM = 7000."); // Energia do processo em GeV
  pythia.readString("Beams:idA = 2212"); // Proton
  pythia.readString("Beams:idB = 2212");  // Proton

 // Iniciando os processos subsequentes
  pythia.init();
  TFile *file = TFile::Open("exer4.root","recreate"); // criando um arquivo root para armazenar os histogramas
  Event *event = &pythia.event;
  TTree *T = new TTree("T","exer4 Tree");
  T->Branch("event",&event);

  int bquark = 0; // variable to count b quarks in hadron process
  int Bmeson = 0; // variable to count B mesons in final state
  int ev= 100000; // número de eventos que estamos gerando

  // iniciando a contagem dos eventos e selecionando os quarks b
  for (int iEvent = 0; iEvent < ev; ++iEvent) {
    if (!pythia.next()) continue;
    for (int i = 0; i < pythia.event.size(); ++i) {
      if (pythia.event[i].id() == 5 && std::abs(pythia.event[i].status()) >= 21 && std::abs(pythia.event[i].status()) <=29){
        ++bquark;
        break;
}
}
}

  // iniciando a contagem de eventos e selecionado os mesons B
  for (int iEvent = 0; iEvent < ev; ++iEvent) {
    if (!pythia.next()) continue;
    // Loop over particles
    for (int i = 0; i < pythia.event.size(); ++i) {
        if (std::abs(pythia.event[i].id()) == 511 || std::abs(pythia.event[i].id()) == 521){
          if (pythia.event[i].isFinal() == 0){
             ++Bmeson;
             break;
 }
 }
 } 
    T->Fill();
 }

  pythia.stat();
  cout << "Quantidade de eventos com quark b: "<< bquark << endl;
  cout << "Quantidade de eventos com Méson B: "<< Bmeson << endl;
  T->Print();
  T->Write();
  delete file;  
  return 0;
}

