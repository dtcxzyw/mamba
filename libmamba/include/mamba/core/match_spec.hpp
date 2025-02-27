// Copyright (c) 2019, QuantStack and Mamba Contributors
//
// Distributed under the terms of the BSD 3-Clause License.
//
// The full license is in the file LICENSE, distributed with this software.

#ifndef MAMBA_CORE_MATCH_SPEC
#define MAMBA_CORE_MATCH_SPEC

#include <string>
#include <tuple>
#include <unordered_map>

namespace mamba
{
    class MatchSpec
    {
    public:

        MatchSpec() = default;
        MatchSpec(const std::string& i_spec);

        void parse();
        std::string conda_build_form() const;
        std::string str() const;

        bool is_simple() const;

        static std::tuple<std::string, std::string> parse_version_and_build(const std::string& s);
        std::string spec;

        std::string name;
        std::string version;
        std::string channel;
        std::string ns;
        std::string subdir;
        std::string build;
        std::string fn;
        std::string url;
        std::string build_number;

        bool is_file = false;
        bool optional = false;
        std::unordered_map<std::string, std::string> brackets;
        std::unordered_map<std::string, std::string> parens;
    };
}  // namespace mamba

#endif
