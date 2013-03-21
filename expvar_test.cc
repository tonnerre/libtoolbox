/*
 * Tests for the exported variable implementation.
 *
 *  Created on: Nov 6, 2012
 *      Author: Caoimhe Clausen
 */

#include <gtest/gtest.h>
#include "toolbox/expvar.h"

namespace toolbox {
namespace testing {

class ExpVarTest : public ::testing::Test {
protected:
	virtual void SetUp()
	{
	}

	virtual void TearDown()
	{
	}
};

TEST_F(ExpVarTest, IntegerVariables)
{
	ExpVar<int64_t> exported(string("test-variable"));
	EXPECT_EQ(0, exported.Get());
	EXPECT_EQ(10, exported += 10);
	exported.Add(1);
	EXPECT_EQ(11, exported.Get());
	exported.SetValue(0);
	EXPECT_EQ(0, exported.Get());

	exported.Add(23);
	EXPECT_EQ("test-variable", exported.Name());
	EXPECT_EQ("23", exported.String());
}

TEST_F(ExpVarTest, StringVariables)
{
	ExpVar<string> exported("test-variable",
			new string("test-string"));
	EXPECT_EQ("test-string", exported.Get());
	EXPECT_EQ("test-variable", exported.Name());
	EXPECT_EQ("test-string", exported.String());

	exported += " test-value";
	EXPECT_EQ("test-string test-value", exported.Get());
	EXPECT_EQ("test-string test-value", exported.String());
}

} /* namespace testing */
} /* namespace toolbox */
