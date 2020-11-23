Int_t ReadoutTest(TString readoutFile, TString readoutName) {
    // We define the 128 bits mask to enable different channels
    Int_t mask[4];
    mask[0] = 0x80000110;  // Channels 4, 8 and 31 enabled
    mask[1] = 0x000000FF;  // Channels from 32 to 47 enabled
    mask[2] = 0x00;        // All channels disabled [From 64 to 95]
    mask[3] = 0x00;        // All channels disabled [From 96 to 127]

    // We define also a reduced region of the readout where we will launch random (x,y)
    Double_t region[4];
    region[0] = 0.05;  // Xmin starts at 5% of full area
    region[1] = 0.95;  // Xmax ends at 95% of full area
    region[2] = 0.05;  // Ymin starts at 5% of full area
    region[3] = 0.95;  // Ymax ends at 95% of full area

    // The last two arguments, N and pId are optional.
    // The number of (x,y) coordinates to be generated.
    Int_t N = 1E4;

    // The plane readout index to be checked
    Int_t pId = 1;

    // This script will launch the generation of random (x,y) positions at the specified region,
    // and it will draw only the hits on the activated channels (8, 31, 32-47).
    REST_CheckReadout(readoutFile, readoutName, region, mask, N, pId);
    return 0;
}
