// Author: Derek Barnett

#include <gtest/gtest.h>

#include "PbbamTestData.h"

#include <pbbam/BamFile.h>
#include <pbbam/BamReader.h>
#include <pbbam/BamRecord.h>
#include <pbbam/IndexedBamWriter.h>
#include <pbbam/PbiBuilder.h>
#include <pbbam/PbiRawData.h>

// clang-format off

TEST(IndexedBamWriter, WritesValidIndex)
{
    using namespace PacBio::BAM;

    const std::string inBam = PbbamTestsConfig::Data_Dir + "/polymerase/internal.subreads.bam";
    const std::string outBam = PbbamTestsConfig::GeneratedData_Dir + "/ibw.bam";
    const std::string outPbi = PbbamTestsConfig::GeneratedData_Dir + "/ibw.bam.pbi";

    const BamFile file{inBam};
    const auto& header = file.Header();

    const std::vector<std::string> expectedQNames{
        "ArminsFakeMovie/100000/2659_3025",
        "ArminsFakeMovie/100000/3116_3628",
        "ArminsFakeMovie/100000/3722_4267",
        "ArminsFakeMovie/100000/4356_4864",
        "ArminsFakeMovie/100000/4960_5477",
        "ArminsFakeMovie/100000/5571_6087",
        "ArminsFakeMovie/100000/6199_6719",
        "ArminsFakeMovie/100000/6812_7034",
        "ArminsFakeMovie/200000/2659_3025",
        "ArminsFakeMovie/200000/3116_3628",
        "ArminsFakeMovie/200000/3722_4267",
        "ArminsFakeMovie/200000/4356_4864",
        "ArminsFakeMovie/200000/4960_5477",
        "ArminsFakeMovie/200000/5571_6087",
        "ArminsFakeMovie/200000/6199_6719",
        "ArminsFakeMovie/200000/6812_7034",
        "ArminsFakeMovie/300000/2659_3025",
        "ArminsFakeMovie/300000/3116_3628",
        "ArminsFakeMovie/300000/3722_4267",
        "ArminsFakeMovie/300000/4356_4864",
        "ArminsFakeMovie/300000/4960_5477",
        "ArminsFakeMovie/300000/5571_6087",
        "ArminsFakeMovie/300000/6199_6719",
        "ArminsFakeMovie/300000/6812_7034"
    };

    {   // copy file & generate index

        BamReader reader{file};
        IndexedBamWriter writer{outBam, header};
        BamRecord b;
        while (reader.GetNext(b))
            writer.Write(b);
    }

    {   // sequential read of new BAM

        BamReader reader{outBam};
        BamRecord b;
        for (size_t i = 0; i < 24; ++i)
        {
            reader.GetNext(b);
            EXPECT_EQ(expectedQNames.at(i), b.FullName());
        }
    }

    {   // check random access in new BAM, using companion PBI

        const PbiRawData idx{outPbi};
        const auto& offsets = idx.BasicData().fileOffset_;

        BamReader reader{outBam};
        BamRecord b;
        for (int i = 23; i >=0; --i)
        {
            reader.VirtualSeek(offsets.at(i));
            reader.GetNext(b);
            EXPECT_EQ(expectedQNames.at(i), b.FullName());
        }
    }
}

// clang-format on