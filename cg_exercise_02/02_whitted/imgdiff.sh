#!/bin/zsh
mkdir -p assignment_diffs
for img in assignment_references/*.png; do
    filename=$(basename "$img")
    compare -compose src assignment_references/$filename assignment_images/$filename assignment_diffs/$filename
done