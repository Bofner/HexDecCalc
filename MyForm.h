#pragma once
#include "MyForm1.h"
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
	private: System::Windows::Forms::Button^ switchButton;
	internal: System::Windows::Forms::ComboBox^ operationDropDown;
	private: System::Windows::Forms::TextBox^ input2TextBox;
	private: System::Windows::Forms::Button^ calcButton2;
	internal: System::Windows::Forms::ComboBox^ calcHexDropDown;
	private: System::Windows::Forms::Label^ label4;
	internal:
	private:
	internal:
	private:

	private:

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		 
//Check if input is a valid Dec number
		int validDecNumber(String^ inputString) {
			//Make sure we only have numbers
			//Set up variables
			Char temp = '5';
			//1 is good, 0 is not good
			int goodCharacters = 1;
			//Find out how long the input is
			int inputLength = inputString->Length;

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
			return goodCharacters;
		};

//Check if input in a valid Hex number
		int validHexNumber(String^ inputString) {
			//Set up variables
			Char temp = '5';
			//1 is good, 0 is not good
			int goodCharacters = 1;
			//Find out how long the input is
			int inputLength = inputString->Length;
			for (int i = 0; i < inputLength; i++) {
				temp = System::Convert::ToChar(inputString[i]);
				//If it is a number between 0-9
				if (temp >= 48 && temp <= 57) {
					//Don't need to do anything
				}
				//If it is a character between A-F
				else if (temp >= 65 && temp <= 70) {
					//Do Nothing
				}
				//Otherwise, we can't do the calculation
				else {
					goodCharacters = 0;
				}
			}
			return goodCharacters;
		};

//Convert from Hexadecimal to Decimal
		System::String^ hexToDecCalc(System::String^ input) {
			//Set up variables
			Char temp = '5';
			//1 is good, 0 is not good
			int goodCharacters = 1;
			//Find out how long the input is
			int inputLength = input->Length;

			//Append string with up to 8 more numbers
			for (int i = 0; i < 8 - inputLength; i++) {
				input = "0" + input;
			}

			//Check that we only are using the proper number (HEX 0-F, DEC 0-9)
			array<int>^ inputValues;
			inputValues = gcnew array<int>(8);
			for (int i = 0; i < 8; i++) {
				temp = System::Convert::ToChar(input[i]);
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
				return output;
			}
			return "Invalid";
		};

