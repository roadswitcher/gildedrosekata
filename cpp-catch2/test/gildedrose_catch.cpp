#include <catch2/catch.hpp>
#include <iostream>
#include "ApprovalTests.hpp"

#include "GildedRose.h"

std::ostream& operator<<(std::ostream& os, const Item& obj)
{
    return os
            << "name: " << obj.name
            << ", sellIn: " << obj.sellIn
            << ", quality: " << obj.quality;
}

// vector<Item> items;
// items.push_back(Item("+5 Dexterity Vest", 10, 20 ));
// items.push_back(Item( "Aged Brie", 2, 0));
// items.push_back(Item("Elixir of the Mongoose", 5, 7 ));
// items.push_back(Item( "Sulfuras, Hand of Ragnaros", 0, 80));
// items.push_back(Item("Sulfuras, Hand of Ragnaros", -1, 80 ));
// items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 15, 20 ));
// items.push_back(Item( "Backstage passes to a TAFKAL80ETC concert", 10, 49));
// items.push_back(Item( "Backstage passes to a TAFKAL80ETC concert", 5, 49));
// items.push_back(Item("Conjured Mana Cake", 3, 6 ));

TEST_CASE("AddOneItem") {
    vector<Item> items;
    items.push_back(Item("testitem", 10, 10));
    GildedRose app(items);
    app.updateQuality();
    std::cout << items[0] << std::endl;
    REQUIRE("testitem" == app.items[0].name);
}

TEST_CASE("VerifyQualityDrops"){
    vector<Item> items;
    items.push_back(Item("+5 Dexterity Vest", 10, 20 ));
    GildedRose app(items);
    app.updateQuality();
    std::cout << items[0] << std::endl;

    app.updateQuality();
    std::cout << items[0] << std::endl;

}


