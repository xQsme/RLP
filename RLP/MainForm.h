#pragma once
#include <fstream>      // std::ifstream
#include <msclr\marshal_cppstd.h>
#include <Windows.h>
#include "Problem.h"
#include "Population.h"
#define SELECTION_PERCENTAGE 0.1
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
	private: System::Windows::Forms::TextBox^  textBoxPopulation;

	private: System::Windows::Forms::TextBox^  textBoxGenerations;


	private: System::Windows::Forms::Label^  labelFitness;


	private: System::Windows::Forms::Button^  buttonSolve;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label4;
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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->buttonRead = (gcnew System::Windows::Forms::Button());
			this->labelNodes = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->textBoxSeed = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPopulation = (gcnew System::Windows::Forms::TextBox());
			this->textBoxGenerations = (gcnew System::Windows::Forms::TextBox());
			this->labelFitness = (gcnew System::Windows::Forms::Label());
			this->buttonSolve = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonRead
			// 
			this->buttonRead->Location = System::Drawing::Point(31, 86);
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
			this->label2->Size = System::Drawing::Size(57, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Population";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(16, 58);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(64, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Generations";
			// 
			// chart
			// 
			chartArea3->Name = L"ChartArea1";
			this->chart->ChartAreas->Add(chartArea3);
			this->chart->Location = System::Drawing::Point(136, 25);
			this->chart->Margin = System::Windows::Forms::Padding(2);
			this->chart->Name = L"chart";
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series3->Name = L"RLP";
			this->chart->Series->Add(series3);
			this->chart->Size = System::Drawing::Size(383, 244);
			this->chart->TabIndex = 6;
			this->chart->Text = L"chart";
			// 
			// textBoxSeed
			// 
			this->textBoxSeed->Location = System::Drawing::Point(84, 4);
			this->textBoxSeed->Margin = System::Windows::Forms::Padding(2);
			this->textBoxSeed->Name = L"textBoxSeed";
			this->textBoxSeed->Size = System::Drawing::Size(45, 20);
			this->textBoxSeed->TabIndex = 7;
			this->textBoxSeed->Text = L"5";
			// 
			// textBoxPopulation
			// 
			this->textBoxPopulation->Location = System::Drawing::Point(84, 30);
			this->textBoxPopulation->Margin = System::Windows::Forms::Padding(2);
			this->textBoxPopulation->Name = L"textBoxPopulation";
			this->textBoxPopulation->Size = System::Drawing::Size(45, 20);
			this->textBoxPopulation->TabIndex = 8;
			this->textBoxPopulation->Text = L"100";
			// 
			// textBoxGenerations
			// 
			this->textBoxGenerations->Location = System::Drawing::Point(84, 54);
			this->textBoxGenerations->Margin = System::Windows::Forms::Padding(2);
			this->textBoxGenerations->Name = L"textBoxGenerations";
			this->textBoxGenerations->Size = System::Drawing::Size(45, 20);
			this->textBoxGenerations->TabIndex = 9;
			this->textBoxGenerations->Text = L"1000";
			// 
			// labelFitness
			// 
			this->labelFitness->AutoSize = true;
			this->labelFitness->Location = System::Drawing::Point(48, 223);
			this->labelFitness->Name = L"labelFitness";
			this->labelFitness->Size = System::Drawing::Size(0, 13);
			this->labelFitness->TabIndex = 11;
			// 
			// buttonSolve
			// 
			this->buttonSolve->Location = System::Drawing::Point(31, 115);
			this->buttonSolve->Name = L"buttonSolve";
			this->buttonSolve->Size = System::Drawing::Size(75, 23);
			this->buttonSolve->TabIndex = 12;
			this->buttonSolve->Text = L"Solve";
			this->buttonSolve->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 284);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(507, 20);
			this->textBox1->TabIndex = 13;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 268);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(81, 13);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Best Individuals";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(530, 318);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->buttonSolve);
			this->Controls->Add(this->labelFitness);
			this->Controls->Add(this->textBoxGenerations);
			this->Controls->Add(this->textBoxPopulation);
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
				currentPopulation.setUpPopulation(Int32::Parse(textBoxPopulation->Text), Int32::Parse(textBoxSeed->Text), ifs);
				currentPopulation.calculateFitness();
				labelNodes->Text = currentPopulation.getTotal() + " Nodes, " + currentPopulation.getConnections() + " Connections";
				labelFitness->Text = currentPopulation.getFitness() + " Fitness";
				chart->Series["RLP"]->Points->Clear();
				chart->Series["RLP"]->Points->AddXY(0, currentPopulation.getFitness());
				textBox1->Text = "";
				for (int i = 0; i < SELECTION_PERCENTAGE*currentPopulation.getIndividualSize(); i++) {
					textBox1->Text += currentPopulation.getTopPercent()[i] + " ";
				}
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
