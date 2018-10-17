#pragma once
#include <memory>
#include <string>
#include <unordered_map>

namespace pos
{

enum ScanResult
{
	Found,
	NotFound
};

class ScannedItemPrice
{
public:
	virtual double getPrice() = 0;
};

class ScannedEachesItemPrice : public ScannedItemPrice
{
public:
	ScannedEachesItemPrice(double itemPrice);
	double getPrice();
private:
	double m_itemPrice;
};

class ScannedWeighedItemPrice : public ScannedItemPrice
{
public:
	ScannedWeighedItemPrice(double itemPricePerLb, double itemWeightInLbs);
	double getPrice();
private:
	double m_itemPricePerLb;
	double m_itemWeightInLbs;
};

class PointOfSaleSystem
{
public:
	PointOfSaleSystem() : m_priceList(0), m_totalPrice(0.0) {}
	~PointOfSaleSystem() {}

	void setItemPrice(std::string item, double itemPrice);
	void setWeighedItemPrice(std::string item, double itemPricePerLb);

	ScanResult scanItem(std::string item);
	ScanResult scanItem(std::string item, double weightInLbs);

	double getTotalPrice();

private:

	std::unordered_map<std::string, double> m_priceList;
	std::unordered_map<std::string, std::unique_ptr<ScannedItemPrice>> m_scannedItems;

	double m_totalPrice;
};

} // namespace pos




