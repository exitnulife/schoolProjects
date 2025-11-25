#include "drawing.h"
#include <stdio.h>
#include <unistd.h>

//čáry
void BlueVerticalDashedLine(int size){
    for (int i = 0; i < size; i++){
        set_blue_color(); 
        draw_pixel(); 
        move_down(); move_down();
    }
}
void BlueHorizontalDashedLine(int size){
    for (int i = 0; i < size; i++){
        set_blue_color(); 
        draw_pixel(); 
        move_right(); move_right();
    }
}
void RedVerticalDashedLine(int size){
    for (int i = 0; i < size; i++){
        set_red_color(); 
        draw_pixel(); 
        move_down(); move_down();
    }
}
void RedHorizontalDashedLine(int size){
    for (int i = 0; i < size; i++){
        set_red_color(); 
        draw_pixel(); 
        move_right(); move_right();
    }
}
void GreenVerticalDashedLine(int size){
    for (int i = 0; i < size; i++){
        set_green_color(); 
        draw_pixel(); 
        move_down(); move_down();
    }
}
void GreenHorizontalDashedLine(int size){
    for (int i = 0; i < size; i++){
        set_green_color(); 
        draw_pixel(); 
        move_right(); move_right();
    }
}

//schody
void BlueStairs(int size){
    for (int i = 0; i < size; i++){
        for (int i = 0; i < size; i++){
            set_blue_color(); 
            draw_pixel(); 
            move_right();
        }
        for (int i = 0; i < size - 1; i++){
            set_blue_color(); 
            draw_pixel(); 
            move_down();
        }
    }
    for (int i = 0; i < size + 1; i++){
        set_blue_color(); 
        draw_pixel(); 
        move_right();
    }
}
void RedStairs(int size){
    for (int i = 0; i < size; i++){
        for (int i = 0; i < size; i++){
            set_red_color(); 
            draw_pixel(); 
            move_right();
        }
        for (int i = 0; i < size - 1; i++){
            set_red_color(); 
            draw_pixel(); 
            move_down();
        }
    }
    for (int i = 0; i < size + 1; i++){
        set_red_color(); 
        draw_pixel(); 
        move_right();
    }
}
void GreenStairs(int size){
    for (int i = 0; i < size; i++){
        for (int i = 0; i < size; i++){
            set_green_color(); 
            draw_pixel(); 
            move_right();
        }
        for (int i = 0; i < size - 1; i++){
            set_green_color(); 
            draw_pixel(); 
            move_down();
        }
    }
    for (int i = 0; i < size + 1; i++){
        set_green_color(); 
        draw_pixel(); 
        move_right();
    }
}


//kytka
void Flower(int width, int height){
    for (int i = 0; i < (height / 2) + 1; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == (height / 2) || j == 0 || j == width - 1) {
                set_white_color(); 
                draw_pixel();
                move_right();
            }
            else {
                set_yellow_color(); 
                draw_pixel();
                move_right();
            }   
        }
        for (int k = 0; k < width; k++){
            move_left(); 
        }
        move_down();
    }
    for (int i = 0; i < width / 2; i++) {
        move_right();
    }
    for (int i = 0; i < height / 2; i++) {
        set_green_color(); 
        draw_pixel();
        move_down();
    }
}

void FlowerFieldColumnFill(int width, int height){
    for (int i = 0; i < width - 1; i++) {
        move_right();
    }
    for (int i = 0; i < height; i++) {
        move_up();
    }
}

void FlowerField(int lineCount, int columnCount){
    int flowerWidth = 5;
    int flowerHeight = 5;
    for (int i = 0; i < lineCount; i++) {
        for (int j = 0; j < columnCount; j++) {
            Flower(flowerWidth, flowerHeight);
            FlowerFieldColumnFill(flowerWidth, flowerHeight);
        }
        for (int j = 0; j < flowerHeight + 1; j++) {
            printf("\n");
        }
    }
}

