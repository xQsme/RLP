#pragma once
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
	private: System::Windows::Forms::Label^  labelNodes;



	private: Problem problem;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart;

	private: System::Windows::Forms::TextBox^  textBoxSeed;
	private: System::Windows::Forms::TextBox^  textBoxPopulacao;
	private: System::Windows::Forms::TextBox^  textBoxGeracao;
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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			this->buttonRead = (gcnew System::Windows::Forms::Button());
			this->labelNodes = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->textBoxSeed = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPopulacao = (gcnew System::Windows::Forms::TextBox());
			this->textBoxGeracao = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonRead
			// 
			this->buttonRead->Location = System::Drawing::Point(24, 105);
			this->buttonRead->Margin = System::Windows::Forms::Padding(4);
			this->buttonRead->Name = L"buttonRead";
			this->buttonRead->Size = System::Drawing::Size(100, 28);
			this->buttonRead->TabIndex = 0;
			this->buttonRead->Text = L"Read File";
			this->buttonRead->UseVisualStyleBackColor = true;
			this->buttonRead->Click += gcnew System::EventHandler(this, &MainForm::buttonRead_Click);
			// 
			// labelNodes
			// 
			this->labelNodes->AutoSize = true;
			this->labelNodes->Location = System::Drawing::Point(179, 9);
			this->labelNodes->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelNodes->Name = L"labelNodes";
			this->labelNodes->Size = System::Drawing::Size(0, 17);
			this->labelNodes->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(21, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 17);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Seed";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(21, 40);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(75, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"População";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(21, 71);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(70, 17);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Gerações";
			// 
			// chart
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart->ChartAreas->Add(chartArea1);
			this->chart->Location = System::Drawing::Point(182, 31);
			this->chart->Name = L"chart";
			this->chart->Size = System::Drawing::Size(511, 300);
			this->chart->TabIndex = 6;
			this->chart->Text = L"chart";
			// 
			// textBoxSeed
			// 
			this->textBoxSeed->Location = System::Drawing::Point(102, 6);
			this->textBoxSeed->Name = L"textBoxSeed";
			this->textBoxSeed->Size = System::Drawing::Size(59, 22);
			this->textBoxSeed->TabIndex = 7;
			this->textBoxSeed->Text = L"5";
			// 
			// textBoxPopulacao
			// 
			this->textBoxPopulacao->Location = System::Drawing::Point(102, 37);
			this->textBoxPopulacao->Name = L"textBoxPopulacao";
			this->textBoxPopulacao->Size = System::Drawing::Size(59, 22);
			this->textBoxPopulacao->TabIndex = 8;
			this->textBoxPopulacao->Text = L"100";
			// 
			// textBoxGeracao
			// 
			this->textBoxGeracao->Location = System::Drawing::Point(102, 68);
			this->textBoxGeracao->Name = L"textBoxGeracao";
			this->textBoxGeracao->Size = System::Drawing::Size(59, 22);
			this->textBoxGeracao->TabIndex = 9;
			this->textBoxGeracao->Text = L"1000";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(707, 366);
			this->Controls->Add(this->textBoxGeracao);
			this->Controls->Add(this->textBoxPopulacao);
			this->Controls->Add(this->textBoxSeed);
			this->Controls->Add(this->chart);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->labelNodes);
			this->Controls->Add(this->buttonRead);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MainForm";
			this->Text = L"RLP";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->EndInit();
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
			try {
				problem.setUpProblem(ifs);
				labelNodes->Text = problem.getTotal() + " Nodes, " + problem.getConnections() + " Connections";
			}
			catch (const std::exception& e) {
				return;
			}
		}
	}
	private: System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		problem.libertarMemoria();
	}
};
}
