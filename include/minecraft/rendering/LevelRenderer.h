#pragma once

#include <code/code.h>


namespace mc {
    class LevelRenderer {
	private:
	
    public:
        void renderDebugWireframeVolume(const mc_boost::shared_ptr<mc::Entity>& entity, const mstd::wstring& string, const mc::AABB* _aabb, uint32_t Colour, bool Subdivide = true, bool RotateText = true, bool useThickerLines = true, bool fixTextPosition = true) {
            code::Func<void, 0x031C5A70, const mc_boost::shared_ptr<mc::Entity>&, const mstd::wstring&, const mc::AABB*, uint32_t, bool, bool, bool, bool>()(entity, string, _aabb, Colour, Subdivide, RotateText, useThickerLines, fixTextPosition);
        }
        void renderDebugVolume(const mc_boost::shared_ptr<mc::Entity>& entity, const mstd::wstring& string, const mc::AABB* _aabb, uint32_t Colour, bool Subdivide = true, bool RotateText = true, bool useThickerLines = true, bool fixTextPosition = true) {
            code::Func<void, 0x031C4D80, const mc_boost::shared_ptr<mc::Entity>&, const mstd::wstring&, const mc::AABB*, uint32_t, bool, bool, bool, bool>()(entity, string, _aabb, Colour, Subdivide, RotateText, useThickerLines, fixTextPosition);
        }
        void renderFancyTextDebugVolume(const mc_boost::shared_ptr<mc::Entity>& entity, const mstd::wstring& string, const mc::AABB* _aabb, uint32_t Colour, bool Subdivide = true, bool RotateText = true, bool useThickerLines = true, bool fixTextPosition = true) {
            code::Func<void, 0x031C502C, const mc_boost::shared_ptr<mc::Entity>&, const mstd::wstring&, const mc::AABB*, uint32_t, bool, bool, bool, bool>()(entity, string, _aabb, Colour, Subdivide, RotateText, useThickerLines, fixTextPosition);
        }
        void renderStringInWorld(const mc_boost::shared_ptr<mc::Entity>& entity, const mstd::wstring& string, const mc::Vec3* _vec3) {
            code::Func<void, 0x031C4734, const mc_boost::shared_ptr<mc::Entity>&, const mstd::wstring&, const mc::Vec3*>()(entity, string, _vec3);
        }
        void renderStringOnPlane(const mc_boost::shared_ptr<mc::Entity>& entity, const mstd::wstring& string, const mc::Vec3* _vec3, const mc::Vec3* _vec32) {
            code::Func<void, 0x031C4B4C, const mc_boost::shared_ptr<mc::Entity>&, const mstd::wstring&, const mc::Vec3*, const mc::Vec3*>()(entity, string, _vec3, _vec32);
        }
        static void renderColoredLineBox(const mc::AABB* _aabb, uint32_t RGBA, bool Flag) {
            code::Func<void, 0x031C34D0, const mc::AABB*, uint32_t, bool>()(_aabb, RGBA, Flag);
        }
		
        void reloadAll() {
            code::Func<void, 0x031b5fcc, LevelRenderer*>()(this);
        }
        void reloadAll(uint32_t i) {
            code::Func<void, 0x0318E624, LevelRenderer*, uint32_t>()(this, i);
        }
		
		
		uint32_t field_0x0[50];
    };
}