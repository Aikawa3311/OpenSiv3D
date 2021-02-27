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
# include "Common.hpp"
# include "PointVector.hpp"
# include "ColorHSV.hpp"
# include "NamedParameter.hpp"
# include "PredefinedNamedParameter.hpp"
# include "PredefinedYesNo.hpp"

namespace s3d
{
	class Texture;
	struct TextureRegion;
	struct TexturedQuad;

	/// @brief 長方形 (int32)
	///
	///  pos, tl()    top()     tr()
	///        +-----------------+
	///        |                 |
	/// left() |                 | right()
	///		   |                 |
	///        +-----------------+
	///       bl()   bottom()   br() 
	/// 
	struct Rect
	{
		using position_type = Point;

		using size_type		= Point;

		using value_type	= typename size_type::value_type;

	SIV3D_DISABLE_MSVC_WARNINGS_PUSH(4201)

		union
		{
			/// @brief 長方形の左上の点の位置
			position_type pos;

			struct
			{
				/// @brief 長方形の左上の点の X 座標
				value_type x;

				/// @brief 長方形の左上の点の Y 座標
				value_type y;
			};
		};

		union
		{
			/// @brief 長方形のサイズ
			size_type size;

			struct
			{
				/// @brief 長方形の幅
				value_type w;

				/// @brief 長方形の高さ
				value_type h;
			};
		};

	SIV3D_DISABLE_MSVC_WARNINGS_POP()

		SIV3D_NODISCARD_CXX20
		Rect() = default;

		/// @brief 長方形を作成します。
		/// @param _size 長方形の幅と高さ
		SIV3D_NODISCARD_CXX20
		explicit constexpr Rect(value_type _size) noexcept;

		SIV3D_CONCEPT_INTEGRAL
		SIV3D_NODISCARD_CXX20
		explicit constexpr Rect(Int _r) noexcept;

		/// @brief 長方形を作成します。
		/// @param _w 長方形の幅
		/// @param _h 長方形の高さ
		SIV3D_NODISCARD_CXX20
		constexpr Rect(value_type _w, value_type _h) noexcept;

	# if __cpp_lib_concepts
		template <Concept::Integral W, Concept::Integral H>
	# else
		template <class W, class H, std::enable_if_t<std::conjunction_v<std::is_integral<W>, std::is_integral<H>>>* = nullptr>
	# endif
		SIV3D_NODISCARD_CXX20
		explicit constexpr Rect(W _w, H _h) noexcept;

		/// @brief 長方形を作成します。
		/// @param _size 長方形の大きさ
		SIV3D_NODISCARD_CXX20
		explicit constexpr Rect(size_type _size) noexcept;

		/// @brief 長方形を作成します。
		/// @param _x 長方形の左上の点の X 座標
		/// @param _y 長方形の左上の点の Y 座標
		/// @param _size 長方形の縦横の大きさ
		SIV3D_NODISCARD_CXX20
		constexpr Rect(value_type _x, value_type _y, value_type _size) noexcept;

	# if __cpp_lib_concepts
		template <Concept::Integral X, Concept::Integral Y, Concept::Integral S>
	# else
		template <class X, class Y, class S, std::enable_if_t<std::conjunction_v<std::is_integral<X>, std::is_integral<Y>, std::is_integral<S>>>* = nullptr>
	# endif
		SIV3D_NODISCARD_CXX20
		constexpr Rect(X _x, Y _y, S _size) noexcept;

		/// @brief 長方形を作成します。
		/// @param _x 長方形の左上の点の X 座標
		/// @param _y 長方形の左上の点の Y 座標
		/// @param _w 長方形の幅
		/// @param _h 	長方形の高さ
		SIV3D_NODISCARD_CXX20
		constexpr Rect(value_type _x, value_type _y, value_type _w, value_type _h) noexcept;

	# if __cpp_lib_concepts
		template <Concept::Integral X, Concept::Integral Y, Concept::Integral W, Concept::Integral H>
	# else
		template <class X, class Y, class W, class H, std::enable_if_t<std::conjunction_v<std::is_integral<X>, std::is_integral<Y>, std::is_integral<W>, std::is_integral<H>>>* = nullptr>
	# endif
		SIV3D_NODISCARD_CXX20
		constexpr Rect(X _x, Y _y, W _w, H _h) noexcept;

