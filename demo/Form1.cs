using System;
using System.Text;
using System.Windows.Forms;

namespace demo
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            StringBuilder myStrB = new StringBuilder(2048);
            DLL.SSCard.iReadCardBas(1, myStrB);
            if (myStrB != null && myStrB.ToString() != "" && myStrB.ToString().IndexOf("|") >= 0)
            {
                //MessageBox.Show(myStrB.ToString());
                //ThreadUPtextBoxMsg(textBoxMsgAppendText, "\r\n" + myStrB.ToString());

                textBox1.Text = "\r\n" + myStrB.ToString();
            }
            else
            {
                textBox1.Text = myStrB.ToString() + "\r\n";
                MessageBox.Show(myStrB.ToString());
                //ThreadUPtextBoxMsg(textBoxMsgAppendText, "\r\n" + myStrB.ToString());
            }
        }
    }
}
