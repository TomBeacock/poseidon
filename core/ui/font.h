#pragma once

#include <string>
#include <memory>
#include <unordered_map>

namespace poseidon
{
	class Texture;

	struct GlyphMeasurements
	{
		int32_t bearingX, bearingY;
		uint32_t width, height;
		uint32_t uvX, uvY;
		uint32_t advance;

		GlyphMeasurements();
		GlyphMeasurements(
			int32_t bearingX, int32_t bearingY,
			uint32_t width, uint32_t height,
			uint32_t uvX, uint32_t uvY,
			uint32_t advance);
	};

	class Font
	{
	public:
		Font(const std::string& atlasFilepath, const std::string& atlasDataFilepath);
		~Font();

		inline const std::shared_ptr<Texture>& atlas() const { return atlas_; }
		inline const GlyphMeasurements& glyph(char32_t codePoint) const { return glyphs_.at(codePoint); }

	private:
		std::shared_ptr<Texture> atlas_;
		std::unordered_map<char32_t, GlyphMeasurements> glyphs_;
	};
}