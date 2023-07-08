﻿//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2023 Ryo Suzuki
//	Copyright (c) 2016-2023 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# pragma once

# define CATCH_CONFIG_FAST_COMPILE
# define CATCH_CONFIG_ENABLE_BENCHMARKING
# define CATCH_CONFIG_NEW_CAPTURE
# include <ThirdParty/Catch2/catch.hpp>
# include <Siv3D.hpp>

using namespace s3d;
using namespace std::literals;

std::tuple<std::string, std::string> CaptureStandardOutput(const std::function<void(void)>& logic);

//# define SIV3D_RUN_BENCHMARK
