namespace StlClr_Sample
{
    partial class Form1
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
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.shuffle = new System.Windows.Forms.Button();
            this.BubbleSort = new System.Windows.Forms.Button();
            this.BubbleStep = new System.Windows.Forms.Button();
            this.BubbleSortNative = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.Items.AddRange(new object[] {
            "X",
            "XX",
            "XXX",
            "XXXX",
            "XXXXX",
            "XXXXXX",
            "XXXXXXX",
            "XXXXXXXX",
            "XXXXXXXXX",
            "XXXXXXXXXX",
            "XXXXXXXXXXX",
            "XXXXXXXXXXXX",
            "XXXXXXXXXXXXX",
            "XXXXXXXXXXXXXX",
            "XXXXXXXXXXXXXXX",
            "XXXXXXXXXXXXXXXX",
            "XXXXXXXXXXXXXXXXX",
            "XXXXXXXXXXXXXXXXXX",
            "XXXXXXXXXXXXXXXXXXX",
            "XXXXXXXXXXXXXXXXXXXX",
            "XXXXXXXXXXXXXXXXXXXXX",
            "XXXXXXXXXXXXXXXXXXXXXX",
            "XXXXXXXXXXXXXXXXXXXXXXX",
            "XXXXXXXXXXXXXXXXXXXXXXXX",
            "XXXXXXXXXXXXXXXXXXXXXXXXX",
            "XXXXXXXXXXXXXXXXXXXXXXXXXX",
            "XXXXXXXXXXXXXXXXXXXXXXXXXXX",
            "XXXXXXXXXXXXXXXXXXXXXXXXXXXX",
            "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
            "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"});
            this.listBox1.Location = new System.Drawing.Point(20, 50);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(359, 407);
            this.listBox1.TabIndex = 0;
            // 
            // shuffle
            // 
            this.shuffle.Location = new System.Drawing.Point(21, 12);
            this.shuffle.Name = "shuffle";
            this.shuffle.Size = new System.Drawing.Size(75, 23);
            this.shuffle.TabIndex = 1;
            this.shuffle.Text = "Shuffle";
            this.shuffle.UseVisualStyleBackColor = true;
            this.shuffle.Click += new System.EventHandler(this.shuffle_Click);
            // 
            // BubbleSort
            // 
            this.BubbleSort.Location = new System.Drawing.Point(115, 12);
            this.BubbleSort.Name = "BubbleSort";
            this.BubbleSort.Size = new System.Drawing.Size(75, 23);
            this.BubbleSort.TabIndex = 2;
            this.BubbleSort.Text = "BubbleSort";
            this.BubbleSort.UseVisualStyleBackColor = true;
            this.BubbleSort.Click += new System.EventHandler(this.BubbleSort_Click);
            // 
            // BubbleStep
            // 
            this.BubbleStep.Location = new System.Drawing.Point(209, 12);
            this.BubbleStep.Name = "BubbleStep";
            this.BubbleStep.Size = new System.Drawing.Size(75, 23);
            this.BubbleStep.TabIndex = 3;
            this.BubbleStep.Text = "BubbleStep";
            this.BubbleStep.UseVisualStyleBackColor = true;
            this.BubbleStep.Click += new System.EventHandler(this.BubbleStep_Click);
            // 
            // BubbleSortNative
            // 
            this.BubbleSortNative.Location = new System.Drawing.Point(303, 12);
            this.BubbleSortNative.Name = "BubbleSortNative";
            this.BubbleSortNative.Size = new System.Drawing.Size(75, 23);
            this.BubbleSortNative.TabIndex = 4;
            this.BubbleSortNative.Text = "BSortNative";
            this.BubbleSortNative.UseVisualStyleBackColor = true;
            this.BubbleSortNative.Click += new System.EventHandler(this.BubbleSortNative_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(398, 477);
            this.Controls.Add(this.BubbleSortNative);
            this.Controls.Add(this.BubbleStep);
            this.Controls.Add(this.BubbleSort);
            this.Controls.Add(this.shuffle);
            this.Controls.Add(this.listBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Button shuffle;
        private System.Windows.Forms.Button BubbleSort;
        private System.Windows.Forms.Button BubbleStep;
        private System.Windows.Forms.Button BubbleSortNative;
    }
}

