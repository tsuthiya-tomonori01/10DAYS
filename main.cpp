#include <Novice.h>
#include <math.h>
#include <string>

const char kWindowTitle[] = "LE2D_14_ツチヤ_トモノリ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	int BlockPosX[4] = {640,640,640,640};
	int BlockPosY[4] = {-200,-400,-600,-800};
	int BlockRadius[4] = {50,50,50,50};
	int Block_color[4] = {0,1,2,3};



	int BlockSpeed = 5;

	int Flame = 60;

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

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

		Flame--;

		for (int i = 0; i < 4; i++)
		{
			BlockPosY[i] += BlockSpeed;

			if (BlockPosY[i] >= 700)
			{
				if (Flame <= 0)
				{
					BlockPosY[i] = -200;
					Block_color[i] = rand() % 4;
					Flame = 60;
				}
			}
		}
		



		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		for (int i = 0; i < 4; i++)
		{
			if (Block_color[i] == 0)
			{
				Novice::DrawEllipse(BlockPosX[i], BlockPosY[i], BlockRadius[i], BlockRadius[i], 0.0f, RED, kFillModeSolid);
			}

			if (Block_color[i] == 1)
			{
				Novice::DrawEllipse(BlockPosX[i], BlockPosY[i], BlockRadius[i], BlockRadius[i], 0.0f, BLUE, kFillModeSolid);
			}

			if (Block_color[i] == 2)
			{
				Novice::DrawEllipse(BlockPosX[i], BlockPosY[i], BlockRadius[i], BlockRadius[i], 0.0f, GREEN, kFillModeSolid);
			}

			if (Block_color[i] == 3)
			{
				Novice::DrawEllipse(BlockPosX[i], BlockPosY[i], BlockRadius[i], BlockRadius[i], 0.0f, BLACK, kFillModeSolid);
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
