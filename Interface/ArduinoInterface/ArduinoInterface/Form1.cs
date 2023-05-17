using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ArduinoInterface
{
    public partial class ArduinoInterface : Form
    {
        public delegate void d1(string indata);
        public ArduinoInterface()
        {
            InitializeComponent();
            serialPort1.Open();
        }

        private void onButton_Click(object sender, EventArgs e)
        {
            // Send command to the arduino
            serialPort1.Write("A");
        }

        private void offButton_Click_1(object sender, EventArgs e)
        {
            // Send command to the arduino
            serialPort1.Write("a");
        }

        private void KpInput_ValueChanged(object sender, EventArgs e)
        {
            serialPort1.Write("P" + KpInput.Value);
        }

        private void KiInput_ValueChanged(object sender, EventArgs e)
        {
            serialPort1.Write("I" + KiInput.Value);
        }

        private void KdInput_ValueChanged(object sender, EventArgs e)
        {
            serialPort1.Write("D" + KdInput.Value);
        }

        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            string indata = serialPort1.ReadLine();
            Invoke(new d1(Write2Form), indata);
        }

        public void Write2Form(string indata)
        {
            // Handles data sent from the arduino
            char firstChar;
            Single numdata;
            firstChar = indata[0];
            switch (firstChar)
            {
                case 'P':
                    kpOutput.Text = indata.Substring(1);
                    break;
                case 'I':
                    kiOutput.Text = indata.Substring(1);
                    break;
                case 'D':
                    kdOutput.Text = indata.Substring(1);
                    break;
            }




        }
    }
}
