#!/bin/bash

compile_help() {
    echo "Usage: $0 [options...] input_dir output_dir"
    echo
    echo "Simple compiler script that uses GM compiler to compile"
    echo "and structure markdown pages for fer-nerds materials."
    echo
    echo "Options:"
    echo "    -h         Display this help message."
    echo "    -g <path>  Used to specify GM compiler path."
    echo "    -t <dir>   Uses specified dir as temp dir, if not specified"
    echo "               directory inside /tmp will be created."
}

# Default gm path
GM_PATH='gm'

# Parse command line switches
while getopts ':hg:t:' OPTION; do
    case "$OPTION" in
        h) # Print help
            compile_help
            exit
            ;;
        g) # Set GM path
            GM_PATH="$OPTARG"
            ;;
        t) # Set temp dir path
            TEMP_DIR="$OPTARG"
            ;;
        *) # Unknown option
            echo "Error: Invalid option specified"
            exit 1
            ;;
    esac
done

shift $(( OPTIND - 1 ))

if [[ $# != 2 ]]; then
    echo "Error: Invalid number of arguments, use -h for help"
    exit 1
fi

# Store directory names
IN_DIR="$1"
OUT_DIR="$2"

# If temp directory is not specified create one
if [ -z "$TEMP_DIR" ]; then
    TEMP_DIR=$(mktemp -d)
fi

# Create content directories if the don't exist
mkdir -p "$TEMP_DIR" "$IN_DIR" "$OUT_DIR"

# Remember initial working directory
OLD_WD=$(pwd)

# Resolve paths
IN_DIR=$(readlink -f "$IN_DIR")
OUT_DIR=$(readlink -f "$OUT_DIR")
TEMP_DIR=$(readlink -f "$TEMP_DIR")
GM_PATH=$(readlink -f "$GM_PATH")

echo "Using following directories"
echo "   in   => $IN_DIR"
echo "   out  => $OUT_DIR"
echo "   temp => $TEMP_DIR"

# Copy all files to temp dir and all but md files to output
rsync -av "$IN_DIR/" "$TEMP_DIR/" > /dev/null
rsync -av --exclude '*.md' "$IN_DIR/" "$OUT_DIR/" > /dev/null

# For each of directories
cd "$TEMP_DIR"
for DIR in $(find . -type d); do

    # If there is no README.md file create directory listing
    if [ ! -f "$TEMP_DIR/$DIR/README.md" ]; then
        echo -e "# Direktorij [$(basename "$DIR")]\n" > "$TEMP_DIR/$DIR/README.md"
        echo "[← Natrag](..)" >> "$TEMP_DIR/$DIR/README.md"

        for FL in $(ls "$IN_DIR/$DIR"); do
            echo "- [$(basename $FL)]($FL)" >> "$TEMP_DIR/$DIR/README.md"
        done
    fi

    # Generate directory _ with directory listing for current directory
    mkdir "$TEMP_DIR/$DIR/_/"
    echo -e "# Direktorij [$(basename "$DIR")]\n" > "$TEMP_DIR/$DIR/_/README.md"
    echo "[← Isključi Directory View](..)" >> "$TEMP_DIR/$DIR/_/README.md"

    for FL in $(ls "$IN_DIR/$DIR"); do
        echo "- [$(basename $FL)](../$FL)" >> "$TEMP_DIR/$DIR/_/README.md"
    done
done

# Compile markdown
echo $(find . -type f -name '*.md' | sed 's|^./||')
$GM_PATH $(find . -type f -name '*.md' | sed 's|^./||') --move-no-md -o "$OUT_DIR" --gm-highlighting "catppuccin-latte"

# Create index.html for eacg README.html file
find "$OUT_DIR" -type f -name 'README.html' -exec bash -c 'cp "$1" $(dirname "$1")/index.html' - '{}' ';'