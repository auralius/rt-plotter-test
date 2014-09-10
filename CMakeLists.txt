project(rt-plotter-test)

add_executable(rt-plotter-test main.cpp shm-access.cpp)

install(TARGETS rt-plotter-test RUNTIME DESTINATION bin)
