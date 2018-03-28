# v00-06

# v00-05

* 2017-06-22 Andre Sailer ([PR#7](https://github.com/iLCSoft/MarlinDD4hep/pull/7))
  - Destroy Detector instance at the end to make valgrind happier

* 2017-06-20 Andre Sailer ([PR#6](https://github.com/iLCSoft/MarlinDD4hep/pull/6))
  - Adapt to namespace changes in DD4hep

# v00-04

* 2017-04-07 Andre Sailer ([PR#4](https://github.com/iLCSoft/MarlinDD4hep/pull/4))
  - DDKalTestConf replaced by LCTrackerConf

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
