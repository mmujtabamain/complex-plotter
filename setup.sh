#!/bin/bash

# variables

# Color codes
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
PURPLE='\033[0;35m'
RESET='\033[0m' # No Color
readonly GREEN RED YELLOW CYAN PURPLE RESET

# variables end

set -e

# DO NOT CALL; has been called once; given below for reference only
# git submodule add https://github.com/microsoft/vcpkg.git external/vcpkg

# update submodules
git submodule update --init --recursive

# bootstrap it to generate ./external/vcpkg/vcpkg
# if bootstrap file `external/vcpkg/vcpkg` does not exists generate it
if [ ! -f "./external/vcpkg/vcpkg" ]; then
    echo -e "${YELLOW}Bootstrapping vcpkg... ${RESET}"
    ./external/vcpkg/bootstrap-vcpkg.sh
else
    echo -e "${GREEN}vcpkg already bootstrapped. ${RESET}"
fi

echo -e "${CYAN}To install packages run ./external/vcpkg/vcpkg install <package_name>${RESET}"

# install packages (for current template)
# ./external/vcpkg/vcpkg install fmt
# ./external/vcpkg/vcpkg install boost-iostreams boost-filesystem boost-system
# curl -L https://raw.githubusercontent.com/dstahlke/gnuplot-iostream/master/gnuplot-iostream.h -o external/include/gnuplot-iostream.h

echo -e "${CYAN}Run ./run.sh for running the program ${RESET}"
