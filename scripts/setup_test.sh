#!/usr/bin/env bash
rm -rf ../cmake-build-debug/test/libToreador.dll
rm -rf ../cmake-build-debug/test/libglad.dll
mv ../cmake-build-debug/libToreador.dll ../cmake-build-debug/test/
mv ../cmake-build-debug/libs/glad/libglad.dll ../cmake-build-debug/test/