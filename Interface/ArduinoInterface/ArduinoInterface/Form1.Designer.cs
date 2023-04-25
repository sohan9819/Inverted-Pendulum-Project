namespace ArduinoInterface
{
    partial class ArduinoInterface
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.onButton = new System.Windows.Forms.Button();
            this.offButton = new System.Windows.Forms.Button();
            this.KpInput = new System.Windows.Forms.NumericUpDown();
            this.KiInput = new System.Windows.Forms.NumericUpDown();
            this.KdInput = new System.Windows.Forms.NumericUpDown();
            this.KpInputLabel = new System.Windows.Forms.Label();
            this.KiInputLabel = new System.Windows.Forms.Label();
            this.KdInputLabel = new System.Windows.Forms.Label();
            this.kpOutput = new System.Windows.Forms.TextBox();
            this.kdOutput = new System.Windows.Forms.TextBox();
            this.kiOutput = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.KpInput)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.KiInput)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.KdInput)).BeginInit();
            this.SuspendLayout();
            // 
            // serialPort1
            // 
            this.serialPort1.PortName = "COM3";
            this.serialPort1.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.serialPort1_DataReceived);
            // 
            // onButton
            // 
            this.onButton.Location = new System.Drawing.Point(27, 30);
            this.onButton.Name = "onButton";
            this.onButton.Size = new System.Drawing.Size(107, 51);
            this.onButton.TabIndex = 0;
            this.onButton.Text = "Turn ON";
            this.onButton.UseVisualStyleBackColor = true;
            this.onButton.Click += new System.EventHandler(this.onButton_Click);
            // 
            // offButton
            // 
            this.offButton.Location = new System.Drawing.Point(171, 31);
            this.offButton.Name = "offButton";
            this.offButton.Size = new System.Drawing.Size(107, 50);
            this.offButton.TabIndex = 1;
            this.offButton.Text = "Turn OFF";
            this.offButton.UseVisualStyleBackColor = true;
            this.offButton.Click += new System.EventHandler(this.offButton_Click_1);
            // 
            // KpInput
            // 
            this.KpInput.Location = new System.Drawing.Point(158, 192);
            this.KpInput.Name = "KpInput";
            this.KpInput.Size = new System.Drawing.Size(120, 22);
            this.KpInput.TabIndex = 2;
            this.KpInput.ValueChanged += new System.EventHandler(this.KpInput_ValueChanged);
            // 
            // KiInput
            // 
            this.KiInput.Location = new System.Drawing.Point(158, 239);
            this.KiInput.Name = "KiInput";
            this.KiInput.Size = new System.Drawing.Size(120, 22);
            this.KiInput.TabIndex = 3;
            this.KiInput.ValueChanged += new System.EventHandler(this.KiInput_ValueChanged);
            // 
            // KdInput
            // 
            this.KdInput.Location = new System.Drawing.Point(158, 287);
            this.KdInput.Name = "KdInput";
            this.KdInput.Size = new System.Drawing.Size(120, 22);
            this.KdInput.TabIndex = 4;
            this.KdInput.ValueChanged += new System.EventHandler(this.KdInput_ValueChanged);
            // 
            // KpInputLabel
            // 
            this.KpInputLabel.AutoSize = true;
            this.KpInputLabel.Location = new System.Drawing.Point(104, 198);
            this.KpInputLabel.Name = "KpInputLabel";
            this.KpInputLabel.Size = new System.Drawing.Size(23, 16);
            this.KpInputLabel.TabIndex = 5;
            this.KpInputLabel.Text = "Kp";
            // 
            // KiInputLabel
            // 
            this.KiInputLabel.AutoSize = true;
            this.KiInputLabel.Location = new System.Drawing.Point(104, 241);
            this.KiInputLabel.Name = "KiInputLabel";
            this.KiInputLabel.Size = new System.Drawing.Size(18, 16);
            this.KiInputLabel.TabIndex = 6;
            this.KiInputLabel.Text = "Ki";
            // 
            // KdInputLabel
            // 
            this.KdInputLabel.AutoSize = true;
            this.KdInputLabel.Location = new System.Drawing.Point(104, 289);
            this.KdInputLabel.Name = "KdInputLabel";
            this.KdInputLabel.Size = new System.Drawing.Size(23, 16);
            this.KdInputLabel.TabIndex = 7;
            this.KdInputLabel.Text = "Kd";
            // 
            // kpOutput
            // 
            this.kpOutput.Location = new System.Drawing.Point(486, 191);
            this.kpOutput.Name = "kpOutput";
            this.kpOutput.Size = new System.Drawing.Size(100, 22);
            this.kpOutput.TabIndex = 8;
            // 
            // kdOutput
            // 
            this.kdOutput.Location = new System.Drawing.Point(486, 283);
            this.kdOutput.Name = "kdOutput";
            this.kdOutput.Size = new System.Drawing.Size(100, 22);
            this.kdOutput.TabIndex = 9;
            // 
            // kiOutput
            // 
            this.kiOutput.Location = new System.Drawing.Point(486, 235);
            this.kiOutput.Name = "kiOutput";
            this.kiOutput.Size = new System.Drawing.Size(100, 22);
            this.kiOutput.TabIndex = 10;
            // 
            // ArduinoInterface
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.kiOutput);
            this.Controls.Add(this.kdOutput);
            this.Controls.Add(this.kpOutput);
            this.Controls.Add(this.KdInputLabel);
            this.Controls.Add(this.KiInputLabel);
            this.Controls.Add(this.KpInputLabel);
            this.Controls.Add(this.KdInput);
            this.Controls.Add(this.KiInput);
            this.Controls.Add(this.KpInput);
            this.Controls.Add(this.offButton);
            this.Controls.Add(this.onButton);
            this.Name = "ArduinoInterface";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.KpInput)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.KiInput)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.KdInput)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.Button onButton;
        private System.Windows.Forms.Button offButton;
        private System.Windows.Forms.NumericUpDown KpInput;
        private System.Windows.Forms.NumericUpDown KiInput;
        private System.Windows.Forms.NumericUpDown KdInput;
        private System.Windows.Forms.Label KpInputLabel;
        private System.Windows.Forms.Label KiInputLabel;
        private System.Windows.Forms.Label KdInputLabel;
        private System.Windows.Forms.TextBox kpOutput;
        private System.Windows.Forms.TextBox kdOutput;
        private System.Windows.Forms.TextBox kiOutput;
    }
}

