This project hosts few basic TRestReadout definitions that should serve as reference to new REST users. A readout can be included inside a processing chain, and it serves to find the relation between the electronic channels of the detector and the physical readout channels, as well as to define the topology of the readout. Typical processes that use the readout are `TRestHitsToSignalProcess` and `TRestSignalToHitsProcess` for event reconstruction.

Any REST process that includes a TRestReadout definition will be able to retrieve the readout by using:

```
fReadout = GetMetadata<TRestReadout>();
```

A complex readout might require some calculation time to produce a mapping. Therefore, a pre-produced readout in a ROOT file is recommended to be re-used later on at a processing chain.

#### Manually generating a readout file

To generate a readout and write it to file you may use the following:

```
restRoot
[0] TFile *f = new TFile("readouts.root");
[1] TRestReadout *r = new TRestReadout("pixelReadout.rml");
[2] r->Write("pixelReadout");
[3] f->Close();
```

#### Recovering the readout saved in a file

Now we will be able to recover the readout in a later session, and access the `TRestReadout` methods and metadata information. The following code loads the saved readout and prints all the relevant information. 

```
restRoot
TFile *f = new TFile("readouts.root");
.ls
TRestReadout *r = (TRestReadout) f->Get("pixelReadout");
r->PrintMetadata();
```

The `PrintMetadata` method for `TRestReadout` might receive as argument an integer number to increase the level of detail in the information. For example:
```
r->PrintMetadata(3);
```

#### Accessing the readout methods to retrieve information


#### Translating positions into readout coordinates and viceversa


#### A macro to generate a file with several readouts.


#### Validating the readout with random localized depositions.



-----



**⚠ WARNING: REST is under continous development.** This README is offered to you by the REST community. Your HELP is needed to keep this file up to date. Feel free to contribute fixing typos, updating information or adding new contributions. See also our [Contribution Guide](https://lfna.unizar.es/rest-development/REST_v2/-/blob/master/CONTRIBUTING.md).


