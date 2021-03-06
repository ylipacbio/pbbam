// File Description
/// \file FastqSequence.h
/// \brief Defines the FastqSequence class.
//
// Author: Derek Barnett

#ifndef FASTQSEQUENCE_H
#define FASTQSEQUENCE_H

#include "pbbam/Config.h"

#include <string>

#include <pbbam/FastaSequence.h>
#include <pbbam/QualityValues.h>

namespace PacBio {
namespace BAM {

///
/// \brief The FastqSequence class represents a FASTQ record (name, bases, and
///        qualities)
///
class FastqSequence : public FastaSequence
{
public:
    /// \name Constructors & Related Methods
    /// \{

    ///
    /// \brief FastaSequence
    /// \param name
    /// \param bases
    /// \param qualities
    ///
    explicit FastqSequence(std::string name, std::string bases, QualityValues qualities);

    ///
    /// \brief FastaSequence
    /// \param name
    /// \param bases
    /// \param qualities
    ///
    explicit FastqSequence(std::string name, std::string bases, std::string qualities);

    FastqSequence() = default;

    /// \}

public:
    /// \name Attributes
    /// \{

    ///
    /// \brief Qualities
    /// \return
    ///
    const QualityValues& Qualities() const;

    ///
    /// \brief
    ///
    /// \param quals
    /// \return FastqSequence
    ///
    FastqSequence& Qualities(QualityValues quals);

    /// \}

    bool operator==(const FastqSequence& other) const;
    bool operator!=(const FastqSequence& other) const;

private:
    QualityValues qualities_;
};

}  // namespace BAM
}  // namespace PacBio

#endif  // FASTQSEQUENCE_H
