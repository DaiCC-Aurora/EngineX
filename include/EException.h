#ifndef EException_
#define EException_

namespace Engine {
    /*
     * @class EException
     * @brief The EException class is the base class of all Exceptions.
     */
    class EException {
    public:
        explicit EException(const char *err_string) noexcept;
        virtual ~EException() noexcept;

        virtual const char* what() noexcept;

    private:
        const char* err_msg;
    };
}

#endif