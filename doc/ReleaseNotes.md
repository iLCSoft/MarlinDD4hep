A.Sailer
- ignore warnings from external packages
- add parameter "EncodingStringParameter", alternate spelling of "EncodingStringParameterName" for compatibility, 
- Alternate spelling can be phased out once everyone has moved to new installation of this package
- Also change DDKaltest:DDKaltestConf instance of encoding string
- MarlinDD4hep now depends on DDKalTest until DDKalTestConf is moved to LCIO

# v00-03
F. Gaede
- apply patch by A.Sailer:
  - add parameter "EncodingStringParameterName" 
  - if specified it will be used to ovewrite ILDCellID0::encoder_string with the lccd parameter of that name
- Note: we might decide in the future to introduce a a fixed canonical name for this, e.g. "TrkDetCellID0_encoder_string" 
 
# v00-02
F. Gaede
- made compatible with c++11
- removed -ansi -pedantic -Wno-long-long

# v00-01
- first release 
