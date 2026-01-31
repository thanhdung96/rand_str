# Compiler and flags
CXX = g++
DEBUGFLAGS = -Wall -fexceptions -std=c++23 -m64 -g -Iinclude
RELEASEFLAGS = -Wall -fexceptions -O2 -std=c++23 -m64 -Iinclude

# Directories
DEBUGDIR = obj/Debug
RELEASEDIR = obj/Release
BINDEBUGDIR = bin/Debug
BINRELEASEDIR = bin/Release

# Source files
SOURCES = main.cpp \
          src/ErrorTranslator.cpp \
          src/MathHelper.cpp \
          src/RandStr.cpp \
          src/SystemCheck.cpp \
          src/TerminalParser.cpp

# Object files
DEBUGOBJS = $(DEBUGDIR)/main.o \
            $(DEBUGDIR)/src/ErrorTranslator.o \
            $(DEBUGDIR)/src/MathHelper.o \
            $(DEBUGDIR)/src/RandStr.o \
            $(DEBUGDIR)/src/SystemCheck.o \
            $(DEBUGDIR)/src/TerminalParser.o

RELEASEOBJS = $(RELEASEDIR)/main.o \
              $(RELEASEDIR)/src/ErrorTranslator.o \
              $(RELEASEDIR)/src/MathHelper.o \
              $(RELEASEDIR)/src/RandStr.o \
              $(RELEASEDIR)/src/SystemCheck.o \
              $(RELEASEDIR)/src/TerminalParser.o

# Targets
DEBUGTARGET = $(BINDEBUGDIR)/rand_str
RELEASETARGET = $(BINRELEASEDIR)/rand_str

# Default target
.PHONY: all debug release clean
all: debug

# Debug build
debug: $(DEBUGTARGET)

$(DEBUGTARGET): $(DEBUGOBJS) | $(BINDEBUGDIR)
	$(CXX) -o $@ $(DEBUGOBJS)

$(DEBUGDIR)/%.o: %.cpp | $(DEBUGDIR) $(DEBUGDIR)/src
	$(CXX) $(DEBUGFLAGS) -c $< -o $@

# Release build
release: $(RELEASETARGET)

$(RELEASETARGET): $(RELEASEOBJS) | $(BINRELEASEDIR)
	$(CXX) -o $@ $(RELEASEOBJS)

$(RELEASEDIR)/%.o: %.cpp | $(RELEASEDIR) $(RELEASEDIR)/src
	$(CXX) $(RELEASEFLAGS) -c $< -o $@

# Create directories
$(DEBUGDIR):
	mkdir -p $(DEBUGDIR)

$(DEBUGDIR)/src:
	mkdir -p $(DEBUGDIR)/src

$(RELEASEDIR):
	mkdir -p $(RELEASEDIR)

$(RELEASEDIR)/src:
	mkdir -p $(RELEASEDIR)/src

$(BINDEBUGDIR):
	mkdir -p $(BINDEBUGDIR)

$(BINRELEASEDIR):
	mkdir -p $(BINRELEASEDIR)

# Clean
clean:
	rm -rf obj bin

# Install (optional - copies to /usr/local/bin)
.PHONY: install
install: release
	sudo cp $(RELEASETARGET) /usr/local/bin/rand_str

# Uninstall (optional - removes from /usr/local/bin)
.PHONY: uninstall
uninstall:
	sudo rm -f /usr/local/bin/rand_str

# Help
.PHONY: help
help:
	@echo "Available targets:"
	@echo "  all      - Build debug version (default)"
	@echo "  debug    - Build debug version"
	@echo "  release  - Build optimized release version"
	@echo "  clean    - Remove build directories"
	@echo "  install  - Install release binary to /usr/local/bin"
	@echo "  uninstall- Remove binary from /usr/local/bin"
	@echo "  help     - Show this help message"