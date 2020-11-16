#pragma once

namespace CricketSimulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		Form ^f;
		MyForm2(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		MyForm2(Form ^f1)
		{
			f = f1;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	public:System::Windows::Forms::ListViewItem^ listViewItem;
	public:System::Windows::Forms::ListViewItem^ listViewItem2;
	public: System::Windows::Forms::ListView^  listView1;
	protected:
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;
	public: System::Windows::Forms::ListView^  listView2;
	private:
	private: System::Windows::Forms::ColumnHeader^  columnHeader4;
	public:
	private: System::Windows::Forms::ColumnHeader^  columnHeader5;
	private: System::Windows::Forms::ColumnHeader^  columnHeader6;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader7;
	public: System::Windows::Forms::Label^  label1;
	public: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ColumnHeader^  columnHeader8;
	private: System::Windows::Forms::ColumnHeader^  columnHeader9;
	private: System::Windows::Forms::ColumnHeader^  columnHeader10;
	private: System::Windows::Forms::ColumnHeader^  columnHeader11;
	private: System::Windows::Forms::ColumnHeader^  columnHeader12;
	private: System::Windows::Forms::ColumnHeader^  columnHeader13;
	private: System::Windows::Forms::ColumnHeader^  columnHeader14;
	private: System::Windows::Forms::ColumnHeader^  columnHeader15;
	private: System::Windows::Forms::ColumnHeader^  columnHeader16;
	public: System::Windows::Forms::Label^  label3;
	public: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	public:
	private: System::Windows::Forms::Label^  label6;


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
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader7 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader8 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader9 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader10 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader11 = (gcnew System::Windows::Forms::ColumnHeader());
			this->listView2 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader6 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader12 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader13 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader14 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader15 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader16 = (gcnew System::Windows::Forms::ColumnHeader());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(8) {
				this->columnHeader1, this->columnHeader2,
					this->columnHeader3, this->columnHeader7, this->columnHeader8, this->columnHeader9, this->columnHeader10, this->columnHeader11
			});
			this->listView1->Location = System::Drawing::Point(12, 25);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(310, 314);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm2::listView1_SelectedIndexChanged);
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Player Name";
			this->columnHeader1->Width = 154;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"AvgRuns";
			this->columnHeader2->Width = 56;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"AvgWicketsTaken";
			this->columnHeader3->Width = 102;
			// 
			// columnHeader7
			// 
			this->columnHeader7->Text = L"AvgBallsFaced";
			this->columnHeader7->Width = 90;
			// 
			// columnHeader8
			// 
			this->columnHeader8->Text = L"AvgBallsBowled";
			this->columnHeader8->Width = 90;
			// 
			// columnHeader9
			// 
			this->columnHeader9->Text = L"AvgFours";
			this->columnHeader9->Width = 62;
			// 
			// columnHeader10
			// 
			this->columnHeader10->Text = L"AvgSixes";
			this->columnHeader10->Width = 65;
			// 
			// columnHeader11
			// 
			this->columnHeader11->Text = L"AvgRunsGiven";
			this->columnHeader11->Width = 90;
			// 
			// listView2
			// 
			this->listView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(8) {
				this->columnHeader4, this->columnHeader5,
					this->columnHeader6, this->columnHeader12, this->columnHeader13, this->columnHeader14, this->columnHeader15, this->columnHeader16
			});
			this->listView2->Location = System::Drawing::Point(360, 25);
			this->listView2->Name = L"listView2";
			this->listView2->Size = System::Drawing::Size(310, 314);
			this->listView2->TabIndex = 1;
			this->listView2->UseCompatibleStateImageBehavior = false;
			this->listView2->View = System::Windows::Forms::View::Details;
			this->listView2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm2::listView2_SelectedIndexChanged);
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"Player Name";
			this->columnHeader4->Width = 154;
			// 
			// columnHeader5
			// 
			this->columnHeader5->Text = L"AvgRuns";
			this->columnHeader5->Width = 56;
			// 
			// columnHeader6
			// 
			this->columnHeader6->Text = L"AvgWicketsTaken";
			this->columnHeader6->Width = 102;
			// 
			// columnHeader12
			// 
			this->columnHeader12->Text = L"AvgBallsFaced";
			this->columnHeader12->Width = 90;
			// 
			// columnHeader13
			// 
			this->columnHeader13->Text = L"AvgBallsBowled";
			this->columnHeader13->Width = 90;
			// 
			// columnHeader14
			// 
			this->columnHeader14->Text = L"AvgFours";
			this->columnHeader14->Width = 62;
			// 
			// columnHeader15
			// 
			this->columnHeader15->Text = L"AvgSixes";
			this->columnHeader15->Width = 65;
			// 
			// columnHeader16
			// 
			this->columnHeader16->Text = L"AvgRunsGiven";
			this->columnHeader16->Width = 90;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(360, 345);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"return";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm2::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 6);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(36, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"team1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(360, 6);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(36, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"team2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(287, 6);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(33, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"value";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm2::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(635, 6);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(33, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"value";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(259, 6);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(31, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"win%";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(607, 6);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(31, 13);
			this->label6->TabIndex = 8;
			this->label6->Text = L"win%";
			this->label6->Click += gcnew System::EventHandler(this, &MyForm2::label6_Click);
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(699, 370);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listView2);
			this->Controls->Add(this->listView1);
			this->Name = L"MyForm2";
			this->Text = L"ScoreCard";
			this->Load += gcnew System::EventHandler(this, &MyForm2::MyForm2_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void listView2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			 f->Show();

}
private: System::Void MyForm2_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void listView1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