		/// @brief 長方形を作成します。
		/// @param _x 長方形の左上の点の X 座標
		/// @param _y 長方形の左上の点の Y 座標
		/// @param _size 長方形の大きさ
		SIV3D_NODISCARD_CXX20
		constexpr Rect(value_type _x, value_type _y, size_type _size) noexcept;

	# if __cpp_lib_concepts
		template <Concept::Integral X, Concept::Integral Y>
	# else
		template <class X, class Y, std::enable_if_t<std::conjunction_v<std::is_integral<X>, std::is_integral<Y>>>* = nullptr>
	# endif
		SIV3D_NODISCARD_CXX20
		constexpr Rect(X _x, Y _y, size_type _size) noexcept;

		/// @brief 長方形を作成します。
		/// @param _pos 長方形の左上の点の座標
		/// @param _size 長方形の大きさ
		SIV3D_NODISCARD_CXX20
		constexpr Rect(position_type _pos, value_type _size) noexcept;

		SIV3D_CONCEPT_INTEGRAL
		SIV3D_NODISCARD_CXX20
		constexpr Rect(position_type _pos, Int _size) noexcept;

		/// @brief 長方形を作成します。
		/// @param _pos 長方形の左上の点の座標
		/// @param _w 長方形の幅
		/// @param _h 長方形の高さ
		SIV3D_NODISCARD_CXX20
		constexpr Rect(position_type _pos, value_type _w, value_type _h) noexcept;

	# if __cpp_lib_concepts
		template <Concept::Integral W, Concept::Integral H>
	# else
		template <class W, class H, std::enable_if_t<std::conjunction_v<std::is_integral<W>, std::is_integral<H>>>* = nullptr>
	# endif
		SIV3D_NODISCARD_CXX20
		constexpr Rect(position_type _pos, W _w, H _h) noexcept;

		/// @brief 長方形を作成します。
		/// @param _pos 長方形の左上の点の座標
		/// @param _size 	長方形の大きさ
		SIV3D_NODISCARD_CXX20
		constexpr Rect(position_type _pos, size_type _size) noexcept;

		/// @brief 
		/// @param _center 
		/// @param _size 
		SIV3D_NODISCARD_CXX20
		constexpr Rect(Arg::center_<position_type> _center, value_type _size) noexcept;

		/// @brief 
		/// @param _center 
		/// @param _w 
		/// @param _h 
		SIV3D_NODISCARD_CXX20
		constexpr Rect(Arg::center_<position_type> _center, value_type _w, value_type _h) noexcept;

		/// @brief 
		/// @param _center 
		/// @param _size 
		SIV3D_NODISCARD_CXX20
		constexpr Rect(Arg::center_<position_type> _center, size_type _size) noexcept;

		/// @brief 
		/// @param topLeft 
		/// @param _size 
		SIV3D_NODISCARD_CXX20
		constexpr Rect(Arg::topLeft_<position_type> topLeft, value_type _size) noexcept;

		/// @brief 
		/// @param topLeft 
		/// @param _w 
		/// @param _h 
		SIV3D_NODISCARD_CXX20
		constexpr Rect(Arg::topLeft_<position_type> topLeft, value_type _w, value_type _h) noexcept;

		/// @brief 
		/// @param topLeft 
		/// @param _size 
		SIV3D_NODISCARD_CXX20
		constexpr Rect(Arg::topLeft_<position_type> topLeft, size_type _size) noexcept;

		/// @brief 
		/// @param _center 
		/// @param _size 
		SIV3D_NODISCARD_CXX20
		constexpr Rect(Arg::topCenter_<position_type> _center, value_type _size) noexcept;

		/// @brief 
		/// @param _center 
		/// @param _w 
		/// @param _h 
		SIV3D_NODISCARD_CXX20
		constexpr Rect(Arg::topCenter_<position_type> _center, value_type _w, value_type _h) noexcept;

		/// @brief 
		/// @param _center 
		/// @param _size 
		SIV3D_NODISCARD_CXX20
		constexpr Rect(Arg::topCenter_<position_type> _center, size_type _size) noexcept;

		/// @brief 
		/// @param topLeft 
		/// @param _size 
		SIV3D_NODISCARD_CXX20
		constexpr Rect(Arg::topRight_<position_type> topLeft, value_type _size) noexcept;

		/// @brief 
		/// @param topLeft 
		/// @param _w 
		/// @param _h 
		SIV3D_NODISCARD_CXX20
		constexpr Rect(Arg::topRight_<position_type> topLeft, value_type _w, value_type _h) noexcept;

