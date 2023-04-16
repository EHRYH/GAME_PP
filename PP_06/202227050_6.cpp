//#define DEBUG
#include <iostream>
#include <conio.h>
#include <Windows.h>

// game_state == 0 �϶�
int print_title_screen()
{
    std::cout << "******************************************" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "*              ������ ����               *" << std::endl;
    std::cout << "*             (Snake  Bite)              *" << std::endl;

#ifdef DEBUG
    std::cout << "*            - ����� ��� -             *" << std::endl;
#else
    std::cout << "*                                        *" << std::endl;
#endif  
    std::cout << "*   1. ���� ����                         *" << std::endl;
    std::cout << "*   2. ���� ����                         *" << std::endl;
    std::cout << "*   3. ���� ��ŷ ����                    *" << std::endl;
    std::cout << "*   4. ���� ���� (esc)                   *" << std::endl;
    std::cout << "******************************************" << std::endl;

    return 0;
}

void gotoxy(int x, int y) {
    //x, y ��ǥ ����
    COORD pos = { x,y };
    //Ŀ�� �̵�
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int print_game_screen(int stage_width, int stage_height)
{


    for (int i = 0; i < stage_height; i++) {
        std::cout << "*";
    }
    std::cout << std::endl;
    for (int i = 0; i < stage_width - 2; i++) {
        std::cout << "*";
        for (int j = 0; j < stage_height - 2; j++) {
            std::cout << " ";


        }

            std::cout << "*";
            std::cout << std::endl;
        }

        for (int i = 0; i < stage_height; i++) {
            std::cout << "*";

        }
        return 0;
    }


    // game_state == 2 �϶�
    int print_introduction_screen()
    {
        std::cout << "******************************************" << std::endl;
        std::cout << "Ÿ��Ʋȭ������ ���ư����? (Y/N)" << std::endl;
        return 0;
    }

    int main()
    {
        int stage_size
        int game_state = 0;
        int is_game_running = 1;

        while (is_game_running)
        {
            char key_input = '0';
            switch (game_state)
            {
            case 0:
                print_title_screen();
                key_input = _getch();
                switch (key_input)
                {
                case '1':
                    game_state = 1;
                    break;
                case '2':
                    game_state = 2;
                    break;
                case '3':
                    break;
                case '4':
                    is_game_running = 0;
                    break;
                case 27:
                    is_game_running = 0;
                    break;
                default:
                    break;
                }
                break;
            case 1:
                
                std::cout << "�������� ����� �Է����ּ���. (���簢��)";
                key_input = _getch(stage_size);
                print_game_screen(stage_size, stage_size);
            case 2:
                print_introduction_screen();
                key_input = _getch();
                switch (key_input)
                {
                case 'y':
                    game_state = 0;
                    break;
                case 'n':
                    break;
                default:
                    break;
                }
                break;

            default:
                break;
            }


        }

        return 0;
    }