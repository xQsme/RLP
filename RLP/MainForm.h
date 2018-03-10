#pragma once
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <msclr\marshal_cppstd.h>
#include "Problem.h"

namespace RLP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonRead;
	private: System::Windows::Forms::RichTextBox^  textBox;

	private: System::Windows::Forms::Label^  labelTextBox;
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
			this->buttonRead = (gcnew System::Windows::Forms::Button());
			this->textBox = (gcnew System::Windows::Forms::RichTextBox());
			this->labelTextBox = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// buttonRead
			// 
			this->buttonRead->Location = System::Drawing::Point(12, 520);
			this->buttonRead->Name = L"buttonRead";
			this->buttonRead->Size = System::Drawing::Size(75, 23);
			this->buttonRead->TabIndex = 0;
			this->buttonRead->Text = L"Read File";
			this->buttonRead->UseVisualStyleBackColor = true;
			this->buttonRead->Click += gcnew System::EventHandler(this, &MainForm::buttonRead_Click);
			// 
			// textBox
			// 
			this->textBox->Location = System::Drawing::Point(33, 29);
			this->textBox->Name = L"textBox";
			this->textBox->Size = System::Drawing::Size(629, 459);
			this->textBox->TabIndex = 1;
			this->textBox->Text = L"";
			// 
			// labelTextBox
			// 
			this->labelTextBox->AutoSize = true;
			this->labelTextBox->Location = System::Drawing::Point(30, 9);
			this->labelTextBox->Name = L"labelTextBox";
			this->labelTextBox->Size = System::Drawing::Size(38, 13);
			this->labelTextBox->TabIndex = 2;
			this->labelTextBox->Text = L"Nodes";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(700, 555);
			this->Controls->Add(this->labelTextBox);
			this->Controls->Add(this->textBox);
			this->Controls->Add(this->buttonRead);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonRead_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog openFileDialog;
		openFileDialog.Filter = "Text Files|*.txt";
		openFileDialog.Title = "Select a Text File";
		openFileDialog.ShowDialog();
		msclr::interop::marshal_context context;
		std::ifstream ifs(context.marshal_as<std::string>(openFileDialog.FileName) + "", std::ifstream::in);
		if (ifs.good()) {
			System::String ^text;
			try {
				Problem problem(ifs);
				labelTextBox->Text = problem.getTotal() + " Nodes, " + problem.getConnections() + " Connections";
				if (problem.hasWeights() == 1) {
					for (int j = 0; j < problem.getTotal(); j++) {
						text += problem.getWeights()[j] + "  ";
					}
					text += "\n\n";
				}
				for (int i = 0; i < problem.getTotal(); i++) {
					for (int j = 0; j < problem.getTotal(); j++) {
						text += problem.getNodes()[i][j] + "  ";
					}
					text += "\n";
				}
				textBox->Text = text;
			}
			catch (const std::exception& e) {
				textBox->Text = "Error reading file, select an appropriate file.";
				return;
			}
		}
	}
	};
}
