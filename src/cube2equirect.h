#ifndef CUBE2EQUIRECT_H
#define CUBE2EQUIRECT_H
#include <string>
#include <sys/stat.h>
#include <SDL.h>
#include <SDL_image.h>
#include <jpeglib.h>
#include <png.h>
#include "glad.h"

class cube2equirect {
private:
    SDL_Window *mainwindow;

    GLuint vertexArrayObject;
    GLuint vertexPositionBuffer;
    GLuint vertexTextureBuffer;
    GLuint vertexIndexBuffer;

    GLuint equirectFramebuffer;
    GLuint equirectTexture;

    GLuint cubeTextures[6];

    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint shaderProgram;
    GLint vertexPositionAttribute;
    GLint vertexTextureAttribute;

    GLint cubeLeftUniform;
    GLint cubeRightUniform;
    GLint cubeBottomUniform;
    GLint cubeTopUniform;
    GLint cubeBackUniform;
    GLint cubeFrontUniform;

    int frameCount;
    char frameIdx[7];
    std::string cubemapDir;
    std::string equirectDir;
    std::string imgExt;
    std::string outExt;
    std::string exePath;

    GLint equirectW;
    GLint equirectH;
    GLubyte *equirectPixels;

public:
    cube2equirect(SDL_Window *win, std::string exe);
    bool initGL(std::string inDir, std::string outDir, int outRes, std::string outFmt);
    void render();
    bool hasMoreFrames();
    void initBuffers();
    void initRenderToTexture();
    void initCubeTextures();
    void deinitGL();
    void updateCubeTextures();
    bool initShaders(std::string name);
    GLuint compileShader(std::string source, GLint type);
    void createShaderProgram(std::string name, GLint vertexShader, GLint fragmentShader);
    std::string readFile(std::string filename);
    void loadImage(std::string filename, GLuint texture, bool firstTime);
    bool saveImageJPEG(std::string filename, GLubyte *pixels, int width, int height);
    bool saveImagePNG(std::string filename, GLubyte *pixels, int width, int height);
};

#endif //CUBE2EQUIRECT_H
