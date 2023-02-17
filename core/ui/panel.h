#pragma once

#include <vector>
#include <memory>

#include "view.h"
#include "math/vec4.h"

namespace poseidon
{
	class Size
	{
	public:
		enum class Type { Fill, Wrap, Exact };

	public:
		Size(float size);

		static const Size fill;
		static const Size wrap;

		inline float size() const { return size_; }
		inline void setSize(float size) { size_ = size; }

		inline Type type() const { return type_; }

	private:
		Size(Type type);

	private:
		float size_;
		Type type_;
	};

	class LayoutParams
	{
	public:
		LayoutParams();
		LayoutParams(const Size& width, const Size& height);
		LayoutParams(float width, float height);
		virtual ~LayoutParams();

		inline const Size& width() const { return width_; }
		inline void setWidth(const Size& width) { width_ = width; }

		inline const Size& height() const { return height_; }
		inline void setHeight(const Size& height) { height_ = height; }

		inline float exactWidth() const { return width_.size(); }
		inline float exactHeight() const { return height_.size(); }
		inline Vec2 exactSize() const { return { width_.size(), height_.size() }; }

	private:
		Size width_;
		Size height_;
	};

	class MarginLayoutParams : public LayoutParams
	{
	public:
		MarginLayoutParams();
		MarginLayoutParams(const Size& width, const Size& height);
		MarginLayoutParams(float width, float height);

		inline const Thickness& margin() const { return margin_; }
		inline void setMargin(const Thickness& margin) { margin_ = margin; }

	private:
		Thickness margin_;
	};

	class Panel : public View
	{
	public:
		Panel();

		inline const std::vector<std::shared_ptr<View>>& children() const { return children_; }

		inline void addView(std::shared_ptr<View> view) { children_.push_back(view); }
		void addView(std::shared_ptr<View> view, std::unique_ptr<LayoutParams> layoutParams);

		inline const Thickness& padding() const { return padding_; }
		inline void setPadding(const Thickness& padding) { padding_ = padding; }

		inline void setColor(const Vec4& color) { color_ = color; }

	protected:
		virtual void onDraw(const Vec2& relativeOrigin) final;

		void measureChildren();
		void calculateChildArea(Vec2& position, Vec2& size);

	private:
		std::vector<std::shared_ptr<View>> children_;
		Thickness padding_;
		Vec4 color_;
	};
}