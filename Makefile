
CXX = g++
CXXFLAGS = -std=c++17 -g -Wall -I . -I src/app/encryptDecrypt -I src/app/fileHandling -I src/app/processes

MAIN_TARGET = encrypt_decrypt
CRYPTION_TARGET = cryption

MAIN_SRC = main.cpp \
           src/app/processes/processManagement.cpp \
           src/app/fileHandling/IO.cpp \
           src/app/fileHandling/read_env.cpp \
           src/app/encryptDecrypt/encryption.cpp

CRYPTION_SRC = src/app/encryptDecrypt/encryptionMain.cpp \
               src/app/encryptDecrypt/encryption.cpp \
               src/app/fileHandling/IO.cpp \
               src/app/fileHandling/read_env.cpp

MAIN_OBJ = $(MAIN_SRC:.cpp=.o)
CRYPTION_OBJ = $(CRYPTION_SRC:.cpp=.o)

all: $(MAIN_TARGET) $(CRYPTION_TARGET)

$(MAIN_TARGET): $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(CRYPTION_TARGET): $(CRYPTION_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(MAIN_OBJ) $(CRYPTION_OBJ) $(MAIN_TARGET) $(CRYPTION_TARGET)

.PHONY: clean all
