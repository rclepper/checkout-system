#include "PointOfSaleSystem.h"
#include <string>
#include <gtest/gtest.h>

TEST(PosTest, TestGetInitialTotalPrice) {
	pos::PointOfSaleSystem system;
	EXPECT_EQ(system.getTotalPrice(), 0.0);
}

TEST(PosTest, TestScanItemPriceListEmpty) {
	std::string item("Lucky Charms cereal");
	pos::PointOfSaleSystem system;

	EXPECT_EQ(system.scanItem(item), pos::NotFound);
}