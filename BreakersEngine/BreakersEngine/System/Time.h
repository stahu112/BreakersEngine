#pragma once

namespace BE
{
	/*!
	 * @brief Namespace with all the time specific globals and functions
	 */
	class Time
	{
	public:
		float timeScale = 1.0f;
		/*!
		* @brief Current dt - TimeStep between frames
		*
		*/
		float dt = 0.0f;
		/*!
		* @brief Fixed constant TimeStep
		*
		* @note If you do any physics calculations, you should use this instead of dt to avoid undefined behaviour
		*/
		float fixedDt = 0.016667f;
		/*!
		* @brief Current frames per second
		*
		*/
		float fps = 0.0f;

	};


} //End namespace BE