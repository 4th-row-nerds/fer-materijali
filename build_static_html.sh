#!/bin/bash

PORT="8080"

# Remove old build
rm -rf ./build/

# Move all files to build
cp -r . ./build/

# Remove build from itself
rm -rf ./build/build

# Remove extra markdown files
find ./build -name '*.md' -exec rm './{}' ';'

# Remove .git directories and config
find ./build -name '*.yml' -exec rm './{}' ';'
rm -rf ./build/.git
rm -f ./build/.gitignore

# Code Highlighting themes:
# github-dark, onedark, arduino, catppuccin-latte, catppuccin-frappe, monokailight, nord, xcode, xcode-dark, vs, pastie
# Test and find more available themes on https://swapoff.org/chroma/playground/
HL_THEME="catppuccin-latte"

# Generate HTML from markdown files
./deploy/gm **/*.md --move-no-md -o build --gm-highlighting $HL_THEME



if [ "$1" = "run" ]; then
	pushd build
	echo "Serving HTTP on localhost:$PORT"
	python3 -m http.server $PORT 2>&1 | tee ../server.log --ignore-interrupts
	popd
fi
