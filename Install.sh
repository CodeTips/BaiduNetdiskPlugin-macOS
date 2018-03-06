#!/bin/sh
if ! [ -x "$(command -v optool)" ]; then
    echo 'Error: Optool is not installed.Installing Through HomeBrew...' >&2
  if ! [ -x "$(command -v brew)" ]; then
    echo 'Error: HomeBrew is not installed.Installing...' >&2
    /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
    brew install optool
  fi
fi
clang -shared -undefined dynamic_lookup -o /Applications/BaiduNetdisk_mac.app/Contents/MacOS/libPCS.dylib PCS.m
optool install -c load -p @executable_path/libPCS.dylib -t /Applications/BaiduNetdisk_mac.app/Contents/MacOS/BaiduNetdisk_mac
echo "Done!"
