#include <pbbam/vcf/VcfQuery.h>

namespace PacBio {
namespace VCF {

VcfQuery::VcfQuery(std::string fn) : VcfQuery{VcfFile{std::move(fn)}} {}

VcfQuery::VcfQuery(const VcfFile& file)
    : PacBio::BAM::internal::QueryBase<VcfVariant>(), reader_{file}
{
}

VcfQuery::VcfQuery(VcfQuery&&) = default;

VcfQuery& VcfQuery::operator=(VcfQuery&&) = default;

VcfQuery::~VcfQuery() = default;

bool VcfQuery::GetNext(VcfVariant& var) { return reader_.GetNext(var); }

}  // namespace VCF
}  // namespace PacBio
