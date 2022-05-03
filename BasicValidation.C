
#include <TRestDetectorReadout.h>

Int_t BasicValidation(const char* readoutFilename, const char* readoutName) {
    TFile file(readoutFilename);
    TRestDetectorReadout* readout = file.Get<TRestDetectorReadout>(readoutName);

    Int_t planes = readout->GetNumberOfReadoutPlanes();

    if (planes != 2) {
        cout << "Basic readout validation. Number of planes is not 2!" << endl;
        return 1;
    }

    Int_t daqId = readout->GetReadoutPlane(1)->GetModule(0)->GetChannel(6)->GetDaqID();

    if (daqId != 30) {
        cout << "Basic readout validation. Daq id does not correspond!" << endl;
        return 2;
    }

    return 0;
}
