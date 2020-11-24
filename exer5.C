
/* Ative o root e Compile usando: 

rootcint -f pythiaDict.cxx -c -I$PYTHIA8/include pythiaROOT.h   pythiaLinkdef.h

g++ -o exer5 exer5.C pythiaDict.cxx -I$PYTHIA8/include `root-config --cflags --glibs` -lEG -lEGPythia8 -L$PYTHIA8/lib -lpythia8
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
  //partciulas que irao colidir, no caso colisao eletron e antieletron(positron)
  Pythia pythia;
  pythia.readString("Beams:idA = 11"); // eletron
  pythia.readString("Beams:idB = -11"); // antieletron (positron)
  pythia.readString("Beams:eCM = 100."); // energia em GeV

  //Dicas do exercicio
  pythia.readString("WeakSingleBoson:ffbar2gmZ = on");
  pythia.readString("PDF:lepton = off");
  pythia.readString("HadronLevel:all = off");
  pythia.readString("23:onMode = off");
  pythia.readString("23:onIfAny = 1 2 3 4 5");

  //Iniciando o pythia
  pythia.init();
//Arquivo .root onde serão salvos os histogramas
  TFile *file = TFile::Open("exer5.root","recreate");
  //Histograma da multiplicidade parton
  TH1F *multHist = new TH1F("multHist","Multiplicidade Parton", 35, 0, 35);
  Event *event = &pythia.event;
  int ev = 10000; //numero de eventos
  int multp; // multiplicidade parton
  // Loop dos eventos
  for (int iEvent = 0; iEvent < ev; ++iEvent) {
    if (!pythia.next()) continue;
    multp = 0;
    //condição para selecionar os eventos desejados
    for (int i = 0; i < pythia.event.size(); ++i){
      if (pythia.event[i].isFinal() && pythia.event[i].isParton()) ++multp; // seleciona apenas a parte final dos partons
}
    multHist->Fill(multp); // preenche o histograma com os dados da multiplicidade
}
  
  // Print stat info
  pythia.stat();
  multHist->Write();

  delete file;
  return 0;
}
