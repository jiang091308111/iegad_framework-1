#ifndef __IEGAD_REDIS_EXCEPTION__
#define __IEGAD_REDIS_EXCEPTION__


#include <exception>
#include <string>


namespace iegad {
    namespace redis {



        class redis_exception : public std::exception {
        public:
            redis_exception(const std::string & errstr, int errcode)
                :
                std::exception(),
                errcode_(errcode),
                errstr_(errstr)
            {}

            virtual const char* what() const _NOEXCEPT{
                errstr_ = errstr_ + " : " + std::to_string(errcode_);
                return errstr_.c_str();
            }

        private:
            int errcode_;
            mutable std::string errstr_;
        }; // class redis_exception;



    } // namespace redis;
} // namespace iegad;


#endif // __IEGAD_REDIS_EXCEPTION__;
