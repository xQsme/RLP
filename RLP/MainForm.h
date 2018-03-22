#pragma once
#include <fstream>      // std::ifstream
#include <msclr\marshal_cppstd.h>
#include <Windows.h>
#include "Problem.h"
#include "Population.h"
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

	private: Population currentPopulation;
	private: Population nextPopulation;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart;

	private: System::Windows::Forms::TextBox^  textBoxSeed;
	private: System::Windows::Forms::TextBox^  textBoxPopulacao;
	private: System::Windows::Forms::TextBox^  textBoxGeracoes;

	private: System::Windows::Forms::Label^  labelFitness;


	private: System::Windows::Forms::Button^  buttonSolve;
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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->buttonRead = (gcnew System::Windows::Forms::Button());
			this->labelNodes = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->textBoxSeed = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPopulacao = (gcnew System::Windows::Forms::TextBox());
			this->textBoxGeracoes = (gcnew System::Windows::Forms::TextBox());
			this->labelFitness = (gcnew System::Windows::Forms::Label());
			this->buttonSolve = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonRead
			// 
			this->buttonRead->Location = System::Drawing::Point(18, 85);
			this->buttonRead->Name = L"buttonRead";
			this->buttonRead->Size = System::Drawing::Size(75, 23);
			this->buttonRead->TabIndex = 0;
			this->buttonRead->Text = L"Read File";
			this->buttonRead->UseVisualStyleBackColor = true;
			this->buttonRead->Click += gcnew System::EventHandler(this, &MainForm::buttonRead_Click);
			// 
			// labelNodes
			// 
			this->labelNodes->AutoSize = true;
			this->labelNodes->Location = System::Drawing::Point(134, 7);
			this->labelNodes->Name = L"labelNodes";
			this->labelNodes->Size = System::Drawing::Size(0, 13);
			this->labelNodes->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(16, 7);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(32, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Seed";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(16, 32);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"População";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(16, 58);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Gerações";
			// 
			// chart
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart->ChartAreas->Add(chartArea2);
			this->chart->Location = System::Drawing::Point(136, 25);
			this->chart->Margin = System::Windows::Forms::Padding(2);
			this->chart->Name = L"chart";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Name = L"RLP";
			this->chart->Series->Add(series2);
			this->chart->Size = System::Drawing::Size(383, 244);
			this->chart->TabIndex = 6;
			this->chart->Text = L"chart";
			// 
			// textBoxSeed
			// 
			this->textBoxSeed->Location = System::Drawing::Point(76, 5);
			this->textBoxSeed->Margin = System::Windows::Forms::Padding(2);
			this->textBoxSeed->Name = L"textBoxSeed";
			this->textBoxSeed->Size = System::Drawing::Size(45, 20);
			this->textBoxSeed->TabIndex = 7;
			this->textBoxSeed->Text = L"5";
			// 
			// textBoxPopulacao
			// 
			this->textBoxPopulacao->Location = System::Drawing::Point(76, 30);
			this->textBoxPopulacao->Margin = System::Windows::Forms::Padding(2);
			this->textBoxPopulacao->Name = L"textBoxPopulacao";
			this->textBoxPopulacao->Size = System::Drawing::Size(45, 20);
			this->textBoxPopulacao->TabIndex = 8;
			this->textBoxPopulacao->Text = L"100";
			// 
			// textBoxGeracoes
			// 
			this->textBoxGeracoes->Location = System::Drawing::Point(76, 55);
			this->textBoxGeracoes->Margin = System::Windows::Forms::Padding(2);
			this->textBoxGeracoes->Name = L"textBoxGeracoes";
			this->textBoxGeracoes->Size = System::Drawing::Size(45, 20);
			this->textBoxGeracoes->TabIndex = 9;
			this->textBoxGeracoes->Text = L"1000";
			// 
			// labelFitness
			// 
			this->labelFitness->AutoSize = true;
			this->labelFitness->Location = System::Drawing::Point(16, 256);
			this->labelFitness->Name = L"labelFitness";
			this->labelFitness->Size = System::Drawing::Size(0, 13);
			this->labelFitness->TabIndex = 11;
			// 
			// buttonSolve
			// 
			this->buttonSolve->Location = System::Drawing::Point(19, 115);
			this->buttonSolve->Name = L"buttonSolve";
			this->buttonSolve->Size = System::Drawing::Size(75, 23);
			this->buttonSolve->TabIndex = 12;
			this->buttonSolve->Text = L"Solve";
			this->buttonSolve->UseVisualStyleBackColor = true;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(530, 278);
			this->Controls->Add(this->buttonSolve);
			this->Controls->Add(this->labelFitness);
			this->Controls->Add(this->textBoxGeracoes);
			this->Controls->Add(this->textBoxPopulacao);
			this->Controls->Add(this->textBoxSeed);
			this->Controls->Add(this->chart);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->labelNodes);
			this->Controls->Add(this->buttonRead);
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
				currentPopulation.setUpPopulation(Int32::Parse(textBoxPopulacao->Text), Int32::Parse(textBoxSeed->Text), ifs);
				labelNodes->Text = currentPopulation.getTotal() + " Nodes, " + currentPopulation.getConnections() + " Connections";
				labelFitness->Text = currentPopulation.getFitness() + " Fitness";
				chart->Series["RLP"]->Points->AddXY(0, currentPopulation.getFitness());
			}
			catch (const std::exception& e) {
				return;
			}
		}
	}
	private: System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		currentPopulation.libertarMemoria();
		nextPopulation.libertarMemoria();
	}
};
}
