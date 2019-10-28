project('cube2equirect', 'cpp', 'c')

opengl = dependency('GL')
sdl = dependency('SDL2')
sdl_image = dependency('SDL2_image')
png = dependency('libpng')
jpeg = dependency('libjpeg')
#xorg = dependency('x11')
#xrandr = dependency('xrandr')
#xi = dependency('xi')
#thread = dependency('threads')

incdir = include_directories('include')
glad_dep = declare_dependency(sources: ['include/glad.c', 'include/glad.h', 'include/khrplatform.h'], link_args: ['-ldl'])

deplist = [opengl, sdl, sdl_image, png, jpeg, glad_dep]


executable('cube2equirect', 'src/main.cpp', 'src/cube2equirect.cpp', dependencies: deplist, link_args: ['-ldl'], include_directories: incdir)