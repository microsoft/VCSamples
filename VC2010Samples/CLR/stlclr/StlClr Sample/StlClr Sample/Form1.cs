using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace StlClr_Sample
{
    public partial class Form1 : Form
    {
        private System.Collections.Generic.List<System.String> list;
        public Form1()
        {
            InitializeComponent();
            list = new System.Collections.Generic.List<System.String>();
            System.String str = "";
            for (int i = 0; i < 30; i++)
            {
                str = str + "x";
                this.list.Insert(i, str);   
            }
            updatelist();
            
        }

        private void shuffle_Click(object sender, EventArgs e)
        {
            StlClrLibrary.Tools tools = new StlClrLibrary.Tools();
            tools.Shuffle(list);
            updatelist();
        }

        public void updatelist()
        {
            int i = 0;
            foreach (String str in list)
            {
                this.listBox1.Items[i] = str;
                i++;
            }
        }

        private void BubbleSort_Click(object sender, EventArgs e)
        {
            StlClrLibrary.Tools tools = new StlClrLibrary.Tools();
            tools.BubbleSort(list);
            updatelist();
        }

        private void BubbleStep_Click(object sender, EventArgs e)
        {
            StlClrLibrary.Tools tools = new StlClrLibrary.Tools();
            tools.BubbleStep(list);
            updatelist();
        }

        private void BubbleSortNative_Click(object sender, EventArgs e)
        {
            StlClrLibrary.Tools tools = new StlClrLibrary.Tools();
            tools.BubbleSortNative(list);
            updatelist();
        }
    }
}
