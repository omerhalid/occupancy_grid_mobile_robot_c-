# CMake generated Testfile for 
# Source directory: C:/Users/katka/source/continental_task_omer_cinar
# Build directory: C:/Users/katka/source/continental_task_omer_cinar/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(MyGoogleTest "C:/Users/katka/source/continental_task_omer_cinar/build/Debug/runUnitTests.exe")
  set_tests_properties(MyGoogleTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/katka/source/continental_task_omer_cinar/CMakeLists.txt;45;add_test;C:/Users/katka/source/continental_task_omer_cinar/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(MyGoogleTest "C:/Users/katka/source/continental_task_omer_cinar/build/Release/runUnitTests.exe")
  set_tests_properties(MyGoogleTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/katka/source/continental_task_omer_cinar/CMakeLists.txt;45;add_test;C:/Users/katka/source/continental_task_omer_cinar/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(MyGoogleTest "C:/Users/katka/source/continental_task_omer_cinar/build/MinSizeRel/runUnitTests.exe")
  set_tests_properties(MyGoogleTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/katka/source/continental_task_omer_cinar/CMakeLists.txt;45;add_test;C:/Users/katka/source/continental_task_omer_cinar/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(MyGoogleTest "C:/Users/katka/source/continental_task_omer_cinar/build/RelWithDebInfo/runUnitTests.exe")
  set_tests_properties(MyGoogleTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/katka/source/continental_task_omer_cinar/CMakeLists.txt;45;add_test;C:/Users/katka/source/continental_task_omer_cinar/CMakeLists.txt;0;")
else()
  add_test(MyGoogleTest NOT_AVAILABLE)
endif()
subdirs("googletest")
