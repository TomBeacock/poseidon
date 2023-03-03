#pragma once

#include <vector>
#include <string>

#include "compound_widget.h"

namespace poseidon
{
	class Tab : public CompoundWidget
	{
	public:
		Tab(const std::u8string& label, std::shared_ptr<Widget> content = nullptr);

		inline const std::shared_ptr<Widget>& content() const { return content_; };
		inline void setContent(std::shared_ptr<Widget> content) { content_ = content; }

	private:
		std::shared_ptr<class Text> text_;
		std::shared_ptr<Widget> content_;
	};

	class TabPanel : public CompoundWidget
	{
	public:
		TabPanel();

		void addTab(std::shared_ptr<Tab> tab);

		void selectTab(const std::shared_ptr<Tab>& tab);

	private:
		std::shared_ptr<class HorizontalPanel> tabBar_;
		std::shared_ptr<class VerticalPanel> contentPanel_;
		std::vector<std::shared_ptr<Tab>> tabs_;
	};
}