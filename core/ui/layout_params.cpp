#include "layout_params.h"

namespace poseidon
{
	const Dimension Dimension::fillParent = Dimension(Type::FillParent);
	const Dimension Dimension::wrapContent = Dimension(Type::WrapContent);

	Dimension::Dimension(float size) :
		size_(size), type_(Type::Exact) {}

	Dimension::Dimension(Type type) :
		size_(0.0f), type_(type) {}

	void Dimension::setFillParent()
	{
		type_ = Type::FillParent;
	}

	void Dimension::setWrapContent()
	{
		type_ = Type::WrapContent;
	}

	void Dimension::setExactSize(float size)
	{
		type_ = Type::Exact;
		size_ = size;
	}

	LayoutParams::LayoutParams(const Dimension& width, const Dimension& height) :
		width_(width), height_(height) {}
}