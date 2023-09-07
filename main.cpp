#include <Novice.h>
#include <math.h>
#include <string>
#include "time.h"

const char kWindowTitle[] = "LE2D_14_ツチヤ_トモノリ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	int Block_PosX[4] = { 640, 640, 640, 640 };
	int Block_PosY[4] = { -100,-350,-600,-850 };
	int Block_Radius[4] = { 50, 50,  50,  50 };
	int Block_color[4] = { 0,  1,   2,   3 };

	int Block_strage_PosX[4] = { 200, 1080, 200, 1080 };
	int Block_strage_PosY[4] = { 200, 200, 520, 520 };
	int Block_strage_Radius[4] = { 50, 50, 50, 50 };
	int Block_strage_color[4] = { 0,  1,   2,   3 };

	int Hit_Circle_PosX[2] = { 640,640 };
	int Hit_Circle_PosY[2] = { 200,520 };
	int Hit_Circle_Radius[2] = { 70, 70 };

	int Box_Circle_PosX[4] = {};
	int Box_Circle_PosY[4] = {};
	int Box_Circle_Radius[4] = {};

	int Block_Speed = 2;

	int Frame = 0;

	int GameScene = 0;

	srand((unsigned int)time(NULL));

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		switch (GameScene)
		{
		case 0:

			break;
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		}

		Frame++;
		if (Frame >= 2000) {
			Block_Speed = 3;
		}
		if (Frame >= 4000) {
			Block_Speed = 4;
		}
		if (Frame >= 7000) {
			Block_Speed = 5;
		}

		for (int i = 0; i < 4; i++)
		{
			if (Block_PosX[i] == 640)
			{
				Block_PosY[i] += Block_Speed;

			}
			else
			{
			}

			if (Block_PosY[i] >= 850)
			{
				Block_PosY[i] = -150;
				Block_color[i] = rand() % 4;
			}
		}


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		for (int h = 0; h < 2; h++)
		{
			Novice::DrawEllipse(Hit_Circle_PosX[h], Hit_Circle_PosY[h], Hit_Circle_Radius[h], Hit_Circle_Radius[h], 0.0f, WHITE, kFillModeSolid);

			Novice::DrawEllipse(Hit_Circle_PosX[h], Hit_Circle_PosY[h], Hit_Circle_Radius[h], Hit_Circle_Radius[h], 0.0f, WHITE, kFillModeSolid);
		}

		for (int i = 0; i < 4; i++)
		{
			if (Block_color[i] == 0)
			{
				Novice::DrawEllipse(Block_PosX[i], Block_PosY[i], Block_Radius[i], Block_Radius[i], 0.0f, RED, kFillModeSolid);
			}

			if (Block_color[i] == 1)
			{
				Novice::DrawEllipse(Block_PosX[i], Block_PosY[i], Block_Radius[i], Block_Radius[i], 0.0f, BLUE, kFillModeSolid);
			}

			if (Block_color[i] == 2)
			{
				Novice::DrawEllipse(Block_PosX[i], Block_PosY[i], Block_Radius[i], Block_Radius[i], 0.0f, GREEN, kFillModeSolid);
			}

			if (Block_color[i] == 3)
			{
				Novice::DrawEllipse(Block_PosX[i], Block_PosY[i], Block_Radius[i], Block_Radius[i], 0.0f, BLACK, kFillModeSolid);
			}

			if (170 <= Block_PosY[i] && Block_PosY[i] <= 230)
			{
				if (Block_color[i] == 0)
				{
					if (keys[DIK_UP] && preKeys[DIK_UP] == 0)
					{
						Novice::DrawEllipse(Block_strage_PosX[0], Block_strage_PosY[0], Block_Radius[i], Block_Radius[i], 0.0f, RED, kFillModeSolid);
					}
				}

				if (Block_color[i] == 1)
				{
					if (keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0)
					{
						Novice::DrawEllipse(Block_strage_PosX[1], Block_strage_PosY[1], Block_Radius[i], Block_Radius[i], 0.0f, BLUE, kFillModeSolid);
					}
				}
			}

			if (490 <= Block_PosY[i] && Block_PosY[i] <= 550)
			{
				if (Block_color[i] == 2)
				{
					if (keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0)
					{
						Novice::DrawEllipse(Block_strage_PosX[2], Block_strage_PosY[2], Block_Radius[i], Block_Radius[i], 0.0f, GREEN, kFillModeSolid);
					}
				}

				if (Block_color[i] == 3)
				{
					if (keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0)
					{
						Novice::DrawEllipse(Block_strage_PosX[3], Block_strage_PosY[3], Block_Radius[i], Block_Radius[i], 0.0f, BLACK, kFillModeSolid);
					}
				}
			}
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
