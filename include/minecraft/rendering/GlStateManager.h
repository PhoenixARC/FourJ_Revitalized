#pragma once

#include <code/code.h>

#include "buffer/BufferedImage.h"

#define MC_GL_ZERO                  0
#define MC_GL_ONE                   1
#define MC_GL_SRC_ALPHA             4
#define MC_GL_ONE_MINUS_SRC_ALPHA   5

#define MC_GL_TRIANGLES             0
#define MC_GL_TRIANGLE_FAN          1
#define MC_GL_QUADS                 2
#define MC_GL_QUADS_STRIP           3
#define MC_GL_LINES                 4
#define MC_GL_LINES_STRIP           5

#define MC_GL_MODELVIEW             0
#define MC_GL_PROJECTION            1
#define MC_GL_TEXTURE               2

namespace mc {
    class GlStateManager {
    public:
        static void disableDepthTest() {
            code::Func<void, 0x030E9B9C>()();
        }

        static void lineWidth(float size) {
            code::Func<void, 0x030e9bfc, float>()(size);
        }

        static void enableDepthTest() {
            code::Func<void, 0x030E9BB8>()();
        }

        static void pushMatrix() {
            code::Func<void, 0x030E4B3C>()();
        }

        static void scalef(float x, float y, float z) {
            code::Func<void, 0x030E4B6C, float, float, float>()(x, y, z);
        }

        static void translatef(float x, float y, float z) {
            code::Func<void, 0x30E4B54, float, float, float>()(x, y, z);
        }

        static void rotatef(float x, float y, float z, float w) {
            code::Func<void, 0x030E4B84, float, float, float, float>()(x, y, z, w);
        }
		
        static void rotate(float rot) {
            code::Func<void, 0x030E4B84, float>()(rot);
        }

        static void popMatrix() {
            code::Func<void, 0x030E4BD8>()();
        }

        static void disableTexture() {
            code::Func<void, 0x030E6268>()();
        }

        static int genTexture() {
            return code::Func<int, 0x03124ef8>()();
        }

        static void enableTexture() {
            code::Func<void, 0x030E6294>()();
        }

        static void depthMask(bool arg1) {
            code::Func<void, 0x030E52FC, bool>()(arg1);
        }

        static void ortho(double arg1, double arg2, double arg3, double arg4, double arg5, double arg6) {
            code::Func<void, 0x3110D4C, double, double, double, double, double, double>()(arg1, arg2, arg3, arg4, arg5, arg6);
        }

        static void matrixMode(uint32_t arg1) {
            code::Func<void, 0x3103064, uint32_t>()(arg1);
        }

        static void loadIdentity() {
            code::Func<void, 0x03103080>()();
        }

        static void disableCull() {
            code::Func<void, 0x030F974C>()();
        }

        static void enableCull() {
            code::Func<void, 0x030f9768>()();
        }

        static void clear(int i) {
            code::Func<void, 0x031078C8, int>()(i);
        }

        static void enableBlend() {
            code::Func<void, 0x30E5284>()();
        }

        static void disableBlend() {
            code::Func<void, 0x030E5328>()();
        }

        static void blendFunc(uint32_t arg1, uint32_t arg2) {
            code::Func<void, 0x30E52A0, uint32_t, uint32_t>()(arg1, arg2);
        }

        static void disableLighting() {
            code::Func<void, 0x030E4B24>()();
        }

        static void color4f(double r, double g, double b, double a) {
            code::Func<void, 0x30E4BA8, double, double, double, double>()(r, g, b, a);
        }

        static void disableFog() {
            code::Func<void, 0x03108C44>()();
        }
        static void enableFog() {
            code::Func<void, 0x03108ba4>()();
        }
        static void disableAlphaTest() {
            code::Func<void, 0x03108e10>()();
        }

        static void enableAlphaTest() {
            code::Func<void, 0x031056BC>()();
        }

        static void activeTexture(uint32_t ImgID) {
            code::Func<void, 0x03124eec, uint32_t>()(ImgID);
        }
		
        static void bindTexture(uint32_t ImgID) {
            code::Func<void, 0x030e4750, uint32_t>()(ImgID);
        }
		
        static void texParameteri(uint32_t x, uint32_t Y) {
            code::Func<void, 0x031216d4, uint32_t, uint32_t>()(x, Y);
        }
        static void blendFuncSeparate(uint32_t x1, uint32_t x2, uint32_t x3, uint32_t x4) {
            code::Func<void, 0x0310B478, uint32_t, uint32_t, uint32_t, uint32_t>()(x1, x2, x3, x4);
        }
        static void shadeModel(uint32_t model) {
            code::Func<void, 0x031251FC, uint32_t>()(model);
        }
    };
}