// This source file is part of the polarphp.org open source project
//
// Copyright (c) 2017 - 2018 polarphp software foundation
// Copyright (c) 2017 - 2018 zzu_softboy <zzu_softboy@163.com>
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://polarphp.org/LICENSE.txt for license information
// See http://polarphp.org/CONTRIBUTORS.txt for the list of polarphp project authors
//
// Created by polarboy on 2018/11/05.

#include <iostream>
#include <list>
#include <string>

extern char **environ;

int main(int, char **)
{
   std::list<std::string> environVars;
   for (char **env = environ; *env != 0; env++)
   {
      environVars.push_back(*env);
   }
   environVars.sort();
   for (const std::string &item : environVars) {
      std::cout << item << std::endl;
   }
   return 0;
}