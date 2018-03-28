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
	using namespace System::Threading;

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

	private: Population population;
	private: int generation = 0;
	private: Thread^ t = gcnew Thread(gcnew ThreadStart(this, &MainForm::solve));
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart;

	private: System::Windows::Forms::TextBox^  textBoxSeed;
	private: System::Windows::Forms::TextBox^  textBoxPopulation;

	private: System::Windows::Forms::TextBox^  textBoxGenerations;


	private: System::Windows::Forms::Label^  labelFitness;


	private: System::Windows::Forms::Button^  buttonSolve;
	private: System::Windows::Forms::Label^  labelRegenerators;
	private: System::Windows::Forms::Label^  labelDisconnected;
	private: System::Windows::Forms::Label^  labelElitism;
	private: System::Windows::Forms::TextBox^  textBoxElitism;

	private: System::Windows::Forms::Label^  labelMutation;
	private: System::Windows::Forms::TextBox^  textBoxMutation;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;


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
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
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
			this->labelRegenerators = (gcnew System::Windows::Forms::Label());
			this->labelDisconnected = (gcnew System::Windows::Forms::Label());
			this->labelElitism = (gcnew System::Windows::Forms::Label());
			this->textBoxElitism = (gcnew System::Windows::Forms::TextBox());
			this->labelMutation = (gcnew System::Windows::Forms::Label());
			this->textBoxMutation = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonRead
			// 
			this->buttonRead->Location = System::Drawing::Point(31, 127);
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
			this->labelNodes->Location = System::Drawing::Point(141, 7);
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
			chartArea1->AxisX->Title = L"Generations";
			chartArea1->AxisY->Title = L"Fitness";
			chartArea1->Name = L"ChartArea1";
			this->chart->ChartAreas->Add(chartArea1);
			this->chart->Location = System::Drawing::Point(144, 20);
			this->chart->Margin = System::Windows::Forms::Padding(2);
			this->chart->Name = L"chart";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Name = L"RLP";
			this->chart->Series->Add(series1);
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
			this->textBoxSeed->Text = L"50";
			this->textBoxSeed->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// textBoxPopulation
			// 
			this->textBoxPopulation->Location = System::Drawing::Point(84, 30);
			this->textBoxPopulation->Margin = System::Windows::Forms::Padding(2);
			this->textBoxPopulation->Name = L"textBoxPopulation";
			this->textBoxPopulation->Size = System::Drawing::Size(45, 20);
			this->textBoxPopulation->TabIndex = 8;
			this->textBoxPopulation->Text = L"150";
			this->textBoxPopulation->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// textBoxGenerations
			// 
			this->textBoxGenerations->Location = System::Drawing::Point(84, 54);
			this->textBoxGenerations->Margin = System::Windows::Forms::Padding(2);
			this->textBoxGenerations->Name = L"textBoxGenerations";
			this->textBoxGenerations->Size = System::Drawing::Size(45, 20);
			this->textBoxGenerations->TabIndex = 9;
			this->textBoxGenerations->Text = L"350";
			this->textBoxGenerations->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// labelFitness
			// 
			this->labelFitness->AutoSize = true;
			this->labelFitness->Location = System::Drawing::Point(1, 240);
			this->labelFitness->Name = L"labelFitness";
			this->labelFitness->Size = System::Drawing::Size(46, 13);
			this->labelFitness->TabIndex = 11;
			this->labelFitness->Text = L"Fitness: ";
			// 
			// buttonSolve
			// 
			this->buttonSolve->Location = System::Drawing::Point(31, 156);
			this->buttonSolve->Name = L"buttonSolve";
			this->buttonSolve->Size = System::Drawing::Size(75, 23);
			this->buttonSolve->TabIndex = 12;
			this->buttonSolve->Text = L"Solve";
			this->buttonSolve->UseVisualStyleBackColor = true;
			this->buttonSolve->Click += gcnew System::EventHandler(this, &MainForm::buttonSolve_Click);
			// 
			// labelRegenerators
			// 
			this->labelRegenerators->AutoSize = true;
			this->labelRegenerators->Location = System::Drawing::Point(1, 217);
			this->labelRegenerators->Name = L"labelRegenerators";
			this->labelRegenerators->Size = System::Drawing::Size(77, 13);
			this->labelRegenerators->TabIndex = 13;
			this->labelRegenerators->Text = L"Regenerators: ";
			// 
			// labelDisconnected
			// 
			this->labelDisconnected->AutoSize = true;
			this->labelDisconnected->Location = System::Drawing::Point(1, 191);
			this->labelDisconnected->Name = L"labelDisconnected";
			this->labelDisconnected->Size = System::Drawing::Size(79, 13);
			this->labelDisconnected->TabIndex = 14;
			this->labelDisconnected->Text = L"Disconnected: ";
			// 
			// labelElitism
			// 
			this->labelElitism->AutoSize = true;
			this->labelElitism->Location = System::Drawing::Point(16, 81);
			this->labelElitism->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelElitism->Name = L"labelElitism";
			this->labelElitism->Size = System::Drawing::Size(36, 13);
			this->labelElitism->TabIndex = 15;
			this->labelElitism->Text = L"Elitism";
			// 
			// textBoxElitism
			// 
			this->textBoxElitism->Location = System::Drawing::Point(84, 78);
			this->textBoxElitism->Margin = System::Windows::Forms::Padding(2);
			this->textBoxElitism->Name = L"textBoxElitism";
			this->textBoxElitism->Size = System::Drawing::Size(45, 20);
			this->textBoxElitism->TabIndex = 16;
			this->textBoxElitism->Text = L"50";
			this->textBoxElitism->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// labelMutation
			// 
			this->labelMutation->AutoSize = true;
			this->labelMutation->Location = System::Drawing::Point(16, 105);
			this->labelMutation->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelMutation->Name = L"labelMutation";
			this->labelMutation->Size = System::Drawing::Size(48, 13);
			this->labelMutation->TabIndex = 17;
			this->labelMutation->Text = L"Mutation";
			// 
			// textBoxMutation
			// 
			this->textBoxMutation->Location = System::Drawing::Point(84, 102);
			this->textBoxMutation->Margin = System::Windows::Forms::Padding(2);
			this->textBoxMutation->Name = L"textBoxMutation";
			this->textBoxMutation->Size = System::Drawing::Size(45, 20);
			this->textBoxMutation->TabIndex = 18;
			this->textBoxMutation->Text = L"5";
			this->textBoxMutation->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(129, 81);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(15, 13);
			this->label4->TabIndex = 19;
			this->label4->Text = L"%";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(129, 105);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(15, 13);
			this->label5->TabIndex = 20;
			this->label5->Text = L"%";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(538, 266);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBoxMutation);
			this->Controls->Add(this->labelMutation);
			this->Controls->Add(this->textBoxElitism);
			this->Controls->Add(this->labelElitism);
			this->Controls->Add(this->labelDisconnected);
			this->Controls->Add(this->labelRegenerators);
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
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonRead_Click(System::Object^  sender, System::EventArgs^  e) {
		//Abrir Selecionador de Ficheiro de Texto
		OpenFileDialog openFileDialog;
		openFileDialog.Filter = "Text Files|*.txt";
		openFileDialog.Title = "Select a Text File";
		openFileDialog.ShowDialog();
		//contexto serve para converter a string do dialog para uma string que o stream aceita
		msclr::interop::marshal_context context;
		//instanciar o stream
		std::ifstream ifs(context.marshal_as<std::string>(openFileDialog.FileName) + "", std::ifstream::in);
		if (ifs.good()) {
			try {
				generation = 0;
				population.setUpPopulation(Int32::Parse(textBoxPopulation->Text), Int32::Parse(textBoxSeed->Text), Int32::Parse(textBoxElitism->Text), Int32::Parse(textBoxMutation->Text), ifs);
				population.calculateFitness();
				//atualiza o form
				labelNodes->Text = population.getTotal() + " Nodes, " + population.getConnections() + " Connections";
				labelDisconnected->Text = "Disconnected: " + population.getDisconnected();
				labelRegenerators->Text = "Regenerators: " + population.getRegenerators();
				labelFitness->Text = "Fitness: " + population.getFitness();
				chart->Series["RLP"]->Points->Clear();
				chart->Series["RLP"]->Points->AddXY(generation, population.getFitness());
				generation++;
			}
			catch (const std::exception& e) {
				return;
			}
		}
	}
	private: System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		t->Abort();
		population.libertarMemoria();
	}
	private: System::Void buttonSolve_Click(System::Object^  sender, System::EventArgs^  e) {
		if (buttonSolve->Text == "Solve") {
			disableForm();
			t = gcnew Thread(gcnew ThreadStart(this, &MainForm::solve));
			t->Start();
		}
		else {
			enableForm();
			t->Abort();
		}
	}

