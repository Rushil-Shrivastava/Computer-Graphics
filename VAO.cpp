#include"VAO.h"

// Constructor that generates a VAO ID
VAO::VAO()
{
	/// @note Constructor that generates a VAO ID
	
	glGenVertexArrays(1, &ID);
}

// Links a VBO Attribute such as a position or color to the VAO
void VAO::LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
{
	/// @note Links a VBO Attribute such as a position or color to the VAO
	
	VBO.Bind();
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	VBO.Unbind();
}

// Binds the VAO
void VAO::Bind()
{
	/// @note Binds the VAO
	
	glBindVertexArray(ID);
}

// Unbinds the VAO
void VAO::Unbind()
{
	/// @note Unbinds the VAO
	
	glBindVertexArray(0);
}

// Deletes the VAO
void VAO::Delete()
{
	/// @note Deletes the VAO
	
	glDeleteVertexArrays(1, &ID);
}