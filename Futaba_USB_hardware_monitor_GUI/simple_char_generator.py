# -*- coding: utf-8 -*-
import cv2
from numba import njit
from font_5x7 import *
from font_8x12 import *
from font_14x28 import *


@njit(cache=True)
def draw_5x7_Char(img, x, y, character_code, character_color=255, background_color=0):
    character_canvas = np.full((7, 5), background_color, dtype=np.uint8)
    # A quick and dirty fix for UTF-8 cyrillic characters
    if character_code > 1039 and character_code < 1104:
        character_code -= 848
    # 'Ё' 1025 UTF-8 = 168 CP-1251
    if character_code == 1025:
        character_code = 168
    # 'ё' 1105 UTF-8 = 184 CP-1251
    if character_code == 1105:
        character_code = 184
    if character_code < 32:
        return img
    # if (x>251) or (y>57):
    #     return image
    char_matrix = font_5x7[character_code - 32]
    img[y:7 + y, x:5 + x] = (character_canvas + char_matrix * character_color) - (character_canvas * char_matrix)
    return img


@njit(cache=True)
def draw_5x7_String(img, text, position, character_color=255, background_color=0):
    """Draws a text string with 5x7 font.

    Parameters
    ----------
    img : Image
    text : Text to be drawn.
    position : Upper-left corner of the text string in the image.
    character_color : Text color
    background_color : Background color
    """
    (x, y) = position
    for i in range(0, len(text)):
        img[y:7 + y, (x + i * 6):6 + (x + i * 6)] = np.full((7, 6), background_color, dtype=np.uint8)
        draw_5x7_Char(img, x + i * 6, y, ord(text[i]), character_color, background_color)
    return img


@njit(cache=True)
def draw_8x12_Char(img, x, y, character_code, character_color=255, background_color=0):
    character_canvas = np.full((12, 8), background_color, dtype=np.uint8)
    # A quick and dirty fix for UTF-8 cyrillic characters
    if character_code > 1039 and character_code < 1104:
        character_code -= 848
    # 'Ё' 1025 UTF-8 = 168 CP-1251
    if character_code == 1025:
        character_code = 168
    # 'ё' 1105 UTF-8 = 184 CP-1251
    if character_code == 1105:
        character_code = 184
    if character_code < 32 or character_code > 1105:
        return img
    char_matrix = font_8x12[character_code - 32]
    img[y:12 + y, x:8 + x] = (character_canvas + char_matrix * character_color) - (character_canvas * char_matrix)
    return img


@njit(cache=True)
def draw_8x12_String(img, text, position, character_color=255, background_color=0):
    """Draws a text string with 8x12 font.

    Parameters
    ----------
    img : Image
    text : Text to be drawn.
    position : Upper-left corner of the text string in the image.
    character_color : Text color
    background_color : Background color
    """
    (x, y) = position
    for i in range(0, len(text)):
        draw_8x12_Char(img, x + i * 8, y, ord(text[i]), character_color, background_color)
    return img


@njit
def draw_14x28_Char(img, x, y, character_code, character_color=255, background_color=0):
    character_canvas = np.full((28, 14), background_color, dtype=np.uint8)
    # A quick and dirty fix for UTF-8 cyrillic characters
    if character_code > 1039 and character_code < 1104:
        character_code -= 848
    # 'Ё' 1025 UTF-8 = 168 CP-1251
    if character_code == 1025:
        character_code = 168
    # 'ё' 1105 UTF-8 = 184 CP-1251
    if character_code == 1105:
        character_code = 184
    if character_code < 32 or character_code > 1105:
        return img
    char_matrix = font_14x28[character_code - 32]
    img[y:28 + y, x:14 + x] = (character_canvas + char_matrix * character_color) - (character_canvas * char_matrix)
    return img


@njit(cache=True)
def draw_14x28_String(img, text, position, character_color=255, background_color=0):
    """Draws a text string with 8x12 font.

    Parameters
    ----------
    img : Image
    text : Text to be drawn.
    position : Upper-left corner of the text string in the image.
    character_color : Text color
    background_color : Background color
    """
    (x, y) = position
    for i in range(0, len(text)):
        draw_14x28_Char(img, x + i * 14, y, ord(text[i]), character_color, background_color)
    return img


if __name__ == "__main__":
    input_img = np.full((80, 500), 96, dtype=np.uint8)
    draw_5x7_String(input_img, "This is string with 5x7 font", (10, 10))
    draw_8x12_String(input_img, "This is string with 8x12 font", (10, 20))
    draw_14x28_String(input_img, "This is string with 14x28 font", (10, 35))
    cv2.imshow("test", input_img)
    cv2.waitKey(0)
