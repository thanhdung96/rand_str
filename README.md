# RandStr

A C++ random string generator application with advanced configuration options.

## Compilation

### Using Make (Recommended)

The project includes a Makefile for easy compilation:

```bash
# Build debug version (default)
make

# Or explicitly:
make debug

# Build optimized release version
make release

# Clean build artifacts
make clean

# Install release binary to system (requires sudo)
make install

# Uninstall from system
make uninstall

# Show help
make help
```

### Using Ninja

If you prefer using Ninja (original build system):

```bash
# Build debug version (default)
ninja

# Build release version
ninja release

# Clean build artifacts
ninja -t clean
```

## Build Outputs

- **Debug build**: `bin/Debug/rand_str`
- **Release build**: `bin/Release/rand_str`

## Requirements

- GCC with C++23 support
- Make or Ninja build system
- Linux/Unix environment

## Installation

The easiest way to install the application is using the Makefile:

```bash
make release
sudo make install
```

This will compile the release version and install it to `/usr/local/bin/rand_str`.

## Usage

After installation or building, you can run the application:

```bash
# If installed to system
rand_str [options]

# If running from build directory
./bin/Debug/rand_str [options]    # Debug build
./bin/Release/rand_str [options]  # Release build
```

### Command Line Options

| Option | Description | Default | Range |
|--------|-------------|---------|-------|
| `--len <number>` | String length | 5 | 5-60 |
| `--upper <number>` | Number of uppercase letters | 0 | 0-5 |
| `--digit <number>` | Number of digits | 0 | 0-5 |
| `--special <number>` | Number of special characters | 0 | 0-5 |

### Examples

```bash
# Generate a 10-character string with default settings
rand_str --len 10

# Generate a 15-character string with 2 uppercase letters and 3 digits
rand_str --len 15 --upper 2 --digit 3

# Generate a 20-character string with all character types
rand_str --len 20 --upper 3 --digit 2 --special 2

# Generate minimum length string with all requirements
rand_str --len 5 --upper 1 --digit 1 --special 1
```

### Notes

- String length must be between 5 and 60 characters
- Uppercase, digit, and special character counts are limited to 0-5 each
- The application uses `/dev/urandom` for secure random generation
- Total required characters (uppercase + digits + special) should not exceed the string length