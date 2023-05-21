#pragma once
#include <iostream> // використовується для організації введення-виведення
#include <string> // робота з символами і рядками
#include <fstream> // робота з файлами
#include <vector> // робота з векторами
#include <cstdlib> // для функций rand() и srand() 
#include <msclr/marshal_cppstd.h> //для функції перетвориня з стрінга

int chek=0;
int chek_button2 = 0;
int chek_button3 = 0;
bool keyMinMaxHour = true;
bool keyMinMaxWeg = true;

namespace Cursova {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace std;

	void MarshalString(String^ s, string& os) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

	struct TAR {
		string neam="ERORR";
		long double coefficient=-1;
	}; vector<TAR> TAR_vector;

	struct СOF
	{
		string nema="ERORR";
		long double coefficient = -1;

	}; vector<СOF> COF_vector;

	struct JOB 
	{
		string Department = "ERORR ";
		string Position="ERORR";
		string PIB="ERORR";
		long int Personal_number=-1;
		long double Hours=-1;
		long double wage = -1;      
		 

	}; vector<JOB> job_vector;

	
	
	bool(CheckWithKey)(double a,double b, bool key) {
		if (key)
		{
			return a > b;
		}
		else
		{
			return a < b;
		}
	}//порівння за ключом

	bool(StringInt)(string line) {
		string chek_int_mas("1234567890");
		for (int i = 0; i < line.length(); i++) {
			if (chek_int_mas.find(line[i]) == string::npos)//провірка чи всі символи строки є числом за допомогую провірки на входження в масив
			{
				return  false;
			} 
		}
		return true;
	}
	//Функція яка приймає текст і перевіряє що її можна перетворити в ціле число
	bool(StringDouble)(string line) {
		string chek_double_mas("1234567890.");
		int chekCopyDouble = 0;

		for (int i = 0; i < line.length(); i++) {
			if (chek_double_mas.find(line[i]) == string::npos)// якщо символа немає в строці 
			{
				return false;
			}
			if (line[i] == '.' && chekCopyDouble == 0)
			{
				chekCopyDouble++;
			}
			else if (line[i] == '.' && chekCopyDouble != 0)
			{
				return false;
			}
		}
		return true;

	}//Функція яка приймає текст і перевіряє що її можна перетворити в дробове  число
	
	string FileNamePeple;
	string FileNameCof;
	string FileNameTar;
	string chek_int_mas("1234567890");
	string chek_double_mas("1234567890.");
	string  sevNum = "";
	string  sevPIB = "";
	string Deportament1 = "";
	string Posit1 = "";
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:

	protected:

