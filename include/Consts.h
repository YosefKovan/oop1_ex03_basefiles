#pragma once
#include <string>

//------------------------- String ---------------------------
const std::string m_imgNamesArr[11] = { "mouse.png", "cat.png","cheese.png",
                                       "door.png","gift.png", "key.png",
                                       "wall.jpg", "save.png","bin.png", 
                                       "Reset.png","Background.jpg" };
//------------------------  Chars -----------------------------

const char charArr[7] = { '%', '^', '*', 'D', '$', 'F', '#' };

const char WHITESPACE = ' ';
//------------------------- Enums ----------------------------

enum objects{ Mouse, Cat, Cheese, Door, Gift, Key, Wall, 
              Save, Bin, Reset, Background, None };
//------------------------- Int ------------------------------
const int MAX_COLS = 20, MAX_ROWS = 20, GRID_SQR = 40,
          BAR_OBJ_AMOUNT = 10, OBJ_AMOUNT = 7, TOTLA_IMG_AMOUNT = 11;