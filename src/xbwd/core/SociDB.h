#pragma once

//------------------------------------------------------------------------------
/*
    This file is part of rippled: https://github.com/ripple/rippled
    Copyright (c) 2012-2015 Ripple Labs Inc.

    Permission to use, copy, modify, and/or distribute this software for any
    purpose  with  or without fee is hereby granted, provided that the above
    copyright notice and this permission notice appear in all copies.

    THE  SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
    WITH  REGARD  TO  THIS  SOFTWARE  INCLUDING  ALL  IMPLIED  WARRANTIES  OF
    MERCHANTABILITY  AND  FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
    ANY  SPECIAL ,  DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
    WHATSOEVER  RESULTING  FROM  LOSS  OF USE, DATA OR PROFITS, WHETHER IN AN
    ACTION  OF  CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
//==============================================================================

/** An embedded database wrapper with an intuitive, type-safe interface.

    This collection of classes let's you access embedded SQLite databases
    using C++ syntax that is very similar to regular SQL.

    This module requires the @ref beast_sqlite external module.
*/

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated"
#endif

#include <ripple/basics/Log.h>
#include <ripple/core/JobQueue.h>

#define SOCI_USE_BOOST
#include <cstdint>
#include <soci/soci.h>
#include <string>
#include <vector>

namespace sqlite_api {
struct sqlite3;
}

namespace xbwd {

/**
 *  Open a soci session.
 *
 *  @param s Session to open.
 *  @param beName Backend name.
 *  @param connectionString Connection string to forward to soci::open.
 *         see the soci::open documentation for how to use this.
 *
 */
void
open(
    soci::session& s,
    std::string const& beName,
    std::string const& connectionString);

std::uint32_t
getKBUsedAll(soci::session& s);
std::uint32_t
getKBUsedDB(soci::session& s);

void
convert(soci::blob& from, std::vector<std::uint8_t>& to);
void
convert(soci::blob& from, std::string& to);
void
convert(std::vector<std::uint8_t> const& from, soci::blob& to);
void
convert(std::string const& from, soci::blob& to);

}  // namespace xbwd

#if defined(__clang__)
#pragma clang diagnostic pop
#endif
