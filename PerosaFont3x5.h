#pragma once

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

#include <stddef.h>
#include <stdint.h>
#include <Print.h>

class PerosaFont3x5 : public Print
{
public:
	static constexpr uint8_t charWidth = 3;
	static constexpr uint8_t charHeight = 6;

private:
	// Needed for linebreak.
	int8_t baseX = 0;
	
	int8_t cursorX = 0;
	int8_t cursorY = 0;

	// 0 is Black, everything else is White.
	uint8_t textColour = 1;

	// letterSpacing controls the distance between letters.
	uint8_t letterSpacing = 1;

	// lineHeight controls the height between lines (separated by '\n').
	uint8_t lineHeight = 8;

public:
	PerosaFont3x5() = default;
	
	PerosaFont3x5(uint8_t lineSpacing)
		: lineHeight(lineSpacing)
	{
	}

	// Overrides Print::write
	size_t write(uint8_t) override;
	
	void printChar(char c, int8_t x, int8_t y);
	
	void setCursor(int8_t x, int8_t y);

	void setTextColour(uint8_t colour);
	
	void setHeight(uint8_t height);
	
private:
	static int8_t getCharIndex(char c);
};
