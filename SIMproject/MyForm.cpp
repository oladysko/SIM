#include "MyForm.h"
#include "Parser.h"
#include "DicomDataAdapter.h"

//included by Marek Kos
#include "GlobalVariables.h"
#include <Vcclr.h>

using namespace System; 
using namespace System::Windows::Forms; 
using namespace System::Drawing;

GlobalVariables *gb; //Dump for all variables shared between functions

[STAThread]
void Main(array<String^>^ args) 
{ 
	srand(time(NULL));
	gb = new GlobalVariables();
	Application::EnableVisualStyles(); 
	Application::SetCompatibleTextRenderingDefault(false); 
	SIMproject::MyForm form;
	Application::Run(%form); 
} 

namespace SIMproject{
	System::Void MyForm::button1_Click(System::Object^  sender, System::EventArgs^  e) {

		//unsigned int frameNumber;
		String^ debugInfo;
		array<System::String^>^ fileNames;
		std::string stdFileName;
		palette_choice->SelectedItem = 0;
		palette_choice->Enabled = true;
		

		try
		{
			//get file
			OpenFileDialog^ dlg = gcnew OpenFileDialog();
			dlg->Multiselect = true; 
			dlg->ShowDialog();
			fileNames = dlg->FileNames;
		}
		catch (Exception^ errorHandle){
			this->Info_label->Text = errorHandle->Message;
			return;
		}
		
		//gb->vh->setFps(25);
		//gb->vh->setTotalLength(20);
		textBox1->Text = "25";
		textBox2->Text = "5";
		textBox3->Text = "1";

		DicomDataAdapter dicomData = DicomDataAdapter::DicomDataAdapter(gb->vh);
		
		for (int i = 0; i < fileNames->GetLength(0); i++)
		{
		//Przyklad skradziony z MSDN
		// Pin memory so GC can't move it while native function is called
		pin_ptr<const wchar_t> wch = PtrToStringChars(fileNames[i]);
		
		size_t convertedChars = 0;
		size_t  sizeInBytes = ((fileNames[i]->Length + 1) * 2);
		errno_t err = 0;
		char    *ch = (char *)malloc(sizeInBytes);

		err = wcstombs_s(&convertedChars,ch, sizeInBytes,wch, sizeInBytes);
		if (err != 0)
			//gui sie powinno rzucic tu ze podalismy nielegalne znaki w nazwie pliku
			return;

			dicomData.loadImage(ch);
		}
		gb->vh->sort();
		gb->vh->getSize(gb->bitmapWidth, gb->bitmapHeight);
		this->dicomImage = gcnew Bitmap(gb->bitmapHeight, gb->bitmapWidth, Imaging::PixelFormat::Format24bppRgb);

		this->Info_label->Text = gb->bitmapWidth + " " + gb->bitmapHeight;
		
		//vh->getCurrentMinMax(min,max); //pelna dynamika kazdej klatki. falszuje informacje miedzy obrazami
		gb->vh->getGlobalMinMax(gb->min, gb->max);  //nie pelna dynamika klatek. Prawdziwe relacje miedzy barwami w roznych klatkach
		gb->cp->setMinMax(gb->min, gb->max);
		int* frame = gb->vh->getThisFrame();

		ParserH::getBitmap(gb->bitmapWidth, gb->bitmapHeight, this->dicomImage, frame, gb->min, gb->max, gb->cp);
		reverser->Checked = gb->vh->getCurrentState();

		//display picture
		if ((double)gb->bitmapHeight / pictureBox1->Height>(double)gb->bitmapWidth / pictureBox1->Width)
			pictureBox1->Image = gcnew Bitmap(this->dicomImage, pictureBox1->Height, pictureBox1->Height*gb->bitmapWidth / gb->bitmapHeight);
		else
			pictureBox1->Image = gcnew Bitmap(this->dicomImage, pictureBox1->Width*gb->bitmapHeight / gb->bitmapWidth, pictureBox1->Width);

		gb->active = true;
	}

	System::Void MyForm::next_Click(System::Object^  sender, System::EventArgs^  e) {
		
		int* frame;

		if (gb->vh->moveToNextFrame())
		{
			next->ForeColor = System::Drawing::Color::Red;

		}
			else {
				frame = gb->vh->getThisFrame();

				gb->vh->getSize(gb->bitmapWidth, gb->bitmapHeight);
				this->dicomImage = gcnew Bitmap(gb->bitmapHeight, gb->bitmapWidth, Imaging::PixelFormat::Format24bppRgb);
				ParserH::getBitmap(gb->bitmapWidth, gb->bitmapHeight, this->dicomImage, frame, gb->min, gb->max, gb->cp);
				back->ForeColor = System::Drawing::Color::Black;
				next->ForeColor = System::Drawing::Color::Black;

				//display picture
				if ((double)gb->bitmapHeight / pictureBox1->Height>(double)gb->bitmapWidth / pictureBox1->Width)
					pictureBox1->Image = gcnew Bitmap(this->dicomImage, pictureBox1->Height, pictureBox1->Height*gb->bitmapWidth / gb->bitmapHeight);
				else
					pictureBox1->Image = gcnew Bitmap(this->dicomImage, pictureBox1->Width*gb->bitmapHeight / gb->bitmapWidth, pictureBox1->Width);
				reverser->Checked = gb->vh->getCurrentState();
			}
	}

