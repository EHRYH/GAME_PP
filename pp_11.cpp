#include <iostream>
#include <vector>

namespace MuSoeun
{
    class Component;

    class Object
    {
    public:
        int posX = 0;
        int posY = 0;
        float scale = 1.0f;
        float rotation = 0.0f;
        std::vector<Component*> componentList;

        virtual void Render(char* screenBuf) {}

        virtual void Start()
        {
            for (Component* component : componentList)
            {
                component->Start();
            }
        }

        virtual void Update()
        {
            for (Component* component : componentList)
            {
                component->Update();
            }
        }
    };

    class Component
    {
    public:
        virtual void Start() {}
        virtual void Update() {}
    };

    class Scene
    {
    public:
        int width = 0;
        int height = 0;
        std::vector<Object*> objList;
        char* screenBuf = nullptr;

        void InitScreenBuf()
        {
            screenBuf = new char[(width + 1) * height + 5]();
        }

        void ClearScreenBuf()
        {
            for (int i = 0; i < (width + 1) * height + 5; i++)
            {
                screenBuf[i] = ' ';
            }
        }

        void Draw()
        {
            ClearScreenBuf();

            for (Object* obj : objList)
            {
                obj->Render(screenBuf);
            }

            std::cout << screenBuf;
        }
    };

    class SnakeBody : public Object
    {
        // SnakeBody 특화된 기능을 구현할 수 있음
        void Start() override
        {
            std::cout << "SnakeBody Start" << std::endl;
        }

        void Update() override
        {
            std::cout << "SnakeBody Update" << std::endl;
        }
    };

    class SnakeMovement : public Component
    {
        // Snake의 움직임을 제어하는 기능을 구현할 수 있음
        void Start() override
        {
            std::cout << "SnakeMovement Start" << std::endl;
        }

        void Update() override
        {
            std::cout << "SnakeMovement Update" << std::endl;
        }
    };

    class SnakeController : public Component
    {
        // Snake의 입력을 받아 처리하는 기능을 구현할 수 있음
        void Start() override
        {
            std::cout << "SnakeController Start" << std::endl;
        }

        void Update() override
        {
            std::cout << "SnakeController Update" << std::endl;
        }
    };
}

int main()
{
    MuSoeun::Scene scene;
    scene.width = 10;
    scene.height = 5;
    scene.InitScreenBuf();

    MuSoeun::SnakeBody snakeBody;
    snakeBody.posX = 5;
    snakeBody.posY = 2;

    MuSoeun::SnakeMovement snakeMovement;
    snakeBody.componentList.push_back(&snakeMovement);

    MuSoeun::SnakeController snakeController;
    snakeBody.componentList.push_back(&snakeController);

    scene.objList.push_back(&snakeBody);

    for (MuSoeun::Object* obj : scene.objList)
    {
        obj->Start();
    }

    while (true)
    {
        scene.Draw();

        for (MuSoeun::Object* obj : scene.objList)
        {
            obj->Update();
        }
    }

    return 0;
}