//animace
void Plane(){
    for (int i = 0; i < 3; i++) {
        set_white_color(); 
        draw_pixel();
        move_down();
    }
    move_right(); 
    move_up(); 
    move_up();
    for (int i = 0; i < 2; i++) {
        set_white_color(); 
        draw_pixel();
        move_down();
    }
    move_up();
    move_right();
    for (int i = 0; i < 16; i++) {
        set_white_color(); 
        draw_pixel();
        move_right();
    }
    set_blue_color(); 
    draw_pixel();
    move_right();
    draw_pixel();
    move_down();
    for (int i = 0; i < 18; i++) {
        move_left();
    }
    for (int i = 0; i < 20; i++) {
        set_red_color(); 
        draw_pixel();
        move_right();
    }
    for (int i = 0; i < 13; i++) {
        move_left();
    }
    for (int i = 0; i < 6; i++) {
        set_white_color(); 
        draw_pixel();
        move_right();
    }
    move_down();
    for (int i = 0; i < 7; i++) {
        move_left();
    }
    for (int i = 0; i < 6; i++) {
        set_white_color(); 
        draw_pixel();
        move_right();
    }
    move_down();
    for (int i = 0; i < 7; i++) {
        move_left();
    }
    for (int i = 0; i < 6; i++) {
        set_white_color(); 
        draw_pixel();
        move_right();
    }
    for (int i = 0; i < 4; i++) {
        move_up();
    }
    for (int i = 0; i < 4; i++) {
        move_left();
    }
    for (int i = 0; i < 6; i++) {
        set_white_color(); 
        draw_pixel();
        move_right();
    }
    move_up();
    for (int i = 0; i < 7; i++) {
        move_left();
    }
     for (int i = 0; i < 6; i++) {
        set_white_color(); 
        draw_pixel();
        move_right();
    }
}

void Towers(){
    move_to(2, 57);
    for (int i = 0; i < 18; i++) {
        set_white_color(); 
        draw_pixel();
        move_down();
    }
    move_to(2, 56);
    for (int i = 0; i < 18; i++) {
        set_white_color(); 
        draw_pixel();
        move_down();
    }
    move_to(2, 55);
    for (int i = 0; i < 18; i++) {
        set_white_color(); 
        draw_pixel();
        move_down();
    }
    move_to(3, 52);
    for (int i = 0; i < 18; i++) {
        set_white_color(); 
        draw_pixel();
        move_down();
    }
    move_to(3, 51);
    for (int i = 0; i < 18; i++) {
        set_white_color(); 
        draw_pixel();
        move_down();
    }
    move_to(3, 50);
    for (int i = 0; i < 18; i++) {
        set_white_color(); 
        draw_pixel();
        move_down();
    }
    move_to(2, 51);
    set_red_color(); 
    draw_pixel();
    move_up();
    set_white_color(); 
    draw_pixel();
    move_up();
    move_to(4, 51);
    for (int i = 0; i < 8; i++) {
        set_blue_color(); 
        draw_pixel();
        move_down();
        move_down();
    }
    move_to(3, 56);
    for (int i = 0; i < 8; i++) {
        set_blue_color(); 
        draw_pixel();
        move_down();
        move_down();
    }
}

void HalfFallenTowers(){
    move_to(8, 57);
    for (int i = 0; i < 12; i++) {
        set_white_color(); 
        draw_pixel();
        move_down();
    }
    move_to(8, 56);
    for (int i = 0; i < 12; i++) {
        set_white_color(); 
        draw_pixel();
        move_down();
    }
    move_to(8, 55);
    for (int i = 0; i < 12; i++) {
        set_white_color(); 
        draw_pixel();
        move_down();
    }
    move_to(9, 52);
    for (int i = 0; i < 12; i++) {
        set_white_color(); 
        draw_pixel();
        move_down();
    }
    move_to(9, 51);
    for (int i = 0; i < 12; i++) {
        set_white_color(); 
        draw_pixel();
        move_down();
    }
    move_to(9, 50);
    for (int i = 0; i < 12; i++) {
        set_white_color(); 
        draw_pixel();
        move_down();
    }
    move_to(8, 51);
    set_red_color(); 
    draw_pixel();
    move_up();
    set_white_color(); 
    draw_pixel();
    move_up();
    move_to(10, 51);
    for (int i = 0; i < 6; i++) {
        set_blue_color(); 
        draw_pixel();
        move_down();
        move_down();
    }
    move_to(9, 56);
    for (int i = 0; i < 6; i++) {
        set_blue_color(); 
        draw_pixel();
        move_down();
        move_down();
    } 
}

void LittleExplosion(){
    move_right();
    for (int i = 0; i < 5; i++) {
        set_red_color(); 
        draw_pixel();
        move_right();
    }
    move_down();
    for (int i = 0; i < 3; i++) {
        set_red_color(); 
        draw_pixel();
        move_down();
    }
    move_left();
    for (int i = 0; i < 5; i++) {
        set_red_color(); 
        draw_pixel();
        move_left();
    }
    move_up();
    for (int i = 0; i < 3; i++) {
        set_red_color(); 
        draw_pixel();
        move_up();
    }
    move_down();
    move_right();
    for (int i = 0; i < 5; i++) {
        for (int i = 0; i < 3; i++) {
            set_yellow_color(); 
            draw_pixel();
            move_down();
        }
        move_right();
        for (int i = 0; i < 3; i++) {
            move_up();
        }
    }
}

