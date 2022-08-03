#pragma once
#include <chrono>
#include <thread>
#include<string>

using namespace std::this_thread;
using namespace std::chrono;
namespace animatedsorting {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		
	public:
		MyForm(void)
		{
			InitializeComponent();
			numberofcol = -1;
			
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

	protected:

	protected:

	protected:
	
	private: System::Windows::Forms::Button^ button2;






	private: int numberofcol;



















	








	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::TextBox^ textBox1;

	private:cli::array<Button^, 1>^ arr = gcnew cli::array<Button^, 1>(200);
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;






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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(468, 12);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 57);
			this->button2->TabIndex = 1;
			this->button2->Text = L"animate";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::starttttt);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"bubble sort", L"insertion sort", L"selection sort",
					L"shell sort", L"heap sort", L"quick sort"
			});
			this->comboBox1->Location = System::Drawing::Point(588, 26);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(268, 24);
			this->comboBox1->TabIndex = 22;
			this->comboBox1->Text = L"selection sort";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(8, 0);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(175, 22);
			this->textBox1->TabIndex = 23;
			this->textBox1->Text = L"20";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(878, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(128, 29);
			this->label1->TabIndex = 25;
			this->label1->Text = L"inversions:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(192, 3);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 16);
			this->label2->TabIndex = 26;
			this->label2->Text = L"number of columns";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1530, 524);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button2);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	void changecolor(Button^ s1, Button^ s2,int x)
		{
			if (x == 1)
			{
				s1->BackColor = System::Drawing::Color::Red;
				s2->BackColor = System::Drawing::Color::Red;
				Refresh();
				_sleep(1000/(2*numberofcol));
			}
			if (x == 2)
			{
				s1->BackColor = System::Drawing::Color::Green;
				s2->BackColor = System::Drawing::Color::Green;
				Refresh();
				_sleep(1000/(2*numberofcol));
			}
			if (x == 3)
			{
				s1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
					static_cast<System::Int32>(static_cast<System::Byte>(0)));
				s2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
					static_cast<System::Int32>(static_cast<System::Byte>(0)));
			}
		}
	void move(Button^s1, Button^ s2)
		{
		changecolor(s1, s2, 1);
		System::Drawing::Point x = s1->Location;
		s1->Location = s2->Location;
		s2->Location= x;
		changecolor(s1, s2, 2);
		changecolor(s1, s2, 3);
		}
	void makenewcol(int number, int height)
	{
		int total;
		if (numberofcol <= 70)
			total = 700;
		if (numberofcol > 70 && numberofcol < 100)
			total = 1000;
		if (numberofcol >= 100)
			total = 1500;
		//guyssss do it baliz
		arr[number]= (gcnew System::Windows::Forms::Button());
		arr[number]->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));
		arr[number]->ForeColor = System::Drawing::Color::White;
		arr[number]->Location = System::Drawing::Point(31+number*total/numberofcol, 90);
		arr[number]->Margin = System::Windows::Forms::Padding(4);
		arr[number]->Name = L"col" + char(number);
		int x = 406 * height;
		arr[number]->Size = System::Drawing::Size(total/numberofcol, x);
		arr[number]->TabIndex = number;
		arr[number]->UseVisualStyleBackColor = false;
		arr[number]->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 1.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->Controls->Add(this->arr[number]);


	}
	private: System::Void starttttt(System::Object^ sender, System::EventArgs^ e) {
	 srand(time(0));
	 if (numberofcol != -1)
	 {
		 for (int i = 0; i < numberofcol; i++)
		 {
			 delete arr[i];
		 }

	 }
	 numberofcol = Double::Parse(textBox1->Text);
	 for (int i = 0; i < numberofcol; i++)
	 {
		 makenewcol(i, 1);
	 }
	 Refresh();
	 int total;
	 if (numberofcol <= 70)
		 total = 700;
	 if (numberofcol > 70 && numberofcol < 100)
		 total = 1000;
	 if (numberofcol >= 100)
		 total = 1500;
	 for (int i = 0; i < numberofcol; i++)
		{
			float x = rand() / 30000.0;
			int y = x * 100;
			x = y / 100.0;
			
			arr[i]->Size = System::Drawing::Size(total/numberofcol, 250*x+10);
			arr[i]->Text = x.ToString();
		}
	 Refresh();
	 if (comboBox1->Text == "selection sort")
	 selectionsort();
	 if(comboBox1->Text == "bubble sort")
	 bubblesort();
	 if (comboBox1->Text == "shell sort")
	 shellsort();
	 if (comboBox1->Text == "insertion sort")
		 insertionsort(numberofcol);


	}
    void bubblesort()
		   {
			   bool change = true;
			   Button^ s;
			   double x;
			   for (int j = 0; j < numberofcol-1; j++)
			   {
				   change = true;
				   for (int i = 0; i < numberofcol-1-j; i++)
				   {
					   if (Double::Parse(arr[i]->Text) > Double::Parse(arr[i + 1]->Text))
					   {
						   change = false;
						   s = arr[i + 1];
						   arr[i + 1] = arr[i];
						   arr[i] = s;
						   move(arr[i], arr[i + 1]);
					   }
					   else
					   {
						   changecolor(arr[i], arr[i + 1], 1);
						   changecolor(arr[i], arr[i + 1], 2);
						   changecolor(arr[i], arr[i + 1], 3);
					   }
				   }
				   inversioncount(numberofcol);
				   if (change)
					   break;
			   }
		   }
	void selectionsort()
	 {
		 double min;
		 int mini;
		 Button^ s;
		 for (int j = 0; j < numberofcol; j++)
		 {
			 for (int i = j; i < numberofcol; i++)
			 {
				 changecolor(arr[i], arr[i],1);
				 changecolor(arr[i], arr[i], 3);
				 if (i == j || min > Double::Parse(arr[i]->Text))
				 {
					 min = Double::Parse(arr[i]->Text);
					 mini = i;
				 }
			 }
			 s = arr[j];
			 arr[j] = arr[mini];
			 arr[mini] = s;
			 move(arr[j], arr[mini]);
			 inversioncount(numberofcol);
		 }


	 }
	void shellsort()
	{

		//Shell Sort
		int walker, k = numberofcol / 2;
		double hold=0;
		Button^ temp;
		while (k)
		{
			for (int i = k; i < numberofcol; i++)
			{
				hold = Double::Parse(arr[i]->Text);
				walker = i - k;
				while (walker >= 0 && hold < Double::Parse(arr[walker]->Text))
				{
					changeheightval(arr[walker + k], Double::Parse(arr[walker]->Text));
					walker -= k;
				}
				changeheightval(arr[walker + k], hold);
				
			}
			inversioncount(numberofcol);
			k = k / 2;
			
		}

		
	
	
	
	
	}
	void insertionsort(int num)
	{
		int walker, k = 1;
		double hold = 0;
		Button^ temp;
		
		
		for (int i = k; i < num; i++)
		{
			hold = Double::Parse(arr[i]->Text);
			walker = i - k;
			while (walker >= 0 && hold < Double::Parse(arr[walker]->Text))
			{
				changeheightval(arr[walker + k], Double::Parse(arr[walker]->Text));
				walker -= k;
			}
			changeheightval(arr[walker + k], hold);
			inversioncount(num);
		}
		
		
	
	
	}
	void changeheightval(Button^ s, double num)
	{
		int total;
		if (numberofcol <= 70)
			total = 700;
		if (numberofcol > 70 && numberofcol < 100)
			total = 1000;
		if (numberofcol >= 100)
			total = 1500;
		changecolor(s, s, 1);
		double x = Double::Parse(s->Text);
		s->Size = System::Drawing::Size(total/numberofcol,(250 * num + 10));
		s->Text = num.ToString();
		changecolor(s, s, 2);
		changecolor(s, s, 3);
		Refresh();
	
	
	
	}
	void inversioncount(int num)
	{
		int inv = 0;
		for (int i = 0; i < num; i++)
		{
			for (int j = i + 1; j < num; j++)
			{
				if (Double::Parse(arr[i]->Text) > Double::Parse(arr[j]->Text))
				{
					inv++;
				}
			}
		}
		label1->Text = "inversions:" + inv.ToString();
		_sleep(30);
	
	
	
	}

private: System::Void col4_Click(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {}

private: System::Void col20_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