	System::Void MyForm::back_Click_1(System::Object^  sender, System::EventArgs^  e) {
		
		int* frame;

		if ((gb->vh->moveToPrevFrame()))
		{
			back->ForeColor = System::Drawing::Color::Red;
		}
		else
		{
			frame = gb->vh->getThisFrame();
			gb->vh->getSize(gb->bitmapWidth, gb->bitmapHeight);
			this->dicomImage = gcnew Bitmap(gb->bitmapHeight, gb->bitmapWidth, Imaging::PixelFormat::Format24bppRgb);
			ParserH::getBitmap(gb->bitmapWidth, gb->bitmapHeight, this->dicomImage, frame, gb->min, gb->max, gb->cp);
			reverser->Checked = gb->vh->getCurrentState();
			next->ForeColor = System::Drawing::Color::Black;
			back->ForeColor = System::Drawing::Color::Black;

			//display picture
			if ((double)gb->bitmapHeight / pictureBox1->Height>(double)gb->bitmapWidth / pictureBox1->Width)
				pictureBox1->Image = gcnew Bitmap(this->dicomImage, pictureBox1->Height, pictureBox1->Height*gb->bitmapWidth / gb->bitmapHeight);
			else
				pictureBox1->Image = gcnew Bitmap(this->dicomImage, pictureBox1->Width*gb->bitmapHeight / gb->bitmapWidth, pictureBox1->Width);
		}
	}
	
	System::Void MyForm::palette_choice_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (gb->active)
		{
			int* frame;
			frame = gb->vh->getThisFrame();
			gb->cp->switchPalette((PaleteName)(palette_choice->SelectedIndex));
			this->dicomImage = gcnew Bitmap(gb->bitmapHeight, gb->bitmapWidth, Imaging::PixelFormat::Format24bppRgb);
			ParserH::getBitmap(gb->bitmapWidth, gb->bitmapHeight, this->dicomImage, frame, gb->min, gb->max, gb->cp);

			//display picture
			if ((double)gb->bitmapHeight / pictureBox1->Height>(double)gb->bitmapWidth / pictureBox1->Width)
				pictureBox1->Image = gcnew Bitmap(this->dicomImage, pictureBox1->Height, pictureBox1->Height*gb->bitmapWidth / gb->bitmapHeight);
			else
				pictureBox1->Image = gcnew Bitmap(this->dicomImage, pictureBox1->Width*gb->bitmapHeight / gb->bitmapWidth, pictureBox1->Width);
		}
	}

	
	System::Void MyForm::video_maker_Click(System::Object^  sender, System::EventArgs^  e)
	{
		try
		{
		
			std::string stdFileName;
			String^ fileName;

			Double fpsValue = Convert::ToDouble(this->textBox1->Text);
			Double lenghtValue = Convert::ToDouble(this->textBox2->Text);
			Double scale = Convert::ToDouble(this->textBox3->Text);

			if (fpsValue != 0)
			{
				gb->vh->setFps(fpsValue);
			}

			if (lenghtValue != 0)
			{
				gb->vh->setTotalLength(lenghtValue);
			}

			if (scale != 0)
			{
				gb->vh->setScale(scale);
			}

			try
			{
				//get file
				SaveFileDialog^ svdlg = gcnew SaveFileDialog();
				svdlg->ShowDialog();
				fileName = svdlg->FileName;
			}
			catch (Exception^ errorHandle){
				this->Info_label->Text = errorHandle->Message;
				return;
			}

			
			//Przyklad skradziony z MSDN
			pin_ptr<const wchar_t> wch = PtrToStringChars(fileName);
			size_t convertedChars = 0;
			size_t  sizeInBytes = ((fileName->Length + 1) * 2);
			errno_t err = 0;
				
			char *fileName2 = (char *)malloc(sizeInBytes);
			err = wcstombs_s(&convertedChars, fileName2, sizeInBytes, wch, sizeInBytes);
	
			gb->vh->video_encode(fileName2, AV_CODEC_ID_MPEG4);
			this->Info_label->Text = "finished creating a video";
		}
		catch (Exception^ e)
		{
			this->Info_label->Text = "Settings are incorrect";
		}
	}
	
	System::Void MyForm::reverser_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		gb->vh->setCurrentState(reverser->Checked);
	}

}

