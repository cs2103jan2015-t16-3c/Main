#pragma once

#include <msclr\marshal_cppstd.h>
#include <string>
#include "TextUI.h"

namespace GUIProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	unsigned int MEDIUM_SIZE_STRING = 25;
	unsigned int SMALL_SIZE_STRING = 5;
	string LONG_BLANK_SPACE = "                ";
	string SMALL_BLANK_SPACE = "                                      ";
	string command, feedback, stdDisplayResult, stdTaskComponent;
	bool helpDisplayed = false;
	TextUI userInterface;

	/// <summary>
	/// Summary for ConstanGUI
	/// </summary>
	public ref class ConstanGUI : public System::Windows::Forms::Form
	{
	public:
		ConstanGUI(void)
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
		~ConstanGUI()
		{
			if (components)
			{
				delete components;
			}
		}


	protected: 

	protected: 



	private: System::Windows::Forms::TextBox^  InputTextBox;
	//private: System::Resources::ResourceManager^ Resources;


	private: System::Windows::Forms::ListView^  listViewDisplay;
	private: System::Windows::Forms::ColumnHeader^  taskHeader;
	private: System::Windows::Forms::ColumnHeader^  startDateHeader;
	private: System::Windows::Forms::ColumnHeader^  startTimeHeader;
	private: System::Windows::Forms::ColumnHeader^  endDateHeader;
	private: System::Windows::Forms::ColumnHeader^  endTimeHeader;
	protected: System::Windows::Forms::ListViewItem^ aListViewItem;
	private: System::Windows::Forms::ColumnHeader^  taskIndex;
	private: System::Windows::Forms::Label^  feedbackLabel;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  helloLabel;

	private: System::Windows::Forms::Label^  welcomeMsgLabel;

	private: System::Windows::Forms::Button^  ExitButton;
	private: System::Windows::Forms::Label^  headerLabel;

	private: System::Drawing::Color chosenColor;
	private: System::Drawing::Color chosenBGColor;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  displayTypeTexbox;


	private: System::Windows::Forms::Label^  TodayIsLabel;
	private: System::Windows::Forms::TextBox^  TodayDateTextbox;
	private: System::Windows::Forms::ListView^  deadlineListView;


	private: System::Windows::Forms::ColumnHeader^  deadlineCol;
	private: System::Windows::Forms::ColumnHeader^  dueCol;

	private: System::Windows::Forms::TextBox^  searchTextBox;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  greyTheme;
	private: System::Windows::Forms::Label^  blueTheme;
	private: System::Windows::Forms::Label^  pinkTheme;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  deadlineBG;
	private: System::Windows::Forms::Label^  helpButton;
	private: System::Windows::Forms::Label^  helpPage;

	private: System::Windows::Forms::Label^  helpLabel1;
	private: System::Windows::Forms::Label^  helpLabel2;
	private: System::Windows::Forms::Label^  helpLabel3;

	private: System::Windows::Forms::Label^  helpLabel4;







	private: System::Windows::Forms::Label^  helpPageClose;

	private: System::Windows::Forms::Label^  helpLabel11;
	private: System::Windows::Forms::Label^  helpLabel12;
	private: System::Windows::Forms::Label^  helpLabel13;
	private: System::Windows::Forms::Label^  helpLabel10;

	private: System::Windows::Forms::Label^  helpLabel14;
	private: System::Windows::Forms::Label^  helpLabel15;
	private: System::Windows::Forms::Label^  helpLabel16;
	private: System::Windows::Forms::Label^  helpLabel5;
	private: System::Windows::Forms::Label^  helpLabel6;




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
			this->InputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->listViewDisplay = (gcnew System::Windows::Forms::ListView());
			this->taskHeader = (gcnew System::Windows::Forms::ColumnHeader());
			this->startDateHeader = (gcnew System::Windows::Forms::ColumnHeader());
			this->startTimeHeader = (gcnew System::Windows::Forms::ColumnHeader());
			this->endDateHeader = (gcnew System::Windows::Forms::ColumnHeader());
			this->endTimeHeader = (gcnew System::Windows::Forms::ColumnHeader());
			this->taskIndex = (gcnew System::Windows::Forms::ColumnHeader());
			this->feedbackLabel = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->helloLabel = (gcnew System::Windows::Forms::Label());
			this->welcomeMsgLabel = (gcnew System::Windows::Forms::Label());
			this->ExitButton = (gcnew System::Windows::Forms::Button());
			this->headerLabel = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->displayTypeTexbox = (gcnew System::Windows::Forms::TextBox());
			this->TodayIsLabel = (gcnew System::Windows::Forms::Label());
			this->TodayDateTextbox = (gcnew System::Windows::Forms::TextBox());
			this->deadlineListView = (gcnew System::Windows::Forms::ListView());
			this->deadlineCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->dueCol = (gcnew System::Windows::Forms::ColumnHeader());
			this->searchTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->greyTheme = (gcnew System::Windows::Forms::Label());
			this->blueTheme = (gcnew System::Windows::Forms::Label());
			this->pinkTheme = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->deadlineBG = (gcnew System::Windows::Forms::Label());
			this->helpButton = (gcnew System::Windows::Forms::Label());
			this->helpPage = (gcnew System::Windows::Forms::Label());
			this->helpLabel1 = (gcnew System::Windows::Forms::Label());
			this->helpLabel2 = (gcnew System::Windows::Forms::Label());
			this->helpLabel3 = (gcnew System::Windows::Forms::Label());
			this->helpLabel4 = (gcnew System::Windows::Forms::Label());
			this->helpPageClose = (gcnew System::Windows::Forms::Label());
			this->helpLabel11 = (gcnew System::Windows::Forms::Label());
			this->helpLabel12 = (gcnew System::Windows::Forms::Label());
			this->helpLabel13 = (gcnew System::Windows::Forms::Label());
			this->helpLabel10 = (gcnew System::Windows::Forms::Label());
			this->helpLabel14 = (gcnew System::Windows::Forms::Label());
			this->helpLabel15 = (gcnew System::Windows::Forms::Label());
			this->helpLabel16 = (gcnew System::Windows::Forms::Label());
			this->helpLabel5 = (gcnew System::Windows::Forms::Label());
			this->helpLabel6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// InputTextBox
			// 
			this->InputTextBox->BackColor = System::Drawing::Color::WhiteSmoke;
			this->InputTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->InputTextBox->Font = (gcnew System::Drawing::Font(L"Calibri", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->InputTextBox->ForeColor = System::Drawing::Color::Black;
			this->InputTextBox->Location = System::Drawing::Point(509, 508);
			this->InputTextBox->Name = L"InputTextBox";
			this->InputTextBox->Size = System::Drawing::Size(468, 26);
			this->InputTextBox->TabIndex = 7;
			this->InputTextBox->TextChanged += gcnew System::EventHandler(this, &ConstanGUI::InputTextBox_TextChanged);
			this->InputTextBox->DoubleClick += gcnew System::EventHandler(this, &ConstanGUI::InputTextBox_DoubleClick);
			this->InputTextBox->Enter += gcnew System::EventHandler(this, &ConstanGUI::InputTextBox_Enter);
			this->InputTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ConstanGUI::InputTextBox_KeyPress_1);
			// 
			// listViewDisplay
			// 
			this->listViewDisplay->BackColor = System::Drawing::Color::WhiteSmoke;
			this->listViewDisplay->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listViewDisplay->CheckBoxes = true;
			this->listViewDisplay->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(6) {this->taskHeader, 
				this->startDateHeader, this->startTimeHeader, this->endDateHeader, this->endTimeHeader, this->taskIndex});
			this->listViewDisplay->Font = (gcnew System::Drawing::Font(L"Calibri", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->listViewDisplay->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->listViewDisplay->FullRowSelect = true;
			this->listViewDisplay->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->listViewDisplay->Location = System::Drawing::Point(304, 97);
			this->listViewDisplay->Name = L"listViewDisplay";
			this->listViewDisplay->Size = System::Drawing::Size(673, 378);
			this->listViewDisplay->TabIndex = 6;
			this->listViewDisplay->UseCompatibleStateImageBehavior = false;
			this->listViewDisplay->View = System::Windows::Forms::View::Details;
			this->listViewDisplay->ItemCheck += gcnew System::Windows::Forms::ItemCheckEventHandler(this, &ConstanGUI::listViewDisplay_ItemCheck);
			// 
			// taskHeader
			// 
			this->taskHeader->DisplayIndex = 1;
			this->taskHeader->Text = L"Task";
			this->taskHeader->Width = 304;
			// 
			// startDateHeader
			// 
			this->startDateHeader->DisplayIndex = 2;
			this->startDateHeader->Text = L"Start Date";
			this->startDateHeader->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->startDateHeader->Width = 90;
			// 
			// startTimeHeader
			// 
			this->startTimeHeader->DisplayIndex = 3;
			this->startTimeHeader->Text = L"Start Time";
			this->startTimeHeader->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->startTimeHeader->Width = 80;
			// 
			// endDateHeader
			// 
			this->endDateHeader->DisplayIndex = 4;
			this->endDateHeader->Text = L"End Date";
			this->endDateHeader->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->endDateHeader->Width = 90;
			// 
			// endTimeHeader
			// 
			this->endTimeHeader->DisplayIndex = 5;
			this->endTimeHeader->Text = L"End Time";
			this->endTimeHeader->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->endTimeHeader->Width = 80;
			// 
			// taskIndex
			// 
			this->taskIndex->DisplayIndex = 0;
			this->taskIndex->Text = L"Id.";
			this->taskIndex->Width = 30;
			// 
			// feedbackLabel
			// 
			this->feedbackLabel->Font = (gcnew System::Drawing::Font(L"Calibri Light", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->feedbackLabel->ForeColor = System::Drawing::Color::LightGray;
			this->feedbackLabel->Location = System::Drawing::Point(509, 486);
			this->feedbackLabel->Name = L"feedbackLabel";
			this->feedbackLabel->Size = System::Drawing::Size(471, 23);
			this->feedbackLabel->TabIndex = 8;
			this->feedbackLabel->Text = L"Press F1 for Help";
			this->feedbackLabel->UseMnemonic = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->label1->Location = System::Drawing::Point(511, 536);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(309, 15);
			this->label1->TabIndex = 9;
			this->label1->Text = L"add / display / edit / delete / mark / unmark / search / exit";
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Tomato;
			this->label2->Font = (gcnew System::Drawing::Font(L"Calibri", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(304, 508);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(196, 26);
			this->label2->TabIndex = 10;
			this->label2->Text = L"ENTER COMMAND:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// helloLabel
			// 
			this->helloLabel->BackColor = System::Drawing::Color::Tomato;
			this->helloLabel->Font = (gcnew System::Drawing::Font(L"Calibri", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->helloLabel->ForeColor = System::Drawing::Color::White;
			this->helloLabel->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->helloLabel->Location = System::Drawing::Point(40, 44);
			this->helloLabel->Name = L"helloLabel";
			this->helloLabel->Size = System::Drawing::Size(227, 160);
			this->helloLabel->TabIndex = 11;
			this->helloLabel->Text = L"Hello.";
			// 
			// welcomeMsgLabel
			// 
			this->welcomeMsgLabel->AutoSize = true;
			this->welcomeMsgLabel->BackColor = System::Drawing::Color::Tomato;
			this->welcomeMsgLabel->Font = (gcnew System::Drawing::Font(L"Calibri", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->welcomeMsgLabel->ForeColor = System::Drawing::Color::White;
			this->welcomeMsgLabel->Location = System::Drawing::Point(53, 102);
			this->welcomeMsgLabel->Name = L"welcomeMsgLabel";
			this->welcomeMsgLabel->Size = System::Drawing::Size(164, 21);
			this->welcomeMsgLabel->TabIndex = 12;
			this->welcomeMsgLabel->Text = L"Welcome to CONSTAN";
			// 
			// ExitButton
			// 
			this->ExitButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ExitButton->FlatAppearance->BorderSize = 0;
			this->ExitButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ExitButton->Font = (gcnew System::Drawing::Font(L"Calibri Light", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ExitButton->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->ExitButton->Location = System::Drawing::Point(955, -9);
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->Size = System::Drawing::Size(45, 45);
			this->ExitButton->TabIndex = 13;
			this->ExitButton->Text = L"x";
			this->ExitButton->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->ExitButton->UseVisualStyleBackColor = false;
			this->ExitButton->Click += gcnew System::EventHandler(this, &ConstanGUI::ExitButton_Click);
			// 
			// headerLabel
			// 
			this->headerLabel->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->headerLabel->Font = (gcnew System::Drawing::Font(L"Calibri", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->headerLabel->ForeColor = System::Drawing::Color::White;
			this->headerLabel->ImageAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->headerLabel->Location = System::Drawing::Point(304, 81);
			this->headerLabel->Name = L"headerLabel";
			this->headerLabel->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->headerLabel->Size = System::Drawing::Size(673, 40);
			this->headerLabel->TabIndex = 14;
			this->headerLabel->Text = L" ID                                                   TASK                       " 
				L"                              START DATE / TIME                  END DATE / TIME" 
				L"          ";
			this->headerLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Calibri Light", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button1->Location = System::Drawing::Point(908, -9);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(45, 45);
			this->button1->TabIndex = 21;
			this->button1->Text = L"-";
			this->button1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &ConstanGUI::button1_Click);
			// 
			// displayTypeTexbox
			// 
			this->displayTypeTexbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->displayTypeTexbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->displayTypeTexbox->Font = (gcnew System::Drawing::Font(L"Calibri Light", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->displayTypeTexbox->ForeColor = System::Drawing::Color::White;
			this->displayTypeTexbox->Location = System::Drawing::Point(306, 36);
			this->displayTypeTexbox->Name = L"displayTypeTexbox";
			this->displayTypeTexbox->ReadOnly = true;
			this->displayTypeTexbox->Size = System::Drawing::Size(671, 49);
			this->displayTypeTexbox->TabIndex = 23;
			// 
			// TodayIsLabel
			// 
			this->TodayIsLabel->AutoSize = true;
			this->TodayIsLabel->BackColor = System::Drawing::Color::Tomato;
			this->TodayIsLabel->Font = (gcnew System::Drawing::Font(L"Calibri Light", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TodayIsLabel->ForeColor = System::Drawing::Color::White;
			this->TodayIsLabel->Location = System::Drawing::Point(53, 144);
			this->TodayIsLabel->Name = L"TodayIsLabel";
			this->TodayIsLabel->Size = System::Drawing::Size(65, 21);
			this->TodayIsLabel->TabIndex = 24;
			this->TodayIsLabel->Text = L"Today is";
			// 
			// TodayDateTextbox
			// 
			this->TodayDateTextbox->BackColor = System::Drawing::Color::Tomato;
			this->TodayDateTextbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->TodayDateTextbox->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TodayDateTextbox->ForeColor = System::Drawing::Color::White;
			this->TodayDateTextbox->Location = System::Drawing::Point(57, 165);
			this->TodayDateTextbox->Name = L"TodayDateTextbox";
			this->TodayDateTextbox->ReadOnly = true;
			this->TodayDateTextbox->Size = System::Drawing::Size(188, 25);
			this->TodayDateTextbox->TabIndex = 25;
			// 
			// deadlineListView
			// 
			this->deadlineListView->AllowColumnReorder = true;
			this->deadlineListView->BackColor = System::Drawing::Color::WhiteSmoke;
			this->deadlineListView->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->deadlineListView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {this->deadlineCol, 
				this->dueCol});
			this->deadlineListView->Font = (gcnew System::Drawing::Font(L"Calibri", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->deadlineListView->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->deadlineListView->Location = System::Drawing::Point(53, 258);
			this->deadlineListView->Name = L"deadlineListView";
			this->deadlineListView->Size = System::Drawing::Size(214, 217);
			this->deadlineListView->TabIndex = 26;
			this->deadlineListView->TileSize = System::Drawing::Size(248, 56);
			this->deadlineListView->UseCompatibleStateImageBehavior = false;
			this->deadlineListView->View = System::Windows::Forms::View::Tile;
			// 
			// deadlineCol
			// 
			this->deadlineCol->Text = L"Deadline";
			this->deadlineCol->Width = 131;
			// 
			// dueCol
			// 
			this->dueCol->Text = L"Due";
			this->dueCol->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->dueCol->Width = 87;
			// 
			// searchTextBox
			// 
			this->searchTextBox->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->searchTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->searchTextBox->Font = (gcnew System::Drawing::Font(L"Calibri Light", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->searchTextBox->ForeColor = System::Drawing::Color::White;
			this->searchTextBox->Location = System::Drawing::Point(642, 8);
			this->searchTextBox->Name = L"searchTextBox";
			this->searchTextBox->Size = System::Drawing::Size(258, 28);
			this->searchTextBox->TabIndex = 28;
			this->searchTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ConstanGUI::searchTextBox_KeyPress);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->label4->Font = (gcnew System::Drawing::Font(L"Calibri", 10.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(879, 14);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(17, 21);
			this->label4->TabIndex = 29;
			this->label4->Text = L"/";
			// 
			// label5
			// 
			this->label5->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->label5->Font = (gcnew System::Drawing::Font(L"Calibri", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->ImageAlign = System::Drawing::ContentAlignment::BottomLeft;
			this->label5->Location = System::Drawing::Point(879, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(17, 18);
			this->label5->TabIndex = 30;
			this->label5->Text = L"O";
			this->label5->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// greyTheme
			// 
			this->greyTheme->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->greyTheme->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->greyTheme->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->greyTheme->Location = System::Drawing::Point(39, 502);
			this->greyTheme->Name = L"greyTheme";
			this->greyTheme->Size = System::Drawing::Size(30, 30);
			this->greyTheme->TabIndex = 31;
			this->greyTheme->Click += gcnew System::EventHandler(this, &ConstanGUI::greyTheme_Click);
			// 
			// blueTheme
			// 
			this->blueTheme->BackColor = System::Drawing::Color::DarkSlateGray;
			this->blueTheme->Location = System::Drawing::Point(90, 502);
			this->blueTheme->Name = L"blueTheme";
			this->blueTheme->Size = System::Drawing::Size(30, 30);
			this->blueTheme->TabIndex = 32;
			this->blueTheme->Click += gcnew System::EventHandler(this, &ConstanGUI::blueTheme_Click);
			// 
			// pinkTheme
			// 
			this->pinkTheme->BackColor = System::Drawing::Color::Crimson;
			this->pinkTheme->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->pinkTheme->Location = System::Drawing::Point(142, 502);
			this->pinkTheme->Name = L"pinkTheme";
			this->pinkTheme->Size = System::Drawing::Size(30, 30);
			this->pinkTheme->TabIndex = 33;
			this->pinkTheme->Click += gcnew System::EventHandler(this, &ConstanGUI::pinkTheme_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Calibri Light", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(34, 226);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(138, 29);
			this->label3->TabIndex = 34;
			this->label3->Text = L"Deadline due";
			// 
			// deadlineBG
			// 
			this->deadlineBG->BackColor = System::Drawing::Color::WhiteSmoke;
			this->deadlineBG->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->deadlineBG->Location = System::Drawing::Point(40, 253);
			this->deadlineBG->Name = L"deadlineBG";
			this->deadlineBG->Size = System::Drawing::Size(227, 222);
			this->deadlineBG->TabIndex = 35;
			// 
			// helpButton
			// 
			this->helpButton->AutoSize = true;
			this->helpButton->BackColor = System::Drawing::Color::Transparent;
			this->helpButton->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->helpButton->ForeColor = System::Drawing::Color::White;
			this->helpButton->Location = System::Drawing::Point(612, 9);
			this->helpButton->Name = L"helpButton";
			this->helpButton->Size = System::Drawing::Size(19, 24);
			this->helpButton->TabIndex = 36;
			this->helpButton->Text = L"\?";
			this->helpButton->Click += gcnew System::EventHandler(this, &ConstanGUI::helpButton_Click);
			// 
			// helpPage
			// 
			this->helpPage->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->helpPage->Font = (gcnew System::Drawing::Font(L"Calibri Light", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->helpPage->ForeColor = System::Drawing::Color::White;
			this->helpPage->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->helpPage->Location = System::Drawing::Point(304, 40);
			this->helpPage->Name = L"helpPage";
			this->helpPage->Size = System::Drawing::Size(673, 436);
			this->helpPage->TabIndex = 37;
			this->helpPage->Text = L"Help Page";
			// 
			// helpLabel1
			// 
			this->helpLabel1->AutoSize = true;
			this->helpLabel1->Font = (gcnew System::Drawing::Font(L"Calibri", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->helpLabel1->ForeColor = System::Drawing::Color::White;
			this->helpLabel1->Location = System::Drawing::Point(313, 95);
			this->helpLabel1->Name = L"helpLabel1";
			this->helpLabel1->Size = System::Drawing::Size(217, 23);
			this->helpLabel1->TabIndex = 38;
			this->helpLabel1->Text = L"General command format:";
			// 
			// helpLabel2
			// 
			this->helpLabel2->Font = (gcnew System::Drawing::Font(L"Calibri", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->helpLabel2->ForeColor = System::Drawing::Color::White;
			this->helpLabel2->Location = System::Drawing::Point(331, 123);
			this->helpLabel2->Name = L"helpLabel2";
			this->helpLabel2->Size = System::Drawing::Size(98, 212);
			this->helpLabel2->TabIndex = 39;
			this->helpLabel2->Text = L"add...............\r\n\r\n\r\nsearch...........\r\nedit...............\r\ndelete..........." 
				L"\r\nmark.............\r\nunmark.........\r\nundo.............\r\ndisplay..........";
			// 
			// helpLabel3
			// 
			this->helpLabel3->Font = (gcnew System::Drawing::Font(L"Calibri Light", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->helpLabel3->ForeColor = System::Drawing::Color::White;
			this->helpLabel3->Location = System::Drawing::Point(417, 123);
			this->helpLabel3->Name = L"helpLabel3";
			this->helpLabel3->Size = System::Drawing::Size(496, 56);
			this->helpLabel3->TabIndex = 40;
			this->helpLabel3->Text = L"for schedules:  add -t [task name] -s [start date] [start time] -e [end date] [en" 
				L"d time]\r\nfor deadlines:  add -t [task name] -e [end date] [end time]\r\nfor to-dos" 
				L":        add -t [task name] ";
			// 
			// helpLabel4
			// 
			this->helpLabel4->AutoSize = true;
			this->helpLabel4->Font = (gcnew System::Drawing::Font(L"Calibri", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->helpLabel4->ForeColor = System::Drawing::Color::White;
			this->helpLabel4->Location = System::Drawing::Point(313, 387);
			this->helpLabel4->Name = L"helpLabel4";
			this->helpLabel4->Size = System::Drawing::Size(85, 23);
			this->helpLabel4->TabIndex = 41;
			this->helpLabel4->Text = L"Hot Keys:";
			// 
			// helpPageClose
			// 
			this->helpPageClose->AutoSize = true;
			this->helpPageClose->Font = (gcnew System::Drawing::Font(L"Calibri", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->helpPageClose->ForeColor = System::Drawing::Color::White;
			this->helpPageClose->Location = System::Drawing::Point(849, 451);
			this->helpPageClose->Name = L"helpPageClose";
			this->helpPageClose->Size = System::Drawing::Size(125, 18);
			this->helpPageClose->TabIndex = 47;
			this->helpPageClose->Text = L"close Help Page [x]";
			this->helpPageClose->Click += gcnew System::EventHandler(this, &ConstanGUI::helpPageClose_Click);
			// 
			// helpLabel11
			// 
			this->helpLabel11->AutoSize = true;
			this->helpLabel11->Font = (gcnew System::Drawing::Font(L"Calibri", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->helpLabel11->ForeColor = System::Drawing::Color::White;
			this->helpLabel11->Location = System::Drawing::Point(313, 313);
			this->helpLabel11->Name = L"helpLabel11";
			this->helpLabel11->Size = System::Drawing::Size(232, 23);
			this->helpLabel11->TabIndex = 48;
			this->helpLabel11->Text = L"Accepted date/time format:";
			// 
			// helpLabel12
			// 
			this->helpLabel12->AutoSize = true;
			this->helpLabel12->Font = (gcnew System::Drawing::Font(L"Calibri", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->helpLabel12->ForeColor = System::Drawing::Color::White;
			this->helpLabel12->Location = System::Drawing::Point(334, 341);
			this->helpLabel12->Name = L"helpLabel12";
			this->helpLabel12->Size = System::Drawing::Size(47, 21);
			this->helpLabel12->TabIndex = 49;
			this->helpLabel12->Text = L"Date:\r";
			// 
			// helpLabel13
			// 
			this->helpLabel13->AutoSize = true;
			this->helpLabel13->Font = (gcnew System::Drawing::Font(L"Calibri Light", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->helpLabel13->ForeColor = System::Drawing::Color::White;
			this->helpLabel13->Location = System::Drawing::Point(381, 343);
			this->helpLabel13->Name = L"helpLabel13";
			this->helpLabel13->Size = System::Drawing::Size(202, 36);
			this->helpLabel13->TabIndex = 50;
			this->helpLabel13->Text = L"DDMMYYYY (eg. 13042015)\r\nDD MMM YYYY (eg 13 Apr 2015)";
			// 
			// helpLabel10
			// 
			this->helpLabel10->AutoSize = true;
			this->helpLabel10->Font = (gcnew System::Drawing::Font(L"Calibri Light", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->helpLabel10->ForeColor = System::Drawing::Color::White;
			this->helpLabel10->Location = System::Drawing::Point(639, 343);
			this->helpLabel10->Name = L"helpLabel10";
			this->helpLabel10->Size = System::Drawing::Size(256, 36);
			this->helpLabel10->TabIndex = 52;
			this->helpLabel10->Text = L"HHMM (eg. 1200)\r\n0000 = 12:00 a.m.  to  2359 = 11:59 p.m.\r\n";
			// 
			// helpLabel14
			// 
			this->helpLabel14->AutoSize = true;
			this->helpLabel14->Font = (gcnew System::Drawing::Font(L"Calibri", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->helpLabel14->ForeColor = System::Drawing::Color::White;
			this->helpLabel14->Location = System::Drawing::Point(592, 341);
			this->helpLabel14->Name = L"helpLabel14";
			this->helpLabel14->Size = System::Drawing::Size(49, 21);
			this->helpLabel14->TabIndex = 51;
			this->helpLabel14->Text = L"Time:";
			// 
			// helpLabel15
			// 
			this->helpLabel15->Font = (gcnew System::Drawing::Font(L"Calibri Light", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->helpLabel15->ForeColor = System::Drawing::Color::White;
			this->helpLabel15->Location = System::Drawing::Point(417, 176);
			this->helpLabel15->Name = L"helpLabel15";
			this->helpLabel15->Size = System::Drawing::Size(496, 56);
			this->helpLabel15->TabIndex = 53;
			this->helpLabel15->Text = L"search [keyword(s)]\r\nedit add -t [task name] -s [start date] [start time] -e [end" 
				L" date] [end time]\r\ndelete [index]";
			// 
			// helpLabel16
			// 
			this->helpLabel16->Font = (gcnew System::Drawing::Font(L"Calibri Light", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->helpLabel16->ForeColor = System::Drawing::Color::White;
			this->helpLabel16->Location = System::Drawing::Point(417, 231);
			this->helpLabel16->Name = L"helpLabel16";
			this->helpLabel16->Size = System::Drawing::Size(496, 82);
			this->helpLabel16->TabIndex = 54;
			this->helpLabel16->Text = L"mark [index]\r\nunmark [index]\r\nundo\r\ndisplay all/today/tomorrow";
			// 
			// helpLabel5
			// 
			this->helpLabel5->AutoSize = true;
			this->helpLabel5->Font = (gcnew System::Drawing::Font(L"Calibri", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->helpLabel5->ForeColor = System::Drawing::Color::White;
			this->helpLabel5->Location = System::Drawing::Point(335, 414);
			this->helpLabel5->Name = L"helpLabel5";
			this->helpLabel5->Size = System::Drawing::Size(111, 54);
			this->helpLabel5->TabIndex = 42;
			this->helpLabel5->Text = L"Help (F1)\r\nSearch (CTRL + F)\r\nUndo (CTRL + Z)";
			// 
			// helpLabel6
			// 
			this->helpLabel6->AutoSize = true;
			this->helpLabel6->Font = (gcnew System::Drawing::Font(L"Calibri", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->helpLabel6->ForeColor = System::Drawing::Color::White;
			this->helpLabel6->Location = System::Drawing::Point(514, 414);
			this->helpLabel6->Name = L"helpLabel6";
			this->helpLabel6->Size = System::Drawing::Size(187, 18);
			this->helpLabel6->TabIndex = 55;
			this->helpLabel6->Text = L"Enter command (CTRL+Enter)\r\n";
			// 
			// ConstanGUI
			// 
			this->AutoScroll = true;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(1000, 562);
			this->Controls->Add(this->helpButton);
			this->Controls->Add(this->pinkTheme);
			this->Controls->Add(this->blueTheme);
			this->Controls->Add(this->greyTheme);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->searchTextBox);
			this->Controls->Add(this->TodayDateTextbox);
			this->Controls->Add(this->TodayIsLabel);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->ExitButton);
			this->Controls->Add(this->welcomeMsgLabel);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->InputTextBox);
			this->Controls->Add(this->helloLabel);
			this->Controls->Add(this->feedbackLabel);
			this->Controls->Add(this->deadlineListView);
			this->Controls->Add(this->deadlineBG);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->headerLabel);
			this->Controls->Add(this->listViewDisplay);
			this->Controls->Add(this->displayTypeTexbox);
			this->Controls->Add(this->helpLabel6);
			this->Controls->Add(this->helpLabel16);
			this->Controls->Add(this->helpLabel15);
			this->Controls->Add(this->helpLabel10);
			this->Controls->Add(this->helpLabel14);
			this->Controls->Add(this->helpLabel13);
			this->Controls->Add(this->helpLabel12);
			this->Controls->Add(this->helpLabel11);
			this->Controls->Add(this->helpPageClose);
			this->Controls->Add(this->helpLabel5);
			this->Controls->Add(this->helpLabel4);
			this->Controls->Add(this->helpLabel3);
			this->Controls->Add(this->helpLabel2);
			this->Controls->Add(this->helpLabel1);
			this->Controls->Add(this->helpPage);
			this->Font = (gcnew System::Drawing::Font(L"Calibri", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->Name = L"ConstanGUI";
			this->Load += gcnew System::EventHandler(this, &ConstanGUI::ConstanGUI_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &ConstanGUI::ConstanGUI_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

/*USER OPEN APP*/
//clear all the display
//set initial display -> Today's task and deadline due
private: System::Void ConstanGUI_Load(System::Object^  sender, System::EventArgs^  e) {
			
			 listViewDisplay->Items->Clear(); 
			 deadlineListView->Items->Clear();
					  
			 string initialDisplay = "display today";
			 command = initialDisplay;
			 userInterface.processUserInput(command);
			 Print();

			 string todayDate = userInterface.showTodayDate();
			 String^ showDate = gcnew String(todayDate.c_str());
			 TodayDateTextbox->Text = showDate;

			 displayTypeTexbox->Text = "Today's task:";

			 PrintDeadline();
		 }

/*USER PRESS ENTER ON INPUT TEXTBOX*/
//get user input and pass it to TextUI class
//print the display
private: System::Void InputTextBox_KeyPress_1(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 

			 if (e->KeyChar == /*Keys::Enter*/ (char)13){
				 feedbackLabel->Text = "";
				 //clear the display box first
				 listViewDisplay->Items->Clear(); 
				 deadlineListView->Items->Clear();
					  
					  String^ userInput;
					  userInput = InputTextBox->Text; //System String
					  //convert to std string
					  command = msclr::interop::marshal_as < std::string > (userInput); 
					 
					  if (command == "clr" || command == "Clr") {
						//clear screen
						  listViewDisplay->Items->Clear(); 
						return;
					  }

					  if (command == "") {
						return;
					  }

					  if (command == "exit" || command == "Exit") {
						  Application::Exit();
						  return;
					  }

					  //pass command to TextUI.h class to be passed to logic and then processed
					  userInterface.processUserInput(command);
					 
					  Print();
					  PrintDisplayType();
					  PrintFeedback();
					  PrintDeadline();
					  
					  e->Handled = true;

			 }
					  //MessageBox::Show(input);
					  //TestInput a;
					  //a.userInput = input;
		 }

/*USER PRESS ENTER ON SEARCH TEXTBOX*/
//pass command search and the keywords to TextUI
//print the resulted display
private: System::Void searchTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			
			 if (e->KeyChar == /*Keys::Enter*/ (char)13){
				 feedbackLabel->Text = "";
				 //clear the display box first
				 listViewDisplay->Items->Clear(); 
					  
					  String^ userSearchInput;
					  string search = "search ";
					  userSearchInput = searchTextBox->Text; //System String
					  //convert to std string
					  command = search + msclr::interop::marshal_as < std::string > (userSearchInput);
					 
					  if (command == "") {
						return;
					  }

					  userInterface.processUserInput(command);
					  Print();
					  PrintDisplayType();
					  PrintFeedback();

					  searchTextBox->Text = "";

					  e->Handled = true;
			 }
		 }

/*PRINT THE CURRENT DISPLAY TYPE*/
private: System::Void PrintDisplayType() {

			 string commandDisplay = userInterface.showCurrentDisplayIndicator();
			 String^ displayType = gcnew String(commandDisplay.c_str());
			 
			 displayTypeTexbox->Text = displayType;

		 }

/*DISPLAY THE TASK TO USER IN TABLE FORM*/
//differentiate the task based on their type and give them unique indexes
private: System::Void Print() {

			 System::Windows::Forms::ListViewGroup^  listViewGroup1 = (gcnew System::Windows::Forms::ListViewGroup(L"Scheduled Tasks", System::Windows::Forms::HorizontalAlignment::Left));
			 System::Windows::Forms::ListViewGroup^  listViewGroup2 = (gcnew System::Windows::Forms::ListViewGroup(L"Deadlines", System::Windows::Forms::HorizontalAlignment::Left));
			 System::Windows::Forms::ListViewGroup^  listViewGroup3 = (gcnew System::Windows::Forms::ListViewGroup(L"To Do", System::Windows::Forms::HorizontalAlignment::Left));
			 
			 this->listViewDisplay->FullRowSelect = true;
			 listViewGroup1->Header = L"Scheduled Tasks";
			 listViewGroup1->Name = L"ScheduleGroup";
			 listViewGroup2->Header = L"Deadlines";
			 listViewGroup2->Name = L"DeadlineGroup";
			 listViewGroup3->Header = L"To Do";
			 listViewGroup3->Name = L"FloatingGroup";
			 
			 this->listViewDisplay->Groups->AddRange(gcnew cli::array< System::Windows::Forms::ListViewGroup^  >(3) {listViewGroup1, listViewGroup2, listViewGroup3});

					  String^ displayResult;
					  String^ taskComponent;
					  String^ taskIndex;
					  String^ taskTitle;
					  String^ taskStartDate;
					  String^ taskStartTime;
					  String^ taskEndDate;
					  String^ taskEndTime;					  
					  String^ taskStatus;

					  
					  //get A STRING of the tasks list and their details to be displayed from TextUI
					  stdDisplayResult = userInterface.showDisplay();
					  displayResult = gcnew String(stdDisplayResult.c_str());

					  int frontTask, endTask = -1, count, index = 1;

					  count = userInterface.getNoOfTask();

					  while (count > 0) {

						  /*INDEX*/
						  taskIndex = System::Convert::ToString(index);
						  index++;

						  /*TITLE*/
						  frontTask = endTask + 1;
						  //extract the task title
						  endTask = stdDisplayResult.find_first_of("]", frontTask);
						  stdTaskComponent = stdDisplayResult.substr(frontTask, endTask-frontTask);
						  //convert to std string
						  taskComponent = gcnew String(stdTaskComponent.c_str());
						  //add into a system string object
						  taskTitle = taskComponent;

						  /*START DATE*/
						  frontTask = endTask + 1;
						  //extract the task's start date
						  endTask = stdDisplayResult.find_first_of("]", frontTask);
						  stdTaskComponent = stdDisplayResult.substr(frontTask, endTask-frontTask);
						  //convert to std string
						  taskComponent = gcnew String(stdTaskComponent.c_str());
						  if(taskComponent == "NULL")
							  taskStartDate = "";
						  else
							  //add into a system string object
							  taskStartDate = taskComponent;

						  /*START TIME*/
						  frontTask = endTask + 1;
						  //extract the task's start time
						  endTask = stdDisplayResult.find_first_of("]", frontTask);
						  stdTaskComponent = stdDisplayResult.substr(frontTask, endTask-frontTask);
						  //convert to std string
						  taskComponent = gcnew String(stdTaskComponent.c_str());
						  if(taskComponent == "NULL")
							  taskStartTime = "";
						  else
							  //add into a system string object
							  taskStartTime = taskComponent;

						  /*END DATE*/
						  frontTask = endTask + 1;
						  //extract the task's end date
						  endTask = stdDisplayResult.find_first_of("]", frontTask);
						  stdTaskComponent = stdDisplayResult.substr(frontTask, endTask-frontTask);
						  //convert to std string
						  taskComponent = gcnew String(stdTaskComponent.c_str());
						  if(taskComponent == "NULL")
							  taskEndDate = "";
						  else
							  //add into a system string object
							  taskEndDate = taskComponent;

						  /*END TIME*/
						  frontTask = endTask + 1;
						  //extract the task's start time
						  endTask = stdDisplayResult.find_first_of("]", frontTask);
						  stdTaskComponent = stdDisplayResult.substr(frontTask, endTask-frontTask);
						  //convert to std string
						  taskComponent = gcnew String(stdTaskComponent.c_str());
						  if(taskComponent == "NULL")
							  taskEndTime = "";
						  else
							  //add into a system string object
							  taskEndTime = taskComponent;

						  /*MARK/UNMARKED*/
						  frontTask = endTask + 1;
						  //extract the task's status
						  endTask = stdDisplayResult.find_first_of("]", frontTask);
						  stdTaskComponent = stdDisplayResult.substr(frontTask, endTask-frontTask);
						  //convert to std string
						  taskComponent = gcnew String(stdTaskComponent.c_str());
						  //add into a system string object
						  taskStatus = taskComponent;

						  aListViewItem = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(6) { taskTitle, taskStartDate, taskStartTime, taskEndDate, taskEndTime, taskIndex }, -1));

						  //group according to task type and mark done/undone
						  if(taskStartTime != "" && taskEndTime != "") {
							  aListViewItem->Group = listViewGroup1;
							  if(taskStatus == "done") {
								aListViewItem->StateImageIndex = 1;
								aListViewItem->ForeColor = System::Drawing::Color::LightGray;
							  } else if(taskStatus == "undone")
								  aListViewItem->StateImageIndex = 0;
						  } else if(taskStartTime == "" && taskEndTime != "") {
							  aListViewItem->Group = listViewGroup2;
							  if(taskStatus == "done") {
								aListViewItem->StateImageIndex = 1;
								aListViewItem->ForeColor = System::Drawing::Color::LightGray;
							  } else if(taskStatus == "undone")
								  aListViewItem->StateImageIndex = 0;
						  } else {
							  aListViewItem->Group = listViewGroup3;
							  if(taskStatus == "done") {
								aListViewItem->StateImageIndex = 1;
								aListViewItem->ForeColor = System::Drawing::Color::LightGray;
							  } else if(taskStatus == "undone")
								  aListViewItem->StateImageIndex = 0;
						  }

						  listViewDisplay->Items->Add(this->aListViewItem);

						  count--;
					  }

					  //clear input box for the next command
						InputTextBox->Clear();
		 }

/*DISPLAY FEEDBACK/ERROR MESSAGE TO USER AFTER EACH COMMAND*/
private: System::Void PrintFeedback() {

			 String^ feedbackStr;
			 //get A STRING of feedback message to be displayed from TextUI
			 feedback = userInterface.showFeedback();

			 //clear the feedback box first, then display feedback
			 feedbackLabel->Text = "";
			 feedbackStr = gcnew String(feedback.c_str());
			 feedbackLabel->Text = feedbackStr;


		 }

/*DISPLAY DUE DEADLINES IN SIDE BOX*/
//give different color to the deadlines' titles and due dates based on the color theme
private: System::Void PrintDeadline() {

			 String^ taskComponent;
			 String^ taskTitle;
			 String^ taskEndDate;
			 String^ taskEndTime;
			 String^ deadlineList;
			 String^ deadline;
			 string stdDeadline;

			 stdDeadline = userInterface.showDeadline(); //std string
			//convert std string to System string
			 deadlineList = gcnew String(stdDisplayResult.c_str());

					  int frontTask, endTask = -1, count, index = 1;

					  count = userInterface.getNoOfDeadline();

					  while (count > 0) {

						  /*TITLE*/
						  frontTask = endTask + 1;
						  //extract the task title
						  endTask = stdDeadline.find_first_of("]", frontTask);
						  stdTaskComponent = stdDeadline.substr(frontTask, endTask-frontTask);
						  if (stdTaskComponent.size() < MEDIUM_SIZE_STRING && stdTaskComponent.size() > SMALL_SIZE_STRING)
							  stdTaskComponent = stdTaskComponent + SMALL_BLANK_SPACE;
						  if (stdTaskComponent.size() <= SMALL_SIZE_STRING)
							  stdTaskComponent = stdTaskComponent + LONG_BLANK_SPACE;
						  //convert to std string
						  taskComponent = gcnew String(stdTaskComponent.c_str());
						  //add into a system string object
						  taskTitle = taskComponent;

						  /*END DATE*/
						  frontTask = endTask + 1;
						  //extract the task's end date
						  endTask = stdDeadline.find_first_of("]", frontTask);
						  stdTaskComponent = stdDeadline.substr(frontTask, endTask-frontTask);
						  //convert to std string
						  taskComponent = gcnew String(stdTaskComponent.c_str());
						  taskEndDate = taskComponent;

						  /*END TIME*/
						  frontTask = endTask + 1;
						  //extract the task's start time
						  endTask = stdDeadline.find_first_of("]", frontTask);
						  stdTaskComponent = stdDeadline.substr(frontTask, endTask-frontTask);
						  //convert to std string
						  taskComponent = gcnew String(stdTaskComponent.c_str());
						  taskEndTime = taskComponent;

//CONVERT END DATE TO TODAY OR TOMORROW
						  deadline = taskEndDate + " " + taskEndTime;

						  ListViewItem^ aListViewItem = deadlineListView->Items->Add(taskTitle);
						  deadlineListView->ForeColor = chosenColor;
						  deadlineListView->Font = gcnew System::Drawing::Font( L"Calibri",9,System::Drawing::FontStyle::Bold );
						 
						  aListViewItem->UseItemStyleForSubItems = false;
						  
						  ListViewItem::ListViewSubItem ^ deadlineDateTime =  aListViewItem->SubItems->Add(deadline);
						  deadlineDateTime->ForeColor = System::Drawing::Color::DimGray;
						  deadlineDateTime->Font = gcnew System::Drawing::Font( L"Calibri Light",9,System::Drawing::FontStyle::Regular );
						  
						  count--;

					 }
		 }

/*DISPLAY INPUT GUIDE FOR USER*/
private: System::Void InputTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {

			 if(InputTextBox->Text == "add") {
				 feedbackLabel->Text = "add  -t [task name]  -s [start date] [start time]  -e [end date] [end time]";
			 }else if(InputTextBox->Text == "display") {
				 feedbackLabel->Text = "display today/tomorrow/all"; 
			 }else if(InputTextBox->Text == "edit") {
				 feedbackLabel->Text = "edit [index] -t [task name]  -s [start date] [start time]  -e [end date] [end time]"; 
			 }else if(InputTextBox->Text == "delete") {
				 feedbackLabel->Text = "delete [index]"; 
			 }else if(InputTextBox->Text == "mark") {
				 feedbackLabel->Text = "mark [index]";
			 }else if(InputTextBox->Text == "unmark") {
				 feedbackLabel->Text = "unmark [index]";
			 }else if(InputTextBox->Text == "search") {
				 feedbackLabel->Text = "search [keyword(s)]";
			 }
		 }

private: System::Void InputTextBox_Enter(System::Object^  sender, System::EventArgs^  e) {
			 
		 }

/*USER CAN CLEAR INPUT TEXTBOX BY DOUBLE CLICKING ON THE TEXT BOX*/
private: System::Void InputTextBox_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			 InputTextBox->Clear();
			 feedbackLabel->Text = "Enter command";
		 }

/*USER CAN TICK/UNTICK CHECKBOX TO MARK/UNMARK TASK*/
//function run when the user tick/unticked the checkbox
//print the display
private: System::Void listViewDisplay_ItemCheck(System::Object^  sender, System::Windows::Forms::ItemCheckEventArgs^  e) {
			
			 feedbackLabel->Text = "";

			 //int itemIndex = e->Index;
			 ListViewItem^ item1 = listViewDisplay->Items[e->Index];
			
			 String^ txt = item1->SubItems[5]->Text;
			 string index = msclr::interop::marshal_as < std::string > (txt); 
			 string unmark = "unmark ";
			 string mark = "mark ";

			 if(e->CurrentValue == CheckState::Checked) {
				 userInterface.processUserInput( unmark + index );
				 item1->ForeColor = System::Drawing::Color::Black;

			 } else if(e->CurrentValue == CheckState::Unchecked) {
				 userInterface.processUserInput( mark + index );
				 item1->ForeColor = System::Drawing::Color::LightGray;
			 }

			 deadlineListView->Items->Clear();
			 PrintDeadline();

		 }
		 

/*CUSTOM EXIT BUTTON*/
private: System::Void ExitButton_Click(System::Object^  sender, System::EventArgs^  e) {
			  Application::Exit();
		 }

/*CUSTOM MINIMIZE BUTTON*/
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->WindowState = FormWindowState::Minimized;
		 }

/*CHANGE COLOR THEME TO PINK*/
private: System::Void pinkTheme_Click(System::Object^  sender, System::EventArgs^  e) {
				
				this->chosenColor = System::Drawing::Color::LightCoral;
				this->chosenBGColor = System::Drawing::Color::White;

				deadlineListView->Items->Clear();
				PrintDeadline();

				this->feedbackLabel->BackColor = System::Drawing::Color::LightCoral;
				this->feedbackLabel->ForeColor = System::Drawing::Color::White;

				this->label2->BackColor = System::Drawing::Color::Crimson;

				this->helloLabel->BackColor = System::Drawing::Color::White;
				this->helloLabel->ForeColor = System::Drawing::Color::LightCoral;

				this->welcomeMsgLabel->BackColor = System::Drawing::Color::White;
				this->welcomeMsgLabel->ForeColor = System::Drawing::Color::LightCoral;

				this->ExitButton->BackColor = System::Drawing::Color::LightCoral;
				this->ExitButton->ForeColor = System::Drawing::Color::White;

				this->button1->BackColor = System::Drawing::Color::LightCoral;
				this->button1->ForeColor = System::Drawing::Color::White;

				this->headerLabel->BackColor = System::Drawing::Color::Crimson;

				this->displayTypeTexbox->BackColor = System::Drawing::Color::LightCoral;
				this->displayTypeTexbox->ForeColor = System::Drawing::Color::White;

				this->TodayIsLabel->BackColor = System::Drawing::Color::White;
				this->TodayIsLabel->ForeColor = System::Drawing::Color::LightCoral;

				this->TodayDateTextbox->BackColor = System::Drawing::Color::White;
				this->TodayDateTextbox->ForeColor = System::Drawing::Color::LightCoral;

				this->searchTextBox->BackColor = System::Drawing::Color::White;
				this->searchTextBox->ForeColor = System::Drawing::Color::DimGray;

				this->label4->BackColor = System::Drawing::Color::White;
				this->label4->ForeColor = System::Drawing::Color::DimGray;

				this->label5->BackColor = System::Drawing::Color::White;
				this->label5->ForeColor = System::Drawing::Color::DimGray;

				this->label3->BackColor = System::Drawing::Color::LightCoral;
				this->label3->ForeColor = System::Drawing::Color::White;
				
				this->deadlineBG->BackColor = System::Drawing::Color::White;
				this->deadlineListView->BackColor = System::Drawing::Color::White;
				this->listViewDisplay->BackColor = System::Drawing::Color::White;
				this->InputTextBox->BackColor = System::Drawing::Color::White;
				this->label1->ForeColor = System::Drawing::Color::White;

				this->BackColor = System::Drawing::Color::LightCoral;

				/*Help page color*/
				helpPage->BackColor = System::Drawing::Color::LightCoral;
				helpLabel1->BackColor = System::Drawing::Color::LightCoral;
				helpLabel2->BackColor = System::Drawing::Color::LightCoral;
				helpLabel3->BackColor = System::Drawing::Color::LightCoral;
				helpLabel4->BackColor = System::Drawing::Color::LightCoral;
				helpLabel5->BackColor = System::Drawing::Color::LightCoral;
				helpLabel6->BackColor = System::Drawing::Color::LightCoral;
				helpLabel10->BackColor = System::Drawing::Color::LightCoral;
				helpLabel11->BackColor = System::Drawing::Color::LightCoral;
				helpLabel12->BackColor = System::Drawing::Color::LightCoral;
				helpLabel13->BackColor = System::Drawing::Color::LightCoral;
				helpLabel14->BackColor = System::Drawing::Color::LightCoral;
				helpLabel15->BackColor = System::Drawing::Color::LightCoral;
				helpLabel16->BackColor = System::Drawing::Color::LightCoral;
				helpPageClose->BackColor = System::Drawing::Color::LightCoral;

		 }

/*CHANGE COLOR THEME TO DEFAULT THEME (GREY)*/
private: System::Void greyTheme_Click(System::Object^  sender, System::EventArgs^  e) {
				
				this->chosenColor = System::Drawing::Color::DimGray;
				this->chosenBGColor = System::Drawing::Color::WhiteSmoke;

				deadlineListView->Items->Clear();
				PrintDeadline();

				this->feedbackLabel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
				this->feedbackLabel->ForeColor = System::Drawing::Color::LightGray;

				this->label2->BackColor = System::Drawing::Color::Tomato;

				this->helloLabel->BackColor = System::Drawing::Color::Tomato;
				this->helloLabel->ForeColor = System::Drawing::Color::White;

				this->welcomeMsgLabel->BackColor = System::Drawing::Color::Tomato;
				this->welcomeMsgLabel->ForeColor = System::Drawing::Color::White;

				this->TodayIsLabel->BackColor = System::Drawing::Color::Tomato;
				this->TodayIsLabel->ForeColor = System::Drawing::Color::White;

				this->TodayDateTextbox->BackColor = System::Drawing::Color::Tomato;
				this->TodayDateTextbox->ForeColor = System::Drawing::Color::White;

				this->displayTypeTexbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
				this->displayTypeTexbox->ForeColor = System::Drawing::Color::White;

				this->searchTextBox->BackColor = System::Drawing::SystemColors::WindowFrame;
				this->searchTextBox->ForeColor = System::Drawing::Color::White;

				this->label4->BackColor = System::Drawing::SystemColors::WindowFrame;
				this->label4->ForeColor = System::Drawing::Color::White;

				this->label5->BackColor = System::Drawing::SystemColors::WindowFrame;
				this->label5->ForeColor = System::Drawing::Color::White;

				this->ExitButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
				this->ExitButton->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));

				this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
				this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));

				this->headerLabel->BackColor = System::Drawing::SystemColors::WindowFrame;	

				this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
				this->label3->ForeColor = System::Drawing::Color::White;
				
				this->deadlineBG->BackColor = System::Drawing::Color::WhiteSmoke;
				this->deadlineListView->BackColor = System::Drawing::Color::WhiteSmoke;
				this->listViewDisplay->BackColor = System::Drawing::Color::WhiteSmoke;
				this->InputTextBox->BackColor = System::Drawing::Color::WhiteSmoke;
				this->label1->ForeColor = System::Drawing::SystemColors::ControlDark;

				this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));

				/*Help page color*/
				helpPage->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
				helpLabel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
				helpLabel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
				helpLabel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
				helpLabel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
				helpLabel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
				helpLabel6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
				helpLabel10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
				helpLabel11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
				helpLabel12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
				helpLabel13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
				helpLabel14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
				helpLabel15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
				helpLabel16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
				helpPageClose->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));

		 }

/*CHANGE COLOR THEME TO BLUE*/
private: System::Void blueTheme_Click(System::Object^  sender, System::EventArgs^  e) {

				this->chosenColor = System::Drawing::Color::Teal;
				this->chosenBGColor = System::Drawing::Color::WhiteSmoke;

				deadlineListView->Items->Clear();
				PrintDeadline();
			 
				this->feedbackLabel->BackColor = System::Drawing::Color::Teal;
				this->feedbackLabel->ForeColor = System::Drawing::Color::White;

				this->label2->BackColor = System::Drawing::Color::DarkSlateGray;

				this->helloLabel->BackColor = System::Drawing::Color::White;
				this->helloLabel->ForeColor = System::Drawing::Color::Teal;

				this->welcomeMsgLabel->BackColor = System::Drawing::Color::White;
				this->welcomeMsgLabel->ForeColor = System::Drawing::Color::Teal;

				this->TodayIsLabel->BackColor = System::Drawing::Color::White;
				this->TodayIsLabel->ForeColor = System::Drawing::Color::Teal;

				this->TodayDateTextbox->BackColor = System::Drawing::Color::White;
				this->TodayDateTextbox->ForeColor = System::Drawing::Color::Teal;

				this->displayTypeTexbox->BackColor = System::Drawing::Color::Teal;
				this->displayTypeTexbox->ForeColor = System::Drawing::Color::White;

				this->searchTextBox->BackColor = System::Drawing::Color::DarkCyan;
				this->searchTextBox->ForeColor = System::Drawing::Color::White;

				this->label4->BackColor = System::Drawing::Color::DarkCyan;
				this->label4->ForeColor = System::Drawing::Color::White;

				this->label5->BackColor = System::Drawing::Color::DarkCyan;
				this->label5->ForeColor = System::Drawing::Color::White;

				this->ExitButton->BackColor = System::Drawing::Color::Teal;
				this->ExitButton->ForeColor = System::Drawing::Color::White;

				this->button1->BackColor = System::Drawing::Color::Teal;
				this->button1->ForeColor = System::Drawing::Color::White;

				this->headerLabel->BackColor = System::Drawing::Color::DarkSlateGray;	

				this->label3->BackColor = System::Drawing::Color::Teal;
				this->label3->ForeColor = System::Drawing::Color::White;
				
				this->deadlineBG->BackColor = System::Drawing::Color::WhiteSmoke;
				this->deadlineListView->BackColor = System::Drawing::Color::WhiteSmoke;
				this->listViewDisplay->BackColor = System::Drawing::Color::WhiteSmoke;
				this->InputTextBox->BackColor = System::Drawing::Color::WhiteSmoke;
				this->label1->ForeColor = System::Drawing::Color::White;

				this->BackColor = System::Drawing::Color::Teal;

				/*Help page color*/
				helpPage->BackColor = System::Drawing::Color::Teal;
				helpLabel1->BackColor = System::Drawing::Color::Teal;
				helpLabel2->BackColor = System::Drawing::Color::Teal;
				helpLabel3->BackColor = System::Drawing::Color::Teal;
				helpLabel4->BackColor = System::Drawing::Color::Teal;
				helpLabel5->BackColor = System::Drawing::Color::Teal;
				helpLabel6->BackColor = System::Drawing::Color::Teal;
				helpLabel10->BackColor = System::Drawing::Color::Teal;
				helpLabel11->BackColor = System::Drawing::Color::Teal;
				helpLabel12->BackColor = System::Drawing::Color::Teal;
				helpLabel13->BackColor = System::Drawing::Color::Teal;
				helpLabel14->BackColor = System::Drawing::Color::Teal;
				helpLabel15->BackColor = System::Drawing::Color::Teal;
				helpLabel16->BackColor = System::Drawing::Color::Teal;
				helpPageClose->BackColor = System::Drawing::Color::Teal;

		 }

/*HELP BUTTON -> DISPLAY AND CLOSE HELP PAGE WHEN CLICKED*/
private: System::Void helpButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 if (helpDisplayed == false)
				 displayHelp();
			 else if (helpDisplayed == true)
				 closeHelp();			 

		 }

/*DISPLAY HELP PAGE*/
private: System::Void displayHelp() {

			 helpPage->BringToFront();
			 helpLabel1->BringToFront();
			 helpLabel2->BringToFront();
			 helpLabel3->BringToFront();
			 helpLabel4->BringToFront();
			 helpLabel5->BringToFront();
			 helpLabel6->BringToFront();
			 helpLabel10->BringToFront();
			 helpLabel11->BringToFront();
			 helpLabel12->BringToFront();
			 helpLabel13->BringToFront();
			 helpLabel14->BringToFront();
			 helpLabel15->BringToFront();
			 helpLabel16->BringToFront();
			 helpPageClose->BringToFront();

			 helpDisplayed = true;

		 }

/*CLOSE HELP PAGE WHEN CLICKED*/
private: System::Void helpPageClose_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 closeHelp();
			 
		 }

/*CLOSE HELP PAGE*/
private: System::Void closeHelp() {

			 helpLabel1->SendToBack();
			 helpLabel2->SendToBack();
			 helpLabel3->SendToBack();
			 helpLabel4->SendToBack();
			 helpLabel5->SendToBack();
			 helpLabel6->SendToBack();
			 helpLabel10->SendToBack();
			 helpLabel11->SendToBack();
			 helpLabel12->SendToBack();
			 helpLabel13->SendToBack();
			 helpLabel14->SendToBack();
			 helpLabel15->SendToBack();
			 helpLabel16->SendToBack();
			 helpPageClose->SendToBack();
			 helpPage->SendToBack();

			 helpDisplayed = false;

		 }


/*HOT KEY CODES*/
private: System::Void ConstanGUI_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			
			 /*F1 for help*/
			if (e->KeyCode == Keys::F1) {

				if (helpDisplayed == false)
				 displayHelp();
				else if (helpDisplayed == true)
				 closeHelp();
			}

			/*CTRL+F for search*/
			if (e->Control && e->KeyCode == Keys::F) {
				searchTextBox->Select();
				e->SuppressKeyPress = true;
				return;
			}

			/*CTRL+F for undo*/
			if (e->Control && e->KeyCode == Keys::Z) {
				feedbackLabel->Text = "";
				listViewDisplay->Items->Clear(); 
					  
					  string undo = "undo";
					  //convert to std string
					  command = undo;
					  userInterface.processUserInput(command);
					  Print();
					  PrintDisplayType();
					  PrintFeedback();
			}

			/*CTRL+ENTER to enter command*/
			if (e->Control && e->KeyCode == Keys::Enter) {
				InputTextBox->Select();
				e->SuppressKeyPress = true;
				return;
			}			

		 }



};
}

