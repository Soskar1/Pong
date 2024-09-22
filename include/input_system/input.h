#ifndef INPUT_H
#define INPUT_H

#include <ArxSmartPtr.h>

#include "input_event.h"

namespace ArduinoPong {
    class Input {
        public:
            Input();

            virtual void read() = 0;
        
            void registerInputEvent(const std::shared_ptr<InputEvent>& inputEvent);
            std::shared_ptr<InputEvent> getInputEvent() const;
        private:
            std::shared_ptr<InputEvent> lastInputEvent;
    };
}

#endif