		/// @brief 
		/// @param topLeft 
		/// @param _size 
		SIV3D_NODISCARD_CXX20
		constexpr Rect(Arg::topRight_<position_type> topLeft, size_type _size) noexcept;

		/// @brief 
		/// @param _center 
		/// @param _size 
		SIV3D_NODISCARD_CXX20
		constexpr Rect(Arg::rightCenter_<position_type> _center, value_type _size) noexcept;

		/// @brief 
		/// @param _center 
		/// @param _w 
		/// @param _h 
		SIV3D_NODISCARD_CXX20
		constexpr Rect(Arg::rightCenter_<position_type> _center, value_type _w, value_type _h) noexcept;

		/// @brief 
		/// @param _center 
		/// @param _size 
		SIV3D_NODISCARD_CXX20
		constexpr Rect(Arg::rightCenter_<position_type> _center, size_type _size) noexcept;

		/// @brief 
		/// @param topLeft 
		/// @param _size 
		SIV3D_NODISCARD_CXX20
		constexpr Rect(Arg::bottomRight_<position_type> topLeft, value_type _size) noexcept;

		/// @brief 
		/// @param topLeft 
		/// @param _w 
		/// @param _h 
		SIV3D_NODISCARD_CXX20
		constexpr Rect(Arg::bottomRight_<position_type> topLeft, value_type _w, value_type _h) noexcept;

		/// @brief 
		/// @param topLeft 
		/// @param _size 
		SIV3D_NODISCARD_CXX20
		constexpr Rect(Arg::bottomRight_<position_type> topLeft, size_type _size) noexcept;

		/// @brief 
		/// @param _center 
		/// @param _size 
		SIV3D_NODISCARD_CXX20
		constexpr Rect(Arg::bottomCenter_<position_type> _center, value_type _size) noexcept;

		/// @brief 
		/// @param _center 
		/// @param _w 
		/// @param _h 
		SIV3D_NODISCARD_CXX20
		constexpr Rect(Arg::bottomCenter_<position_type> _center, value_type _w, value_type _h) noexcept;

		/// @brief 
		/// @param _center 
		/// @param _size 
		SIV3D_NODISCARD_CXX20
		constexpr Rect(Arg::bottomCenter_<position_type> _center, size_type _size) noexcept;

		/// @brief 
		/// @param topLeft 
		/// @param _size 
		SIV3D_NODISCARD_CXX20
		constexpr Rect(Arg::bottomLeft_<position_type> topLeft, value_type _size) noexcept;

		/// @brief 
		/// @param topLeft 
		/// @param _w 
		/// @param _h 
		SIV3D_NODISCARD_CXX20
		constexpr Rect(Arg::bottomLeft_<position_type> topLeft, value_type _w, value_type _h) noexcept;

		/// @brief 
		/// @param topLeft 
		/// @param _size 
		SIV3D_NODISCARD_CXX20
		constexpr Rect(Arg::bottomLeft_<position_type> topLeft, size_type _size) noexcept;

		/// @brief 
		/// @param _center 
		/// @param _size 
		SIV3D_NODISCARD_CXX20
		constexpr Rect(Arg::leftCenter_<position_type> _center, value_type _size) noexcept;

		/// @brief 
		/// @param _center 
		/// @param _w 
		/// @param _h 
		SIV3D_NODISCARD_CXX20
		constexpr Rect(Arg::leftCenter_<position_type> _center, value_type _w, value_type _h) noexcept;

		/// @brief 
		/// @param _center 
		/// @param _size 
		SIV3D_NODISCARD_CXX20
		constexpr Rect(Arg::leftCenter_<position_type> _center, size_type _size) noexcept;

		[[nodiscard]]
		friend constexpr bool operator ==(const Rect& lhs, const Rect& rhs) noexcept
		{
			return (lhs.pos == rhs.pos)
				&& (lhs.size == rhs.size);
		}

		[[nodiscard]]
		friend constexpr bool operator !=(const Rect& lhs, const Rect& rhs) noexcept
		{
			return (lhs.pos != rhs.pos)
				|| (lhs.size != rhs.size);
		}


		constexpr Rect& setPos(value_type _x, value_type _y) noexcept;

		constexpr Rect& setPos(position_type _pos) noexcept;

		constexpr Rect& setPos(Arg::center_<position_type> _center) noexcept;

		constexpr Rect& setPos(Arg::topLeft_<position_type> topLeft) noexcept;

		constexpr Rect& setPos(Arg::topCenter_<position_type> topCenter) noexcept;

