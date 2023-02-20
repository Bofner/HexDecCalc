#pragma once

namespace HexDecCalc {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		MyForm1(String^ data)
		{
			InitializeComponent();
			input1TextBox->Text = data;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ input1TextBox;

	private: System::Windows::Forms::TextBox^ textBox1;
	internal: System::Windows::Forms::ComboBox^ hexDecDropdown;
	private: System::Windows::Forms::Button^ calculateButton;
	private: System::Windows::Forms::TextBox^ outputTextBox;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	internal:
	private:
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->input1TextBox = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->hexDecDropdown = (gcnew System::Windows::Forms::ComboBox());
			this->calculateButton = (gcnew System::Windows::Forms::Button());
			this->outputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(540, 25);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Hex-Dec";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label1->Location = System::Drawing::Point(145, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(349, 53);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Hex Calculator";
			// 
			// input1TextBox
			// 
			this->input1TextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->input1TextBox->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
			this->input1TextBox->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 19.69811F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->input1TextBox->Location = System::Drawing::Point(30, 161);
			this->input1TextBox->MaxLength = 8;
			this->input1TextBox->Name = L"input1TextBox";
			this->input1TextBox->Size = System::Drawing::Size(227, 36);
			this->input1TextBox->TabIndex = 12;
			this->input1TextBox->TextChanged += gcnew System::EventHandler(this, &MyForm1::input1TextBox_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBox1->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 19.69811F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->textBox1->Location = System::Drawing::Point(371, 161);
			this->textBox1->MaxLength = 8;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(227, 36);
			this->textBox1->TabIndex = 13;
			// 
			// hexDecDropdown
			// 
			this->hexDecDropdown->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->hexDecDropdown->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->hexDecDropdown->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 19.69811F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->hexDecDropdown->FormattingEnabled = true;
			this->hexDecDropdown->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Hexadecimal", L"Decimal" });
			this->hexDecDropdown->Location = System::Drawing::Point(274, 161);
			this->hexDecDropdown->MaxLength = 32;
			this->hexDecDropdown->Name = L"hexDecDropdown";
			this->hexDecDropdown->Size = System::Drawing::Size(82, 37);
			this->hexDecDropdown->TabIndex = 14;
			// 
			// calculateButton
			// 
			this->calculateButton->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 19.69811F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->calculateButton->Location = System::Drawing::Point(371, 277);
			this->calculateButton->Name = L"calculateButton";
			this->calculateButton->Size = System::Drawing::Size(227, 37);
			this->calculateButton->TabIndex = 15;
			this->calculateButton->Text = L"Calculate";
			this->calculateButton->UseVisualStyleBackColor = true;
			this->calculateButton->Click += gcnew System::EventHandler(this, &MyForm1::calculateButton_Click);
			// 
			// outputTextBox
			// 
			this->outputTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->outputTextBox->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 19.69811F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->outputTextBox->Location = System::Drawing::Point(30, 277);
			this->outputTextBox->Name = L"outputTextBox";
			this->outputTextBox->ReadOnly = true;
			this->outputTextBox->Size = System::Drawing::Size(326, 36);
			this->outputTextBox->TabIndex = 16;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(27, 145);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 13);
			this->label2->TabIndex = 17;
			this->label2->Text = L"Input 1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(368, 145);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 13);
			this->label3->TabIndex = 18;
			this->label3->Text = L"Input 2";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(27, 261);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(48, 13);
			this->label4->TabIndex = 19;
			this->label4->Text = L"Answer";
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(624, 439);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->outputTextBox);
			this->Controls->Add(this->calculateButton);
			this->Controls->Add(this->hexDecDropdown);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->input1TextBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(640, 480);
			this->MinimumSize = System::Drawing::Size(640, 480);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
//Input 1 Textbox
	private: System::Void input1TextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
//Calculate Button
	private: System::Void calculateButton_Click(System::Object^ sender, System::EventArgs^ e) {
		//String^ decConversion = hexToDecCalc("inputString");
	}
};
}
