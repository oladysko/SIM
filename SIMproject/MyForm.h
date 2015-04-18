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
	private: System::Windows::Forms::Button^  saveCurrent;
			 /// </summary>
			 System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
			 void InitializeComponent(void)
			 {
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
				 this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				 this->ViewImage = (gcnew System::Windows::Forms::Button());
				 this->frame_textBox = (gcnew System::Windows::Forms::TextBox());
				 this->Debug_label = (gcnew System::Windows::Forms::Label());
				 this->Info_label = (gcnew System::Windows::Forms::Label());
				 this->label_FrameNumber = (gcnew System::Windows::Forms::Label());
				 this->saveCurrent = (gcnew System::Windows::Forms::Button());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // pictureBox1
				 // 
				 this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
				 this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
				 this->pictureBox1->Location = System::Drawing::Point(13, 13);
				 this->pictureBox1->Name = L"pictureBox1";
				 this->pictureBox1->Size = System::Drawing::Size(535, 501);
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
				 // saveCurrent
				 // 
				 this->saveCurrent->Location = System::Drawing::Point(555, 106);
				 this->saveCurrent->Name = L"saveCurrent";
				 this->saveCurrent->Size = System::Drawing::Size(112, 33);
				 this->saveCurrent->TabIndex = 6;
				 this->saveCurrent->Text = L"save current pic";
				 this->saveCurrent->UseVisualStyleBackColor = true;
				 this->saveCurrent->Click += gcnew System::EventHandler(this, &MyForm::saveCurrent_Click);
				 // 
				 // MyForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(803, 526);
				 this->Controls->Add(this->saveCurrent);
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
		private: System::Void saveCurrent_Click(System::Object^  sender, System::EventArgs^  e);// {
	};
}
