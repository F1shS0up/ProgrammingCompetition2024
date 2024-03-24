#pragma once

void RetrieveShopsAndBuyingListCommons(std::vector<std::vector<std::string>>& shops, std::vector<std::string>& items, std::vector<std::pair<std::vector<int>, int>>& wantedShopItems);

void GetShoppingList(std::ifstream& seznam, std::string& line, std::vector<std::string>& items);

void GetShopWithHighestCommons(std::vector<std::pair<std::vector<int>, int>>& wantedShopItems, int& index);

void RetrieveShopAndShoppingListCommons(std::vector<std::vector<std::string>>& shops, std::vector<std::string>& items, std::vector<std::pair<std::vector<int>, int>>& wantedShopItems);

void GetShopsItems(std::ifstream& obchody, std::string& line, std::vector<std::vector<std::string>>& shops);
