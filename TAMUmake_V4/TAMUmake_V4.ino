// TAMUmake 2019
// IEEE | TAMU
// Team Raaje with an AJ
// Version 3

#include <LiquidCrystal.h>
#include <PCM.h>

// initialize the library with the numbers of the interface pins
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 6;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// alarm sound file
const unsigned char sample[] PROGMEM = {
  124, 124, 126, 125, 125, 124, 125, 126, 125, 126, 127, 127, 128, 127, 127, 128, 128, 129, 128, 128, 128, 130, 128, 127, 127, 127, 128, 126, 127, 128, 126, 126, 126, 127, 126, 126, 125, 126, 127, 127, 127, 127, 128, 128, 128, 129, 130, 129, 130, 128, 130, 129, 128, 130, 129, 130, 129, 130, 129, 127, 127, 127, 126, 127, 126, 127, 127, 126, 127, 126, 125, 125, 124, 125, 125, 125, 126, 126, 126, 127, 127, 128, 128, 128, 129, 129, 128, 128, 129, 128, 129, 127, 127, 126, 127, 125, 125, 124, 123, 124, 122, 124, 122, 123, 122, 123, 125, 125, 125, 124, 125, 125, 125, 125, 125, 125, 125, 126, 127, 126, 125, 126, 125, 125, 126, 125, 125, 124, 125, 125, 125, 124, 124, 126, 125, 126, 126, 124, 126, 126, 126, 127, 127, 129, 129, 129, 130, 130, 131, 132, 131, 132, 132, 132, 132, 131, 131, 133, 132, 131, 131, 132, 132, 131, 132, 131, 132, 130, 130, 129, 130, 130, 129, 130, 130, 129, 130, 130, 131, 132, 131, 132, 133, 132, 133, 133, 132, 132, 131, 131, 131, 131, 130, 130, 129, 128, 127, 127, 128, 127, 129, 128, 128, 128, 127, 128, 128, 127, 126, 128, 128, 128, 128, 128, 129, 129, 129, 129, 129, 129, 129, 129, 129, 129, 128, 128, 129, 129, 128, 127, 128, 127, 127, 126, 125, 125, 126, 127, 128, 127, 127, 128, 127, 127, 128, 127, 128, 130, 129, 130, 130, 130, 130, 132, 132, 132, 131, 130, 131, 131, 130, 129, 129, 129, 128, 129, 130, 130, 128, 129, 129, 128, 128, 128, 129, 129, 128, 128, 130, 129, 130, 130, 131, 131, 131, 132, 131, 132, 130, 130, 129, 129, 128, 128, 129, 128, 127, 126, 127, 125, 126, 126, 126, 126, 125, 126, 124, 125, 126, 125, 126, 127, 126, 127, 128, 127, 128, 128, 129, 127, 127, 126, 124, 126, 126, 125, 125, 124, 123, 124, 123, 124, 124, 123, 124, 123, 124, 123, 123, 123, 123, 122, 124, 124, 124, 124, 124, 125, 124, 126, 125, 125, 125, 125, 125, 124, 124, 125, 124, 124, 125, 124, 124, 124, 125, 124, 124, 123, 123, 122, 122, 122, 123, 123, 123, 123, 125, 126, 126, 125, 126, 128, 127, 127, 127, 128, 128, 128, 128, 128, 128, 127, 127, 127, 127, 126, 127, 127, 127, 126, 126, 126, 127, 126, 125, 125, 125, 125, 126, 126, 127, 126, 126, 127, 128, 129, 129, 129, 129, 130, 128, 128, 129, 129, 129, 127, 128, 127, 126, 127, 127, 126, 124, 124, 125, 123, 124, 123, 126, 125, 125, 125, 125, 127, 125, 127, 126, 129, 129, 128, 128, 128, 128, 127, 127, 127, 128, 127, 126, 126, 126, 126, 126, 125, 124, 125, 124, 125, 125, 126, 126, 125, 126, 127, 128, 126, 127, 127, 127, 128, 127, 128, 127, 128, 128, 128, 129, 128, 128, 127, 126, 126, 125, 125, 126, 125, 125, 125, 124, 123, 124, 124, 124, 124, 124, 125, 125, 126, 127, 126, 127, 126, 128, 129, 130, 130, 129, 129, 130, 131, 130, 130, 131, 129, 128, 128, 128, 127, 126, 127, 125, 125, 125, 127, 126, 125, 126, 125, 125, 124, 125, 126, 127, 128, 127, 128, 129, 129, 129, 130, 132, 130, 130, 130, 130, 131, 130, 130, 131, 130, 130, 128, 128, 129, 128, 129, 128, 129, 129, 129, 128, 129, 130, 129, 129, 132, 130, 131, 132, 131, 131, 132, 133, 133, 134, 133, 132, 133, 132, 131, 132, 132, 131, 129, 129, 128, 127, 127, 127, 127, 127, 127, 126, 126, 127, 127, 126, 125, 127, 126, 125, 125, 126, 127, 127, 127, 126, 128, 128, 129, 128, 128, 128, 127, 129, 128, 128, 129, 128, 128, 127, 127, 127, 127, 126, 127, 127, 126, 127, 127, 127, 128, 127, 127, 129, 129, 129, 130, 130, 129, 129, 129, 130, 131, 131, 131, 130, 130, 128, 129, 128, 127, 127, 125, 125, 125, 124, 125, 124, 124, 124, 124, 125, 124, 126, 124, 126, 127, 126, 127, 128, 129, 128, 129, 129, 130, 129, 128, 128, 128, 129, 127, 126, 125, 126, 125, 126, 126, 125, 124, 124, 125, 124, 124, 122, 126, 124, 124, 125, 125, 128, 127, 129, 127, 127, 127, 128, 128, 129, 131, 129, 131, 130, 129, 130, 128, 128, 127, 128, 129, 128, 129, 128, 128, 128, 128, 128, 129, 129, 129, 129, 128, 129, 128, 130, 130, 129, 131, 131, 131, 132, 133, 133, 132, 132, 131, 132, 132, 131, 131, 132, 129, 129, 131, 130, 129, 129, 129, 129, 127, 128, 127, 129, 131, 130, 130, 131, 130, 130, 131, 128, 129, 130, 131, 130, 131, 131, 132, 130, 127, 128, 128, 126, 127, 126, 126, 127, 125, 126, 125, 125, 122, 125, 124, 123, 125, 125, 123, 122, 123, 122, 123, 123, 123, 124, 126, 126, 122, 125, 124, 124, 123, 125, 124, 124, 125, 121, 123, 118, 121, 120, 120, 119, 118, 119, 119, 120, 120, 120, 121, 119, 121, 122, 124, 126, 124, 126, 124, 129, 123, 130, 124, 131, 125, 131, 127, 132, 124, 130, 125, 129, 128, 131, 126, 123, 129, 119, 136, 113, 148, 47, 202, 178, 110, 92, 55, 146, 77, 220, 123, 216, 213, 33, 20, 11, 156, 161, 242, 156, 145, 222, 32, 1, 49, 170, 162, 173, 203, 81, 203, 132, 16, 60, 108, 219, 137, 167, 101, 135, 226, 52, 57, 68, 179, 164, 163, 123, 102, 255, 93, 33, 46, 161, 203, 140, 157, 70, 211, 176, 23, 28, 122, 209, 157, 160, 69, 167, 212, 54, 27, 69, 193, 169, 190, 110, 96, 230, 80, 32, 51, 167, 196, 178, 162, 65, 210, 129, 32, 37, 127, 210, 164, 191, 67, 173, 172, 30, 33, 86, 204, 163, 201, 89, 127, 217, 53, 25, 48, 185, 176, 202, 141, 86, 221, 88, 21, 39, 156, 188, 183, 183, 72, 214, 133, 12, 27, 108, 202, 172, 209, 84, 173, 177, 22, 21, 78, 198, 167, 220, 115, 121, 214, 47, 21, 58, 180, 176, 201, 160, 85, 227, 97, 10, 40, 155, 188, 176, 195, 76, 202, 150, 8, 30, 93, 222, 165, 195, 112, 111, 223, 38, 26, 67, 174, 193, 170, 149, 76, 231, 111, 13, 41, 128, 213, 154, 183, 76, 187, 190, 5, 15, 82, 215, 185, 179, 102, 124, 214, 52, 3, 51, 184, 196, 194, 139, 70, 216, 97, 14, 40, 133, 214, 183, 184, 64, 173, 153, 21, 41, 97, 208, 174, 202, 90, 129, 194, 32, 31, 68, 197, 184, 189, 125, 87, 218, 78, 15, 43, 162, 203, 181, 172, 67, 204, 131, 14, 42, 123, 213, 170, 196, 77, 167, 176, 25, 36, 84, 215, 173, 203, 105, 117, 208, 48, 34, 58, 191, 185, 189, 152, 81, 213, 87, 25, 46, 154, 203, 172, 190, 73, 188, 140, 21, 44, 112, 207, 164, 199, 93, 147, 186, 32, 40, 70, 206, 176, 177, 144, 80, 220, 77, 23, 57, 144, 221, 151, 172, 70, 183, 171, 19, 44, 97, 213, 163, 182, 92, 142, 227, 40, 22, 50, 196, 204, 170, 132, 91, 219, 106, 7, 29, 159, 213, 178, 162, 58, 195, 149, 22, 30, 98, 226, 173, 191, 79, 131, 205, 42, 31, 64, 199, 187, 191, 127, 86, 209, 76, 26, 44, 167, 205, 171, 167, 60, 193, 132, 18, 37, 118, 217, 169, 191, 72, 149, 185, 37, 30, 79, 214, 178, 196, 103, 107, 215, 62, 29, 51, 187, 196, 190, 144, 67, 216, 105, 24, 36, 145, 213, 172, 189, 65, 185, 149, 20, 37, 97, 222, 168, 200, 90, 139, 201, 32, 33, 63, 205, 184, 191, 134, 92, 223, 73, 27, 48, 160, 206, 172, 171, 64, 208, 135, 15, 48, 93, 234, 161, 178, 92, 122, 220, 39, 36, 70, 184, 183, 171, 131, 93, 236, 90, 21, 39, 142, 220, 166, 163, 77, 192, 156, 19, 21, 103, 220, 179, 179, 76, 143, 194, 44, 33, 60, 201, 187, 183, 117, 83, 221, 84, 33, 44, 152, 204, 176, 169, 63, 194, 137, 28, 41, 114, 211, 163, 191, 77, 147, 184, 31, 38, 76, 204, 175, 184, 113, 97, 214, 71, 31, 48, 172, 195, 180, 158, 69, 209, 116, 22, 42, 135, 206, 176, 184, 65, 183, 165, 21, 35, 96, 205, 170, 195, 91, 134, 204, 41, 29, 67, 191, 172, 186, 136, 94, 223, 78, 23, 43, 156, 196, 171, 176, 74, 204, 137, 20, 40, 113, 202, 163, 195, 83, 158, 191, 23, 43, 65, 203, 181, 171, 136, 80, 225, 82, 24, 60, 150, 203, 153, 168, 67, 203, 160, 25, 42, 99, 217, 155, 179, 92, 149, 218, 43, 19, 61, 203, 192, 173, 116, 91, 218, 95, 23, 36, 161, 209, 175, 159, 54, 195, 148, 31, 39, 101, 214, 172, 193, 77, 132, 195, 45, 37, 70, 198, 180, 197, 125, 84, 209, 71, 34, 52, 168, 201, 169, 167, 59, 197, 132, 28, 40, 113, 217, 169, 191, 73, 156, 184, 39, 38, 72, 208, 178, 200, 106, 111, 218, 57, 33, 49, 178, 196, 190, 147, 74, 217, 100, 25, 40, 143, 202, 174, 187, 65, 189, 146, 29, 41, 98, 214, 162, 200, 91, 137, 196, 40, 40, 71, 195, 176, 191, 135, 93, 213, 73, 34, 51, 158, 203, 159, 178, 65, 190, 142, 18, 58, 103, 217, 155, 175, 95, 125, 211, 54, 43, 70, 187, 175, 171, 135, 91, 228, 97, 27, 44, 145, 217, 164, 159, 79, 178, 162, 33, 27, 113, 209, 177, 180, 78, 138, 195, 58, 39, 66, 190, 185, 186, 123, 86, 212, 91, 37, 48, 156, 201, 175, 169, 64, 191, 136, 31, 44, 117, 212, 161, 185, 74, 149, 189, 39, 40, 74, 200, 172, 180, 109, 100, 216, 81, 39, 48, 166, 188, 180, 155, 74, 210, 120, 37, 43, 131, 202, 167, 182, 70, 177, 165, 36, 43, 93, 199, 167, 191, 95, 129, 195, 57, 39, 68, 189, 168, 188, 135, 87, 213, 87, 36, 53, 157, 192, 168, 172, 73, 190, 139, 33, 45, 116, 202, 156, 193, 88, 143, 191, 33, 44, 73, 199, 177, 163, 138, 83, 214, 96, 26, 61, 151, 191, 159, 167, 77, 204, 154, 24, 41, 100, 213, 164, 176, 99, 145, 202, 48, 15, 71, 199, 188, 182, 118, 96, 212, 90, 24, 38, 159, 207, 176, 163, 62, 193, 143, 31, 35, 104, 218, 174, 194, 79, 140, 185, 45, 36, 67, 207, 179, 192, 116, 92, 206, 71, 34, 47, 175, 197, 176, 154, 61, 200, 124, 35, 37, 126, 209, 168, 189, 69, 162, 169, 42, 37, 89, 208, 167, 198, 97, 118, 204, 55, 35, 61, 182, 186, 187, 137, 82, 203, 95, 31, 51, 152, 193, 175, 172, 65, 188, 137, 31, 50, 113, 206, 165, 190, 82, 145, 186, 45, 44, 81, 196, 167, 190, 119, 98, 213, 68, 42, 52, 162, 207, 154, 168, 63, 186, 148, 31, 57, 101, 211, 155, 176, 89, 139, 213, 52, 47, 58, 187, 180, 167, 136, 96, 226, 101, 20, 37, 149, 207, 167, 159, 76, 187, 156, 31, 26, 107, 212, 169, 185, 76, 135, 200, 51, 38, 57, 198, 186, 185, 127, 85, 212, 87, 39, 42, 158, 200, 172, 170, 66, 192, 126, 30, 42, 119, 211, 163, 186, 72, 156, 182, 41, 40, 70, 203, 172, 192, 111, 105, 214, 71, 35, 46, 177, 183, 187, 156, 75, 216, 109, 26, 35, 138, 202, 178, 190, 69, 178, 158, 31, 32, 102, 205, 167, 207, 90, 132, 198, 43, 36, 69, 200, 172, 193, 140, 84, 220, 79, 28, 55, 164, 191, 168, 183, 71, 195, 135, 19, 48, 115, 210, 156, 191, 94, 133, 201, 34, 44, 76, 189, 180, 166, 139, 85, 221, 97, 32, 56, 140, 195, 162, 171, 80, 203, 155, 27, 34, 96, 211, 174, 180, 94, 143, 195, 56, 22, 66, 195, 188, 189, 116, 90, 214, 88, 33, 38, 152, 211, 176, 167, 63, 186, 144, 36, 35, 106, 214, 174, 196, 82, 141, 181, 41, 37, 78, 205, 179, 187, 115, 93, 208, 77, 30, 55, 171, 193, 176, 154, 69, 199, 125, 34, 40, 131, 199, 170, 193, 73, 170, 165, 38, 35, 96, 204, 169, 202, 96, 126, 196, 53, 30, 65, 187, 179, 196, 136, 85, 205, 86, 30, 49, 158, 195, 177, 176, 66, 189, 134, 32, 45, 118, 209, 165, 197, 79, 144, 185, 42, 41, 81, 202, 171, 184, 120, 89, 214, 78, 35, 58, 159, 209, 155, 163, 61, 186, 161, 27, 56, 106, 204, 163, 179, 86, 150, 210, 46, 38, 60, 194, 188, 178, 125, 98, 219, 90, 18, 43, 159, 205, 181, 151, 69, 197, 136, 29, 33, 105, 219, 176, 184, 74, 142, 192, 44, 39, 68, 196, 188, 192, 115, 97, 205, 76, 34, 47, 169, 198, 181, 154, 63, 198, 122, 28, 42, 127, 211, 170, 182, 67, 158, 177, 40, 37, 83, 203, 171, 199, 106, 112, 203, 61, 33, 59, 185, 179, 194, 147, 80, 209, 94, 27, 40, 151, 196, 177, 185, 69, 183, 137, 28, 38, 107, 206, 163, 204, 88, 141, 180, 36, 41, 70, 202, 167, 198, 131, 93, 208, 67, 36, 55, 167, 187, 174, 168, 70, 195, 124, 28, 48, 117, 212, 156, 184, 87, 133, 198, 44, 48, 77, 187, 172, 170, 131, 93, 227, 98, 34, 46, 143, 198, 162, 167, 80, 203, 162, 23, 27, 98, 210, 180, 170, 90, 144, 198, 60, 16, 63, 195, 190, 187, 112, 86, 214, 96, 34, 40, 152, 207, 177, 159, 67, 186, 143, 44, 37, 115, 205, 166, 185, 77, 144, 178, 50, 38, 81, 199, 171, 184, 105, 97, 206, 80, 38, 52, 170, 185, 178, 152, 67, 200, 119, 39, 44, 137, 198, 169, 190, 63, 170, 161, 36, 41, 100, 206, 164, 200, 87, 119, 202, 48, 37, 70, 193, 176, 185, 137, 78, 211, 86, 28, 54, 166, 191, 165, 179, 64, 194, 135, 25, 46, 128, 209, 149, 197, 83, 147, 188, 31, 42, 85, 204, 164, 173, 133, 86, 218, 78, 29, 69, 158, 199, 145, 170, 73, 188, 163, 28, 53, 109, 200, 149, 182, 93, 151, 215, 45, 35, 60, 190, 187, 166, 131, 99, 215, 104, 16, 40, 156, 204, 176, 157, 68, 193, 147, 32, 38, 100, 214, 172, 187, 84, 136, 190, 47, 43, 70, 199, 175, 185, 126, 94, 210, 71, 35, 55, 168, 196, 165, 162, 65, 198, 128, 27, 47, 121, 212, 159, 183, 71, 148, 184, 37, 44, 84, 201, 169, 190, 109, 109, 208, 59, 38, 60, 180, 181, 178, 151, 77, 210, 98, 30, 46, 142, 202, 162, 189, 70, 178, 150, 23, 53, 103, 207, 159, 194, 97, 133, 192, 41, 46, 80, 199, 163, 186, 135, 92, 214, 76, 36, 61, 163, 186, 163, 172, 68, 200, 133, 25, 56, 105, 222, 150, 182, 87, 129, 212, 42, 52, 70, 188, 173, 171, 131, 90, 238, 92, 31, 41, 144, 208, 162, 165, 72, 198, 158, 24, 26, 103, 216, 177, 182, 75, 142, 200, 46, 28, 55, 202, 189, 190, 123, 78, 221, 79, 33, 42, 160, 210, 172, 174, 64, 193, 131, 27, 35, 120, 221, 167, 193, 74, 148, 180, 35, 38, 73, 211, 180, 187, 115, 95, 212, 69, 36, 45, 173, 197, 185, 163, 65, 205, 105, 35, 44, 127, 212, 174, 188, 72, 172, 156, 34, 36, 88, 209, 176, 202, 96, 123, 194, 44, 41, 60, 183, 184, 194, 139, 82, 208, 76, 34, 57, 153, 196, 177, 178, 68, 194, 133, 25, 54, 118, 200, 165, 198, 82, 152, 184, 30, 49, 72, 201, 177, 179, 130, 81, 219, 82, 37, 60, 147, 203, 156, 168, 67, 198, 159, 33, 50, 90, 213, 163, 178, 94, 143, 212, 51, 25, 57, 192, 196, 171, 119, 94, 211, 103, 26, 35, 149, 214, 176, 154, 63, 188, 148, 36, 37, 96, 216, 173, 186, 82, 137, 194, 47, 37, 67, 194, 184, 182, 123, 95, 208, 78, 30, 50, 159, 201, 169, 157, 71, 196, 129, 34, 38, 114, 209, 166, 191, 77, 160, 177, 40, 44, 79, 202, 170, 190, 117, 117, 204, 66, 37, 54, 180, 183, 178, 151, 82, 207, 106, 34, 45, 138, 197, 169, 184, 77, 179, 149, 34, 45, 102, 204, 164, 197, 95, 141, 195, 46, 44, 75, 192, 174, 190, 130, 101, 218, 78, 35, 57, 159, 206, 163, 173, 70, 190, 155, 20, 63, 101, 218, 167, 173, 97, 131, 221, 55, 46, 67, 189, 180, 175, 137, 93, 239, 99, 28, 38, 143, 221, 168, 164, 76, 192, 163, 34, 25, 99, 224, 177, 185, 78, 136, 205, 53, 38, 54, 197, 191, 184, 130, 82, 216, 90, 37, 41, 150, 208, 167, 177, 69, 186, 141, 29, 40, 108, 209, 166, 185, 79, 146, 187, 46, 36, 69, 195, 173, 191, 115, 91, 218, 81, 35, 47, 165, 193, 177, 165, 64, 204, 129, 30, 40, 129, 206, 165, 185, 66, 169, 176, 35, 35, 90, 204, 165, 197, 95, 118, 204, 52, 37, 69, 192, 172, 194, 137, 77, 215, 84, 34, 56, 167, 192, 174, 177, 62, 194, 139, 26, 49, 121, 207, 162, 190, 85, 139, 195, 31, 44, 77, 198, 183, 163, 134, 76, 217, 100, 21, 65, 152, 192, 161, 164, 73, 202, 156, 25, 33, 98, 220, 159, 179, 97, 137, 202, 46, 21, 63, 196, 185, 181, 117, 86, 212, 87, 32, 38, 149, 202, 167, 165, 55, 187, 143, 32, 42, 102, 207, 159, 190, 77, 137, 182, 45, 38, 68, 201, 167, 188, 114, 90, 204, 71, 33, 49, 166, 186, 173, 152, 61, 199, 128, 27, 40, 126, 192, 168, 187, 68, 163, 172, 34, 36, 95, 194, 165, 196, 98, 114, 203, 56, 25, 63, 180, 178, 185, 142, 79, 203, 91, 26, 50, 149, 191, 166, 178, 68, 186, 138, 22, 46, 113, 200, 162, 193, 85, 145, 190, 38, 38, 82, 191, 166, 185, 126, 95, 218, 75, 26, 54, 153, 209, 157, 167, 64, 186, 165, 14, 58, 103, 205, 159, 167, 99, 132, 222, 57, 35, 67, 187, 182, 160, 134, 87, 228, 117, 16, 43, 148, 211, 165, 153, 76, 179, 166, 31, 28, 106, 213, 172, 175, 80, 127, 206, 50, 38, 68, 192, 190, 178, 126, 80, 209, 92, 35, 49, 163, 207, 170, 166, 59, 189, 138, 31, 41, 118, 222, 165, 184, 73, 140, 188, 47, 34, 74, 207, 179, 190, 113, 98, 213, 73, 30, 55, 174, 202, 187, 153, 76, 205, 115, 27, 44, 133, 212, 182, 185, 73, 172, 162, 28, 40, 104, 209, 172, 198, 101, 131, 191, 45, 42, 75, 198, 175, 184, 143, 93, 206, 83, 36, 57, 165, 193, 164, 170, 79, 194, 137, 33, 47, 117, 218, 160, 181, 94, 133, 202, 44, 50, 83, 196, 186, 160, 140, 84, 221, 108, 40, 59, 146, 204, 152, 172, 76, 196, 167, 38, 34, 94, 216, 170, 181, 93, 133, 202, 67, 23, 64, 193, 186, 189, 124, 79, 212, 105, 33, 48, 152, 208, 172, 176, 59, 179, 166, 36, 41, 108, 216, 170, 193, 83, 135, 198, 46, 34, 74, 205, 182, 186, 120, 82, 218, 88, 16, 50, 176, 201, 172, 162, 58, 206, 142, 13, 37, 131, 217, 159, 190, 74, 162, 186, 30, 26, 88, 211, 173, 195, 102, 116, 199, 65, 18, 59, 177, 188, 195, 147, 95, 153, 94, 26, 73, 163, 196, 190, 137, 73, 108, 124, 87, 115, 159, 173, 142, 128, 96, 96, 137, 123, 124, 122, 144, 149, 139, 109, 116, 130, 102, 114, 118, 136, 132, 155, 141, 108, 124, 108, 107, 123, 138, 131, 139, 145, 133, 120, 114, 114, 117, 125, 129, 138, 138, 139, 138, 122, 103, 104, 114, 132, 142, 142, 146, 132, 115, 103, 105, 119, 134, 144, 138, 126, 128, 120, 112, 118, 120, 125, 134, 134, 131, 129, 122, 116, 112, 126, 128, 127, 135, 130, 123, 118, 122, 122, 121, 123, 132, 127, 125, 126, 122, 124, 117, 123, 123, 134, 130, 123, 129, 126, 125, 118, 121, 120, 133, 137, 127, 125, 121, 124, 114, 120, 127, 130, 134, 127, 119, 117, 122, 120, 115, 119, 133, 134, 127, 128, 119, 121, 121, 113, 121, 131, 139, 133, 129, 129, 121, 118, 116, 125, 134, 137, 133, 131, 128, 119, 116, 118, 131, 130, 129, 131, 129, 123, 121, 120, 116, 133, 134, 132, 127, 126, 129, 128, 129, 124, 134, 134, 135, 134, 131, 131, 128, 131, 128, 132, 131, 134, 133, 130, 132, 129, 127, 126, 129, 127, 132, 136, 133, 132, 126, 122, 126, 127, 129, 134, 137, 135, 131, 132, 127, 128, 131, 127, 135, 137, 134, 133, 131, 134, 130, 129, 126, 130, 136, 131, 134, 129, 130, 
};

