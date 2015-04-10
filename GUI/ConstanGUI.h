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

	string command, feedback, stdDisplayResult, stdTaskComponent;

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
			System::Windows::Forms::ListViewItem^  listViewItem1 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::Windows::Forms::ListViewItem::ListViewSubItem^  >(2) {(gcnew System::Windows::Forms::ListViewItem::ListViewSubItem(nullptr, 
				L"tutorial", System::Drawing::Color::DimGray, System::Drawing::Color::WhiteSmoke, (gcnew System::Drawing::Font(L"Calibri", 
				9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0))))), (gcnew System::Windows::Forms::ListViewItem::ListViewSubItem(nullptr, 
				L"today", System::Drawing::Color::Gray, System::Drawing::Color::WhiteSmoke, (gcnew System::Drawing::Font(L"Calibri", 
				9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)))))}, -1));
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
			this->SuspendLayout();
			// 
			// InputTextBox
			// 
			this->InputTextBox->BackColor = System::Drawing::Color::WhiteSmoke;
			this->InputTextBox->Font = (gcnew System::Drawing::Font(L"Open Sans", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->InputTextBox->ForeColor = System::Drawing::Color::Black;
			this->InputTextBox->Location = System::Drawing::Point(509, 508);
			this->InputTextBox->Name = L"InputTextBox";
			this->InputTextBox->Size = System::Drawing::Size(468, 25);
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
			this->startDateHeader->Width = 80;
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
			this->endDateHeader->Width = 80;
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
			this->feedbackLabel->UseMnemonic = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->label1->Location = System::Drawing::Point(517, 536);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(281, 15);
			this->label1->TabIndex = 9;
			this->label1->Text = L"add / display / edit / delete / mark / unmark / search";
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->label2->Font = (gcnew System::Drawing::Font(L"Calibri", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(304, 508);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(196, 25);
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
			this->headerLabel->Location = System::Drawing::Point(304, 76);
			this->headerLabel->Name = L"headerLabel";
			this->headerLabel->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->headerLabel->Size = System::Drawing::Size(673, 40);
			this->headerLabel->TabIndex = 14;
			this->headerLabel->Text = L" ID                                                      TASK                    " 
				L"                          START DATE / TIME                     END DATE / TIME " 
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
			this->displayTypeTexbox->Location = System::Drawing::Point(306, 29);
			this->displayTypeTexbox->Name = L"displayTypeTexbox";
			this->displayTypeTexbox->Size = System::Drawing::Size(413, 49);
			this->displayTypeTexbox->TabIndex = 23;
			this->displayTypeTexbox->Text = L"Today\'s task:";
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
			this->TodayDateTextbox->Size = System::Drawing::Size(188, 25);
			this->TodayDateTextbox->TabIndex = 25;
			this->TodayDateTextbox->Text = L"12 March 2015";
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
			listViewItem1->UseItemStyleForSubItems = false;
			this->deadlineListView->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(1) {listViewItem1});
			this->deadlineListView->Location = System::Drawing::Point(53, 258);
			this->deadlineListView->Name = L"deadlineListView";
			this->deadlineListView->Scrollable = false;
			this->deadlineListView->Size = System::Drawing::Size(202, 217);
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
			this->searchTextBox->Text = L"search";
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
			this->label5->Size = System::Drawing::Size(20, 18);
			this->label5->TabIndex = 30;
			this->label5->Text = L"O";
			this->label5->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// greyTheme
			// 
			this->greyTheme->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->greyTheme->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->greyTheme->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->greyTheme->Location = System::Drawing::Point(135, 503);
			this->greyTheme->Name = L"greyTheme";
			this->greyTheme->Size = System::Drawing::Size(30, 30);
			this->greyTheme->TabIndex = 31;
			// 
			// blueTheme
			// 
			this->blueTheme->BackColor = System::Drawing::Color::Teal;
			this->blueTheme->Location = System::Drawing::Point(40, 503);
			this->blueTheme->Name = L"blueTheme";
			this->blueTheme->Size = System::Drawing::Size(30, 30);
			this->blueTheme->TabIndex = 32;
			// 
			// pinkTheme
			// 
			this->pinkTheme->BackColor = System::Drawing::Color::LightCoral;
			this->pinkTheme->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->pinkTheme->Location = System::Drawing::Point(88, 503);
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
			this->deadlineBG->BackColor = System::Drawing::Color::White;
			this->deadlineBG->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->deadlineBG->Location = System::Drawing::Point(40, 253);
			this->deadlineBG->Name = L"deadlineBG";
			this->deadlineBG->Size = System::Drawing::Size(227, 222);
			this->deadlineBG->TabIndex = 35;
			// 
			// ConstanGUI
			// 
			this->AutoScroll = true;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(1000, 562);
			this->Controls->Add(this->pinkTheme);
			this->Controls->Add(this->blueTheme);
			this->Controls->Add(this->greyTheme);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->searchTextBox);
			this->Controls->Add(this->TodayDateTextbox);
			this->Controls->Add(this->TodayIsLabel);
			this->Controls->Add(this->headerLabel);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->ExitButton);
			this->Controls->Add(this->welcomeMsgLabel);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->InputTextBox);
			this->Controls->Add(this->listViewDisplay);
			this->Controls->Add(this->helloLabel);
			this->Controls->Add(this->displayTypeTexbox);
			this->Controls->Add(this->feedbackLabel);
			this->Controls->Add(this->deadlineListView);
			this->Controls->Add(this->deadlineBG);
			this->Controls->Add(this->label3);
			this->Font = (gcnew System::Drawing::Font(L"Calibri", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->Name = L"ConstanGUI";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

private: System::Void InputTextBox_KeyPress_1(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 

			 if (e->KeyChar == /*Keys::Enter*/ (char)13){
				 feedbackLabel->Text = "";
				 //clear the display box first
				 listViewDisplay->Items->Clear(); 
					  
					  String^ userInput;
					  userInput = InputTextBox->Text; //System String
					  //convert to std string
					  command = msclr::interop::marshal_as < std::string > (userInput); 
					 
					  if (command == "clr") {
						//clear screen
						  listViewDisplay->Items->Clear(); 
						return;
					  }

					  if (command == "") {
						return; //HOW TO EXIT PROGRAM???
					  }

					  //pass command to TextUI.h class to be passed to logic and then processed
					  userInterface.processUserInput(command);
					  Print();
//					  PrintDeadline();
					  
					  e->Handled = true;

			 }
					  //MessageBox::Show(input);
					  //TestInput a;
					  //a.userInput = input;
		 }


private: System::Void Print(){


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
					  String^ feedbackStr;
					  String^ taskStatus;

					  //get A STRING of feedback message to be displayed from TextUI
					  feedback = userInterface.showFeedback(); //std string
					  //convert std string to System string

					  //clear the feedback box first, then display feedback
					  feedbackLabel->Text = "";
					  feedbackStr = gcnew String(feedback.c_str());
					  feedbackLabel->Text = feedbackStr;

					  //get A STRING of the tasks list and their details to be displayed from TextUI
					  stdDisplayResult = userInterface.showDisplay(); //std string
					  //convert std string to System string
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
						  endTask = stdDisplayResult.find_first_of("]", frontTask);
						  stdTaskComponent = stdDisplayResult.substr(frontTask, endTask-frontTask);
						  //convert to std string
						  taskComponent = gcnew String(stdTaskComponent.c_str());
						  //add into a system string object
						  taskTitle = taskComponent;

						  /*END DATE*/
						  frontTask = endTask + 1;
						  //extract the task's end date
						  endTask = stdDisplayResult.find_first_of("]", frontTask);
						  stdTaskComponent = stdDisplayResult.substr(frontTask, endTask-frontTask);
						  //convert to std string
						  taskComponent = gcnew String(stdTaskComponent.c_str());
						  taskEndDate = taskComponent;

						  /*END TIME*/
						  frontTask = endTask + 1;
						  //extract the task's start time
						  endTask = stdDisplayResult.find_first_of("]", frontTask);
						  stdTaskComponent = stdDisplayResult.substr(frontTask, endTask-frontTask);
						  //convert to std string
						  taskComponent = gcnew String(stdTaskComponent.c_str());
						  taskEndTime = taskComponent;

						  //CONVERT END DATE TO TODAY OR TOMORROW
						  deadline = taskEndDate + " " + taskEndTime;

						  aListViewItem->UseItemStyleForSubItems = false;
						  aListViewItem = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::Windows::Forms::ListViewItem::ListViewSubItem^  >(2) {(gcnew System::Windows::Forms::ListViewItem::ListViewSubItem(nullptr, 
							taskTitle, chosenColor, System::Drawing::Color::WhiteSmoke, (gcnew System::Drawing::Font(L"Calibri", 
							9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0))))), (gcnew System::Windows::Forms::ListViewItem::ListViewSubItem(nullptr, 
							deadline, System::Drawing::Color::DimGray, System::Drawing::Color::WhiteSmoke, (gcnew System::Drawing::Font(L"Calibri Light", 
							9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)))))}, -1));

						  deadlineListView->Items->Add(this->aListViewItem);

						  count--;

					 }
		 }


