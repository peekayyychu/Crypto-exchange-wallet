#include "OrderBook.h"
#include "CSVreader.h"
#include <map>
#include <string>
#include <vector>

OrderBook::OrderBook(std::string filename){
    orders = CSVReader::readCSV(filename);
}


double OrderBook::getLowPrice(std::vector<OrderBookEntry>& orders)
{
    double min = orders[0].price;
    for(OrderBookEntry& e: orders){
        if(e.price < min)min = e.price;
    }
    return min;
}

double OrderBook::getHighPrice(std::vector<OrderBookEntry>& orders){
    double max = orders[0].price;
    for(OrderBookEntry& e: orders){
        if(e.price > max)max = e.price;
    }
    return max;
}

double OrderBook::getaveragePrice(std::vector<OrderBookEntry>& orders){
    double sum = 0;
    int i = 0;
    for(OrderBookEntry& e: orders){
        sum = sum + e.price;
        i++;
    }
    double average = sum/i;
    return average;
}

std::vector<OrderBookEntry> orders(){

}

std::string OrderBook::getEarliestTime(){
    return orders[0].timestamp;
}

std::string OrderBook::getNextTime(const std::string& timestamp)
{
    std::string next_timestamp = "";
    for (OrderBookEntry& e : orders)
    {
        if (e.timestamp > timestamp)
        {
            next_timestamp = e.timestamp;
            break;
        }
        
    }
    if (next_timestamp == "")
    {
    next_timestamp = getEarliestTime();
    }

    return next_timestamp;
}

/** return vector of all known products in a dataset*/
std::vector <std::string> OrderBook::getKnownProducts(){
    std::vector<std::string> products;
    std::map <std::string,bool> prodMap;
    for(OrderBookEntry& e :orders)
    {
        prodMap[e.product] =  true;
    }
;
    for (const auto& e : prodMap)
    {
    products.push_back(e.first);
    }

    return products;
}

std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type, std::string product, std::string timestamp){
    std::vector<OrderBookEntry> orders_sub;
    for (OrderBookEntry& e: orders){
        if(e.orderType == type && e.product == product && e.timestamp == timestamp){
            orders_sub.push_back(e);
        }
    };
    return orders_sub;
}