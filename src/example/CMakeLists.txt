cmake_minimum_required(VERSION 3.20)
project(MyQtProject LANGUAGES CXX)

# Включаем магию Qt (MOC, UIC, RCC)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Стандарт C++20 для нашего God Object
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ищем Qt 6
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# --- ВАЖНО: Список исходников ---
# Если parser.cpp лежит в соседней папке, укажи к нему путь прямо здесь!
# Например: ../parser/sd/parser.cpp
set(SOURCES
    main.cpp
    RenderWindow.cpp
    ../../parser/sd/parser.cpp
)

# 1. Создаем исполняемый файл (называем его так же как проект для удобства)
add_executable(${PROJECT_NAME} ${SOURCES})

# 2. Теперь привязываем пути к хедерам в смежной папке
# Используем PRIVATE, чтобы настройки касались только нашего проекта
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../parser/sd")

# 3. Линкуем библиотеки Qt
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)

# Если у тебя Windows, эта строчка уберет консоль при запуске (чисто для красоты)
set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)