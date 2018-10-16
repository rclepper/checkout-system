#pragma once
#include <string>
#include <unordered_map>

namespace pos
{

enum ScanResult
{
	Found,
	NotFound
};

class PointOfSaleSystem
{
public:
	PointOfSaleSystem() : m_priceList(0), m_totalPrice(0.0) {}
	~PointOfSaleSystem() {}

	void setItemPrice(std::string item, double itemPrice);

	ScanResult scanItem(std::string item);
	double getTotalPrice();

private:

	std::unordered_map<std::string, double> m_priceList; // item, price
	double m_totalPrice;
};

} // namespace pos




