#pragma once

namespace CppWinForm1 {

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
	private: System::Windows::Forms::GroupBox^  DataSourceBox;
	private: System::Windows::Forms::TextBox^  serverConnectionTextbox;
	private: System::Windows::Forms::TextBox^  unDataConnectionTextBox;
	private: System::Windows::Forms::TextBox^  passDataConnectionTextBox;
	private: System::Windows::Forms::Button^  dataConnectButton;
	private: System::Windows::Forms::Label^  testOutputLabel;




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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->DataSourceBox = (gcnew System::Windows::Forms::GroupBox());
			this->dataConnectButton = (gcnew System::Windows::Forms::Button());
			this->passDataConnectionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->unDataConnectionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->serverConnectionTextbox = (gcnew System::Windows::Forms::TextBox());
			this->testOutputLabel = (gcnew System::Windows::Forms::Label());
			this->DataSourceBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// DataSourceBox
			// 
			this->DataSourceBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->DataSourceBox->Controls->Add(this->dataConnectButton);
			this->DataSourceBox->Controls->Add(this->passDataConnectionTextBox);
			this->DataSourceBox->Controls->Add(this->unDataConnectionTextBox);
			this->DataSourceBox->Controls->Add(this->serverConnectionTextbox);
			this->DataSourceBox->Location = System::Drawing::Point(12, 12);
			this->DataSourceBox->Name = L"DataSourceBox";
			this->DataSourceBox->Size = System::Drawing::Size(251, 185);
			this->DataSourceBox->TabIndex = 0;
			this->DataSourceBox->TabStop = false;
			this->DataSourceBox->Text = L"Connect to Data Source";
			// 
			// dataConnectButton
			// 
			this->dataConnectButton->Location = System::Drawing::Point(7, 133);
			this->dataConnectButton->Name = L"dataConnectButton";
			this->dataConnectButton->Size = System::Drawing::Size(75, 23);
			this->dataConnectButton->TabIndex = 0;
			this->dataConnectButton->Text = L"Connect";
			this->dataConnectButton->UseVisualStyleBackColor = true;
			this->dataConnectButton->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::dataConnectButton_MouseClick);
			// 
			// passDataConnectionTextBox
			// 
			this->passDataConnectionTextBox->Location = System::Drawing::Point(126, 137);
			this->passDataConnectionTextBox->Name = L"passDataConnectionTextBox";
			this->passDataConnectionTextBox->Size = System::Drawing::Size(100, 20);
			this->passDataConnectionTextBox->TabIndex = 3;
			this->passDataConnectionTextBox->Text = L"password";
			this->passDataConnectionTextBox->Enter += gcnew System::EventHandler(this, &MyForm::passDataConnectionTextBox_Enter);
			// 
			// unDataConnectionTextBox
			// 
			this->unDataConnectionTextBox->Location = System::Drawing::Point(75, 82);
			this->unDataConnectionTextBox->Name = L"unDataConnectionTextBox";
			this->unDataConnectionTextBox->Size = System::Drawing::Size(100, 20);
			this->unDataConnectionTextBox->TabIndex = 2;
			this->unDataConnectionTextBox->Text = L"username";
			this->unDataConnectionTextBox->Enter += gcnew System::EventHandler(this, &MyForm::unDataConnectionTextBox_Enter);
			// 
			// serverConnectionTextbox
			// 
			this->serverConnectionTextbox->Location = System::Drawing::Point(7, 20);
			this->serverConnectionTextbox->Name = L"serverConnectionTextbox";
			this->serverConnectionTextbox->Size = System::Drawing::Size(219, 20);
			this->serverConnectionTextbox->TabIndex = 1;
			this->serverConnectionTextbox->Text = L"'ip address, portnumber' (remote) or 'hostname\\instancename' (local)";
			this->serverConnectionTextbox->Enter += gcnew System::EventHandler(this, &MyForm::serverConnectionTextbox_Enter);
			// 
			// testOutputLabel
			// 
			this->testOutputLabel->AutoSize = true;
			this->testOutputLabel->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->testOutputLabel->Location = System::Drawing::Point(304, 32);
			this->testOutputLabel->Name = L"testOutputLabel";
			this->testOutputLabel->Size = System::Drawing::Size(52, 13);
			this->testOutputLabel->TabIndex = 1;
			this->testOutputLabel->Text = L"no output";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->ClientSize = System::Drawing::Size(528, 509);
			this->Controls->Add(this->testOutputLabel);
			this->Controls->Add(this->DataSourceBox);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Frog Form";
			this->DataSourceBox->ResumeLayout(false);
			this->DataSourceBox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataConnectButton_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		//test for auth type
		// for windows auth
		if (unDataConnectionTextBox->Text == "" && passDataConnectionTextBox->Text == "")
		{
			//create connection
			System::Data::SqlClient::SqlConnection^ connection =
				(gcnew System::Data::SqlClient::SqlConnection(
					// don't return password 
					"Persist Security Info=False" +
					// use windows un/pw
					";Integragted Securiy=true" +
					// specify network SQL server
					";server=" + serverConnectionTextbox->Text +
					// initial database
					";Initial Catalog=customers"
					));
			// connection state change event
			connection->StateChange += gcnew System::Data::StateChangeEventHandler(this, &CppWinForm1::MyForm::OnStateChange);
			// open connection
			connection->Open();

			testOutputLabel->Text = L"opened connection";

			//testOutputLabel->Text = state->ToString();
			

			
		}
		else { //for typical un/pw auth
			// create connection
			System::Data::SqlClient::SqlConnection^ connection = (gcnew System::Data::SqlClient::SqlConnection(
				// remote TCP: servername, portnumber from user
				"server=tcp:" + serverConnectionTextbox->Text +
				";user id=" + unDataConnectionTextBox->Text +
				"password=" + passDataConnectionTextBox->Text
				));
		}
	}
private: System::Void passDataConnectionTextBox_Enter(System::Object^  sender, System::EventArgs^  e) {
	this->passDataConnectionTextBox->Text = L"";
}
private: System::Void unDataConnectionTextBox_Enter(System::Object^  sender, System::EventArgs^  e) {
	this->unDataConnectionTextBox->Text = L"";
}
private: System::Void serverConnectionTextbox_Enter(System::Object^  sender, System::EventArgs^  e) {
	this->serverConnectionTextbox->Text = L"";
}
		
void OnStateChange(System::Object ^ sender, System::Data::StateChangeEventArgs ^ e);
};
}

void CppWinForm1::MyForm::OnStateChange(System::Object ^sender, System::Data::StateChangeEventArgs ^e)
{
	throw gcnew System::NotImplementedException();
}