void BigExplosion(){
    move_right();
    for (int i = 0; i < 9; i++) {
        set_red_color(); 
        draw_pixel();
        move_right();
    }
    move_down();
    for (int i = 0; i < 5; i++) {
        set_red_color(); 
        draw_pixel();
        move_down();
    }
    move_left();
    for (int i = 0; i < 9; i++) {
        set_red_color(); 
        draw_pixel();
        move_left();
    }
    move_up();
    for (int i = 0; i < 5; i++) {
        set_red_color(); 
        draw_pixel();
        move_up();
    }
    move_down();
    move_right();
    for (int i = 0; i < 9; i++) {
        for (int i = 0; i < 5; i++) {
            set_yellow_color(); 
            draw_pixel();
            move_down();
        }
        move_right();
        for (int i = 0; i < 5; i++) {
            move_up();
        }
    }
}

void FullFallenTowers(){
    move_down();
    move_down();
    move_down();
    for (int i = 0; i < 9; i++) {
        set_white_color(); 
        draw_pixel();
        move_right();
    }
    move_up();
    move_left();
    draw_pixel();
    move_left();
    for (int i = 0; i < 2; i++) {
        draw_pixel();
        move_up();
    }
    move_down();
    move_down();
    move_left();
    draw_pixel();
    for (int i = 0; i < 3; i++) {
        move_left();
    }
    for (int i = 0; i < 3; i++) {
        draw_pixel();
        move_left();
    }
}

void Animation(){
    for (int i = 0; i < 1;) {
        //1
        move_to(6, 6);
        Plane();
        Towers();
        animate();
        clear_screen();
        //2
        move_to(6, 12);
        Plane();
        Towers();
        animate();
        clear_screen();
        //3
        move_to(6, 18);
        Plane();
        Towers();
        animate();
        clear_screen();
        //4
        move_to(6, 24);
        Plane();
        Towers();
        animate();
        clear_screen();
        //5
        move_to(6, 30);
        Plane();
        Towers();
        move_to(6, 47);
        LittleExplosion();
        animate();
        clear_screen();
        //6
        Towers();
        move_to(5, 44);
        BigExplosion();
        animate();
        clear_screen();
        //7
        Towers();
        move_to(6, 47);
        LittleExplosion();
        animate();
        clear_screen();
        //8
        HalfFallenTowers();
        move_to(6, 47);
        animate();
        clear_screen();
        //9
        move_to(17, 49);
        FullFallenTowers();
        animate();
        clear_screen();
    }
}

void Scene0(){
    //first letter
    move_to(3, 1);
    BlueVerticalDashedLine(5);
    BlueHorizontalDashedLine(5);
    //second letter
    move_to(3, 12);
    GreenVerticalDashedLine(6);
    move_to(13, 14);
    GreenHorizontalDashedLine(3);
    move_to(3, 14);
    GreenHorizontalDashedLine(3);
    move_to(3, 20);
    GreenVerticalDashedLine(6);
    //third letter
    move_to(3, 23);
    RedVerticalDashedLine(5);
    RedHorizontalDashedLine(5);
}

void Scene1(){
    //first stairs
    move_to(10, 5);
    RedStairs(3);
    //second stairs
    move_to(5, 19);
    GreenStairs(4);
    //third stairs
    move_to(1, 33);
    BlueStairs(5);
}

void Scene2(){
    //first flower
    move_to(3, 3);
    Flower(5, 5);
    //second flower
    move_to(4, 25);
    Flower(7, 7);
    //third flower
    move_to(12, 15);
    Flower(9, 9);
    //fourth flower
    move_to(5, 50);
    Flower(11, 11);
    //fifth flower
    move_to(15, 40);
    Flower(3, 3);
}

void Scene3(){
    move_to(6, 1);
    FlowerField(2, 8);
}

void Scene4(){
    Animation();
}

int main() {
    int drawing = 0;
    scanf("%d", &drawing);
    clear_screen();
    switch (drawing) {
        case 0:
            Scene0();
            break;
        case 1:
            Scene1();
            break;
        case 2:
            Scene2();
            break;
        case 3:
            Scene3();
            break;
        case 4:
            Scene4();
            break;
        default:
            printf("Neexistující scéna, akceptovatelné parametry jsou 0 až 4.\n");
            break;
    }
    end_drawing();
  return 0;
}
