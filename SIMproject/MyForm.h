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
	private: System::Windows::Forms::TextBox^  frame_textBox;
	private: System::Windows::Forms::Label^  Debug_label;
	private: System::Windows::Forms::Label^  Info_label;
	private: System::Windows::Forms::Label^  label_FrameNumber;


	protected:


	private:
		Bitmap ^ dicomImage; //IS CAUSNG MEMORY LEAKING????=================================
	private: System::Windows::Forms::Button^  next;

	private: System::Windows::Forms::Button^  back;
	private: System::Windows::Forms::Button^  video_maker;
	private: System::Windows::Forms::CheckBox^  reverser;
	private: System::Windows::Forms::ComboBox^  palette_choice;



			 /// </summary>
			 System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
			 void InitializeComponent(void)
			 {
				 this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				 this->ViewImage = (gcnew System::Windows::Forms::Button());
				 this->frame_textBox = (gcnew System::Windows::Forms::TextBox());
				 this->Debug_label = (gcnew System::Windows::Forms::Label());
				 this->Info_label = (gcnew System::Windows::Forms::Label());
				 this->label_FrameNumber = (gcnew System::Windows::Forms::Label());
				 this->next = (gcnew System::Windows::Forms::Button());
				 this->back = (gcnew System::Windows::Forms::Button());
				 this->video_maker = (gcnew System::Windows::Forms::Button());
				 this->reverser = (gcnew System::Windows::Forms::CheckBox());
				 this->palette_choice = (gcnew System::Windows::Forms::ComboBox());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // pictureBox1
				 // 
				 this->pictureBox1->InitialImage = nullptr;
				 this->pictureBox1->Location = System::Drawing::Point(13, 13);
				 this->pictureBox1->Name = L"pictureBox1";
				 this->pictureBox1->Size = System::Drawing::Size(466, 410);
				 this->pictureBox1->TabIndex = 0;
				 this->pictureBox1->TabStop = false;
				 this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
				 // 
				 // ViewImage
				 // 
				 this->ViewImage->Location = System::Drawing::Point(555, 46);
				 this->ViewImage->Name = L"ViewImage";
				 this->ViewImage->Size = System::Drawing::Size(112, 31);
				 this->ViewImage->TabIndex = 1;
				 this->ViewImage->Text = L"View Image";
				 this->ViewImage->UseVisualStyleBackColor = true;
				 this->ViewImage->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
				 // 
				 // frame_textBox
				 // 
				 this->frame_textBox->Location = System::Drawing::Point(673, 57);
				 this->frame_textBox->Name = L"frame_textBox";
				 this->frame_textBox->Size = System::Drawing::Size(100, 20);
				 this->frame_textBox->TabIndex = 2;
				 this->frame_textBox->Text = L"0";
				 this->frame_textBox->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
				 // 
				 // Debug_label
				 // 
				 this->Debug_label->AutoSize = true;
				 this->Debug_label->Location = System::Drawing::Point(552, 343);
				 this->Debug_label->Name = L"Debug_label";
				 this->Debug_label->Size = System::Drawing::Size(42, 13);
				 this->Debug_label->TabIndex = 3;
				 this->Debug_label->Text = L"Debug:";
				 // 
				 // Info_label
				 // 
				 this->Info_label->AutoSize = true;
				 this->Info_label->Location = System::Drawing::Point(558, 376);
				 this->Info_label->Name = L"Info_label";
				 this->Info_label->Size = System::Drawing::Size(25, 13);
				 this->Info_label->TabIndex = 4;
				 this->Info_label->Text = L"Info";
				 // 
				 // label_FrameNumber
				 // 
				 this->label_FrameNumber->AutoSize = true;
				 this->label_FrameNumber->Location = System::Drawing::Point(674, 38);
				 this->label_FrameNumber->Name = L"label_FrameNumber";
				 this->label_FrameNumber->Size = System::Drawing::Size(79, 13);
				 this->label_FrameNumber->TabIndex = 5;
				 this->label_FrameNumber->Text = L"Frame Number:";
				 this->label_FrameNumber->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
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
				 this->video_maker->Location = System::Drawing::Point(555, 104);
				 this->video_maker->Name = L"video_maker";
				 this->video_maker->Size = System::Drawing::Size(112, 38);
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
				 this->palette_choice->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
					 L"GREYSCALE", L"RAINBOW", L"SYMMETRIC", L"JET",
						 L"STAR", L"GREENSTAR", L"HOTRANDOM", L"COLDRANDOM", L"RANDOM"
				 });
				 this->palette_choice->Location = System::Drawing::Point(557, 171);
				 this->palette_choice->Name = L"palette_choice";
				 this->palette_choice->Size = System::Drawing::Size(109, 21);
				 this->palette_choice->TabIndex = 10;
				 this->palette_choice->Text = L"GREYSCALE";
				 this->palette_choice->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::palette_choice_SelectedIndexChanged);
				 // 
				 // MyForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(803, 526);
				 this->Controls->Add(this->palette_choice);
				 this->Controls->Add(this->reverser);
				 this->Controls->Add(this->video_maker);
				 this->Controls->Add(this->back);
				 this->Controls->Add(this->next);
				 this->Controls->Add(this->label_FrameNumber);
				 this->Controls->Add(this->Info_label);
				 this->Controls->Add(this->Debug_label);
				 this->Controls->Add(this->frame_textBox);
				 this->Controls->Add(this->ViewImage);
				 this->Controls->Add(this->pictureBox1);
				 this->Name = L"MyForm";
				 this->Text = L"MyForm";
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);// {
			 
		private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void next_Click(System::Object^  sender, System::EventArgs^  e);
		private: System::Void back_Click_1(System::Object^  sender, System::EventArgs^  e);
	
		private: System::Void video_maker_Click(System::Object^  sender, System::EventArgs^  e);

		private: System::Void reverser_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

		private: System::Void palette_choice_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);

};
}
