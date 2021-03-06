// Author: Derek Barnett

#include "../PbbamInternalConfig.h"

#include <pbbam/vcf/VcfWriter.h>

#include <cassert>

#include <fstream>
#include <iostream>
#include <type_traits>

#include <pbbam/vcf/VcfFormat.h>
#include <pbbam/vcf/VcfHeader.h>
#include <pbbam/vcf/VcfVariant.h>

#include "../FileProducer.h"

namespace PacBio {
namespace VCF {

static_assert(!std::is_copy_constructible<VcfWriter>::value,
              "VcfWriter(const VcfWriter&) is not = delete");
static_assert(!std::is_copy_assignable<VcfWriter>::value,
              "VcfWriter& operator=(const VcfWriter&) is not = delete");

struct VcfWriter::VcfWriterPrivate : public PacBio::BAM::FileProducer
{
    VcfWriterPrivate(std::string fn, const VcfHeader& header)
        : PacBio::BAM::FileProducer{std::move(fn)}, out_{TempFilename()}
    {
        out_ << VcfFormat::FormattedHeader(header) << '\n';
    }

    bool Write(const VcfVariant& var)
    {
        out_ << VcfFormat::FormattedVariant(var) << '\n';
        return true;  // TODO: handle errors
    }

    std::ofstream out_;
};

VcfWriter::VcfWriter(std::string fn, const VcfHeader& header)
    : d_{std::make_unique<VcfWriterPrivate>(std::move(fn), header)}
{
}

VcfWriter::VcfWriter(VcfWriter&&) noexcept = default;

VcfWriter& VcfWriter::operator=(VcfWriter&&) noexcept = default;

VcfWriter::~VcfWriter() = default;

bool VcfWriter::Write(const VcfVariant& var) { return d_->Write(var); }

}  // namespace VCF
}  // namespace PacBio