		constexpr Rect& setPos(Arg::topRight_<position_type> topRight) noexcept;

		constexpr Rect& setPos(Arg::rightCenter_<position_type> rightCenter) noexcept;

		constexpr Rect& setPos(Arg::bottomRight_<position_type> bottomRight) noexcept;

		constexpr Rect& setPos(Arg::bottomCenter_<position_type> bottomCenter) noexcept;

		constexpr Rect& setPos(Arg::bottomLeft_<position_type> bottomLeft) noexcept;

		constexpr Rect& setPos(Arg::leftCenter_<position_type> leftCenter) noexcept;

		constexpr Rect& setCenter(value_type _x, value_type _y) noexcept;

		constexpr Rect& setCenter(position_type _pos) noexcept;

		constexpr Rect& setSize(value_type _size) noexcept;

		constexpr Rect& setSize(value_type _w, value_type _h) noexcept;

		constexpr Rect& setSize(size_type _size) noexcept;

		constexpr Rect& set(value_type _x, value_type _y, value_type _w, value_type _h) noexcept;

		constexpr Rect& set(value_type _x, value_type _y, value_type _size) noexcept;

		constexpr Rect& set(value_type _x, value_type _y, size_type _size) noexcept;

		constexpr Rect& set(position_type _pos, value_type _size) noexcept;

		constexpr Rect& set(position_type _pos, value_type _w, value_type _h) noexcept;

		constexpr Rect& set(position_type _pos, size_type _size) noexcept;

		constexpr Rect& set(const Rect& r) noexcept;

		constexpr Rect& set(Arg::center_<position_type> _center, value_type _size) noexcept;

		constexpr Rect& set(Arg::center_<position_type> _center, value_type _w, value_type _h) noexcept;

		constexpr Rect& set(Arg::center_<position_type> _center, size_type _size) noexcept;

		constexpr Rect& set(Arg::topLeft_<position_type> topLeft, value_type _size) noexcept;

		constexpr Rect& set(Arg::topLeft_<position_type> topLeft, value_type _w, value_type _h) noexcept;

		constexpr Rect& set(Arg::topLeft_<position_type> topLeft, size_type _size) noexcept;

		constexpr Rect& set(Arg::topCenter_<position_type> topCenter, value_type _size) noexcept;

		constexpr Rect& set(Arg::topCenter_<position_type> topCenter, value_type _w, value_type _h) noexcept;

		constexpr Rect& set(Arg::topCenter_<position_type> topCenter, size_type _size) noexcept;

		constexpr Rect& set(Arg::topRight_<position_type> topRight, value_type _size) noexcept;

		constexpr Rect& set(Arg::topRight_<position_type> topRight, value_type _w, value_type _h) noexcept;

		constexpr Rect& set(Arg::topRight_<position_type> topRight, size_type _size) noexcept;

		constexpr Rect& set(Arg::rightCenter_<position_type> rightCenter, value_type _size) noexcept;

		constexpr Rect& set(Arg::rightCenter_<position_type> rightCenter, value_type _w, value_type _h) noexcept;

		constexpr Rect& set(Arg::rightCenter_<position_type> rightCenter, size_type _size) noexcept;

		constexpr Rect& set(Arg::bottomRight_<position_type> bottomRight, value_type _size) noexcept;

		constexpr Rect& set(Arg::bottomRight_<position_type> bottomRight, value_type _w, value_type _h) noexcept;

		constexpr Rect& set(Arg::bottomRight_<position_type> bottomRight, size_type _size) noexcept;

		constexpr Rect& set(Arg::bottomCenter_<position_type> bottomCenter, value_type _size) noexcept;

		constexpr Rect& set(Arg::bottomCenter_<position_type> bottomCenter, value_type _w, value_type _h) noexcept;

		constexpr Rect& set(Arg::bottomCenter_<position_type> bottomCenter, size_type _size) noexcept;

		constexpr Rect& set(Arg::bottomLeft_<position_type> bottomLeft, value_type _size) noexcept;

		constexpr Rect& set(Arg::bottomLeft_<position_type> bottomLeft, value_type _w, value_type _h) noexcept;

		constexpr Rect& set(Arg::bottomLeft_<position_type> bottomLeft, size_type _size) noexcept;

		constexpr Rect& set(Arg::leftCenter_<position_type> leftCenter, value_type _size) noexcept;

		constexpr Rect& set(Arg::leftCenter_<position_type> leftCenter, value_type _w, value_type _h) noexcept;

