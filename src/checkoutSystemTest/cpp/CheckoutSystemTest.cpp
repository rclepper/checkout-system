#include "PointOfSaleSystem.h"
#include <string>
#include <gtest/gtest.h>

class PosTest : public ::testing::Test
{
protected:
	pos::PointOfSaleSystem m_system;
};

TEST_F(PosTest, TestGetInitialTotalPrice) {
	EXPECT_DOUBLE_EQ(m_system.getTotalPrice(), 0.0);
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

	EXPECT_DOUBLE_EQ(itemPrice, totalAfterScan - totalBeforeScan);
}

TEST_F(PosTest, TestScan1ItemMultipleItemsInPriceList) {
	std::string scannedItem("Lucky Charms cereal");
	double scannedItemPrice = 3.32;
	double totalBeforeScan, totalAfterScan;

	m_system.setItemPrice("Pop Tarts Strawberry 16ct", 3.68);
	m_system.setItemPrice(scannedItem, scannedItemPrice);
	m_system.setItemPrice("Quaker Quick Cook Oats 18oz", 2.79);

	totalBeforeScan = m_system.getTotalPrice();
	m_system.scanItem(scannedItem);
	totalAfterScan = m_system.getTotalPrice();

	EXPECT_DOUBLE_EQ(scannedItemPrice, totalAfterScan - totalBeforeScan);
}

TEST_F(PosTest, TestScanMultipleEachesItems) {
	std::string scannedItem1("Pop Tarts Strawberry 16ct");
	double scannedItem1Price = 3.68;
	std::string scannedItem2("Lucky Charms cereal");
	double scannedItem2Price = 3.32;
	std::string scannedItem3("Quaker Quick Cook Oats 18oz");
	double scannedItem3Price = 2.79;
	double totalBeforeScans, totalAfterScans;

	m_system.setItemPrice(scannedItem1, scannedItem1Price);
	m_system.setItemPrice(scannedItem2, scannedItem2Price);
	m_system.setItemPrice(scannedItem3, scannedItem3Price);

	totalBeforeScans = m_system.getTotalPrice();
	m_system.scanItem(scannedItem1);
	m_system.scanItem(scannedItem2);
	m_system.scanItem(scannedItem3);
	totalAfterScans = m_system.getTotalPrice();

	EXPECT_DOUBLE_EQ(scannedItem1Price + scannedItem2Price + scannedItem3Price,
		totalAfterScans - totalBeforeScans);
}

TEST_F(PosTest, TestScan3OfSameItem) {
	std::string scannedItem("Lucky Charms cereal");
	double scannedItemPrice = 3.32;
	double totalBeforeScan, totalAfterScan;

	m_system.setItemPrice("Pop Tarts Strawberry 16ct", 3.68);
	m_system.setItemPrice(scannedItem, scannedItemPrice);

	totalBeforeScan = m_system.getTotalPrice();
	m_system.scanItem(scannedItem);
	m_system.scanItem(scannedItem);
	m_system.scanItem(scannedItem);
	totalAfterScan = m_system.getTotalPrice();

	EXPECT_DOUBLE_EQ(scannedItemPrice * 3, totalAfterScan - totalBeforeScan);
}

TEST_F(PosTest, TestScanWeightedItem) {
	std::string scannedItem("Ground Beef");
	double scannedPerLbPrice = 1.99;
	double scannedWeight = 2.5;
	double totalBeforeScan, totalAfterScan;

	m_system.setItemPrice("Pop Tarts Strawberry 16ct", 3.68);
	m_system.setItemPrice(scannedItem, scannedPerLbPrice);
	m_system.setItemPrice("Quaker Quick Cook Oats 18oz", 2.79);

	totalBeforeScan = m_system.getTotalPrice();
	m_system.scanItem(scannedItem, scannedWeight);
	totalAfterScan = m_system.getTotalPrice();

	EXPECT_DOUBLE_EQ(scannedPerLbPrice * scannedWeight, totalAfterScan - totalBeforeScan);
}