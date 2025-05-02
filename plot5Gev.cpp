#include <iostream>
#include <fstream>
#include <set>
#include <vector>

#include "TFile.h"
#include "TString.h"
#include "TGraph2D.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TMath.h"
#include "TLatex.h"
#include "TLine.h"
#include "TLegend.h"
#include "TGaxis.h"
#include "TF1.h"

void plot5Gev()
{
    TFile *inputfile = new TFile("hists/processed_thesis_5gev.edm4eic.root", "READ");

    TH1D *phiResolution;
    TH1D *thetaResolution;

    phiResolution = (TH1D *)inputfile->Get("HCal_Reco/hPhiResolution_HCal_Reco");
    //if (!phiResolution.back()) std::cout << "phiResolution is null" << std::endl;
    thetaResolution = (TH1D *)inputfile->Get("HCal_Reco/hThetaResolution_HCal_Reco");
    //if (!thetaResolution.back()) std::cout << "theta is null" << std::endl;

    TCanvas *can = new TCanvas("can", "can", 1200, 600);
    // can->cd();
    can->SetLeftMargin(0.16);
    can->SetBottomMargin(0.15);
    can->Divide(2,1,0.,0.);
    
    // can->Divide(2, 1);
    TString outPdf = "pdfs/5gev_plots.pdf";
    can->SaveAs(outPdf + "[");

    TLatex *text_phi = new TLatex();
    TLatex *text_theta = new TLatex();


    can->cd(1);
    phiResolution->Draw();
 
    phiResolution->SetTitle("");
    phiResolution->GetXaxis()->SetTitle("#Delta#phi [#circ]");
    phiResolution->GetYaxis()->SetTitle("Counts");

    phiResolution->GetXaxis()->SetTitleSize(0.06);
    phiResolution->GetYaxis()->SetTitleSize(0.06);
    phiResolution->GetXaxis()->CenterTitle(true);

    phiResolution->GetXaxis()->SetLabelSize(0.06);
    phiResolution->GetYaxis()->SetLabelSize(0.06);
    phiResolution->Rebin(2);

    phiResolution->GetYaxis()->SetTitleOffset(1.5);
    phiResolution->GetXaxis()->SetTitleOffset(1);
    phiResolution->GetYaxis()->SetRangeUser(0., 3100.);
    phiResolution->SetAxisRange(-5.9, 5.9,"X");
    phiResolution->SetLineColor(kGreen+2);
    phiResolution->SetLineWidth(2);
    phiResolution->SetStats(0);
    phiResolution->Draw();

    text_phi->SetNDC();
    text_phi->SetTextSize(0.07);
    text_phi->SetTextFont(42);
    text_phi->DrawLatex(0.7, 0.85, "#splitline{5 GeV}{#phi resolution}");
    text_phi->Draw();

    can->cd(2);
    thetaResolution->Draw("Y+");
  
    thetaResolution->SetTitle("");
    thetaResolution->GetXaxis()->SetTitle("#Delta#theta [#circ]");
    thetaResolution->GetXaxis()->SetLabelSize(0.06);
    thetaResolution->Rebin(2);
    thetaResolution->GetXaxis()->SetTitleSize(0.06);
    thetaResolution->GetYaxis()->SetLabelSize(0.06);
    thetaResolution->GetXaxis()->CenterTitle(true);
    thetaResolution->GetYaxis()->SetTitleSize(0.06);
    thetaResolution->GetYaxis()->SetTitle("Counts");
    thetaResolution->GetYaxis()->SetRangeUser(0., 3100.);
    thetaResolution->GetYaxis()->SetTitleOffset(1);
    thetaResolution->GetXaxis()->SetTitleOffset(1);
    thetaResolution->SetAxisRange(-5.9, 5.9,"X");
    thetaResolution->SetLineColor(kBlue);
    thetaResolution->SetLineWidth(2);
    thetaResolution->SetStats(0);
    thetaResolution->Draw();

    text_theta->SetNDC();
    text_theta->SetTextSize(0.07);
    text_theta->SetTextFont(42);
    text_theta->DrawLatex(0.6, 0.85, "#splitline{5 GeV}{#theta resolution}");
    text_theta->Draw();


    can->Update();
    can->Modified();
    can->SaveAs(outPdf);
    can->SaveAs(outPdf + "]");
}
