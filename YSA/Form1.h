#pragma once
#include "Sample.h"
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Process.h"
namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//using namespace std;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			pictureBox1->Width = 500;
			pictureBox1->Height = 500;
			classCount = 0;
			size = 0;
			comboBoxClassCount->SelectedIndex = 0;
			comboBox1->SelectedIndex = 0;

			comboBoxClassColors->Enabled = false;
			colors = gcnew array<Color>(6) { Color::Purple, Color::Red, Color::Green, Color::Blue, Color::DarkSlateGray, Color::Orange };
			surface = gcnew Bitmap(500, 500);
			pictureBox1->Image = surface;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
				delete W;
				delete desiredValue;
				delete numOfElements;
				delete samples;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ processesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ýnitialToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ randomlyToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::ComboBox^ comboBoxClassCount;
	private: System::Windows::Forms::ComboBox^ comboBoxClassColors;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ buttonSave;
	private: System::Windows::Forms::Label^ labelPoints;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		/// 
		int classCount;
		array<Color>^ colors;
		Sample* samples;
		int* numOfElements;
		int* desiredValue;
		int size;
		Bitmap^ surface;
		double* W;
		int numOfNeurons;
		int hLayerCount;
		Layer* layers;
		int* neurons;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ToolStripMenuItem^ tRaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ perceptronToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ deltaToolStripMenuItem;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ labelError;

	private: System::Windows::Forms::ToolStripMenuItem^ multiLayerTrainToolStripMenuItem;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label6;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ buttonLayers;
	private: System::Windows::Forms::CheckBox^ checkBoxMoment;
	private: System::Windows::Forms::ToolStripMenuItem^ savingdatasetToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ savesamplesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveweightToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ readDataToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ readSamplesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ readWeightToolStripMenuItem;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;



	private: System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1;
	private: System::Windows::Forms::DataVisualization::Charting::Legend^ legend1;
	private: System::Windows::Forms::DataVisualization::Charting::Series^ series1;



		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   /// 

		   void InitializeComponent(void)
		   {
			   this->chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			   this->legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			   this->series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			   this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			   this->processesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->ýnitialToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->randomlyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->tRaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->perceptronToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->deltaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->multiLayerTrainToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->savingdatasetToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->savesamplesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->saveweightToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->readDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->readSamplesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->readWeightToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->comboBoxClassCount = (gcnew System::Windows::Forms::ComboBox());
			   this->comboBoxClassColors = (gcnew System::Windows::Forms::ComboBox());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->buttonSave = (gcnew System::Windows::Forms::Button());
			   this->labelPoints = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->labelError = (gcnew System::Windows::Forms::Label());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->buttonLayers = (gcnew System::Windows::Forms::Button());
			   this->checkBoxMoment = (gcnew System::Windows::Forms::CheckBox());
			   this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			   this->menuStrip1->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // menuStrip1
			   // 
			   this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			   this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->processesToolStripMenuItem });
			   this->menuStrip1->Location = System::Drawing::Point(0, 0);
			   this->menuStrip1->Name = L"menuStrip1";
			   this->menuStrip1->Size = System::Drawing::Size(1186, 28);
			   this->menuStrip1->TabIndex = 0;
			   this->menuStrip1->Text = L"menuStrip1";
			   // 
			   // processesToolStripMenuItem
			   // 
			   this->processesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				   this->ýnitialToolStripMenuItem,
					   this->tRaToolStripMenuItem, this->multiLayerTrainToolStripMenuItem, this->savingdatasetToolStripMenuItem, this->readDataToolStripMenuItem
			   });
			   this->processesToolStripMenuItem->Name = L"processesToolStripMenuItem";
			   this->processesToolStripMenuItem->Size = System::Drawing::Size(86, 24);
			   this->processesToolStripMenuItem->Text = L"Processes";
			   // 
			   // ýnitialToolStripMenuItem
			   // 
			   this->ýnitialToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->randomlyToolStripMenuItem });
			   this->ýnitialToolStripMenuItem->Name = L"ýnitialToolStripMenuItem";
			   this->ýnitialToolStripMenuItem->Size = System::Drawing::Size(201, 26);
			   this->ýnitialToolStripMenuItem->Text = L"Initial";
			   // 
			   // randomlyToolStripMenuItem
			   // 
			   this->randomlyToolStripMenuItem->Name = L"randomlyToolStripMenuItem";
			   this->randomlyToolStripMenuItem->Size = System::Drawing::Size(159, 26);
			   this->randomlyToolStripMenuItem->Text = L"Randomly";
			   this->randomlyToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::randomlyToolStripMenuItem_Click);
			   // 
			   // tRaToolStripMenuItem
			   // 
			   this->tRaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				   this->perceptronToolStripMenuItem,
					   this->deltaToolStripMenuItem
			   });
			   this->tRaToolStripMenuItem->Name = L"tRaToolStripMenuItem";
			   this->tRaToolStripMenuItem->Size = System::Drawing::Size(201, 26);
			   this->tRaToolStripMenuItem->Text = L"Train";
			   // 
			   // perceptronToolStripMenuItem
			   // 
			   this->perceptronToolStripMenuItem->Name = L"perceptronToolStripMenuItem";
			   this->perceptronToolStripMenuItem->Size = System::Drawing::Size(163, 26);
			   this->perceptronToolStripMenuItem->Text = L"Perceptron";
			   this->perceptronToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::perceptronToolStripMenuItem_Click);
			   // 
			   // deltaToolStripMenuItem
			   // 
			   this->deltaToolStripMenuItem->Name = L"deltaToolStripMenuItem";
			   this->deltaToolStripMenuItem->Size = System::Drawing::Size(163, 26);
			   this->deltaToolStripMenuItem->Text = L"Delta";
			   this->deltaToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::deltaToolStripMenuItem_Click);
			   // 
			   // multiLayerTrainToolStripMenuItem
			   // 
			   this->multiLayerTrainToolStripMenuItem->Name = L"multiLayerTrainToolStripMenuItem";
			   this->multiLayerTrainToolStripMenuItem->Size = System::Drawing::Size(201, 26);
			   this->multiLayerTrainToolStripMenuItem->Text = L"Multi Layer Train";
			   this->multiLayerTrainToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::multiLayerTrainToolStripMenuItem_Click);
			   // 
			   // savingdatasetToolStripMenuItem
			   // 
			   this->savingdatasetToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				   this->savesamplesToolStripMenuItem,
					   this->saveweightToolStripMenuItem
			   });
			   this->savingdatasetToolStripMenuItem->Name = L"savingdatasetToolStripMenuItem";
			   this->savingdatasetToolStripMenuItem->Size = System::Drawing::Size(201, 26);
			   this->savingdatasetToolStripMenuItem->Text = L"Saving Data Set";
			   // 
			   // savesamplesToolStripMenuItem
			   // 
			   this->savesamplesToolStripMenuItem->Name = L"savesamplesToolStripMenuItem";
			   this->savesamplesToolStripMenuItem->Size = System::Drawing::Size(183, 26);
			   this->savesamplesToolStripMenuItem->Text = L"Save Samples";
			   this->savesamplesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::savesamplesToolStripMenuItem_Click);
			   // 
			   // saveweightToolStripMenuItem
			   // 
			   this->saveweightToolStripMenuItem->Name = L"saveweightToolStripMenuItem";
			   this->saveweightToolStripMenuItem->Size = System::Drawing::Size(183, 26);
			   this->saveweightToolStripMenuItem->Text = L"Save Weight";
			   this->saveweightToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveweightToolStripMenuItem_Click);
			   // 
			   // readDataToolStripMenuItem
			   // 
			   this->readDataToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				   this->readSamplesToolStripMenuItem,
					   this->readWeightToolStripMenuItem
			   });
			   this->readDataToolStripMenuItem->Name = L"readDataToolStripMenuItem";
			   this->readDataToolStripMenuItem->Size = System::Drawing::Size(201, 26);
			   this->readDataToolStripMenuItem->Text = L"Read Data";
			   // 
			   // readSamplesToolStripMenuItem
			   // 
			   this->readSamplesToolStripMenuItem->Name = L"readSamplesToolStripMenuItem";
			   this->readSamplesToolStripMenuItem->Size = System::Drawing::Size(186, 26);
			   this->readSamplesToolStripMenuItem->Text = L"Read Samples";
			   this->readSamplesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::readSamplesToolStripMenuItem_Click);
			   // 
			   // readWeightToolStripMenuItem
			   // 
			   this->readWeightToolStripMenuItem->Name = L"readWeightToolStripMenuItem";
			   this->readWeightToolStripMenuItem->Size = System::Drawing::Size(186, 26);
			   this->readWeightToolStripMenuItem->Text = L"Read Weight";
			   this->readWeightToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::readWeightToolStripMenuItem_Click);
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->pictureBox1->Location = System::Drawing::Point(12, 42);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(500, 500);
			   this->pictureBox1->TabIndex = 1;
			   this->pictureBox1->TabStop = false;
			   this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			   this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::OnPictureBoxMouseClick);
			   // 
			   // comboBoxClassCount
			   // 
			   this->comboBoxClassCount->FormattingEnabled = true;
			   this->comboBoxClassCount->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"2", L"3", L"4", L"5", L"6" });
			   this->comboBoxClassCount->Location = System::Drawing::Point(692, 61);
			   this->comboBoxClassCount->Name = L"comboBoxClassCount";
			   this->comboBoxClassCount->Size = System::Drawing::Size(121, 24);
			   this->comboBoxClassCount->TabIndex = 2;
			   // 
			   // comboBoxClassColors
			   // 
			   this->comboBoxClassColors->FormattingEnabled = true;
			   this->comboBoxClassColors->Location = System::Drawing::Point(692, 91);
			   this->comboBoxClassColors->Name = L"comboBoxClassColors";
			   this->comboBoxClassColors->Size = System::Drawing::Size(121, 24);
			   this->comboBoxClassColors->TabIndex = 3;
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(689, 42);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(72, 16);
			   this->label1->TabIndex = 4;
			   this->label1->Text = L"Sýnýf Sayýsý";
			   // 
			   // buttonSave
			   // 
			   this->buttonSave->Location = System::Drawing::Point(841, 62);
			   this->buttonSave->Name = L"buttonSave";
			   this->buttonSave->Size = System::Drawing::Size(75, 23);
			   this->buttonSave->TabIndex = 5;
			   this->buttonSave->Text = L"Kaydet";
			   this->buttonSave->UseVisualStyleBackColor = true;
			   this->buttonSave->Click += gcnew System::EventHandler(this, &Form1::buttonSave_Click);
			   // 
			   // labelPoints
			   // 
			   this->labelPoints->AutoSize = true;
			   this->labelPoints->Location = System::Drawing::Point(689, 144);
			   this->labelPoints->Name = L"labelPoints";
			   this->labelPoints->Size = System::Drawing::Size(50, 16);
			   this->labelPoints->TabIndex = 6;
			   this->labelPoints->Text = L"X: -  Y: -";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(689, 160);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(83, 16);
			   this->label2->TabIndex = 7;
			   this->label2->Text = L"Örnek Sayýsý";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(841, 144);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(20, 16);
			   this->label3->TabIndex = 8;
			   this->label3->Text = L"W";
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Location = System::Drawing::Point(692, 196);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(44, 16);
			   this->label4->TabIndex = 9;
			   this->label4->Text = L"Cycle:";
			   // 
			   // labelError
			   // 
			   this->labelError->AutoSize = true;
			   this->labelError->Location = System::Drawing::Point(692, 216);
			   this->labelError->Name = L"labelError";
			   this->labelError->Size = System::Drawing::Size(39, 16);
			   this->labelError->TabIndex = 10;
			   this->labelError->Text = L"Error:";
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Location = System::Drawing::Point(689, 239);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(116, 16);
			   this->label5->TabIndex = 13;
			   this->label5->Text = L"Ara Katman Sayýsý";
			   // 
			   // comboBox1
			   // 
			   this->comboBox1->FormattingEnabled = true;
			   this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"1", L"2", L"3", L"4", L"5" });
			   this->comboBox1->Location = System::Drawing::Point(692, 259);
			   this->comboBox1->Name = L"comboBox1";
			   this->comboBox1->Size = System::Drawing::Size(121, 24);
			   this->comboBox1->TabIndex = 14;
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->Location = System::Drawing::Point(692, 290);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(84, 16);
			   this->label6->TabIndex = 15;
			   this->label6->Text = L"Nöron Sayýsý";
			   // 
			   // textBox1
			   // 
			   this->textBox1->Location = System::Drawing::Point(695, 309);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(100, 22);
			   this->textBox1->TabIndex = 16;
			   // 
			   // buttonLayers
			   // 
			   this->buttonLayers->Location = System::Drawing::Point(844, 259);
			   this->buttonLayers->Name = L"buttonLayers";
			   this->buttonLayers->Size = System::Drawing::Size(75, 47);
			   this->buttonLayers->TabIndex = 17;
			   this->buttonLayers->Text = L"Layer Kaydet";
			   this->buttonLayers->UseVisualStyleBackColor = true;
			   this->buttonLayers->Click += gcnew System::EventHandler(this, &Form1::buttonLayers_Click);
			   // 
			   // checkBoxMoment
			   // 
			   this->checkBoxMoment->AutoSize = true;
			   this->checkBoxMoment->Location = System::Drawing::Point(957, 259);
			   this->checkBoxMoment->Name = L"checkBoxMoment";
			   this->checkBoxMoment->Size = System::Drawing::Size(77, 20);
			   this->checkBoxMoment->TabIndex = 18;
			   this->checkBoxMoment->Text = L"Moment";
			   this->checkBoxMoment->UseVisualStyleBackColor = true;
			   // 
			   // chart1
			   // 
			   this->chartArea1->Name = L"ChartArea1";
			   this->chart1->ChartAreas->Add(chartArea1);
			   this->legend1->Name = L"Legend1";
			   this->chart1->Legends->Add(legend1);
			   this->chart1->Location = System::Drawing::Point(700, 350);
			   this->chart1->Name = L"chart1";
			   this->series1->ChartArea = L"ChartArea1";
			   this->series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			   this->series1->Legend = L"Legend1";
			   this->series1->Name = L"Series1";
			   this->chart1->Series->Add(series1);
			   this->chart1->Size = System::Drawing::Size(600, 330);
			   this->chart1->TabIndex = 19;
			   this->chart1->Text = L"chart1";
			   // 
			   // Form1
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1286, 690);
			   this->Controls->Add(this->chart1);
			   this->Controls->Add(this->checkBoxMoment);
			   this->Controls->Add(this->buttonLayers);
			   this->Controls->Add(this->textBox1);
			   this->Controls->Add(this->label6);
			   this->Controls->Add(this->comboBox1);
			   this->Controls->Add(this->label5);
			   this->Controls->Add(this->labelError);
			   this->Controls->Add(this->label4);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->labelPoints);
			   this->Controls->Add(this->buttonSave);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->comboBoxClassColors);
			   this->Controls->Add(this->comboBoxClassCount);
			   this->Controls->Add(this->pictureBox1);
			   this->Controls->Add(this->menuStrip1);
			   this->MainMenuStrip = this->menuStrip1;
			   this->Name = L"Form1";
			   this->Text = L"Form1";
			   this->menuStrip1->ResumeLayout(false);
			   this->menuStrip1->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
		   void drawLine(int neuronNo) {
			   Graphics^ g = Graphics::FromImage(surface);
			   Pen^ pen = gcnew Pen(colors[neuronNo], 2);
			   double* tempw = new double[DIMENSION + 1];
			   tempw[0] = W[neuronNo * (DIMENSION + 1)];
			   tempw[1] = W[neuronNo * (DIMENSION + 1) + 1];
			   tempw[2] = W[neuronNo * (DIMENSION + 1) + 2];

			   int min_x = pictureBox1->Width / -2;
			   int min_y = YPoint(min_x, tempw, 50);
			   int max_x = pictureBox1->Height / 2;
			   int max_y = YPoint(max_x, tempw, 50);

			   g->DrawLine(pen, (pictureBox1->Width / 2) + min_x, (pictureBox1->Height / 2) - min_y, (pictureBox1->Width / 2) + max_x, (pictureBox1->Height / 2) - max_y);
			   //pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x, (pictureBox1->Height / 2) - min_y, (pictureBox1->Width / 2) + max_x, (pictureBox1->Height / 2) - max_y);

		   }
		   void testForMultiLayer(double* mean, double* std) {
			   Graphics^ g = Graphics::FromImage(surface);
			   System::Drawing::Color color = Color::White;
			   double* x = new double[DIMENSION];
			   double max = -9999999;
			   int label = -1;
			   int k, l, j;
			   double net;

			   for (int h = 0; h < pictureBox1->Height; h += 2) {
				   for (int w = 0; w < pictureBox1->Width; w += 2) {
					   x[0] = (double)(w - (pictureBox1->Width / 2));
					   x[1] = (double)((pictureBox1->Height / 2) - h);

					   //Test verilerinin normalizasyonu
					   x[0] = (x[0] - mean[0]) / std[0];
					   x[1] = (x[1] - mean[1]) / std[1];

					   //giriþ katmaný için feedforward
					   for (k = 0; k < layers[0].numOfNeuron; k++) {
						   net = 0;
						   for (j = 0; j < layers[0].inputDim; j++) {
							   net += layers[0].W[k * (layers[0].inputDim + 1) + j] * x[j];
						   }
						   net += layers[0].W[k * (layers[0].inputDim + 1) + layers[0].inputDim];
						   layers[0].outputs[k] = sigmoid(net, 1);
					   } //feedforward
					   for (l = 1; l < (hLayerCount + 1); l++) {
						   for (k = 0; k < layers[l].numOfNeuron; k++) {
							   net = 0;
							   for (j = 0; j < layers[l].inputDim; j++) {
								   net += layers[l].W[k * (layers[l].inputDim + 1) + j] * layers[l - 1].outputs[j];
							   }
							   net += layers[l].W[k * (layers[l].inputDim + 1) + layers[l].inputDim];
							   layers[l].outputs[k] = sigmoid(net, 1);
						   }
					   }

					   max = -9999999;
					   label = -1;
					   if (layers[hLayerCount].numOfNeuron == 1)
						   color = layers[hLayerCount].outputs[0] > 0 ? colors[0] : colors[1];
					   else {
						   for (k = 0; k < layers[hLayerCount].numOfNeuron; k++) {
							   if (max < layers[hLayerCount].outputs[k]) {
								   max = layers[hLayerCount].outputs[k];
								   label = k;
							   }
						   }
						   color = colors[label];
					   }
					   surface->SetPixel(w, h, color);

				   }
			   }
			   pictureBox1->Invalidate();
		   }
