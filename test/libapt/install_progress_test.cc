#include <config.h>

#include <apt-pkg/install-progress.h>

#include <string>

#include <gtest/gtest.h>

TEST(InstallProgressTest, FancyGetTextProgressStr)
{
   APT::Progress::PackageManagerFancy p;

   EXPECT_EQ(60, p.GetTextProgressStr(0.5, 60).size());
   EXPECT_EQ("[#.]", p.GetTextProgressStr(0.5, 4));
   EXPECT_EQ("[#.........]", p.GetTextProgressStr(0.1, 12));
   EXPECT_EQ("[#########.]", p.GetTextProgressStr(0.9, 12));

   // deal with incorrect inputs gracefully (or should we die instead?)
   EXPECT_EQ("", p.GetTextProgressStr(-999, 12));
}
