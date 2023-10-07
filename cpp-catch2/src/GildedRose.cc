#include "GildedRose.h"
#include <algorithm>

GildedRose::GildedRose(vector<Item> &items) : items(items) {}

void GildedRose::processItem(Item &item) {
  if (item.name != "Aged Brie" &&
      item.name != "Backstage passes to a TAFKAL80ETC concert") {
    if (item.quality > 0 && !itemIsLegendary(item)) {
      item.quality -= 1;
    }
  } else {
    if (itemQualityUnderMaxValue(item)) {
      item.quality = item.quality + 1;

      if (item.name == "Backstage passes to a TAFKAL80ETC concert") {
        if (item.sellIn < 11) {
          if (itemQualityUnderMaxValue(item)) {
            item.quality = item.quality + 1;
          }
        }

        if (item.sellIn < 6) {
          if (itemQualityUnderMaxValue(item)) {
            item.quality = item.quality + 1;
          }
        }
      }
    }
  }

  if (!itemIsLegendary(item)) {
    item.sellIn = item.sellIn - 1;
  }

  if (item.sellIn < 0) {
    if (item.name != "Aged Brie") {
      if (item.name != "Backstage passes to a TAFKAL80ETC concert") {
        if (item.quality > 0) {
          if (!itemIsLegendary(item)) {
            item.quality = item.quality - 1;
          }
        }
      } else {
        item.quality = item.quality - item.quality;
      }
    } else {
      if (itemQualityUnderMaxValue(item)) {
        item.quality = item.quality + 1;
      }
    }
  }
}


void GildedRose::updateQuality() {
  for (auto &item : items) {
    processItem(item);
  }
}
