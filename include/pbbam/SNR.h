// File Description
/// \file SNR.h
/// \brief Defines the SNR struct
//
// Author: Lance Hepler, Derek Barnett

#ifndef SNR_H
#define SNR_H

#include "pbbam/Config.h"

#include <cstddef>
#include <vector>

#include <pbcopper/data/SNR.h>

namespace PacBio {
namespace BAM {

using SNR = PacBio::Data::SNR;

constexpr auto ClampSNR = PacBio::Data::ClampSNR;

}  // namespace BAM
}  // namespace PacBio

#endif  // SNR_H