private: void solve() {
	//Verificar se os dados da população sao diferentes do form, ou se ja chegou à ultima geração
	//Se forem diferentes gera uma nova população
	if (generation >= Int32::Parse(textBoxGenerations->Text) || Int32::Parse(textBoxPopulation->Text) != population.getPopulationSize() 
		|| Int32::Parse(textBoxElitism->Text) != population.getElitism() * 100 || Int32::Parse(textBoxMutation->Text) != population.getMutation() * 100 
		|| Int32::Parse(textBoxSeed->Text) != population.getSeed()) {
		generation = 0;
		population.setUpPopulation(Int32::Parse(textBoxPopulation->Text), Int32::Parse(textBoxSeed->Text), Int32::Parse(textBoxElitism->Text), Int32::Parse(textBoxMutation->Text));
		population.calculateFitness();
		generation++;
	}
	//A thread nao pode alterar o form, contudo pode pedir à outra thread para o fazer
	this->Invoke(gcnew MethodInvoker(this, &MainForm::clearForm));
	if (population.getTotal() > 0) {
		for (generation; generation <= Int32::Parse(textBoxGenerations->Text); generation++) {
			generateNewPopulation();
			population.calculateFitness();
			this->Invoke(gcnew MethodInvoker(this, &MainForm::updateForm));
		}
	}
	else {
		this->Invoke(gcnew MethodInvoker(this, &MainForm::alertSelectFile));
	}
}

