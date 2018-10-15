#include "PointOfSaleSystem.h"
#include <string>
#include <gtest/gtest.h>

TEST(PosTest, TestGetTotalPrice) {
	PointOfSaleSystem system;
	EXPECT_EQ(system.getTotalPrice(), 0.0);
}