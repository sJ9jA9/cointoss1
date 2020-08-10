// Copyright (c) 2018, Filmote
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// * Neither the name of the copyright holder nor the names of its
//   contributors may be used to endorse or promote products derived from
//   this software without specific prior written permission.
//
// Heavily modified by Pharap

#include "PerosaFont3x5.h"

#include <Sprites.h>

constexpr char uppercaseFirst = 'A';
constexpr char uppercaseLast = 'Z';
constexpr uint8_t uppercaseIndex = 0;
constexpr uint8_t uppercaseCount = ((uppercaseLast - uppercaseFirst) + 1);

constexpr char digitsFirst = '0';
constexpr char digitsLast = '9';
constexpr uint8_t digitsIndex = (uppercaseIndex + uppercaseCount);
constexpr uint8_t digitsCount = ((digitsLast - digitsFirst) + 1);

constexpr char punctuationGroupAFirst = '!';
constexpr char punctuationGroupALast = '/';
constexpr uint8_t punctuationGroupAIndex = (digitsIndex + digitsCount);
constexpr uint8_t punctuationGroupACount = ((punctuationGroupALast - punctuationGroupAFirst) + 1);

constexpr char punctuationGroupBFirst = ':';
constexpr char punctuationGroupBLast = '@';
constexpr uint8_t punctuationGroupBIndex = (punctuationGroupAIndex + punctuationGroupACount);
constexpr uint8_t punctuationGroupBCount = ((punctuationGroupBLast - punctuationGroupBFirst) + 1);

constexpr char punctuationGroupCFirst = '[';
constexpr char punctuationGroupCLast = '`';
constexpr uint8_t punctuationGroupCIndex = (punctuationGroupBIndex + punctuationGroupBCount);
constexpr uint8_t punctuationGroupCCount = ((punctuationGroupCLast - punctuationGroupCFirst) + 1);

constexpr char punctuationGroupDFirst = '{';
constexpr char punctuationGroupDLast = '~';
constexpr uint8_t punctuationGroupDIndex = (punctuationGroupCIndex + punctuationGroupCCount);
constexpr uint8_t punctuationGroupDCount = ((punctuationGroupDLast - punctuationGroupDFirst) + 1);

int8_t PerosaFont3x5::getCharIndex(char c)
{
	if((c >= uppercaseFirst) && (c <= uppercaseLast))
		return static_cast<int8_t>(uppercaseIndex + (c - uppercaseFirst));

	if((c >= digitsFirst) && (c <= digitsLast))
		return static_cast<int8_t>(digitsIndex + (c - digitsFirst));

	if((c >= punctuationGroupAFirst) && (c <= punctuationGroupALast))
		return static_cast<int8_t>(punctuationGroupAIndex + (c - punctuationGroupAFirst));

	if((c >= punctuationGroupBFirst) && (c <= punctuationGroupBLast))
		return static_cast<int8_t>(punctuationGroupBIndex + (c - punctuationGroupBFirst));

	if((c >= punctuationGroupCFirst) && (c <= punctuationGroupCLast))
		return static_cast<int8_t>(punctuationGroupCIndex + (c - punctuationGroupCFirst));

	if((c >= punctuationGroupDFirst) && (c <= punctuationGroupDLast))
		return static_cast<int8_t>(punctuationGroupDIndex + (c - punctuationGroupDFirst));

	return -1;
}

