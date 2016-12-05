#include "InitializeDD4hep.h"

#include "DD4hep/LCDD.h"

#include "DDKalTest/DDKalTestConf.h"
#include "UTIL/ILDConf.h"

using namespace marlin ;

InitializeDD4hep aInitializeDD4hep ;


InitializeDD4hep::InitializeDD4hep() : Processor("InitializeDD4hep"),
				       _dd4hepFileName(""),
				       _encodingStringParameter("")
{
  
  // modify processor description
  _description = "InitializeDD4hep reads a compact xml file and initializes the DD4hep::LCDD object" ;
  
  registerProcessorParameter( "DD4hepXMLFile" , 
			      "Name of the DD4hep compact xml file to load"  ,
			      _dd4hepFileName ,
			      std::string("dd4hep_compact.xml")
			      );

  registerProcessorParameter( "EncodingStringParameterName" ,
			      "If given, ILDCellID0::encoder_string will be overwritten with the LCDD parameter of that name.",
			      _encodingStringParameter,
			      std::string("")
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


  if ( _encodingStringParameter != "" ){

    streamlog_out(MESSAGE) << " ---------------------------------------------------------------------------------- \n" 
			   << "  ILDCellID0::encoder_string will set to   " << lcdd.constantAsString( _encodingStringParameter ) << std::endl 
			   << "  as specified in lccd parameter  : " << _encodingStringParameter  << std::endl 
			   << " ---------------------------------------------------------------------------------- \n"
			   << std::endl;

    ILDCellID0::encoder_string = lcdd.constantAsString( _encodingStringParameter );
    DDKalTest::CellIDEncoding::instance().set_encoding_string( lcdd.constantAsString( _encodingStringParameter ) );
  }

}


void InitializeDD4hep::processRunHeader( LCRunHeader*) { } 

void InitializeDD4hep::processEvent( LCEvent * ) { }

void InitializeDD4hep::check( LCEvent *  ) { }

void InitializeDD4hep::end(){ }