#pragma endregion
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;

		int centerX = (int)this->pictureBox1->Width / 2;
		int centerY = (int)this->pictureBox1->Height / 2;

		Pen^ blackPen = gcnew Pen(Color::Black, 2);
		g->DrawLine(blackPen, 0, centerY, this->pictureBox1->Width, centerY);
		g->DrawLine(blackPen, centerX, 0, centerX, this->pictureBox1->Height);

		delete blackPen;
	}
	private: System::Void buttonSave_Click(System::Object^ sender, System::EventArgs^ e) {
		classCount = Convert::ToInt32(comboBoxClassCount->SelectedItem);
		numOfNeurons = classCount == 2 ? 1 : classCount;

		buttonSave->Enabled = false;
		comboBoxClassColors->Enabled = true;
		numOfElements = new int[classCount];
		desiredValue = new int[classCount * numOfNeurons];
		W = new double[numOfNeurons * (DIMENSION + 1)];

		for (int i = 0; i < classCount; i++) {
			comboBoxClassColors->Items->Add(colors[i]);
			numOfElements[i] = 0;
		}
		comboBoxClassColors->SelectedIndex = 0;

		if (classCount == 2) {
			desiredValue[0] = 1;
			desiredValue[1] = -1;
		}
		else {
			for (int i = 0; i < classCount; i++) {  //her sýnýf için i== j için 1 aksi -1 koy.  label etiketinin olduðu indis o sýnýfýn beklenen deðeri
				for (int j = 0; j < numOfNeurons; j++) {
					desiredValue[i * classCount + j] = (i == j) ? 1 : -1;
				}
			}
		}

	}
	private: System::Void OnPictureBoxMouseClick(Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		int clickX = Convert::ToInt32(e->X);
		int clickY = Convert::ToInt32(e->Y);
		double x1 = (double)(clickX - (pictureBox1->Width / 2));
		double x2 = (double)((pictureBox1->Height / 2) - clickY);
		Graphics^ g = Graphics::FromImage(surface);
		Pen^ pen = gcnew Pen(colors[comboBoxClassColors->SelectedIndex], 2);

		labelPoints->Text = " X : " + x1.ToString() + " Y : " + x2.ToString();
		g->DrawLine(pen, clickX - 5, clickY, clickX + 5, clickY);
		g->DrawLine(pen, clickX, clickY - 5, clickX, clickY + 5);
		/*pictureBox1->CreateGraphics()->DrawLine(pen, clickX - 5, clickY, clickX + 5, clickY);
		pictureBox1->CreateGraphics()->DrawLine(pen, clickX, clickY - 5, clickX, clickY + 5);*/
		pictureBox1->Invalidate();
		delete pen;

		numOfElements[comboBoxClassColors->SelectedIndex]++;
		if (size == 0) {
			size = 1;
			samples = new Sample[1];
			samples[0].x[0] = x1;
			samples[0].x[1] = x2;
			samples->label = comboBoxClassColors->SelectedIndex;
		}
		else {
			size++;
			Sample* oldSamples = samples;
			samples = new Sample[size];
			for (int i = 0; i < size - 1; i++) {
				samples[i].x[0] = oldSamples[i].x[0];
				samples[i].x[1] = oldSamples[i].x[1];
				samples[i].label = oldSamples[i].label;
			}
			samples[size - 1].x[0] = x1;
			samples[size - 1].x[1] = x2;
			samples[size - 1].label = comboBoxClassColors->SelectedIndex;
		}


		label2->Text = "Örnek Sayýsý: " + size.ToString();
	}

	private: System::Void randomlyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		int width = DIMENSION + 1;
		srand(time(0));
		for (int i = 0; i < numOfNeurons; i++) {
			for (int j = 0; j < width; j++) {
				W[i * width + j] = ((double)rand() / (RAND_MAX)) * 2.0 - 1.0;
			}
		}
		for (int i = 0; i < numOfNeurons; i++) {
			for (int j = 0; j < width; j++) {
				label3->Text += W[i * width + j].ToString() + "  ";
			}
			label3->Text += "\n";
		}
	}
	private: System::Void perceptronToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		double c = 0.01;
		int cycle = 0;
		int i, j, k, n;
		int TotalError = 0;
		double* net = new double[numOfNeurons];
		double* out = new double[numOfNeurons];
		int* error = new int[numOfNeurons];

		do
		{
			TotalError = 0;
			for (i = 0; i < size; i++) {  //örnek sayýsý
				for (k = 0; k < numOfNeurons; k++) { //nöron sayýsý
					net[k] = 0;
					for (j = 0; j < DIMENSION; j++) {
						net[k] += W[k * (DIMENSION + 1) + j] * samples[i].x[j];
					}
					net[k] += W[k * (DIMENSION + 1) + DIMENSION];  //bias eklendi
					out[k] = sgn(net[k]);
					error[k] = desiredValue[samples[i].label * numOfNeurons + k] - out[k];  //desiredValue[samples[i].label * numOfNeurons + k] label deðerinin eþit olduðu satýrda o sýnýfýn beklenen deðeri tutulur.
				}

				for (k = 0; k < numOfNeurons; k++) {
					TotalError += abs(error[k]);
					for (j = 0; j < DIMENSION; j++) {
						W[k * (DIMENSION + 1) + j] += c * error[k] * samples[i].x[j];
					}
					W[k * (DIMENSION + 1) + DIMENSION] += c * error[k];
				}
			}
			cycle++;
		} while (TotalError != 0);

		label4->Text = "Cycle: " + cycle.ToString();
		//Test
		double* x = new double[DIMENSION];


		for (int h = 0; h < pictureBox1->Height; h += 2) {
			for (int w = 0; w < pictureBox1->Width; w += 2) {
				x[0] = (double)(w - (pictureBox1->Width / 2));
				x[1] = (double)((pictureBox1->Height / 2) - h);
				System::Drawing::Color color = Color::White;
				for (k = 0; k < numOfNeurons; k++) {
					net[k] = 0;
					for (j = 0; j < DIMENSION; j++) {
						net[k] += W[k * (DIMENSION + 1) + j] * x[j];
					}
					net[k] += W[k * (DIMENSION + 1) + DIMENSION];
					out[k] = sgn(net[k]);
				}
				for (int c = 0; c < classCount; c++) {
					double sum = 0;
					for (k = 0; k < numOfNeurons; k++) {
						sum += abs(desiredValue[c * numOfNeurons + k] - out[k]);
					}
					if (sum == 0) {
						color = colors[c];
						break;
					}
				}
				surface->SetPixel(w, h, color);

			}
		}
		pictureBox1->Invalidate();
		/*for (i = 0; i < numOfNeurons; i++)
			drawLine(i);*/
		label3->Text = "W: ";
		for (int i = 0; i < numOfNeurons; i++) {
			for (int j = 0; j < (DIMENSION + 1); j++) {
				label3->Text += W[i * (DIMENSION + 1) + j].ToString() + "  ";
			}
			label3->Text += "\n";
		}
		delete[] net;
		delete[] out;
		delete[] error;
	}
	private: System::Void deltaToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		int maxEpoch = 50000;
		double c = 0.1;
		int cycle = 0;
		int i, j, k, n;
		double TotalError = 0;
		double maxError = 0.01;
		double* net = new double[numOfNeurons];
		double* derivednet = new double[numOfNeurons];
		double* out = new double[numOfNeurons];
		double* delta = new double[numOfNeurons];
		double error = 0;

		double* mean = calculateMean(samples, size);
		double* std = calculateStdDer(samples, size);

		Sample* normalizedSamples = MeanStdNormalization(samples, size);
		do
		{
			TotalError = 0;
			for (i = 0; i < size; i++) {
				error = 0;
				for (k = 0; k < numOfNeurons; k++) {
					net[k] = 0;
					for (j = 0; j < DIMENSION; j++) {
						net[k] += W[k * (DIMENSION + 1) + j] * normalizedSamples[i].x[j];
					}
					net[k] += W[k * (DIMENSION + 1) + DIMENSION];
					out[k] = sigmoid(net[k], 1);
					derivednet[k] = derivativeOfSigmoid(net[k], 1);
					error += 0.5 * pow(desiredValue[samples[i].label * numOfNeurons + k] - out[k], 2);
				}

				for (k = 0; k < numOfNeurons; k++) {
					delta[k] = (desiredValue[samples[i].label * numOfNeurons + k] - out[k]) * derivednet[k];
					for (j = 0; j < DIMENSION; j++) {
						W[k * (DIMENSION + 1) + j] += c * delta[k] * normalizedSamples[i].x[j];
					}
					W[k * (DIMENSION + 1) + DIMENSION] += c * delta[k];
				}
				TotalError += error / numOfNeurons;
			}
			cycle++;
			series1->Points->AddXY(cycle, TotalError);
			if (cycle >= maxEpoch)
				break;
		} while (TotalError > maxError);

		label4->Text = "Cycle: " + cycle.ToString();
		labelError->Text = "Error" + TotalError.ToString();

		Graphics^ g = Graphics::FromImage(surface);
		System::Drawing::Color color = Color::White;
		double* x = new double[DIMENSION];
		double max = -9999999;
		int label = -1;

		for (int h = 0; h < pictureBox1->Height; h += 2) {
			for (int w = 0; w < pictureBox1->Width; w += 2) {
				x[0] = (double)(w - (pictureBox1->Width / 2));
				x[1] = (double)((pictureBox1->Height / 2) - h);

				//Test verilerinin normalizasyonu
				x[0] = (x[0] - mean[0]) / std[0];
				x[1] = (x[1] - mean[1]) / std[1];

				for (k = 0; k < numOfNeurons; k++) {
					net[k] = 0;
					for (j = 0; j < DIMENSION; j++) {
						net[k] += W[k * (DIMENSION + 1) + j] * x[j];
					}
					net[k] += W[k * (DIMENSION + 1) + DIMENSION];
					out[k] = sigmoid(net[k], 1);
				}

				max = -9999999;
				label = -1;
				if (numOfNeurons == 1)
					color = out[0] > 0 ? colors[0] : colors[1];
				else {
					for (k = 0; k < numOfNeurons; k++) {
						if (max < out[k]) {
							max = out[k];
							label = k;
						}
					}
					color = colors[label];
				}
				surface->SetPixel(w, h, color);
			}
		}
		
		pictureBox1->Invalidate();

	}
	private: System::Void multiLayerTrainToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

		double* mean = calculateMean(samples, size);
		double* std = calculateStdDer(samples, size);

		//Giriþ verileri normalize edildi.
		Sample* normalizedSamples = MeanStdNormalization(samples, size);
		int i, k, j, l;
		double net;
		double c = 0.1;
		int desired;
		double error = 0;
		double totalError = 0;
		int cycle = 0;
		int width;
		double momentRate = 0.9;

		do {
			totalError = 0;
			for (i = 0; i < size; i++) { //örnek sayýsý
				//giriþ katmaný için feedforward
				for (k = 0; k < layers[0].numOfNeuron; k++) {
					width = layers[0].inputDim + 1;
					net = 0;
					for (j = 0; j < layers[0].inputDim; j++) {
						net += layers[0].W[k * width + j] * normalizedSamples[i].x[j];
					}
					net += layers[0].W[k * width + layers[0].inputDim]; //bias eklendi
					layers[0].outputs[k] = sigmoid(net, 1);
					layers[0].out_derived[k] = derivativeOfSigmoid(net, 1);
				} //feedforward
				for (l = 1; l < (hLayerCount + 1); l++) {
					width = layers[l].inputDim + 1;
					for (k = 0; k < layers[l].numOfNeuron; k++) {
						net = 0;
						for (j = 0; j < layers[l].inputDim; j++) {
							net += layers[l].W[k * width + j] * layers[l - 1].outputs[j];
						}
						net += layers[l].W[k * width + layers[l].inputDim];
						layers[l].outputs[k] = sigmoid(net, 1);
						layers[l].out_derived[k] = derivativeOfSigmoid(net, 1);
					}
				}
				error = 0;

				//çýkýþ katmaný için backpropagation
				width = (layers[hLayerCount].inputDim + 1);  //aðýrlýklar için
				for (k = 0; k < layers[hLayerCount].numOfNeuron; k++) {
					desired = desiredValue[samples[i].label * layers[hLayerCount].numOfNeuron + k];
					error += 0.5 * pow((desired - layers[hLayerCount].outputs[k]), 2);
					layers[hLayerCount].delta[k] = (desired - layers[hLayerCount].outputs[k]) * layers[hLayerCount].out_derived[k];

					for (j = 0; j < layers[hLayerCount].inputDim; j++) {
						layers[hLayerCount].W[k * width + j] += c * layers[hLayerCount].delta[k] * layers[hLayerCount - 1].outputs[j];

						if (checkBoxMoment->Checked) {
							layers[hLayerCount].W[k * width + j] += momentRate * layers[hLayerCount].moment[k * width + j];
							layers[hLayerCount].moment[k * width + j] = c * layers[hLayerCount].delta[k] * layers[hLayerCount - 1].outputs[j];
						}
					}
					layers[hLayerCount].W[k * width + layers[hLayerCount].inputDim] += c * layers[hLayerCount].delta[k];  //bias güncelleme

					if (checkBoxMoment->Checked) {
						layers[hLayerCount].W[k * width + layers[hLayerCount].inputDim] += momentRate * layers[hLayerCount].moment[k * width + layers[hLayerCount].inputDim];
						layers[hLayerCount].moment[k * width + layers[hLayerCount].inputDim] = c * layers[hLayerCount].delta[k];
					}
				}
				totalError += (error / layers[hLayerCount].numOfNeuron);
				//backpropagation
				for (l = hLayerCount - 1; l > 0; l--) {
					width = (layers[l].inputDim + 1);
					for (k = 0; k < layers[l].numOfNeuron; k++) {
						layers[l].delta[k] = 0;

						for (int kk = 0; kk < layers[l + 1].numOfNeuron; kk++) {
							layers[l].delta[k] += layers[l + 1].delta[kk] * layers[l + 1].W[kk * (layers[l + 1].inputDim + 1) + k];
						}
						layers[l].delta[k] *= layers[l].out_derived[k];

						for (j = 0; j < layers[l].inputDim; j++) {
							layers[l].W[k * width + j] += c * layers[l].delta[k] * layers[l - 1].outputs[j];

							if (checkBoxMoment->Checked) {
								layers[l].W[k * width + j] += momentRate * layers[l].moment[k * width + j];
								layers[l].moment[k * width + j] = c * layers[l].delta[k] * layers[l - 1].outputs[j];
							}
						}
						layers[l].W[k * width + layers[l].inputDim] += c * layers[l].delta[k];

						if (checkBoxMoment->Checked) {
							layers[l].W[k * width + layers[l].inputDim] += momentRate * layers[l].moment[k * width + layers[l].inputDim];
							layers[l].moment[k * width + layers[l].inputDim] = c * layers[l].delta[k];
						}
					}
				}//giriþ için aðýrlýk güncellemesi
				width = (layers[0].inputDim + 1); //DIMENSION+1
				for (k = 0; k < layers[0].numOfNeuron; k++) {
					layers[0].delta[k] = 0;
					for (int kk = 0; kk < layers[1].numOfNeuron; kk++) {
						layers[0].delta[k] += layers[1].delta[kk] * layers[1].W[kk * (layers[1].inputDim + 1) + k];
					}
					layers[0].delta[k] *= layers[0].out_derived[k];

					for (j = 0; j < layers[0].inputDim; j++) {
						layers[0].W[k * width + j] += c * layers[0].delta[k] * normalizedSamples[i].x[j];

						if (checkBoxMoment->Checked) {
							layers[0].W[k * width + j] += momentRate * layers[0].moment[k * width + j];
							layers[0].moment[k * width + j] = c * layers[0].delta[k] * normalizedSamples[i].x[j];
						}
					}
					layers[0].W[k * width + layers[0].inputDim] += c * layers[0].delta[k];

					if (checkBoxMoment->Checked) {
						layers[0].W[k * width + layers[0].inputDim] += momentRate * layers[0].moment[k * width + layers[0].inputDim];
						layers[0].moment[k * width + layers[0].inputDim] = c * layers[0].delta[k];
					}
				}
			}
			cycle++;
			series1->Points->AddXY(cycle, totalError);
			if (cycle > 100000)
				break;
		} while (totalError > 0.01);

		label4->Text = "Cycle: " + cycle.ToString();
		labelError->Text = "Error" + totalError.ToString();

		testForMultiLayer(mean, std);

	}
	private: System::Void buttonLayers_Click(System::Object^ sender, System::EventArgs^ e) {
		hLayerCount = Convert::ToInt32(comboBox1->SelectedItem);
		neurons = new int[hLayerCount];
		array<String^>^ neuronCount = textBox1->Text->Split(' ');  //her hidden layerda kaç nöron olacaðý bilgisini aldýk

		for (int i = 0; i < hLayerCount; i++)
			neurons[i] = Convert::ToInt32(neuronCount[i]);

		layers = new Layer[hLayerCount + 1]; //çýkýþ katmaný da dahil edildi

		layers[0].InitializeValue(neurons[0], DIMENSION);  //giriþ katmanýnda giriþ boyutu setleme
		layers[0].startTheWeights();
		layers[0].startMoment();
		for (int i = 1; i < hLayerCount; i++) {
			layers[i].InitializeValue(neurons[i], neurons[i - 1]);
			layers[i].startTheWeights();
			layers[i].startMoment();
		}
		layers[hLayerCount].InitializeValue(numOfNeurons, neurons[hLayerCount - 1]); //çýkýþ katmaný için nöron sayýsý ve giriþ boyutu setleme
		layers[hLayerCount].startTheWeights();
		layers[hLayerCount].startMoment();
	}

	private: System::Void savesamplesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string fileName = "örnek16.txt";
		std::ofstream outFile(fileName, std::ios::trunc);

		if (outFile.is_open()) {
			outFile << classCount << "\n"; //sýnýf sayýsý
			outFile << size << "\n";       //toplam örnek sayýsý
			outFile << hLayerCount << "\n"; // ara katman sayýsý
			for (int i = 0; i < hLayerCount; ++i) {
				outFile << neurons[i];   //her ara katmanda kaç nöron olduðu bilgisi
				outFile << " ";
			}
			outFile << "\n";
			for (int i = 0; i < size; i++) {
				outFile << samples[i].x[0];
				outFile << " ";
				outFile << samples[i].x[1];
				outFile << " ";
				outFile << samples[i].label;
				outFile << "\n";
			}
			outFile.close(); // Dosyayý kapat.
		}
		else {
			std::cerr << "Dosya oluþturulamadý!\n";
		}
	}
	private: System::Void readSamplesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string fileName = "örnek16.txt";
		std::ifstream inFile(fileName);
		std::string line;
		int i = 0;
		double x1, x2;    // x1 ve x2 deðerlerini saklamak için.
		int label;
		if (inFile.is_open()) {
			inFile >> line;
			classCount = std::stoi(line);
			comboBoxClassCount->SelectedIndex = classCount - 2; //sýnýf sayýsý 2 den baþlýyor
			inFile >> line;
			size = std::stoi(line);
			samples = new Sample[size];

			inFile >> line;
			hLayerCount = std::stoi(line);
			comboBox1->SelectedIndex = hLayerCount - 1;
			neurons = new int[hLayerCount];

			getline(inFile, line);
			getline(inFile, line);
			std::istringstream ss(line);
			int value;
			while (ss >> value) {
				neurons[i++] = value;
			}
			System::String^ result = L"";
			for (int i = 0; i < hLayerCount; ++i) {
				result += neurons[i].ToString();  // Elemaný string'e dönüþtür
				if (i < hLayerCount - 1) {
					result += L" ";  // Elemanlarý arasýna boþluk ekle
				}
			}
			this->textBox1->Text = result;
			i = 0;
			while (getline(inFile, line)) {
				std::istringstream iss(line);
				if (iss >> x1 >> x2 >> label) {
					samples[i].x[0] = x1;
					samples[i].x[1] = x2;
					samples[i++].label = label;
				}
				else {
					std::cerr << "Satýrda bir sorun var: " << line << "\n";
				}
			}
			inFile.close();
		}
		else {
			std::cerr << "Dosya açýlamadý!\n";
		}

		int clickX;
		int clickY;
		Graphics^ g = Graphics::FromImage(surface);
		Pen^ pen;

		for (int i = 0; i < size; i++) {
			clickX = (pictureBox1->Width / 2) + samples[i].x[0];
			clickY = (pictureBox1->Height / 2) - samples[i].x[1];
			pen = gcnew Pen(colors[samples[i].label], 2);

			g->DrawLine(pen, clickX - 5, clickY, clickX + 5, clickY);
			g->DrawLine(pen, clickX, clickY - 5, clickX, clickY + 5);
		}
		pictureBox1->Invalidate();
		delete pen;
	}
	private: System::Void saveweightToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string fileName = "örnek16_weight.txt";
		std::ofstream outFile(fileName, std::ios::trunc);
		int width;
		if (outFile.is_open()) {
			outFile << hLayerCount; //dosyanýn baþýna aðda kaç ara katman olduðu bilgisi yazýlýr.
			outFile << "\n";
			outFile << DIMENSION;
			outFile << " ";
			for (int i = 0; i < hLayerCount; ++i) {
				outFile << neurons[i];   //her ara katmanda kaç nöron olduðu bilgisi
				outFile << " ";
			}
			outFile << numOfNeurons;
			outFile << "\n";
			outFile << "\n";
			for (int i = 0; i < (hLayerCount + 1); i++) {
				for (int k = 0; k < layers[i].numOfNeuron; k++) {
					width = layers[i].inputDim + 1;
					for (int j = 0; j < width; j++) {
						outFile << layers[i].W[k * width + j];
						outFile << " ";
					}
					outFile << "\n";
				}
				outFile << "\n";
				outFile << "\n";
			}
			outFile.close(); // Dosyayý kapat.
		}
		else {
			std::cerr << "Dosya oluþturulamadý!\n";
		}
	}
	private: System::Void readWeightToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string fileName = "örnek16_weight.txt";
		std::ifstream inFile(fileName);
		std::string line;
		int hiddenCount;
		int* n;
		int i = 0;
		int k = 0;
		int j = 0;
		int width;
		if (inFile.is_open()) {
			inFile >> line;
			hiddenCount = std::stoi(line);
			n = new int[hiddenCount + 2]; //giriþ çýkýþ dahil edildi.

			getline(inFile, line);
			getline(inFile, line);
			std::istringstream ss(line);
			int value;
			while (ss >> value) {
				n[i++] = value;
			}
			layers = new Layer[hiddenCount + 1]; //çýkýþ katmaný da dahil edildi
			for (int i = 0; i < hiddenCount + 1; i++) {
				layers[i].InitializeValue(n[i + 1], n[i]);  //giriþ katmanýnda giriþ boyutu setleme
				layers[i].startMoment();
			}

			getline(inFile, line);
			double weight;
			for (int l = 0; l < (hiddenCount + 1); l++) {
				width = layers[l].inputDim + 1;
				for (k = 0; k < layers[l].numOfNeuron; k++) {
					j = 0; //inputdim
					getline(inFile, line);
					std::istringstream ss(line);
					while (ss >> weight) {
						layers[l].W[k * width + j] = weight;
						j++;
					}

				}
				getline(inFile, line);
				getline(inFile, line);
			}

		}
		else {
			std::cerr << "Dosya açýlamadý!\n";
		}
	}
	};
}