//Convert from Decimal to Hexadecimal
		System::String^ decToHexCalc(System::String^ input) {

			//Make sure we only have numbers
			int onlyNumbers = validDecNumber(input);

			//As long as we are only using 0-9...
			if (onlyNumbers == 1) {
				int decNumber = System::Convert::ToInt32(input);
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
				while (remainders[w] < 17) {
					if (remainders[w] < 10) {
						output = Convert::ToString(remainders[w]) + output;
					}
					else if (remainders[w] == 10) {
						output = "A" + output;
					}
					else if (remainders[w] == 11) {
						output = "B" + output;
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
				//return
				return output;
			}

			return "Invalid";
		};

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
			this->switchButton = (gcnew System::Windows::Forms::Button());
			this->operationDropDown = (gcnew System::Windows::Forms::ComboBox());
			this->input2TextBox = (gcnew System::Windows::Forms::TextBox());
			this->calcButton2 = (gcnew System::Windows::Forms::Button());
			this->calcHexDropDown = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// inputTextBox
			// 
			this->inputTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->inputTextBox->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
			this->inputTextBox->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 19.69811F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->inputTextBox->Location = System::Drawing::Point(35, 154);
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
			this->outputTextBox->Location = System::Drawing::Point(35, 288);
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
			this->hexDecTextBox->Location = System::Drawing::Point(385, 288);
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
			this->hexDecDropdown->Location = System::Drawing::Point(385, 153);
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
			this->label1->Location = System::Drawing::Point(157, 25);
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
			this->label2->Location = System::Drawing::Point(35, 135);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(82, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Input Number";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(35, 272);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(113, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Converted Number";
			// 
			// calculateButton
			// 
			this->calculateButton->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 19.69811F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->calculateButton->Location = System::Drawing::Point(35, 370);
			this->calculateButton->Name = L"calculateButton";
			this->calculateButton->Size = System::Drawing::Size(166, 37);
			this->calculateButton->TabIndex = 8;
			this->calculateButton->Text = L"Convert";
			this->calculateButton->UseVisualStyleBackColor = true;
			this->calculateButton->Click += gcnew System::EventHandler(this, &MyForm::calculateButton_Click);
			// 
			// switchButton
			// 
			this->switchButton->Location = System::Drawing::Point(537, 25);
			this->switchButton->Name = L"switchButton";
			this->switchButton->Size = System::Drawing::Size(75, 23);
			this->switchButton->TabIndex = 9;
			this->switchButton->Text = L"Calculator";
			this->switchButton->UseVisualStyleBackColor = true;
			this->switchButton->Click += gcnew System::EventHandler(this, &MyForm::switchButton_Click);
			// 
			// operationDropDown
			// 
			this->operationDropDown->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->operationDropDown->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->operationDropDown->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 19.69811F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->operationDropDown->FormattingEnabled = true;
			this->operationDropDown->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"+", L"-", L"x", L"€" });
			this->operationDropDown->Location = System::Drawing::Point(297, 153);
			this->operationDropDown->MaxLength = 32;
			this->operationDropDown->Name = L"operationDropDown";
			this->operationDropDown->Size = System::Drawing::Size(56, 37);
			this->operationDropDown->TabIndex = 15;
			this->operationDropDown->Visible = false;
			this->operationDropDown->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::operationDropDown_SelectedIndexChanged);
			this->operationDropDown->SelectedIndex = 0;
			// 
			// input2TextBox
			// 
			this->input2TextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->input2TextBox->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
			this->input2TextBox->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 19.69811F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->input2TextBox->Location = System::Drawing::Point(385, 154);
			this->input2TextBox->MaxLength = 8;
			this->input2TextBox->Name = L"input2TextBox";
			this->input2TextBox->Size = System::Drawing::Size(227, 36);
			this->input2TextBox->TabIndex = 16;
			this->input2TextBox->Visible = false;
			// 
			// calcButton2
			// 
			this->calcButton2->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 19.69811F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->calcButton2->Location = System::Drawing::Point(35, 370);
			this->calcButton2->Name = L"calcButton2";
			this->calcButton2->Size = System::Drawing::Size(166, 37);
			this->calcButton2->TabIndex = 17;
			this->calcButton2->Text = L"Calculate";
			this->calcButton2->UseVisualStyleBackColor = true;
			this->calcButton2->Visible = false;
			this->calcButton2->Click += gcnew System::EventHandler(this, &MyForm::calcButton2_Click);
			// 
			// calcHexDropDown
			// 
			this->calcHexDropDown->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->calcHexDropDown->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->calcHexDropDown->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 19.69811F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->calcHexDropDown->FormattingEnabled = true;
			this->calcHexDropDown->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Hexadecimal", L"Decimal" });
			this->calcHexDropDown->Location = System::Drawing::Point(385, 287);
			this->calcHexDropDown->MaxLength = 32;
			this->calcHexDropDown->Name = L"calcHexDropDown";
			this->calcHexDropDown->Size = System::Drawing::Size(227, 37);
			this->calcHexDropDown->TabIndex = 18;
			this->calcHexDropDown->Visible = false;
			this->calcHexDropDown->SelectedIndex = 0;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(382, 135);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 13);
			this->label4->TabIndex = 19;
			this->label4->Text = L"Input 2";
			this->label4->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(624, 439);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->calcHexDropDown);
			this->Controls->Add(this->calcButton2);
			this->Controls->Add(this->input2TextBox);
			this->Controls->Add(this->operationDropDown);
			this->Controls->Add(this->switchButton);
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
//Hex/Dec Conversion Button
	private: System::Void calculateButton_Click(System::Object^ sender, System::EventArgs^ e) {

		//Save the input
		String^ inputString = inputTextBox->Text;

	//If we are converting a Hexadecimal number to decimal...
		if (hexDecDropdown->Text == "Hexadecimal" && inputTextBox->Text != "") {
			
			//Do the Hex-To-Dec conversion
			String^ decConversion = hexToDecCalc(inputString);
			//Display the Decimal number
			if (decConversion != "Invalid") {
				outputTextBox->Text = decConversion;
			}
			else {
				outputTextBox->Text = "Invalid Input";
			}
		}

	//If we are converting from Dec to Hex...
		else if (hexDecDropdown->Text == "Decimal" && inputTextBox->Text != "") {
			//Do the Dec-To-Hex conversion
			String^ hexConversion = decToHexCalc(inputString);
			//Display the Hexadecimal number
			if (hexConversion != "Invalid") {
				outputTextBox->Text = hexConversion;
			}
			else {
				outputTextBox->Text = "Invalid Input";
			}
			
		}
	}
//HexDec Output TextBox
	private: System::Void hexDecTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
//Output TextBox
	private: System::Void outputTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
