// File Description
/// \file Autovalidate.h
/// \brief Sets the default macro for the autovalidation mode.
//
// Author: Derek Barnett

#ifndef AUTOVALIDATE_H
#define AUTOVALIDATE_H

#include "pbbam/Config.h"

// \brief Auto-validation
//
// To validate BAM components (header, records, etc.) you can either use the
// Validator API provided, or enable auto-validation. To compile pbbam for
// auto-validation, add the -Dauto-validate=true option to your Meson
// invocation.
//
//
#ifndef PBBAM_AUTOVALIDATE
#define PBBAM_AUTOVALIDATE 0
#endif

#endif  // AUTOVALIDATE_H