volatile int sec, minute = 0, hour = 0;
int b_h = 8;
int b_m = 7;
int b_startstop = 2;
int state = 0;

//Alarm time
int alarmHour;
int alarmMinute;

long debouncing_time = 15;
volatile unsigned long last_micros;;

void setup() {

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  pinMode(b_h, INPUT_PULLUP);
  pinMode(b_m, INPUT_PULLUP);
  pinMode(b_startstop, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(b_startstop), debounceInterruptClock, FALLING);

  // alarm sound setup
  startPlayback(sample, sizeof(sample));

  alarmHour = 10;
  alarmMinute = 10;
}

void loop() {
  //Setting the time will stop the clock to set the time
  switch(state) {
    case 0:
      setTime();
      break;
    case 1:
      keepTime();
      break;
    case 2:
      setAlarm();
      break;
  }
}

void debounceInterruptClock(){
 if((long)(micros() - last_micros) >= debouncing_time * 1000) {
   setState();
   last_micros = micros();
 }
}

void setState(){
  lcd.clear();
  state++;
  if(state > 4){
    state = 0;
  }
}

void setTime(){
  lcd.setCursor(0, 1);
  lcd.print("Time");
  delay(100);
  lcd.setCursor(0, 0);
  lcd.print("Time: ");
     
  if(hour<10) {
    lcd.print("0");
    lcd.print(hour);
       
  } else {
    lcd.print(hour);
  }
    
  lcd.print(":");
     
  if(minute<10) {
    lcd.print("0");
    lcd.print(minute);
      
  } else {
    lcd.print(minute);
  }
  lcd.print(":");
      
  if(sec<10) {
    lcd.print("0");  
    lcd.print(sec);
      
  } else {
    lcd.print(sec);
  }
      
  lcd.print(" ");

  if (digitalRead(b_h) == LOW) {
    hour++;
  }
      
  if (hour > 23){
    hour = 0;
  }

  if (digitalRead(b_m) == LOW)
  {
    minute++;
    if (minute > 59)
        minute = 0;
    }
}

