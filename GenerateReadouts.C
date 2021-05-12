
Int_t GenerateReadouts(TString outFileName) {
    TFile* f = new TFile(outFileName, "RECREATE");

    // If TRestDetectorReadout name is not given, the first
    // definition will be taken
    TRestDetectorReadout* r1 = new TRestDetectorReadout("pixelReadout.rml");
    r1->Write("pixel");

    // We need to provide the name because it is not the
    // first definition
    TRestDetectorReadout* r2 = new TRestDetectorReadout("pixelReadout.rml", "pixelDecoding");
    r2->Write("pixelDecoding");

    TRestDetectorReadout* r3 = new TRestDetectorReadout("strippedReadout.rml");
    r3->Write("stripped");

    TRestDetectorReadout* r4 = new TRestDetectorReadout("microbulk.rml");
    r4->Write("microbulk");

    f->Close();

    return 0;
}

