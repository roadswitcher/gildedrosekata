#include "GildedRose.h"
#include <algorithm>

using namespace GR;

GildedRose::GildedRose(vector<Item> &items) : items(items) {}

void GildedRose::processItem(Item &item) {
  if (item.name != "Aged Brie" &&
      item.name != "Backstage passes to a TAFKAL80ETC concert") {
    if (item.quality > 0 && !isItemLegendary(item)) {
      item.quality -= 1;
    }
  } else {
    if (isQualityUnderMaxValue(item)) {
      item.quality = item.quality + 1;

      if (item.name == "Backstage passes to a TAFKAL80ETC concert") {
        if (item.sellIn < 11) {
          if (item.quality < 50) {
            item.quality = item.quality + 1;
          }
        }

        if (item.sellIn < 6) {
          if (isQualityUnderMaxValue(item)) {
            item.quality = item.quality + 1;
          }
        }
      }
    }
  }

  if (!isItemLegendary(item)) {
    item.sellIn = item.sellIn - 1;
  }

  if (item.sellIn < 0) {
    if (item.name != "Aged Brie") {
      if (item.name != "Backstage passes to a TAFKAL80ETC concert") {
        if (item.quality > 0) {
          if (!isItemLegendary(item)) {
            item.quality = item.quality - 1;
          }
        }
      } else {
        item.quality = item.quality - item.quality;
      }
    } else {
      if (isQualityUnderMaxValue(item)) {
        item.quality = item.quality + 1;
      }
    }
  }
}

bool GildedRose::isItemLegendary(Item &item) {
  vector<string> legendaries = {"Sulfuras, Hand of Ragnaros"};

  if (binary_search(legendaries.begin(), legendaries.end(), item.name)) {
    return true;
  }
  return false;
}

bool GildedRose::isConjured(Item &item) {
  return item.name.rfind("Conjured", 0) == 0;
}

bool GildedRose::isQualityUnderMaxValue(Item &item) {
  return item.quality < 50;
}

void GildedRose::updateQuality() {
  for (auto &item : items) {
    processItem(item);
  }
}
