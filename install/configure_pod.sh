#!/bin/bash

ERROR_canNotAutoDetectXcodeprojFile=(1 "Sorry, couldn't locate the .xcodeproj file automatically. Please specify it with the -p option")
ERROR_noAppKeyProvided=(2 "Please specify the app key (use the -k switch)")

fail() {
  eval local error=('"${'$1'[@]}"')
  echo "${error[1]}" 1>&2
  exit ${error[0]}
}

BIN_DIR="$(cd "$(dirname "$0")" && pwd )"
BASE_DIR="$(dirname "$BIN_DIR")"
PROJECT_DIR="${BASE_DIR}/../.."

shopt -s nullglob

unset app_key help exit xcode_dir
while getopts "p:k:h" option; do
  case $option in
    k)
      app_key=$OPTARG
      ;;
    h)
      help=1
      ;;
    p)
      xcode_dir=$OPTARG
      ;;
    *)
      exit=1
      ;;
  esac
done

[ -z "$help" ] || {
  cat << EOF
Usage:
$0 <options>

  -k <app key>           Rollout app key (required)
  -p <.xcodeproj dir>    a path to the project directory (optional, for cases
                         in which the script can't locate it automatically)
  -h                     this help message
EOF
  exit
}

[ -z "$exit" ] || exit 1

[ -n "$app_key" ] || fail ERROR_noAppKeyProvided

[ -n "$xcode_dir" ] || {
  dirs=("$PROJECT_DIR/"*.xcodeproj)
  [ ${#dirs[*]} == 1 ] || fail ERROR_canNotAutoDetectXcodeprojFile
  xcode_dir=${dirs[0]}
}

echo "Configuring project \"$xcode_dir\""

rm -rf "$PROJECT_DIR"/Rollout-ios-SDK/{.cache,lib,install,Rollout}
"$BIN_DIR"/remove_rollout_from_xcodeproj.rb "$xcode_dir"

add_script="$BIN_DIR/addFile.rb"

cd "$BASE_DIR" && "$add_script" "$xcode_dir"  Pods/Rollout.io/Rollout/RolloutDynamic.m
add_file_exit_status=$?
"$BIN_DIR/create_script.rb" "$xcode_dir" "Rollout Code analyzer" "\"\${SRCROOT}/Pods/Rollout.io/lib/tweaker\" -k $app_key"
create_script_exit_status=$?
exit $(( $add_file_exit_status + $create_script_exit_status ))
