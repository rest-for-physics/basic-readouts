
Int_t GenerateReadouts(TString outFileName) {
    TFile* f = new TFile(outFileName, "RECREATE");

    // If TRestReadout name is not given, the first
    // definition will be taken
    TRestReadout* r1 = new TRestReadout("pixelReadout.rml");
    r1->Write("pixel");

    // We need to provide the name because it is not the
    // first definition
    TRestReadout* r2 = new TRestReadout("pixelReadout.rml", "pixelDecoding");
    r2->Write("pixelDecoding");

    TRestReadout* r3 = new TRestReadout("strippedReadout.rml");
    r3->Write("stripped");

    f->Close();

    return 0;
}

