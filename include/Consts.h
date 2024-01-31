#pragma once
#include <string>

const std::string m_imgNamesArr[8] = { "mouse.png", "cat.png","cheese.png",
                                       "door.png","gift.png", "key.png",
                                       "wall.jpg", "Background.jpg" };

const char charArr[7] = { '%', '^', '*', 'D', '$', 'F', '#' };

enum objects{ Mouse, Cat, Cheese, Door, Gift, Key, Wall, 
              Background, Save, Delete, None };