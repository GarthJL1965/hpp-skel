#include <gzip.hpp>

#include <iostream>
#include <cassert>
#include "catch.hpp"

// static void test_version() {
//     std::clog << "test_version ... ";
//     assert(HELLOWORLD_VERSION_STRING == "1.0.0");
//     std::clog << "success!\n";
// }

TEST_CASE("successful compress") {
    std::string data = "hello";
    std::string value = gzip::compress(data);

    REQUIRE(value.size() > data.size());
}

TEST_CASE("successful decompress") {
    std::string data = "hello";
    std::string compressed_data = gzip::compress(data);
    std::string value = gzip::decompress(compressed_data);

    REQUIRE(value.size() == data.size());
}

TEST_CASE("invalid decompression")
{
    std::string data("this is a string that should be compressed data");
    // data is not compressed but we will try to decompress it

    CHECK_THROWS(gzip::decompress(data));
}

// These came from zlib tests
// TEST_CASE("round trip compression - zlib")
// {
//     std::string data("this is a sentence that will be compressed into something");
//     // CHECK(!gzip::is_compressed(data));
    
//     int strategy;

//     SECTION("strategy - invalid compression")
//     {
//         strategy = 99;
//         int level = Z_DEFAULT_COMPRESSION;

//         CHECK_THROWS(gzip::compress(data, level, strategy));
//     }
    
//     SECTION("compression level - invalid")
//     {
//         strategy = Z_DEFAULT_STRATEGY;
//         int level = 99;

//         CHECK_THROWS(gzip::compress(data, level, strategy));
//     }
// }

