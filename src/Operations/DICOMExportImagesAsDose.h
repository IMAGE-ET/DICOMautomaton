// DICOMExportImagesAsDose.h.

#pragma once

#include <string>
#include <map>

#include "../Structs.h"


OperationDoc OpArgDocDICOMExportImagesAsDose(void);

Drover
DICOMExportImagesAsDose(Drover DICOM_data, 
                        OperationArgPkg /*OptArgs*/,
                        std::map<std::string, std::string> /*InvocationMetadata*/,
                        std::string /*FilenameLex*/);
