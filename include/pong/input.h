#ifndef INPUT_H
#define INPUT_H

namespace ArduinoPong {
    class Input {
        public:
            Input();

            virtual void read() = 0;
        
            void registerInput(const float& value);
            float getInputValue() const;
        private:
            float inputValue;
    };
}

#endif