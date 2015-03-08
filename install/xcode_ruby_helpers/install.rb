#!/usr/bin/env ruby

require 'json'
require_relative './bundle/bundler/setup'
require_relative './remove_rollout_from_xcodeproj'
require_relative './addfile'
require_relative './create_script'
require_relative './override_clang'

configuration = JSON.parse(STDIN.read)
xcode_dir = configuration["xcode_dir"]
app_key = configuration["app_key"]
files_to_add = configuration["files_to_add"]
sdk_subdir = configuration["sdk_subdir"]

project = Xcodeproj::Project.new(xcode_dir)
project.initialize_from_file

RemoveRolloutFromXcodeproj.new(project).remove_rollout_from_xcodeproj

add_file = AddFile.new(project)
add_file_result = 0 
files_to_add.each do |full_path|
  add_file_result = [add_file.add_file(full_path), add_file_result].max
end

script_content = "\"\${SRCROOT}/#{sdk_subdir}/lib/tweaker\" -k #{app_key}"
CreateScript.new(project).create_script("Rollout.io post-build", script_content)

OverrideClang.new(project).install("\${SRCROOT}/#{sdk_subdir}/lib")

project.save()

base_dir = "#{File.dirname __FILE__}/../.."
system "{ . '#{base_dir}/lib/versions' ; echo $build; } > '#{base_dir}'/.last_installed_build"

exit add_file_result
