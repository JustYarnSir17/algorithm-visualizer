cmake_minimum_required(VERSION 3.10)

project(AlgorithmVisualizer)

set(CMAKE_CXX_STANDARD 17)

# SFML 경로 설정
set(SFML_DIR "C:/Users/Admin/Desktop/prj/algorithm-visualizer/algorithm-visualizer/include/SFML-2.6.1/lib/cmake/SFML")
set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};${SFML_DIR}")

# SFML 패키지 찾기
find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

# 실행 파일 추가
add_executable(AlgorithmVisualizer algorithm-visualizer/main.cpp algorithm-visualizer/AlgorithmVisualizer.cpp)

# 포함 디렉토리 설정
target_include_directories(AlgorithmVisualizer PRIVATE include)

# SFML 라이브러리 연결
target_link_libraries(AlgorithmVisualizer sfml-graphics sfml-window sfml-system)
