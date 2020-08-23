#pragma once

class SystemMessage {
public:
    SystemMessage();

    void MenuItem();

    void Render();

private:
    bool bShow;
    float m_color[3];
    char m_buffer[200];
};
