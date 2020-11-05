#pragma once
#include "MyForm2.h"
#include <string>
#include <msclr\marshal_cppstd.h>
#include "Player.h"
#include <iostream>
#include "Team.h"
#include "Match.h"
#include <conio.h>
#include <cstdlib>

using namespace std;

namespace CricketSimulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
		void testMatch(string t1, string t2,int n,MyForm2^ f1) {
			srand((unsigned)time(0));
			Team mi(t1);
			Team csk(t2);
			label1->Text = msclr::interop::marshal_as<System::String ^>(t1);
			label2->Text = msclr::interop::marshal_as<System::String ^>(t2);
			f1->label1->Text = msclr::interop::marshal_as<System::String ^>(t1);
			f1->label2->Text = msclr::interop::marshal_as<System::String ^>(t2);
			Team* mip = &mi;
			Team* cskp = &csk;
			Match match1(mip, cskp);
			Match match2(cskp, mip);
			srand(time(0));
			for (int i = 0; i < n; i++){
				match1.play();
				match2.play();

				if (mi.runsScoredIn1Match>csk.runsScoredIn1Match) mi.wins++;
				else if (mi.runsScoredIn1Match < csk.runsScoredIn1Match) csk.wins++;

				mi.reset();
				csk.reset();
			}
			csk.getAvgResults(n);
			mi.getAvgResults(n);
			f1->label3->Text = System::Convert::ToString(mi.wins);
			f1->label4->Text = System::Convert::ToString(csk.wins);
			int score1 = match1.team2->runsScored;
			int score2 = match2.team2->runsScored;

			//int score1 = match1.team2->getAvgRunsScored(n);

			String ^ scor1 = System::Convert::ToString(score1) + "/" + System::Convert::ToString(csk.wicketsLost);
			label4->Text = scor1;
			//cout << match1.team1->runsScored << "\n";
			/*cout << match1.team2->runsScored << "\n";*/ 
			//cout << match1.team1->wicketsLost << "\n";
			//cout << match1.team2->wicketsLost << "\n";

			//int score2 = match2.team2->getAvgRunsScored(n);
			String ^ scor2 = System::Convert::ToString(score2) + "/" + System::Convert::ToString(mi.wicketsLost);
			label3->Text = scor2;
			display(&mi, &csk, f1);
			//	cout << match2.team1->runsScored << "\n";
			/*cout << match2.team2->runsScored << "\n";*/ //label4->Text = msclr::interop::marshal_as<System::String ^>(t2);
			//	cout << match2.team1->wicketsLost << "\n";
			//cout << match2.team2->wicketsLost << "\n";
		}
		void display(Team* t1, Team* t2, MyForm2^ f1)
		{
			for (int i = 0; i < t1->batting.size(); i++)
			{
				f1->listViewItem = gcnew Windows::Forms::ListViewItem(msclr::interop::marshal_as<System::String ^>(t1->batting.at(i)->name));
				f1->listViewItem->SubItems->Add(System::Convert::ToString(t1->batting.at(i)->runsScored));
				f1->listViewItem->SubItems->Add(System::Convert::ToString(t1->batting.at(i)->wicketsTaken));
				f1->listViewItem->SubItems->Add(System::Convert::ToString(t1->batting.at(i)->ballsBatted));
				f1->listViewItem->SubItems->Add(System::Convert::ToString(t1->batting.at(i)->ballsBowled));
				f1->listViewItem->SubItems->Add(System::Convert::ToString(t1->batting.at(i)->foursScored));
				f1->listViewItem->SubItems->Add(System::Convert::ToString(t1->batting.at(i)->sixesScored));
				f1->listViewItem->SubItems->Add(System::Convert::ToString(t1->batting.at(i)->runsGiven));
				f1->listView1->Items->Add(f1->listViewItem);

				f1->listViewItem2 = gcnew Windows::Forms::ListViewItem(msclr::interop::marshal_as<System::String ^>(t2->batting.at(i)->name));
				f1->listViewItem2->SubItems->Add(System::Convert::ToString(t2->batting.at(i)->runsScored));
				f1->listViewItem2->SubItems->Add(System::Convert::ToString(t2->batting.at(i)->wicketsTaken));
				f1->listViewItem2->SubItems->Add(System::Convert::ToString(t2->batting.at(i)->ballsBatted));
				f1->listViewItem2->SubItems->Add(System::Convert::ToString(t2->batting.at(i)->ballsBowled));
				f1->listViewItem2->SubItems->Add(System::Convert::ToString(t2->batting.at(i)->foursScored));
				f1->listViewItem2->SubItems->Add(System::Convert::ToString(t2->batting.at(i)->sixesScored));
				f1->listViewItem2->SubItems->Add(System::Convert::ToString(t2->batting.at(i)->runsGiven));
				f1->listView2->Items->Add(f1->listViewItem2);

			}
		}



	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button2;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(89, 114);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(96, 31);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Simulate";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(89, 62);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"enter team 1";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(89, 88);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 2;
			this->textBox2->Text = L"enter team 2";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(53, 170);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Team1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(196, 170);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Team2";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(53, 205);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Score1";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(196, 205);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(41, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Score2";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(87, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(104, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"enter no. of matches";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(89, 25);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 8;
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(99, 227);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 9;
			this->button2->Text = L"ScoreCard";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"Simulator";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public:MyForm2^ f1; 
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 String ^ t1 = textBox1->Text;
				 String ^ t2 = textBox2->Text;
				 String ^ t3 = textBox3->Text;
				 int n = System::Convert::ToInt32(t3);
				 string team1 = msclr::interop::marshal_as<std::string>(t1);
				 string team2 = msclr::interop::marshal_as<std::string>(t2);
				 f1 = gcnew MyForm2(this);
				 testMatch(team1, team2,n,f1);
				 
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			 f1->ShowDialog();
}
};

}
