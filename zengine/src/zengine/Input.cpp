#include "Input.h"
#include <iostream>
namespace zengine
{
    //glm::vec3 Input::Movement(const SDL_Event& evt)
    //{
    //    // Calculate the forward and right direction vectors based on the model's rotation (m_rotation.y)
    //    glm::vec3 forward;
    //    forward.x = sin(glm::radians(m_rotation.y));  // Sine gives us the direction on the X-axis
    //    forward.z = cos(glm::radians(m_rotation.y));  // Cosine gives us the direction on the Z-axis
    //    forward = glm::normalize(forward);  // Normalize the forward vector

    //    glm::vec3 right;
    //    right.x = sin(glm::radians(m_rotation.y - 90.0f));  // Right is 90 degrees to the left (counterclockwise)
    //    right.z = cos(glm::radians(m_rotation.y - 90.0f));
    //    right = glm::normalize(right);  // Normalize the right vector

    //    if (evt.type == SDL_KEYDOWN)
    //    {
    //        switch (evt.key.keysym.sym)
    //        {
    //        case SDLK_w:
    //            // Move forward in the direction the model is facing (relative to the forward vector)
    //            m_position += forward * 0.05f;  // Fine-tune the movement sensitivity (0.05f)
    //            std::cout << "W" << std::endl;
    //            break;

    //        case SDLK_s:
    //            // Move backward (in the opposite direction of forward)
    //            m_position -= forward * 0.05f;  // Fine-tune the movement sensitivity (0.05f)
    //            std::cout << "S" << std::endl;
    //            break;

    //        case SDLK_a:
    //            // Move left (relative to the model's orientation, in the direction of the right vector)
    //            m_position -= right * 0.05f;  // Fine-tune the movement sensitivity (0.05f)
    //            std::cout << "A" << std::endl;
    //            break;

    //        case SDLK_d:
    //            // Move right (relative to the model's orientation, in the direction of the right vector)
    //            m_position += right * 0.05f;  // Fine-tune the movement sensitivity (0.05f)
    //            std::cout << "D" << std::endl;
    //            break;

    //        case SDLK_SPACE:
    //            break;
    //        }
    //    }
    //    return m_position;
    //}





    //glm::vec3 Input::Rotation(const SDL_Event& evt)
    //{
    //    static int prevX = 0, prevY = 0;  // Previous mouse position
    //    static bool isLeftMouseDown = false;  // Track left mouse button state

    //    // Get the current mouse position
    //    int mouseX, mouseY;
    //    SDL_GetMouseState(&mouseX, &mouseY);

    //    // Check if the left mouse button is pressed or released
    //    if (evt.type == SDL_MOUSEBUTTONDOWN && evt.button.button == SDL_BUTTON_LEFT) {
    //        isLeftMouseDown = true;  // Left mouse button is pressed
    //    }
    //    else if (evt.type == SDL_MOUSEBUTTONUP && evt.button.button == SDL_BUTTON_LEFT) {
    //        isLeftMouseDown = false;  // Left mouse button is released
    //    }

    //    // If the left mouse button is held down, calculate rotation
    //    if (isLeftMouseDown) {
    //        // Calculate the mouse movement (delta)
    //        int deltaX = mouseX - prevX;
    //        // We don't use deltaY since we only want to rotate horizontally (around the Y-axis)

    //        // Sensitivity factor to control how fast the rotation changes
    //        const float sensitivity = 0.1f;

    //        // Update rotation based on mouse movement (delta)
    //        m_rotation.y += deltaX * sensitivity;  // Rotate around Y-axis

    //        // Optionally, clamp the rotation values to avoid extreme values (if needed)
    //        // m_rotation.y = glm::clamp(m_rotation.y, -180.0f, 180.0f); // Example of limiting horizontal rotation

    //        // Update previous mouse position for the next frame
    //        prevX = mouseX;
    //        prevY = mouseY;
    //    }

    //    // Return the updated rotation values
    //    return m_rotation;
    //}

    glm::vec3 Input::Movement(const SDL_Event& evt)
    {
        glm::vec3 forward(0.0f, 0.0f, -1.0f); 
        glm::vec3 backward(0.0f, 0.0f, 1.0f);
        glm::vec3 left(-1.0f, 0.0f, 0.0f);     
        glm::vec3 right(1.0f, 0.0f, 0.0f);     

        if (evt.type == SDL_KEYDOWN)
        {
            switch (evt.key.keysym.sym)
            {
            case SDLK_w:
                m_position += forward * 0.05f;
                break;

            case SDLK_s:
                m_position += backward * 0.05f;
                break;

            case SDLK_a:
                m_position += left * 0.05f;
                break;

            case SDLK_d:
                m_position += right * 0.05f;
                break;

            case SDLK_SPACE:
                break;
            }
        }
        return m_position;
    }

    glm::vec3 Input::Rotation(const SDL_Event& evt)
    {
        // set rotation of model to direction of movement
        if (evt.type == SDL_KEYDOWN)
        {
            switch (evt.key.keysym.sym)
            {
            case SDLK_w:
                m_rotation.y = 40.7999f;
				m_rotation.x = 0.0f;
                break;

            case SDLK_a:
                m_rotation.y = -90.0f;
				m_rotation.x = 0.0f;
                break;

            case SDLK_s:
                m_rotation.y = 0.0f;
				m_rotation.x = 0.0f;
                break;

            case SDLK_d:
                m_rotation.y = 90.0f;
				m_rotation.x = 0.0f;
                break;

            default:
                break;
            }
        }


        //mouse rotation of cat
        static int prevX = 0, prevY = 0; 
        static bool isLeftMouseDown = false;
        // Get the current mouse position
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);

        if (evt.type == SDL_MOUSEBUTTONDOWN && evt.button.button == SDL_BUTTON_LEFT) 
        {
            isLeftMouseDown = true;  
        }
        else if (evt.type == SDL_MOUSEBUTTONUP && evt.button.button == SDL_BUTTON_LEFT) 
        {
            isLeftMouseDown = false;  
        }

        if (isLeftMouseDown) 
        {
            int deltaX = mouseX - prevX;
			int deltaY = mouseY - prevY;

            m_rotation.y += deltaX * mouseSensitivity; 
			m_rotation.x += deltaY * mouseSensitivity;

            prevX = mouseX;
            prevY = mouseY;
        }


        return m_rotation;
    }




    void Input::RecievePosition(glm::vec3 position)
    {
        m_position = position;
    }
    void Input::RecieveRotation(glm::vec3 rotation)
    {
		m_rotation = rotation;
    };
}