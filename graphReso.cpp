#include "TF1.h"
#include "TRandom.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TMath.h"
#include "TStyle.h"
#include "TFile.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TLine.h"
//#include "TTree.h"
#include "TTreeReader.h"
//#include "TTreeReaderArray.h"
//#include "TTreeReaderValue.h"

void graphReso()
{
    TCanvas *c1 = new TCanvas("c1","c1",800,600);
    c1->SetGrid(0,1);

    const Int_t n = 5;
    Int_t entries[n] = {21521,70788,95685,95772,95028};
    Int_t total = 100000;

    // create the arrays for the points
    Double_t x[n] = {0.3,1,3,5,10};
    Double_t y[n];

    for (Int_t i=0; i<n; i++)
    {
        y[i] = (entries[i]*1.0 / total) * 100;
    }

    TGraph *gr = new TGraph(n,x,y);
    TAxis *axis = gr->GetXaxis();
    TLine *l1 = new TLine(0,100,10.5,100);
    TLine *l2 = new TLine(0.,14.5,0.,100.5);

    gr->SetTitle(";E [GeV];Efficiency [%]");
    gr->SetMarkerColor(kBlue);
    gr->SetMarkerStyle(70);
    gr->SetMarkerSize(3.5);

    gr->GetXaxis()->SetTitleSize(0.06);
    gr->GetYaxis()->SetTitleSize(0.06);
    gr->GetXaxis()->SetLabelSize(0.06);
    gr->GetYaxis()->SetLabelSize(0.06);

    gPad->SetLeftMargin(0.13);
    gPad->SetBottomMargin(0.13);
    gPad->SetRightMargin(0.02);
    gPad->SetTopMargin(0.02);

    //gr->GetXaxis()->SetLabelSize(0.0001);

    l1->SetLineColor(kGreen+2);
    l1->SetLineStyle(2);
    l1->SetLineWidth(2);

    l2->SetLineColor(kBlack);
    l2->SetLineStyle(2);
    l2->SetLineWidth(2);
    
    gr->GetYaxis()->SetTitleOffset(1.);
    gr->GetYaxis()->CenterTitle(true);
    gr->GetXaxis()->CenterTitle(true);

    gr->Draw("AP");
    l1->Draw("same");
    l2->Draw("same");

    axis->SetLimits(-0.5,10.5);
    

    TFile *output = new TFile("eff.root","RECREATE");
    c1->Write();
    c1->SaveAs("pdfs/efficiency.pdf");
    output->Close();
}