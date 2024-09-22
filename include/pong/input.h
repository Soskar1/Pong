#ifndef INPUT_H
#define INPUT_H

namespace ArduinoPong {
    class Input {
        public:
            Input() { };

            virtual float read() const = 0;
    };
}

#endif