//Switch between Converter and Calculator
	private: System::Void switchButton_Click(System::Object^ sender, System::EventArgs^ e) {

		if (switchButton->Text == "Calculator") {
			switchButton->Text = "Converter";
			operationDropDown->Visible = true;
			label1->Text = "Hex Calculator";
			label2->Text = "Input 1";
			label3->Text = "Answer";
			input2TextBox->Visible = true;
			calculateButton->Visible = false;
			calcButton2->Visible = true;
			calcHexDropDown->Visible = true;
			label4->Visible = true;
			inputTextBox->Text = "";
			outputTextBox->Text = "";
			input2TextBox->Text = "";
		}
		else {
			switchButton->Text = "Calculator";
			operationDropDown->Visible = false;
			label1->Text = "Hex <--> Dec";
			label2->Text = "Input Number";
			label3->Text = "Converted Number";
			input2TextBox->Visible = false;
			calculateButton->Visible = true;
			calcButton2->Visible = false;
			calcHexDropDown->Visible = false;
			label4->Visible = false;
			inputTextBox->Text = "";
			outputTextBox->Text = "";
			input2TextBox->Text = "";
			
		}
		
	}
//Operation Drop Down
	private: System::Void operationDropDown_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
//Hex/Dec Calculator Button
	private: System::Void calcButton2_Click(System::Object^ sender, System::EventArgs^ e) {
		//Save the input
		String^ inputString1 = inputTextBox->Text;
		String^ inputString2 = input2TextBox->Text;

		int int1; 
		int int2; 
		String^ answer;

//Hexadecimal operations
		if (calcHexDropDown->Text == "Hexadecimal" && inputTextBox->Text != "" && input2TextBox->Text != "") {

			int goodHexNum1 = validHexNumber(inputString1);

			int goodHexNum2 = validHexNumber(inputString2);

			

			//As long as we only have proper characters
			if (goodHexNum1 == 1 && goodHexNum2 == 1) {

				//Do the Hex-To-Dec conversion
				String^ input1 = hexToDecCalc(inputString1);
				String^ input2 = hexToDecCalc(inputString2);
				int1 = Convert::ToInt32(input1);
				int2 = Convert::ToInt32(input2);

				if (operationDropDown->Text == "+") {
					//Add up the numbers
					int decAnswer = int1 + int2;
					//Send it back into the converter
					String^ additionString = Convert::ToString(decAnswer);
					answer = decToHexCalc(additionString);
				}
				else if (operationDropDown->Text == "-") {
					//Subtract the numbers
					int decAnswer = int1 - int2;
					//Send it back into the converter
					String^ subtractionString = Convert::ToString(decAnswer);
					answer = decToHexCalc(subtractionString);
				}
				else if (operationDropDown->Text == "x") {
					//Multiple the numbers
					int decAnswer = int1 * int2;
					//Send it back into the converter
					String^ multiplicationString = Convert::ToString(decAnswer);
					answer = decToHexCalc(multiplicationString);
				}
				else if (operationDropDown->Text == "€") {
					//Divide the numbers
					int decAnswer = int1 / int2;
					//Send it back into the converter
					String^ divisionString = Convert::ToString(decAnswer);
					answer = decToHexCalc(divisionString);
				}
				//Display the Decimal number
				outputTextBox->Text = answer;
			}
			else {
				outputTextBox->Text = "Invalid Input";
			}
			
		}
//Decimal operations
		else if (calcHexDropDown->Text == "Decimal" && inputTextBox->Text != "" && input2TextBox->Text != "") {

			int goodNumber1 = validDecNumber(inputString1);

			int goodNumber2 = validDecNumber(inputString2);
			//If all set, then do the operation
			if (goodNumber1 == 1 && goodNumber2 == 1) {
				int1 = Convert::ToInt32(inputString1);
				int2 = Convert::ToInt32(inputString2);
				if (operationDropDown->Text == "+") {
					//Add up the numbers
					int additionAnswer = int1 + int2;
					//Send it back into the converter
					answer = Convert::ToString(additionAnswer);
				}
				else if (operationDropDown->Text == "-") {
					//Subtract the numbers
					int subtractionAnswer = int1 - int2;
					//Send it back into the converter
					answer = Convert::ToString(subtractionAnswer);
				}
				else if (operationDropDown->Text == "x") {
					//Multiple the numbers
					int multiplicationAnswer = int1 * int2;
					//Send it back into the converter
					answer = Convert::ToString(multiplicationAnswer);
				}
				else if (operationDropDown->Text == "€") {
					//Divide the numbers
					int divisionAnswer = int1 / int2;
					//Send it back into the converter
					answer = Convert::ToString(divisionAnswer);
				}
				//Display the Decimal number
				outputTextBox->Text = answer;
			}
			else {
				outputTextBox->Text = "Invalid Input";
			}
		}
	}
};

}