private: System::Void InputTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {

			 if(InputTextBox->Text == "add") {
				 feedbackLabel->Text = "add  -t [task name]  -s [start date] [start time]  -e [end date] [end time]";
			 }else if(InputTextBox->Text == "display") {
				 feedbackLabel->Text = "display today/deadlines/schedules/to do"; 
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

private: System::Void InputTextBox_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			 InputTextBox->Clear();
			 feedbackLabel->Text = "Enter command";
		 }


//function run when the user tick/unticked the checkbox
//take in the index displayed as string and 
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

		 }
		 


private: System::Void ExitButton_Click(System::Object^  sender, System::EventArgs^  e) {
			  Application::Exit();
		 }


private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->WindowState = FormWindowState::Minimized;

		 }

private: System::Void pinkTheme_Click(System::Object^  sender, System::EventArgs^  e) {
			 chosenColor = System::Drawing::Color::LightCoral;

			 
				this->feedbackLabel->ForeColor = System::Drawing::Color::Gray;
				this->label2->BackColor = System::Drawing::Color::LightCoral;
				this->helloLabel->BackColor = System::Drawing::Color::LightCoral;
				this->welcomeMsgLabel->BackColor = System::Drawing::Color::LightCoral;

				this->ExitButton->BackColor = System::Drawing::SystemColors::ControlLight;
				this->ExitButton->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
								static_cast<System::Int32>(static_cast<System::Byte>(64)));

				this->button1->BackColor = System::Drawing::SystemColors::ControlLight;
				this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)), 
								static_cast<System::Int32>(static_cast<System::Byte>(64)));

				this->headerLabel->BackColor = System::Drawing::Color::LightCoral;

				this->displayTypeTexbox->BackColor = System::Drawing::SystemColors::ControlLight;
				this->displayTypeTexbox->ForeColor = System::Drawing::Color::DimGray;

				this->TodayIsLabel->BackColor = System::Drawing::Color::LightCoral;
				this->TodayDateTextbox->BackColor = System::Drawing::Color::LightCoral;

				this->searchTextBox->BackColor = System::Drawing::SystemColors::Window;
				this->searchTextBox->ForeColor = System::Drawing::Color::DimGray;

				this->label4->BackColor = System::Drawing::SystemColors::Control;
				this->label4->ForeColor = System::Drawing::Color::DimGray;

				this->label5->BackColor = System::Drawing::Color::White;
				this->label5->ForeColor = System::Drawing::Color::DimGray;

				this->label3->ForeColor = System::Drawing::Color::DimGray;

				this->BackColor = System::Drawing::SystemColors::ControlLight;

		 }
};
}

