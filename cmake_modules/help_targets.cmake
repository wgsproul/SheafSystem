#
#
# Copyright (c) 2014 Limit Point Systems, Inc. 
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#


#
# Help targets
# $$TODO: format output to 80 chars

add_custom_target(help
    COMMAND ${CMAKE_COMMAND} -E echo "    "     
    COMMAND ${CMAKE_COMMAND} -E echo "    "  
    COMMAND ${CMAKE_COMMAND} -E echo "The following help targets are available: "
    COMMAND ${CMAKE_COMMAND} -E echo "    "        
    COMMAND ${CMAKE_COMMAND} -E echo "    help-targets -- lists available system targets."
    COMMAND ${CMAKE_COMMAND} -E echo "    help-cmake-options -- Things you can say to cmake to affect the build system state."
    COMMAND ${CMAKE_COMMAND} -E echo "    "        
    COMMAND ${CMAKE_COMMAND} -E echo "")
    
add_custom_target(help-cmake-options
    COMMAND ${CMAKE_COMMAND} -E echo "" 
    COMMAND ${CMAKE_COMMAND} -E echo "BUILD_SHEAFSCOPE:"
    COMMAND ${CMAKE_COMMAND} -E echo "    "         
    COMMAND ${CMAKE_COMMAND} -E echo "    Toggles generation of SheafScope target. "
    COMMAND ${CMAKE_COMMAND} -E echo "    " 
    COMMAND ${CMAKE_COMMAND} -E echo "    Type: boolean"         
    COMMAND ${CMAKE_COMMAND} -E echo "    " 
    COMMAND ${CMAKE_COMMAND} -E echo "    Default Value: OFF"
    COMMAND ${CMAKE_COMMAND} -E echo "    " 
    COMMAND ${CMAKE_COMMAND} -E echo "        example: ./cmboot -DBUILD_SHEAFSCOPE=ON"
    COMMAND ${CMAKE_COMMAND} -E echo "        example -- from build directory: cmake -DBUILD_SHEAFSCOPE=ON .."        
    COMMAND ${CMAKE_COMMAND} -E echo "    "
    COMMAND ${CMAKE_COMMAND} -E echo "CMAKE_BUILD_TYPE:"
    COMMAND ${CMAKE_COMMAND} -E echo "    "         
    COMMAND ${CMAKE_COMMAND} -E echo "    Sets the default build type for this run. Only meaningful in Linux "
    COMMAND ${CMAKE_COMMAND} -E echo "    as build type is chosen at compile time in Visual Studio."
    COMMAND ${CMAKE_COMMAND} -E echo "    " 
    COMMAND ${CMAKE_COMMAND} -E echo "    Type: string"         
    COMMAND ${CMAKE_COMMAND} -E echo "    " 
    COMMAND ${CMAKE_COMMAND} -E echo "    Default Value: Debug_contracts"
    COMMAND ${CMAKE_COMMAND} -E echo "    " 
    COMMAND ${CMAKE_COMMAND} -E echo "        example: ./cmboot -DCMAKE_BUILD_TYPE=Release_contracts"
    COMMAND ${CMAKE_COMMAND} -E echo "        example -- from build directory: cmake -DCMAKE_BUILD_TYPE=Release_contracts .."        
    COMMAND ${CMAKE_COMMAND} -E echo "    "
    COMMAND ${CMAKE_COMMAND} -E echo "ENABLE_COVERAGE:"
    COMMAND ${CMAKE_COMMAND} -E echo "    "         
    COMMAND ${CMAKE_COMMAND} -E echo "    Toggles Intel compiler flag for generating coverage data. "
    COMMAND ${CMAKE_COMMAND} -E echo "    " 
    COMMAND ${CMAKE_COMMAND} -E echo "    Type: boolean"         
    COMMAND ${CMAKE_COMMAND} -E echo "    "         
    COMMAND ${CMAKE_COMMAND} -E echo "    Default Value: OFF"
    COMMAND ${CMAKE_COMMAND} -E echo "    " 
    COMMAND ${CMAKE_COMMAND} -E echo "        example: ./cmboot -DENABLE_COVERAGE=ON"
    COMMAND ${CMAKE_COMMAND} -E echo "        example -- from build directory: cmake -DENABLE_COVERAGE=ON .."        
    COMMAND ${CMAKE_COMMAND} -E echo "    "
    COMMAND ${CMAKE_COMMAND} -E echo "DOC_STATE:"
    COMMAND ${CMAKE_COMMAND} -E echo "    "         
    COMMAND ${CMAKE_COMMAND} -E echo "    Changes nature of generated documentation. "
    COMMAND ${CMAKE_COMMAND} -E echo "    " 
    COMMAND ${CMAKE_COMMAND} -E echo "    Type: string"         
    COMMAND ${CMAKE_COMMAND} -E echo "    " 
    COMMAND ${CMAKE_COMMAND} -E echo "    Default Value: user"
    COMMAND ${CMAKE_COMMAND} -E echo "    " 
    COMMAND ${CMAKE_COMMAND} -E echo "        example: ./cmboot -DDOC_STATE=dev"
    COMMAND ${CMAKE_COMMAND} -E echo "        example -- from build directory: cmake -DDOC_STATE=dev .."        
    COMMAND ${CMAKE_COMMAND} -E echo "    "
    COMMAND ${CMAKE_COMMAND} -E echo "INSTALL_DOCS:"
    COMMAND ${CMAKE_COMMAND} -E echo "    "         
    COMMAND ${CMAKE_COMMAND} -E echo "    Toggles installation of generated documentation. "
    COMMAND ${CMAKE_COMMAND} -E echo "    " 
    COMMAND ${CMAKE_COMMAND} -E echo "    Type: boolean"         
    COMMAND ${CMAKE_COMMAND} -E echo "    " 
    COMMAND ${CMAKE_COMMAND} -E echo "    Default Value: OFF"
    COMMAND ${CMAKE_COMMAND} -E echo "    " 
    COMMAND ${CMAKE_COMMAND} -E echo "        example: ./cmboot -DINSTALL_DOCS=ON"
    COMMAND ${CMAKE_COMMAND} -E echo "        example -- from build directory: cmake -DINSTALL_DOCS=ON .."        
    COMMAND ${CMAKE_COMMAND} -E echo "    "
    COMMAND ${CMAKE_COMMAND} -E echo "BUILD_BINDINGS:"
    COMMAND ${CMAKE_COMMAND} -E echo "    "         
    COMMAND ${CMAKE_COMMAND} -E echo "    Toggles bindings targets. Implies BUILD_TOOLS=ON "
    COMMAND ${CMAKE_COMMAND} -E echo "    " 
    COMMAND ${CMAKE_COMMAND} -E echo "    Type: boolean"         
    COMMAND ${CMAKE_COMMAND} -E echo "    "        
    COMMAND ${CMAKE_COMMAND} -E echo "    Default Value: OFF"
    COMMAND ${CMAKE_COMMAND} -E echo "    " 
    COMMAND ${CMAKE_COMMAND} -E echo "        example: ./cmboot -DBUILD_BINDINGS=ON"
    COMMAND ${CMAKE_COMMAND} -E echo "        example -- from build directory: cmake -DBUILD_BINDINGS=ON .."  
    COMMAND ${CMAKE_COMMAND} -E echo "")
    
