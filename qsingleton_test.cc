/*
 * Tests for the QT Singleton implementation.
 *
 *  Created on: Nov 6, 2012
 *      Author: Caoimhe Clausen
 */

#include <gtest/gtest.h>
#include "toolbox/qsingleton.h"

namespace toolbox {
namespace testing {

struct TestData
{
	int id;
};

class QSingletonTest : public ::testing::Test {
protected:
	virtual void SetUp()
	{
	}

	virtual void TearDown()
	{
	}
};

TEST_F(QSingletonTest, CreatesIdenticalInstances)
{
	TestData& one = QSingleton<TestData>::GetInstance();
	one.id = 1;

	TestData& two = QSingleton<TestData>::GetInstance();

	EXPECT_EQ(one.id, two.id);
}

} /* namespace testing */
} /* namespace toolbox */