TEST_CASE("round trip compression - gzip")
{
    std::string data("this is a sentence that will be compressed into something");
    // Do we plan to create a bool method?
    // CHECK(!gzip::is_compressed(data));
    
    int strategy;

    SECTION("strategy - invalid compression")
    {
        strategy = 99;
        int level = Z_DEFAULT_COMPRESSION;

        CHECK_THROWS(gzip::compress(data, level, strategy));
    }

    SECTION("compression level - invalid")
    {
        strategy = Z_DEFAULT_STRATEGY;
        int level = 99;

        CHECK_THROWS(gzip::compress(data, level, strategy));
    }

    SECTION("strategy - default")
    {
        strategy = Z_DEFAULT_STRATEGY;

        SECTION("no compression")
        {
            int level = Z_NO_COMPRESSION;
            std::string compressed_data = gzip::compress(data, level, strategy);
            // CHECK(is_compressed(compressed_data));
            std::string new_data = gzip::decompress(compressed_data);
            CHECK(data == new_data);
        }

        SECTION("default compression level")
        {
            int level = Z_DEFAULT_COMPRESSION;
            std::string compressed_data = gzip::compress(data, level, strategy);
            // CHECK(gzip::is_compressed(compressed_data));
            std::string new_data = gzip::decompress(compressed_data);
            CHECK(data == new_data);
        }

        SECTION("compression level -- min to max")
        {
            for (int level = Z_BEST_SPEED; level <= Z_BEST_COMPRESSION; ++level)
            {
                std::string compressed_data = gzip::compress(data, level, strategy);
                // CHECK(gzip::is_compressed(compressed_data));
                std::string new_data = gzip::decompress(compressed_data);
                CHECK(data == new_data);
            }
        }
    }

    SECTION("strategy - filtered")
    {
        strategy = Z_FILTERED;

        SECTION("no compression")
        {
            int level = Z_NO_COMPRESSION;
            std::string compressed_data = gzip::compress(data, level, strategy);
            // CHECK(gzip::is_compressed(compressed_data));
            std::string new_data = gzip::decompress(compressed_data);
            CHECK(data == new_data);
        }

        SECTION("default compression level")
        {
            int level = Z_DEFAULT_COMPRESSION;
            std::string compressed_data = gzip::compress(data, level, strategy);
            // CHECK(gzip::is_compressed(compressed_data));
            std::string new_data = gzip::decompress(compressed_data);
            CHECK(data == new_data);
        }

        SECTION("compression level -- min to max")
        {
            for (int level = Z_BEST_SPEED; level <= Z_BEST_COMPRESSION; ++level)
            {
                std::string compressed_data = gzip::compress(data, level, strategy);
                // CHECK(gzip::is_compressed(compressed_data));
                std::string new_data = gzip::decompress(compressed_data);
                CHECK(data == new_data);
            }
        }
    }

    SECTION("strategy - huffman only")
    {
        strategy = Z_HUFFMAN_ONLY;

        SECTION("no compression")
        {
            int level = Z_NO_COMPRESSION;
            std::string compressed_data = gzip::compress(data, level, strategy);
            // CHECK(gzip::is_compressed(compressed_data));
            std::string new_data = gzip::decompress(compressed_data);
            CHECK(data == new_data);
        }

        SECTION("default compression level")
        {
            int level = Z_DEFAULT_COMPRESSION;
            std::string compressed_data = gzip::compress(data, level, strategy);
            // CHECK(gzip::is_compressed(compressed_data));
            std::string new_data = gzip::decompress(compressed_data);
            CHECK(data == new_data);
        }

        SECTION("compression level -- min to max")
        {
            for (int level = Z_BEST_SPEED; level <= Z_BEST_COMPRESSION; ++level)
            {
                std::string compressed_data = gzip::compress(data, level, strategy);
                // CHECK(gzip::is_compressed(compressed_data));
                std::string new_data = gzip::decompress(compressed_data);
                CHECK(data == new_data);
            }
        }
    }

    SECTION("strategy - rle")
    {
        strategy = Z_RLE;

        SECTION("no compression")
        {
            int level = Z_NO_COMPRESSION;
            std::string compressed_data = gzip::compress(data, level, strategy);
            // CHECK(gzip::is_compressed(compressed_data));
            std::string new_data = gzip::decompress(compressed_data);
            CHECK(data == new_data);
        }

        SECTION("default compression level")
        {
            int level = Z_DEFAULT_COMPRESSION;
            std::string compressed_data = gzip::compress(data, level, strategy);
            // CHECK(gzip::is_compressed(compressed_data));
            std::string new_data = gzip::decompress(compressed_data);
            CHECK(data == new_data);
        }

        SECTION("compression level -- min to max")
        {
            for (int level = Z_BEST_SPEED; level <= Z_BEST_COMPRESSION; ++level)
            {
                std::string compressed_data = gzip::compress(data, level, strategy);
                // CHECK(gzip::is_compressed(compressed_data));
                std::string new_data = gzip::decompress(compressed_data);
                CHECK(data == new_data);
            }
        }
    }

    SECTION("strategy - fixed")
    {
        strategy = Z_FIXED;

        SECTION("no compression")
        {
            int level = Z_NO_COMPRESSION;
            std::string compressed_data = gzip::compress(data, level, strategy);
            // CHECK(gzip::is_compressed(compressed_data));
            std::string new_data = gzip::decompress(compressed_data);
            CHECK(data == new_data);
        }

        SECTION("default compression level")
        {
            int level = Z_DEFAULT_COMPRESSION;
            std::string compressed_data = gzip::compress(data, level, strategy);
            // CHECK(gzip::is_compressed(compressed_data));
            std::string new_data = gzip::decompress(compressed_data);
            CHECK(data == new_data);
        }

        SECTION("compression level -- min to max")
        {
            for (int level = Z_BEST_SPEED; level <= Z_BEST_COMPRESSION; ++level)
            {
                std::string compressed_data = gzip::compress(data, level, strategy);
                // CHECK(gzip::is_compressed(compressed_data));
                std::string new_data = gzip::decompress(compressed_data);
                CHECK(data == new_data);
            }
        }
    }
}