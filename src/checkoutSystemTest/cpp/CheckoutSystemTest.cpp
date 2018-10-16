#include "PointOfSaleSystem.h"
#include <string>
#include <gtest/gtest.h>

class PosTest : public ::testing::Test
{
protected:
	pos::PointOfSaleSystem m_system;
};

TEST_F(PosTest, TestGetInitialTotalPrice) {
	EXPECT_FLOAT_EQ(m_system.getTotalPrice(), 0.0);
}

TEST_F(PosTest, TestScanItemPriceListEmpty) {
	std::string item("Lucky Charms cereal");

	EXPECT_EQ(m_system.scanItem(item), pos::NotFound);
}

TEST_F(PosTest, TestScan1Item1ItemInPriceList) {
	std::string item("Lucky Charms cereal");
	double itemPrice = 3.32;
	double totalBeforeScan, totalAfterScan;

	m_system.setItemPrice(item, itemPrice);
	totalBeforeScan = m_system.getTotalPrice();
	m_system.scanItem(item);
	totalAfterScan = m_system.getTotalPrice();

	EXPECT_FLOAT_EQ(itemPrice, totalAfterScan - totalBeforeScan);
}

TEST_F(PosTest, TestScan1ItemMultipleItemsInPriceList) {
	std::string item("Lucky Charms cereal");
	double itemPrice = 3.32;
	double totalBeforeScan, totalAfterScan;

	m_system.setItemPrice("Pop Tarts Strawberry 16ct", 3.68);
	m_system.setItemPrice(item, itemPrice);
	m_system.setItemPrice("Quaker Quick Cook Oats 18oz", 2.79);

	totalBeforeScan = m_system.getTotalPrice();
	m_system.scanItem(item);
	totalAfterScan = m_system.getTotalPrice();

	EXPECT_FLOAT_EQ(itemPrice, totalAfterScan - totalBeforeScan);
}