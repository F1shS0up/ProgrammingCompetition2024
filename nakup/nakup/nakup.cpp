#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include "nakup.h"

int main()
{
    std::ifstream seznam("nakupni_seznam.txt");
    std::ifstream obchody("obchody.txt");
    std::string line;

    std::vector<std::string> items;

    std::vector<std::vector<std::string>> shops;

    GetShoppingList(seznam, line, items);

    GetShopsItems(obchody, line, shops);
    int shopCount = 0;

    while (items.size() > 0) {
        shopCount++;
        std::vector<std::pair<std::vector<int>, int>> wantedShopItems;
        RetrieveShopAndShoppingListCommons(shops, items, wantedShopItems);
        int index = 0;
        GetShopWithHighestCommons(wantedShopItems, index);

        for (int i = 0; i < wantedShopItems[index].first.size(); i++) {
            items.erase(items.begin() + wantedShopItems[index].first[0]);
        }
    }
    std::cout << shopCount << std::endl;
}

void GetShopsItems(std::ifstream& obchody, std::string& line, std::vector<std::vector<std::string>>& shops)
{
    int index = 0;
    bool skip = true;
    while (std::getline(obchody, line, ':')) {
        if (skip) {
            skip = false;
            continue;
        }
        std::vector<std::string> currentItems;
        std::string currentItem = "";
        for (int i = 1; i < line.size(); i++) { // i = 1 because we want to skip space that is after ':'
            if (line[i] == ',' || line[i] == '\n') {
                currentItems.push_back(currentItem);
                currentItem = "";
                i++; // skip the space that is after
            }
            else {
                currentItem += line[i];
            }
        }
        shops.push_back(currentItems);
        index++;
    }
}

void RetrieveShopAndShoppingListCommons(std::vector<std::vector<std::string>>& shops, std::vector<std::string>& items, std::vector<std::pair<std::vector<int>, int>>& wantedShopItems)
{
    for (int i = 0; i < shops.size(); i++) {
        std::vector<int> shopItems;
        for (int j = 0; j < shops[i].size(); j++) {
            for (int s = 0; s < items.size(); s++) {
                if (shops[i][j] == items[s]) {
                    shopItems.push_back(s);
                }
            }
        }
        wantedShopItems.push_back(std::pair<std::vector<int>, int>(shopItems, i));
    }
}

void GetShopWithHighestCommons(std::vector<std::pair<std::vector<int>, int>>& wantedShopItems, int& index)
{
    int largestN = 0;
    for (int i = 0; i < wantedShopItems.size(); i++) {
        if (wantedShopItems[i].first.size() > largestN) {
            largestN = wantedShopItems[i].first.size();
            index = i;
        }
    }
}

void GetShoppingList(std::ifstream& seznam, std::string& line, std::vector<std::string>& items)
{
    while (std::getline(seznam, line)) {
        items.push_back(line);
    }
}