	private: System::Windows::Forms::DataGridView^ dataGridView1;
private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ buttonAddPeople;
	private: System::Windows::Forms::Button^ buttonAddTar;
	private: System::Windows::Forms::Button^ buttonAddCof;
	private: System::Windows::Forms::Label^ labelAddPeople;
	private: System::Windows::Forms::Label^ labelAddPeople2;
	private: System::Windows::Forms::Label^ labelAddPeople6;
	private: System::Windows::Forms::Label^ labelAddPeople3;
	private: System::Windows::Forms::Label^ labelAddPeople4;
	private: System::Windows::Forms::Button^ backButton;
	private: System::Windows::Forms::Button^ noButton;
	private: System::Windows::Forms::Button^ yesButton;
	private: System::Windows::Forms::Label^ labelYesOrNo;
	private: System::Windows::Forms::Button^ buttonAddPeopleFaill;
	private: System::Windows::Forms::Button^ backButtonAdd;
	private: System::Windows::Forms::Button^ buttonAddCofFaill;
	private: System::Windows::Forms::Label^ labelAddCof1;
	private: System::Windows::Forms::Label^ labelAddCof2;
	private: System::Windows::Forms::Label^ labelAddTar1;
	private: System::Windows::Forms::Label^ labelAddTar2;
	private: System::Windows::Forms::Button^ buttonAddTarFaill;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog2;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog3;
	private: System::Windows::Forms::Button^ buttonEditing;
	private: System::Windows::Forms::Button^ buttonRaundNoumber;
	private: System::Windows::Forms::Button^ buttonSort;
	private: System::Windows::Forms::TextBox^ textBoxSortPositon;
	private: System::Windows::Forms::TextBox^ textBoxSortHors;
	private: System::Windows::Forms::TextBox^ textBoxSortWag;
	private: System::Windows::Forms::Label^ labelSort1;
	private: System::Windows::Forms::Label^ labelSort2;
	private: System::Windows::Forms::Label^ labelSort3;
	private: System::Windows::Forms::Label^ labelSort4;
	private: System::Windows::Forms::Button^ buttonSearch;
	private: System::Windows::Forms::Button^ buttonSearchDo;
	private: System::Windows::Forms::Label^ labelSearch1;
	private: System::Windows::Forms::CheckBox^ checkBoxMinMaxWeg;
	private: System::Windows::Forms::CheckBox^ checkBoxMinMaxHors;
	private: System::Windows::Forms::TextBox^ textBoxSortAllNoumber;
	private: System::Windows::Forms::Label^ labelSortAllNoumber;
private: System::Windows::Forms::TextBox^ TEST;
private: System::Windows::Forms::Button^ buttonDelete;
private: System::Windows::Forms::Button^ buttonDeleteCof;
private: System::Windows::Forms::Button^ buttonDeletePeople;
private: System::Windows::Forms::Button^ buttonDeleteTar;
private: System::Windows::Forms::Button^ buttonDeletePeopleFaill;
private: System::Windows::Forms::Label^ labelDeletePepl;
private: System::Windows::Forms::Button^ buttonDeleteCofFaill;
private: System::Windows::Forms::Label^ labelDeleteCof;
private: System::Windows::Forms::Button^ buttonDeleteTarFaill;
private: System::Windows::Forms::Label^ labelDeleteTar;
private: System::Windows::Forms::Button^ BackbuttonDelete;
private: System::Windows::Forms::Label^ labelSort3on;
private: System::Windows::Forms::Label^ labelSort4on;
private: System::Windows::Forms::TextBox^ textBox1;
private: System::Windows::Forms::TextBox^ textBox2;
private: System::Windows::Forms::TextBox^ textBox3;
private: System::Windows::Forms::TextBox^ textBox4;
private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Button^ buttonEditingPepl;
	private: System::Windows::Forms::Button^ buttonEditingCof;
	private: System::Windows::Forms::Button^ buttonEditingTar;
	private: System::Windows::Forms::Button^ buttonEditingPeplFile;
	private: System::Windows::Forms::Button^ buttonEditingPeplFileDo;
	private: System::Windows::Forms::Button^ buttonEditingPeplFileR;
	private: System::Windows::Forms::Label^ labelEdittPepol1;
	private: System::Windows::Forms::Label^ labelEdittPepol2;
	private: System::Windows::Forms::Label^ labelEdittPepol3;
	private: System::Windows::Forms::Label^ labelEdittPepol4;
	private: System::Windows::Forms::Label^ labelEdittPepol5;
private: System::Windows::Forms::Button^ buttonEditingCofFill;

private: System::Windows::Forms::Button^ buttonEditingCoflFileDo;
private: System::Windows::Forms::Button^ buttonEditingCofFileDoR;

private: System::Windows::Forms::Label^ labelEditingCof1;
private: System::Windows::Forms::Label^ labelEditingCof2;
private: System::Windows::Forms::Button^ BackbuttonEdiit;
private: System::Windows::Forms::Button^ buttonEditingTarFill;
private: System::Windows::Forms::Button^ buttonEditingTarFillDo;
private: System::Windows::Forms::Button^ buttonEditingTarFillDoR;
private: System::Windows::Forms::Label^ labelEditingTar1;
private: System::Windows::Forms::Label^ labelEditingTar2;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->buttonAddPeople = (gcnew System::Windows::Forms::Button());
			this->buttonAddTar = (gcnew System::Windows::Forms::Button());
			this->buttonAddCof = (gcnew System::Windows::Forms::Button());
			this->labelAddPeople = (gcnew System::Windows::Forms::Label());
			this->labelAddPeople2 = (gcnew System::Windows::Forms::Label());
			this->labelAddPeople6 = (gcnew System::Windows::Forms::Label());
			this->labelAddPeople3 = (gcnew System::Windows::Forms::Label());
			this->labelAddPeople4 = (gcnew System::Windows::Forms::Label());
			this->backButton = (gcnew System::Windows::Forms::Button());
			this->yesButton = (gcnew System::Windows::Forms::Button());
			this->noButton = (gcnew System::Windows::Forms::Button());
			this->labelYesOrNo = (gcnew System::Windows::Forms::Label());
			this->buttonAddPeopleFaill = (gcnew System::Windows::Forms::Button());
			this->backButtonAdd = (gcnew System::Windows::Forms::Button());
			this->buttonAddCofFaill = (gcnew System::Windows::Forms::Button());
			this->labelAddCof1 = (gcnew System::Windows::Forms::Label());
			this->labelAddCof2 = (gcnew System::Windows::Forms::Label());
			this->labelAddTar1 = (gcnew System::Windows::Forms::Label());
			this->labelAddTar2 = (gcnew System::Windows::Forms::Label());
			this->buttonAddTarFaill = (gcnew System::Windows::Forms::Button());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->openFileDialog3 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->buttonEditing = (gcnew System::Windows::Forms::Button());
			this->buttonRaundNoumber = (gcnew System::Windows::Forms::Button());
			this->buttonSort = (gcnew System::Windows::Forms::Button());
			this->textBoxSortPositon = (gcnew System::Windows::Forms::TextBox());
			this->textBoxSortHors = (gcnew System::Windows::Forms::TextBox());
			this->textBoxSortWag = (gcnew System::Windows::Forms::TextBox());
			this->labelSort1 = (gcnew System::Windows::Forms::Label());
			this->labelSort2 = (gcnew System::Windows::Forms::Label());
			this->labelSort3 = (gcnew System::Windows::Forms::Label());
			this->labelSort4 = (gcnew System::Windows::Forms::Label());
			this->buttonSearch = (gcnew System::Windows::Forms::Button());
			this->buttonSearchDo = (gcnew System::Windows::Forms::Button());
			this->labelSearch1 = (gcnew System::Windows::Forms::Label());
			this->checkBoxMinMaxWeg = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxMinMaxHors = (gcnew System::Windows::Forms::CheckBox());
			this->textBoxSortAllNoumber = (gcnew System::Windows::Forms::TextBox());
			this->labelSortAllNoumber = (gcnew System::Windows::Forms::Label());
			this->TEST = (gcnew System::Windows::Forms::TextBox());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->buttonDeleteCof = (gcnew System::Windows::Forms::Button());
			this->buttonDeletePeople = (gcnew System::Windows::Forms::Button());
			this->buttonDeleteTar = (gcnew System::Windows::Forms::Button());
			this->buttonDeletePeopleFaill = (gcnew System::Windows::Forms::Button());
			this->labelDeletePepl = (gcnew System::Windows::Forms::Label());
			this->buttonDeleteCofFaill = (gcnew System::Windows::Forms::Button());
			this->labelDeleteCof = (gcnew System::Windows::Forms::Label());
			this->buttonDeleteTarFaill = (gcnew System::Windows::Forms::Button());
			this->labelDeleteTar = (gcnew System::Windows::Forms::Label());
			this->BackbuttonDelete = (gcnew System::Windows::Forms::Button());
			this->labelSort3on = (gcnew System::Windows::Forms::Label());
			this->labelSort4on = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->buttonEditingPepl = (gcnew System::Windows::Forms::Button());
			this->buttonEditingCof = (gcnew System::Windows::Forms::Button());
			this->buttonEditingTar = (gcnew System::Windows::Forms::Button());
			this->buttonEditingPeplFile = (gcnew System::Windows::Forms::Button());
			this->buttonEditingPeplFileDo = (gcnew System::Windows::Forms::Button());
			this->buttonEditingPeplFileR = (gcnew System::Windows::Forms::Button());
			this->labelEdittPepol1 = (gcnew System::Windows::Forms::Label());
			this->labelEdittPepol2 = (gcnew System::Windows::Forms::Label());
			this->labelEdittPepol3 = (gcnew System::Windows::Forms::Label());
			this->labelEdittPepol4 = (gcnew System::Windows::Forms::Label());
			this->labelEdittPepol5 = (gcnew System::Windows::Forms::Label());
			this->buttonEditingCofFill = (gcnew System::Windows::Forms::Button());
			this->buttonEditingCoflFileDo = (gcnew System::Windows::Forms::Button());
			this->buttonEditingCofFileDoR = (gcnew System::Windows::Forms::Button());
			this->labelEditingCof1 = (gcnew System::Windows::Forms::Label());
			this->labelEditingCof2 = (gcnew System::Windows::Forms::Label());
			this->BackbuttonEdiit = (gcnew System::Windows::Forms::Button());
			this->buttonEditingTarFill = (gcnew System::Windows::Forms::Button());
			this->buttonEditingTarFillDo = (gcnew System::Windows::Forms::Button());
			this->buttonEditingTarFillDoR = (gcnew System::Windows::Forms::Button());
			this->labelEditingTar1 = (gcnew System::Windows::Forms::Label());
			this->labelEditingTar2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(207, 69);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Файл з інформацією про працівників";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(429, 24);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(1288, 364);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->Visible = false;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(225, 13);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(198, 68);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Файл з коефіцієнтами та відділами";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(134, 87);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(185, 64);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Файл з тарифами та посадами";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(12, 135);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(180, 70);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Розрахунок зарплати";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(134, 59);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(185, 51);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Обрати інші файли";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Visible = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(16, 213);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(180, 70);
			this->button6->TabIndex = 6;
			this->button6->Text = L"Сортування";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Visible = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(214, 135);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(213, 70);
			this->button7->TabIndex = 7;
			this->button7->Text = L"Додавання нових елементів у файл";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Visible = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// buttonAddPeople
			// 
			this->buttonAddPeople->Location = System::Drawing::Point(118, 133);
			this->buttonAddPeople->Name = L"buttonAddPeople";
			this->buttonAddPeople->Size = System::Drawing::Size(169, 74);
			this->buttonAddPeople->TabIndex = 13;
			this->buttonAddPeople->Text = L"Додавання  даних про працівника";
			this->buttonAddPeople->UseVisualStyleBackColor = true;
			this->buttonAddPeople->Visible = false;
			this->buttonAddPeople->Click += gcnew System::EventHandler(this, &MyForm::buttonAddPeople_Click);
			// 
			// buttonAddTar
			// 
			this->buttonAddTar->Location = System::Drawing::Point(214, 213);
			this->buttonAddTar->Name = L"buttonAddTar";
			this->buttonAddTar->Size = System::Drawing::Size(169, 74);
			this->buttonAddTar->TabIndex = 14;
			this->buttonAddTar->Text = L"Додавання тарифу та посади";
			this->buttonAddTar->UseVisualStyleBackColor = true;
			this->buttonAddTar->Visible = false;
			this->buttonAddTar->Click += gcnew System::EventHandler(this, &MyForm::buttonAddTar_Click);
			// 
			// buttonAddCof
			// 
			this->buttonAddCof->Location = System::Drawing::Point(27, 209);
			this->buttonAddCof->Name = L"buttonAddCof";
			this->buttonAddCof->Size = System::Drawing::Size(169, 74);
			this->buttonAddCof->TabIndex = 15;
			this->buttonAddCof->Text = L"Додавання коефіцієнта та відділу";
			this->buttonAddCof->UseVisualStyleBackColor = true;
			this->buttonAddCof->Visible = false;
			this->buttonAddCof->Click += gcnew System::EventHandler(this, &MyForm::buttonAddCof_Click);
			// 
			// labelAddPeople
			// 
			this->labelAddPeople->AutoSize = true;
			this->labelAddPeople->Location = System::Drawing::Point(30, 418);
			this->labelAddPeople->Name = L"labelAddPeople";
			this->labelAddPeople->Size = System::Drawing::Size(171, 20);
			this->labelAddPeople->TabIndex = 16;
			this->labelAddPeople->Text = L"Персональний номер";
			this->labelAddPeople->Visible = false;
			// 
			// labelAddPeople2
			// 
			this->labelAddPeople2->AutoSize = true;
			this->labelAddPeople2->Location = System::Drawing::Point(235, 418);
			this->labelAddPeople2->Name = L"labelAddPeople2";
			this->labelAddPeople2->Size = System::Drawing::Size(37, 20);
			this->labelAddPeople2->TabIndex = 17;
			this->labelAddPeople2->Text = L"ПІБ";
			this->labelAddPeople2->Visible = false;
			// 
			// labelAddPeople6
			// 
			this->labelAddPeople6->AutoSize = true;
			this->labelAddPeople6->Location = System::Drawing::Point(340, 416);
			this->labelAddPeople6->Name = L"labelAddPeople6";
			this->labelAddPeople6->Size = System::Drawing::Size(62, 20);
			this->labelAddPeople6->TabIndex = 18;
			this->labelAddPeople6->Text = L"Відділ ";
			this->labelAddPeople6->Visible = false;
			// 
			// labelAddPeople3
			// 
			this->labelAddPeople3->AutoSize = true;
			this->labelAddPeople3->Location = System::Drawing::Point(481, 416);
			this->labelAddPeople3->Name = L"labelAddPeople3";
			this->labelAddPeople3->Size = System::Drawing::Size(67, 20);
			this->labelAddPeople3->TabIndex = 19;
			this->labelAddPeople3->Text = L"Посада";
			this->labelAddPeople3->Visible = false;
			// 
			// labelAddPeople4
			// 
			this->labelAddPeople4->AutoSize = true;
			this->labelAddPeople4->Location = System::Drawing::Point(585, 416);
			this->labelAddPeople4->Name = L"labelAddPeople4";
			this->labelAddPeople4->Size = System::Drawing::Size(176, 20);
			this->labelAddPeople4->TabIndex = 20;
			this->labelAddPeople4->Text = L"Відпрацьовані години";
			this->labelAddPeople4->Visible = false;
			// 
			// backButton
			// 
			this->backButton->BackColor = System::Drawing::Color::LightCoral;
			this->backButton->Location = System::Drawing::Point(16, 13);
			this->backButton->Name = L"backButton";
			this->backButton->Size = System::Drawing::Size(96, 51);
			this->backButton->TabIndex = 21;
			this->backButton->Text = L"Назад";
			this->backButton->UseVisualStyleBackColor = false;
			this->backButton->Visible = false;
			this->backButton->Click += gcnew System::EventHandler(this, &MyForm::backButton_Click);
			// 
			// yesButton
			// 
			this->yesButton->Location = System::Drawing::Point(316, 181);
			this->yesButton->Name = L"yesButton";
			this->yesButton->Size = System::Drawing::Size(151, 61);
			this->yesButton->TabIndex = 22;
			this->yesButton->Text = L"Так";
			this->yesButton->UseVisualStyleBackColor = true;
			this->yesButton->Visible = false;
			this->yesButton->Click += gcnew System::EventHandler(this, &MyForm::yesButton_Click);
			// 
			// noButton
			// 
			this->noButton->Location = System::Drawing::Point(498, 181);
			this->noButton->Name = L"noButton";
			this->noButton->Size = System::Drawing::Size(151, 61);
			this->noButton->TabIndex = 23;
			this->noButton->Text = L"Ні";
			this->noButton->UseVisualStyleBackColor = true;
			this->noButton->Visible = false;
			this->noButton->Click += gcnew System::EventHandler(this, &MyForm::noButton_Click);
			// 
			// labelYesOrNo
			// 
			this->labelYesOrNo->AutoSize = true;
			this->labelYesOrNo->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->labelYesOrNo->Location = System::Drawing::Point(330, 152);
			this->labelYesOrNo->Name = L"labelYesOrNo";
			this->labelYesOrNo->Size = System::Drawing::Size(330, 20);
			this->labelYesOrNo->TabIndex = 24;
			this->labelYesOrNo->Text = L"Ви впевнені що бажаєте замінити файли\?";
			this->labelYesOrNo->Visible = false;
			// 
			// buttonAddPeopleFaill
			// 
			this->buttonAddPeopleFaill->Location = System::Drawing::Point(767, 432);
			this->buttonAddPeopleFaill->Name = L"buttonAddPeopleFaill";
			this->buttonAddPeopleFaill->Size = System::Drawing::Size(122, 54);
			this->buttonAddPeopleFaill->TabIndex = 25;
			this->buttonAddPeopleFaill->Text = L"Додати";
			this->buttonAddPeopleFaill->UseVisualStyleBackColor = true;
			this->buttonAddPeopleFaill->Visible = false;
			this->buttonAddPeopleFaill->Click += gcnew System::EventHandler(this, &MyForm::buttonAddPeopleFaill_Click);
			// 
			// backButtonAdd
			// 
			this->backButtonAdd->BackColor = System::Drawing::Color::LightCoral;
			this->backButtonAdd->Location = System::Drawing::Point(16, 12);
			this->backButtonAdd->Name = L"backButtonAdd";
			this->backButtonAdd->Size = System::Drawing::Size(96, 51);
			this->backButtonAdd->TabIndex = 31;
			this->backButtonAdd->Text = L"Назад";
			this->backButtonAdd->UseVisualStyleBackColor = false;
			this->backButtonAdd->Visible = false;
			this->backButtonAdd->Click += gcnew System::EventHandler(this, &MyForm::backButtonAdd_Click);
			// 
			// buttonAddCofFaill
			// 
			this->buttonAddCofFaill->Location = System::Drawing::Point(305, 423);
			this->buttonAddCofFaill->Name = L"buttonAddCofFaill";
			this->buttonAddCofFaill->Size = System::Drawing::Size(122, 58);
			this->buttonAddCofFaill->TabIndex = 32;
			this->buttonAddCofFaill->Text = L"Додати";
			this->buttonAddCofFaill->UseVisualStyleBackColor = true;
			this->buttonAddCofFaill->Visible = false;
			this->buttonAddCofFaill->Click += gcnew System::EventHandler(this, &MyForm::buttonAddCofFaill_Click);
			// 
			// labelAddCof1
			// 
			this->labelAddCof1->AutoSize = true;
			this->labelAddCof1->Location = System::Drawing::Point(54, 416);
			this->labelAddCof1->Name = L"labelAddCof1";
			this->labelAddCof1->Size = System::Drawing::Size(58, 20);
			this->labelAddCof1->TabIndex = 33;
			this->labelAddCof1->Text = L"Відділ";
			this->labelAddCof1->Visible = false;
			// 
			// labelAddCof2
			// 
			this->labelAddCof2->AutoSize = true;
			this->labelAddCof2->Location = System::Drawing::Point(210, 417);
			this->labelAddCof2->Name = L"labelAddCof2";
			this->labelAddCof2->Size = System::Drawing::Size(94, 20);
			this->labelAddCof2->TabIndex = 34;
			this->labelAddCof2->Text = L"Коефіцієнт";
			this->labelAddCof2->Visible = false;
			// 
			// labelAddTar1
			// 
			this->labelAddTar1->AutoSize = true;
			this->labelAddTar1->Location = System::Drawing::Point(54, 416);
			this->labelAddTar1->Name = L"labelAddTar1";
			this->labelAddTar1->Size = System::Drawing::Size(67, 20);
			this->labelAddTar1->TabIndex = 37;
			this->labelAddTar1->Text = L"Посада";
			this->labelAddTar1->Visible = false;
			// 
			// labelAddTar2
			// 
			this->labelAddTar2->AutoSize = true;
			this->labelAddTar2->Location = System::Drawing::Point(224, 417);
			this->labelAddTar2->Name = L"labelAddTar2";
			this->labelAddTar2->Size = System::Drawing::Size(60, 20);
			this->labelAddTar2->TabIndex = 38;
			this->labelAddTar2->Text = L"Тариф";
			this->labelAddTar2->Visible = false;
			// 
			// buttonAddTarFaill
			// 
			this->buttonAddTarFaill->Location = System::Drawing::Point(305, 422);
			this->buttonAddTarFaill->Name = L"buttonAddTarFaill";
			this->buttonAddTarFaill->Size = System::Drawing::Size(122, 58);
			this->buttonAddTarFaill->TabIndex = 42;
			this->buttonAddTarFaill->Text = L"Додати";
			this->buttonAddTarFaill->UseVisualStyleBackColor = true;
			this->buttonAddTarFaill->Visible = false;
			this->buttonAddTarFaill->Click += gcnew System::EventHandler(this, &MyForm::buttonAddTarFaill_Click);
			// 
			// openFileDialog2
			// 
			this->openFileDialog2->FileName = L"openFileDialog2";
			// 
			// openFileDialog3
			// 
			this->openFileDialog3->FileName = L"openFileDialog3";
			// 
			// buttonEditing
			// 
			this->buttonEditing->Location = System::Drawing::Point(16, 289);
			this->buttonEditing->Name = L"buttonEditing";
			this->buttonEditing->Size = System::Drawing::Size(180, 70);
			this->buttonEditing->TabIndex = 43;
			this->buttonEditing->Text = L"Редагування";
			this->buttonEditing->UseVisualStyleBackColor = true;
			this->buttonEditing->Visible = false;
			this->buttonEditing->Click += gcnew System::EventHandler(this, &MyForm::buttonEditing_Click);
			// 
			// buttonRaundNoumber
			// 
			this->buttonRaundNoumber->Location = System::Drawing::Point(38, 488);
			this->buttonRaundNoumber->Name = L"buttonRaundNoumber";
			this->buttonRaundNoumber->Size = System::Drawing::Size(118, 55);
			this->buttonRaundNoumber->TabIndex = 44;
			this->buttonRaundNoumber->Text = L"Генерація числа";
			this->buttonRaundNoumber->UseVisualStyleBackColor = true;
			this->buttonRaundNoumber->Visible = false;
			this->buttonRaundNoumber->Click += gcnew System::EventHandler(this, &MyForm::buttonRaundNoumber_Click);
			// 
			// buttonSort
			// 
			this->buttonSort->Location = System::Drawing::Point(582, 433);
			this->buttonSort->Name = L"buttonSort";
			this->buttonSort->Size = System::Drawing::Size(151, 59);
			this->buttonSort->TabIndex = 45;
			this->buttonSort->Text = L"Відсортувати";
			this->buttonSort->UseVisualStyleBackColor = true;
			this->buttonSort->Visible = false;
			this->buttonSort->Click += gcnew System::EventHandler(this, &MyForm::buttonSort_Click);
			// 
			// textBoxSortPositon
			// 
			this->textBoxSortPositon->Location = System::Drawing::Point(0, 0);
			this->textBoxSortPositon->Name = L"textBoxSortPositon";
			this->textBoxSortPositon->Size = System::Drawing::Size(100, 26);
			this->textBoxSortPositon->TabIndex = 0;
			// 
			// textBoxSortHors
			// 
			this->textBoxSortHors->Location = System::Drawing::Point(0, 0);
			this->textBoxSortHors->Name = L"textBoxSortHors";
			this->textBoxSortHors->Size = System::Drawing::Size(100, 26);
			this->textBoxSortHors->TabIndex = 0;
			// 
			// textBoxSortWag
			// 
			this->textBoxSortWag->Location = System::Drawing::Point(0, 0);
			this->textBoxSortWag->Name = L"textBoxSortWag";
			this->textBoxSortWag->Size = System::Drawing::Size(100, 26);
			this->textBoxSortWag->TabIndex = 0;
			// 
			// labelSort1
			// 
			this->labelSort1->AutoSize = true;
			this->labelSort1->Location = System::Drawing::Point(63, 416);
			this->labelSort1->Name = L"labelSort1";
			this->labelSort1->Size = System::Drawing::Size(58, 20);
			this->labelSort1->TabIndex = 50;
			this->labelSort1->Text = L"Відділ";
			this->labelSort1->Visible = false;
			// 
			// labelSort2
			// 
			this->labelSort2->AutoSize = true;
			this->labelSort2->Location = System::Drawing::Point(217, 422);
			this->labelSort2->Name = L"labelSort2";
			this->labelSort2->Size = System::Drawing::Size(67, 20);
			this->labelSort2->TabIndex = 51;
			this->labelSort2->Text = L"Посада";
			this->labelSort2->Visible = false;
			// 
			// labelSort3
			// 
			this->labelSort3->AutoSize = true;
			this->labelSort3->Location = System::Drawing::Point(310, 402);
			this->labelSort3->Name = L"labelSort3";
			this->labelSort3->Size = System::Drawing::Size(140, 40);
			this->labelSort3->TabIndex = 52;
			this->labelSort3->Text = L"Відпрацювали\r\nменше годин ніж:";
			this->labelSort3->Visible = false;
			// 
			// labelSort4
			// 
			this->labelSort4->AutoSize = true;
			this->labelSort4->Location = System::Drawing::Point(465, 402);
			this->labelSort4->Name = L"labelSort4";
			this->labelSort4->Size = System::Drawing::Size(88, 40);
			this->labelSort4->TabIndex = 53;
			this->labelSort4->Text = L"Зарплата \r\nменша за:";
			this->labelSort4->Visible = false;
			// 
			// buttonSearch
			// 
			this->buttonSearch->Location = System::Drawing::Point(214, 215);
			this->buttonSearch->Name = L"buttonSearch";
			this->buttonSearch->Size = System::Drawing::Size(213, 70);
			this->buttonSearch->TabIndex = 54;
			this->buttonSearch->Text = L"Пошук за персональним номером";
			this->buttonSearch->UseVisualStyleBackColor = true;
			this->buttonSearch->Visible = false;
			this->buttonSearch->Click += gcnew System::EventHandler(this, &MyForm::buttonSearch_Click);
			// 
			// buttonSearchDo
			// 
			this->buttonSearchDo->Location = System::Drawing::Point(172, 437);
			this->buttonSearchDo->Name = L"buttonSearchDo";
			this->buttonSearchDo->Size = System::Drawing::Size(100, 40);
			this->buttonSearchDo->TabIndex = 55;
			this->buttonSearchDo->Text = L"Знайти";
			this->buttonSearchDo->UseVisualStyleBackColor = true;
			this->buttonSearchDo->Visible = false;
			this->buttonSearchDo->Click += gcnew System::EventHandler(this, &MyForm::buttonSearchDo_Click);
			// 
			// labelSearch1
			// 
			this->labelSearch1->AutoSize = true;
			this->labelSearch1->Location = System::Drawing::Point(30, 416);
			this->labelSearch1->Name = L"labelSearch1";
			this->labelSearch1->Size = System::Drawing::Size(171, 20);
			this->labelSearch1->TabIndex = 56;
			this->labelSearch1->Text = L"Персональний номер";
			this->labelSearch1->Visible = false;
			// 
			// checkBoxMinMaxWeg
			// 
			this->checkBoxMinMaxWeg->AutoSize = true;
			this->checkBoxMinMaxWeg->Location = System::Drawing::Point(469, 488);
			this->checkBoxMinMaxWeg->Name = L"checkBoxMinMaxWeg";
			this->checkBoxMinMaxWeg->Size = System::Drawing::Size(147, 24);
			this->checkBoxMinMaxWeg->TabIndex = 58;
			this->checkBoxMinMaxWeg->Text = L"Менша/Більша";
			this->checkBoxMinMaxWeg->UseVisualStyleBackColor = true;
			this->checkBoxMinMaxWeg->Visible = false;
			this->checkBoxMinMaxWeg->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBoxMinMaxWeg_CheckedChanged);
			// 
			// checkBoxMinMaxHors
			// 
			this->checkBoxMinMaxHors->AutoSize = true;
			this->checkBoxMinMaxHors->Location = System::Drawing::Point(320, 487);
			this->checkBoxMinMaxHors->Name = L"checkBoxMinMaxHors";
			this->checkBoxMinMaxHors->Size = System::Drawing::Size(147, 24);
			this->checkBoxMinMaxHors->TabIndex = 59;
			this->checkBoxMinMaxHors->Text = L"Менше/Більше";
			this->checkBoxMinMaxHors->UseVisualStyleBackColor = true;
			this->checkBoxMinMaxHors->Visible = false;
			this->checkBoxMinMaxHors->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBoxMinMaxHors_CheckedChanged);
			// 
			// textBoxSortAllNoumber
			// 
			this->textBoxSortAllNoumber->Location = System::Drawing::Point(941, 444);
			this->textBoxSortAllNoumber->Name = L"textBoxSortAllNoumber";
			this->textBoxSortAllNoumber->ReadOnly = true;
			this->textBoxSortAllNoumber->Size = System::Drawing::Size(100, 26);
			this->textBoxSortAllNoumber->TabIndex = 60;
			this->textBoxSortAllNoumber->Visible = false;
			// 
			// labelSortAllNoumber
			// 
			this->labelSortAllNoumber->AutoSize = true;
			this->labelSortAllNoumber->Location = System::Drawing::Point(739, 433);
			this->labelSortAllNoumber->Name = L"labelSortAllNoumber";
			this->labelSortAllNoumber->Size = System::Drawing::Size(196, 40);
			this->labelSortAllNoumber->TabIndex = 61;
			this->labelSortAllNoumber->Text = L"Кількість записів\r\nщо підходять критеріям:";
			this->labelSortAllNoumber->Visible = false;
			// 
			// TEST
			// 
			this->TEST->Location = System::Drawing::Point(698, 24);
			this->TEST->Name = L"TEST";
			this->TEST->Size = System::Drawing::Size(100, 26);
			this->TEST->TabIndex = 62;
			this->TEST->Visible = false;
			this->TEST->TextChanged += gcnew System::EventHandler(this, &MyForm::TEST_TextChanged);
			// 
			// buttonDelete
			// 
			this->buttonDelete->Location = System::Drawing::Point(214, 289);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(213, 70);
			this->buttonDelete->TabIndex = 64;
			this->buttonDelete->Text = L"Видалення";
			this->buttonDelete->UseVisualStyleBackColor = true;
			this->buttonDelete->Visible = false;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &MyForm::buttonDelete_Click);
			// 
			// buttonDeleteCof
			// 
			this->buttonDeleteCof->Location = System::Drawing::Point(27, 209);
			this->buttonDeleteCof->Name = L"buttonDeleteCof";
			this->buttonDeleteCof->Size = System::Drawing::Size(169, 74);
			this->buttonDeleteCof->TabIndex = 65;
			this->buttonDeleteCof->Text = L"Видалення коефіцієнта та відділу";
			this->buttonDeleteCof->UseVisualStyleBackColor = true;
			this->buttonDeleteCof->Visible = false;
			this->buttonDeleteCof->Click += gcnew System::EventHandler(this, &MyForm::buttonDeleteCof_Click);
			// 
			// buttonDeletePeople
			// 
			this->buttonDeletePeople->Location = System::Drawing::Point(115, 133);
			this->buttonDeletePeople->Name = L"buttonDeletePeople";
			this->buttonDeletePeople->Size = System::Drawing::Size(169, 74);
			this->buttonDeletePeople->TabIndex = 66;
			this->buttonDeletePeople->Text = L"Видалення даних про працівника";
			this->buttonDeletePeople->UseVisualStyleBackColor = true;
			this->buttonDeletePeople->Visible = false;
			this->buttonDeletePeople->Click += gcnew System::EventHandler(this, &MyForm::buttonDeletePeople_Click);
			// 
			// buttonDeleteTar
			// 
			this->buttonDeleteTar->Location = System::Drawing::Point(214, 215);
			this->buttonDeleteTar->Name = L"buttonDeleteTar";
			this->buttonDeleteTar->Size = System::Drawing::Size(169, 74);
			this->buttonDeleteTar->TabIndex = 67;
			this->buttonDeleteTar->Text = L"Видалення тарифу та посади";
			this->buttonDeleteTar->UseVisualStyleBackColor = true;
			this->buttonDeleteTar->Visible = false;
			this->buttonDeleteTar->Click += gcnew System::EventHandler(this, &MyForm::buttonDeleteTar_Click);
			// 
			// buttonDeletePeopleFaill
			// 
			this->buttonDeletePeopleFaill->Location = System::Drawing::Point(172, 437);
			this->buttonDeletePeopleFaill->Name = L"buttonDeletePeopleFaill";
			this->buttonDeletePeopleFaill->Size = System::Drawing::Size(100, 40);
			this->buttonDeletePeopleFaill->TabIndex = 68;
			this->buttonDeletePeopleFaill->Text = L"Видалити";
			this->buttonDeletePeopleFaill->UseVisualStyleBackColor = true;
			this->buttonDeletePeopleFaill->Visible = false;
			this->buttonDeletePeopleFaill->Click += gcnew System::EventHandler(this, &MyForm::buttonDeletePeopleFaill_Click);
			// 
			// labelDeletePepl
			// 
			this->labelDeletePepl->AutoSize = true;
			this->labelDeletePepl->Location = System::Drawing::Point(30, 416);
			this->labelDeletePepl->Name = L"labelDeletePepl";
			this->labelDeletePepl->Size = System::Drawing::Size(171, 20);
			this->labelDeletePepl->TabIndex = 70;
			this->labelDeletePepl->Text = L"Персональний номер";
			this->labelDeletePepl->Visible = false;
			// 
			// buttonDeleteCofFaill
			// 
			this->buttonDeleteCofFaill->Location = System::Drawing::Point(172, 436);
			this->buttonDeleteCofFaill->Name = L"buttonDeleteCofFaill";
			this->buttonDeleteCofFaill->Size = System::Drawing::Size(100, 44);
			this->buttonDeleteCofFaill->TabIndex = 71;
			this->buttonDeleteCofFaill->Text = L"Видалити";
			this->buttonDeleteCofFaill->UseVisualStyleBackColor = true;
			this->buttonDeleteCofFaill->Visible = false;
			this->buttonDeleteCofFaill->Click += gcnew System::EventHandler(this, &MyForm::buttonDeleteCofFaill_Click);
			// 
			// labelDeleteCof
			// 
			this->labelDeleteCof->AutoSize = true;
			this->labelDeleteCof->Location = System::Drawing::Point(42, 418);
			this->labelDeleteCof->Name = L"labelDeleteCof";
			this->labelDeleteCof->Size = System::Drawing::Size(114, 20);
			this->labelDeleteCof->TabIndex = 73;
			this->labelDeleteCof->Text = L"Назва відділу";
			this->labelDeleteCof->Visible = false;
			// 
			// buttonDeleteTarFaill
			// 
			this->buttonDeleteTarFaill->Location = System::Drawing::Point(172, 437);
			this->buttonDeleteTarFaill->Name = L"buttonDeleteTarFaill";
			this->buttonDeleteTarFaill->Size = System::Drawing::Size(100, 40);
			this->buttonDeleteTarFaill->TabIndex = 74;
			this->buttonDeleteTarFaill->Text = L"Видалити";
			this->buttonDeleteTarFaill->UseVisualStyleBackColor = true;
			this->buttonDeleteTarFaill->Visible = false;
			this->buttonDeleteTarFaill->Click += gcnew System::EventHandler(this, &MyForm::buttonDeleteTarFaill_Click);
			// 
			// labelDeleteTar
			// 
			this->labelDeleteTar->AutoSize = true;
			this->labelDeleteTar->Location = System::Drawing::Point(38, 416);
			this->labelDeleteTar->Name = L"labelDeleteTar";
			this->labelDeleteTar->Size = System::Drawing::Size(115, 20);
			this->labelDeleteTar->TabIndex = 76;
			this->labelDeleteTar->Text = L"Назва посади";
			this->labelDeleteTar->Visible = false;
			// 
			// BackbuttonDelete
			// 
			this->BackbuttonDelete->BackColor = System::Drawing::Color::LightCoral;
			this->BackbuttonDelete->Location = System::Drawing::Point(16, 12);
			this->BackbuttonDelete->Name = L"BackbuttonDelete";
			this->BackbuttonDelete->Size = System::Drawing::Size(96, 51);
			this->BackbuttonDelete->TabIndex = 77;
			this->BackbuttonDelete->Text = L"Назад";
			this->BackbuttonDelete->UseVisualStyleBackColor = false;
			this->BackbuttonDelete->Visible = false;
			this->BackbuttonDelete->Click += gcnew System::EventHandler(this, &MyForm::BackbuttonDelete_Click);
			// 
			// labelSort3on
			// 
			this->labelSort3on->AutoSize = true;
			this->labelSort3on->Location = System::Drawing::Point(310, 402);
			this->labelSort3on->Name = L"labelSort3on";
			this->labelSort3on->Size = System::Drawing::Size(142, 40);
			this->labelSort3on->TabIndex = 78;
			this->labelSort3on->Text = L"Відпрацювали\r\nбільше годин ніж:\r\n";
			this->labelSort3on->Visible = false;
			// 
			// labelSort4on
			// 
			this->labelSort4on->AutoSize = true;
			this->labelSort4on->Location = System::Drawing::Point(466, 402);
			this->labelSort4on->Name = L"labelSort4on";
			this->labelSort4on->Size = System::Drawing::Size(87, 40);
			this->labelSort4on->TabIndex = 79;
			this->labelSort4on->Text = L"Зарплата\r\nбільша за:";
			this->labelSort4on->Visible = false;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->ForeColor = System::Drawing::Color::Black;
			this->textBox1->Location = System::Drawing::Point(58, 449);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 26);
			this->textBox1->TabIndex = 80;
			this->textBox1->Visible = false;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::White;
			this->textBox2->ForeColor = System::Drawing::Color::Black;
			this->textBox2->Location = System::Drawing::Point(184, 447);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 26);
			this->textBox2->TabIndex = 81;
			this->textBox2->Visible = false;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::White;
			this->textBox3->ForeColor = System::Drawing::Color::Black;
			this->textBox3->Location = System::Drawing::Point(320, 447);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 26);
			this->textBox3->TabIndex = 82;
			this->textBox3->Visible = false;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::White;
			this->textBox4->ForeColor = System::Drawing::Color::Black;
			this->textBox4->Location = System::Drawing::Point(459, 447);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 26);
			this->textBox4->TabIndex = 83;
			this->textBox4->Visible = false;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::Color::White;
			this->textBox5->ForeColor = System::Drawing::Color::Black;
			this->textBox5->Location = System::Drawing::Point(607, 447);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 26);
			this->textBox5->TabIndex = 84;
			this->textBox5->Visible = false;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox5_TextChanged);
			// 
			// buttonEditingPepl
			// 
			this->buttonEditingPepl->Location = System::Drawing::Point(115, 135);
			this->buttonEditingPepl->Name = L"buttonEditingPepl";
			this->buttonEditingPepl->Size = System::Drawing::Size(169, 74);
			this->buttonEditingPepl->TabIndex = 85;
			this->buttonEditingPepl->Text = L"Редагування даних про працівника";
			this->buttonEditingPepl->UseVisualStyleBackColor = true;
			this->buttonEditingPepl->Visible = false;
			this->buttonEditingPepl->Click += gcnew System::EventHandler(this, &MyForm::buttonEditingPepl_Click);
			// 
			// buttonEditingCof
			// 
			this->buttonEditingCof->Location = System::Drawing::Point(34, 211);
			this->buttonEditingCof->Name = L"buttonEditingCof";
			this->buttonEditingCof->Size = System::Drawing::Size(169, 74);
			this->buttonEditingCof->TabIndex = 86;
			this->buttonEditingCof->Text = L"Редагування коефіцієнта та відділу";
			this->buttonEditingCof->UseVisualStyleBackColor = true;
			this->buttonEditingCof->Visible = false;
			this->buttonEditingCof->Click += gcnew System::EventHandler(this, &MyForm::buttonEditingCof_Click);
			// 
			// buttonEditingTar
			// 
			this->buttonEditingTar->Location = System::Drawing::Point(214, 215);
			this->buttonEditingTar->Name = L"buttonEditingTar";
			this->buttonEditingTar->Size = System::Drawing::Size(169, 74);
			this->buttonEditingTar->TabIndex = 87;
			this->buttonEditingTar->Text = L"Редагування тарифу та посади";
			this->buttonEditingTar->UseVisualStyleBackColor = true;
			this->buttonEditingTar->Visible = false;
			this->buttonEditingTar->Click += gcnew System::EventHandler(this, &MyForm::buttonEditingTar_Click);
			// 
			// buttonEditingPeplFile
			// 
			this->buttonEditingPeplFile->Location = System::Drawing::Point(753, 436);
			this->buttonEditingPeplFile->Name = L"buttonEditingPeplFile";
			this->buttonEditingPeplFile->Size = System::Drawing::Size(136, 53);
			this->buttonEditingPeplFile->TabIndex = 88;
			this->buttonEditingPeplFile->Text = L"Знайти";
			this->buttonEditingPeplFile->UseVisualStyleBackColor = true;
			this->buttonEditingPeplFile->Visible = false;
			this->buttonEditingPeplFile->Click += gcnew System::EventHandler(this, &MyForm::buttonEditingPeplFile_Click);
			// 
			// buttonEditingPeplFileDo
			// 
			this->buttonEditingPeplFileDo->Location = System::Drawing::Point(753, 439);
			this->buttonEditingPeplFileDo->Name = L"buttonEditingPeplFileDo";
			this->buttonEditingPeplFileDo->Size = System::Drawing::Size(136, 52);
			this->buttonEditingPeplFileDo->TabIndex = 89;
			this->buttonEditingPeplFileDo->Text = L"Редагувати";
			this->buttonEditingPeplFileDo->UseVisualStyleBackColor = true;
			this->buttonEditingPeplFileDo->Visible = false;
			this->buttonEditingPeplFileDo->Click += gcnew System::EventHandler(this, &MyForm::buttonEditingPeplFileDo_Click);
			// 
			// buttonEditingPeplFileR
			// 
			this->buttonEditingPeplFileR->Location = System::Drawing::Point(753, 495);
			this->buttonEditingPeplFileR->Name = L"buttonEditingPeplFileR";
			this->buttonEditingPeplFileR->Size = System::Drawing::Size(136, 52);
			this->buttonEditingPeplFileR->TabIndex = 90;
			this->buttonEditingPeplFileR->Text = L"Замінити працівника";
			this->buttonEditingPeplFileR->UseVisualStyleBackColor = true;
			this->buttonEditingPeplFileR->Visible = false;
			this->buttonEditingPeplFileR->Click += gcnew System::EventHandler(this, &MyForm::buttonEditingPeplFileR_Click);
			// 
			// labelEdittPepol1
			// 
			this->labelEdittPepol1->AutoSize = true;
			this->labelEdittPepol1->Location = System::Drawing::Point(8, 418);
			this->labelEdittPepol1->Name = L"labelEdittPepol1";
			this->labelEdittPepol1->Size = System::Drawing::Size(171, 20);
			this->labelEdittPepol1->TabIndex = 91;
			this->labelEdittPepol1->Text = L"Персональний номер";
			this->labelEdittPepol1->Visible = false;
			// 
			// labelEdittPepol2
			// 
			this->labelEdittPepol2->AutoSize = true;
			this->labelEdittPepol2->Location = System::Drawing::Point(340, 418);
			this->labelEdittPepol2->Name = L"labelEdittPepol2";
			this->labelEdittPepol2->Size = System::Drawing::Size(58, 20);
			this->labelEdittPepol2->TabIndex = 92;
			this->labelEdittPepol2->Text = L"Відділ";
			this->labelEdittPepol2->Visible = false;
			// 
			// labelEdittPepol3
			// 
			this->labelEdittPepol3->AutoSize = true;
			this->labelEdittPepol3->Location = System::Drawing::Point(481, 418);
			this->labelEdittPepol3->Name = L"labelEdittPepol3";
			this->labelEdittPepol3->Size = System::Drawing::Size(67, 20);
			this->labelEdittPepol3->TabIndex = 93;
			this->labelEdittPepol3->Text = L"Посада";
			this->labelEdittPepol3->Visible = false;
			// 
			// labelEdittPepol4
			// 
			this->labelEdittPepol4->AutoSize = true;
			this->labelEdittPepol4->Location = System::Drawing::Point(208, 415);
			this->labelEdittPepol4->Name = L"labelEdittPepol4";
			this->labelEdittPepol4->Size = System::Drawing::Size(37, 20);
			this->labelEdittPepol4->TabIndex = 94;
			this->labelEdittPepol4->Text = L"ПІБ";
			this->labelEdittPepol4->Visible = false;
			// 
			// labelEdittPepol5
			// 
			this->labelEdittPepol5->AutoSize = true;
			this->labelEdittPepol5->Location = System::Drawing::Point(564, 415);
			this->labelEdittPepol5->Name = L"labelEdittPepol5";
			this->labelEdittPepol5->Size = System::Drawing::Size(176, 20);
			this->labelEdittPepol5->TabIndex = 95;
			this->labelEdittPepol5->Text = L"Відпрацьовані години";
			this->labelEdittPepol5->Visible = false;
			// 
			// buttonEditingCofFill
			// 
			this->buttonEditingCofFill->Location = System::Drawing::Point(305, 441);
			this->buttonEditingCofFill->Name = L"buttonEditingCofFill";
			this->buttonEditingCofFill->Size = System::Drawing::Size(136, 44);
			this->buttonEditingCofFill->TabIndex = 96;
			this->buttonEditingCofFill->Text = L"Знайти";
			this->buttonEditingCofFill->UseVisualStyleBackColor = true;
			this->buttonEditingCofFill->Visible = false;
			this->buttonEditingCofFill->Click += gcnew System::EventHandler(this, &MyForm::buttonEditingCofFill_Click);
			// 
			// buttonEditingCoflFileDo
			// 
			this->buttonEditingCoflFileDo->Location = System::Drawing::Point(305, 441);
			this->buttonEditingCoflFileDo->Name = L"buttonEditingCoflFileDo";
			this->buttonEditingCoflFileDo->Size = System::Drawing::Size(136, 44);
			this->buttonEditingCoflFileDo->TabIndex = 97;
			this->buttonEditingCoflFileDo->Text = L"Редагувати";
			this->buttonEditingCoflFileDo->UseVisualStyleBackColor = true;
			this->buttonEditingCoflFileDo->Visible = false;
			this->buttonEditingCoflFileDo->Click += gcnew System::EventHandler(this, &MyForm::buttonEditingCoflFileDo_Click);
			// 
			// buttonEditingCofFileDoR
			// 
			this->buttonEditingCofFileDoR->Location = System::Drawing::Point(305, 492);
			this->buttonEditingCofFileDoR->Name = L"buttonEditingCofFileDoR";
			this->buttonEditingCofFileDoR->Size = System::Drawing::Size(122, 62);
			this->buttonEditingCofFileDoR->TabIndex = 98;
			this->buttonEditingCofFileDoR->Text = L"Замінити відділ";
			this->buttonEditingCofFileDoR->UseVisualStyleBackColor = true;
			this->buttonEditingCofFileDoR->Visible = false;
			this->buttonEditingCofFileDoR->Click += gcnew System::EventHandler(this, &MyForm::buttonEditingPeplFileDoR_Click);
			// 
			// labelEditingCof1
			// 
			this->labelEditingCof1->AutoSize = true;
			this->labelEditingCof1->Location = System::Drawing::Point(72, 418);
			this->labelEditingCof1->Name = L"labelEditingCof1";
			this->labelEditingCof1->Size = System::Drawing::Size(58, 20);
			this->labelEditingCof1->TabIndex = 99;
			this->labelEditingCof1->Text = L"Відділ";
			this->labelEditingCof1->Visible = false;
			// 
			// labelEditingCof2
			// 
			this->labelEditingCof2->AutoSize = true;
			this->labelEditingCof2->Location = System::Drawing::Point(180, 418);
			this->labelEditingCof2->Name = L"labelEditingCof2";
			this->labelEditingCof2->Size = System::Drawing::Size(94, 20);
			this->labelEditingCof2->TabIndex = 100;
			this->labelEditingCof2->Text = L"Коєфіціент";
			this->labelEditingCof2->Visible = false;
			// 
			// BackbuttonEdiit
			// 
			this->BackbuttonEdiit->BackColor = System::Drawing::Color::LightCoral;
			this->BackbuttonEdiit->Location = System::Drawing::Point(16, 12);
			this->BackbuttonEdiit->Name = L"BackbuttonEdiit";
			this->BackbuttonEdiit->Size = System::Drawing::Size(96, 51);
			this->BackbuttonEdiit->TabIndex = 101;
			this->BackbuttonEdiit->Text = L"Назад";
			this->BackbuttonEdiit->UseVisualStyleBackColor = false;
			this->BackbuttonEdiit->Visible = false;
			this->BackbuttonEdiit->Click += gcnew System::EventHandler(this, &MyForm::BackbuttonEdiit_Click);
			// 
			// buttonEditingTarFill
			// 
			this->buttonEditingTarFill->Location = System::Drawing::Point(305, 445);
			this->buttonEditingTarFill->Name = L"buttonEditingTarFill";
			this->buttonEditingTarFill->Size = System::Drawing::Size(136, 44);
			this->buttonEditingTarFill->TabIndex = 102;
			this->buttonEditingTarFill->Text = L"Знайти";
			this->buttonEditingTarFill->UseVisualStyleBackColor = true;
			this->buttonEditingTarFill->Visible = false;
			this->buttonEditingTarFill->Click += gcnew System::EventHandler(this, &MyForm::buttonEditingTarFill_Click);
			// 
			// buttonEditingTarFillDo
			// 
			this->buttonEditingTarFillDo->Location = System::Drawing::Point(305, 442);
			this->buttonEditingTarFillDo->Name = L"buttonEditingTarFillDo";
			this->buttonEditingTarFillDo->Size = System::Drawing::Size(136, 44);
			this->buttonEditingTarFillDo->TabIndex = 103;
			this->buttonEditingTarFillDo->Text = L"Редагувати";
			this->buttonEditingTarFillDo->UseVisualStyleBackColor = true;
			this->buttonEditingTarFillDo->Visible = false;
			this->buttonEditingTarFillDo->Click += gcnew System::EventHandler(this, &MyForm::buttonEditingTarFillDo_Click);
			// 
			// buttonEditingTarFillDoR
			// 
			this->buttonEditingTarFillDoR->Location = System::Drawing::Point(305, 491);
			this->buttonEditingTarFillDoR->Name = L"buttonEditingTarFillDoR";
			this->buttonEditingTarFillDoR->Size = System::Drawing::Size(122, 59);
			this->buttonEditingTarFillDoR->TabIndex = 104;
			this->buttonEditingTarFillDoR->Text = L"Замінити посаду";
			this->buttonEditingTarFillDoR->UseVisualStyleBackColor = true;
			this->buttonEditingTarFillDoR->Visible = false;
			this->buttonEditingTarFillDoR->Click += gcnew System::EventHandler(this, &MyForm::buttonEditingTarFillDoR_Click);
			// 
			// labelEditingTar1
			// 
			this->labelEditingTar1->AutoSize = true;
			this->labelEditingTar1->Location = System::Drawing::Point(76, 415);
			this->labelEditingTar1->Name = L"labelEditingTar1";
			this->labelEditingTar1->Size = System::Drawing::Size(67, 20);
			this->labelEditingTar1->TabIndex = 105;
			this->labelEditingTar1->Text = L"Посада";
			this->labelEditingTar1->Visible = false;
			// 
			// labelEditingTar2
			// 
			this->labelEditingTar2->AutoSize = true;
			this->labelEditingTar2->Location = System::Drawing::Point(186, 417);
			this->labelEditingTar2->Name = L"labelEditingTar2";
			this->labelEditingTar2->Size = System::Drawing::Size(60, 20);
			this->labelEditingTar2->TabIndex = 106;
			this->labelEditingTar2->Text = L"Тариф";
			this->labelEditingTar2->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(150)));
			this->ClientSize = System::Drawing::Size(1676, 771);
			this->Controls->Add(this->labelEditingTar2);
			this->Controls->Add(this->labelEditingTar1);
			this->Controls->Add(this->buttonEditingTarFillDoR);
			this->Controls->Add(this->buttonEditingTarFillDo);
			this->Controls->Add(this->buttonEditingTarFill);
			this->Controls->Add(this->BackbuttonEdiit);
			this->Controls->Add(this->labelEditingCof2);
			this->Controls->Add(this->labelEditingCof1);
			this->Controls->Add(this->buttonEditingCofFileDoR);
			this->Controls->Add(this->buttonEditingCoflFileDo);
			this->Controls->Add(this->buttonEditingCofFill);
			this->Controls->Add(this->labelEdittPepol5);
			this->Controls->Add(this->labelEdittPepol4);
			this->Controls->Add(this->labelEdittPepol3);
			this->Controls->Add(this->labelEdittPepol2);
			this->Controls->Add(this->labelEdittPepol1);
			this->Controls->Add(this->buttonEditingPeplFileR);
			this->Controls->Add(this->buttonEditingPeplFileDo);
			this->Controls->Add(this->buttonEditingPeplFile);
			this->Controls->Add(this->buttonEditingTar);
			this->Controls->Add(this->buttonEditingCof);
			this->Controls->Add(this->buttonEditingPepl);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->labelSort4on);
			this->Controls->Add(this->labelSort3on);
			this->Controls->Add(this->BackbuttonDelete);
			this->Controls->Add(this->labelDeleteTar);
			this->Controls->Add(this->buttonDeleteTarFaill);
			this->Controls->Add(this->labelDeleteCof);
			this->Controls->Add(this->buttonDeleteCofFaill);
			this->Controls->Add(this->labelDeletePepl);
			this->Controls->Add(this->buttonDeletePeopleFaill);
			this->Controls->Add(this->buttonDeleteTar);
			this->Controls->Add(this->buttonDeletePeople);
			this->Controls->Add(this->buttonDeleteCof);
			this->Controls->Add(this->buttonDelete);
			this->Controls->Add(this->TEST);
			this->Controls->Add(this->textBoxSortAllNoumber);
			this->Controls->Add(this->checkBoxMinMaxHors);
			this->Controls->Add(this->checkBoxMinMaxWeg);
			this->Controls->Add(this->labelSearch1);
			this->Controls->Add(this->buttonSearchDo);
			this->Controls->Add(this->buttonSearch);
			this->Controls->Add(this->labelSort4);
			this->Controls->Add(this->labelSort3);
			this->Controls->Add(this->labelSort2);
			this->Controls->Add(this->labelSort1);
			this->Controls->Add(this->buttonSort);
			this->Controls->Add(this->buttonRaundNoumber);
			this->Controls->Add(this->buttonEditing);
			this->Controls->Add(this->buttonAddTarFaill);
			this->Controls->Add(this->labelAddTar2);
			this->Controls->Add(this->labelAddTar1);
			this->Controls->Add(this->labelAddCof2);
			this->Controls->Add(this->labelAddCof1);
			this->Controls->Add(this->buttonAddCofFaill);
			this->Controls->Add(this->backButtonAdd);
			this->Controls->Add(this->buttonAddPeopleFaill);
			this->Controls->Add(this->labelYesOrNo);
			this->Controls->Add(this->noButton);
			this->Controls->Add(this->yesButton);
			this->Controls->Add(this->backButton);
			this->Controls->Add(this->labelAddPeople4);
			this->Controls->Add(this->labelAddPeople3);
			this->Controls->Add(this->labelAddPeople6);
			this->Controls->Add(this->labelAddPeople2);
			this->Controls->Add(this->labelAddPeople);
			this->Controls->Add(this->buttonAddCof);
			this->Controls->Add(this->buttonAddTar);
			this->Controls->Add(this->buttonAddPeople);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->labelSortAllNoumber);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Job program";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void(OffMenu1)() {
			button7->Visible = false;
			button6->Visible = false;
			button5->Visible = false;
			button4->Visible = false;
			buttonEditing->Visible = false;
			buttonSearch->Visible = false;
			buttonDelete->Visible = false;
		}
		Void(OnMenu1)() {
			button7->Visible = true;
			button6->Visible = true;
			button5->Visible = true;
			button4->Visible = true;
			buttonEditing->Visible = true;
			buttonSearch->Visible = true;
			buttonDelete->Visible = true;
			dataGridView1->Visible = true;
		}
		Void(PrintDataGridView1)(int i, bool wegOnOff)
		{
			if (wegOnOff)
				if (job_vector[i].wage != -1)//якщо зарплата існує 
				{
					dataGridView1->Rows->Add(
						job_vector[i].Personal_number,
						gcnew String(job_vector[i].PIB.c_str()),
						gcnew String(job_vector[i].Department.c_str()),
						gcnew String(job_vector[i].Position.c_str()),
						job_vector[i].Hours, job_vector[i].wage
					);
				}
				else
				{
					dataGridView1->Rows->Add(
						job_vector[i].Personal_number,
						gcnew String(job_vector[i].PIB.c_str()),
						gcnew String(job_vector[i].Department.c_str()),
						gcnew String(job_vector[i].Position.c_str()),
						job_vector[i].Hours, "Помилка!"
					);

				}
			else
			{
				dataGridView1->Rows->Add(
					job_vector[i].Personal_number,
					gcnew String(job_vector[i].PIB.c_str()),
					gcnew String(job_vector[i].Department.c_str()),
					gcnew String(job_vector[i].Position.c_str()),
					job_vector[i].Hours
				);
			}
			
		}
	private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	}
	double bigHour;
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ FileNameVector = ""; //змінна, де зберігається шлях до файлу
		FileNamePeple = ""; //змінна, де зберігається шлях до файлу
		if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK)
		{/*//відкр. діалогове вікно, якщо натиснути і дії будуть виконані
		 тільки у випадку коли діалог закінчиться успішно
		 */
			

			
		FileNameVector = openFileDialog1-> FileName; //шлях до обраного файлу
		MarshalString(FileNameVector, FileNamePeple); //виклик ф-ї перетворення між типами даних (див.пунк 4)
		

		fstream file(FileNamePeple);
		int chekFileNamePeple = 0;
		bool keyFileNamePeple = true;


		string line;
		while (getline(file, line) && keyFileNamePeple)
			{
				for (int i = 0; i < line.length(); i++)
				{

					if (line[i] == ' ') {
						chekFileNamePeple++;
					}

				}
			
				if (chekFileNamePeple != 4)
				{
					keyFileNamePeple = false;

				}
				else
				{
					chekFileNamePeple = 0;
				}
				
				line = "";
			}
		//цей код провіряє щр в кожній строці файла знаходиться саме 4 пробіла

			if (keyFileNamePeple)
				{
					FileNameVector = openFileDialog1->FileName; //шлях до обраного файлу
					MarshalString(FileNameVector, FileNamePeple); //виклик ф-ї перетворення між типами даних (див.пунк 4)

					bool KeyDATAInFail = true;
					fstream file(FileNamePeple);
					string Department;
					string Coefficient;
					string Position;
					string PIB;
					string Personal_numberSTR;
					string HoursSTR;
					while (file >> Personal_numberSTR) {
						file >> PIB >> Department >> Position >> HoursSTR;

						if (!StringInt(Personal_numberSTR) || !StringDouble(HoursSTR))
						{
							KeyDATAInFail = false;
						}
					}//провірка що всі поля файла можуть бути считані
					file.close();
					if (KeyDATAInFail)
					{
						try {


							
							fstream file(FileNamePeple);
							while (file >> Personal_numberSTR) {
								file >> PIB >> Department >> Position >> HoursSTR;
								int Personal_number = stoi(Personal_numberSTR);
								double Hours = stod(HoursSTR);
								job_vector.push_back({ Department,Position,PIB,Personal_number,Hours });
							}
							//доставання даних з файлу
							dataGridView1->Visible = true;
							dataGridView1->Columns->Clear();
							dataGridView1->Columns->Add("", "Personal number");
							dataGridView1->Columns->Add("", "PIB");
							dataGridView1->Columns->Add("", "Department");
							dataGridView1->Columns->Add("", "Position");
							dataGridView1->Columns->Add("", "Hours worked");
							for (int i = 0; i < job_vector.size(); i++)
							{
								dataGridView1->Rows->Add(
									job_vector[i].Personal_number,
									gcnew String(job_vector[i].PIB.c_str()),
									gcnew String(job_vector[i].Department.c_str()),
									gcnew String(job_vector[i].Position.c_str()),
									job_vector[i].Hours
								);
								if (bigHour < job_vector[i].Hours)
								{
									bigHour = job_vector[i].Hours;
								}
								//визначення найбільшого значення годин для сортування
							}
							// запись в таблицю
							for each (DataGridViewColumn ^ column in dataGridView1->Columns)
							{
								column->SortMode = DataGridViewColumnSortMode::NotSortable;
							}
							//відключення можливості сортировки для уникнення помилок
							button2->Visible = true;
							button3->Visible = true;
							button1->Visible = false;
						}
						catch (std::exception& e) {
							// обробка стандартних виключень
							MessageBox::Show(L"Вибачте, при записі даних сталася помилка (можливо за велике значення числа) ", L"Erorr", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
						}
						catch (...) {
							// обробка інших виключень
							MessageBox::Show(L"Вибачте, при записі даних сталася помилка (можливо за велике значення числа)  ", L"Erorr", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
						}

					}
					else
					{
						MessageBox::Show(L"Вибачте, тип даних у файлі не підходить.", L"Eror in file ", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);



					}

					
			}
			else
			{
				MessageBox::Show(L"Вибачте, тип файлу не підходить", L"Eror file type", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);


			}

	    }
		

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ FileNameVector2 = ""; //змінна, де зберігається шлях до файлу
		FileNameCof = ""; //змінна, де зберігається шлях до файлу
		if (openFileDialog2->ShowDialog() == Windows::Forms::DialogResult::OK) //відкр. діалогове вікно, якщо натиснути і дії будуть виконані тільки у випадку коли діалог закінчиться успішно
		{
			FileNameVector2 = openFileDialog2->FileName; //шлях до обраного файлу
			MarshalString(FileNameVector2, FileNameCof); //виклик ф-ї перетворення між типами даних (див.пунк 4)

			
			fstream file(FileNameCof);
			int chekFileNameCof = 0;
			bool keyFileNameCof = true;

			
			string line;
			while (getline(file, line) && keyFileNameCof)
			{
				for (int i = 0; i < line.length(); i++)
				{

					if (line[i] == ' ') {
						chekFileNameCof++;
					}

				}

				if (chekFileNameCof != 1)
				{
					keyFileNameCof = false;

				}
				else
				{
					chekFileNameCof = 0;
				}

				line = "";
			}
			//цей код провіряє щр в кожній строці файла знаходиться саме 4 пробіла


			if(keyFileNameCof){
				
				FileNameVector2 = openFileDialog2->FileName; //шлях до обраного файлу
				MarshalString(FileNameVector2, FileNameCof); //виклик ф-ї перетворення між типами даних (див.пунк 4)
				fstream file(FileNameCof);


				bool KeyCofInFail = true;
				string CoefficientSTR;
				string nema;

				while (file >> nema)
				{
					file >> CoefficientSTR;
					if (!StringDouble(CoefficientSTR))
					{
						KeyCofInFail = false;
					}
					
				}
				file.close();
				if (KeyCofInFail)
				{
					try
					{
						fstream file(FileNameCof);
						while (file >> nema)
						{
							file >> CoefficientSTR;
							double Coefficient = stod(CoefficientSTR);
							COF_vector.push_back({ nema,Coefficient });
						}

						if (!chek_button2) {
							chek_button2 += 1;
						}
						chek = chek_button2 + chek_button3;
						if (chek == 2) {
							OnMenu1();

							button3->Visible = false;
							button2->Visible = false;
							button1->Visible = false;
						}
						//провірка що юзер вів 2 файла в систему тобто натиснув і вів на обидві кнопки

						button2->Visible = false;
					}
					catch (std::exception& e) {
						// обробка стандартних виключень
						MessageBox::Show(L"Вибачте, при записі даних сталася помилка (можливо за велике значення числа) ", L"Erorr", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
					}
					catch (...) {
						// обробка інших виключень
						MessageBox::Show(L"Вибачте, при записі даних сталася помилка (можливо за велике значення числа)  ", L"Erorr", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
					}

				}
				else
				{
					MessageBox::Show(L"Вибачте, тип даних у файлі не підходить.", L"Eror in file ", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

				}


			}
			else
			{
				MessageBox::Show(L"Вибачте, тип файлу не підходить.", L"Eror file type", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);


			}
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ FileNameVector3 = ""; //змінна, де зберігається шлях до файлу
		FileNameTar = ""; //змінна, де зберігається шлях до файлу
		if (openFileDialog3->ShowDialog() == Windows::Forms::DialogResult::OK) //відкр. діалогове вікно, якщо натиснути і дії будуть виконані тільки у випадку коли діалог закінчиться успішно
		{
			FileNameVector3 = openFileDialog3->FileName; //шлях до обраного файлу
			MarshalString(FileNameVector3, FileNameTar); //виклик ф-ї перетворення між типами даних (див.пунк 4)

			fstream file(FileNameTar);

			
			int chekFileNameTar = 0;
			bool keyFileNameTar = true;


			string line;
			while (getline(file, line) && keyFileNameTar)
			{
				for (int i = 0; i < line.length(); i++)
				{

					if (line[i] == ' ') {
						chekFileNameTar++;
					}

				}

				if (chekFileNameTar != 1)
				{
					keyFileNameTar = false;

				}
				else
				{
					chekFileNameTar = 0;
				}

				line = "";
			}
			//цей код провіряє щр в кожній строці файла знаходиться саме 4 пробіла


			if(keyFileNameTar){

				FileNameVector3 = openFileDialog3->FileName; //шлях до обраного файлу
				MarshalString(FileNameVector3, FileNameTar); //виклик ф-ї перетворення між типами даних (див.пунк 4)
				fstream file(FileNameTar);
				bool KeyTarInFail = true;
				string TarifSTR;
				string name;
				while (file >> name)
				{
					file >> TarifSTR;
					if (!StringDouble(TarifSTR))
					{
						KeyTarInFail = false;
					}
					
				}
				file.close();
				if (KeyTarInFail)
				{
					try
					{
						fstream file(FileNameTar);
						while (file >> name)
						{
							file >> TarifSTR;
							double Tarif = stod(TarifSTR);
							TAR_vector.push_back({ name,Tarif });
						}

						if (!chek_button3)
						{
							chek_button3 += 1;
						}

						chek = chek_button2 + chek_button3;
						if (chek == 2) {
							OnMenu1();

							button3->Visible = false;
							button2->Visible = false;
							button1->Visible = false;


						}
						//провірка що юзер вів 2 файла в систему тобто натиснув і вів на обидві кнопки
						button3->Visible = false;
					}
					catch (std::exception& e) {
						// обробка стандартних виключень
						MessageBox::Show(L"Вибачте, при записі даних сталася помилка (можливо за велике значення числа) ", L"Erorr", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
					}
					catch (...) {
						// обробка інших виключень
						MessageBox::Show(L"Вибачте, при записі даних сталася помилка (можливо за велике значення числа)  ", L"Erorr", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
					}
				}
				else
				{
					MessageBox::Show(L"Вибачте, тип даних у файлі не підходить.", L"Eror in file ", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

				}
			}
			else
			{
				MessageBox::Show(L"Вибачте, тип файлу не підходить.", L"Eror file type", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);


			}
		}

	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void dataGridView2_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void dataGridView3_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	//кнопка розрахунку зарплати
	double BigWeg=0;
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {

		for (int i = 0; i < job_vector.size(); i++)//проходемося по всіх елементах вектора
		{
			for (int j = 0; j < COF_vector.size(); j++)//проходження по структурі з коєфіціентом
			{


				if (job_vector[i].Department == COF_vector[j].nema)//провірка що віділ з файлу з людми  існує в файлу з коєфіцентами 
				{
					
					for (int I = 0; I < TAR_vector.size(); I++)//проходження по структурі з тарифами
					{
						if (job_vector[i].Position == TAR_vector[I].neam)//провірка що посада з файлу з людми  існує в файлу з тарифами 
						{
							job_vector[i].wage = COF_vector[j].coefficient * TAR_vector[I].coefficient * job_vector[i].Hours;//розрахунок та запись зарплати в вектор
							if (BigWeg<job_vector[i].wage)
							{
								BigWeg=job_vector[i].wage;
							}
							
						}
					}

				}
			}
		}
		dataGridView1->Columns->Clear();
		dataGridView1->Columns->Add("", "Personal number");
		dataGridView1->Columns->Add("", "PIB");
		dataGridView1->Columns->Add("", "Department");
		dataGridView1->Columns->Add("", "Position");
		dataGridView1->Columns->Add("", "Horse work");
		dataGridView1->Columns->Add("", "Wage");
		for (int i = 0; i < job_vector.size(); i++) {
			PrintDataGridView1(i, true);
		}
		for each (DataGridViewColumn ^ column in dataGridView1->Columns)
		{
			column->SortMode = DataGridViewColumnSortMode::NotSortable;
		}
		//відключення можливості сортировки для уникнення помилок
	}
//кнопка яка відкриває діалог заміни файлу
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	buttonSearch->Visible = false;
	button7->Visible = false;
	button6->Visible = false;
	button5->Visible = false;
	button4->Visible = false;
	button3->Visible = false;
	button2->Visible = false;
	button1->Visible = false;
	dataGridView1->Visible = false;
	buttonEditing->Visible = false;
	buttonDelete->Visible = false;

	labelYesOrNo->Visible = true;
	yesButton->Visible = true;
	noButton->Visible = true;
}

//кнопка яка відкриває сортировку
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	OffMenu1();

	labelSortAllNoumber->Visible = true;
	textBoxSortAllNoumber->Visible = true;
	checkBoxMinMaxWeg->Visible = true;
	checkBoxMinMaxHors->Visible = true;
	backButton->Visible = true;
	buttonSort->Visible = true;
	textBox1->Visible = true;
	textBox4->Visible = true;
	textBox2->Visible = true;
	textBox3->Visible = true;
	labelSort1->Visible = true;
	labelSort2->Visible = true;
	labelSort3->Visible = true;
	labelSort4->Visible = true;

	dataGridView1->Columns->Clear();
	dataGridView1->Columns->Add("", "Personsl nomber");
	dataGridView1->Columns->Add("", "PIB");
	dataGridView1->Columns->Add("", "Department");
	dataGridView1->Columns->Add("", "Position");
	dataGridView1->Columns->Add("", "Hours worked");
	dataGridView1->Columns->Add("", "Wage");
	for (int i = 0; i < job_vector.size(); i++) 
	{

		if (job_vector[i].wage != -1)//якщо зарплата існує 
		{
			dataGridView1->Rows->Add(
				job_vector[i].Personal_number,
				gcnew String(job_vector[i].PIB.c_str()),
				gcnew String(job_vector[i].Department.c_str()),
				gcnew String(job_vector[i].Position.c_str()),
				job_vector[i].Hours, job_vector[i].wage
			);
		}
		else
		{
			dataGridView1->Rows->Add(
				job_vector[i].Personal_number,
				gcnew String(job_vector[i].PIB.c_str()),
				gcnew String(job_vector[i].Department.c_str()),
				gcnew String(job_vector[i].Position.c_str()),
				job_vector[i].Hours, "Помилка!"
			);

		}

	}
	for each (DataGridViewColumn ^ column in dataGridView1->Columns)
	{
		column->SortMode = DataGridViewColumnSortMode::NotSortable;
	}
}
//кнопка відкритя діалогу додавання елементу в файли
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	OffMenu1();

	buttonAddCof->Visible = true;
	buttonAddPeople->Visible = true;
	buttonAddTar->Visible = true;
	backButton->Visible = true;
	buttonEditing->Visible = false;
}
private: System::Void buttonAddPeople_Click(System::Object^ sender, System::EventArgs^ e) {


	System::String^ sevNum1 = msclr::interop::marshal_as<System::String^>(sevNum);//функція пертворення зі 
	System::String^ sevPIB1 = msclr::interop::marshal_as<System::String^>(sevPIB);//функція пертворення зі 
	textBox1->Text = sevNum1;
	textBox2->Text = sevPIB1;

	backButtonAdd->Visible = true;
	buttonAddPeople->Visible = false;
	buttonAddCof->Visible = false;
	buttonAddTar->Visible = false;
	backButton->Visible = false;

	buttonAddPeopleFaill->Visible = true;

	labelAddPeople->Visible = true;
	labelAddPeople2->Visible = true;
	labelAddPeople3->Visible = true;
	labelAddPeople4->Visible = true;
	labelAddPeople6->Visible = true;

	textBox1->Visible = true;
	textBox2->Visible = true;
	textBox3->Visible = true;
	textBox4->Visible = true;
	textBox5->Visible = true;

	dataGridView1->Columns->Clear();
	dataGridView1->Columns->Add("", "Personsl nomber");
	dataGridView1->Columns->Add("", "PIB");
	dataGridView1->Columns->Add("", "Department");
	dataGridView1->Columns->Add("", "Position");
	dataGridView1->Columns->Add("", "Hours worked");
	for (int i = 0; i < job_vector.size(); i++) {
		PrintDataGridView1(i, false);

	}
	for each (DataGridViewColumn ^ column in dataGridView1->Columns)
	{
		column->SortMode = DataGridViewColumnSortMode::NotSortable;
	}
	//відключення можливості сортировки для уникнення помилок



}
private: System::Void buttonAddCof_Click(System::Object^ sender, System::EventArgs^ e) {
	MarshalString(textBox1->Text, sevNum);
	MarshalString(textBox2->Text, sevPIB);
	textBox1->Clear();
	textBox2->Clear();
	textBox1->Text = textBox3->Text;
	buttonAddPeopleFaill->Visible = false;

	labelAddPeople->Visible = false;
	labelAddPeople2->Visible = false;
	labelAddPeople3->Visible = false;
	labelAddPeople4->Visible = false;
	labelAddPeople6->Visible = false;
	
	labelEdittPepol1->Visible = false;
	labelEdittPepol2->Visible = false;
	labelEdittPepol3->Visible = false;
	labelEdittPepol4->Visible = false;
	labelEdittPepol5->Visible = false;

	textBox3->Visible = false;
	textBox4->Visible = false;
	textBox5->Visible = false;
	

	buttonEditingPeplFileDo->Visible = false;
	buttonEditingPeplFileR->Visible = false;
	buttonAddCof->Visible = false;
	buttonAddPeople->Visible = false;
	buttonAddTar->Visible = false;
	backButton->Visible = false;
	buttonRaundNoumber->Visible = false;
	
	backButtonAdd->Visible = true;

	labelAddCof1->Visible = true;
	labelAddCof2->Visible = true;

	textBox1->Visible = true;
	textBox2->Visible = true;

	buttonAddCofFaill->Visible = true;
	dataGridView1->Columns->Clear();
	dataGridView1->Columns->Add("", "Name");
	dataGridView1->Columns->Add("", "Coefficient");
	for (int i = 0; i < COF_vector.size(); i++)
	{
		dataGridView1->Rows->Add(gcnew String(COF_vector[i].nema.c_str()),
			COF_vector[i].coefficient);
	}
	for each (DataGridViewColumn ^ column in dataGridView1->Columns)
	{
		column->SortMode = DataGridViewColumnSortMode::NotSortable;
	}
	//відключення можливості сортировки для уникнення помилок
}
private: System::Void buttonAddTar_Click(System::Object^ sender, System::EventArgs^ e) {
	MarshalString(textBox1->Text, sevNum);
	 MarshalString(textBox2->Text, sevPIB);
	textBox1->Clear();
	textBox2->Clear();
	textBox1->Text = textBox4->Text;
	buttonAddPeopleFaill->Visible = false;
	labelAddPeople->Visible = false;
	labelAddPeople2->Visible = false;
	labelAddPeople3->Visible = false;
	labelAddPeople4->Visible = false;
	labelAddPeople6->Visible = false;

	labelEdittPepol1->Visible = false;
	labelEdittPepol2->Visible = false;
	labelEdittPepol3->Visible = false;
	labelEdittPepol4->Visible = false;
	labelEdittPepol5->Visible = false;


	textBox3->Visible = false;
	textBox4->Visible = false;
	textBox5->Visible = false;

	buttonEditingPeplFileDo->Visible = false;
	buttonEditingPeplFileR->Visible = false;
	buttonAddCof->Visible = false;
	buttonAddPeople->Visible = false;
	buttonAddTar->Visible = false;
	backButton->Visible = false;
	buttonRaundNoumber->Visible = false;

	buttonAddTarFaill->Visible = true;
	backButtonAdd->Visible = true;
	labelAddTar1 -> Visible = true;
	labelAddTar2 -> Visible = true;

	textBox1->Visible = true;
	textBox2->Visible = true;
	
	dataGridView1->Columns->Clear();
	dataGridView1->Columns->Add("", "Name");
	dataGridView1->Columns->Add("", "Coefficient");
	for (int i = 0; i < TAR_vector.size(); i++)
	{
		dataGridView1->Rows->Add(gcnew String(TAR_vector[i].neam.c_str()),
			TAR_vector[i].coefficient);
	}
	for each (DataGridViewColumn ^ column in dataGridView1->Columns)
	{
		column->SortMode = DataGridViewColumnSortMode::NotSortable;
	}
	//відключення можливості сортировки для уникнення помилок

}
//кнопка яка повертає до розрахунка зарплати і т.д
private: System::Void backButton_Click(System::Object^ sender, System::EventArgs^ e) {
	OnMenu1();

	textBox1->BackColor = Color::WhiteSmoke;
	textBox2->BackColor = Color::WhiteSmoke;
	textBox3->BackColor = Color::WhiteSmoke;
	textBox4->BackColor = Color::WhiteSmoke;
	textBox5->BackColor = Color::WhiteSmoke;


	textBox1->Visible = false;
	textBox2->Visible = false;
	textBox3->Visible = false;
	textBox4->Visible = false;

	textBox1->Clear();
	textBox2->Clear();
	textBox3->Clear();
	textBox4->Clear();

	labelSort4on->Visible = false;
	labelSort3on->Visible = false;
	buttonDeletePeople->Visible = false;
	buttonDeleteCof->Visible = false;
	buttonDeleteTar->Visible = false;
	labelSortAllNoumber->Visible = false;
	textBoxSortAllNoumber->Visible = false;
	checkBoxMinMaxHors->Visible = false;
	checkBoxMinMaxWeg->Visible = false;
	buttonSearchDo->Visible = false;
	labelSearch1->Visible = false;
	
	yesButton->Visible = false;
	noButton->Visible = false;
	buttonAddPeople->Visible = false;
	buttonAddCof->Visible = false;
	buttonAddTar->Visible = false;
	backButton->Visible = false;
	buttonSort->Visible = false;
	buttonEditingPepl->Visible = false;
	buttonEditingTar->Visible = false;
	buttonEditingCof->Visible = false;
	labelSort1->Visible = false;
	labelSort2->Visible = false;
	labelSort3->Visible = false;
	labelSort4->Visible = false;


}
private: System::Void yesButton_Click(System::Object^ sender, System::EventArgs^ e) {
	job_vector.clear();
	COF_vector.clear();
	TAR_vector.clear();
	// очищення векторів для запобігану "наслоюваня" інформації одну на одну
	button7->Visible = false;
	button6->Visible = false;
	button5->Visible = false;
	button4->Visible = false;
	button3->Visible = false;
	button2->Visible = false;
	yesButton->Visible = false;
	noButton->Visible = false;
	button1->Visible = true;
	labelYesOrNo->Visible = false;

	chek = 0;
	chek_button2 = 0;
	chek_button3 = 0;
	//очищення чек маркерів для кнопок
}
private: System::Void noButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	OnMenu1();

	yesButton->Visible = false;
	noButton->Visible = false;
	button1->Visible = false;
	labelYesOrNo->Visible = false;
	
	
}



	  
private: System::Void buttonAddPeopleFaill_Click(System::Object^ sender, System::EventArgs^ e) {
	try
	{


		buttonAddTar->Visible = false;
		buttonAddCof->Visible = false;
		

		//портібно якщо при обропці помилок які включають ці кнопки пользеватель просто вирішить змінити назву посади та відела на коректні
		if (textBox3->Text != "" && textBox4->Text != "" && textBox2->Text != "" && textBox1->Text != "" && textBox5->Text != "") {
			bool keyAddPepleDep = false;
			bool keyAddPeplePos = false;
			bool keyAddPepleNum1 = true;
			bool keyAddPepleNum2 = true;
			bool keyAddPepleHou1 = true;
			bool keyAddPepleHou2 = true;
			//ключі від помилок

			string Department; MarshalString(textBox3->Text, Department);
			for (int i = 0; i < Department.length(); i++)
			{
				if ((Department[i] == ' ') || (Department[i] == '	')) {

					Department[i] = '_';
				}
			}
			//заміна пробіли на інші знаки

			for (int i = 0; i < COF_vector.size(); i++)
			{
				if (COF_vector[i].nema == Department)
				{
					keyAddPepleDep = true;
				}
			}
			//провірка що такий підрозділ існує
			string Position; MarshalString(textBox4->Text, Position);
			for (int i = 0; i < Position.length(); i++)
			{
				if ((Position[i] == ' ') || (Position[i] == '	')) {

					Position[i] = '_';
				}
			}
			//заміна пробіли на інші знаки

			for (int i = 0; i < TAR_vector.size(); i++)
			{
				if (TAR_vector[i].neam == Position)
				{
					keyAddPeplePos = true;
				}
			}
			//провірка що така посада існує
			string PIB; MarshalString(textBox2->Text, PIB);
			for (int i = 0; i < PIB.length(); i++)
			{
				if ((PIB[i] == ' ') || (PIB[i] == '	')) {

					PIB[i] = '_';
				}
			}//заміна пробіли на інші знаки




			string Personal_number; MarshalString(textBox1->Text, Personal_number);

			keyAddPepleNum1 = StringInt(Personal_number);
			if (keyAddPepleNum1) {
				string Personal_numberstr; MarshalString(textBox1->Text, Personal_numberstr);
				int Personal_number = stoi(Personal_numberstr);//Convert::ToInt64(textBoxAddPepleNoumber->Text);
				for (int i = 0; i < job_vector.size(); i++)
				{
					if (job_vector[i].Personal_number == Personal_number)//провірка що персональний номер унікальний
					{
						keyAddPepleNum2 = false;
					}
				}
			}

			string Hoursstr; MarshalString(textBox5->Text, Hoursstr);
			keyAddPepleHou1 = StringDouble(Hoursstr);
			if (keyAddPepleHou1)
			{
				double Hours = stod(Hoursstr);

				if (Hours > 192) {
					keyAddPepleHou2 = false;
				}
			}

			if (keyAddPepleDep && keyAddPepleHou1 && keyAddPepleHou2 && keyAddPepleNum2 && keyAddPepleNum1 && keyAddPeplePos)
			{
				int Personal_number = Convert::ToInt64(textBox1->Text);
				double Hours = stod(Hoursstr);
				job_vector.push_back({ Department,Position,PIB, Personal_number,Hours });
				dataGridView1->Rows->Add(
					Personal_number,
					gcnew String(PIB.c_str()),
					gcnew String(Position.c_str()),
					gcnew String(Department.c_str()),
					Hours
				);
				ofstream text2(FileNamePeple);
				for (auto& element : job_vector) {
					text2 << element.Personal_number << ' ' << element.PIB << ' ' << element.Department << ' '
						<< element.Position << ' ' << element.Hours << endl;
				}


				OnMenu1();

				button3->Visible = false;
				button2->Visible = false;
				yesButton->Visible = false;
				noButton->Visible = false;
				button1->Visible = false;
				buttonAddPeople->Visible = false;
				buttonAddCof->Visible = false;
				buttonAddTar->Visible = false;
				backButton->Visible = false;
				buttonAddPeopleFaill->Visible = false;
				backButtonAdd->Visible = false;
				buttonRaundNoumber->Visible = false;
				labelAddPeople->Visible = false;
				labelAddPeople2->Visible = false;
				labelAddPeople3->Visible = false;
				labelAddPeople4->Visible = false;
				labelAddPeople6->Visible = false;
				textBox5->Visible = false;
				textBox2->Visible = false;
				textBox4->Visible = false;
				textBox3->Visible = false;
				textBox1->Visible = false;
				textBox5->Clear();
				textBox2->Clear();
				textBox4->Clear();
				textBox3->Clear();
				textBox1->Clear();

			}
			if (!keyAddPepleDep && !keyAddPeplePos)
			{

				MessageBox::Show(L"Вибачте, ви ввели некоректний відділ та посаду. Будь ласка, додайте правильний відділ та посаду або змініть їх на існуючі.  ", L"Erorr not deport and positon", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
				textBox4->BackColor = Color::LightCoral;
				textBox3->BackColor = Color::LightCoral;
				buttonAddTar->Visible = true;
				buttonAddCof->Visible = true;
				MarshalString(textBox1->Text, sevNum);
				MarshalString(textBox2->Text, sevPIB);



			}

			else if (!keyAddPepleDep)
			{

				textBox3->BackColor = Color::LightCoral;
				MessageBox::Show(L"Вибачте, ви ввели некоректний відділ. Будь ласка, додайте правильний відділ або змініть його. ", L"Erorr not deport", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
				buttonAddCof->Visible = true;
				MarshalString(textBox1->Text, sevNum);
				MarshalString(textBox2->Text, sevPIB);
			}
			else if (!keyAddPeplePos) {

				textBox4->BackColor = Color::LightCoral;
				MessageBox::Show(L"Вибачте, ви ввели некоректну посаду. Будь ласка, додайте правильну посаду або змініть її  ", L"Eror not positon", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
				buttonAddTar->Visible = true;
				MarshalString(textBox1->Text, sevNum);
				MarshalString(textBox2->Text, sevPIB);
			}

			if (!keyAddPepleNum1)
			{
				textBox1->BackColor = Color::LightCoral;
				MessageBox::Show(L"Вибачте, ви ввели некоректний номер. Будь ласка, перевірте, що у номері відсутні пробіли, риски або точки. ", L"Eror int", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

			}
			if (!keyAddPepleNum2)
			{
				textBox1->BackColor = Color::LightCoral;
				buttonRaundNoumber->Visible = true;
				MessageBox::Show(L"Вибачте, ви ввели вже існуючий персональний номер. Змініть його або згенеруйте новий, який ще не зайнятий ", L"Erorr personal noumber copy", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

			}
			if (!keyAddPepleHou1)
			{
				textBox5->BackColor = Color::LightCoral;
				MessageBox::Show(L"Вибачте, ви ввели некоректне число. Перевірте, чи відсутні пробіли або подвійні точки.  ", L"Erorr Double", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

			}
			if (!keyAddPepleHou2)
			{/*textBoxAddPeopleHorse->Visible = false;
				textBoxAddPeoplePIB->Visible = false;
				textBoxAddPeoplePosition->Visible = false;
				textBoxAddPepleDeportament->Visible = false;
				textBoxAddPepleNoumber->Visible = false;*/
				textBox5->BackColor = Color::LightCoral;
				MessageBox::Show(L"Трудовим кодексом України заборонено працювати більше ніж 192 години на місяць  ", L"Erorr exaggeration of norms", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

			}
		}
		else
		{
			MessageBox::Show(L"Вибачте, одне або декілька полів порожні  ", L"Erorr None", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

		}
	}
	catch (std::exception& e) {
		// обробка стандартних виключень
		MessageBox::Show(L"Вибачте, при вводі даних сталася помилка (можливо за велике значення числа) ", L"Erorr", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}
	catch (...) {
		// обробка інших виключень
		MessageBox::Show(L"Вибачте, при вводі даних сталася помилка (можливо за велике значення числа)  ", L"Erorr", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}

}
private: System::Void backButtonAdd_Click(System::Object^ sender, System::EventArgs^ e) {

	textBox1->BackColor = Color::WhiteSmoke;
	textBox2->BackColor = Color::WhiteSmoke;
	textBox3->BackColor = Color::WhiteSmoke;
	textBox4->BackColor = Color::WhiteSmoke;
	textBox5->BackColor = Color::WhiteSmoke;

	buttonAddCof->Visible = true;
	buttonAddPeople->Visible = true;
	buttonAddTar->Visible = true;
	backButton->Visible = true;

	labelSort4on->Visible = false;
	labelSort3on->Visible = false;
	buttonRaundNoumber->Visible = false;
	buttonAddTarFaill->Visible = false;
	backButtonAdd->Visible = false;
	labelAddTar1->Visible = false;
	labelAddTar2->Visible = false;
	backButtonAdd->Visible = false;
	labelAddCof1->Visible = false;
	labelAddCof2->Visible = false;
	
	buttonAddCofFaill->Visible = false;
	backButtonAdd->Visible = false;
	buttonAddPeopleFaill->Visible = false;
	labelAddPeople->Visible = false;
	labelAddPeople2->Visible = false;
	labelAddPeople3->Visible = false;
	labelAddPeople4->Visible = false;
	labelAddPeople6->Visible = false;

	textBox1->Visible = false;
	textBox2->Visible = false;
	textBox3->Visible = false;
	textBox4->Visible = false;
	textBox5->Visible = false;


	
}
private: System::Void buttonAddCofFaill_Click(System::Object^ sender, System::EventArgs^ e) {
	try
	{
		if (textBox1->Text != "" && textBox2->Text != "") {
			bool keyAddCofName = true;
			bool keyAddCofCoefficient = true;

			string Name; MarshalString(textBox1->Text, Name);
			for (int i = 0; i < Name.length(); i++)
			{
				if ((Name[i] == ' ') || (Name[i] == '	')) {

					Name[i] = '_';
				}
			}
			for (int i = 0; i < COF_vector.size(); i++)
			{
				if (COF_vector[i].nema == Name) {
					keyAddCofName = false;

				}
			}
			string Coefficientstr; MarshalString(textBox2->Text, Coefficientstr);
			keyAddCofCoefficient = StringDouble(Coefficientstr);
			if (keyAddCofCoefficient && keyAddCofName) {
				double Coefficient = stod(Coefficientstr);

				COF_vector.push_back({ Name,Coefficient });
				dataGridView1->Rows->Add
				(
					gcnew String(Name.c_str()),
					Coefficient, gcnew String(FileNameCof.c_str())
				);
				ofstream text4(FileNameCof);
				for (auto& element : COF_vector) {
					text4 << element.nema << " " << element.coefficient << endl;

				}
				backButtonAdd->Visible = false;
				labelAddCof1->Visible = false;
				labelAddCof2->Visible = false;
			
				textBox1->Visible = false;
				textBox2->Visible = false;
				buttonAddCofFaill->Visible = false;
				buttonAddCof->Visible = true;
				buttonAddPeople->Visible = true;
				buttonAddTar->Visible = true;
				backButton->Visible = true;
				textBox2->Clear();
				textBox1->Clear();
			}
			if (!keyAddCofCoefficient) {
				textBox2->BackColor = Color::LightCoral;
				MessageBox::Show(L"Вибачте, ви ввели некоректний коефіцієнт. Перевірте, чи відсутні пробіли або подвійні крапки ", L"Erorr Double", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);


			}
			if (!keyAddCofName)
			{
				textBox1->BackColor = Color::LightCoral;
				MessageBox::Show(L"Вибачте, відділ з таким іменем вже існує. Змініть назву або відредагуйте бажаний відділ   ", L"Erorr Name", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

			}
		}
		else
		{
			MessageBox::Show(L"Вибачте, одне або декілька полів порожні   ", L"Erorr None", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

		}
	}
	catch (std::exception& e) {
		// обробка стандартних виключень
		MessageBox::Show(L"Вибачте, при вводі даних сталася помилка (можливо за велике значення числа) ", L"Erorr", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}
	catch (...) {
		// обробка інших виключень
		MessageBox::Show(L"Вибачте, при вводі даних сталася помилка (можливо за велике значення числа)  ", L"Erorr", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}
}
private: System::Void buttonAddTarFaill_Click(System::Object^ sender, System::EventArgs^ e) {
	try
	{
	if(textBox1->Text != "" && textBox2->Text != "") {
		bool keyAddTarName = true;
		bool keyAddTarCoefficient = true;

		string Name; MarshalString(textBox1->Text, Name);
		for (int i = 0; i < Name.length(); i++)
		{
			if ((Name[i] == ' ') || (Name[i] == '	')) {

				Name[i] = '_';
			}
		}
		for (int i = 0; i < TAR_vector.size(); i++)
		{
			if (TAR_vector[i].neam == Name) {
				keyAddTarName = false;

			}
		}
		string Coefficientstr; MarshalString(textBox2->Text, Coefficientstr);
		keyAddTarCoefficient = StringDouble(Coefficientstr);
		if (keyAddTarCoefficient && keyAddTarName) {

			double Coefficient = stod(Coefficientstr);

			TAR_vector.push_back({ Name,Coefficient });
			dataGridView1->Rows->Add
			(
				gcnew String(Name.c_str()),
				Coefficient
			);
			ofstream text3(FileNameTar);

			for (auto& element : TAR_vector) {
				text3 << element.neam << " " << element.coefficient << endl;

			}

			buttonAddCof->Visible = true;
			buttonAddPeople->Visible = true;
			buttonAddTar->Visible = true;
			backButton->Visible = true;

			buttonAddTarFaill->Visible = false;
			backButtonAdd->Visible = false;
			labelAddTar1->Visible = false;
			labelAddTar2->Visible = false;
			textBox2->Visible = false;
			textBox1->Visible = false;
			textBox2->Clear();
			textBox1->Clear();


		}
		if (!keyAddTarCoefficient) {
			textBox2->BackColor = Color::LightCoral;
			MessageBox::Show(L"Вибачте, ви ввели некоректний тариф. Перевірте, чи не міститься в ньому пробілів або чи не повторюються крапки  ", L"Erorr Double", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);


		}
		if (!keyAddTarName)
		{
			textBox1->BackColor = Color::LightCoral;
			MessageBox::Show(L"Вибачте, посада з таким іменем вже існує. Змініть назву або відредагуйте бажаниу посаду  ", L"Erorr Name", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

		}
		
	}
	else
	{
		MessageBox::Show(L"Вибачте, одне або кілька полів порожні   ", L"Erorr None", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

	}
	  }
	   catch (std::exception& e) {
		   // обробка стандартних виключень
		   MessageBox::Show(L"Вибачте, при вводі даних сталася помилка (можливо за велике значення числа)", L"Erorr", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	   }
	   catch (...) {
		   // обробка інших виключень
		   MessageBox::Show(L"Вибачте, при вводі даних сталася помилка (можливо за велике значення числа) ", L"Erorr", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	   }
}
private: System::Void buttonRaundNoumber_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox1->Clear();
	srand(static_cast<unsigned int>(time(0)));
	bool chekRanNouber;
	int ranNouber=-1;
	do
	{
		chekRanNouber = false;
		ranNouber = rand() % INT_MAX;
		for (int i = 0; i < job_vector.size(); i++) {
			if (ranNouber == job_vector[i].Personal_number)
			{
				chekRanNouber = true;
			}
		}
	} while (chekRanNouber);
	

	textBox1->Text = ranNouber.ToString();
		
	buttonRaundNoumber->Visible = false;
	textBox1->BackColor = Color::White;
}
private: System::Void buttonSort_Click(System::Object^ sender, System::EventArgs^ e)
{

	try
	{

	if (textBox1->Text != "" || textBox2->Text != "" || textBox3->Text != "" || textBox4->Text != "")
	{

		textBox4->BackColor = Color::WhiteSmoke;
		textBox3->BackColor = Color::WhiteSmoke;
		textBox2->BackColor = Color::WhiteSmoke;
		textBox1->BackColor = Color::WhiteSmoke;

		bool keySortHors = true;
		bool keySortWeg = true;

		bool keySortDeportamentDefault = false;
		bool keySortPositonDefault = false;
		bool keySortHorsDefault = false;
		bool keySortWegDefault = false;

		if (textBox1->Text == "")
		{
			keySortDeportamentDefault = true;
		}
		if (textBox2->Text == "")
		{
			keySortPositonDefault = true;
		}
		if (textBox3->Text == "")
		{
			keySortHorsDefault = true;
		}
		if (textBox4->Text == "")
		{
			keySortWegDefault = true;
		}


		string SortDepartment;
		if (!keySortDeportamentDefault)
		{
			MarshalString(textBox1->Text, SortDepartment);
			for (int i = 0; i < SortDepartment.length(); i++)
			{
				if ((SortDepartment[i] == ' ') || (SortDepartment[i] == '	')) {

					SortDepartment[i] = '_';
				}
			}
		}
		string SortPositon;
		if (!keySortPositonDefault)
		{
			MarshalString(textBox2->Text, SortPositon);
			for (int i = 0; i < SortPositon.length(); i++)
			{
				if ((SortPositon[i] == ' ') || (SortPositon[i] == '	')) {

					SortPositon[i] = '_';
				}
			}
		}
		double SortHours;
		if (!keySortHorsDefault)
		{
			string SortHoursstr; MarshalString(textBox3->Text, SortHoursstr);
			keySortHors = StringDouble(SortHoursstr);
			if (keySortHors)
			{
				SortHours = stod(SortHoursstr);
			}
		}
		else
		{
			if (keyMinMaxHour)
			{
				SortHours = bigHour + 1;
			}
			else
			{
				SortHours = -2;
			}
			textBox3->Clear();
		}

		double SortWeg;
		if (!keySortWegDefault)
		{

			string SortWegstr; MarshalString(textBox4->Text, SortWegstr);
			int chekCopyDouble = 0;
			keySortWeg = StringDouble(SortWegstr);
			if (keySortWeg)
			{
				SortWeg = stod(SortWegstr);
			}
		}
		else
		{


			if (keyMinMaxWeg)
			{
				SortWeg = BigWeg + 1;
			}
			else
			{
				SortWeg = -2;
			}
			
			textBox4->Clear();
		}
		int AllNoumber = 0;
		if (keySortHors && keySortWeg)
		{

			dataGridView1->Columns->Clear();
			dataGridView1->Columns->Add("", "Personal number");
			dataGridView1->Columns->Add("", "PIB");
			dataGridView1->Columns->Add("", "Department");
			dataGridView1->Columns->Add("", "Position");
			dataGridView1->Columns->Add("", "Hours worked");
			dataGridView1->Columns->Add("", "Wage");
			for (int i = 0; i < job_vector.size(); i++)
			{


				if (keySortDeportamentDefault && keySortPositonDefault)
				{



					if (
						CheckWithKey(SortHours, job_vector[i].Hours, keyMinMaxHour) &&
						CheckWithKey(SortWeg, job_vector[i].wage, keyMinMaxWeg)

						)
					{

						AllNoumber++;
						PrintDataGridView1(i, true);


					}



				}
				else if (keySortDeportamentDefault)
				{


					if (
						SortPositon == job_vector[i].Position &&
						CheckWithKey(SortHours, job_vector[i].Hours, keyMinMaxHour) &&
						CheckWithKey(SortWeg, job_vector[i].wage, keyMinMaxWeg)
						)
					{

						AllNoumber++;
						PrintDataGridView1(i, true);


					}



				}
				else if (keySortPositonDefault)
				{



					if (
						SortDepartment == job_vector[i].Department &&
						CheckWithKey(SortHours, job_vector[i].Hours, keyMinMaxHour) &&
						CheckWithKey(SortWeg, job_vector[i].wage, keyMinMaxWeg)
						)
					{

						AllNoumber++;
						PrintDataGridView1(i, true);


					}

				}
				else
				{



					if (
						SortDepartment == job_vector[i].Department &&
						SortPositon == job_vector[i].Position &&
						CheckWithKey(SortHours, job_vector[i].Hours, keyMinMaxHour) &&
						CheckWithKey(SortWeg, job_vector[i].wage, keyMinMaxWeg)
						)
					{
						AllNoumber++;
						PrintDataGridView1(i, true);


					}



				}
			}

			textBoxSortAllNoumber->Text = AllNoumber.ToString();// вивод кількості запесів;

			for each (DataGridViewColumn ^ column in dataGridView1->Columns)
			{
				column->SortMode = DataGridViewColumnSortMode::NotSortable;
			}
			//відключення можливості сортировки для уникнення помилок
		}
		else if (!keySortHors && !keySortWeg)
		{
			textBox3->BackColor = Color::LightCoral;
			textBox4->BackColor = Color::LightCoral;
			MessageBox::Show(L"Вибачте, від зарплати та годин не коректний. Перевірте, чи не має пробілів або чи не повторюються точки   ", L"Erorr double ", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

		}
		else if (!keySortWeg)
		{
			textBox4->BackColor = Color::LightCoral;
			MessageBox::Show(L"Вибачте, від зарплати некоректний (перевірте, чи не має пробілів або чи не повторюються точки)   ", L"Erorr double", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

		}
		else if (!keySortHors)
		{
			textBox3->BackColor = Color::LightCoral;
			MessageBox::Show(L"Вибачте, від годин не коректний. Перевірте, чи не має пробілів або чи не повторюються точки   ", L"Erorr double", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

		}
	}//t || textBoxSortPositon->Text != "" || textBoxSortHors->Text != "" || textBoxSortWag->Text != ""
	else
	{

		textBox4->BackColor = Color::LightCoral;
		textBox3->BackColor = Color::LightCoral;
		textBox2->BackColor = Color::LightCoral;
		textBox1->BackColor = Color::LightCoral;
		MessageBox::Show(L"Вибачте, всі поля порожні   ", L"Erorr None", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

	}
}
catch (std::exception& e) {
	// обробка стандартних виключень
	MessageBox::Show(L"Вибачте, при вводі даних сталася помилка (можливо за велике значення числа) ", L"Erorr", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
}
catch (...) {
	// обробка інших виключень
	MessageBox::Show(L"Вибачте, при вводі даних сталася помилка (можливо за велике значення числа) ", L"Erorr", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
}
	
}
private: System::Void buttonSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	OffMenu1();

	backButton->Visible = true;
	buttonSearchDo->Visible = true;
	labelSearch1->Visible = true;
	textBox1->Visible = true;


}
private: System::Void buttonSearchDo_Click(System::Object^ sender, System::EventArgs^ e) {
	try
	{


		if (textBox1->Text != "")
		{
			bool keySearcNomber = true;

			string Personal_number; MarshalString(textBox1->Text, Personal_number);
			keySearcNomber = StringInt(Personal_number);

			if (keySearcNomber)
			{
				int Personal_number = Convert::ToInt64(textBox1->Text);

				dataGridView1->Columns->Clear();
				dataGridView1->Columns->Add("", "Personal number");
				dataGridView1->Columns->Add("", "PIB");
				dataGridView1->Columns->Add("", "Department");
				dataGridView1->Columns->Add("", "Position");
				dataGridView1->Columns->Add("", "Hours worked");
				dataGridView1->Columns->Add("", "Wage");
				for (int i = 0; i < job_vector.size(); i++)
				{
					if (job_vector[i].Personal_number == Personal_number) {
						PrintDataGridView1(i, true);
					}
				}
				for each (DataGridViewColumn ^ column in dataGridView1->Columns)
				{
					column->SortMode = DataGridViewColumnSortMode::NotSortable;
				}
			}
			else
			{
				textBox1->BackColor = Color::LightCoral;
				MessageBox::Show(L"Вибачте, при вводі даних сталася помилка (можливо за велике значення числа) ", L"Eror int", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

			}


		}
		else
		{
			textBox1->BackColor = Color::LightCoral;
			MessageBox::Show(L"Вибачте, поле пусте ", L"Erorr None", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

		}
	}
	catch (std::exception& e) {
		// обробка стандартних виключень
		MessageBox::Show(L"Вибачте, при вводі даних сталася помилка (можливо за велике значення числа) ", L"Erorr", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}
	catch (...) {
		// обробка інших виключень
		MessageBox::Show(L"Вибачте, при вводі даних сталася помилка (можливо за велике значення числа) ", L"Erorr", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}
}
private: System::Void buttonEditing_Click(System::Object^ sender, System::EventArgs^ e) {
	OffMenu1();
	buttonEditingCof->Visible = true;
	buttonEditingPepl->Visible = true;
	buttonEditingTar->Visible = true;
	backButton->Visible = true;
	
}

private: System::Void checkBoxMinMaxWeg_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBoxMinMaxWeg->Checked)
	{
		labelSort4->Visible = false;
		keyMinMaxWeg = false;
		labelSort4on->Visible = true;
	}
	else
	{
		labelSort4->Visible = true;
		keyMinMaxWeg = true;
		labelSort4on->Visible = false;
	}
	
}
private: System::Void checkBoxMinMaxHors_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBoxMinMaxHors->Checked)
	{
		labelSort3->Visible = false;
		keyMinMaxHour = false;
		labelSort3on->Visible = true;
	}
	else
	{
		labelSort3on->Visible = false;
		keyMinMaxHour = true;
		labelSort3->Visible = true;
	}

}
private: System::Void buttonDeleteCof_Click(System::Object^ sender, System::EventArgs^ e) {
	buttonDeleteCofFaill->Visible = true;
	textBox1->Visible = true;
	labelDeleteCof->Visible = true;
	backButton->Visible = false;

	BackbuttonDelete->Visible = true;
	buttonDeletePeople->Visible = false;
	buttonDeleteCof->Visible = false;
	buttonDeleteTar->Visible = false;


	dataGridView1->Columns->Clear();
	dataGridView1->Columns->Add("", "Name");
	dataGridView1->Columns->Add("", "Coefficient");
	for (int i = 0; i < COF_vector.size(); i++)
	{
		dataGridView1->Rows->Add(gcnew String(COF_vector[i].nema.c_str()),
			COF_vector[i].coefficient);
	}
	for each (DataGridViewColumn ^ column in dataGridView1->Columns)
	{
		column->SortMode = DataGridViewColumnSortMode::NotSortable;
	}

}
private: System::Void buttonDeletePeopleFaill_Click(System::Object^ sender, System::EventArgs^ e) {

	try
	{
		if (textBox1->Text != "")
		{

			bool keyDeletePeople=true;
			bool keyDeletePeopleExist = false;
			string Personal_number; MarshalString(textBox1->Text, Personal_number);
			keyDeletePeople = StringInt(Personal_number);
			
			
			if (keyDeletePeople)
			{
				
					int Personal_number = Convert::ToInt64(textBox1->Text);
					for (int i = 0; i < job_vector.size(); i++)
					{
						if (job_vector[i].Personal_number == Personal_number)
						{
							keyDeletePeopleExist = true;
						}
					}
					if (keyDeletePeopleExist)
					{
					
					remove(FileNamePeple.c_str());

					ofstream text2(FileNamePeple);


					for (int i = 0; i < job_vector.size(); i++)
					{
						if (job_vector[i].Personal_number != Personal_number)
						{
							text2 << job_vector[i].Personal_number << ' ' << job_vector[i].PIB << ' ' << job_vector[i].Department << ' '
								<< job_vector[i].Position << ' ' << job_vector[i].Hours << endl;
						}
						else
						{
							for (int i = job_vector.size() - 1; i >= 0; i--) {
								if (job_vector[i].Personal_number == Personal_number) {
									job_vector.erase(job_vector.begin() + i);
								}
							}
						}
					}
					dataGridView1->Columns->Clear();
					dataGridView1->Columns->Add("", "Personal number");
					dataGridView1->Columns->Add("", "PIB");
					dataGridView1->Columns->Add("", "Department");
					dataGridView1->Columns->Add("", "Position");
					dataGridView1->Columns->Add("", "Hours worked");
					for (int i = 0; i < job_vector.size(); i++)
					{
						PrintDataGridView1(i, false);

					}
				}
				else
				{
						textBox1->BackColor = Color::LightCoral;
					MessageBox::Show(L"Вибачте, такого номера не існує ", L"Eror None", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
				}

			}
			else
			{
				textBox1->BackColor = Color::LightCoral;
				MessageBox::Show(L"Вибачте, ви ввели некоректний номер (переконайтеся, що він не містить пробілів, тире або крапок) ", L"Eror int", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			}
			
		}
		else
		{
			textBox1->BackColor = Color::LightCoral;
			MessageBox::Show(L"Вибачте, поле пусте  ", L"Erorr None", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

		}

	}
	catch (std::exception& e) {
		// обробка стандартних виключень

		MessageBox::Show(L"Вибачте, при вводі даних сталася помилка (можливо за велике значення числа) ", L"Erorr", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}
	catch (...) {
		// обробка інших виключень
		MessageBox::Show(L"Вибачте, при вводі даних сталася помилка (можливо за велике значення числа)", L"Erorr", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}
}
private: System::Void buttonDeletePeople_Click(System::Object^ sender, System::EventArgs^ e) {
	buttonDeletePeopleFaill->Visible = true;
	textBox1->Visible = true;
	labelDeletePepl->Visible = true;
	backButton->Visible = false;

	BackbuttonDelete->Visible = true;
	buttonDeletePeople->Visible = false;
	buttonDeleteCof->Visible = false;
	buttonDeleteTar->Visible = false;
	dataGridView1->Columns->Clear();
	dataGridView1->Columns->Add("", "Personal number");
	dataGridView1->Columns->Add("", "PIB");
	dataGridView1->Columns->Add("", "Department");
	dataGridView1->Columns->Add("", "Position");
	dataGridView1->Columns->Add("", "Hours worked");
	for (int i = 0; i < job_vector.size(); i++) {
		PrintDataGridView1(i, false);

	}
	for each (DataGridViewColumn ^ column in dataGridView1->Columns)
	{
		column->SortMode = DataGridViewColumnSortMode::NotSortable;
	}

}
private: System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e) {
	OffMenu1();

	backButton->Visible = true;
	buttonDeletePeople->Visible = true;
	buttonDeleteCof->Visible = true;
	buttonDeleteTar->Visible = true;
}
private: System::Void buttonDeleteTar_Click(System::Object^ sender, System::EventArgs^ e) {
	buttonDeletePeople->Visible = false;
	buttonDeleteCof->Visible = false;
	buttonDeleteTar->Visible = false;
	backButton->Visible = false;

	BackbuttonDelete->Visible = true;
	buttonDeleteTarFaill->Visible = true;
	textBox1->Visible = true;
	labelDeleteTar->Visible = true;

	dataGridView1->Columns->Clear();
	dataGridView1->Columns->Add("", "Name");
	dataGridView1->Columns->Add("", "Tariff");
	for (int i = 0; i < TAR_vector.size(); i++)
	{
		dataGridView1->Rows->Add(gcnew String(TAR_vector[i].neam.c_str()),
			TAR_vector[i].coefficient);
	}
	for each (DataGridViewColumn ^ column in dataGridView1->Columns)
	{
		column->SortMode = DataGridViewColumnSortMode::NotSortable;
	}

}
private: System::Void buttonDeleteCofFaill_Click(System::Object^ sender, System::EventArgs^ e) {

	{
		if (textBox1->Text != "")
		{
			bool keyDepartmentDelete = false;
			string Department; MarshalString(textBox1->Text, Department);
			for (int i = 0; i < Department.length(); i++)
			{
				if ((Department[i] == ' ') || (Department[i] == '	')) {

					Department[i] = '_';
				}
			}
			for (int i = 0 ; i< COF_vector.size();i++)
			{
				if (Department==COF_vector[i].nema)
				{
					keyDepartmentDelete = true;
				}
			}
			if (keyDepartmentDelete)
			{
				remove(FileNameCof.c_str());


				ofstream text2(FileNameCof);
				dataGridView1->Columns->Clear();
				dataGridView1->Columns->Add("", "Name");
				dataGridView1->Columns->Add("", "Coefficient");
				for (int i = 0; i < COF_vector.size(); i++)
				{
					if (COF_vector[i].nema != Department)
					{
						text2 << COF_vector[i].nema << " " << COF_vector[i].coefficient << endl;
					}
					else
					{
						for (int i = COF_vector.size() - 1; i >= 0; i--) {
							if (COF_vector[i].nema == Department) {
								COF_vector.erase(COF_vector.begin() + i);
							}
						}
					}
				}
				for (int i = 0; i < COF_vector.size(); i++)
				{
					dataGridView1->Rows->Add(gcnew String(COF_vector[i].nema.c_str()),
						COF_vector[i].coefficient);
				}
				for each (DataGridViewColumn ^ column in dataGridView1->Columns)
				{
					column->SortMode = DataGridViewColumnSortMode::NotSortable;
				}

			}
			else
			{
				textBox1->BackColor = Color::LightCoral;
				MessageBox::Show(L"Вибачте, такого відділу не існує  ", L"Eror None", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			}

		}
		else
		{
			textBox1->BackColor = Color::LightCoral;
			MessageBox::Show(L"Вибачте, поле пусте  ", L"Erorr None", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

		}


	}
}
private: System::Void buttonDeleteTarFaill_Click(System::Object^ sender, System::EventArgs^ e) {
	
	if (textBox1->Text != "")
	{
		bool keyPositonDelete = false;
		string Positon; MarshalString(textBox1->Text, Positon);
		for (int i = 0; i < Positon.length(); i++)
		{
			if ((Positon[i] == ' ') || (Positon[i] == '	')) {

				Positon[i] = '_';
			}
		}
		for (int i = 0; i < TAR_vector.size(); i++)
		{
			if (Positon == TAR_vector[i].neam)
			{
				keyPositonDelete = true;
			}
		}
		if (keyPositonDelete)
		{
			remove(FileNameTar.c_str());

			dataGridView1->Columns->Clear();
			dataGridView1->Columns->Add("", "Tariff");
			dataGridView1->Columns->Add("", "Coefficient");
			ofstream text2(FileNameTar);
			for (int i = 0; i < TAR_vector.size(); i++)
			{
				if (TAR_vector[i].neam != Positon)
				{
					text2 << TAR_vector[i].neam << " " << TAR_vector[i].coefficient << endl;
				}
				else
				{
					for (int i = TAR_vector.size() - 1; i >= 0; i--) {
						if (TAR_vector[i].neam == Positon) {
							TAR_vector.erase(TAR_vector.begin() + i);
						}
					}
				}
			}
			for (int i = 0; i < TAR_vector.size(); i++)
			{
				dataGridView1->Rows->Add(gcnew String(TAR_vector[i].neam.c_str()),
					TAR_vector[i].coefficient);
			}
			for each (DataGridViewColumn ^ column in dataGridView1->Columns)
			{
				column->SortMode = DataGridViewColumnSortMode::NotSortable;
			}
		}
		else
		{
			textBox1->BackColor = Color::LightCoral;
			MessageBox::Show(L"Вибачте, такого відділу не існує ", L"Eror None", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		}

	}
	else
	{
		textBox1->BackColor = Color::LightCoral;
		MessageBox::Show(L"Вибачте, поле пусте ", L"Erorr None", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

	}
	
}
private: System::Void BackbuttonDelete_Click(System::Object^ sender, System::EventArgs^ e) {

	textBox1->BackColor = Color::WhiteSmoke;


	buttonDeletePeople->Visible = true;
	buttonDeleteCof->Visible = true;
	buttonDeleteTar->Visible = true;
	backButton->Visible = true;


	textBox1->Visible = false;
	BackbuttonDelete->Visible = false;
	buttonDeleteTarFaill->Visible = false;
	buttonDeleteCofFaill->Visible = false;

	labelDeleteTar->Visible = false;
	buttonDeleteCofFaill->Visible = false;
	
	labelDeleteCof->Visible = false;
	buttonDeletePeopleFaill->Visible = false;
	
	labelDeletePepl->Visible = false;
	textBox1->Clear();
}
private: System::Void TEST_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	textBox1->BackColor = Color::WhiteSmoke;
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	textBox4->BackColor = Color::WhiteSmoke;
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	textBox2->BackColor = Color::WhiteSmoke;
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	textBox3->BackColor = Color::WhiteSmoke;
}
private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	textBox5->BackColor = Color::WhiteSmoke;
}
int Personal_number1;
private: System::Void buttonEditingPeplFile_Click(System::Object^ sender, System::EventArgs^ e) {
	
	try
	{


		if (textBox1->Text != "")
		{
			bool keySearcNomber = true;
			int index=-1;
			string Personal_number; MarshalString(textBox1->Text, Personal_number);
			keySearcNomber = StringInt(Personal_number);
			if (keySearcNomber)
			{
				Personal_number1 = Convert::ToInt64(textBox1->Text);
				for (int i = 0; i < job_vector.size();i++)
				{
					if (job_vector[i].Personal_number == Personal_number1) {
						
						index = i;

					}
				}
			}

			if (keySearcNomber&& index != -1)
			{

				Personal_number1 = Convert::ToInt64(textBox1->Text);
				string PIB_V;
				string Deportament_V;
				string Position_V;
				int number_VI;
				double Horse_VD;
			
				dataGridView1->Columns->Clear();
				dataGridView1->Columns->Add("", "Personal number");
				dataGridView1->Columns->Add("", "PIB");
				dataGridView1->Columns->Add("", "Department");
				dataGridView1->Columns->Add("", "Position");
				dataGridView1->Columns->Add("", "Hours worked");
				
						PrintDataGridView1(index, false);
						number_VI = job_vector[index].Personal_number;
						PIB_V = job_vector[index].PIB;
						Deportament_V=job_vector[index].Department;
						Position_V=job_vector[index].Position;
						Horse_VD= job_vector[index].Hours;
						

					
				for each (DataGridViewColumn ^ column in dataGridView1->Columns)
				{
					column->SortMode = DataGridViewColumnSortMode::NotSortable;
				}
				
				textBox1->Clear();
				textBox2->Visible = true;
				textBox3->Visible = true;
				textBox4->Visible = true;
				textBox5->Visible = true;
				buttonEditingPeplFileDo->Visible = true;
				buttonEditingPeplFile->Visible = false;
				buttonEditingPeplFileR->Visible = true;
				labelEdittPepol1->Visible = true;
				labelEdittPepol2->Visible = true;
				labelEdittPepol3->Visible = true;
				labelEdittPepol4->Visible = true;
				labelEdittPepol5->Visible = true;

				string number_V = to_string(number_VI);
				string Horse_V = to_string(Horse_VD);
				System::String^  PIB = msclr::interop::marshal_as<System::String^>(PIB_V);//функція пертворення зі звичайного стрінга в системний
				System::String^ Department = msclr::interop::marshal_as<System::String^>(Deportament_V);//функція пертворення зі звичайного стрінга в системний
				System::String^ Hors = msclr::interop::marshal_as<System::String^>(Horse_V);//функція пертворення зі звичайного стрінга в системний
				System::String^ Position = msclr::interop::marshal_as<System::String^>(Position_V);//функція пертворення зі звичайного стрінга в системний
				System::String^ number = msclr::interop::marshal_as<System::String^>(number_V);//функція пертворення зі звичайного стрінга в системний

				textBox1->Text = number;
				textBox2->Text = PIB;
				textBox3->Text = Department;
				textBox4->Text = Position;
				textBox5->Text = Hors;

				
				


				
			}
			else if(!keySearcNomber)
			{
				textBox1->BackColor = Color::LightCoral;
				MessageBox::Show(L"Вибачте, ви ввели некоректний номер (переконайтеся, що він не містить пробілів, тире або крапок)  ", L"Eror int", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

			}
			else if(index == -1)
			{
				textBox1->BackColor = Color::LightCoral;
				MessageBox::Show(L"Вибачте, працівника з таким номером не існує ", L"Eror int", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

			}



		}
		else
		{
			textBox1->BackColor = Color::LightCoral;
			MessageBox::Show(L"Вибачте, поле пусте ", L"Erorr None", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

		}
	}
	catch (std::exception& e) {
		// обробка стандартних виключень
		MessageBox::Show(L"Вибачте, при вводі даних сталася помилка (можливо за велике значення числа) ", L"Erorr", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}
	catch (...) {
		// обробка інших виключень
		MessageBox::Show(L"Вибачте, при вводі даних сталася помилка (можливо за велике значення числа) ", L"Erorr", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}
	
	
}
private: System::Void buttonEditingPeplFileDo_Click(System::Object^ sender, System::EventArgs^ e) {
	try
	{

		buttonAddTar->Visible = false;
		buttonAddCof->Visible = false;
	if (textBox3->Text != "" && textBox4->Text != "" && textBox2->Text != "" && textBox1->Text != "" && textBox5->Text != "") {
			bool keyAddPepleDep = false;
			bool keyAddPeplePos = false;
			bool keyAddPepleNum1 = true;
			bool keyAddPepleNum2 = true;
			bool keyAddPepleHou1 = true;
			bool keyAddPepleHou2 = true;
			//ключі від помилок

			string Department; MarshalString(textBox3->Text, Department);
			for (int i = 0; i < Department.length(); i++)
			{
				if ((Department[i] == ' ') || (Department[i] == '	')) {

					Department[i] = '_';
				}
			}
			//заміна пробіли на інші знаки

			for (int i = 0; i < COF_vector.size(); i++)
			{
				if (COF_vector[i].nema == Department)
				{
					keyAddPepleDep = true;
				}
			}
			//провірка що такий підрозділ існує
			string Position; MarshalString(textBox4->Text, Position);
			for (int i = 0; i < Position.length(); i++)
			{
				if ((Position[i] == ' ') || (Position[i] == '	')) {

					Position[i] = '_';
				}
			}
			//заміна пробіли на інші знаки

			for (int i = 0; i < TAR_vector.size(); i++)
			{
				if (TAR_vector[i].neam == Position)
				{
					keyAddPeplePos = true;
				}
			}
			//провірка що така посада існує
			string PIB; MarshalString(textBox2->Text, PIB);
			for (int i = 0; i < PIB.length(); i++)
			{
				if ((PIB[i] == ' ') || (PIB[i] == '	')) {

					PIB[i] = '_';
				}
			}//заміна пробіли на інші знаки




			string Personal_number; MarshalString(textBox1->Text, Personal_number);

			keyAddPepleNum1 = StringInt(Personal_number);
			if (keyAddPepleNum1) {
				string Personal_numberstr; MarshalString(textBox1->Text, Personal_numberstr);
				int Personal_number = stoi(Personal_numberstr);//Convert::ToInt64(textBoxAddPepleNoumber->Text);
				for (int i = 0; i < job_vector.size(); i++)
				{
					if (job_vector[i].Personal_number == Personal_number && job_vector[i].Personal_number != Personal_number1)//провірка що персональний номер унікальний
					{
						keyAddPepleNum2 = false;
					}
				}
			}

			string Hoursstr; MarshalString(textBox5->Text, Hoursstr);
			keyAddPepleHou1 = StringDouble(Hoursstr);
			if (keyAddPepleHou1)
			{
				double Hours = stod(Hoursstr);

				if (Hours > 192) {
					keyAddPepleHou2 = false;
				}
			}

			if (keyAddPepleDep && keyAddPepleHou1 && keyAddPepleHou2 && keyAddPepleNum2 && keyAddPepleNum1 && keyAddPeplePos)
			{
				int Personal_number = Convert::ToInt64(textBox1->Text);
				double Hours = stod(Hoursstr);
				remove(FileNamePeple.c_str());
				ofstream text2(FileNamePeple);
				for (int i = 0; i < job_vector.size(); i++)
				{
					if (Personal_number1 == job_vector[i].Personal_number)
					{
						job_vector[i].Personal_number = Personal_number;
						job_vector[i].Department = Department;
						job_vector[i].Hours = Hours;
						job_vector[i].PIB = PIB;
						job_vector[i].Position = Position;
					}

				}
				for (int i = 0; i < job_vector.size(); i++) 
				{
					text2 << job_vector[i].Personal_number << ' ' << job_vector[i].PIB << ' ' <<
						job_vector[i].Department << ' ' << job_vector[i].Position << ' ' << job_vector[i].Hours << endl;


				}
				dataGridView1->Columns->Clear();
				dataGridView1->Columns->Add("", "Personal number");
				dataGridView1->Columns->Add("", "PIB");
				dataGridView1->Columns->Add("", "Department");
				dataGridView1->Columns->Add("", "Position");
				dataGridView1->Columns->Add("", "Hours worked");
				for (int i = 0; i < job_vector.size(); i++)
				{
					if (job_vector[i].Personal_number == Personal_number1) { 
						PrintDataGridView1(i, false); 

					}
				}
				for each (DataGridViewColumn ^ column in dataGridView1->Columns)
				{
					column->SortMode = DataGridViewColumnSortMode::NotSortable;
				}
				BackbuttonEdiit_Click(sender,e);



				


			}
			if (!keyAddPepleDep && !keyAddPeplePos)
			{

				MessageBox::Show(L"Вибачте, ви ввели некоректний відділ та посаду. Будь ласка, додайте правильний відділ та посаду або змініть їх на існуючі.  ", L"Erorr not deport and positon", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
				textBox4->BackColor = Color::LightCoral;
				textBox3->BackColor = Color::LightCoral;
				buttonAddTar->Visible = true;
				buttonAddCof->Visible = true;


			}

			else if (!keyAddPepleDep)
			{

				textBox3->BackColor = Color::LightCoral;
				MessageBox::Show(L"Вибачте, ви ввели некоректний відділ. Будь ласка, додайте правильний відділ або змініть його. ", L"Erorr not deport", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
				buttonAddCof->Visible = true;
			}
			else if (!keyAddPeplePos) {

				textBox4->BackColor = Color::LightCoral;
				MessageBox::Show(L"Вибачте, ви ввели некоректну посаду. Будь ласка, додайте правильну посаду або змініть її  ", L"Eror not positon", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
				buttonAddTar->Visible = true;
			}

			if (!keyAddPepleNum1)
			{
				textBox1->BackColor = Color::LightCoral;
				MessageBox::Show(L"Вибачте, ви ввели некоректний номер. Будь ласка, перевірте, що у номері відсутні пробіли, риски або точки. ", L"Eror int", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

			}
			if (!keyAddPepleNum2)
			{
				textBox1->BackColor = Color::LightCoral;
				buttonRaundNoumber->Visible = true;
				MessageBox::Show(L"Вибачте, ви ввели вже існуючий персональний номер. Змініть його або згенеруйте новий, який ще не зайнятий ", L"Erorr personal noumber copy", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

			}
			if (!keyAddPepleHou1)
			{
				textBox5->BackColor = Color::LightCoral;
				MessageBox::Show(L"Вибачте, ви ввели некоректне число. Перевірте, чи відсутні пробіли або подвійні точки.  ", L"Erorr Double", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

			}
			if (!keyAddPepleHou2)
			{
				textBox5->BackColor = Color::LightCoral;
				MessageBox::Show(L"Трудовим кодексом України заборонено працювати більше ніж 192 години на місяць  ", L"Erorr exaggeration of norms", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

			}
		}
		else
		{
			MessageBox::Show(L"Вибачте, одне або декілька полів порожні  ", L"Erorr None", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

		}

	
	}
	catch (std::exception& e) {
		// обробка стандартних виключень
		MessageBox::Show(L"Вибачте, при вводі даних сталася помилка (можливо за велике значення числа) ", L"Erorr", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}
	catch (...) {
		// обробка інших виключень
		MessageBox::Show(L"Вибачте, при вводі даних сталася помилка (можливо за велике значення числа) ", L"Erorr", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}

}
private: System::Void buttonEditingPepl_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox1->Visible = true;
	buttonEditingPeplFile->Visible = true;
	backButton->Visible = false;
	buttonEditingPepl->Visible = false;
	buttonEditingCof->Visible = false;
	buttonEditingTar->Visible = false;


	BackbuttonEdiit->Visible = true;

	labelEdittPepol1->Visible = true;
	dataGridView1->Columns->Clear();
	dataGridView1->Columns->Add("", "Personal number");
	dataGridView1->Columns->Add("", "PIB");
	dataGridView1->Columns->Add("", "Department");
	dataGridView1->Columns->Add("", "Position");
	dataGridView1->Columns->Add("", "Hours worked");
	for (int i = 0; i < job_vector.size(); i++)
	{
		PrintDataGridView1(i, false);

	}
}
private: System::Void buttonEditingPeplFileR_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox1->Clear();

	labelEdittPepol2->Visible = false;
	labelEdittPepol3->Visible = false;
	labelEdittPepol4->Visible = false;
	labelEdittPepol5->Visible = false;
	textBox2->Visible = false;
	textBox3->Visible = false;
	textBox4->Visible = false;
	textBox5->Visible = false;
	buttonEditingPeplFileDo->Visible = false;
	buttonEditingPeplFile->Visible = true;
	buttonEditingPeplFileR->Visible = false;
	dataGridView1->Columns->Clear();
	dataGridView1->Columns->Add("", "Personal number");
	dataGridView1->Columns->Add("", "PIB");
	dataGridView1->Columns->Add("", "Department");
	dataGridView1->Columns->Add("", "Position");
	dataGridView1->Columns->Add("", "Hours worked");
	for (int i = 0; i < job_vector.size(); i++)
	{
		PrintDataGridView1(i, false);

	}
	for each (DataGridViewColumn ^ column in dataGridView1->Columns)
	{
		column->SortMode = DataGridViewColumnSortMode::NotSortable;
	}
}
private: System::Void buttonEditingTar_Click(System::Object^ sender, System::EventArgs^ e) {
	buttonEditingTarFill->Visible = true;
	labelEditingTar1->Visible = true;
	textBox1->Visible = true;
	backButton->Visible = false;
	buttonEditingPepl->Visible = false;
	buttonEditingCof->Visible = false;
	buttonEditingTar->Visible = false;
	BackbuttonEdiit->Visible = true;


	dataGridView1->Columns->Clear();
	dataGridView1->Columns->Add("", "Name");
	dataGridView1->Columns->Add("", "Coefficient");
	for (int i = 0; i < TAR_vector.size(); i++)
	{
		dataGridView1->Rows->Add(gcnew String(TAR_vector[i].neam.c_str()),
			TAR_vector[i].coefficient);
	}
	for each (DataGridViewColumn ^ column in dataGridView1->Columns)
	{
		column->SortMode = DataGridViewColumnSortMode::NotSortable;
	}
}
private: System::Void buttonEditingCof_Click(System::Object^ sender, System::EventArgs^ e) {
	buttonEditingPepl->Visible = false;
	buttonEditingCof->Visible = false;
	buttonEditingTar->Visible = false;
	backButton->Visible = false;
	textBox1->Visible = true;
	labelEditingCof1->Visible = true;
	buttonEditingCofFill->Visible = true;
	BackbuttonEdiit->Visible = true;


	dataGridView1->Columns->Clear();
	dataGridView1->Columns->Add("", "Name");
	dataGridView1->Columns->Add("", "Coefficient");
	for (int i = 0; i < COF_vector.size(); i++)
	{
		dataGridView1->Rows->Add(gcnew String(COF_vector[i].nema.c_str()),
			COF_vector[i].coefficient);
	}
	for each (DataGridViewColumn ^ column in dataGridView1->Columns)
	{
		column->SortMode = DataGridViewColumnSortMode::NotSortable;
	}
}


private: System::Void buttonEditingCofFill_Click(System::Object^ sender, System::EventArgs^ e) {

	if (textBox1->Text!="")
	{
		bool keyEditingCof = false;
		string Deportament_v; MarshalString(textBox1->Text, Deportament_v);
		double COF_vD;
		string COF_v;
		int indx=-1;
		for (int i = 0; i < COF_vector.size(); i++) {
			if (COF_vector[i].nema == Deportament_v) 
			{
				
				COF_vD = COF_vector[i].coefficient;
				indx = i;
				Deportament1=Deportament_v;

			}
		}
		if (indx != -1)
		{
			buttonEditingCofFill->Visible = false;
			buttonEditingCoflFileDo->Visible = true;
			buttonEditingCofFileDoR->Visible = true;
			string COF_v = to_string(COF_vD);
			System::String^ Deportament = msclr::interop::marshal_as<System::String^>(Deportament_v);
			System::String^ COF = msclr::interop::marshal_as<System::String^>(COF_v);

			textBox1->Text = Deportament;
			textBox2->Text = COF;

			textBox1->Visible = true;
			textBox2->Visible = true;

			labelEditingCof1->Visible = true;
			labelEditingCof2->Visible = true;

			dataGridView1->Columns->Clear();
			dataGridView1->Columns->Add("", "Name");
			dataGridView1->Columns->Add("", "Coefficient");
			dataGridView1->Rows->Add(
				gcnew String(COF_vector[indx].nema.c_str()),
				COF_vector[indx].coefficient
			);
			for each (DataGridViewColumn ^ column in dataGridView1->Columns)
			{
				column->SortMode = DataGridViewColumnSortMode::NotSortable;
			}

		}
		else 
		{
			textBox3->BackColor = Color::LightCoral;
			MessageBox::Show(L"Вибачте, але ви ввели неіснуючий відділ. Будь ласка, перевірте правильність введення відділу і спробуйте знову. ", L"Erorr not deport", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			buttonAddCof->Visible = true;

		}
	}
	else
	{
		textBox1->BackColor = Color::LightCoral;
		MessageBox::Show(L"Вибачте, поле пусте ", L"Erorr None", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

	}
}
private: System::Void buttonEditingCoflFileDo_Click(System::Object^ sender, System::EventArgs^ e) {
	try
	{
		if (textBox1->Text != "" && textBox2->Text != "") {
			bool keyAddCofName = true;
			bool keyAddCofCoefficient = true;

			string Name; MarshalString(textBox1->Text, Name);
			for (int i = 0; i < Name.length(); i++)
			{
				if ((Name[i] == ' ') || (Name[i] == '	')) {

					Name[i] = '_';
				}
			}
			for (int i = 0; i < COF_vector.size(); i++)
			{
				if (COF_vector[i].nema == Name && COF_vector[i].nema != Deportament1) {
					keyAddCofName = false;

				}
			}
			string Coefficientstr; MarshalString(textBox2->Text, Coefficientstr);
			keyAddCofCoefficient = StringDouble(Coefficientstr);
			if (keyAddCofCoefficient && keyAddCofName) 
			{
				double Coefficient = stod(Coefficientstr);
				remove(FileNameCof.c_str());
				ofstream text2(FileNameCof);

				for (int i = 0; i < COF_vector.size(); i++)
				{
					if (COF_vector[i].nema == Deportament1)
					{
						COF_vector[i].nema = Name;
						COF_vector[i].coefficient = Coefficient;
					}
				}
				for (int i = 0; i < COF_vector.size(); i++)
				{
					text2 << COF_vector[i].nema << " " << COF_vector[i].coefficient << endl;
				}

				dataGridView1->Columns->Clear();
				dataGridView1->Columns->Add("", "Name");
				dataGridView1->Columns->Add("", "Coefficient");
				for (int i = 0; i < COF_vector.size(); i++)
				{
					dataGridView1->Rows->Add(gcnew String(COF_vector[i].nema.c_str()),
						COF_vector[i].coefficient);
				}
				for each (DataGridViewColumn ^ column in dataGridView1->Columns)
				{
					column->SortMode = DataGridViewColumnSortMode::NotSortable;
				}

				BackbuttonEdiit_Click(sender, e);

			}
			if (!keyAddCofCoefficient) {
				textBox2->BackColor = Color::LightCoral;
				MessageBox::Show(L"Вибачте, ви ввели некоректний коефіцієнт. Перевірте, чи відсутні пробіли або подвійні крапки ", L"Erorr Double", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);


			}
			if (!keyAddCofName)
			{
				textBox1->BackColor = Color::LightCoral;
				MessageBox::Show(L"Вибачте, відділ з таким іменем вже існує.    ", L"Erorr Name", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

			}
		}
		else
		{
			MessageBox::Show(L"Вибачте, одне або декілька полів порожні   ", L"Erorr None", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

		}
	}
	catch (std::exception& e) {
		// обробка стандартних виключень
		MessageBox::Show(L"Вибачте, при вводі даних сталася помилка (можливо за велике значення числа) ", L"Erorr", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}
	catch (...) {
		// обробка інших виключень
		MessageBox::Show(L"Вибачте, при вводі даних сталася помилка (можливо за велике значення числа)  ", L"Erorr", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}

}
private: System::Void buttonEditingPeplFileDoR_Click(System::Object^ sender, System::EventArgs^ e) {
	buttonEditingCofFill->Visible = true;
	textBox1->Clear();
	textBox2->Clear();
	textBox2->Visible = false;
	labelEditingCof2->Visible = false;
	buttonEditingCoflFileDo->Visible = false;
	buttonEditingCofFileDoR->Visible = false;
	dataGridView1->Columns->Clear();
	dataGridView1->Columns->Add("", "Name");
	dataGridView1->Columns->Add("", "Coefficient");
	for (int i = 0; i < COF_vector.size(); i++)
	{
		dataGridView1->Rows->Add(gcnew String(COF_vector[i].nema.c_str()),
			COF_vector[i].coefficient);
	}
	for each (DataGridViewColumn ^ column in dataGridView1->Columns)
	{
		column->SortMode = DataGridViewColumnSortMode::NotSortable;
	}
}
private: System::Void BackbuttonEdiit_Click(System::Object^ sender, System::EventArgs^ e) {
	backButton->Visible = true;
	buttonEditingTar->Visible = true;
	buttonEditingPepl->Visible = true;
	buttonEditingCof->Visible = true;
	BackbuttonEdiit->Visible = false;

	buttonEditingTarFill->Visible = false;
	labelEditingTar1->Visible = false;
	labelEditingTar2->Visible = false;
	textBox1->Visible = false;
	buttonEditingTarFillDo->Visible = false;
	buttonEditingTarFillDoR->Visible = false;

	
	BackbuttonEdiit->Visible = false;


	textBox1->Visible = false;
	textBox2->Visible = false;
	textBox3->Visible = false;
	textBox4->Visible = false;
	textBox5->Visible = false;

	textBox1->Clear();
	textBox2->Clear();
	textBox3->Clear();
	textBox4->Clear();
	textBox5->Clear();

	buttonEditingCoflFileDo->Visible = false;
	buttonEditingCofFileDoR->Visible = false;
	buttonEditingCofFill->Visible = false;
	buttonEditingPeplFileDo->Visible = false;
	buttonEditingPeplFile->Visible = false;
	buttonEditingPeplFileR->Visible = false;

	labelEditingCof1->Visible = false;
	labelEditingCof2->Visible = false;
	labelEdittPepol1->Visible = false;
	labelEdittPepol2->Visible = false;
	labelEdittPepol3->Visible = false;
	labelEdittPepol4->Visible = false;
	labelEdittPepol5->Visible = false;

}
private: System::Void buttonEditingTarFill_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox1->Text != "")
	{
		bool keyEditingTar = false;
		string Posit_v; MarshalString(textBox1->Text, Posit_v);
		double TAR_vD;
		string TAR_v;
		int indx = -1;
		for (int i = 0; i < TAR_vector.size(); i++) {
			if (TAR_vector[i].neam == Posit_v)
			{

				TAR_vD = TAR_vector[i].coefficient;
				indx = i;
				Posit1 = Posit_v;

			}
		}
		if (indx != -1)
		{
			buttonEditingTarFill->Visible = false;
			buttonEditingTarFillDo->Visible = true;
			buttonEditingTarFillDoR->Visible = true;
			string TAR_v = to_string(TAR_vD);
			System::String^ Posit = msclr::interop::marshal_as<System::String^>(Posit_v);
			System::String^ TAR = msclr::interop::marshal_as<System::String^>(TAR_v);

			textBox1->Text = Posit;
			textBox2->Text = TAR;

			textBox1->Visible = true;
			textBox2->Visible = true;

			labelEditingTar1->Visible = true;
			labelEditingTar2->Visible = true;

			dataGridView1->Columns->Clear();
			dataGridView1->Columns->Add("", "Name");
			dataGridView1->Columns->Add("", "Coefficient");
			dataGridView1->Rows->Add(
				gcnew String(TAR_vector[indx].neam.c_str()),
				TAR_vector[indx].coefficient
			);
			for each (DataGridViewColumn ^ column in dataGridView1->Columns)
			{
				column->SortMode = DataGridViewColumnSortMode::NotSortable;
			}

		}
		else
		{
			textBox3->BackColor = Color::LightCoral;
			MessageBox::Show(L"Вибачте, але ви ввели неіснуючу посаду. Будь ласка, перевірте правильність введення посади і спробуйте знову. ", L"Erorr not deport", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			buttonAddCof->Visible = true;

		}
	}
	else
	{
		textBox1->BackColor = Color::LightCoral;
		MessageBox::Show(L"Вибачте, поле пусте ", L"Erorr None", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

	}
}
private: System::Void buttonEditingTarFillDo_Click(System::Object^ sender, System::EventArgs^ e)
{
	try
	{
		if (textBox1->Text != "" && textBox2->Text != "") {
			bool keyAddTARName = true;
			bool keyAddTARCoefficient = true;

			string Name; MarshalString(textBox1->Text, Name);
			for (int i = 0; i < Name.length(); i++)
			{
				if ((Name[i] == ' ') || (Name[i] == '	')) {

					Name[i] = '_';
				}
			}
			for (int i = 0; i < TAR_vector.size(); i++)
			{
				if (TAR_vector[i].neam == Name && TAR_vector[i].neam != Posit1) {
					keyAddTARName = false;

				}
			}
			string Tarifstr; MarshalString(textBox2->Text, Tarifstr);
			keyAddTARCoefficient = StringDouble(Tarifstr);
			if (keyAddTARCoefficient && keyAddTARName)
			{
				double Tarif = stod(Tarifstr);
				remove(FileNameTar.c_str());
				ofstream text2(FileNameTar);

				for (int i = 0; i < TAR_vector.size(); i++)
				{
					if (TAR_vector[i].neam ==Posit1)
					{
						TAR_vector[i].neam = Name;
						TAR_vector[i].coefficient = Tarif;
					}
				}
				for (int i = 0; i < TAR_vector.size(); i++)
				{
					text2 << TAR_vector[i].neam << " " << TAR_vector[i].coefficient << endl;
				}

				dataGridView1->Columns->Clear();
				dataGridView1->Columns->Add("", "Name");
				dataGridView1->Columns->Add("", "Coefficient");
				for (int i = 0; i < TAR_vector.size(); i++)
				{
					dataGridView1->Rows->Add(gcnew String(TAR_vector[i].neam.c_str()),
						TAR_vector[i].coefficient);
				}
				for each (DataGridViewColumn ^ column in dataGridView1->Columns)
				{
					column->SortMode = DataGridViewColumnSortMode::NotSortable;
				}

				BackbuttonEdiit_Click(sender, e);

			}
			if (!keyAddTARCoefficient) {
				textBox2->BackColor = Color::LightCoral;
				MessageBox::Show(L"Вибачте, ви ввели некоректни тариф. Перевірте, чи відсутні пробіли або подвійні крапки ", L"Erorr Double", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);


			}
			if (!keyAddTARName)
			{
				textBox1->BackColor = Color::LightCoral;
				MessageBox::Show(L"Вибачте, посада з таким іменем вже існує.  ", L"Erorr Name", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

			}
		}
		else
		{
			MessageBox::Show(L"Вибачте, одне або декілька полів порожні   ", L"Erorr None", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);

		}
	}
	catch (std::exception& e) {
		// обробка стандартних виключень
		MessageBox::Show(L"Вибачте, при вводі даних сталася помилка (можливо за велике значення числа) ", L"Erorr", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}
	catch (...) {
		// обробка інших виключень
		MessageBox::Show(L"Вибачте, при вводі даних сталася помилка (можливо за велике значення числа)  ", L"Erorr", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}

}
private: System::Void buttonEditingTarFillDoR_Click(System::Object^ sender, System::EventArgs^ e) {
	buttonEditingTarFill->Visible = true;
	textBox1->Clear();
	textBox2->Clear();
	textBox2->Visible = false;
	labelEditingTar2->Visible = false;
	buttonEditingTarFillDo->Visible = false;
	buttonEditingTarFillDoR->Visible = false;
	dataGridView1->Columns->Clear();
	dataGridView1->Columns->Add("", "Name");
	dataGridView1->Columns->Add("", "Coefficient");
	for (int i = 0; i < TAR_vector.size(); i++)
	{
		dataGridView1->Rows->Add(gcnew String(TAR_vector[i].neam.c_str()),
			TAR_vector[i].coefficient);
	}
	for each (DataGridViewColumn ^ column in dataGridView1->Columns)
	{
		column->SortMode = DataGridViewColumnSortMode::NotSortable;
	}
}
};

}
