// This source file is part of the polarphp.org open source project
//
// Copyright (c) 2017 - 2018 polarphp software foundation
// Copyright (c) 2017 - 2018 zzu_softboy <zzu_softboy@163.com>
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://polarphp.org/LICENSE.txt for license information
// See http://polarphp.org/CONTRIBUTORS.txt for the list of polarphp project authors
//
// Created by polarboy on 2018/08/30.

#ifndef POLAR_DEVLTOOLS_LIT_LITCONFIG_H
#define POLAR_DEVLTOOLS_LIT_LITCONFIG_H

#include <string>
#include <list>
#include <map>
#include <optional>

namespace polar {
namespace lit {

class LitConfig
{
public:
   LitConfig(const std::string &progName, const std::list<std::string> &path,
             bool quiet, bool useValgrind,
             bool valgrindLeakCheck, const std::list<std::string> &valgrindArgs,
             bool noExecute, bool debug, bool singleProcess, bool isWindows,
             const std::map<std::string, std::string> &params, const std::optional<std::string> &configPrefix = std::nullopt,
             int maxIndividualTestTime = 0, const std::optional<int> &maxFailures = std::nullopt,
             const std::map<std::string, std::string> &parallelismGroups = std::map<std::string, std::string>{},
             bool echoAllCommands = false);

   int getMaxIndividualTestTime()
   {
      return m_maxIndividualTestTime;
   }

   LitConfig &setMaxIndividualTestTime(int value);

   void note(const std::string &message,
             const std::string &file = "", const std::string &line = "")
   {
      writeMessage("note", message, file, line);
   }
   void warning(const std::string &message,
                const std::string &file = "", const std::string &line = "")
   {
      writeMessage("warning", message, file, line);
      m_numWarnings += 1;
   }
   void error(const std::string &message,
              const std::string &file = "", const std::string &line = "")
   {
      writeMessage("error", message, file, line);
      m_numErrors += 1;
   }

   void fatal(const std::string &message,
              const std::string &file = "", const std::string &line = "")
   {
      writeMessage("fatal", message, file, line);
      exit(2);
   }

   std::optional<std::string> getBashPath();
   std::string getToolsPath();
private:
   void writeMessage(const std::string &kind, const std::string &message,
                     const std::string &file = "", const std::string &line = "");
protected:
   std::string m_progName;
   std::list<std::string> m_path;
   bool m_quiet;
   bool m_useValgrind;
   bool m_valgrindLeakCheck;
   std::list<std::string> m_valgrindUserArgs;
   bool m_noExecute;
   bool m_debug;
   bool m_singleProcess;
   bool m_isWindows;
   std::map<std::string, std::string> m_params;
   std::optional<std::string> m_bashPath;
   std::string m_configPrefix;
   std::list<std::string> m_suffixes;
   std::list<std::string> m_configNames;
   std::list<std::string> m_siteConfigNames;
   std::list<std::string> m_localConfigNames;
   int m_numErrors;
   int m_numWarnings;
   std::list<std::string> m_valgrindArgs;
   int m_maxIndividualTestTime;
   std::optional<int> m_maxFailures;
   std::map<std::string, std::string> m_parallelismGroups;
   bool m_echoAllCommands;
};

} // lit
} // polar

#endif // POLAR_DEVLTOOLS_LIT_LITCONFIG_H