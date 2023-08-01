#ifndef EException_
#define EException_
#include <exception>
namespace Engine {
    /*
     * @class EException
     * @brief The EException class is the base class of all Exceptions.
     */
    class EException : public std::exception{
    public:
        explicit EException(const char *err_string) noexcept;
        ~EException() noexcept override;

        virtual const char* what() noexcept;

    private:
        const char* err_msg;
    };
}

#endif