private: void generateNewPopulation() {
	//Selected é o indice onde acabam os individuos que foram mantidos (Elitismo), estes não são alterados
	int selected = population.getElitism() * population.getPopulationSize();
	//Reprodução
	for (int i = selected; i < population.getPopulationSize(); i++) {
		for (int j = 0; j < population.getIndividualSize(); j++) {
			if (selected != 0) { //Para nao dividir por 0
				population.getIndividuals()[i][j] = population.getIndividuals()[rand() % selected][j];
				//cada nó dum individuo não selecionado, toma um valor dum nó dum individuo selecionado
			}
		}
	}
	//Mutação
	int zeroes, ones;
	for (int j = 0; j < population.getIndividualSize(); j++) {
		zeroes = ones = 0;
		for (int i = 0; i < selected; i++) {
			if (population.getIndividuals()[i][j] == 0) {
				zeroes++;
			}
			else {
				ones++;
			}
		}
		//A partir do selecionados até metade dos restantes
		//quando naquela coluna os selecionados apenas têm 1s
		if (zeroes == 0) {
			for (int i = selected; i < (population.getPopulationSize()-selected) / 2 + selected; i++) {
				if (rand() % (int)(1 / population.getMutation()) == 0) { //conforme a probabilidade de mutação
					population.getIndividuals()[i][j] = 0; //alguns nós passam a 0
				}
			}
		}
		//quando naquela coluna os selecionados apenas têm 0s
		if (ones == 0) {
			for (int i = selected; i < (population.getPopulationSize() - selected) / 2 + selected; i++) {
				if (rand() % (int)(1 / population.getMutation()) == 0) {
					population.getIndividuals()[i][j] = 1; //alguns nós passam a 1
				}
			}
		}

		//A partir de metade dos restantes até ao final da população
		for (int i = (population.getPopulationSize() - selected) / 2 + selected; i < population.getPopulationSize(); i++) {
			if (rand() % (int)(1 / population.getMutation()) == 0) { //Conforme a probabilidade de mutação
				population.getIndividuals()[i][j] = rand() % 2; //É atribuido um valor 0 ou 1 random
			}
		}
	}
}

private: void disableForm() {
	textBoxElitism->Enabled = false;
	textBoxMutation->Enabled = false;
	textBoxGenerations->Enabled = false;
	textBoxSeed->Enabled = false;
	textBoxPopulation->Enabled = false;
	buttonRead->Enabled = false;
	buttonSolve->Text = "Stop";
}

private: void enableForm() {
	textBoxElitism->Enabled = true;
	textBoxMutation->Enabled = true;
	textBoxGenerations->Enabled = true;
	textBoxSeed->Enabled = true;
	textBoxPopulation->Enabled = true;
	buttonRead->Enabled = true;
	buttonSolve->Text = "Solve";
}

private: void alertSelectFile() {
	MessageBox::Show(this, "Please select a file first");
	enableForm();
}

private: void clearForm() {
	chart->Series["RLP"]->Points->Clear();
	chart->Series["RLP"]->Points->AddXY(generation, population.getFitness());
	chart->ChartAreas[0]->AxisX->Maximum = NAN;
	chart->ChartAreas[0]->RecalculateAxesScale();
}

private: void updateForm() {
	chart->Series["RLP"]->Points->AddXY(generation, population.getFitness());
	if (generation == Int32::Parse(textBoxGenerations->Text)) {
		chart->ChartAreas[0]->AxisX->Maximum = generation;
		enableForm();
	}
	labelDisconnected->Text = "Disconnected: " + population.getDisconnected();
	labelRegenerators->Text = "Regenerators: " + population.getRegenerators();
	labelFitness->Text = "Fitness: " + population.getFitness();
}

private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
	chart->ChartAreas[0]->AxisX->Minimum = 0;
}
};
}
