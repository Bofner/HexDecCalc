#pragma once

namespace HexDecCalc {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text;


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
	private: System::Windows::Forms::TextBox^ inputTextBox;
	protected:
	private: System::Windows::Forms::TextBox^ outputTextBox;
	private: System::Windows::Forms::TextBox^ hexDecTextBox;
	internal: System::Windows::Forms::ComboBox^ hexDecDropdown;
	private:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ calculateButton;

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->inputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->outputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->hexDecTextBox = (gcnew System::Windows::Forms::TextBox());
			this->hexDecDropdown = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->calculateButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// inputTextBox
			// 
			this->inputTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->inputTextBox->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
			this->inputTextBox->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 19.69811F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->inputTextBox->Location = System::Drawing::Point(47, 154);
			this->inputTextBox->MaxLength = 8;
			this->inputTextBox->Name = L"inputTextBox";
			this->inputTextBox->Size = System::Drawing::Size(227, 36);
			this->inputTextBox->TabIndex = 0;
			this->inputTextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::inputTextBox_TextChanged);
			// 
			// outputTextBox
			// 
			this->outputTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->outputTextBox->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 19.69811F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->outputTextBox->Location = System::Drawing::Point(47, 288);
			this->outputTextBox->Name = L"outputTextBox";
			this->outputTextBox->ReadOnly = true;
			this->outputTextBox->Size = System::Drawing::Size(227, 36);
			this->outputTextBox->TabIndex = 1;
			this->outputTextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::outputTextBox_TextChanged);
			// 
			// hexDecTextBox
			// 
			this->hexDecTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->hexDecTextBox->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 19.69811F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->hexDecTextBox->Location = System::Drawing::Point(356, 288);
			this->hexDecTextBox->Name = L"hexDecTextBox";
			this->hexDecTextBox->ReadOnly = true;
			this->hexDecTextBox->Size = System::Drawing::Size(227, 36);
			this->hexDecTextBox->TabIndex = 2;
			this->hexDecTextBox->Text = L"Decimal";
			this->hexDecTextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::hexDecTextBox_TextChanged);
			// 
			// hexDecDropdown
			// 
			this->hexDecDropdown->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->hexDecDropdown->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->hexDecDropdown->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 19.69811F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->hexDecDropdown->FormattingEnabled = true;
			this->hexDecDropdown->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Hexadecimal", L"Decimal" });
			this->hexDecDropdown->Location = System::Drawing::Point(356, 153);
			this->hexDecDropdown->MaxLength = 32;
			this->hexDecDropdown->Name = L"hexDecDropdown";
			this->hexDecDropdown->Size = System::Drawing::Size(227, 37);
			this->hexDecDropdown->TabIndex = 3;
			this->hexDecDropdown->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::hexDecDropdown_SelectedIndexChanged);
			this->hexDecDropdown->SelectedIndex = 0;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label1->Location = System::Drawing::Point(157, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(336, 53);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Hex <--> Dec";
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(18, 18);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(47, 135);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(82, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Input Number";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(47, 272);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(113, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Converted Number";
			// 
			// calculateButton
			// 
			this->calculateButton->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 19.69811F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->calculateButton->Location = System::Drawing::Point(47, 369);
			this->calculateButton->Name = L"calculateButton";
			this->calculateButton->Size = System::Drawing::Size(166, 37);
			this->calculateButton->TabIndex = 8;
			this->calculateButton->Text = L"Calculate";
			this->calculateButton->UseVisualStyleBackColor = true;
			this->calculateButton->Click += gcnew System::EventHandler(this, &MyForm::calculateButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(624, 439);
			this->Controls->Add(this->calculateButton);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->hexDecDropdown);
			this->Controls->Add(this->hexDecTextBox);
			this->Controls->Add(this->outputTextBox);
			this->Controls->Add(this->inputTextBox);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(640, 480);
			this->MinimumSize = System::Drawing::Size(640, 480);
			this->Name = L"MyForm";
			this->Text = L"Hex Dec Calc";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
//Input TextBox
	private: System::Void inputTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
//HexDec Dropdown
	private: System::Void hexDecDropdown_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

		if (hexDecDropdown->Text == "Hexadecimal"){
			hexDecTextBox->Text = "Decimal";
			inputTextBox->Text = "";
			outputTextBox->Text = "";
		}
		else if (hexDecDropdown->Text == "Decimal") {
			hexDecTextBox->Text = "Hexadecimal";
			inputTextBox->Text = "";
			outputTextBox->Text = "";
		}

	}
//Calculation Button
	private: System::Void calculateButton_Click(System::Object^ sender, System::EventArgs^ e) {

		//Save the input
		String^ inputString = inputTextBox->Text;

		//Find out how long the input is
		int inputLength = inputString->Length;
		Char temp = '5';
		int goodCharacters = 1; //1 is good, 0 is not good

		//If we are converting a Hexadecimal number to decimal...
		if (hexDecDropdown->Text == "Hexadecimal") {
			//Append string with up to 8 more numbers
			for (int i = 0; i < 8 - inputLength; i++) {
				inputString = "0" + inputString;
			}

			//Check that we only are using the proper number (HEX 0-F, DEC 0-9)
			array<int>^ inputValues;
			inputValues = gcnew array<int>(8);

			for (int i = 0; i < 8; i++) {
				temp = System::Convert::ToChar(inputString[i]);
				//If it is a number between 0-9
				if (temp >= 48 && temp <= 57) {
					inputValues[i] = temp - '0';
				}
				//If it is a character between A-F
				else if (temp >= 65 && temp <= 70) {
					inputValues[i] = temp - 55;
				}
				//Otherwise, we can't do the calculation
				else {
					goodCharacters = 0;
				}
			}
			//As long as we are only using 0-F...
			if (goodCharacters == 1) {
					inputValues[0] = inputValues[0] * 268435456;//16^7
					inputValues[1] = inputValues[1] * 16777216;//16^6
					inputValues[2] = inputValues[2] * 1048576;//16^5
					inputValues[3] = inputValues[3] * 65536;//16^4
					inputValues[4] = inputValues[4] * 4096;//16^3
					inputValues[5] = inputValues[5] * 256;//16^2
					inputValues[6] = inputValues[6] * 16;//16^1
					inputValues[7] = inputValues[7] * 1;//16^0
					//Add up the results
					int finalInt = inputValues[0] + inputValues[1] + inputValues[2] + inputValues[3] + inputValues[4] + inputValues[5] + inputValues[6] + inputValues[7];
					
					//Convert to presentable text
					String^ output = Convert::ToString(finalInt);
					//Display the Decimal number
					outputTextBox->Text = output;
			}
		}

		//If we are converting from Dec to Hex...
		else if (hexDecDropdown->Text == "Decimal") {
			for (int i = 0; i < inputLength; i++) {
				temp = System::Convert::ToChar(inputString[i]);
				//If it is a number between 0-9
				if (temp >= 48 && temp <= 57) {
					//Don't need to do anything
				}
				//Otherwise, we can't do the calculation
				else {
					goodCharacters = 0;
				}
			}
			//As long as we are only using 0-9...
			if (goodCharacters == 1) {
				int decNumber = System::Convert::ToInt32(inputString);
				array<int>^ remainders;
				remainders = gcnew array<int>(8);	//Hex Number will always have fewer digits than DEC
				for (int i = 0; i < remainders->Length; i++) {
					remainders[i] = 17;//Can never happen with normal input
				}
				//Do Dec to Hex calculation
				int w = 0;
				while (decNumber > 0) {
					remainders[w] = decNumber % 16;
					decNumber = decNumber / 16;
					w++;
				}
				//Convert to presentable text
				String^ output = "";
				w = 0;
				while(remainders[w] < 17) {
					if (remainders[w] < 10) {
						output = Convert::ToString(remainders[w]) + output;
					}
					else if(remainders[w] == 10) {
						output = "A" + output;
					}
					else if (remainders[w] == 11) {
						output ="B" + output;
					}
					else if (remainders[w] == 12) {
						output = "C" + output;
					}
					else if (remainders[w] == 13) {
						output = "D" + output;
					}
					else if (remainders[w] == 14) {
						output = "E" + output;
					}
					else if (remainders[w] == 15) {
						output = "F" + output;
					}
					w++;
				}
				//Display the Decimal number
				outputTextBox->Text = output;
			}
		}
	}
//HexDec Output TextBox
	private: System::Void hexDecTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
//Output TextBox
	private: System::Void outputTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
