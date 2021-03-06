/**
 *   Copyright 2019 Rajdeep Roy Chowdhury <rrajdeeproychowdhury@gmail.com>
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */

#ifndef __BASE_EXCEPTION_H
#define __BASE_EXCEPTION_H

#include <iostream>
#include <exception>

namespace cpsk {
    namespace exceptions {
        class InvalidConstructor : public std::exception {
        public:
            InvalidConstructor() {
                std::cout << "Invalid Constructor Exception" << std::endl;
            }

            const char *what() const noexcept override {
                return "Invalid Constructor Exception";
            }
        };

        class FileNotFoundException : public std::exception {
        public:
            FileNotFoundException() {
                std::cout << "FileNotFound Exception" << std::endl;
            }

            const char *what() const noexcept override {
                return "FileNotFound Exception";
            }
        };

        class FileCreationException : public std::exception {
        public:
            FileCreationException() {
                std::cout << "FileCreation Exception" << std::endl;
            }

            const char *what() const noexcept override {
                return "FileCreation Exception";
            }
        };

        class FileNameException : public std::exception {
        public:
            FileNameException() {
                std::cout << "FileName Exception" << std::endl;
            }

            const char *what() const noexcept override {
                return "FileName Exception";
            }
        };

        class BaseException : public std::exception {
            std::string message;
        public:
            BaseException() {
                InvalidConstructor();
            }

            BaseException(int a) {
                InvalidConstructor();
            }

            const char *what() const noexcept override {
                return "Base Exception";
            }

            explicit BaseException(std::string message) : message(message) {}

        };
    }; // namespace exceptions
}; // namespace cpsk
#endif
