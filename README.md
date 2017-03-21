#  MarlinDD4hep 
[![Build Status](https://travis-ci.org/iLCSoft/MarlinDD4hep.svg?branch=master)](https://travis-ci.org/iLCSoft/MarlinDD4hep)

Provides one processor to initialize a DD4hep detector geometry
from a compact file for a Marlin job.

MarlinDD4hep is distributed under the [GPLv3 License](http://www.gnu.org/licenses/gpl-3.0.en.html)

[![License](https://www.gnu.org/graphics/gplv3-127x51.png)](https://www.gnu.org/licenses/gpl-3.0.en.html)

## Notes

InitializeDD4hep:
@parameter: DD4hepXMLFile:  compact xml file to load 

NB: This processor has to be run  before any processor that accesses the detector geometry, i.e. best to run it as first processor in the steering file.

## License and Copyright
Copyright (C), MarlinDD4hep Authors

MarlinDD4hep is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License long with this program.  If not, see <http://www.gnu.org/licenses/>.