#include "test_helper.hpp"
#include <fstream>
#include <stdexcept>

namespace test_helper {
std::string loadDBCFile(const fs::path& dbcFileName)
{
    const auto path = fs::path{ DBC_DIR } / dbcFileName;

    std::fstream ff{ path.c_str() };

    std::string buff;
    std::copy(std::istreambuf_iterator<char>(ff), std::istreambuf_iterator<char>(), std::back_inserter(buff));

    ff.close();
    // if (buff.empty())
    //  throw std::runtime_error(fmt::format("File {} does not exists", path.string()));
    return buff;
}
} // namespace test_helper
