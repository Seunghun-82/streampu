/*!
 * \file
 * \brief AFF3CT helper.
 */
#ifndef HELP_HPP_
#define HELP_HPP_

#include <sstream>
#include <iostream>

#include "Module/Module.hpp"
#include "Runtime/Task/Task.hpp"
#include "Runtime/Socket/Socket.hpp"

namespace aff3ct
{
namespace tools
{
    /*! Print help for a module.
    \param mdl A reference on the module.
    \param verbose If true, more information is displayed.
    \param stream Output stream to write help.
    */
    inline void help(const aff3ct::module::Module  &mdl, const bool& verbose = false, std::ostream& stream = std::cout);

    /*! Print help for a task.
    \param tsk A reference on the task.
    \param verbose If true, more information is displayed.
    \param stream Output stream to write help.
    */
    inline void help(const aff3ct::runtime::Task   &tsk, const bool& verbose = false, std::ostream& stream = std::cout);

    /*! Print help for a socket.
    \param sck A reference on the socket.
    \param verbose If true, more information is displayed.
    \param stream Output stream to write help.
    */
    inline void help(const aff3ct::runtime::Socket &sck, const bool& verbose = false, std::ostream& stream = std::cout);

    /*! Get the help string for a module.
    \param mdl A reference on the module.
    \param verbose If true, more information is displayed.
    \return The help string for the module object.
    */
    inline std::string get_help(const aff3ct::module::Module  &mdl, const bool & verbose = false);

    /*! Get the help string for a task.
    \param tsk A reference on the task.
    \param verbose If true, more information is displayed.
    \return The help string for the task object.
    */
    inline std::string get_help(const aff3ct::runtime::Task   &tsk, const bool & verbose = false);

    /*! Get the help string for a socket.
    \param sck A reference on the socket.
    \param verbose If true, more information is displayed.
    \return The help string for the socket object.
    */
    inline std::string get_help(const aff3ct::runtime::Socket &sck, const bool & verbose = false);
}
}
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#include "Tools/Help/Help.hxx"
#endif

#endif /* HELP_HPP_ */
