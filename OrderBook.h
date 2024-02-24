#pragma once
#include "OrderBookEntry.h"
#include "CSVreader.h"
#include <string>
#include <vector>

class OrderBook
{
    public:
        /** construct, reading a csv data file */
        OrderBook(std::string filename);
        /** return vector of all know products in the dataset*/
        std::vector<std::string> getKnownProducts();
        /** return vector of Orders according to the sent filters*/
        std::vector<OrderBookEntry> getOrders(OrderBookType type,
        std::string product,
        std::string timestamp);
        /** return the price of the highest bid in the sent set */
        static double getHighPrice(std::vector<OrderBookEntry>& orders);
        /** return the price of the lowest bid in the sent set */
        static double getLowPrice(std::vector<OrderBookEntry>& orders);
        std::string getEarliestTime();
        std::string getNextTime(const std::string& timestamp);
        /**returns the average price offered for a commodity*/
        static double getaveragePrice(std::vector<OrderBookEntry>& orders);
    private:
        std::vector<OrderBookEntry> orders;
};