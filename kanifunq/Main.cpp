#include <Siv3D.hpp>
#include<string>
#include<Windows.h>
#include<time.h>
using namespace std;

void Main()
{
	//System::SetExitEvent(WindowEvent::Manual);
	//Window::SetStyle(WindowStyle::NonFrame);
	Window::Resize(875, 635);//ウィンドウサイズ
	TextReader reader(L"quiz.txt");

	Window::SetTitle(L"kani.fun");//ウィンドウタイトル
	Graphics::SetBackground(Palette::White);//背景

	const Font font(30);
	const Font font2(15);
	const Font font3(15, L"Meiryo UI");




	while (System::Update()) {
		font(L"Press start").drawCenter(437, 317, Color(0, 0, 0));
		if (Input::MouseL.clicked) break;
		if (Input::KeyEscape.clicked/* || WindowEvent::CloseButton*/) { system("taskkill /IM kani.funquiz.exe /F"); }
	}

	System::Update();

	font(L"Wait").drawCenter(437, 317, Color(0, 0, 0));


	System::Update();

	//ここからクイズフォーマット１
	const Rect B0(25, 310, 400, 150);
	const Rect B1(25, 475, 400, 150);
	const Rect B2(450, 310, 400, 150);
	const Rect B3(450, 475, 400, 150);
	//ここまで
	int qm = 0;
	int qn = 0;
	int clock1 = 0;
	int point = 0;


	String question[1000];
	String S0[1000], S1[1000], S2[1000], S3[1000];
	String answer[1000];
	String drawquestion = L"";
	String maked[1000];
	String genre[1000];
	String check;
	String line;

	Sleep(500);

	for (int i = 0; i < 1000; i++) {

		question[i] = L"";
		S0[i] = L"";
		S1[i] = L"";
		S2[i] = L"";
		S3[i] = L"";
		answer[i] = L"";
		maked[i] = L"";
		genre[i] = L"";


	}



	//clock1=clock();
	for (int i = 0; reader.readLine(question[i]); i++) {
		reader.readLine(S0[i]);
		reader.readLine(S1[i]);
		reader.readLine(S2[i]);
		reader.readLine(S3[i]);
		reader.readLine(answer[i]);
		reader.readLine(maked[i]);
		reader.readLine(genre[i]);

		qm = i;
	}

	for (int i = 0; i<10; i++) {

		srand(time(NULL));
		if (qm == 0) { break; }
		qn = rand() % (qm + 1);


		drawquestion = question[qn];
		clock1 = clock();
		while (System::Update())
		{

			//if (100 < clock() - clock1) {}
			font3(20000 - clock() + clock1).drawCenter(200, 50, Color(0, 0, 0));
			font2(L"制作者:" + maked[qn]).drawCenter(700, 250, Color(0, 0, 0));
			font2(drawquestion).drawCenter(437, 100, Color(0, 0, 0));
			if (clock() - clock1 > 20000) {

				check = L"4";

				break;
			}
			if (Input::KeyEscape.clicked/* || WindowEvent::CloseButton*/) { system("taskkill /IM kani.funquiz.exe /F"); }
			if (B0.leftPressed) {
				B0.draw(Color(150, 150, 150));
				B1.draw(Color(180, 180, 180));
				B2.draw(Color(180, 180, 180));
				B3.draw(Color(180, 180, 180));
				font(S0[qn]).drawCenter(225, 385);
				font(S1[qn]).drawCenter(225, 550);
				font(S2[qn]).drawCenter(650, 385);
				font(S3[qn]).drawCenter(650, 550);
				check = L"0";
				break;
			}
			else if (B1.leftPressed) {
				B0.draw(Color(180, 180, 180));
				B1.draw(Color(150, 150, 150));
				B2.draw(Color(180, 180, 180));
				B3.draw(Color(180, 180, 180));
				font(S0[qn]).drawCenter(225, 385);
				font(S1[qn]).drawCenter(225, 550);
				font(S2[qn]).drawCenter(650, 385);
				font(S3[qn]).drawCenter(650, 550);
				check = L"1";
				break;
			}
			else if (B2.leftPressed) {
				B0.draw(Color(180, 180, 180));
				B1.draw(Color(180, 180, 180));
				B2.draw(Color(150, 150, 150));
				B3.draw(Color(180, 180, 180));
				font(S0[qn]).drawCenter(225, 385);
				font(S1[qn]).drawCenter(225, 550);
				font(S2[qn]).drawCenter(650, 385);
				font(S3[qn]).drawCenter(650, 550);
				check = L"2";
				break;
			}
			else if (B3.leftPressed) {
				B0.draw(Color(180, 180, 180));
				B1.draw(Color(180, 180, 180));
				B2.draw(Color(180, 180, 180));
				B3.draw(Color(150, 150, 150));
				font(S0[qn]).drawCenter(225, 385);
				font(S1[qn]).drawCenter(225, 550);
				font(S2[qn]).drawCenter(650, 385);
				font(S3[qn]).drawCenter(650, 550);
				check = L"3";
				break;
			}
			else {
				B0.draw(Color(180, 180, 180));
				B1.draw(Color(180, 180, 180));
				B2.draw(Color(180, 180, 180));
				B3.draw(Color(180, 180, 180));
				font(S0[qn]).drawCenter(225, 385);
				font(S1[qn]).drawCenter(225, 550);
				font(S2[qn]).drawCenter(650, 385);
				font(S3[qn]).drawCenter(650, 550);
			}
		}



		if (answer[qn] == check) {
			point += 20000 + clock1 - clock();
			//正解
			System::Update();
			font(L"正解").drawCenter(437, 317, Color(0, 0, 0));




			System::Update();



			Sleep(2500);

		}

		else if (check == L"4") {
			//時間切れ

			System::Update();

			font(L"時間切れ").drawCenter(437, 317, Color(0, 0, 0));


			System::Update();

			Sleep(2500);



		}
		else {

			//不正解
			System::Update();

			font(L"不正解").drawCenter(437, 317, Color(0, 0, 0));


			System::Update();


			Sleep(2500);

		}
	}
	int end = 0;
	while (System::Update()) {

		font(point).drawCenter(437, 317, Color(0, 0, 0));

		if (Input::MouseL.clicked)end++;
		if (end > 2)break;
	}


}
