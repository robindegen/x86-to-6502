CLANG_FORMAT="clang-format"

function format {
    DIRECTORY=$1
    echo "Formatting code under $DIRECTORY/"
    find "$DIRECTORY" \( -name '*.h' -or -name '*.cpp' \) -print0 | xargs -0 "$CLANG_FORMAT" -i
}

format $(pwd)/libca
format $(pwd)/targets
format $(pwd)/x86-to-6502
