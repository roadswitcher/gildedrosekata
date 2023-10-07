#include "ApprovalTests.hpp"
#include <catch2/catch.hpp>
#include <iostream>

#include "GildedRose.h"

using namespace GR;

std::ostream &operator<<(std::ostream &os, const Item &obj) {
  return os << "name: " << obj.name << ", sellIn: " << obj.sellIn
            << ", quality: " << obj.quality;
}

TEST_CASE("AddOneItem") {
  vector<Item> items;
  items.push_back(Item("testitem", 10, 10));
  GildedRose app(items);
  app.updateQuality();
  REQUIRE("testitem" == app.items[0].name);
}

TEST_CASE("VerifyQualityDrops") {
  vector<Item> items;
  items.push_back(Item("+5 Dexterity Vest", 10, 20));
  GildedRose app(items);
  app.updateQuality();
  REQUIRE(app.items[0].quality == 19);
  app.updateQuality();
  REQUIRE(app.items[0].quality == 18);
}

TEST_CASE("30 Day Check") {

  vector<Item> items;
  items.push_back(Item("+5 Dexterity Vest", 10, 20));
  items.push_back(Item("Aged Brie", 2, 0));
  items.push_back(Item("Elixir of the Mongoose", 5, 7));
  items.push_back(Item("Sulfuras, Hand of Ragnaros", 0, 80));
  items.push_back(Item("Sulfuras, Hand of Ragnaros", -1, 80));
  items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 15, 20));
  items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 10, 49));
  items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 5, 49));
  items.push_back(Item("Conjured Mana Cake", 3, 6));

  vector<Item> day30items;
  day30items.push_back(Item("+5 Dexterity Vest", -20, 0));
  day30items.push_back(Item("Aged Brie", -28, 50));
  day30items.push_back(Item("Elixir of the Mongoose", -25, 0));
  day30items.push_back(Item("Sulfuras, Hand of Ragnaros", 0, 80));
  day30items.push_back(Item("Sulfuras, Hand of Ragnaros", -1, 80));
  day30items.push_back(
      Item("Backstage passes to a TAFKAL80ETC concert", -15, 0));
  day30items.push_back(
      Item("Backstage passes to a TAFKAL80ETC concert", -20, 0));
  day30items.push_back(
      Item("Backstage passes to a TAFKAL80ETC concert", -25, 0));
  day30items.push_back(Item("Conjured Mana Cake", -27, 0));

  GildedRose app(items);

  for (auto i = 1; i <= 30; i++) {
    app.updateQuality();
    std::cout << "------ day " << i << "-------" << std::endl;
    for (auto item : app.items) {
      std::cout << item.name << ", " << item.sellIn << ", " << item.quality
                << endl;
    }
  }

  for (auto j = 0; j < 9; j++) {
    REQUIRE(app.items[j].sellIn == day30items[j].sellIn);
    REQUIRE(app.items[j].quality == day30items[j].quality);
  }
}