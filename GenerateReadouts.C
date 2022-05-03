
#include <TFile.h>
#include <TRestDetectorReadout.h>
#include <TString.h>

#include <iostream>

using namespace std;

Int_t GenerateReadouts(const char* outFilename) {
    cout << "Starting macro" << endl;

    cout << "Creating TFile" << endl;
    TFile file(outFilename, "RECREATE");

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

    cout << "Creating fourth TRestDetectorReadout" << endl;
    TRestDetectorReadout* r4 = new TRestDetectorReadout("microbulk.rml");
    r4->Write("microbulk");

    cout << "Closing TFile" << endl;
    file.Close();

    return 0;
}