void keepTime(){
  lcd.setCursor(0, 0);
  //sec=millis()/1000;
  delay(1000);
  lcd.print("Time: ");
  if (hour < 10)
  {
    lcd.print("0");
  }
  lcd.print(hour);
  lcd.print(":");
  if (minute < 10)
  {
    lcd.print("0");
  }
  lcd.print(minute);
  lcd.print(":");
  if (sec < 10)
  {
   lcd.print("0");
  }
  lcd.print(sec);
  lcd.print(" ");
  
  sec++;
  if (sec > 59)
  {
    minute++;
    sec = 0;
  }
  if (minute > 59) {
    hour++;
    minute = 0;
  }
  if (hour > 23)
  {
    hour = 0;
    minute = 0;
    sec = 0;

  }
}

void setAlarm(){
  lcd.setCursor(0, 1);
  lcd.print("Set Alarm");
  delay(100);
  lcd.setCursor(0, 0);
  lcd.print("Time: ");
     
  if(alarmHour<10) {
    lcd.print("0");
    lcd.print(alarmHour);
       
  } else {
    lcd.print(alarmHour);
  }
    
  lcd.print(":");
     
  if(alarmMinute<10) {
    lcd.print("0");
    lcd.print(alarmMinute);
      
  } else {
    lcd.print(alarmMinute);
  }
      
  lcd.print(" ");

  if (digitalRead(b_h) == LOW) {
    alarmHour++;
  }
      
  if (alarmHour > 23){
    alarmHour = 0;
  }

  if (digitalRead(b_m) == LOW)
  {
    alarmMinute++;
    if (alarmMinute > 59)
        alarmMinute = 0;
    }
}
