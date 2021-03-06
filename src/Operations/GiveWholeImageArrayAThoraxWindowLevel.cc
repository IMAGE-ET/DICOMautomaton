//GiveWholeImageArrayAThoraxWindowLevel.cc - A part of DICOMautomaton 2015, 2016. Written by hal clark.

#include <experimental/any>
#include <functional>
#include <list>
#include <map>
#include <memory>
#include <string>    

#include "../Structs.h"
#include "../Regex_Selectors.h"
#include "../YgorImages_Functors/Grouping/Misc_Functors.h"
#include "../YgorImages_Functors/Processing/CT_Reasonable_HU_Window.h"
#include "GiveWholeImageArrayAThoraxWindowLevel.h"
#include "YgorImages.h"
#include "YgorMisc.h"         //Needed for FUNCINFO, FUNCWARN, FUNCERR macros.


OperationDoc OpArgDocGiveWholeImageArrayAThoraxWindowLevel(void){
    OperationDoc out;
    out.name = "GiveWholeImageArrayAThoraxWindowLevel";

    out.desc = 
        "This operation runs the images in an image array through a uniform window-and-leveler instead of per-slice"
        " window-and-level or no window-and-level at all. Data is modified and no copy is made!";

    return out;
}

Drover GiveWholeImageArrayAThoraxWindowLevel(Drover DICOM_data, OperationArgPkg /*OptArgs*/, std::map<std::string,std::string> /*InvocationMetadata*/, std::string /*FilenameLex*/){
    for(auto & img_arr : DICOM_data.image_data){
        if(!img_arr->imagecoll.Process_Images_Parallel( GroupIndividualImages,
                                               StandardThoraxHUWindow,
                                               {},{} )){
            FUNCERR("Unable to force window to cover a reasonable thorax HU range");
        }
    }

    return DICOM_data;
}
