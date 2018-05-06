#pragma once

namespace BE
{
	/*!
	 * @brief Namespace with all the time specific globals and functions
	 */
	namespace Time
	{
		/*!
		 * @brief Factor to manipulate the speed of the game
		 *
		 */
		static float timeScale = 1.0f;
		/*!
		 * @brief Current dt - TimeStep between frames
		 *
		 */
		static float dt = 0.0f;
		/*!
		 * @brief Fixed constant TimeStep
		 *
		 * @note If you do any physics calculations, you should use this instead of dt to avoid undefined behaviour
		 */
		static float fixedDt = 0.016667f;
		/*!
		 * @brief Current frames per second
		 *
		 */
		static float fps = 0.0f;


	} //End namespace Time
} //End namespace BE