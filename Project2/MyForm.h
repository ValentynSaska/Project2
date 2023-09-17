#pragma once
#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS
#define n 10
namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	
	union gotel_tel{
		char* gotel;
		char* tel;
	};

	public struct konfer {
		char* Name;
		char* Surname;
		char* Adress;
		int br;
		gotel_tel bron;
	};

	konfer mas[n];

	int qountity = 0;

	
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		void SearchNameSurname(char* name, char* surname)
		{
			FILE* f;
			f = fopen("result.txt", "wt");

			char* s = "Прізвище\tІм'я\t\tAдресса\t\tБронь\t\tГотель/Телефон\n";

			fputs(s, f);

			dataGridView1->Rows->Clear();

			int k = 0;

			for (int j = 0; j < qountity; j++) {
				if (strcmp(mas[j].Name, name) == 0 && strcmp(mas[j].Surname, surname) == 0)
				{
					fprintf(f, "%s\t\t%s\t\t%s\t\t", mas[j].Name, mas[j].Surname, mas[j].Adress);
					
					dataGridView1->RowCount = qountity;

					String^ s_name = gcnew String(mas[j].Name);
					this->dataGridView1->Rows[k]->Cells[0]->Value = s_name;

					String^ s_surname = gcnew String(mas[j].Surname);
					this->dataGridView1->Rows[k]->Cells[1]->Value = s_surname;

					String^ s_adress = gcnew String(mas[j].Adress);
					this->dataGridView1->Rows[k]->Cells[2]->Value = s_adress;

					if (mas[j].br == 1) {
						fprintf(f, "Так\t\t");
						fprintf(f, "%s\n", mas[j].bron.gotel);

						this->dataGridView1->Rows[k]->Cells[3]->Value = "тaк";

						String^ s_gotel = gcnew String(mas[j].bron.gotel);
						this->dataGridView1->Rows[k]->Cells[4]->Value = s_gotel;
					}
					else {
						fprintf(f, "ні\t\t");
						fprintf(f, "%s\n", mas[j].bron.tel);

						this->dataGridView1->Rows[k]->Cells[3]->Value = "ні";

						String^ s_tel = gcnew String(mas[j].bron.tel);
						this->dataGridView1->Rows[k]->Cells[4]->Value = s_tel;
					}
					k++;
				}
			}
			fclose(f);
		}

	public:
		void SearchAdress(char* adress)
		{
			FILE* f;
			f = fopen("result.txt", "wt");

			char* s = "Прізвище\tІм'я\t\tAдресса\t\tБронь\t\tГотель/Телефон\n";

			fputs(s, f);

			dataGridView1->Rows->Clear();

			int k = 0;

			for (int j = 0; j < qountity; j++) {
				if (strcmp(mas[j].Adress, adress) == 0)
				{
					fprintf(f, "%s\t\t%s\t\t%s\t\t", mas[j].Name, mas[j].Surname, mas[j].Adress);

					dataGridView1->RowCount = qountity;

					String^ s_name = gcnew String(mas[j].Name);
					this->dataGridView1->Rows[k]->Cells[0]->Value = s_name;

					String^ s_surname = gcnew String(mas[j].Surname);
					this->dataGridView1->Rows[k]->Cells[1]->Value = s_surname;

					String^ s_adress = gcnew String(mas[j].Adress);
					this->dataGridView1->Rows[k]->Cells[2]->Value = s_adress;

					if (mas[j].br == 1) {
						fprintf(f, "Так\t\t");
						fprintf(f, "%s\n", mas[j].bron.gotel);

						this->dataGridView1->Rows[k]->Cells[3]->Value = "тaк";

						String^ s_gotel = gcnew String(mas[j].bron.gotel);
						this->dataGridView1->Rows[k]->Cells[4]->Value = s_gotel;
					}
					else {
						fprintf(f, "ні\t\t");
						fprintf(f, "%s\n", mas[j].bron.tel);

						this->dataGridView1->Rows[k]->Cells[3]->Value = "ні";

						String^ s_tel = gcnew String(mas[j].bron.tel);
						this->dataGridView1->Rows[k]->Cells[4]->Value = s_tel;
					}
					k++;
				}
			}
			fclose(f);
		}

	public:
		void SearcHotelTel(char* ht)
		{
			FILE* f;
			f = fopen("result.txt", "wt");

			char* s = "Прізвище\tІм'я\t\tAдресса\t\tБронь\t\tГотель/Телефон\n";

			fputs(s, f);

			dataGridView1->Rows->Clear();

			int k = 0;

			for (int j = 0; j < qountity; j++) {
				if (mas[j].br == 1 && strcmp(mas[j].bron.gotel, ht) == 0) {
					fprintf(f, "%s\t\t%s\t\t%s\t\t", mas[j].Name, mas[j].Surname, mas[j].Adress);
					fprintf(f, "тaк\t\t");
					fprintf(f, "%s\n", mas[j].bron.gotel);

					dataGridView1->RowCount = qountity;

					String^ s_name = gcnew String(mas[j].Name);
					this->dataGridView1->Rows[k]->Cells[0]->Value = s_name;

					String^ s_surname = gcnew String(mas[j].Surname);
					this->dataGridView1->Rows[k]->Cells[1]->Value = s_surname;

					String^ s_adress = gcnew String(mas[j].Adress);
					this->dataGridView1->Rows[k]->Cells[2]->Value = s_adress;

					this->dataGridView1->Rows[k]->Cells[3]->Value = "тaк";

					String^ s_gotel = gcnew String(mas[j].bron.gotel);
					this->dataGridView1->Rows[k]->Cells[4]->Value = s_gotel;
					k++;
				}
				if (mas[j].br == 2 && strcmp(mas[j].bron.tel, ht) == 0) {
					fprintf(f, "%s\t\t%s\t\t%s\t\t", mas[j].Name, mas[j].Surname, mas[j].Adress);
					fprintf(f, "ні\t\t");
					fprintf(f, "%s\n", mas[j].bron.tel);

					String^ s_name = gcnew String(mas[j].Name);
					this->dataGridView1->Rows[k]->Cells[0]->Value = s_name;

					String^ s_surname = gcnew String(mas[j].Surname);
					this->dataGridView1->Rows[k]->Cells[1]->Value = s_surname;

					String^ s_adress = gcnew String(mas[j].Adress);
					this->dataGridView1->Rows[k]->Cells[2]->Value = s_adress;

					this->dataGridView1->Rows[k]->Cells[3]->Value = "ні";

					String^ s_tel = gcnew String(mas[j].bron.tel);
					this->dataGridView1->Rows[k]->Cells[4]->Value = s_tel;
					k++;

				}
			}
			fclose(f);

		}

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
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::RadioButton^ radioButton5;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label5;

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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(343, 434);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ввести";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &MyForm::groupBox1_Enter);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(23, 319);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 20);
			this->label5->TabIndex = 12;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button2->Location = System::Drawing::Point(226, 388);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(92, 28);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Зберегти";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Location = System::Drawing::Point(110, 388);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(92, 28);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Ввести";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(265, 292);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(42, 24);
			this->radioButton2->TabIndex = 9;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Ні";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton2_CheckedChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(36, 292);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(53, 24);
			this->radioButton1->TabIndex = 8;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Так";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(27, 345);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(291, 26);
			this->textBox4->TabIndex = 7;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(110, 125);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(208, 112);
			this->textBox3->TabIndex = 6;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(110, 75);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(208, 26);
			this->textBox2->TabIndex = 5;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(110, 25);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(208, 26);
			this->textBox1->TabIndex = 4;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(23, 261);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(226, 20);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Потрібно бронювати номер\?";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(23, 125);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 20);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Адреса";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(23, 75);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(37, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Ім\'я";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(23, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Прізвище";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->dataGridView1);
			this->groupBox2->Controls->Add(this->button3);
			this->groupBox2->Controls->Add(this->button4);
			this->groupBox2->Controls->Add(this->radioButton5);
			this->groupBox2->Controls->Add(this->textBox7);
			this->groupBox2->Controls->Add(this->radioButton4);
			this->groupBox2->Controls->Add(this->textBox6);
			this->groupBox2->Controls->Add(this->radioButton3);
			this->groupBox2->Controls->Add(this->textBox5);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox2->Location = System::Drawing::Point(383, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(338, 434);
			this->groupBox2->TabIndex = 0;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Знайти";
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(16, 247);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(300, 124);
			this->dataGridView1->TabIndex = 19;
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button3->Location = System::Drawing::Point(225, 388);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(92, 28);
			this->button3->TabIndex = 18;
			this->button3->Text = L"Вихід";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button4->Location = System::Drawing::Point(115, 388);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(92, 28);
			this->button4->TabIndex = 17;
			this->button4->Text = L"Знайти";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(16, 169);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(194, 24);
			this->radioButton5->TabIndex = 16;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"За прізвищем та ім\'ям";
			this->radioButton5->UseVisualStyleBackColor = true;
			this->radioButton5->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton5_CheckedChanged);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(16, 199);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(301, 26);
			this->textBox7->TabIndex = 15;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(16, 95);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(194, 24);
			this->radioButton4->TabIndex = 14;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"За прізвищем та ім\'ям";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton4_CheckedChanged);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(16, 125);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(301, 26);
			this->textBox6->TabIndex = 13;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox6_TextChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(16, 27);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(200, 24);
			this->radioButton3->TabIndex = 12;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"За прізвищем тф ім\'ям";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton3_CheckedChanged);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(16, 57);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(301, 26);
			this->textBox5->TabIndex = 6;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox5_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(733, 458);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Name = L"MyForm";
			this->Text = L"Реєстрація на конфернцію";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) 
	{

	}
	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) 
	{

	}
	private: System::Void radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{

	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (radioButton3->Checked) {
			char* str = (char*)(void*)Marshal::StringToHGlobalAnsi(textBox5->Text);
			char* s1 = strtok(str, " ");
			char* s2 = strtok(NULL, " ");;
			SearchNameSurname(s1, s2);
		}
		if (radioButton4->Checked) {
			char* s = (char*)(void*)Marshal::StringToHGlobalAnsi(textBox6->Text);
			SearchAdress(s);
		}
		if (radioButton5->Checked) {
			char* sht = (char*)(void*)Marshal::StringToHGlobalAnsi(textBox7->Text);
			SearcHotelTel(sht);
		}
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
	if (qountity < n) {
		mas[qountity].Name = (char*)(void*)Marshal::StringToHGlobalAnsi(textBox1->Text);
		mas[qountity].Surname = (char*)(void*)Marshal::StringToHGlobalAnsi(textBox2->Text);
		mas[qountity].Adress = (char*)(void*)Marshal::StringToHGlobalAnsi(textBox3->Text);
		if (this->radioButton1->Checked) {
			mas[qountity].br = 1;
			mas[qountity].bron.gotel = (char*)(void*)Marshal::StringToHGlobalAnsi(textBox4->Text);
		}
		if (this->radioButton2->Checked) {
			mas[qountity].br = 2;
			mas[qountity].bron.tel = (char*)(void*)Marshal::StringToHGlobalAnsi(textBox4->Text);
		}
		qountity++;
		textBox1->Text = "";
		textBox2->Text = "";
		textBox3->Text = "";
		textBox4->Text = "";
		}
		else
		{
		MessageBox::Show("База учасників заповнена", "Попередження");
		button1->Enabled = false;
		}
	
	}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) 
	{
	
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) 
	{

	}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) 
	{
	
	}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) 
	{
	
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
	FILE* file;
	file = fopen("konferenc.txt", "wt");
	char* s = "Прізвище\tІм'я\tАдреccа\n";
	fputs(s, file);
	for (int j = 0; j < i; j++) {
		fprintf(file, "%s\t\t%s\t%s\n", mas[j].Surname, mas[j].Adress);
	}
	fclose(file);
	}
private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) 
	{

	}
private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
	if (this->radioButton1->Checked) {
		this->label5->Text = "Введіть назву готелю";
	}
	}
private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
	if (this->radioButton2->Checked) {
		this->label5->Text = "Введіть номер телефону";
	}
	}
private: System::Void radioButton5_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void radioButton4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
	MyForm::Close();
	}
};
}
