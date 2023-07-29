#ifndef EObject_
#define EObject_

#include "EEvent.h"

namespace Engine {
    /*
     * @class EObject
     * @brief The EObject class is the base class of all Engine objects.
     */
    class EObject {
    public:
        explicit EObject(EObject* parent = nullptr);
        virtual ~EObject();

        /*
         * @brief connect signals
         * @param sender - sender
         * @param receive - receive
         * @param signal - signal
         * @return complete or not
         */
        static bool connect(EObject* sender, void(*receive)(), Engine::Event signal);
    protected:
    };
}

#endif