#pragma once

#include "main.h"

#include <string>
#include <memory>

/**
 * @class GUI
 * @brief Graphical User Interface wrapper class that encapsulates much of the
 * details needed to use the imGUI user interface toolkit.
 *
 * This class hides some of the functions and variables needed to
 * create a user interface with imGUI. To use it, you need to
 * construct a GUI instance, and then call the mainLoop function.
 */
class GUI {
public:
	/**
	 * Base constructor for GUI
	 *
	 */
	GUI();
	virtual ~GUI();

	/**
	 * Change the background color of the GUI, which is specified with RGB color values.  See https://rgbcolorpicker.com/0-1 for some
	 * way to see how these colors are formed.
	 *
	 * @param red float that specifies the red component. Value is in the range of 0.0f to 1.0f, with 0.0 being no red and 1.0 being all red
	 * @param green float that specifies the greend component. Value is in the range of 0.0f to 1.0f, with 0.0 being no green and 1.0 being all green
	 * @param blue float that specifies the blued component. Value is in the range of 0.0f to 1.0f, with 0.0 being no blue and 1.0 being all blue
	 * @return Nothing returned.
	 */
	void setBackgroundColor(float red, float green, float blue);

	/**
	 * The bulk of the code for rendering various GUI elements, such as
	 * buttons, input text boxes and other items. The mainLoop function
	 * does not return unless the GUI window is closed.
	 *
	 * @return Nothing returned.
	 */
	void mainLoop();

private:
	// Variable that holds a pointer to the underlying window toolkit
	// implementation.
	GLFWwindow* m_window;

	// You can change the clear color 
	ImVec4 m_clear_color;
	static constexpr std::string_view m_windowTitle{ "Visual Sort" };
	static void makeFrame();
	static void fortniteComponent();
	void render();
};

