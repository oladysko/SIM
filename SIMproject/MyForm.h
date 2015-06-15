#pragma once

#include <iostream>
#include "Parser.h"

namespace SIMproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  ViewImage;

	private: System::Windows::Forms::Label^  Debug_label;
	private: System::Windows::Forms::Label^  Info_label;



	protected:


	private:
		Bitmap ^ dicomImage; //IS CAUSNG MEMORY LEAKING????=================================
	private: System::Windows::Forms::Button^  next;

	private: System::Windows::Forms::Button^  back;
	private: System::Windows::Forms::Button^  video_maker;
	private: System::Windows::Forms::CheckBox^  reverser;
	private: System::Windows::Forms::ComboBox^  palette_choice;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox3;




	private: System::Windows::Forms::Label^  label1;


	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;



			 /// </summary>
			 System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
			 void InitializeComponent(void)
			 {
				 this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				 this->ViewImage = (gcnew System::Windows::Forms::Button());
				 this->Debug_label = (gcnew System::Windows::Forms::Label());
				 this->Info_label = (gcnew System::Windows::Forms::Label());
				 this->next = (gcnew System::Windows::Forms::Button());
				 this->back = (gcnew System::Windows::Forms::Button());
				 this->video_maker = (gcnew System::Windows::Forms::Button());
				 this->reverser = (gcnew System::Windows::Forms::CheckBox());
				 this->palette_choice = (gcnew System::Windows::Forms::ComboBox());
				 this->textBox1 = (gcnew System::Windows::Forms::TextBox());
				 this->textBox3 = (gcnew System::Windows::Forms::TextBox());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->textBox2 = (gcnew System::Windows::Forms::TextBox());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // pictureBox1
				 // 
				 this->pictureBox1->InitialImage = nullptr;
				 this->pictureBox1->Location = System::Drawing::Point(30, 0);
				 this->pictureBox1->Name = L"pictureBox1";
				 this->pictureBox1->Size = System::Drawing::Size(466, 410);
				 this->pictureBox1->TabIndex = 0;
				 this->pictureBox1->TabStop = false;
				 // 
				 // ViewImage
				 // 
				 this->ViewImage->Location = System::Drawing::Point(586, 86);
				 this->ViewImage->Name = L"ViewImage";
				 this->ViewImage->Size = System::Drawing::Size(112, 31);
				 this->ViewImage->TabIndex = 1;
				 this->ViewImage->Text = L"View Image";
				 this->ViewImage->UseVisualStyleBackColor = true;
				 this->ViewImage->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
				 // 
				 // Debug_label
				 // 
				 this->Debug_label->AutoSize = true;
				 this->Debug_label->Location = System::Drawing::Point(583, 401);
				 this->Debug_label->Name = L"Debug_label";
				 this->Debug_label->Size = System::Drawing::Size(42, 13);
				 this->Debug_label->TabIndex = 3;
				 this->Debug_label->Text = L"Debug:";
				 // 
				 // Info_label
				 // 
				 this->Info_label->AutoSize = true;
				 this->Info_label->Location = System::Drawing::Point(583, 414);
				 this->Info_label->Name = L"Info_label";
				 this->Info_label->Size = System::Drawing::Size(25, 13);
				 this->Info_label->TabIndex = 4;
				 this->Info_label->Text = L"Info";
				 // 
				 // next
				 // 
				 this->next->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18.25F));
				 this->next->Location = System::Drawing::Point(324, 429);
				 this->next->Name = L"next";
				 this->next->Size = System::Drawing::Size(57, 53);
				 this->next->TabIndex = 6;
				 this->next->Text = L">";
				 this->next->UseVisualStyleBackColor = true;
				 this->next->Click += gcnew System::EventHandler(this, &MyForm::next_Click);
				 // 
				 // back
				 // 
				 this->back->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18.25F));
				 this->back->Location = System::Drawing::Point(147, 429);
				 this->back->Name = L"back";
				 this->back->Size = System::Drawing::Size(57, 53);
				 this->back->TabIndex = 7;
				 this->back->Text = L"<";
				 this->back->UseVisualStyleBackColor = true;
				 this->back->Click += gcnew System::EventHandler(this, &MyForm::back_Click_1);
				 // 
				 // video_maker
				 // 
				 this->video_maker->Location = System::Drawing::Point(586, 123);
				 this->video_maker->Name = L"video_maker";
				 this->video_maker->Size = System::Drawing::Size(112, 30);
				 this->video_maker->TabIndex = 8;
				 this->video_maker->Text = L"Make video";
				 this->video_maker->UseVisualStyleBackColor = true;
				 this->video_maker->Click += gcnew System::EventHandler(this, &MyForm::video_maker_Click);
				 // 
				 // reverser
				 // 
				 this->reverser->AutoSize = true;
				 this->reverser->Location = System::Drawing::Point(252, 453);
				 this->reverser->Name = L"reverser";
				 this->reverser->Size = System::Drawing::Size(15, 14);
				 this->reverser->TabIndex = 9;
				 this->reverser->UseVisualStyleBackColor = true;
				 this->reverser->CheckedChanged += gcnew System::EventHandler(this, &MyForm::reverser_CheckedChanged);
				 // 
				 // palette_choice
				 // 
				 this->palette_choice->Enabled = false;
				 this->palette_choice->FormattingEnabled = true;
				 this->palette_choice->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
					 L"GREYSCALE,", L"RGB", L"BGR", L"JET", L"SYMMETRIC",
						 L"STAR", L"GREENSTAR", L"HOTRANDOM", L"COLDRANDOM", L"RANDOM"
				 });
				 this->palette_choice->Location = System::Drawing::Point(589, 172);
				 this->palette_choice->Name = L"palette_choice";
				 this->palette_choice->Size = System::Drawing::Size(109, 21);
				 this->palette_choice->TabIndex = 10;
				 this->palette_choice->Text = L"GREYSCALE";
				 this->palette_choice->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::palette_choice_SelectedIndexChanged);
				 // 
				 // textBox1
				 // 
				 this->textBox1->Location = System::Drawing::Point(586, 254);
				 this->textBox1->Name = L"textBox1";
				 this->textBox1->Size = System::Drawing::Size(112, 20);
				 this->textBox1->TabIndex = 11;
				 // 
				 // textBox3
				 // 
				 this->textBox3->Location = System::Drawing::Point(586, 324);
				 this->textBox3->Name = L"textBox3";
				 this->textBox3->Size = System::Drawing::Size(112, 20);
				 this->textBox3->TabIndex = 13;
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Location = System::Drawing::Point(552, 261);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(27, 13);
				 this->label1->TabIndex = 18;
				 this->label1->Text = L"FPS";
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->Location = System::Drawing::Point(542, 331);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(37, 13);
				 this->label4->TabIndex = 21;
				 this->label4->Text = L"Scale:";
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Location = System::Drawing::Point(517, 287);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(63, 13);
				 this->label2->TabIndex = 23;
				 this->label2->Text = L"Total length";
				 // 
				 // textBox2
				 // 
				 this->textBox2->Location = System::Drawing::Point(586, 280);
				 this->textBox2->Name = L"textBox2";
				 this->textBox2->Size = System::Drawing::Size(112, 20);
				 this->textBox2->TabIndex = 22;
				 // 
				 // MyForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(803, 526);
				 this->Controls->Add(this->label2);
				 this->Controls->Add(this->textBox2);
				 this->Controls->Add(this->label4);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->textBox3);
				 this->Controls->Add(this->textBox1);
				 this->Controls->Add(this->palette_choice);
				 this->Controls->Add(this->reverser);
				 this->Controls->Add(this->video_maker);
				 this->Controls->Add(this->back);
				 this->Controls->Add(this->next);
				 this->Controls->Add(this->Info_label);
				 this->Controls->Add(this->Debug_label);
				 this->Controls->Add(this->ViewImage);
				 this->Controls->Add(this->pictureBox1);
				 this->Name = L"MyForm";
				 this->Text = L"MyForm";
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);			 

		private: System::Void next_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void back_Click_1(System::Object^  sender, System::EventArgs^  e);
		private: System::Void video_maker_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void reverser_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
		private: System::Void palette_choice_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);

};
}
