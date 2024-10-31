#!/bin/bash

# Set directories used during compilation
IN_DIR=$1
OUT_DIR=$2
TEMP_DIR=$3

# Create content directories if the don't exist
mkdir -p $TEMP_DIR $IN_DIR $OUT_DIR

# Remember initial working directory
OLD_WD=$(pwd)

# Resolve paths
IN_DIR=$(readlink -f $IN_DIR)
OUT_DIR=$(readlink -f $OUT_DIR)
TEMP_DIR=$(readlink -f $TEMP_DIR)
GM_PATH=$(readlink -f $GM_PATH)

echo $IN_DIR $OUT_DIR $TEMP_DIR $GM_PATH

# Find paths for all folders without README.md file (paths are relative to content dir)
cd $IN_DIR
DATA_DIRS=$(find . -type d ! -exec test -e "{}/README.md" \; -print)
cd $OLD_WD

# Copy all files to temp dir and all but md files to output
rsync -av $IN_DIR/ $TEMP_DIR/ > /dev/null
rsync -av --exclude '*.md' $IN_DIR/ $OUT_DIR/ > /dev/null

# For each of directories with no README.md files create directory listing
# README.md file
for DIR in $DATA_DIRS; do
    FILES=$(find $TEMP_DIR/$DIR -mindepth 1)

    if [[ "$DIR" != "$IN_DIR" ]]; then
        touch $TEMP_DIR/$DIR/README.md
        echo -e "# Direktorij [$(basename "$DIR")]\n" > $TEMP_DIR/$DIR/README.md
        echo "[← Natrag](..)" >> $TEMP_DIR/$DIR/README.md
    fi;

    for FL in $(ls $IN_DIR/$DIR); do
        echo "- [$(basename $FL)]($FL)" >> $TEMP_DIR/$DIR/README.md
    done
done

# Compile markdown
cd $TEMP_DIR
echo $(find . -type f -name '*.md' | sed 's|^./||')
$GM_PATH $(find . -type f -name '*.md' | sed 's|^./||') --move-no-md -o $OUT_DIR --gm-highlighting "catppuccin-latte"

# Create index.html for eacg README.html file
find $OUT_DIR -type f -name 'README.html' -exec bash -c 'cp "$1" $(dirname "$1")/index.html' - '{}' ';'