const uint8_t PROGMEM fontImages[] =
{
	// Width, Height
	3, 5,

	//
	// Uppercase
	//

	// 'A'
	0x1E, 0x09, 0x1E,

	// 'B'
	0x1F, 0x15, 0x0A,

	// 'C'
	0x0E, 0x11, 0x0A,

	// 'D'
	0x1F, 0x11, 0x0E,

	// 'E'
	0x1F, 0x15, 0x11,

	// 'F'
	0x1F, 0x05, 0x01,

	// 'G'
	0x1F, 0x11, 0x19,

	// 'H'
	0x1F, 0x04, 0x1F,

	// 'I'
	0x11, 0x1F, 0x11,

	// 'J'
	0x18, 0x10, 0x1F,

	// 'K'
	0x1F, 0x04, 0x1B,

	// 'L'
	0x1F, 0x10, 0x10,

	// 'M'
	0x1F, 0x06, 0x1F,
	
	// 'N'
	0x1F, 0x01, 0x1F,
	
	// 'O'
	0x1F, 0x11, 0x1F,
	
	// 'P'
	0x1F, 0x09, 0x06,
	
	// 'Q'
	0x0F, 0x09, 0x17,
	
	// 'R'
	0x1F, 0x09, 0x16,
	
	// 'S'
	0x17, 0x15, 0x1D,
	
	// 'T'
	0x01, 0x1F, 0x01,
	
	// 'U'
	0x1F, 0x10, 0x1F,
	
	// 'V'
	0x0F, 0x10, 0x0F,
	
	// 'W'
	0x1F, 0x0C, 0x1F,
	
	// 'X'
	0x1B, 0x04, 0x1B,
	
	// 'Y'
	0x07, 0x18, 0x07,
	
	// 'Z'
	0x19, 0x15, 0x13,
	
	//
	// Digits
	//

	// '0'
	0x1F, 0x11, 0x1F,
	
	// '1'
	0x12, 0x1F, 0x10,
	
	// '2'
	0x19, 0x15, 0x12,
	
	// '3'
	0x15, 0x15, 0x1F,
	
	// '4'
	0x07, 0x04, 0x1F,
	
	// '5'
	0x17, 0x15, 0x0D,
	
	// '6'
	0x1F, 0x15, 0x1D,
	
	// 7
	0x03, 0x01, 0x1F,
	
	// '8'
	0x1F, 0x15, 0x1F,
	
	// '9'
	0x07, 0x05, 0x1F,

	//
	// Punctuation Group A
	//
		
	// '!'
	0x00, 0x17, 0x00,

	// '"'
	0x03, 0x00, 0x03,

	// '#' X
	0x00, 0x00, 0x00,

	// '$' X
	0x00, 0x00, 0x00,

	// '%'
	0x19, 0x04, 0x13,

	// '&' X
	0x00, 0x00, 0x00,

	// '\''
	0x00, 0x03, 0x00,

	// '('
	0x00, 0x0E, 0x11,

	// ')'
	0x11, 0x0E, 0x00,

	// '*'
	0x0A, 0x04, 0x0A,

	// '+'
	0x04, 0x0E, 0x04,

	// ','
	0x10, 0x08, 0x00,

	// '-'
	0x04, 0x04, 0x04,

	// '.'
	0X00, 0x10, 0x00,

	// '/'
	0x18, 0x04, 0x03,

	//
	// Punctuation Group B
	//
	
	// ':'
	0x00, 0x1B, 0x00,

	// ';'
	0x10, 0x0B, 0x00,

	// '<'
	0x04, 0x0A, 0x11,

	// '='
	0x0A, 0x0A, 0x0A,

	// '>'
	0x11, 0x0A, 0x04,

	// '?'
	0x01, 0x15, 0x03,

	// '@' X
	0x00, 0x00, 0x00,

	//
	// Punctuation Group C
	//
	
	// '['
	0x00, 0x1F, 0x11,

	// '\' 
	0x03, 0x04, 0x18,

	// ']'
	0x11, 0x1f, 0x00,

	// '^'
	0x02, 0x01, 0x02,

	// '_'
	0x10, 0x10, 0x10,

	// '`'
	0x00, 0x01, 0x02,

	//
	// Punctuation Group D
	//
	
	// '{'
	0x04, 0x0E, 0x11,

	// '|'
	0x00, 0x1F, 0x00,

	// '}'
	0x11, 0x0E, 0x04,

	// '~' X
	0x00, 0x00, 0x00,
};

size_t PerosaFont3x5::write(uint8_t c)
{
	if (c == '\n')
	{
		this->cursorX = this->baseX;
		this->cursorY += this->lineHeight;
	}
	else
	{
		this->printChar(c, this->cursorX, this->cursorY);
		this->cursorX += (charWidth + this->letterSpacing);
	}
	return 1;
}

void PerosaFont3x5::printChar(char c, int8_t x, int8_t y)
{
	int8_t index = getCharIndex(c);
	if (index >= 0)
	{
		if (this->textColour != 0)
			Sprites::drawSelfMasked(x, (y + 1), fontImages, index);
		else
			Sprites::drawErase(x, (y + 1), fontImages, index);
	}
}

void PerosaFont3x5::setCursor(int8_t x, int8_t y)
{
	this->baseX = x;
	this->cursorX = x;
	this->cursorY = y;
}

void PerosaFont3x5::setTextColour(uint8_t colour)
{
	this->textColour = colour;
}

void PerosaFont3x5::setHeight(uint8_t colour)
{
	this->lineHeight = colour;
}
