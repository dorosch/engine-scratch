CXX = g++
INCLUDE = -I include
LDFLAGS = -fPIC -shared -lSDL2 -lSDL2main
CXXFLAGS = -Wall -Wextra -Werror -pedantic $(INCLUDE) $(LDFLAGS)
OBJECTS=src/engine.o src/window.o src/render.o src/io.o src/primitive.o src/model.o src/math.o src/math/vector.o
TARGET_DIR=lib
TARGET=$(TARGET_DIR)/libengine.so


$(TARGET): directories $(OBJECTS)
	$(CXX) $(OBJECTS) $(CXXFLAGS) -o $(TARGET)

directories:
	@mkdir -p lib

clean:
	@rm -rf $(TARGET_DIR) src/*.o
