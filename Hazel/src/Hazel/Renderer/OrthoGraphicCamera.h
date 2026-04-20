#pragma once

#include <glm/glm.hpp>

namespace Hazel
{
	class OrthoGraphicCamera
	{
	public:
		OrthoGraphicCamera(float left, float right, float bottomm, float top);

		const glm::vec3& GetPosition() const { return m_Position; }
		void SetPosition(const glm::vec3& position) { m_Position = position; RecalculateViewMatrix(); }

		const float GetRotation() const { return m_Rotation; }
		void SetRotation(float rotation) { m_Rotation = rotation; RecalculateViewMatrix(); }

		const glm::mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
		void SetProjectionMatrix(const glm::mat4& projection) { m_ProjectionMatrix = projection; RecalculateViewMatrix(); }

		const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; }
		void SetViewMatrix(const glm::mat4& view) { m_ViewMatrix = view; RecalculateViewMatrix(); }

		const glm::mat4& GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }
		void SetViewProjectionMatrix(const glm::mat4& viewProjection) { m_ViewProjectionMatrix = viewProjection; }
	private:
		void RecalculateViewMatrix();
	private:
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ViewProjectionMatrix;

		glm::vec3 m_Position = { 0.0f, 0.0f, 0.0f };
		float m_Rotation = 0.0f;
	};
}