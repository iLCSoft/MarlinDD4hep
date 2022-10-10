#include "InitializeDD4hep.h"

#include "DD4hep/Printout.h"
#include "DD4hep/Detector.h"

#include "UTIL/LCTrackerConf.h"

using namespace marlin ;

InitializeDD4hep aInitializeDD4hep ;


InitializeDD4hep::InitializeDD4hep() : Processor("InitializeDD4hep"),
				       _dd4hepFileName(""),
				       _encodingStringParameter("")
{
  
  // modify processor description
  _description = "InitializeDD4hep reads a compact xml file and initializes the dd4hep::Detector object" ;
  
  registerProcessorParameter( "DD4hepXMLFile" , 
			      "Name of the DD4hep compact xml file to load"  ,
			      _dd4hepFileName ,
			      std::string("dd4hep_compact.xml")
			      );

  registerProcessorParameter( "EncodingStringParameterName" ,
			      "If given, the Compact File parameter of that name will be used as argument to LCTrackerCellID::set_encoding_string()",
			      _encodingStringParameter,
			      std::string("")
			      );

  registerOptionalParameter( "EncodingStringParameter" ,
			      "Alternate name for EncodingStringParameterName",
			      _encodingStringParameter,
			      std::string("")
			      );

}

void InitializeDD4hep::init() { 
  
  // usually a good idea to
  // printParameters() ;

  if (_logLevelName.find("DEBUG") != std::string::npos) dd4hep::setPrintLevel(dd4hep::DEBUG);
  else if (_logLevelName.find("MESSAGE") != std::string::npos) dd4hep::setPrintLevel(dd4hep::INFO);
  else if (_logLevelName.find("WARNING") != std::string::npos) dd4hep::setPrintLevel(dd4hep::WARNING);
  else if (_logLevelName.find("ERROR") != std::string::npos) dd4hep::setPrintLevel(dd4hep::ERROR);
  else if (_logLevelName.find("SILENT") != std::string::npos) dd4hep::setPrintLevel(dd4hep::NOLOG);
  else dd4hep::setPrintLevel(dd4hep::INFO);

  streamlog_out(MESSAGE) << " -------------------------------------" << std::endl
			 << " ---- Initializing DD4hep from file  " << _dd4hepFileName << " ... " << std::endl ;
  
  dd4hep::Detector& theDetector = dd4hep::Detector::getInstance();
  
  theDetector.fromCompact( _dd4hepFileName );
  
  streamlog_out( MESSAGE )  << " ---- instantiated  geometry for detector " << theDetector.header().name()  << std::endl
			    << " -------------------------------------" << std::endl ;


  if ( _encodingStringParameter != "" ){

    streamlog_out(MESSAGE) << " ---------------------------------------------------------------------------------- \n" 
			   << "  LCTrackerCellID::_encoding will set to   " << theDetector.constantAsString( _encodingStringParameter ) << std::endl
			   << "  as specified in lccd parameter  : " << _encodingStringParameter  << std::endl 
			   << " ---------------------------------------------------------------------------------- \n"
			   << std::endl;

    LCTrackerCellID::instance().set_encoding_string( theDetector.constantAsString( _encodingStringParameter ) );
  }

}


void InitializeDD4hep::processRunHeader( LCRunHeader*) { } 

void InitializeDD4hep::processEvent( LCEvent * ) { }

void InitializeDD4hep::check( LCEvent *  ) { }

void InitializeDD4hep::end(){

  dd4hep::Detector::getInstance().destroyInstance();

}
