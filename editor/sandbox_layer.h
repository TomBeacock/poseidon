#pragma once

#include <poseidon/core.h>
#include <memory>

namespace poseidon
{
	class Event;
	class ArrayBuffer;
	class IndexBuffer;
	class VertexArray;
	class Shader;
	class Texture;
}

namespace editor
{
	class SandboxLayer : public poseidon::Layer
	{
	public:
		SandboxLayer();
		virtual ~SandboxLayer() override;

		virtual void onStart() override;
		virtual void onUpdate(float deltaTime) override;
		virtual bool onEvent(const poseidon::Event& event) override;

	private:
		std::unique_ptr<poseidon::ArrayBuffer> cubeVbo_;
		std::unique_ptr<poseidon::IndexBuffer> cubeIbo_;
		std::unique_ptr<poseidon::VertexArray> cubeVao_;
		std::unique_ptr<poseidon::Shader> cubeShader_, quadShader_;
		std::shared_ptr<poseidon::Texture> quadTexture_;

		float angle_;
	};
}