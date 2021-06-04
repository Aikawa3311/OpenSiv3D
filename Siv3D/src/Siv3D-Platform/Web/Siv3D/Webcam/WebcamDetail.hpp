﻿//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2021 Ryo Suzuki
//	Copyright (c) 2016-2021 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# pragma once
# include <Siv3D/Webcam.hpp>
# include <Siv3D/PseudoThread/PseudoThread.hpp>
# include "FrameBufferUnpacker.hpp"
# include "WebCameraCapture.hpp"

namespace s3d
{
	class Webcam::WebcamDetail
	{
	public:

		WebcamDetail();

		~WebcamDetail();

		bool open(uint32 cameraIndex);

		void close();

		bool isOpen();

		bool start();

		bool isActive() const;

		uint32 cameraIndex() const;

		Size getResolution() const;

		bool setResolution(const Size& resolution);

		bool hasNewFrame();

		bool getFrame(Image& image);

		bool getFrame(DynamicTexture& texture);

	private:

		WebCameraCapture m_capture;

		uint32 m_cameraIndex = 0;

		PseudoThread m_thread;

		Size m_captureResolution = Size { 640, 480 };

		GLuint m_copyFrameBuffer = 0;

		Array<FrameBufferUnpacker> m_frameBufferUnpackers;		

		std::atomic<bool> m_abort = { false };

		//////
		//
		GLuint m_capturedFrameBuffer = 0;

		int32 m_newFrameCount = 0;

		int32 m_totalFrameCount = 0;
		//
		//////

		static bool Run(WebcamDetail& webcam);
	};
}