		constexpr Rect& set(Arg::leftCenter_<position_type> leftCenter, size_type _size) noexcept;

		[[nodiscard]]
		constexpr Rect movedBy(value_type _x, value_type _y) const noexcept;

		[[nodiscard]]
		constexpr Rect movedBy(size_type v) const noexcept;

		constexpr Rect& moveBy(value_type _x, value_type _y) noexcept;

		constexpr Rect& moveBy(size_type v) noexcept;

		[[nodiscard]]
		constexpr Rect stretched(value_type xy) const noexcept;

		[[nodiscard]]
		constexpr Rect stretched(value_type _x, value_type _y) const noexcept;

		[[nodiscard]]
		constexpr Rect stretched(size_type xy) const noexcept;

		[[nodiscard]]
		constexpr Rect stretched(value_type top, value_type right, value_type bottom, value_type left) const noexcept;

		[[nodiscard]]
		constexpr RectF scaled(double s) const noexcept;

		[[nodiscard]]
		constexpr RectF scaled(double sx, double sy) const noexcept;

		[[nodiscard]]
		constexpr RectF scaled(Vec2 s) const noexcept;

		[[nodiscard]]
		constexpr RectF scaledAt(double _x, double _y, double s) const noexcept;

		[[nodiscard]]
		constexpr RectF scaledAt(double _x, double _y, double sx, double sy) const noexcept;

		[[nodiscard]]
		constexpr RectF scaledAt(double _x, double _y, Vec2 s) const noexcept;

		[[nodiscard]]
		constexpr RectF scaledAt(Vec2 _pos, double s) const noexcept;

		[[nodiscard]]
		constexpr RectF scaledAt(Vec2 _pos, double sx, double sy) const noexcept;

		[[nodiscard]]
		constexpr RectF scaledAt(Vec2 _pos, Vec2 s) const noexcept;

		[[nodiscard]]
		constexpr bool hasArea() const noexcept;

		[[nodiscard]]
		constexpr size_type tl() const noexcept;

		[[nodiscard]]
		constexpr size_type tr() const noexcept;

		[[nodiscard]]
		constexpr size_type bl() const noexcept;

		[[nodiscard]]
		constexpr size_type br() const noexcept;

		[[nodiscard]]
		constexpr Vec2 topCenter() const noexcept;

		[[nodiscard]]
		constexpr Vec2 bottomCenter() const noexcept;

		[[nodiscard]]
		constexpr Vec2 leftCenter() const noexcept;

		[[nodiscard]]
		constexpr Vec2 rightCenter() const noexcept;

		[[nodiscard]]
		constexpr Vec2 center() const noexcept;

		[[nodiscard]]
		constexpr Line top() const noexcept;

		[[nodiscard]]
		constexpr Line right() const noexcept;

		[[nodiscard]]
		constexpr Line bottom() const noexcept;

		[[nodiscard]]
		constexpr Line left() const noexcept;

		[[nodiscard]]
		constexpr position_type point(size_t index) const;

		[[nodiscard]]
		constexpr Line side(size_t index) const;

		[[nodiscard]]
		constexpr Triangle triangle(size_t index) const;

		/// @brief 長方形の面積を返します。
		/// @return 長方形の面積
		[[nodiscard]]
		constexpr value_type area() const noexcept;

		/// @brief 長方形の周の長さを返します。
		/// @return 長方形の周の長さ
		[[nodiscard]]
		constexpr value_type perimeter() const noexcept;

		[[nodiscard]]
		Quad rotated(double angle) const noexcept;

		[[nodiscard]]
		Quad rotatedAt(double _x, double _y, double angle) const noexcept;

		[[nodiscard]]
		Quad rotatedAt(Vec2 _pos, double angle) const noexcept;

		[[nodiscard]]
		constexpr Quad shearedX(double vx) const noexcept;

		[[nodiscard]]
		constexpr Quad shearedY(double vy) const noexcept;

		[[nodiscard]]
		constexpr RoundRect rounded(double r) const noexcept;

		[[nodiscard]]
		Polygon rounded(double tl, double tr, double br, double bl) const noexcept;

		[[nodiscard]]
		constexpr Quad asQuad() const noexcept;

		[[nodiscard]]
		LineString outline(CloseRing closeRing = CloseRing::No) const;

		[[nodiscard]]
		LineString outline(double distanceFromOrigin, double length) const;

		[[nodiscard]]
		Polygon asPolygon() const;

