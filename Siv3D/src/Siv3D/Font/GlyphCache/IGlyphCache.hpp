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
# include <Siv3D/Common.hpp>
# include <Siv3D/2DShapes.hpp>
# include <Siv3D/Texture.hpp>
# include <Siv3D/Font.hpp>
# include "../FontData.hpp"

namespace s3d
{
	class IGlyphCache
	{
	public:

		virtual ~IGlyphCache() = default;

		virtual RectF draw(const FontData& font, StringView s, const Array<GlyphCluster>& clusters, const Vec2& pos, double size, const TextStyle& textStyle, const ColorF& color, double lineHeightScale) = 0;

		virtual bool draw(const FontData& font, StringView s, const Array<GlyphCluster>& clusters, const RectF& area, double size, const TextStyle& textStyle, const ColorF& color, double lineHeightScale) = 0;

		virtual RectF drawBase(const FontData& font, StringView s, const Array<GlyphCluster>& clusters, const Vec2& pos, double size, const TextStyle& textStyle, const ColorF& color, double lineHeightScale) = 0;

		virtual RectF drawFallback(const FontData& font, const GlyphCluster& cluster, const Vec2& pos, const double size, const ColorF& color, double lineHeightScale) = 0;

		virtual RectF drawBaseFallback(const FontData& font, const GlyphCluster& cluster, const Vec2& pos, const double size, const ColorF& color, double lineHeightScale) = 0;
		
		[[nodiscard]]
		virtual Array<double> getXAdvances(const FontData& font, StringView s, const Array<GlyphCluster>& clusters) = 0;

		[[nodiscard]]
		virtual double xAdvanceFallback(const FontData& font, const GlyphCluster& cluster) = 0;

		[[nodiscard]]
		virtual RectF region(const FontData& font, StringView s, const Array<GlyphCluster>& clusters, const Vec2& pos, const double size, double lineHeightScale) = 0;

		[[nodiscard]]
		virtual RectF regionBase(const FontData& font, StringView s, const Array<GlyphCluster>& clusters, const Vec2& pos, const double size, double lineHeightScale) = 0;

		[[nodiscard]]
		virtual RectF regionFallback(const FontData& font, const GlyphCluster& cluster, const Vec2& pos, const double size, double lineHeightScale) = 0;

		[[nodiscard]]
		virtual RectF regionBaseFallback(const FontData& font, const GlyphCluster& clusters, const Vec2& pos, const double size, double lineHeightScale) = 0;

		virtual void setBufferWidth(int32 width) = 0;

		virtual int32 getBufferWidth() const noexcept = 0;

		virtual bool preload(const FontData& font, StringView s) = 0;

		[[nodiscard]]
		virtual const Texture& getTexture() const noexcept = 0;
	};
}
