
#include <TRestDetectorReadout.h>

Int_t BasicValidation(const char* readoutFilename, const char* readoutName) {
    TFile* f = new TFile(readoutFilename);
    TRestDetectorReadout* r = (TRestDetectorReadout*)f->Get(readoutName);

    Int_t planes = r->GetNumberOfReadoutPlanes();

    if (planes != 2) {
        cout << "Basic readout validation. Number of planes is not 2!" << endl;
        return 1;
    }

    Int_t daqId = r->GetReadoutPlane(1)->GetModule(0)->GetChannel(6)->GetDaqID();

    if (daqId != 30) {
        cout << "Basic readout validation. Daq id does not correspond!" << endl;
        return 2;
    }

    return 0;
}