add_custom_target(help-targets
    COMMAND ${CMAKE_COMMAND} -E echo "" 
    COMMAND ${CMAKE_COMMAND} -E echo "The fundamental targets are: "
    COMMAND ${CMAKE_COMMAND} -E echo "    all"
    COMMAND ${CMAKE_COMMAND} -E echo "    bin" 
    COMMAND ${CMAKE_COMMAND} -E echo "    bindings"
    COMMAND ${CMAKE_COMMAND} -E echo "    check"
    COMMAND ${CMAKE_COMMAND} -E echo "    coverage"
    COMMAND ${CMAKE_COMMAND} -E echo "    doc"
    COMMAND ${CMAKE_COMMAND} -E echo "    lib"        
    COMMAND ${CMAKE_COMMAND} -E echo "    shared-libs"
    COMMAND ${CMAKE_COMMAND} -E echo "    static-libs"
    COMMAND ${CMAKE_COMMAND} -E echo "    SheafScope"


    COMMAND ${CMAKE_COMMAND} -E echo ""
    COMMAND ${CMAKE_COMMAND} -E echo ""
    COMMAND ${CMAKE_COMMAND} -E echo "all [default]:"
    COMMAND ${CMAKE_COMMAND} -E echo "    Builds the entire system -- shared libraries, static libraries, bindings, unit test, examples, and all docs. "
    COMMAND ${CMAKE_COMMAND} -E echo "    "
    COMMAND ${CMAKE_COMMAND} -E echo "    Aliases: none."
    COMMAND ${CMAKE_COMMAND} -E echo "    "
    COMMAND ${CMAKE_COMMAND} -E echo "    Related commands: none."
    COMMAND ${CMAKE_COMMAND} -E echo "    "
    COMMAND ${CMAKE_COMMAND} -E echo "bin:    "
    COMMAND ${CMAKE_COMMAND} -E echo "    Builds all shared libraries, unit test routines, and examples." 
    COMMAND ${CMAKE_COMMAND} -E echo "    Does not execute any compiled code."
    COMMAND ${CMAKE_COMMAND} -E echo ""
    COMMAND ${CMAKE_COMMAND} -E echo "    Aliases: none."
    COMMAND ${CMAKE_COMMAND} -E echo "    "
    COMMAND ${CMAKE_COMMAND} -E echo "    Related commands:"
    COMMAND ${CMAKE_COMMAND} -E echo "        Bin targets can be invoked per component. All prerequisite libraries. "
    COMMAND ${CMAKE_COMMAND} -E echo "        and executables will be constructed in dependency order if needed."
    COMMAND ${CMAKE_COMMAND} -E echo "    " 
    COMMAND ${CMAKE_COMMAND} -E echo "        example: make fields-bin"
    COMMAND ${CMAKE_COMMAND} -E echo "        example: make sheaves-bin"
    COMMAND ${CMAKE_COMMAND} -E echo "    "
    COMMAND ${CMAKE_COMMAND} -E echo "bindings:    "
    COMMAND ${CMAKE_COMMAND} -E echo "    Builds the shared libraries, bindings libraries, and associated jar files for all"
    COMMAND ${CMAKE_COMMAND} -E echo "    system components -- also builds the SheafScope."
    COMMAND ${CMAKE_COMMAND} -E echo "    " 
    COMMAND ${CMAKE_COMMAND} -E echo "    Aliases: SheafScope."
    COMMAND ${CMAKE_COMMAND} -E echo ""
    COMMAND ${CMAKE_COMMAND} -E echo "    Related commands:"
    COMMAND ${CMAKE_COMMAND} -E echo "        Bindings targets can be invoked per component as well as per component-language."
    COMMAND ${CMAKE_COMMAND} -E echo "        All prerequisite libraries will be constructed in dependency order if needed."
    COMMAND ${CMAKE_COMMAND} -E echo "    " 
    COMMAND ${CMAKE_COMMAND} -E echo "        example: make fields-bindings"
    COMMAND ${CMAKE_COMMAND} -E echo "        example: make fields-java-binding"
    COMMAND ${CMAKE_COMMAND} -E echo "        example: make fields-python-binding"
    COMMAND ${CMAKE_COMMAND} -E echo "        example: make fields-csharp-binding"     	
    COMMAND ${CMAKE_COMMAND} -E echo "    "            
    COMMAND ${CMAKE_COMMAND} -E echo "check:    "
    COMMAND ${CMAKE_COMMAND} -E echo "    Builds all shared libraries and unit test routines, then executes the unit " 
    COMMAND ${CMAKE_COMMAND} -E echo "    tests. Provided make -j1, execution will be in component order. That is -- all"
    COMMAND ${CMAKE_COMMAND} -E echo "    tests for a component will be built and executed in serial order before moving"
    COMMAND ${CMAKE_COMMAND} -E echo "    on to the next component. If make -j greater than 1, behavior may vary."
    COMMAND ${CMAKE_COMMAND} -E echo "    "            
    COMMAND ${CMAKE_COMMAND} -E echo "    Aliases: none."
    COMMAND ${CMAKE_COMMAND} -E echo "    "
    COMMAND ${CMAKE_COMMAND} -E echo "    Related commands:"
    COMMAND ${CMAKE_COMMAND} -E echo "        Check targets can be invoked per component. All prerequisite libraries "
    COMMAND ${CMAKE_COMMAND} -E echo "        will be constructed in dependency order if needed."
    COMMAND ${CMAKE_COMMAND} -E echo "    " 
    COMMAND ${CMAKE_COMMAND} -E echo "        example: make fields-check"
    COMMAND ${CMAKE_COMMAND} -E echo "        example: make sheaves-check"
    COMMAND ${CMAKE_COMMAND} -E echo "    " 
    COMMAND ${CMAKE_COMMAND} -E echo "coverage:    "
    COMMAND ${CMAKE_COMMAND} -E echo "    Only available if C++ compiler is Intel."
    COMMAND ${CMAKE_COMMAND} -E echo "    Builds all shared libraries and unit test routines using '-prof-gen=srcpos' on  " 
    COMMAND ${CMAKE_COMMAND} -E echo "    linux, or '/Qprof-gen:srcpos' on Windows , executes the unit tests, and generates coverage documentation."
    COMMAND ${CMAKE_COMMAND} -E echo "    Provided make -j1, execution will be in component order. That is -- all"
    COMMAND ${CMAKE_COMMAND} -E echo "    tests for a component will be built and executed in serial order before moving"
    COMMAND ${CMAKE_COMMAND} -E echo "    on to the next component. If make -j greater than 1, behavior may vary."
    COMMAND ${CMAKE_COMMAND} -E echo "    "
    COMMAND ${CMAKE_COMMAND} -E echo "    Aliases: none."
    COMMAND ${CMAKE_COMMAND} -E echo "    "
    COMMAND ${CMAKE_COMMAND} -E echo "    Related commands:"
    COMMAND ${CMAKE_COMMAND} -E echo "        Coverage targets can be invoked per component. All prerequisite libraries "
    COMMAND ${CMAKE_COMMAND} -E echo "        and executables will be constructed in dependency order if needed."
    COMMAND ${CMAKE_COMMAND} -E echo "    " 
    COMMAND ${CMAKE_COMMAND} -E echo "        example: make fields-coverage"
    COMMAND ${CMAKE_COMMAND} -E echo "        example: make sheaves-coverage"
    COMMAND ${CMAKE_COMMAND} -E echo "    "
    COMMAND ${CMAKE_COMMAND} -E echo "doc:    "
    COMMAND ${CMAKE_COMMAND} -E echo "    Constructs system-scope C++ library documentation, placing the output in CMAKE_BINARY_DIR/documentation."
    COMMAND ${CMAKE_COMMAND} -E echo "    "
    COMMAND ${CMAKE_COMMAND} -E echo "    Aliases: none."
    COMMAND ${CMAKE_COMMAND} -E echo "    "
    COMMAND ${CMAKE_COMMAND} -E echo "    Related commands:"                    
    COMMAND ${CMAKE_COMMAND} -E echo "        java-docs -- Builds the system bindings and constructs java documentation for same."
    COMMAND ${CMAKE_COMMAND} -E echo "                     Does not construct the C++ library docs."
    COMMAND ${CMAKE_COMMAND} -E echo "        alldocs   -- Contructs C++ and java documentation    "
    COMMAND ${CMAKE_COMMAND} -E echo ""              
    COMMAND ${CMAKE_COMMAND} -E echo "shared-libs:"
    COMMAND ${CMAKE_COMMAND} -E echo "    Builds the shared libraries, and only the shared libraries, for all system components."
    COMMAND ${CMAKE_COMMAND} -E echo "    "
    COMMAND ${CMAKE_COMMAND} -E echo "    Aliases: lib"
    COMMAND ${CMAKE_COMMAND} -E echo "    "
    COMMAND ${CMAKE_COMMAND} -E echo "    Related commands:"
    COMMAND ${CMAKE_COMMAND} -E echo "        [comp]-shared-lib will invoke the shared library target for [comp], dealing"
    COMMAND ${CMAKE_COMMAND} -E echo "        with dependencies in order."
    COMMAND ${CMAKE_COMMAND} -E echo "    "        
    COMMAND ${CMAKE_COMMAND} -E echo "        example: make fields-shared-lib"   
    COMMAND ${CMAKE_COMMAND} -E echo ""        
    COMMAND ${CMAKE_COMMAND} -E echo "static-libs:    "
    COMMAND ${CMAKE_COMMAND} -E echo "    Builds the static libraries, and only the static libraries, for all system components.     "
    COMMAND ${CMAKE_COMMAND} -E echo "    "
    COMMAND ${CMAKE_COMMAND} -E echo "    Aliases: none."
    COMMAND ${CMAKE_COMMAND} -E echo "    "
    COMMAND ${CMAKE_COMMAND} -E echo "    Related commands:"
    COMMAND ${CMAKE_COMMAND} -E echo "        \"<comp>\"-static-lib will invoke the static library target for \"<comp>\", dealing"
    COMMAND ${CMAKE_COMMAND} -E echo "        with dependencies in order."
    COMMAND ${CMAKE_COMMAND} -E echo "    "        
    COMMAND ${CMAKE_COMMAND} -E echo "        example: make fields-static-lib"   
    COMMAND ${CMAKE_COMMAND} -E echo "    "
    COMMAND ${CMAKE_COMMAND} -E echo "SheafScope:    "
    COMMAND ${CMAKE_COMMAND} -E echo "    Builds the SheafScope and all dependent shared libraries, bindings libraries, and jar files."
    COMMAND ${CMAKE_COMMAND} -E echo "    " 
    COMMAND ${CMAKE_COMMAND} -E echo "    Aliases: bindings."
    COMMAND ${CMAKE_COMMAND} -E echo ""
    COMMAND ${CMAKE_COMMAND} -E echo "    Related commands:"
    COMMAND ${CMAKE_COMMAND} -E echo "        Bindings targets can be invoked per component as well as per component-language."
    COMMAND ${CMAKE_COMMAND} -E echo "        All prerequisite libraries will be constructed in dependency order if needed."
    COMMAND ${CMAKE_COMMAND} -E echo "    " 
    COMMAND ${CMAKE_COMMAND} -E echo "        example: make bindings"
    COMMAND ${CMAKE_COMMAND} -E echo "        example: make fields-bindings"
    COMMAND ${CMAKE_COMMAND} -E echo "        example: make fields-java-binding"
    COMMAND ${CMAKE_COMMAND} -E echo "        example: make fields-python-binding"
    COMMAND ${CMAKE_COMMAND} -E echo "        example: make fields-csharp-binding"   	
    COMMAND ${CMAKE_COMMAND} -E echo "    "    
)