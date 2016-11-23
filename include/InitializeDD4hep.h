#ifndef InitializeDD4hep_h
#define InitializeDD4hep_h 1

#include "marlin/Processor.h"
#include <string>

/** InitializeDD4hep: initializes a DD4hep detector geometry from a compact XML file.
 *  Call as first processor in your steering file.
 *  Processors access the geometry simply via: 
 *  <p>
 *     DD4hep::Geometry::LCDD& lcdd = DD4hep::Geometry::LCDD::getInstance(); 
 *  </p>
 * 
 * @param DD4hepXMLFile Name of the DD4hep compact XML file to load
 * 
 * @author F. Gaede, CERN/DESY
 * @version $Id:$
 */

class InitializeDD4hep : public marlin::Processor {
  
public:
  
  virtual Processor*  newProcessor() { return new InitializeDD4hep ; }
  
  
  InitializeDD4hep() ;
  
  /** Initiallize the DD4hep geometry.
   */
  virtual void init() ;
  
  /// do nothing
  virtual void processRunHeader( LCRunHeader* run ) ;
  
  /// do nothing
  virtual void processEvent( LCEvent * evt ) ; 
  
  /// do nothing
  virtual void check( LCEvent * evt ) ; 
  
  /// do nothing
  virtual void end() ;
  
  
 protected:

  ///path to dd4p compact detector xml file
  std::string _dd4hepFileName ;

  ///name of lcdd parameter for encoding string
  std::string _encodingStringParameter;

} ;

#endif



