
#include <TFile.h>
#include <TRestDetectorReadout.h>
#include <TString.h>

#include <iostream>

using namespace std;

Int_t GenerateReadouts(const char* outFilename) {
    cout << "Starting macro" << endl;

    cout << "Creating TFile: " << outFilename << endl;
    TFile file(outFilename, "RECREATE");

    // If TRestDetectorReadout name is not given, the first definition will be taken
    cout << "Creating first TRestDetectorReadout" << endl;
    auto pixelReadout = new TRestDetectorReadout("pixelReadout.rml");
    pixelReadout->Write("pixel");

    // We need to provide the name because it is not the first definition
    cout << "Creating second TRestDetectorReadout" << endl;
    auto pixelReadoutDecoding = new TRestDetectorReadout("pixelReadout.rml", "pixelDecoding");
    pixelReadoutDecoding->Write("pixelDecoding");

    cout << "Creating third TRestDetectorReadout" << endl;
    auto strippedReadout = new TRestDetectorReadout("strippedReadout.rml");
    strippedReadout->Write("stripped");

    cout << "Creating fourth TRestDetectorReadout" << endl;
    auto readoutMicrobulk = new TRestDetectorReadout("microbulk.rml");
    readoutMicrobulk->Write("microbulk");

    cout << "Closing TFile: " << file.GetName() << endl;
    file.Close();

    return 0;
}