		[[nodiscard]]
		constexpr RectF lerp(const Rect& other, double f) const noexcept;

		[[nodiscard]]
		constexpr RectF lerp(const RectF& other, double f) const noexcept;

		[[nodiscard]]
		size_t hash() const noexcept;

		template <class Shape2DType>
		[[nodiscard]]
		constexpr bool intersects(const Shape2DType& other) const;

		template <class Shape2DType>
		[[nodiscard]]
		Optional<Array<Vec2>> intersectsAt(const Shape2DType& other) const;

		template <class Shape2DType>
		[[nodiscard]]
		bool contains(const Shape2DType& other) const;

		[[nodiscard]]
		bool leftClicked() const noexcept;

		[[nodiscard]]
		bool leftPressed() const noexcept;

		[[nodiscard]]
		bool leftReleased() const noexcept;

		[[nodiscard]]
		bool rightClicked() const noexcept;

		[[nodiscard]]
		bool rightPressed() const noexcept;

		[[nodiscard]]
		bool rightReleased() const noexcept;

		[[nodiscard]]
		bool mouseOver() const noexcept;

		//const Rect& paint(Image& dst, const Color& color) const;

		//const Rect& overwrite(Image& dst, const Color& color) const;

		//const Rect& paintFrame(Image& dst, int32 innerThickness, int32 outerThickness, const Color& color) const;

		//const Rect& overwriteFrame(Image& dst, int32 innerThickness, int32 outerThickness, const Color& color) const;

		const Rect& draw(const ColorF& color = Palette::White) const;

		const Rect& draw(const ColorF(&colors)[4]) const;

		const Rect& draw(Arg::top_<ColorF> topColor, Arg::bottom_<ColorF> bottomColor) const;

		const Rect& draw(Arg::left_<ColorF> leftColor, Arg::right_<ColorF> rightColor) const;

		const Rect& drawFrame(double thickness = 1.0, const ColorF& color = Palette::White) const;

		const Rect& drawFrame(double thickness, const ColorF& innerColor, const ColorF& outerColor) const;

		const Rect& drawFrame(double innerThickness, double outerThickness, const ColorF& color = Palette::White) const;

		const Rect& drawFrame(double innerThickness, double outerThickness, const ColorF& innerColor, const ColorF& outerColor) const;

		const Rect& drawShadow(const Vec2& offset, double blurRadius, double spread = 0.0, const ColorF& color = ColorF{ 0.0, 0.5 }) const;

		[[nodiscard]]
		TexturedQuad operator ()(const Texture& texture) const;

		[[nodiscard]]
		TexturedQuad operator ()(const TextureRegion& textureRegion) const;

		template <class CharType>
		friend std::basic_ostream<CharType>& operator <<(std::basic_ostream<CharType>& output, const Rect& value)
		{
			return output << CharType('(')
				<< value.x << CharType(',') << CharType(' ')
				<< value.y << CharType(',') << CharType(' ')
				<< value.w << CharType(',') << CharType(' ')
				<< value.h << CharType(')');
		}

		template <class CharType>
		friend std::basic_istream<CharType>& operator >>(std::basic_istream<CharType>& input, Rect& value)
		{
			CharType unused;
			return input >> unused
				>> value.x >> unused
				>> value.y >> unused
				>> value.w >> unused
				>> value.h >> unused;
		}

		friend void Formatter(FormatData& formatData, const Rect& value)
		{
			_Formatter(formatData, value);
		}

		static void _Formatter(FormatData& formatData, const Rect& value);
	};
}

template <>
struct SIV3D_HIDDEN fmt::formatter<s3d::Rect, s3d::char32>
{
	std::u32string tag;

	auto parse(basic_format_parse_context<s3d::char32>& ctx)
	{
		return s3d::detail::GetFormatTag(tag, ctx);
	}

	template <class FormatContext>
	auto format(const s3d::Rect& value, FormatContext& ctx)
	{
		if (tag.empty())
		{
			return format_to(ctx.out(), U"({}, {}, {}, {})", value.x, value.y, value.w, value.h);
		}
		else
		{
			const std::u32string format
				= (U"({:" + tag + U"}, {:" + tag + U"}, {:" + tag + U"}, {:" + tag + U"})");
			return format_to(ctx.out(), format, value.x, value.y, value.w, value.h);
		}
	}
};

template <>
struct std::hash<s3d::Rect>
{
	[[nodiscard]]
	size_t operator()(const s3d::Rect& value) const noexcept
	{
		return value.hash();
	}
};
