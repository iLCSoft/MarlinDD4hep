#include "InitializeDD4hep.h"

#include "DD4hep/LCDD.h"

using namespace marlin ;

InitializeDD4hep aInitializeDD4hep ;


InitializeDD4hep::InitializeDD4hep() : Processor("InitializeDD4hep") {
  
  // modify processor description
  _description = "InitializeDD4hep reads a compact xml file and initializes the DD4hep::LCDD object" ;
  
  registerProcessorParameter( "DD4hepXMLFile" , 
			      "Name of the DD4hep compact xml file to load"  ,
			      _dd4hepFileName ,
			      std::string("dd4hep_compact.xml")
			      );
}

void InitializeDD4hep::init() { 
  
  // usually a good idea to
  // printParameters() ;

  streamlog_out(MESSAGE) << " -------------------------------------" << std::endl
			 << " ---- Initializing DD4hep from file  " << _dd4hepFileName << " ... " << std::endl ;
  
  DD4hep::Geometry::LCDD& lcdd = DD4hep::Geometry::LCDD::getInstance();
  
  lcdd.fromCompact( _dd4hepFileName );
  
  streamlog_out( MESSAGE )  << " ---- instantiated  geometry for detector " << lcdd.header().name()  << std::endl 
			    << " -------------------------------------" << std::endl ;

}


void InitializeDD4hep::processRunHeader( LCRunHeader*) { } 

void InitializeDD4hep::processEvent( LCEvent * ) { }

void InitializeDD4hep::check( LCEvent *  ) { }

void InitializeDD4hep::end(){ }

