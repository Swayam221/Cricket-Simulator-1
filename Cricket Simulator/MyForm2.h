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
			this->listView2 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader6 = (gcnew System::Windows::Forms::ColumnHeader());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->columnHeader1, this->columnHeader2,
					this->columnHeader3
			});
			this->listView1->Location = System::Drawing::Point(12, 12);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(310, 314);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
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
			this->columnHeader3->Width = 183;
			// 
			// listView2
			// 
			this->listView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->columnHeader4, this->columnHeader5,
					this->columnHeader6
			});
			this->listView2->Location = System::Drawing::Point(360, 12);
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
			this->columnHeader6->Width = 183;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(360, 333);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"return";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm2::button1_Click);
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(699, 370);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listView2);
			this->Controls->Add(this->listView1);
			this->Name = L"MyForm2";
			this->Text = L"MyForm2";
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void listView2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Hide();
			 f->Show();

}
};
}
