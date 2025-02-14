# Compilador
CXX = g++

# Opções de compilação
CXXFLAGS = -Wall -Wextra -std=c++11

# Nome do executável
TARGET = lista_sequencial

# Arquivos fonte
SRCS = main.cpp

# Arquivos objeto (gerados a partir dos arquivos fonte)
OBJS = $(SRCS:.cpp=.o)

# Regra padrão
all: $(TARGET)

# Regra para compilar o executável
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regra para compilar cada arquivo fonte em um arquivo objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para limpar os arquivos gerados
clean:
	rm -f $(OBJS) $(TARGET)

# Regra para recompilar tudo
rebuild: clean all