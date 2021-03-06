// File Description
/// \file ZmwWhitelistVirtualReader.h
/// \brief Defines the ZmwWhitelistVirtualReader class.
//
// Author: Derek Barnett

#ifndef ZMWWHITELISTVIRTUALREADER_H
#define ZMWWHITELISTVIRTUALREADER_H

#include "pbbam/Config.h"

#include "pbbam/virtual/WhitelistedZmwReadStitcher.h"

namespace PacBio {
namespace BAM {

/// \deprecated Use WhitelistedZmwReadStitcher instead.
using ZmwWhitelistVirtualReader = WhitelistedZmwReadStitcher;

}  // namespace BAM
}  // namespace PacBio

#endif  // ZMWWHITELISTVIRTUALREADER_H
