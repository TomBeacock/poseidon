#pragma once

namespace poseidon
{
	class Dimension {
	public:
		enum class Type { FillParent, WrapContent, Exact };

		Dimension(float size);

		static const Dimension fillParent;
		static const Dimension wrapContent;

		float size() const { return size_; }
		Type type() const { return type_; }

		void setFillParent();
		void setWrapContent();
		void setExactSize(float size);

	private:
		Dimension(Type type);

	private:
		float size_;
		Type type_;
	};

	class LayoutParams
	{
	public:
		LayoutParams(const Dimension& width, const Dimension& height);
		
		Dimension& width() { return width_; }
		Dimension& height() { return height_; }

	private:
		Dimension width_;
		Dimension height_;
	};
}