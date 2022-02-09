
Int_t GenerateReadouts(TString outFileName) {
    cout << "Starting macro" << endl;

    cout << "Creating TFile" << endl;
    TFile* f = new TFile(outFileName, "RECREATE");

    // If TRestDetectorReadout name is not given, the first definition will be taken
    cout << "Creating first TRestDetectorReadout" << endl;
    TRestDetectorReadout* r1 = new TRestDetectorReadout("pixelReadout.rml");
    r1->Write("pixel");

    // We need to provide the name because it is not the first definition
    cout << "Creating second TRestDetectorReadout" << endl;
    TRestDetectorReadout* r2 = new TRestDetectorReadout("pixelReadout.rml", "pixelDecoding");
    r2->Write("pixelDecoding");

    cout << "Creating third TRestDetectorReadout" << endl;
    TRestDetectorReadout* r3 = new TRestDetectorReadout("strippedReadout.rml");
    r3->Write("stripped");

    cout << "Closing TFile" << endl;
    f->Close();

    return 0;
}
