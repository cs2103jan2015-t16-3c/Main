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
	private: System::Windows::Forms::Label^  label3;
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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// InputTextBox
			// 
			this->InputTextBox->BackColor = System::Drawing::Color::White;
			this->InputTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->InputTextBox->Font = (gcnew System::Drawing::Font(L"Open Sans", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->InputTextBox->ForeColor = System::Drawing::Color::Black;
			this->InputTextBox->Location = System::Drawing::Point(169, 433);
			this->InputTextBox->Name = L"InputTextBox";
			this->InputTextBox->Size = System::Drawing::Size(608, 25);
			this->InputTextBox->TabIndex = 7;
			this->InputTextBox->TextChanged += gcnew System::EventHandler(this, &ConstanGUI::InputTextBox_TextChanged);
			this->InputTextBox->DoubleClick += gcnew System::EventHandler(this, &ConstanGUI::InputTextBox_DoubleClick);
			this->InputTextBox->Enter += gcnew System::EventHandler(this, &ConstanGUI::InputTextBox_Enter);
			this->InputTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ConstanGUI::InputTextBox_KeyPress_1);
			// 
			// listViewDisplay
			// 
			this->listViewDisplay->BackColor = System::Drawing::Color::White;
			this->listViewDisplay->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->listViewDisplay->CheckBoxes = true;
			this->listViewDisplay->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(6) {this->taskHeader, 
				this->startDateHeader, this->startTimeHeader, this->endDateHeader, this->endTimeHeader, this->taskIndex});
			this->listViewDisplay->Font = (gcnew System::Drawing::Font(L"Calibri", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->listViewDisplay->FullRowSelect = true;
			this->listViewDisplay->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->listViewDisplay->Location = System::Drawing::Point(37, 95);
			this->listViewDisplay->Name = L"listViewDisplay";
			this->listViewDisplay->Size = System::Drawing::Size(740, 303);
			this->listViewDisplay->TabIndex = 6;
			this->listViewDisplay->UseCompatibleStateImageBehavior = false;
			this->listViewDisplay->View = System::Windows::Forms::View::Details;
			// 
			// taskHeader
			// 
			this->taskHeader->DisplayIndex = 1;
			this->taskHeader->Text = L"Task";
			this->taskHeader->Width = 366;
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
			this->startTimeHeader->Width = 75;
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
			this->endTimeHeader->Width = 75;
			// 
			// taskIndex
			// 
			this->taskIndex->DisplayIndex = 0;
			this->taskIndex->Text = L"Id.";
			this->taskIndex->Width = 35;
			// 
			// feedbackLabel
			// 
			this->feedbackLabel->Font = (gcnew System::Drawing::Font(L"Calibri Light", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->feedbackLabel->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->feedbackLabel->Location = System::Drawing::Point(168, 407);
			this->feedbackLabel->Name = L"feedbackLabel";
			this->feedbackLabel->Size = System::Drawing::Size(608, 23);
			this->feedbackLabel->TabIndex = 8;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->label1->Location = System::Drawing::Point(167, 463);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(281, 15);
			this->label1->TabIndex = 9;
			this->label1->Text = L"add / display / edit / delete / mark / unmark / search";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Calibri", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(34, 431);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(128, 21);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Enter Command:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Calibri", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label3->Location = System::Drawing::Point(30, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(269, 73);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Hello Jim.";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Calibri", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::Desktop;
			this->label4->Location = System::Drawing::Point(43, 70);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(145, 18);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Welcome to CONSTAN";
			// 
			// ConstanGUI
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(813, 510);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->feedbackLabel);
			this->Controls->Add(this->InputTextBox);
			this->Controls->Add(this->listViewDisplay);
			this->Controls->Add(this->label3);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->Name = L"ConstanGUI";
			this->Text = L"CONSTAN - your trusty task manager";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

private: System::Void InputTextBox_KeyPress_1(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 /*
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
			 */
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

					  if (command == "exit") {
						return; //HOW TO EXIT PROGRAM???
					  }

					  //pass command to TextUI.h class to be passed to logic and then processed
					  userInterface.processUserInput(command);
					  Print();

					  /*
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

						  /*INDEX*
						  taskIndex = System::Convert::ToString(index);
						  index++;

						  /*TITLE*
						  frontTask = endTask + 1;
						  //extract the task title
						  endTask = stdDisplayResult.find_first_of("]", frontTask);
						  stdTaskComponent = stdDisplayResult.substr(frontTask, endTask-frontTask);
						  //convert to std string
						  taskComponent = gcnew String(stdTaskComponent.c_str());
						  //add into a system string object
						  taskTitle = taskComponent;

						  /*START DATE*
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

						  /*START TIME*
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

						  /*END DATE*
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

						  /*END TIME*
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

						  /*MARK/UNMARKED*
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
						*/
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
/*
//function run when the user tick/unticked the checkbox
//take in the index displayed as string and 
private: System::Void listViewDisplay_ItemChecked(System::Object^  sender, System::Windows::Forms::ItemCheckedEventArgs^  e) {
			 
			 feedbackLabel->Text = "";
			 //clear the display box first
			 listViewDisplay->Items->Clear(); 

			 size_t displayIndex;
			 ListViewItem^ selItem = e->Item;

			 String^ txt = selItem->SubItems[5]->Text;
			 string index = msclr::interop::marshal_as < std::string > (txt); 
			 
			 if(e->Item->Checked) {
				 userInterface.processUserInput("unmark" + index);
			 } else if(e->Item->Checked == 0) {
				 userInterface.processUserInput("mark" + index);
			 }

			 Print();
		 }
 */ //wait until command mark is implemented
};
}

