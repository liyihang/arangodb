////////////////////////////////////////////////////////////////////////////////
/// @brief application simple user and session management feature
///
/// @file
///
/// DISCLAIMER
///
/// Copyright 2004-2012 triagens GmbH, Cologne, Germany
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     http://www.apache.org/licenses/LICENSE-2.0
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// Copyright holder is triAGENS GmbH, Cologne, Germany
///
/// @author Dr. Frank Celler
/// @author Copyright 2011-2012, triAGENS GmbH, Cologne, Germany
////////////////////////////////////////////////////////////////////////////////

#ifndef TRIAGENS_USER_MANAGER_APPLICATION_USER_MANAGER_H
#define TRIAGENS_USER_MANAGER_APPLICATION_USER_MANAGER_H 1

#include "ApplicationServer/ApplicationFeature.h"

#include "UserManager/Right.h"

namespace triagens {
  namespace rest {
    class ApplicationServer;
    class HttpHandlerFactory;
    class HttpResponse;
    class HttpRequest;
  }

  namespace admin {

// -----------------------------------------------------------------------------
// --SECTION--                                      class ApplicationUserManager
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup ApplicationServer
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief application simple user and session management feature
////////////////////////////////////////////////////////////////////////////////

    class ApplicationUserManager : public rest::ApplicationFeature {
      ApplicationUserManager (ApplicationUserManager const&);
      ApplicationUserManager& operator= (ApplicationUserManager const&);

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// --SECTION--                                      constructors and destructors
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup ApplicationServer
/// @{
////////////////////////////////////////////////////////////////////////////////

      public:

////////////////////////////////////////////////////////////////////////////////
/// @brief constructor
////////////////////////////////////////////////////////////////////////////////

        ApplicationUserManager ();

////////////////////////////////////////////////////////////////////////////////
/// @brief destructor
////////////////////////////////////////////////////////////////////////////////

        ~ApplicationUserManager ();

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// --SECTION--                                                    public methods
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup ApplicationServer
/// @{
////////////////////////////////////////////////////////////////////////////////

      public:

////////////////////////////////////////////////////////////////////////////////
/// @brief adds the http handlers for administration
///
/// Note that the server does not claim ownership of the factory.
////////////////////////////////////////////////////////////////////////////////

        void addHandlers (rest::HttpHandlerFactory*, string const& prefix);

////////////////////////////////////////////////////////////////////////////////
/// @brief creates a role
////////////////////////////////////////////////////////////////////////////////

        bool createRole (string const& name, vector<right_t> const&, right_t rightToManage);

////////////////////////////////////////////////////////////////////////////////
/// @brief unloads all roles
////////////////////////////////////////////////////////////////////////////////

        static void unloadRoles ();

////////////////////////////////////////////////////////////////////////////////
/// @brief creates a user
////////////////////////////////////////////////////////////////////////////////

        bool createUser (string const& name, string const& role);

////////////////////////////////////////////////////////////////////////////////
/// @brief loads the user database
////////////////////////////////////////////////////////////////////////////////

        bool loadUser ();

////////////////////////////////////////////////////////////////////////////////
/// @brief unloads all users
////////////////////////////////////////////////////////////////////////////////

        static void unloadUsers ();

////////////////////////////////////////////////////////////////////////////////
/// @brief sets the right of an anonymous session
////////////////////////////////////////////////////////////////////////////////

        void setAnonymousRights (vector<right_t> const&);

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// --SECTION--                                        ApplicationFeature methods
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup ApplicationServer
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// {@inheritDoc}
////////////////////////////////////////////////////////////////////////////////

        void setupOptions (map<string, basics::ProgramOptionsDescription>&);

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// --SECTION--                                          static private variables
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup ApplicationServer
/// @{
////////////////////////////////////////////////////////////////////////////////

      private:

////////////////////////////////////////////////////////////////////////////////
/// @brief option for the path of the user database
////////////////////////////////////////////////////////////////////////////////

        static string optionUserDatabase;
    };
  }
}

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

#endif

// Local Variables:
// mode: outline-minor
// outline-regexp: "^\\(/// @brief\\|/// {@inheritDoc}\\|/// @addtogroup\\|// --SECTION--\\|/// @\\}\\)"
// End:
