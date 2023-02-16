#include "font.h"

#include <fstream>
#include "rendering/texture.h"
#include "nlohmann/json.hpp"

#include <iostream>

using Json = nlohmann::json;

namespace poseidon
{
	GlyphMeasurements::GlyphMeasurements() :
		bearingX(0), bearingY(0),
		width(0), height(0),
		uvX(0), uvY(0),
		advance(0) {}

	GlyphMeasurements::GlyphMeasurements(
		int32_t bearingX, int32_t bearingY,
		uint32_t width, uint32_t height,
		uint32_t uvX, uint32_t uvY,
		uint32_t advance) :
		bearingX(bearingX), bearingY(bearingY),
		width(width), height(height),
		uvX(uvX), uvY(uvY),
		advance(advance) {}

	Font::Font(const std::string& atlasFilepath, const std::string& atlasDataFilepath) :
		atlas_(std::make_shared<Texture>(atlasFilepath))
	{
		std::ifstream f(atlasDataFilepath);
		Json data = Json::parse(f);
		for (auto& glyphData : data["glyphTable"].items())
		{
			const Json& data = glyphData.value();
			char32_t codePoint = data["codePoint"].get<uint32_t>();
			uint32_t bearingX = data["bearingX"].get<uint32_t>();
			uint32_t bearingY = data["bearingY"].get<uint32_t>();
			uint32_t width = data["width"].get<uint32_t>();
			uint32_t height = data["height"].get<uint32_t>();
			uint32_t uvX = data["uvX"].get<uint32_t>();
			uint32_t uvY = data["uvY"].get<uint32_t>();
			uint32_t advance = data["advance"].get<uint32_t>();

			glyphs_[codePoint] = GlyphMeasurements(
				bearingX, bearingY,
				width, height,
				uvX, uvY,
				advance
			);
		}
	}

	Font::~Font()
	{

	}
}